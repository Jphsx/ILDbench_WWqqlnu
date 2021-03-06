#ifndef HISTS
#define HISTS


#include "TH1D.h"
#include "TH2D.h"
#include "ROOT/TThreadedObject.hxx"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "myselector.C"
#include "TFile.h"
#include "TClass.h"
#include "TKey.h"
#include "TH1.h"
#include <string>

#include "TLorentzVector.h"
//#include "TIter.h"
class histset{
	
	public:
//	   histset(TFile* f,std::string ofilename, std::string tag);	
histset(TFile* f,std::string selmode,std::string cutfile,  std::string tag );

	   void init(); 

	  //lumi stuff
	  double _iLumi;
	  double _Pem;
	  double _Pep;

	  int _nLL;
	  int _nLR;
	  int _nRL;
	  int _nRR;
	
	double _evtwLL;
	double _evtwLR;
	double _evtwRL;
	double _evtwRR;

	void setWeightParams(double iLumi, double Pem, double Pep, int nLL, int nLR, int nRL, int nRR );

	   void AnalyzeEntry(myselector& s); 
	 //  void AnalyzeEntry(mytreevalues& s);

	   //bookeeping enumeration: (if we do this we dont need to worry about hist ptr copies and merging)
	   enum th1d_index{ind_EvisHist, numTH1Hist};
	   enum th2d_index{ numTH2Hist};
	
	std::string _tag{};
	   // make a big vector and load enumerated histograms onto the vector
	 std::vector<ROOT::TThreadedObject<TH1D>* >  TH1Manager{};
	 std::vector<ROOT::TThreadedObject<TH2D>* >  TH2Manager{};
	//std::vector<TH1D> TH1Manager{};
	//st
/*	TH1D* EvisHist{};//{(_tag+"EvisHist").c_str(),"Visible Energy;GeV; Entries per 10 GeV bin", 70, 0 , 700};
	TH1D* PtvisHist{};
	TH1D* nLepHist{};
	TH1D* mwlepHist{};
	TH1D* mwhadHist{};
	TH1D* EcomHist{};
	TH1D* nRemHist{};
	TH1D* vrecoilHist{};
	TH1D* wlrecoilHist{};
	TH1D* ntracksHist{};
	TH1D* costwlHist{};
	TH1D* costwqHist{};
	TH1D* qcostHist{};
////gen diff lots
	TH1D* mqqdiffHist{};
	TH1D* qcostdiffHist{};

        TH1D* EvisHist2{};//{(_tag+"EvisHist").c_str(),"Visible Energy;GeV; Entries per 10 GeV bin", 70, 0 , 700};
        TH1D* PtvisHist2{};
        TH1D* nLepHist2{};
        TH1D* mwlepHist2{};
        TH1D* mwhadHist2{};
        TH1D* EcomHist2{};
        TH1D* nRemHist2{};
        TH1D* vrecoilHist2{};
        TH1D* wlrecoilHist2{};
        TH1D* ntracksHist2{};
        TH1D* costwlHist2{};
        TH1D* costwqHist2{};
        TH1D* qcostHist2{};
*/
/*
	TH1D* maxntracksNum{};
        TH1D* maxntracksDen{};
	TH1D* minntracksNum{};
        TH1D* minntracksDen{};
        TH1D* minvisptNum{};
        TH1D* minvisptDen{};
        TH1D* minviseNum{};
        TH1D* minviseDen{};
        TH1D* maxviseNum{};
        TH1D* maxviseDen{};
        TH1D* minrootsNum{};
        TH1D* minrootsDen{};
        TH1D* maxrootsNum{};
        TH1D* maxrootsDen{};
        TH1D* minqqmassNum{};
        TH1D* minqqmassDen{};
        TH1D* maxqqmassNum{};
        TH1D* maxqqmassDen{};
        TH1D* minqcostNum{};
        TH1D* minqcostDen{};
*/

	TH1D* mqqOL{};
        TH1D* mqqDiffOL{};
        TH1D* mqqCuts{};
        TH1D* mqqDiffCuts{};
        TH1D* mqqCutsFine{};
        TH1D* mqqDiffCutsFine{};

	TH1D* mqqUDOL{};
	TH1D* mqqCSOL{};
	TH1D* mqqDiffUDOL{};
	TH1D* mqqDiffCSOL{};

	TH1D* mqqUDCuts{};
	TH1D* mqqCSCuts{};
	TH1D* mqqUDCutsFine{};
	TH1D* mqqCSCutsFine{};
	TH1D* mqqDiffUDCuts{};
	TH1D* mqqDiffCSCuts{};
	
	TH1D* mqqDiffUDCutsFine{};
	TH1D* mqqDiffCSCutsFine{};

        TH1D* ipd0sig{};
        TH1D* ip3dsig{};

	TH1D* chargeID{};
	TH1D* chargeIDpost{};
        void processCutFile(std::string cutfile);



	bool electronsBG = false;
	bool electrons = false;
	bool muons = false;
	bool taus = false;
	bool muonsBG = false;
	bool tausBG = false;
	  //locate the histogram and perform ptr copying 
	  void FillTH1(int index, double x, double w);
	  void FillTH2(int index, double x, double y);
	
	  void WriteHist(std::string outputfilename, std::string TFileOption);

	//Tag for compiling multiple datasets into same file which share the same plots
	//std::string _tag{}; 
	//this tag will automatically appended to the variable name in each histogram on write
	
	//cut flow stuff
	bool orderCuts = true;
	//std::vector<std::string> _cutsequence{"nocut", "lepton", "ntracks", "esum","roots","mwlep", "mwhad", "costwl", "costwq"};
//	std::vector<std::string> _cutsequence{"nocut", "lepton", "ntracks","ptcut", "esum", "roots", "mwhad","mwlep", "qcostw"};
//	std::vector<std::string> _cutsequence{"nocut", "lepton", "ntracks", "ptcut", "esum", "roots", "mwhad", "qcostw"};
	std::vector<int> _nLLpass{};
	std::vector<int> _nLRpass{};
	std::vector<int> _nRLpass{};
	std::vector<int> _nRRpass{};
	std::vector<int> _nTotpass{};	

std::vector<std::string> _cutsequence{"nocut","lepton"};
       // std::vector<double> _cutrangeLO{1,1};
        //std::vector<double> _cutrangeHI{1,1};
        //std::vector<double> _cutbin{1,1};
	std::vector<double> _cutval{1,1};

		
	
	std::vector<int>& getPassPol(int pol1, int pol2);

	void printtables();
	void normtables();
	void printtablesspecial();	
	bool _tauConeMode=false;
	//cut descriptions
	// lepton = ntau0 > 0
	// ntracks = total track multiplicity > 10
	// esum = total visible energy < 500 GeV
	// roots = center of mass energy (rest frame mass) > 100 GeV
	// mwlep = 40 < leptonic w mass < 120
	// mwhad = 40 < hadronic w mass < 120
	// costw = cos thetaW  > -0.95
	
	
};
template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
void histset::processCutFile(std::string cutfile){
        ifstream file;
        file.open (cutfile);
        //$ means set a value that is optimized
        //
        //* means scan for optimal value        
          std::string line;
         while (getline(file, line)) {
                // using printf() in all tests for consistency
     //         printf("%s", line.c_str());i
                std::vector<std::string> strs = split(line,  ' ');
                //push back cut names 
                _cutsequence.push_back(strs[1]);
                _cutval.push_back(std::stod(strs[2]));
 	//               _cutrangeHI.push_back(std::stod(strs[3]));
        //        _cutbin.push_back(std::stod(strs[4]));
         }
  //    getline(file, line);
//      std::vector<std::string> strs = split(line, ' ');
	for(int i=0; i< _cutsequence.size(); i++){
                std::cout<<_cutsequence.at(i)<<" "<<_cutval.at(i)<<" ";//<<_cutrangeHI.at(i)<<" "<<_cutbin.at(i)<<" ";
        }
        std::cout<<std::endl;

         file.close();
}

histset::histset(TFile* f,std::string selmode,std::string cutfile,  std::string tag = "" ){

	_tag = tag; 

	if(selmode.compare("LOOSE")==0){ _tauConeMode = true;

     //   std::vector<std::string> cutsequence{"nocut", "lepton","mucone", "ntracks","ptcut", "esum", "roots", "mwhad", "qcostw"};
      //  _cutsequence = cutsequence;
       _cutsequence.push_back("mucone");
//         _cutrangeLO.push_back(1);
  //       _cutrangeHI.push_back(1);
    //     _cutbin.push_back(1);
	_cutval.push_back(1);

	 }


	if(_tag.compare("WS1")==0){
		electrons = true;
	}
	if(_tag.compare("WSBG")==0){
		electronsBG = true;
	}
	if(_tag.compare("WWS1")==0){
		muons = true;
	}
	if(_tag.compare("WWS2")==0){
		taus = true;
	}
	if(_tag.compare("WWS1BG")==0){
		muonsBG = true;
	}
	if(_tag.compare("WWS2BG")==0){
		tausBG = true;
	}

	processCutFile(cutfile);	

	init();

}
void histset::setWeightParams(double iLumi, double Pem, double Pep, int nLL, int nLR, int nRL, int nRR ){
 	_iLumi = iLumi;
	_Pem = Pem;
	_Pep = Pep;
	_nLL = nLL;
	_nLR = nLR;
	_nRL = nRL;
	_nRR = nRR;

	std::cout<<"Running with "<<iLumi<<" "<<Pem<<" "<<Pep<<" "<<" "<<nLL<<" "<<nLR<<" "<<nRL<<" "<<nRR<<std::endl;
	//init evt cut counters
	std::vector<int> LL(_cutsequence.size());
	std::vector<int> LR(_cutsequence.size());
	std::vector<int> RL(_cutsequence.size());
	std::vector<int> RR(_cutsequence.size());	
	std::vector<int> TOT(_cutsequence.size());
	LL[0] = 0;// _nLL;
	LR[0] = 0;//_nLR;
	RL[0] = 0;//_nRL;
	RR[0] = 0;//_nRR;

	TOT[0] = 0;// _nLL + _nLR + _nRL + _nRR;

	for(unsigned int i=1; i<_cutsequence.size(); i++){
		LL[i] = 0;
		LR[i] = 0;
		RL[i] = 0;
		RR[i] = 0;
		TOT[i] = 0;
	}
	_nLLpass = LL;
	_nLRpass = LR;
	_nRLpass = RL;
	_nRRpass = RR;
	_nTotpass = TOT;

	
}
template <class type>
void printvec(std::vector<type> vec){
	for(unsigned int i=0; i< vec.size(); i++){
	std::cout<<vec[i]<<" ";
	}
	std::cout<<std::endl;
}
void histset::normtables(){
	for(unsigned int i=0; i<_nLLpass.size(); i++){
		_nLLpass[i]= _nLLpass[i]*_evtwLL;
		_nLRpass[i]= _nLRpass[i]*_evtwLR;
		_nRLpass[i]= _nRLpass[i]*_evtwRL;
		_nRRpass[i]= _nRRpass[i]*_evtwRR;
	}
}
void histset::printtablesspecial(){
        for(unsigned int i=0; i< _nTotpass.size(); i++){
                _nTotpass.at(i) = _nLLpass[i] + _nLRpass[i] + _nRLpass[i] + _nRRpass[i];
        }
        std::cout<<"$$ "<<_tag<<" cut "<<" ";
        printvec( _cutsequence );
        std::cout<<" LL "<<" ";
        printvec( _nLLpass );
        std::cout<<" LR " << " ";
        printvec( _nLRpass );
        std::cout<<" RL " << " ";
        printvec( _nRLpass );
        std::cout<<" RR " << " ";
        printvec( _nRRpass );
        std::cout<<"$$ "<<_tag<<" tot " << " ";
        printvec( _nTotpass );

}
 
void histset::printtables(){
	//sum tot
	for(unsigned int i=0; i< _nTotpass.size(); i++){
		_nTotpass.at(i) = _nLLpass[i] + _nLRpass[i] + _nRLpass[i] + _nRRpass[i];
	}	
	std::cout<<"* "<<_tag<<" cut "<<" ";
	printvec( _cutsequence );
	std::cout<<" LL "<<" ";
	printvec( _nLLpass );
	std::cout<<" LR " << " ";
	printvec( _nLRpass );
	std::cout<<" RL " << " ";
	printvec( _nRLpass );
	std::cout<<" RR " << " ";
	printvec( _nRRpass );
	std::cout<<"* "<<_tag<<" tot " << " ";
	printvec( _nTotpass );
	
	
}
void histset::init(){
/*	
	EvisHist = new TH1D((_tag+"EvisHist").c_str(),"Visible Energy;GeV; Entries per 10 GeV bin", 70, 0 , 700 );
	PtvisHist = new TH1D((_tag+"PtvisHist").c_str(),"Visible Pt; GeV; Entries per 10 GeV bin",50,0,500);
	nLepHist = new TH1D((_tag+"nLepHist").c_str(),"Number of Reconstructed Leptons; n #l jets; Entries Per Lepton",11,-0.5,10.5);
	mwlepHist = new TH1D((_tag+"mwlepHist").c_str(),"W #rightarrow l #nu Reconstructed Mass; Mass GeV; Entries Per 5 GeV Bin", 50,0,250);
	mwhadHist = new TH1D((_tag+"mwhadHist").c_str(),"W #rightarrow qq Reconstructed Mass;Mass GeV; Entries Per 5 GeV Bin", 50,0,250);
	EcomHist = new TH1D((_tag+"EcomHist").c_str(),"#sqrt{s};GeV; Entries per 10 GeV bin", 70,0, 700);
	nRemHist = new TH1D((_tag+"nRemHist").c_str(), "Number of Jet Fragments;N Jets",21,-0.5,20.5);
	vrecoilHist = new TH1D((_tag+"vrecoilHist").c_str(),"Mass^{2} Recoiling from qql;  GeV^{2}; Entries per 1e4 GeV^{2} bin",25,-100,300000);
	wlrecoilHist = new TH1D((_tag+"wlrecoilHist").c_str(),"Mass^{2} Recoiling from qq; GeV^{2}; Entries per 1e4 GeV^{2} bin",25,-100,300000);
	ntracksHist = new TH1D((_tag+"ntracksHist").c_str(),"Total Track Multiplicity; N Tracks",101,-0.5,100.5);
	costwlHist = new TH1D((_tag+"costwlHist").c_str(),"Leptonic W cos#theta;cos#theta;Entries per .01 bin",200,-1,1);
	costwqHist = new TH1D((_tag+"costwqHist").c_str(),"Hadronic W cos#theta;cos#theta;Entries per .01 bin",200,-1,1);
	qcostHist = new TH1D((_tag+"qcostHist").c_str(),"W Scattering angle; -qcos#theta",200,-1,1);

	 mqqdiffHist = new TH1D((_tag+"mqqdiffHist").c_str(),"Measured and Gen. Mass Difference ;M^{meas}_{qq}-M^{gen}_{qq} ;Events per 2 GeV bin",100,-100,100 );
         qcostdiffHist = new TH1D((_tag+"qcostdiffHist").c_str(), "Measured and Gen W^{-} Scattering Difference; -q(cos#theta^{meas}_{W} - cos#theta^{gen}_{W}); Events per 0.05 bin",40,-1,1);

*/
//	if(electrons){

/*
        EvisHist2 = new TH1D((_tag+"BGEvisHist").c_str(),"Visible Energy;GeV; Entries per 10 GeV bin", 70, 0 , 700 );
        PtvisHist2 = new TH1D((_tag+"BGPtvisHist").c_str(),"Visible Pt; GeV; Entries per 10 GeV bin",50,0,500);
        nLepHist2 = new TH1D((_tag+"BGnLepHist").c_str(),"Number of Reconstructed Leptons; n #l jets; Entries Per Lepton",11,-0.5,10.5);
        mwlepHist2 = new TH1D((_tag+"BGmwlepHist").c_str(),"W #rightarrow l #nu Reconstructed Mass; Mass GeV; Entries Per 5 GeV Bin", 50,0,250);
        mwhadHist2 = new TH1D((_tag+"BGmwhadHist").c_str(),"W #rightarrow qq Reconstructed Mass;Mass GeV; Entries Per 5 GeV Bin", 50,0,250);
        EcomHist2 = new TH1D((_tag+"BGEcomHist").c_str(),"#sqrt{s};GeV; Entries per 10 GeV bin", 70,0, 700);
        nRemHist2 = new TH1D((_tag+"BGnRemHist").c_str(), "Number of Jet Fragments;N Jets",21,-0.5,20.5);
        vrecoilHist2 = new TH1D((_tag+"BGvrecoilHist").c_str(),"Mass^{2} Recoiling from qql;  GeV^{2}; Entries per 1e4 GeV^{2} bin",25,0,250000);
        wlrecoilHist2 = new TH1D((_tag+"BGwlrecoilHist").c_str(),"Mass^{2} Recoiling from qq; GeV^{2}; Entries per 1e4 GeV^{2} bin",25,0,250000);
        ntracksHist2 = new TH1D((_tag+"BGntracksHist").c_str(),"Total Track Multiplicity; N Tracks",101,-0.5,100.5);
        costwlHist2 = new TH1D((_tag+"BGcostwlHist").c_str(),"Leptonic W cos#theta;cos#theta;Entries per .01 bin",200,-1,1);
        costwqHist2 = new TH1D((_tag+"BGcostwqHist").c_str(),"Hadronic W cos#theta;cos#theta;Entries per .01 bin",200,-1,1);
        qcostHist2 = new TH1D((_tag+"BGqcostHist").c_str(),"W Scattering angle; -qcos#theta",200,-1,1); */
//	}

/*
	maxntracksNum = new TH1D((_tag+"maxntracksNUM").c_str(), "Maximum Track Multiplicity;Ntracks < x;#epsilon",65,0.5,65.5);
        maxntracksNum->Sumw2 (true);
        maxntracksDen = new TH1D((_tag+"maxntracksDEN").c_str(), "maxtracks den",65,0.5,65.5);
        maxntracksDen->Sumw2(true);
	
	minntracksNum= new TH1D((_tag+"minntracksNUM").c_str(), "Minimum Track Multiplicity;Ntracks > x;#epsilon",20,0.5,20.5);
        minntracksDen= new TH1D((_tag+"minntracksDEN").c_str(), "Minimum Track Multiplicity;Ntracks > x;#epsilon",20,0.5,20.5);
        minntracksNum->Sumw2 (true);
        minntracksDen->Sumw2 (true);

        minvisptNum= new TH1D((_tag+"minvisptNUM").c_str(), "Minimum Visible Pt;Pt > x;#epsilon",51,-.5,50.5);
        minvisptDen= new TH1D((_tag+"minvisptDEN").c_str(), "Minimum Visible Pt;Pt > x;#epsilon",51,-.5,50.5);
        minvisptNum->Sumw2 (true);
        minvisptDen->Sumw2 (true);


        minviseNum= new TH1D((_tag+"minviseNUM").c_str(), "Minimum Visible Energy;E_{vis} > x;#epsilon",26,-5,255);
        minviseDen= new TH1D((_tag+"minviseDEN").c_str(), "Minimum Visible Energy;E_{vis} > x;#epsilon",26,-5,255);
        minviseNum->Sumw2 (true);
        minviseDen->Sumw2 (true);

        maxviseNum= new TH1D((_tag+"maxviseNUM").c_str(), "Maximum Visible Energy;E_{vis} < x;#epsilon",24,465,705);
        maxviseDen= new TH1D((_tag+"maxviseDEN").c_str(), "Maximum Visible Energy;E_{vis} < x;#epsilon",24,465,705);
        maxviseNum->Sumw2 (true);
        maxviseDen->Sumw2 (true);

        minrootsNum= new TH1D((_tag+"minrootsNUM").c_str(), "Minimum Total Rest Energy;#sqrt{s} > x;#epsilon",41,-5,405);
        minrootsDen= new TH1D((_tag+"minrootsDEN").c_str(), "Minimum Total Rest Energy;#sqrt{s} > x;#epsilon",41,-5,405);
        minrootsNum->Sumw2 (true);
        minrootsDen->Sumw2 (true);

        maxrootsNum =new TH1D((_tag+"maxrootsNUM").c_str(), "Maximum Total Rest Energy;#sqrt{s} < x;#epsilon",24,465,705);
        maxrootsDen=new TH1D((_tag+"maxrootsDEN").c_str(), "Maximum Total Rest Energy;#sqrt{s} < x;#epsilon",24,465,705);
        maxrootsNum->Sumw2 (true);
        maxrootsDen->Sumw2 (true);

        minqqmassNum =new TH1D((_tag+"minqqmassNUM").c_str(), "Minimum Hadronic Mass;M_{qq} > x;#epsilon",71,-0.5,70.5);
        minqqmassDen =new TH1D((_tag+"minqqmassDEN").c_str(), "Minimum Hadronic Mass;M_{qq} > x;#epsilon",71,-0.5,70.5);
        minqqmassNum->Sumw2 (true);
        minqqmassDen->Sumw2 (true);

        maxqqmassNum=new TH1D((_tag+"maxqqmassNUM").c_str(), "Maximum Hadronic Mass;M_{qq} < x;#epsilon",301,99.5,400.5);
        maxqqmassDen=new TH1D((_tag+"maxqqmassDEN").c_str(), "Maximum Hadronic Mass;M_{qq} < x;#epsilon",301,99.5,400.5);
        maxqqmassNum->Sumw2 (true);
        maxqqmassDen->Sumw2 (true);

        minqcostNum=new TH1D((_tag+"minqcostNUM").c_str(), "Minimum W^{-} deflection angle;-qcos#theta > x;#epsilon",191,-100.500, 90.500);
        minqcostDen=new TH1D((_tag+"minqcostDEN").c_str(), "Minimum W^{-} deflection angle; -qcos#theta > x;#epsilon",191,-100.500,90.500);
        minqcostNum->Sumw2 (true);
        minqcostDen->Sumw2 (true);
	*/
	mqqOL = new TH1D((_tag+"mqqOL").c_str(), "W#rightarrow qq Mass with pile-up;GeV;Entries per GeV bin",200,0,200);
        mqqDiffOL = new TH1D((_tag+"mqqDiffOL").c_str(), "W#rightarrow qq Gen. Mass Difference;M_{qq}^{meas}-M_{qq}^{gen};Events per GeV bin", 200, -100,100);
        mqqCuts = new TH1D((_tag+"mqqCuts").c_str(),"W#rightarrow qq Mass;GeV;Entries per GeV bin",200,0,200);
        mqqDiffCuts = new TH1D((_tag+"mqqDiffCuts").c_str(),"W#rightarrow qq Gen. Mass Difference;GeV;Entries per GeV bin",200,-100,100);
        mqqCutsFine = new TH1D((_tag+"mqqCutsFine").c_str(),"W#rightarrow qq Mass;GeV;Entries per 0.1 GeV bin",2000, 0,200);
        mqqDiffCutsFine = new TH1D((_tag+"mqqDiffCutsFine").c_str(), "W#rightarrow qq Gen Mass Difference;GeV;Entries per 0.1 GeV bin",2000,-100,100);


	mqqUDOL = new TH1D((_tag+"mqqUDOL").c_str(),"W#rightarrow ud with pile-up;GeV;Entries per GeV bin",200,0,200);
        mqqCSOL = new TH1D((_tag+"mqqCSOL").c_str(),"W#rightarrow cs with pile-up;GeV;Entries per GeV bin",200,0,200);
        mqqDiffUDOL = new TH1D((_tag+"mqqDiffUDOL").c_str(),"W#rightarrow ud Gen. Mass Difference; M_{qq}^{meas}-M_{qq}^{gen};Events per GeV bin", 200, -100,100);
        mqqDiffCSOL = new TH1D((_tag+"mqqDiffCSOL").c_str(),"W#rightarrow cs Gen. Mass Difference; M_{qq}^{meas}-M_{qq}^{gen};Events per GeV bin", 200, -100,100);

        mqqUDCuts = new TH1D((_tag+"mqqUDCuts").c_str(),"W#rightarrow ud Mass;GeV;Entries per GeV bin",200,0,200);
        mqqCSCuts = new TH1D((_tag+"mqqCSCuts").c_str(),"W#rightarrow cs Mass;GeV;Entries per GeV bin",200,0,200);
        mqqDiffUDCuts = new TH1D((_tag+"mqqDiffUDCuts").c_str(),"W#rightarrow ud Gen. Mass Difference;M_{qq}^{meas}-M_{qq}^{gen};Entries per GeV bin",200,-100,100);
        mqqDiffCSCuts= new TH1D((_tag+"mqqDiffCSCuts").c_str(),"W#rightarrow cs Gen. Mass Difference;M_{qq}^{meas}-M_{qq}^{gen};Entries per GeV bin",200,-100,100);

	mqqUDCutsFine = new TH1D((_tag+"mqqUDCutsFine").c_str(),"W#rightarrow ud Mass;GeV;Entries per GeV bin",200,0,200);
	mqqCSCutsFine = new TH1D((_tag+"mqqCSCutsFine").c_str(),"W#rightarrow cs Mass;GeV;Entries per GeV bin",200,0,200);
        mqqDiffUDCutsFine= new TH1D((_tag+"mqqDiffUDCutsFine").c_str(), "W#rightarrow ud Gen Mass Difference;M_{qq}^{meas}-M_{qq}^{gen};Entries per 0.1 GeV bin",2000,-100,100);
        mqqDiffCSCutsFine = new TH1D((_tag+"mqqDiffCSCutsFine").c_str(), "W#rightarrow cs Gen Mass Difference;M_{qq}^{meas}-M_{qq}^{gen};Entries per 0.1 GeV bin",2000,-100,100);

        ipd0sig = new TH1D((_tag+"d0sig").c_str(),"Lepton Candidate leading track Transverse IP significance;#sigma_{d0}/d0",100,0,100);
        ip3dsig = new TH1D((_tag+"ip3dsig").c_str(),"Lepton Candidate leading track 3D IP significance;#sigma_{ip3D}/ip3D",100,0,100);


	chargeID = new TH1D((_tag+"chargeID").c_str(),"Lepton charge id",2,-.5,1.5);	
	chargeIDpost = new TH1D((_tag+"chargeIDpost").c_str(),"Lepton charge id after cuts",2,-.5,1.5);
//init TH1D
	//TH1Manager.at(ind_EvisHist) = new ROOT::TThreadedObject<TH1D>("EvisHist", "Visble Energy;GeV;Entries per 10 GeV bin", 70, 0, 700);
// init TH2D
	//TH2Manager.at(ind_cat0PtcmPtisrDphiCMIHist) = new ROOT::TThreadedObject<TH2D>("cat0PtcmPtisrDphiCMIHist", "cat0: PTCM/PTISR vs dphiCMI ;dphiCMI;PTCM/PTISR", 50, 0, 3.2, 50, 0,2);
	//TH2Manager.at(ind_cat1PtcmPtisrDphiCMIHist) = new ROOT::TThreadedObject<TH2D>("cat1PtcmPtisrDphiCMIHist", "cat1: PTCM/PTISR vs dphiCMI;dphiCMI;PTCM/PTSIR", 50, 0, 3.2,50, 0,2);

}
void histset::FillTH1(int index, double x, double w=1){
	//we must make ptr copies for performance reasons when trying to fill a histogram
	auto myhist = TH1Manager.at(index)->Get();
	myhist->Fill(x,w);
}
void histset::FillTH2(int index, double x, double y){
	auto myhist = TH2Manager.at(index)->Get();
	myhist->Fill(x,y);
}
void histset::WriteHist(std::string outputfilename, std::string TFileOption){

	TFile* outfile = new TFile(outputfilename.c_str(),TFileOption.c_str());


	for(int i=0; i<numTH1Hist; i++){
		//do a check for entries, merge isnt safe on 0 entry histograms
		auto hptr = TH1Manager.at(i)->Get();		
		if(hptr->GetEntries() > 0){
			auto histmerged = TH1Manager.at(i)->Merge();
			TH1D* h = (TH1D*) histmerged->Clone();
			std::string hname(h->GetName());
			outfile->WriteObject(h, (_tag+hname).c_str() );
		}
		else{
			auto h = TH1Manager.at(i)->Get()->Clone();
			std::string hname(h->GetName());
			outfile->WriteObject(h, (_tag+hname).c_str() );
		}
	}

	for(int i=0; i<numTH2Hist; i++){
		auto hptr = TH2Manager.at(i)->Get();
		if(hptr->GetEntries() > 0){
			auto histmerged = TH2Manager.at(i)->Merge();
			TH2D* h = (TH2D*) histmerged->Clone();
			std::string hname(h->GetName());
			outfile->WriteObject(h,(_tag+hname).c_str() );
		}
		else{
			auto h = TH2Manager.at(i)->Get()->Clone();
			std:;string hname(h->GetName());
			outfile->WriteObject(h, (_tag+hname).c_str() );
		}
	}	

}
void docuteff(TH1D* num,TH1D* den, double xlow, double xup, double bin, std::function<bool(double,double)> func, double value, double evtw){
        //declare operation 
        // 1 => observed value < cut value X
        // 2 => observed value = cut value X
        // 3 => observed value > cut value X
        //we pass in operation func such that func(observedvalue, cutvalue)     

        //this will be slow to do everytime
        //based on xlow xup generate cuts
        std::vector<double> cuts{xlow};
        for(double i= xlow+bin; i<=xup; i=i+bin){
                cuts.push_back(i);
        //        std::cout<<"cuts "<<i<<" ";
        }
      //  std::cout<<std::endl;

        //loop over cuts and fill
        bool pass;
        for(int i=0; i<cuts.size(); i++){
                pass = func(value,cuts[i]);
                if(pass){
                        num->Fill(cuts[i], evtw);
                }
                den->Fill(cuts[i],evtw);
        }




}

bool leptoncut(int& count, int ntau){
	if(ntau > 0){ 
		count++;
		return true;
	}
	return false;
}
bool ntrackscut(int& count, int ntrks){
	if(ntrks > 10){
		count++;
		return true;
	}
	return false;
}
bool esumcut(int& count, double evis){
	if( evis < 500){
		count++;
		return true;
	}
	return false;
}
bool rootscut(int& count, double ecom){
	if( ecom > 100){
		count++;
		return true;
	}
	return false;
}
bool mwlepcut(int& count, double wlmass){
	if( wlmass > 20 && wlmass < 140 ){
		count++;
		return true;
	}
	return false;
}
bool mwhadcut(int& count, double wqmass){
	if( wqmass > 40 && wqmass < 120){
		count++;
		return true;
	}
	return false;
}
bool costwcut(int& count, double costw){
	if( costw > -0.95 ){
		count++;
		return true;
	}
	return false;
}
bool qcostw(int& count,double ql, double qq, double qcostl,double qcostqq){
	//determination of W- only
	double qcost;
	if(ql <0){
		qcost = qcostl;
	}
	else{
		qcost = qcostqq;
	}
	if( (qcost > -0.95) ){
		count++;
		return true;
	}
	return false;
}
bool ptcut(int& count, double pt){
	if( pt > 5){
		count++;
		return true;
	}
	return false;
}
bool nocut(int& count){
		count++;
		return true;
	}
bool muconecut(int& count, double nmucone){
        if( nmucone == 0){
                count++;
                return true;
        }
        return false;

}
bool performcut(int& count, double observedvalue, double cutvalue, std::function<bool(double,double)> func ){
        if( func(observedvalue, cutvalue) ){
                count++;
                return true;
        }
        return false;

}


std::vector<int>& histset::getPassPol(int pol1, int pol2){
	if(pol1 == -1 && pol2 == -1) return _nLLpass;
	if(pol1 == -1 && pol2 == 1) return _nLRpass;
	if(pol1 == 1 && pol2 == -1) return _nRLpass;
	if(pol1 == 1 && pol2 == 1) return _nRRpass;
}
void histset::AnalyzeEntry(myselector& s){
   	
	//always make a local copy, if its a value dereference.. if you dont do this scope/dereferencing will get really weird, clunky, and unmanageable
	//have to auto& or myreader will try to register copy of the readerarray ptr
	//auto MET = *(s.MET);
	//polarization stuff
//	 Pem = -0.8;
//	 Pep = 0.3;
//do not consdier wrong gen stuff 
	auto genMuon = *(s.isMuon);
	auto genTau = *(s.isTau);
	auto genElectron = *(s.isElectron);
	
	auto& MCf_PDG = s.MCf_PDG;

	auto& MCf_Px = s.MCf_Px;
                auto& MCf_Py = s.MCf_Py;
                auto& MCf_Pz = s.MCf_Pz;
                auto& MCf_E = s.MCf_E;
                TLorentzVector MCf0(MCf_Px[0],MCf_Py[0],MCf_Pz[0],MCf_E[0]);
                TLorentzVector MCf1(MCf_Px[1],MCf_Py[1],MCf_Pz[1],MCf_E[1]);
                TLorentzVector MCf2(MCf_Px[2],MCf_Py[2],MCf_Pz[2],MCf_E[2]);
                TLorentzVector MCf3(MCf_Px[3],MCf_Py[3],MCf_Pz[3],MCf_E[3]);

                bool isBG;
                TLorentzVector Wqq = MCf0+MCf1;
                TLorentzVector Wlnu = MCf2+MCf3;
	
		int trueqWqq;
		int trueqWl;
		if( MCf_PDG[2] > 0){

			trueqWl =-1;
			trueqWqq = 1;
		}	
		else{
			trueqWl = 1;
			trueqWqq = -1;
		}

		if(  Wqq.M() <70. || Wqq.M() > 92 || Wlnu.M() < 70 || Wlnu.M() > 92 ){
                        isBG = true;
                }
                else{
                        isBG = false;
                }
		
		if(muons && (genMuon == 0)) return;
		if(muons && isBG)return;
		if(muonsBG && (genMuon ==0)) return;
		if(muonsBG && !isBG)return;

		if(electrons && (genElectron ==0)) return;
		if(electrons && isBG)return;
		if(electronsBG && (genElectron ==0)) return;
		if(electronsBG && !isBG)return;

		if(taus && (genTau == 0)) return;
		if(taus && isBG) return;
		if(tausBG && (genTau == 0)) return;
		if(tausBG && !isBG) return;


	bool isUD = false;
	bool isCS = false;
	
	if( (abs(MCf_PDG[0]) == 1) || (abs(MCf_PDG[0]) == 2) ){
		if( (abs(MCf_PDG[1]) == 2) || (abs(MCf_PDG[1]) == 1) ){
			isUD = true;
		}
	}
	if( (abs(MCf_PDG[0]) == 3) || (abs(MCf_PDG[0]) ==4) ){
		if( (abs(MCf_PDG[1]) == 4) || (abs(MCf_PDG[1]) == 3) ){
			isCS = true;
		}
	}
	double xangle = 0.007;//7 millrad xangle boost

	double fRm = 0.5*(1+_Pem);
	double fLm = 1-fRm;

	double fRp = 0.5*(1+_Pep);
	double fLp = 1-fRp;

	double wpolLR = fLm*fRp;
	double  wpolRL = fRm*fLp;
	double  wpolLL = fLm*fLp;
	double  wpolRR = fRm*fRp;

	double xsec_new;
	double nev;
	auto pol1 = *(s.polarization1);
	auto pol2 = *(s.polarization2);
	auto xsec = *(s.xsec);

	if( pol1 == -1 && pol2 == -1){
		xsec_new = wpolLL*xsec;
		nev = _nLL;
	}
	if(pol1 == -1 && pol2 == 1){
		xsec_new = wpolLR*xsec;
		nev = _nLR;
	}
	if(pol1 == 1 && pol2 == 1){
		xsec_new = wpolRR*xsec;
		nev = _nRR;
	}
	if(pol1 ==1 && pol2 == -1){
		xsec_new = wpolRL*xsec;
		nev = _nRL;
	}

	double evtw = 1;	
	double thisLumi = ((double)nev)/xsec_new;
	evtw = _iLumi/thisLumi;	

	//norm for Nevt table later, calculate every step because its easier
	if(pol1 == -1 && pol2 == -1){
		_evtwLL=evtw;
	}
	if(pol1 == -1 && pol2 ==1){
		_evtwLR=evtw;
	}
	if(pol1 == 1 && pol2 == -1){
		_evtwRL=evtw;
	}
	if(pol1 == 1 && pol2 == 1){
		_evtwRR=evtw;
	}


	auto candE0 = *(s.candE0);	
	auto& remE0_preclean = s.remE0;
	auto& remPx0_preclean = s.remPx0;
	auto& remPy0_preclean = s.remPy0;
	auto candPx0 = *(s.candPx0);
	auto candPy0 = *(s.candPy0);
	auto nlep = *(s.ntau0);
	auto candPz0 = *(s.candPz0);
	auto& remPz0_preclean = s.remPz0;
	auto njets0_preclean = *(s.njets0);
	auto& candTrkOm0 = s.candTrkOm0;
        auto& candTrktlam0 = s.candTrktlam0;


	if(_tauConeMode){
	candE0 = *(s.candE3);
         remE0_preclean = s.remE3;
         remPx0_preclean = s.remPx3;
         remPy0_preclean = s.remPy3;
        candPx0 = *(s.candPx3);
         candPy0 = *(s.candPy3);
         nlep = *(s.ntau3);
        candPz0 = *(s.candPz3);
         remPz0_preclean = s.remPz3;
         njets0_preclean = *(s.njets3);
         candTrkOm0 = s.candTrkOm3;
         candTrktlam0 = s.candTrktlam3;	

	}

	 auto nmucone = *(s.ntau0);
	auto nPandoraTrks = *(s.nPandoraTrks);

	//ntracksHist->Fill(nPandoraTrks,evtw);

          //locate the histo
//	nLepHist->Fill(nlep, evtw);
//	nRemHist->Fill(njets0, evtw);
	if(nlep ==0){
		nocut(getPassPol(pol1,pol2)[0]);
	 return;
	}
/*	if(nlep >1){ 
		nocut(getPassPol(pol1,pol2)[0]);
		return;
	}
*/

	//jet preprocessing////////////////////////////////////
	//make std 4vecs to house jets after preselection cuts (pt>2Gev)	
	std::vector<double> remPx0{};
	std::vector<double> remPy0{};
	std::vector<double> remPz0{};
	std::vector<double> remE0{};

	TLorentzVector precleanWqq;


	for(unsigned int i = 0; i< remE0_preclean.GetSize(); i++){
		double pt = sqrt(remPx0_preclean[i]*remPx0_preclean[i] + remPy0_preclean[i]*remPy0_preclean[i]);
		TLorentzVector minijet( remPx0_preclean[i], remPy0_preclean[i], remPz0_preclean[i], remE0_preclean[i]);
		precleanWqq += minijet;
		if(pt > 2){
			remPx0.push_back( remPx0_preclean[i]);
			remPy0.push_back( remPy0_preclean[i]);
			remPz0.push_back( remPz0_preclean[i]);
			remE0.push_back( remE0_preclean[i]);

		} 	

	}
	int njets0 = remE0.size();
	//////////////////////////////////////////////////////
//	 nRemHist->Fill(njets0, evtw);

	mqqOL->Fill(precleanWqq.M(),evtw);
        mqqDiffOL->Fill(precleanWqq.M() -  Wqq.M(),evtw);
	if(isUD){
        mqqUDOL->Fill(precleanWqq.M(),evtw);
        mqqDiffUDOL->Fill(precleanWqq.M() - Wqq.M(),evtw);
	}
	if(isCS){
	mqqCSOL->Fill(precleanWqq.M(),evtw);
        mqqDiffCSOL->Fill(precleanWqq.M()- Wqq.M(),evtw);
	}



//	double Emiss;
	double Ejets=0.;
	double Pxjets=0.;
	double Pyjets=0.;
	double Pzjets=0.;
	for(int i=0; i<remE0.size(); i++){
		Ejets = Ejets + remE0[i]; 
		Pxjets = Pxjets + remPx0[i];
		Pyjets = Pyjets + remPy0[i]; 
		Pzjets = Pzjets + remPz0[i];
	}




	double Ptjets= sqrt(Pxjets*Pxjets + Pyjets*Pyjets);
	double Ptcand = sqrt(candPx0*candPx0 + candPy0*candPy0);
	double Evis = candE0 + Ejets;
	//FillTH1(ind_EvisHist, Evis);
//	EvisHist->Fill(Evis, evtw);
//	PtvisHist->Fill(Ptjets+Ptcand, evtw);

//	nLepHist->Fill(nlep, evtw);
//	nRemHist->Fill(njets0, evtw);
		
   //calculate mwlep //neutrino mass approx 0
   	double Pxmiss, Pymiss, Pzmiss;
	Pxmiss = candPx0;
	Pymiss = candPy0;
	Pzmiss = candPz0;
	for(int i=0; i<remE0.size(); i++){
		Pxmiss += remPx0[i];
		Pymiss += remPy0[i];
		Pzmiss += remPz0[i];
	
	}
	Pxmiss = -Pxmiss;
	Pymiss = -Pymiss;
	Pzmiss = -Pzmiss;

	double Pmiss = sqrt(Pxmiss*Pxmiss + Pymiss*Pymiss + Pzmiss*Pzmiss);
	


	//lep mass is 4vec lep + miss
	//
	TVector3 xangleBoost(-sin(0.007),0,0);

	TLorentzVector lep0(candPx0,candPy0, candPz0, candE0 );
	//TLorentzVector nu0(Pxmiss, Pymiss, Pzmiss, Pmiss );
	
	lep0.Boost(xangleBoost);
	//nu0.Boost(xangleBoost);

//	TLorentzVector Wlep0 = lep0+nu0;
//	mwlepHist->Fill(Wlep0.M(), evtw);



	//get had mass
	TLorentzVector Wqq0(Pxjets, Pyjets, Pzjets, Ejets);
	Wqq0.Boost(xangleBoost);

	

//	EvisHist->Fill((lep0+Wqq0).E(), evtw);
//	PtvisHist->Fill((lep0+Wqq0).Pt(), evtw);

	//TLorentzVector nu0(-(Wqq0+lep0));
	TLorentzVector nu0;
	nu0.SetXYZM(-(Wqq0+lep0).Px(), -(Wqq0+lep0).Py(), -(Wqq0+lep0).Pz(), 0 );
	TLorentzVector Wlep0 = lep0+nu0;
//	mwlepHist->Fill(Wlep0.M(), evtw);

//	mwhadHist->Fill(Wqq0.M(), evtw);

//	costwlHist->Fill(Wlep0.CosTheta(),evtw);
//	costwqHist->Fill(Wqq0.CosTheta(),evtw);
	
	//boost to CM
	TLorentzVector Tot = Wlep0+Wqq0;
	//TVector3 cmboost =  Tot.BoostVector();
	//Tot.Boost(-cmboost);	
        
	//EcomHist->Fill(Tot.E(), evtw);

	//std::cout<<"TOT: "<<Tot.E()<<" "<<Tot.Px()<<" "<<Tot.Py()<<" "<<Tot.Pz()<<std::endl;
	//test boost things
	//std::cout<<"boostVector "<<cmboost.Px()<<" "<<cmboost.Py()<<" "<<cmboost.Pz()<<std::endl;
	//try boosting vectors by sin(.007)	

	//recoiling masses
	//
	// neutrino mass recoiling against lep + qq
	TLorentzVector qql = lep0+Wqq0;
	double mvrecoil = 500*500 + qql.M()*qql.M() - 2*500*qql.E(); //should be 0?
	
	// wlep mass recoiling against qq
	double mwlrecoil = 500*500 + Wqq0.M()*Wqq0.M() - 2*500*Wqq0.E(); // should be the nominal Wmass

	//adjust masses if <0
/*	if(mvrecoil < 0){
		mvrecoil= sqrt(-mvrecoil);
		//reassign to negative mass
		mvrecoil = -mvrecoil;
	}
	else{
		mvrecoil = sqrt(mvrecoil);		
	}
	if(mwlrecoil < 0){
		mwlrecoil = sqrt(-mwlrecoil);
		mwlrecoil = -mwlrecoil;
	}
	else{
		mwlrecoil = sqrt(mwlrecoil);
	}
*/


//	vrecoilHist->Fill(mvrecoil,evtw);
//	wlrecoilHist->Fill(mwlrecoil,evtw);


	//make some charge determination for each W	
	double qwl;
	double qwqq;
//	auto& candTrkOm0 = s.candTrkOm0;
//	auto& candTrktlam0 = s.candTrktlam0;

	double BField = 3.5;
	const double c = 2.99792458e8; // m*s^-1        
  	const double mm2m = 1e-3;
  	const double eV2GeV = 1e-9;
  	const double eB = BField*c*mm2m*eV2GeV;

	std::vector<double> trackP(candTrkOm0.GetSize());
	std::vector<double> trackq(candTrkOm0.GetSize());

	for(unsigned int i=0; i< candTrkOm0.GetSize(); i++){
		double q = candTrkOm0[i]/fabs(candTrkOm0[i]);
		double om = candTrkOm0[i];
		double tanl = candTrktlam0[i];
		trackq.at(i) = q;
		trackP.at(i) = 	q*eB/om * sqrt(1+tanl*tanl);
	}
	//
	//if there is 1 or !3 tracks take highest P track as wl charge
	if(trackq.size() != 3){
		int indexPMax=0;
		double PMax =0;
		for(unsigned int i=0; i<trackP.size(); i++){
			if(trackP.at(i) > PMax){
				PMax = trackP.at(i);
				indexPMax = i;
			}
		}
		qwl = trackq.at(indexPMax);
		qwqq = qwl*(-1.);	
	}
	if(trackq.size() == 3){
		qwl = trackq.at(0) + trackq.at(1) + trackq.at(2);
		qwqq = qwl*(-1.);
	}
	//qcostHist->Fill(-qwl*Wlep0.CosTheta());
	//qcostHist->Fill(-qwqq*Wqq0.CosTheta());
	if( qwl == trueqWl){
		chargeID->Fill(1);
	}
	else{
		chargeID->Fill(0);
	}
	
// apply cuts
//
//
//_cutsequence{"nocut", "lepton", "ntracks", "esum","roots","mwlep", "mwhad", "costw"};

bool pass;
        for(unsigned int i=0; i<_cutsequence.size(); i++){
                std::string cut = _cutsequence.at(i);
		double cutvalue = _cutval.at(i);
                //double cuthi = _cutrangeHI.at(i);
                //double cutbin = _cutbin.at(i);


		if(cut.compare("nocut")==0){
			pass = nocut(getPassPol(pol1,pol2)[i]);
		}
                if( cut.compare("lepton")==0){ //do lepton cut
                        pass = leptoncut(getPassPol(pol1,pol2)[i], nlep);
                         if(!pass && orderCuts) break;
                }

		 if( cut.compare("maxntracks")==0){
                //      pass = maxntrackscut(getPassPol(pol1,pol2)[i], nPandoraTrks)i;
                        //optimize 
                        //ith element in cut sequce ranges also
                        //(numerator, denominator, xlow, xup, bin)
                        //docuteff(maxntracksNum,maxntracksDen, cutlo,cuthi,cutbin, std::less<double>(), nPandoraTrks, evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], nPandoraTrks, cutvalue, std::less<double>());
                        if(!pass && orderCuts) break;

                }
                if( cut.compare("minntracks")==0){
                        //docuteff(minntracksNum, minntracksDen, cutlo, cuthi, cutbin, std::greater<double>(), nPandoraTrks, evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], nPandoraTrks, cutvalue, std::greater<double>());
                        if(!pass && orderCuts) break;

                }
                if( cut.compare("minvispt")==0){
                        //docuteff(minvisptNum,minvisptDen, cutlo, cuthi, cutbin, std::greater<double>(), (lep0+Wqq0).Pt(), evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], (lep0+Wqq0).Pt(), cutvalue, std::greater<double>());
                        if(!pass && orderCuts) break;
                 }
                if( cut.compare("minvise")==0){
                        //docuteff(minviseNum,minviseDen, cutlo, cuthi, cutbin, std::greater<double>(), Evis, evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], Evis, cutvalue, std::greater<double>());
                        if(!pass && orderCuts) break;

                }
                if( cut.compare("maxvise")==0){
                        //docuteff(maxviseNum,maxviseDen, cutlo, cuthi, cutbin, std::less<double>(), Evis, evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], Evis, cutvalue, std::less<double>());
                        if(!pass && orderCuts) break;

                }
                if( cut.compare("minroots")==0){
                        //docuteff(minrootsNum,minrootsDen, cutlo,cuthi, cutbin, std::greater<double>(), Tot.E(), evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], Tot.E(), cutvalue, std::greater<double>());
                        if(!pass && orderCuts) break;

                }
                if( cut.compare("maxroots")==0){
                       // docuteff(maxrootsNum, maxrootsDen, cutlo, cuthi, cutbin, std::less<double>(), Tot.E(), evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], Tot.E(), cutvalue, std::less<double>());
                        if(!pass && orderCuts) break;

                }
                if( cut.compare("minqqmass")==0){
                        //docuteff(minqqmassNum, minqqmassDen, cutlo, cuthi, cutbin, std::greater<double>(), Wqq0.M(), evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], Wqq0.M(), cutvalue, std::greater<double>());
                        if(!pass && orderCuts) break;

                }
                if( cut.compare("maxqqmass")==0){
                        //docuteff(maxqqmassNum, maxqqmassDen, cutlo, cuthi, cutbin, std::less<double>(), Wqq0.M(), evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], Wqq0.M(), cutvalue, std::less<double>());
                        if(!pass && orderCuts) break;

                }
                if( cut.compare("minqcost")==0){
                         if( qwl == -1){
                         //if(pass) 
                         //docuteff(minqcostNum,minqcostDen,cutlo,cuthi,cutbin, std::greater<double>(), -qwl*Wlep0.CosTheta()*100.,evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], -qwl*Wlep0.CosTheta()*100., cutvalue, std::greater<double>());
                        if(!pass && orderCuts) break;

                        }else{
                         //if(pass)
                        // docuteff(minqcostNum,minqcostDen,cutlo,cuthi,cutbin,std::greater<double>(),-qwqq*Wqq0.CosTheta()*100.,evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], -qwqq*Wqq0.CosTheta()*100., cutvalue, std::greater<double>());
                         if(!pass && orderCuts) break;

                        }


		}
		if( cut.compare("maxvrec")==0){
                        //docuteff(maxqqmassNum, maxqqmassDen, cutlo, cuthi, cutbin, std::less<double>(), Wqq0.M(), evtw);
                        pass = performcut( getPassPol(pol1,pol2)[i], mvrecoil, cutvalue, std::less<double>());
                        if(!pass && orderCuts) break;

                }	
		 //if its the last cut and pass populate post cut distributions
                //
                //
                if( i == _cutsequence.size()-1 ){
                        //fill distributions like mass
               
       		mqqCuts->Fill(Wqq0.M(),evtw);
        	mqqDiffCuts->Fill(Wqq0.M()- Wqq.M(),evtw);
        	mqqCutsFine->Fill(Wqq0.M(),evtw);
        	mqqDiffCutsFine->Fill(Wqq0.M()-Wqq.M(),evtw);

		if(isUD){
        	mqqUDCuts->Fill(Wqq0.M(),evtw);
		mqqUDCutsFine->Fill(Wqq0.M(),evtw);	
        	mqqDiffUDCuts->Fill(Wqq0.M()-Wqq.M(),evtw);
        	mqqDiffUDCutsFine->Fill(Wqq0.M()-Wqq.M(),evtw);
        	}
		if(isCS){
		mqqCSCuts->Fill(Wqq0.M(),evtw);
		mqqCSCutsFine->Fill(Wqq0.M(),evtw);
		mqqDiffCSCuts->Fill(Wqq0.M()-Wqq.M(),evtw);
		mqqDiffCSCutsFine->Fill(Wqq0.M()-Wqq.M(),evtw);

		}

		if( qwl == trueqWl){
                chargeIDpost->Fill(1);
	        }
       		 else{
                chargeIDpost->Fill(0);
       		 }

        	//ipd0sig{};
        	//ip3dsig{};
			 
		 }
			
 
		if( cut.compare("mucone")==0){
                        pass = muconecut(getPassPol(pol1,pol2)[i], nmucone);
                        //if(pass)
  //                      nLepHist->Fill(nlep, evtw);
                        if(!pass & orderCuts) break;

                
		}


        }
}
#endif


