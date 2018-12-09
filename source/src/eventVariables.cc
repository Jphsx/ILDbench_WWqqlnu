
#include "eventVariables.h"

eventVariables::eventVariables(const char* variableSetName, int nfermions, int nleptons ,std::vector<MCParticle*> mcpartvec, std::vector<ReconstructedParticle*> jets, TTree* tree){
	_variableSetName = variableSetName;
	_nfermions = nfermions;
	_nleptons = nleptons;
	_mcpartvec = mcpartvec;
	_jets = jets;
	_localTree = tree;

	//allocate correct size for fermion vectors
	std::vector<TLorentzVector*> mcf(nfermions);
	_MCf = mcf;
	std::vector<int> mcfpdg(nfermions);
	_MCfpdg = mcfpdg;
}
void eventVariables::classifyEvent(bool& isTau, bool& isMuon, int& mclepCharge, std::vector<TLorentzVector*>& MCf, std::vector<int>& MCfpdg){
	std::cout<<"debug"<<std::endl;
	for(unsigned int i=0; i<_mcpartvec.size(); i++){
		std::vector<int> parentpdgs{};
		std::vector<int> daughterpdgs{};
		std::vector<MCParticle*> mcparents{};
		std::vector<MCParticle*> daughters{};
		std::cout<<"debug2"<<std::endl;
		daughters = _mcpartvec.at(i)->getDaughters();
		for(unsigned int j = 0; j<daughters.size(); j++){
			daughterpdgs.push_back(daughters.at(j)->getPDG());
			
		}
		//allowed quarks
		std::vector<int> quarks{ 1, 2, 3, 4, 5, -1, -2, -3, -4, -5};
		std::vector<int> leptons{11, 12, 13, 14, 15, 16, -11, -12, -13, -14, -15, -16};
		//we require exactly 2 elements from leptons and 2 from quarks
		int lep=0;
		int qrk=0;

		//categorize the event for plotting
		for(unsigned int k=0; k<quarks.size(); k++){
			qrk += std::count(daughterpdgs.begin(),daughterpdgs.end(),quarks.at(k));
		}
		for(unsigned int k=0; k<leptons.size(); k++){
			lep += std::count(daughterpdgs.begin(),daughterpdgs.end(),leptons.at(k));
		}

		if( qrk == (_nfermions-_nleptons) && lep == _nleptons){
			std::cout<<"debug3"<<std::endl;
			
			for(unsigned int j=0; j<daughters.size(); j++){
		
                TLorentzVector mcVec(TVector3(daughters.at(j)->getMomentum()),daughters.at(j)->getEnergy());
                *_MCf[j] = mcVec;
                _MCfpdg[j] = daughters.at(j)->getPDG();
			}



			if (std::find(daughterpdgs.begin(),daughterpdgs.end(), 13) != daughterpdgs.end() ||
				std::find(daughterpdgs.begin(),daughterpdgs.end(), -13) != daughterpdgs.end() ){
				//identify event containing muon
				isMuon = true;
				//get true charge of the muon
				if (std::find(daughterpdgs.begin(),daughterpdgs.end(), 13) != daughterpdgs.end() ){
					_mclepCharge = -1;
				}
				else{
					_mclepCharge = 1;
				}
			}
			if (std::find(daughterpdgs.begin(),daughterpdgs.end(), 15) != daughterpdgs.end() ||
				std::find(daughterpdgs.begin(),daughterpdgs.end(), -15) != daughterpdgs.end() ){
				//ntau++;
				//identify event containing a tau
				isTau = true;
				//identify the true charge of the lepton
				if (std::find(daughterpdgs.begin(),daughterpdgs.end(), 15) != daughterpdgs.end() ){
					_mclepCharge = -1;
				}
				else{
					_mclepCharge = 1;
				}	
			}
			//if we have found the true decay set break out of the mcpart vec loop
			return;
			//break;
		}//end if 2qrk & 2 lep

	}//end mcpartvec loop

	//if nothing is found return nulll
	return;

}
void eventVariables::printTLVVec( std::vector<TLorentzVector*> v){
	for( unsigned int i=0; i< v.size(); i++){
		std::cout<<v.at(i)->Px()<<" "<<v.at(i)->Py()<<" "<<v.at(i)->Pz()<<" "<<v.at(i)->E()<<" "<<v.at(i)->M()<<std::endl;
	}
}
void eventVariables::printPDGVec(std::vector<int> v){
	for( unsigned int i=0; i< v.size(); i++){
		std::cout<<v.at(i)<<" ";
	}
	std::cout<<std::endl;
}

void eventVariables::printEventVariables(){
	std::cout<<"eventVariables: '"<<_variableSetName<<"'"<<std::endl;
	std::cout<<"nfermions = "<<_nfermions<<"  nleptons = "<<_nleptons<<std::endl;
	printPDGVec(_MCfpdg);	
	printTLVVec(_MCf);

	
}

