#include "MyDetectorConstruction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction :: Construct()
{
	// *****************************************************************************
	//								FIND MATERIALS
	// *****************************************************************************
	G4NistManager* nist = G4NistManager::Instance();
	G4Material *Air = nist->FindOrBuildMaterial("G4_AIR");
	
	// *****************************************************************************
	//									DEFINE GEOMETRIES
	// *****************************************************************************

	// World volume
	G4Box* solidWorld = new G4Box("solidWorld", 100 * cm, 100 * cm, 100 * cm);
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, Air, "logicWorld");
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0,
										G4ThreeVector(0., 0., 0.), 
										logicWorld, 
										"physWorld", 
										0, false, 0, true);
	
	return physWorld;
}
