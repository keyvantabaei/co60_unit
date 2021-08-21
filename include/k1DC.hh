#ifndef k1DC_h
#define k1DC_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4ThreeVector.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class k1DC  : public G4VUserDetectorConstruction
{
    public:
    k1DC();
    virtual ~k1DC();
virtual void ConstructSDandField();
virtual G4VPhysicalVolume* Construct();

G4LogicalVolume* GetPhantomVolume() const { return _phantom_detector; }
G4LogicalVolume* GetIonChamberVolume() const { return _ion_chamber; }

void SetPhantomSize(G4ThreeVector size){_phantom_size=size;}
G4ThreeVector GetPhantomSize(){return _phantom_size ;}
G4ThreeVector GetCellCount(){return _cell_count;}
void SetCellCount(G4ThreeVector size){_cell_count= size;}

G4ThreeVector _phantom_size;
G4ThreeVector _cell_count;
private:
G4LogicalVolume* _phantom_detector;
G4LogicalVolume* _ion_chamber;
};

#endif