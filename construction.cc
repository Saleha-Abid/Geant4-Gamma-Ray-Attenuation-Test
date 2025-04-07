/*#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();
	G4Material *mat = nist->FindOrBuildMaterial("G4_AIR");
	
	//NaI Material Definition
	G4Element *Na = nist->FindOrBuildElement("Na");
	G4Element *I = nist->FindOrBuildElement("I");
	
	G4Material *NaI = new G4Material("NaI", 3.67*g/cm3, 2);
	NaI->AddElement(Na, 1);
	NaI->AddElement(I, 1);
	 
	 
	 //PLA Material Definition
	 G4Element *C = nist->FindOrBuildElement("C");
	 G4Element *H = nist->FindOrBuildElement("H");
	 G4Element *O = nist->FindOrBuildElement("O");
	 
	 G4Material *PLA = new G4Material("PLA", 1.25*g/cm3, 3);
	 PLA->AddElement(C, 3);
	 PLA->AddElement(H, 4);
	 PLA->AddElement(O, 2);
	 
	 
	 //Bismuth Material Definition
	 G4Element *Bi = nist->FindOrBuildElement("Bi");
	 G4Material *Bismuth = new G4Material("Bismuth", 7*g/cm3, 1);
	 Bismuth->AddElement(Bi, 1);
	 
	 
	 //Aluminium A356 Alloy Material Definition
	 G4Element *Al = nist->FindOrBuildElement("Al");
	 G4Material *Al_Matrix = new G4Material("Al_Matrix", 2.67*g/cm3, 1);
	 Al_Matrix->AddElement(Al, 1);
	 
	 
	 //BNNT Material Definiton
	 G4Element *B = nist->FindOrBuildElement("B");
	 G4Element *N = nist->FindOrBuildElement("N");
	 
	 G4Material *BN = new G4Material("BN", 1.35*g/cm3, 2);
	 BN->AddElement(B, 1);
	 BN->AddElement(N, 1);
	 
	 //intergalactic vacuum definition
 	 G4double atomicNumber = 1.;
 	 G4double massOfMole = 1.008*g/mole;
 	 G4double density = 1.e-25*g/cm3;
 	 G4double temperature = 2.73*kelvin;
 	 G4double pressure = 3.e-18*pascal;
 	 G4Material* vacuum = new G4Material("vacuum", atomicNumber, massOfMole, density, kStateGas, temperature, pressure);
 	
 	G4Material* worldMat = vacuum;
	
	G4Box *solidWorld = new G4Box("solidWorld", 0.007*mm, 0.007*mm, 0.007*mm);
	
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
	
	//define 1st layer of PLA-Bi
	G4Box *solidPLA = new G4Box("solidPLA", 1000*nm, 1000*nm, 100*nm);
	
	G4LogicalVolume *logicPLA = new G4LogicalVolume(solidPLA, PLA, "logicPLA");
	
	G4VPhysicalVolume *physPLA = new G4PVPlacement(0, G4ThreeVector(0., 0., -100.005*nm), logicPLA, "physPLA", logicWorld, false, 0, true);
	
	
	G4Sphere *solidBi = new G4Sphere("solidBi", 0*nm, 9*nm, 0*deg, 360*deg, 0*deg, 180*deg);
	
	G4LogicalVolume *logicBi = new G4LogicalVolume(solidBi, Bismuth, "logicBi");
	
	for(G4int i = 0; i < 10; i++)
	{
		for(G4int j = 0; j < 100; j++)
		{
			for(G4int k = 0; k < 100; k++)
			{		
				G4VPhysicalVolume *physBi = new G4PVPlacement(0, G4ThreeVector((990-(20*j))*nm, (990-(20*k))*nm, (90-(20*i))*nm), logicBi, "physBi", logicPLA, false, 10000*i+100*j+k, true);
			}
		}
	}
	
	//define 2nd layer of Al-BNNT
	G4Box *solidAl = new G4Box("solidAl", 1000*nm, 1000*nm, 100*nm);
	
	G4LogicalVolume *logicAl = new G4LogicalVolume(solidAl, Al_Matrix, "logicAl");
	
	G4VPhysicalVolume *physAl = new G4PVPlacement(0, G4ThreeVector(0., 0., 100.005*nm), logicAl, "physAl", logicWorld, false, 0, true);
	
	
	
	
	G4Tubs *solidBNNT = new G4Tubs("solidBNNT", 0*mm, 9*nm, 1000*nm, 0*deg, 360*deg);
	
	G4LogicalVolume *logicBNNT = new G4LogicalVolume(solidBNNT, BN, "logicBNNT");
	
	for(G4int i = 0; i < 100; i++)
	{
		for(G4int j = 0; j < 10; j++)
		{
			G4Rotate3D rotY(90*deg, G4ThreeVector(0,1,0));
			G4Translate3D translation(G4ThreeVector((90-(20*j))*nm,(990-(20*i))*nm,0*nm));
	
			G4Transform3D transformed = (rotY)*(translation);
			
			G4VPhysicalVolume *physBNNT = new G4PVPlacement(transformed, logicBNNT, "physBNNT", logicAl, false, 10*i+j, true);
		}
	}
	
	//detector construction
	G4Box *solidDetector = new G4Box("solidDetector", 0.007*mm, 0.007*mm, 0.0014*mm);
	
	G4LogicalVolume *logicDetector = new G4LogicalVolume(solidDetector, NaI, "logicDetector");
	
	G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.0035), logicDetector, "physDetector", logicWorld, false, 0, true);
	
	fScoringVolume = logicDetector;
	
	return physWorld;
}*/

#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();
	G4Material *mat = nist->FindOrBuildMaterial("G4_AIR");
	
	G4Element *Pb = nist->FindOrBuildElement("Pb");
	
	G4Element *Na = nist->FindOrBuildElement("Na");
	G4Element *I = nist->FindOrBuildElement("I");
	
	G4Material *NaI = new G4Material("NaI", 3.67*g/cm3, 2);
	NaI->AddElement(Na, 1);
	NaI->AddElement(I, 1);
	
	G4Material *Lead = new G4Material("Lead", 11.4*g/cm3, 1);
	Lead->AddElement(Pb, 1);
	
	//PLA Material Definition
	G4Element *C = nist->FindOrBuildElement("C");
	G4Element *H = nist->FindOrBuildElement("H");
	G4Element *O = nist->FindOrBuildElement("O");
	 
	G4Material *PLA = new G4Material("PLA", 1.25*g/cm3, 3);
	PLA->AddElement(C, 3);
	PLA->AddElement(H, 4);
	PLA->AddElement(O, 2);
	 
	 
	//Bismuth Material Definition
	G4Element *Bi = nist->FindOrBuildElement("Bi");
	G4Material *Bismuth = new G4Material("Bismuth", 7*g/cm3, 1);
	Bismuth->AddElement(Bi, 1);
	
	//Main Layer Material Defnition
	G4Material *Sec_Layer = new G4Material("Sec_Layer", 0.707*g/cm3,2);
	Sec_Layer->AddMaterial(Bismuth, 80*perCent);
	Sec_Layer->AddMaterial(PLA, 20*perCent);
	 
	 
	//Aluminium A356 Alloy Material Definition
	G4Element *Al = nist->FindOrBuildElement("Al");
	G4Element *Si = nist->FindOrBuildElement("Si");
	G4Element *Mg = nist->FindOrBuildElement("Mg");
	G4Element *Fe = nist->FindOrBuildElement("Fe");
	G4Element *Cu = nist->FindOrBuildElement("Cu");
	G4Element *Mn = nist->FindOrBuildElement("Mn");
	G4Element *Zn = nist->FindOrBuildElement("Zn");
	
	G4Material *Al_Cast = new G4Material("Al_Cast", 2.67*g/cm3, 7);
	Al_Cast->AddElement(Al, 92.05*perCent);
	Al_Cast->AddElement(Si, 7*perCent);
	Al_Cast->AddElement(Mg, 0.35*perCent);
	Al_Cast->AddElement(Fe, 0.2*perCent);
	Al_Cast->AddElement(Cu, 0.2*perCent);
	Al_Cast->AddElement(Mn, 0.1*perCent);
	Al_Cast->AddElement(Zn, 0.1*perCent);
	 
	 
	//BNNT Material Definiton
	G4Element *B = nist->FindOrBuildElement("B");
	G4Element *N = nist->FindOrBuildElement("N");
	 
	G4Material *BN = new G4Material("BN", 1.35*g/cm3, 2);
	BN->AddElement(B, 1);
	BN->AddElement(N, 1);
	
	//Sacrificial Layer Material
	G4Material *M_Layer = new G4Material("M_Layer", 3*g/cm3, 2);
	M_Layer->AddMaterial(BN, 5*perCent);
	M_Layer->AddMaterial(Al_Cast, 95*perCent);
	
	//intergalactic vacuum definition
 	G4double atomicNumber = 1.;
 	G4double massOfMole = 1.008*g/mole;
 	G4double density = 1.e-25*g/cm3;
 	G4double temperature = 2.73*kelvin;
 	G4double pressure = 3.e-18*pascal;
 	G4Material* vacuum = new G4Material("vacuum", atomicNumber, massOfMole, density, kStateGas, temperature, pressure);
 	
 	G4Material* worldMat = vacuum;
	
	//world volume definition
	G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 1*m);
	
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
	
	//sacrificial layer definition
	G4Box *solid_Sec = new G4Box("solid_Sec", 0.1*m, 0.1*m, 0.005*m);
	
	G4LogicalVolume *logic_Sec = new G4LogicalVolume(solid_Sec, Sec_Layer, "logic_Sec");
	
	G4Colour blue(0,0,1);
	G4VisAttributes* blueLayer = new G4VisAttributes(blue);
	blueLayer->SetForceSolid(true);
	logic_Sec->SetVisAttributes(blueLayer);
	
	G4VPhysicalVolume *phys_Sec = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.00505*m), logic_Sec, "phys_Sec", logicWorld, false, 0, true); 
	
	//main layer definition
	G4Box *solid_Pri = new G4Box("solid_Pri", 0.1*m, 0.1*m, 0.005*m);
	
	G4LogicalVolume *logic_Pri = new G4LogicalVolume(solid_Pri, M_Layer, "logic_Pri");
	
	G4Colour white(1,1,1);
	G4VisAttributes* whiteLayer = new G4VisAttributes(white);
	whiteLayer->SetForceSolid(true);
	logic_Pri->SetVisAttributes(whiteLayer);
	
	G4VPhysicalVolume *phys_Pri = new G4PVPlacement(0, G4ThreeVector(0., 0., -0.00505*m), logic_Pri, "phys_Pri", logicWorld, false, 0, true); 
	
	//detector definition
	G4Box *solidDetector = new G4Box("solidDetector", 0.5*m, 0.5*m, 0.4*m);
	
	G4LogicalVolume *logicDetector = new G4LogicalVolume(solidDetector, NaI, "logicDetector");
	
	G4Colour yellow(0.56,0.494,0.392);
	G4VisAttributes* yellowDetector = new G4VisAttributes(yellow);
	yellowDetector->SetForceSolid(true);
	logicDetector->SetVisAttributes(yellowDetector);
	
	G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.6*m), logicDetector, "physDetector", logicWorld, false, 0, true);
	
	fScoringVolume = logicDetector;
	
	
	
	return physWorld;
}
