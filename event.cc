#include "event.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
	fEdep = 0;
	photonCount = 0;
}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
	fEdep = 0;
}

void MyEventAction::EndOfEventAction(const G4Event*)
{
	G4cout << "Energy Depostion: " <<fEdep <<G4endl;
	
	if (fEdep != 0)
	{
		photonCount++;
	}
	
	G4cout << "Photon Count: " << photonCount << G4endl;
	
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->FillNtupleDColumn(0, 0, fEdep);
	man->AddNtupleRow(0);
	
}
