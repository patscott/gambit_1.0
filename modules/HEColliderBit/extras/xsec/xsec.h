#ifndef xsec_h
#define xsec_h

#include <string>
#include <map>
#include "Pythia8/SusyLesHouches.h"

// Include all NN-classes
#include "networks/NNfunction_NN_1_1.h"
#include "networks/NNfunction_NN_1_2.h"
#include "networks/NNfunction_NN_1_3.h"
#include "networks/NNfunction_NN_1_4.h"
#include "networks/NNfunction_NN_1_5.h"
#include "networks/NNfunction_NN_1_6.h"
#include "networks/NNfunction_NN_1_7.h"
#include "networks/NNfunction_NN_1_8.h"
#include "networks/NNfunction_NN_2_2.h"
#include "networks/NNfunction_NN_2_3.h"
#include "networks/NNfunction_NN_2_4.h"
#include "networks/NNfunction_NN_2_5.h"
#include "networks/NNfunction_NN_2_6.h"
#include "networks/NNfunction_NN_2_7.h"
#include "networks/NNfunction_NN_2_8.h"
#include "networks/NNfunction_NN_3_3.h"
#include "networks/NNfunction_NN_3_4.h"
#include "networks/NNfunction_NN_3_5.h"
#include "networks/NNfunction_NN_3_6.h"
#include "networks/NNfunction_NN_3_7.h"
#include "networks/NNfunction_NN_3_8.h"
#include "networks/NNfunction_NN_4_4.h"
#include "networks/NNfunction_NN_5_7.h"
#include "networks/NNfunction_NN_5_8.h"
#include "networks/NNfunction_NN_6_7.h"
#include "networks/NNfunction_NN_6_8.h"

#include "networks/NNfunction_NG_1.h"
#include "networks/NNfunction_NG_2.h"
#include "networks/NNfunction_NG_3.h"
#include "networks/NNfunction_NG_4.h"
#include "networks/NNfunction_NG_5.h"
#include "networks/NNfunction_NG_6.h"
#include "networks/NNfunction_NG_7.h"
#include "networks/NNfunction_NG_8.h"

#include "networks/NNfunction_b1b1.h"
#include "networks/NNfunction_b2b2.h"
#include "networks/NNfunction_cLg.h"
#include "networks/NNfunction_cRg.h"
#include "networks/NNfunction_dLg.h"
#include "networks/NNfunction_dRg.h"
#include "networks/NNfunction_gg.h"
#include "networks/NNfunction_sLg.h"
#include "networks/NNfunction_sRg.h"
#include "networks/NNfunction_sb_cLcL.h"
#include "networks/NNfunction_sb_cLcR.h"
#include "networks/NNfunction_sb_cLdL.h"
#include "networks/NNfunction_sb_cLdR.h"
#include "networks/NNfunction_sb_cLsL.h"
#include "networks/NNfunction_sb_cLsR.h"
#include "networks/NNfunction_sb_cLuL.h"
#include "networks/NNfunction_sb_cLuR.h"
#include "networks/NNfunction_sb_cRcR.h"
#include "networks/NNfunction_sb_dLcR.h"
#include "networks/NNfunction_sb_dLdL.h"
#include "networks/NNfunction_sb_dLdR.h"
#include "networks/NNfunction_sb_dLsR.h"
#include "networks/NNfunction_sb_dLuR.h"
#include "networks/NNfunction_sb_dRcR.h"
#include "networks/NNfunction_sb_dRdR.h"
#include "networks/NNfunction_sb_dRsR.h"
#include "networks/NNfunction_sb_sLcR.h"
#include "networks/NNfunction_sb_sLdL.h"
#include "networks/NNfunction_sb_sLdR.h"
#include "networks/NNfunction_sb_sLsL.h"
#include "networks/NNfunction_sb_sLsR.h"
#include "networks/NNfunction_sb_sLuL.h"
#include "networks/NNfunction_sb_sLuR.h"
#include "networks/NNfunction_sb_sRcR.h"
#include "networks/NNfunction_sb_sRsR.h"
#include "networks/NNfunction_sb_uLcR.h"
#include "networks/NNfunction_sb_uLdR.h"
#include "networks/NNfunction_sb_uLsR.h"
#include "networks/NNfunction_sb_uLuL.h"
#include "networks/NNfunction_sb_uLuR.h"
#include "networks/NNfunction_sb_uRcR.h"
#include "networks/NNfunction_sb_uRdR.h"
#include "networks/NNfunction_sb_uRsR.h"
#include "networks/NNfunction_sb_uRuR.h"
#include "networks/NNfunction_ss_cLcL.h"
#include "networks/NNfunction_ss_cLcR.h"
#include "networks/NNfunction_ss_cLdL.h"
#include "networks/NNfunction_ss_cLdR.h"
#include "networks/NNfunction_ss_cLsL.h"
#include "networks/NNfunction_ss_cLsR.h"
#include "networks/NNfunction_ss_cLuL.h"
#include "networks/NNfunction_ss_cLuR.h"
#include "networks/NNfunction_ss_cRcR.h"
#include "networks/NNfunction_ss_dLcR.h"
#include "networks/NNfunction_ss_dLdL.h"
#include "networks/NNfunction_ss_dLdR.h"
#include "networks/NNfunction_ss_dLsR.h"
#include "networks/NNfunction_ss_dLuR.h"
#include "networks/NNfunction_ss_dRcR.h"
#include "networks/NNfunction_ss_dRdR.h"
#include "networks/NNfunction_ss_dRsR.h"
#include "networks/NNfunction_ss_sLcR.h"
#include "networks/NNfunction_ss_sLdL.h"
#include "networks/NNfunction_ss_sLdR.h"
#include "networks/NNfunction_ss_sLsL.h"
#include "networks/NNfunction_ss_sLsR.h"
#include "networks/NNfunction_ss_sLuL.h"
#include "networks/NNfunction_ss_sLuR.h"
#include "networks/NNfunction_ss_sRcR.h"
#include "networks/NNfunction_ss_sRsR.h"
#include "networks/NNfunction_ss_uLcR.h"
#include "networks/NNfunction_ss_uLdR.h"
#include "networks/NNfunction_ss_uLsR.h"
#include "networks/NNfunction_ss_uLuL.h"
#include "networks/NNfunction_ss_uLuR.h"
#include "networks/NNfunction_ss_uRcR.h"
#include "networks/NNfunction_ss_uRdR.h"
#include "networks/NNfunction_ss_uRsR.h"
#include "networks/NNfunction_ss_uRuR.h"
#include "networks/NNfunction_t1t1.h"
#include "networks/NNfunction_t2t2.h"
#include "networks/NNfunction_uLg.h"
#include "networks/NNfunction_uRg.h"

using namespace std;

namespace xsec{

  class Evaluator {

    // One object of every NN class
    // Mutable so their Value methods can be called despite not being declared const by ROOT...
    mutable NNfunction_NN_1_1 nn_n1n1;
    mutable NNfunction_NN_1_2 nn_n1n2;
    mutable NNfunction_NN_1_3 nn_n1n3;
    mutable NNfunction_NN_1_4 nn_n1n4;
    mutable NNfunction_NN_1_5 nn_n1n5;
    mutable NNfunction_NN_1_6 nn_n1n6;
    mutable NNfunction_NN_1_7 nn_n1n7;
    mutable NNfunction_NN_1_8 nn_n1n8;
    mutable NNfunction_NN_2_2 nn_n2n2;
    mutable NNfunction_NN_2_3 nn_n2n3;
    mutable NNfunction_NN_2_4 nn_n2n4;
    mutable NNfunction_NN_2_5 nn_n2n5;
    mutable NNfunction_NN_2_6 nn_n2n6;
    mutable NNfunction_NN_2_7 nn_n2n7;
    mutable NNfunction_NN_2_8 nn_n2n8;
    mutable NNfunction_NN_3_3 nn_n3n3;
    mutable NNfunction_NN_3_4 nn_n3n4;
    mutable NNfunction_NN_3_5 nn_n3n5;
    mutable NNfunction_NN_3_6 nn_n3n6;
    mutable NNfunction_NN_3_7 nn_n3n7;
    mutable NNfunction_NN_3_8 nn_n3n8;
    mutable NNfunction_NN_4_4 nn_n4n4;
    mutable NNfunction_NN_5_7 nn_n5n7;
    mutable NNfunction_NN_5_8 nn_n5n8;
    mutable NNfunction_NN_6_7 nn_n6n7;
    mutable NNfunction_NN_6_8 nn_n6n8;

    mutable NNfunction_NG_1 ng_n1g;
    mutable NNfunction_NG_2 ng_n2g;
    mutable NNfunction_NG_3 ng_n3g;
    mutable NNfunction_NG_4 ng_n4g;
    mutable NNfunction_NG_5 ng_n5g;
    mutable NNfunction_NG_6 ng_n6g;
    mutable NNfunction_NG_7 ng_n7g;
    mutable NNfunction_NG_8 ng_n8g;

    mutable NNfunction_b1b1 b1b1;
    mutable NNfunction_b2b2 b2b2;
    mutable NNfunction_cLg cLg;
    mutable NNfunction_cRg cRg;
    mutable NNfunction_dLg dLg;
    mutable NNfunction_dRg dRg;
    mutable NNfunction_gg gg;
    mutable NNfunction_sLg sLg;
    mutable NNfunction_sRg sRg;
    mutable NNfunction_sb_cLcL sb_cLcL;
    mutable NNfunction_sb_cLcR sb_cLcR;
    mutable NNfunction_sb_cLdL sb_cLdL;
    mutable NNfunction_sb_cLdR sb_cLdR;
    mutable NNfunction_sb_cLsL sb_cLsL;
    mutable NNfunction_sb_cLsR sb_cLsR;
    mutable NNfunction_sb_cLuL sb_cLuL;
    mutable NNfunction_sb_cLuR sb_cLuR;
    mutable NNfunction_sb_cRcR sb_cRcR;
    mutable NNfunction_sb_dLcR sb_dLcR;
    mutable NNfunction_sb_dLdL sb_dLdL;
    mutable NNfunction_sb_dLdR sb_dLdR;
    mutable NNfunction_sb_dLsR sb_dLsR;
    mutable NNfunction_sb_dLuR sb_dLuR;
    mutable NNfunction_sb_dRcR sb_dRcR;
    mutable NNfunction_sb_dRdR sb_dRdR;
    mutable NNfunction_sb_dRsR sb_dRsR;
    mutable NNfunction_sb_sLcR sb_sLcR;
    mutable NNfunction_sb_sLdL sb_sLdL;
    mutable NNfunction_sb_sLdR sb_sLdR;
    mutable NNfunction_sb_sLsL sb_sLsL;
    mutable NNfunction_sb_sLsR sb_sLsR;
    mutable NNfunction_sb_sLuL sb_sLuL;
    mutable NNfunction_sb_sLuR sb_sLuR;
    mutable NNfunction_sb_sRcR sb_sRcR;
    mutable NNfunction_sb_sRsR sb_sRsR;
    mutable NNfunction_sb_uLcR sb_uLcR;
    mutable NNfunction_sb_uLdR sb_uLdR;
    mutable NNfunction_sb_uLsR sb_uLsR;
    mutable NNfunction_sb_uLuL sb_uLuL;
    mutable NNfunction_sb_uLuR sb_uLuR;
    mutable NNfunction_sb_uRcR sb_uRcR;
    mutable NNfunction_sb_uRdR sb_uRdR;
    mutable NNfunction_sb_uRsR sb_uRsR;
    mutable NNfunction_sb_uRuR sb_uRuR;
    mutable NNfunction_ss_cLcL ss_cLcL;
    mutable NNfunction_ss_cLcR ss_cLcR;
    mutable NNfunction_ss_cLdL ss_cLdL;
    mutable NNfunction_ss_cLdR ss_cLdR;
    mutable NNfunction_ss_cLsL ss_cLsL;
    mutable NNfunction_ss_cLsR ss_cLsR;
    mutable NNfunction_ss_cLuL ss_cLuL;
    mutable NNfunction_ss_cLuR ss_cLuR;
    mutable NNfunction_ss_cRcR ss_cRcR;
    mutable NNfunction_ss_dLcR ss_dLcR;
    mutable NNfunction_ss_dLdL ss_dLdL;
    mutable NNfunction_ss_dLdR ss_dLdR;
    mutable NNfunction_ss_dLsR ss_dLsR;
    mutable NNfunction_ss_dLuR ss_dLuR;
    mutable NNfunction_ss_dRcR ss_dRcR;
    mutable NNfunction_ss_dRdR ss_dRdR;
    mutable NNfunction_ss_dRsR ss_dRsR;
    mutable NNfunction_ss_sLcR ss_sLcR;
    mutable NNfunction_ss_sLdL ss_sLdL;
    mutable NNfunction_ss_sLdR ss_sLdR;
    mutable NNfunction_ss_sLsL ss_sLsL;
    mutable NNfunction_ss_sLsR ss_sLsR;
    mutable NNfunction_ss_sLuL ss_sLuL;
    mutable NNfunction_ss_sLuR ss_sLuR;
    mutable NNfunction_ss_sRcR ss_sRcR;
    mutable NNfunction_ss_sRsR ss_sRsR;
    mutable NNfunction_ss_uLcR ss_uLcR;
    mutable NNfunction_ss_uLdR ss_uLdR;
    mutable NNfunction_ss_uLsR ss_uLsR;
    mutable NNfunction_ss_uLuL ss_uLuL;
    mutable NNfunction_ss_uLuR ss_uLuR;
    mutable NNfunction_ss_uRcR ss_uRcR;
    mutable NNfunction_ss_uRdR ss_uRdR;
    mutable NNfunction_ss_uRsR ss_uRsR;
    mutable NNfunction_ss_uRuR ss_uRuR;
    mutable NNfunction_t1t1 t1t1;
    mutable NNfunction_t2t2 t2t2;
    mutable NNfunction_uLg uLg;
    mutable NNfunction_uRg uRg;

    // Map for pid codes and strings
    map<int,string> pidmap;

    void _init_pidmap();

    void _params_from_py8slha(double par[24], Pythia8::SusyLesHouches & point) const;

  public:

    Evaluator() { _init_pidmap(); }

    string get_process(int pid1, int pid2) const;

    double xsec(const vector<int>& parts1, const vector<int>& parts2, double * par) const;
    double xsec(const vector<int>& parts1, const vector<int>& parts2, Pythia8::SusyLesHouches& point) const;
    double xsec(const vector<int>& parts1, const vector<int>& parts2, const string& slhafile) const;

    double xsec(int pid1, int pid2, double * par) const;
    double xsec(int pid1, int pid2, Pythia8::SusyLesHouches& point) const;
    double xsec(int pid1, int pid2, const string& slhafile) const;

    double xsec(const string& process, double * par) const;
    double xsec(const string& process, Pythia8::SusyLesHouches& point) const;
    double xsec(const string& process, const string& slhafile) const;

    double log10xsec(const string& process, double * par) const;

  };

  /// @name Unbound functions
  //@{
  inline double xsec(const vector<int>& pids1, const vector<int>& pids2, double * par) { Evaluator e; return e.xsec(pids1, pids2, par); }
  inline double xsec(const vector<int>& pids1, const vector<int>& pids2, Pythia8::SusyLesHouches& point) { Evaluator e; return e.xsec(pids1, pids2, point); }
  inline double xsec(const vector<int>& pids1, const vector<int>& pids2, const string& slhafile) { Evaluator e; return e.xsec(pids1, pids2, slhafile); }

  inline double xsec(int pid1, int pid2, double * par) { Evaluator e; return e.xsec(pid1, pid2, par); }
  inline double xsec(int pid1, int pid2, Pythia8::SusyLesHouches& point) { Evaluator e; return e.xsec(pid1, pid2, point); }
  inline double xsec(int pid1, int pid2, const string& slhafile) { Evaluator e; return e.xsec(pid1, pid2, slhafile); }

  inline double xsec(const string& process, double * par) { Evaluator e; return e.xsec(process, par); }
  inline double xsec(const string& process, Pythia8::SusyLesHouches& point) { Evaluator e; return e.xsec(process, point); }
  inline double xsec(const string& process, const string& slhafile) { Evaluator e; return e.xsec(process, slhafile); }
  //@}


}


// extern "C" {
//   void foo(); //{ cout << "DIE" << endl; }
// }


#endif // xsec_h