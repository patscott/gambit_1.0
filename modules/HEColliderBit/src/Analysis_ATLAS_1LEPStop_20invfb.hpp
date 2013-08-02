#include "Analysis.hpp"
#include <vector>
#include <cmath>
#include <memory>
#include "TLorentzVector.h"
#include "MT2Calculator/ComputeMT2.h"

/* The ATLAS 1 lepton direct stop analysis (20fb^-1). 
   Code by Martin White.
   Known errors:
   a) The isolation is already applied in the simulation rather than after overlap removal
   b) The ATLAS analysis uses the two jets with the highest b tag weight for the MT2 calculation. This is impossible for us. Instead, we should use the two truth b jets. However, the b efficiency will be applied when preselecting events.

   Known features:
   a) Must run simulator with 75% b tagging efficiency and 2% mis-id rate
   b) For now have nicked ATLAS MT2 code. Need to check status of this for public release. The better option is to write a non-ROOT version later.
*/

namespace GAMBIT {


  using namespace std;

  //A useful MT2 class for this module
  class MT2 {
    
  public:
    MT2(){
      MT2tauB=0;
      aMT2_BM=0;
    }
    
    double MT2tauB;
    double aMT2_BM;
  };
    
    
  class Analysis_ATLAS_1LEPStop_20invfb : public Analysis {
  private:
    
    // Numbers passing cuts
    int _numTN1Shape, _numTN2, _numTN3, _numBC1, _numBC2,
      _numBC3;

    // Debug histos
  public:

    Analysis_ATLAS_1LEPStop_20invfb() {
      _numTN1Shape = 0; _numTN2 = 0; _numTN3 = 0; _numBC1 = 0;
      _numBC2 = 0; _numBC3 = 0;

    }


    // void init() {
    // }
    MT2 MT2helper(vector<Jet *> jets, vector<Particle *>  electrons,  vector<Particle *> muons, P4 metVec){

      MT2 results;
      
      bool passmu = false;
      if(muons.size()==1)passmu=true;

      bool passel = false;
      if(electrons.size()==1)passel=true;

      int nJet = jets.size();
      if(nJet < 2)return results;
      
      //ATLAS use the two jets with highest MV1 weights
      //DELPHES does not have a continuous b weight
      //Thus must approximate using the two true b jets
      Jet * trueBjet1=0; //need to assign this
      Jet * trueBjet2=0; //nee to assign this

      for(Jet * tmpJet: jets){
	if(tmpJet->getPdgId()==5){
	  trueBjet1=jet;		     
	  break;
	}
      }

      for(Jet * tmpJet: jets){
	if(tmpJet->getPdgId()==5 && tmpJet!=trueBjet1){
	  trueBjet2=jet;		     
	  break;
	}
      }

      TLorentzVector jet1B,jet2B;
      jet1B.SetPtEtaPhiE(trueBjet1->pT(),trueBjet1->eta(),trueBjet1->phi(),trueBjet1->E());
      jet2B.SetPtEtaPhiE(trueBjet2->pT(),trueBjet2->eta(),trueBjet2->phi(),trueBjet2->E());

      P4 leptontmp;
      float leptonmass = 0;
      if(passel){
	leptonmass = 0.510998910; //MeV
	leptontmp = electrons[0]->mom();
      }
      else if(passmu){
	leptonmass =  105.658367; // MeV
        leptontmp = muons[0]->mom();
      }

      TLorentzVector lepton;
      lepton.SetPtEtaPhiM(leptontmp.pT(),leptontmp.eta(),leptontmp.phi(),leptonmass/1000.);

      TLorentzVector MET;
      MET.SetXYZM(metVec.px(),metVec.py(),0.,0.);

      ComputeMT2 stuff(jet1B+lepton,jet2B,MET,0.,80.);
      double mt2a  = stuff.ComputeNumeric();
      
      ComputeMT2 stuff2(jet2B+lepton,jet1B,MET,0.,80.);
      double mt2b = stuff2.ComputeNumeric();
      
      double aMT2_BM = min(mt2a,mt2b);
      results.aMT2_BM=aMT2_BM;
      
      if (nJet > 3){
        Jet * jet3=0;
	for(Jet * current: jets){
	  if (current == trueBjet1)continue;
	  if (current == trueBjet2)continue;
	  jet3 = current;
	  break;
	}
        TLorentzVector jet3B;
	jet3B.SetPtEtaPhiE(jet3->pT(),jet3->eta(),jet3->phi(),jet3->E());
        ComputeMT2 stuff3(jet3B,lepton,MET,0.,0.);
	double MT2tauB = stuff3.ComputeNumeric();
	results.MT2tauB=MT2tauB;
      }
      return results;
    }


    void analyze(const Event* event) {
      // Missing energy
      P4 ptot = event->missingMom();
      double met = event->met();

      // Now define vectors of baseline objects
      vector<Particle*> baselineElectrons;
      for (Particle* electron : event->electrons()) {
        if (electron->pT() > 10. && fabs(electron->eta()) < 2.47) baselineElectrons.push_back(electron);
      }
      vector<Particle*> baselineMuons;
      for (Particle* muon : event->muons()) {
        if (muon->pT() > 10. && fabs(muon->eta()) < 2.4) baselineMuons.push_back(muon);
      }
      vector<Jet*> baselineJets;
      vector<Jet*> bJets;
      for (Jet* jet : event->jets()) {
        if (jet->pT() > 20. && fabs(jet->eta()) < 10.0) baselineJets.push_back(jet);
	if(jet->isBJet() && fabs(jet->eta()) < 2.5 && jet->pT() > 25.) bJets.push_back(jet);
      }

      // Overlap removal
      vector<Particle*> signalElectrons;
      vector<Particle*> signalMuons;
      vector<Particle*> leptonsForVeto; 
      vector<Jet*> signalJets;
   
      // Remove any jet within dR=0.2 of an electrons
      for (size_t iJet=0;iJet<baselineJets.size();iJet++) {
        bool overlap=false;
        P4 jetVec=baselineJets.at(iJet)->mom();
        for (size_t iEl=0;iEl<baselineElectrons.size();iEl++) {
          P4 elVec=baselineElectrons.at(iEl)->mom();
          if (elVec.deltaR_eta(jetVec)<0.2)overlap=true;
        }
        if (!overlap)signalJets.push_back(baselineJets.at(iJet));
      }

      // Remove electrons with dR=0.4 or surviving jets
      for (size_t iEl=0;iEl<baselineElectrons.size();iEl++) {
        bool overlap=false;
        P4 elVec=baselineElectrons.at(iEl)->mom();
        for (size_t iJet=0;iJet<signalJets.size();iJet++) {
          P4 jetVec=signalJets.at(iJet)->mom();
          if (elVec.deltaR_eta(jetVec)<0.4)overlap=true;
        }
        if (!overlap && elVec.pT()>25.)signalElectrons.push_back(baselineElectrons.at(iEl));
	if(!overlap)leptonsForVeto.push_back(baselineElectrons.at(iEl));
      }

      // Remove muons with dR=0.4 or surviving jets
      for (size_t iMu=0;iMu<baselineMuons.size();iMu++) {
        bool overlap=false;
        P4 muVec=baselineMuons.at(iMu)->mom();
        for (size_t iJet=0;iJet<signalJets.size();iJet++) {
          P4 jetVec=signalJets.at(iJet)->mom();
          if (muVec.deltaR_eta(jetVec)<0.4)overlap=true;
        }
        if (!overlap && muVec.pT()>25.)signalMuons.push_back(baselineMuons.at(iMu));
	if(!overlap)leptonsForVeto.push_back(baselineMuons.at(iMu));
      }

      // We now have the signal electrons, muons, jets and b jets- move on to the analysis

      // Calculate common variables and cuts first
      int nElectrons = signalElectrons.size();
      int nMuons = signalMuons.size();
      int nJets = signalJets.size();
      int nBjets = bJets.size();

      //Common preselection for all signal regions
      if(!(nJets>=4 
	   && signalJets[0]->pT() > 80.
	   && signalJets[1]->pT() > 60.
	   && signalJets[2]->pT() > 40.
	   && signalJets[3]->pT() > 25.))return;
          
      //At least one of the leading four jets must be a b jet
      if(!(signalJets[0]->isBJet() ||
	   signalJets[1]->isBJet() ||
	   signalJets[2]->isBJet() ||
	   signalJets[3]->isBJet()))return;
      
      //Must have exactly one lepton
      if(!(nElectrons==1||nMuons==1))return;
      if(leptonsForVeto.size()>1)return;

      //Calculate dphi(jet,met) for the two leading jets
      float dphi_jetmet1=std::acos(std::cos(signalJets.at(0)->phi()-ptot.phi()));
      float dphi_jetmet2=std::acos(std::cos(signalJets.at(1)->phi()-ptot.phi()));

      //Calculate met/sqrt(HT) (use four leading jets only)
      float HT=signalJets[0]->pT()+signalJets[1]->pT()+signalJets[3]->pT()+signalJets[4]->pT();
      float metOverSqrtHT=met/sqrt(HT);
      
      //Calculate mT
      P4 lepVec;
      if(nElectrons==1)lepVec=baselineElectrons[0]->mom();
      if(nMuons==1)lepVec=baselineMuons[0]->mom();
      float mT = sqrt(2.*lepVec.pT()*met*(1.-cos(ptot.deltaPhi(lepVec))));
  
      //Calculate meff (all jets with pT>30 GeV, lepton pT and met)
      float meff = met + lepVec.pT();
      for (Jet* jet : signalJets) {
	if(jet->pT()>30.)meff += jet->pT();
      }
      
      //Do hadronic top reconstruction
      float mindR1=9999.;
      float mindR2=9999.;
      float index1=9999.;
      float index2=9999.;
      float index3=9999.;
      
      bool whad=false;
      bool Thad=false;
      float mHadTop=0;

      for(int iJet=0;iJet<nJets;iJet++){
	for(int jJet=0;jJet<nJets;jJet++){
	  if(iJet != jJet){
  	    if(signalJets[iJet]->mom().deltaR_eta(signalJets[jJet]->mom()) < mindR1 && (signalJets[iJet]->mom()+signalJets[jJet]->mom()).m() > 60.){
	      mindR1 = signalJets[iJet]->mom().deltaR_eta(signalJets[jJet]->mom());
	      index1 = iJet;
	      index2 = jJet;
	      whad   = true;
	    }
	  }
	}
      }
      if(whad){
	for(int kJet=0;kJet<nJets;kJet++){
	  if(kJet !=index1 && kJet !=index2){
	    if(signalJets[kJet]->mom().deltaR_eta( signalJets[index1]->mom() + signalJets[index2]->mom()) < mindR2 && (signalJets[index1]->mom()+signalJets[index2]->mom()+signalJets[kJet]->mom()).m() > 130.){
	      mindR2=signalJets[kJet]->mom().deltaR_eta(signalJets[index1]->mom() + signalJets[index2]->mom());
	      index3=kJet;
	      Thad=true;
	    }
	  }
	}
      }
      if(Thad)mHadTop = (signalJets[index1]->mom()+signalJets[index2]->mom()+signalJets[index3]->mom()).m();
      
      bool passHadTop=false;
      if(mHadTop>130.&& mHadTop<205.)passHadTop=true;
      
      if(!passHadTop)return;
      
      //Do MT2 calculations (note: do these last, since they are slowest)
      MT2 mt2s = MT2helper(signalJets,signalElectrons,signalMuons,ptot);
      double amt2 = mt2s.aMT2_BM;
      double mt2tau = mt2s.MT2tauB;

      //We're now ready to apply the cuts for each signal region
      
	
      return;
      
    }
      
    void finalize() {
      //cout << "NUMEVENTS: " << _numAT << " " << _numAM << " " << _numAL << " "
      //   << _numBT << " " << _numBM << " " << _numCT << " " << _numCM << " " << _numCL << " "
      //   << _numD << " " << _numET << " " << _numEM << " " << _numEL << endl;

    }


    double logLikelihood() {
      /// @todo Implement!
      return 1.0;
    }
    
    
    };
    

  }
