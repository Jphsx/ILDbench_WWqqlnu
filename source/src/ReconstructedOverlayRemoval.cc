#include "ReconstructedOverlayRemoval.h"

ReconstructedOverlayRemoval aReconstructedOverlayRemoval;


ReconstructedOverlayRemoval::ReconstructedOverlayRemoval() : Processor("ReconstructedOverlayRemoval") {


  // register steering parameters: name, description, class-variable, default value

	registerProcessorParameter( "Printing" ,
	                "Print certain messages"  ,
	                _printing,
	                (int)5 ) ;


	registerProcessorParameter("MCOFilter",
					"option to toggle filtered mco collection",
					_MCOFilter,
					(int) 1);
	
	
//input particle collection:
	std::string inputParticleCollectionName = "x";
  	registerInputCollection( LCIO::RECONSTRUCTEDPARTICLE,
			     	"InputParticleCollectionName" , 
			     	"Input Particle Collection Name "  ,
			     	_inputParticleCollectionName,
			      	inputParticleCollectionName);

	std::string inputMcParticleCollectionName = "x";
	registerInputCollection( LCIO::MCPARTICLE,
					"McParticleCollectionName" ,
					"Name of the MCParticle input collection" ,
					_inputMcParticleCollectionName,
					inputMcParticleCollectionName);

	std::string inputRecoRelationCollectionName = "x";
  	registerInputCollection( LCIO::LCRELATION,
			     	"InputRecoRelationCollectionName" , 
			     	"Input Reco Relation Collection Name "  ,
			     	_inputRecoRelationCollectionName,
			      	inputRecoRelationCollectionName);

  	std::string outputParticleCollectionName = "x";
  	registerOutputCollection( LCIO::RECONSTRUCTEDPARTICLE,
                    "OutputParticleCollectionName" ,
			     	"Output Particle Collection Name "  ,
                    _outputParticleCollectionName,
                     outputParticleCollectionName);

    std::string outputOverlayCollectionName = "x";
  	registerOutputCollection( LCIO::RECONSTRUCTEDPARTICLE,
                    "OutputOverlayCollectionName" ,
			     	"Output Reconstructed Overlay Particle Collection Name "  ,
                    _outputOverlayCollectionName,
                     outputOverlayCollectionName);

	std::string outputMCCollectionName = "y";
  	registerOutputCollection( LCIO::MCPARTICLE,
                    "OutputMCCollectionName" ,
			     	"Output MC Collection Name "  ,
                     _outputMCCollectionName,
                     outputMCCollectionName);

}

void ReconstructedOverlayRemoval::init() {

  streamlog_out(DEBUG) << "   init called  " << std::endl;
                   
  // usually a good idea to
  printParameters() ;
  nEvt = 0;
 
}

void ReconstructedOverlayRemoval::processRunHeader( LCRunHeader* run) {
  streamlog_out(MESSAGE) << " processRunHeader "  << run->getRunNumber() << std::endl ;
}

bool ReconstructedOverlayRemoval::FindPFOs( LCEvent* evt ) {

	bool collectionFound = false;

  	// clear old global pfovector
	_pfovec.clear();
  	typedef const std::vector<std::string> StringVec ;
  	StringVec* strVec = evt->getCollectionNames() ;
	
	//iterate over collections, find the matching name
  	for(StringVec::const_iterator itname=strVec->begin(); itname!=strVec->end(); itname++){
     
		//if found print name and number of elements
    		if(*itname==_inputParticleCollectionName){ 
			LCCollection* collection = evt->getCollection(*itname);
			std::cout<< "Located Pfo Collection "<< *itname<< " with "<< collection->getNumberOfElements() << " elements " <<std::endl;
			collectionFound = true;

 			//add the collection elements to the global vector
      			for(int i=0; i<collection->getNumberOfElements(); i++){
				ReconstructedParticle* recoPart = dynamic_cast<ReconstructedParticle*>(collection->getElementAt(i));
				_pfovec.push_back(recoPart);
      			}
    		}
  	}
	
	if(!collectionFound){
		std::cout<<"Pfo Collection "<< _inputParticleCollectionName << "not found"<<std::endl;
	}

   
	return collectionFound;
}
bool ReconstructedOverlayRemoval::FindRecoToMCRelation( LCEvent* evt ){
   
	bool collectionFound = false;

  	// clear old global MCParticle vector
  	_reco2mcvec.clear();
  	typedef const std::vector<std::string> StringVec ;
  	StringVec* strVec = evt->getCollectionNames() ;

	//iterate over collections, find the matching name
  	for(StringVec::const_iterator itname=strVec->begin(); itname!=strVec->end(); itname++){    
    
		//if found print name and number of elements 
		if(*itname==_inputRecoRelationCollectionName){
      			LCCollection* collection = evt->getCollection(*itname);
     			std::cout<< "Located MC Collection "<< *itname<< " with "<< collection->getNumberOfElements() << " elements " <<std::endl;
      			collectionFound = true;
      
			//add the collection elements to the global vector
			for(unsigned int i=0;i<collection->getNumberOfElements();i++){
				LCRelation* recoRelation = dynamic_cast<LCRelation*>(collection->getElementAt(i));
				_reco2mcvec.push_back(recoRelation);

       
      			}
    		}
  	}

  	if(!collectionFound){
		std::cout<<"LCRelation Collection "<< _inputRecoRelationCollectionName << "not found"<<std::endl;
	}
  
  	return collectionFound;
}
bool ReconstructedOverlayRemoval::FindMCParticles( LCEvent* evt ){
   
	bool collectionFound = false;

  	// clear old global MCParticle vector
  	_mcpartvec.clear();
  	typedef const std::vector<std::string> StringVec ;
  	StringVec* strVec = evt->getCollectionNames() ;

	//iterate over collections, find the matching name
  	for(StringVec::const_iterator itname=strVec->begin(); itname!=strVec->end(); itname++){    
    
		//if found print name and number of elements 
		if(*itname==_inputMcParticleCollectionName){
      			LCCollection* collection = evt->getCollection(*itname);
     			std::cout<< "Located MC Collection "<< *itname<< " with "<< collection->getNumberOfElements() << " elements " <<std::endl;
      			collectionFound = true;
      
			//add the collection elements to the global vector
			for(int i=0;i<collection->getNumberOfElements();i++){
				MCParticle* mcPart = dynamic_cast<MCParticle*>(collection->getElementAt(i));
				_mcpartvec.push_back(mcPart);

       
      			}
    		}
  	}

  	if(!collectionFound){
		std::cout<<"MC Collection "<< _inputMcParticleCollectionName << "not found"<<std::endl;
	}
  
  	return collectionFound;
}
void ReconstructedOverlayRemoval::printReconstructedParticle(ReconstructedParticle* p){
	std::cout<<p->id()<<" "<<p->getType<<" "<<p->getMomentum()[0]<<" "<<p->getMomentum()[1]<<" "<<p->getMomentum()[2]<<" "<<p->getEnergy()<<" "<< p->getMass()<<std::endl;
}
bool ReconstructedOverlayRemoval::particleIsOverlay(int id){
	//find particle in LCRelation list
	for(unsigned int i=0; i<_pfo2mc.size(); i++){
			
		if( _pfo2mc.at(i)->getFrom()->id() == id ){
			//we have located pfo on the list look at  the matching mcparticle
			//is this id on the local overlay list?
			for(unsigned int j=0; j<_mcpartvec.size(); j++){
				if( _mcpartvec.at(j)->id() == _pfo2mc.at(i)->getTo()->id() ){
					std::cout<<"found a particle: wgts "<< (int(_pfo2mc.at(i)->getWeight())%10000)/1000. <<" "<<(int(_pfo2mc.at(i)->getWeight())/10000)/1000. << std::endl;
					//this particle has overlay contribution
					//is the contribution significant?
					if( (((int(_pfo2mc.at(i)->getWeight())%10000)/1000.)+((int(_pfo2mc.at(i)->getWeight())/10000)/1000.)) > 0.5){return true;}
				}//end mc to lcrelation match
			}///end mc loop
			
		}//end id to lcrelation match	
	}//end lcrelation loop
		return false;
}
void ReconstructedOverlayRemoval::classifyReconstructedParticles( LCCollectionVec*& overlayCollection, LCCollectionVec*& purgedCollection){
	for(unsigned int i=0; i<_pfovec.size(); i++){
			if(particleIsOverlay(_pfovec.at(i)->id())){
				overlayCollection->addElement( _pfovec.at(i) );
				if(printing > 1){
					std::cout<<"adding to overlay collection: ";
					
				}
			}
			else{
				purgedCollection->addElement( _pfovec.at(i) );
				if(printing > 1){
					std::cout<<"adding to purged collection: ";
				}
			}				
			printReconstructedParticle( _pfovec.at(i) );

	}
}
void ReconstructedOverlayRemoval::extractMCOverlay( std::vector<MCParticle*>& mcpartvec, LCCollectionVec*& mcCollection ){
	
	//this skims over mcparts and creates a list of all the overlay particles
	for( unsigned int i=0; i<mcpartvec.size(); i++){
		if(!mcpartvec.at(i)->isOverlay()){
			mcpartvec.erase(i);
		}
		else{
			//add the overlay mcparts to a new sub collection
			mcCollection->addElement(mcpartvec.at(i));
		}
	}

	/
}
void ReconstructedOverlayRemoval::processEvent( LCEvent * evt ) {
 
 //get particle collections
 FindMCParticles(evt);
 FindPFOs(evt);
 FindRecoToMCRelation(evt);  

  //if mco filter is toggled on - create a list of pure overlay mcparticles
 if(MCOFilter){
    LCCollectionVec * mcCollection = new LCCollectionVec(LCIO::MCPARTICLE);
 	mcCollection->setSubset(true);
	extractMCOverlay(_mcpartvec, mcCollection); 
	evt->addCollection(mcCollection , _outputMCCollectionName.c_str() );
 }
  
  
  LCCollectionVec * purgedCollection = new LCCollectionVec(LCIO::RECONSTRUCTEDPARTICLE);
  LCCollectionVec * overlayCollection = new LCCollectionVec(LCIO::RECONSTRUCTEDPARTICLE);
 
  classifyReconstructedParticles( overlayCollection,  purgedCollection );

	
  
  evt->addCollection(purgedCollection , _outputParticleCollectionName.c_str() ); 
  evt->addCollection(overlayCollection , _outputOverlayCollectionName.c_str() ); 


  nEvt++;
}
void ReconstructedOverlayRemoval::end(){
	
}
