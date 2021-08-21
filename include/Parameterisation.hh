#ifndef Parameterisation_H
#define Parameterisation_HH

#include "globals.hh"
#include "G4VNestedParameterisation.hh"
#include "G4ThreeVector.hh"
#include <vector>

class G4VPhysicalVolume;
class G4VTouchable; 
class G4VSolid;
class G4Material;

// CSG Entities which may be parameterised/replicated
//
class G4Box;
class G4Tubs;
class G4Trd;
class G4Trap;
class G4Cons;
class G4Sphere;
class G4Orb;
class G4Ellipsoid;
class G4Torus;
class G4Para;
class G4Polycone;
class G4Polyhedra;
class G4Hype;
class Parameterisation : public G4VNestedParameterisation
{
    public:
Parameterisation(const G4ThreeVector&,G4int,std::vector<G4Material*>&);
virtual ~Parameterisation();
 void ComputeTransformation(const G4int,G4VPhysicalVolume*) const;
 void ComputeDimensions(G4Box&,const G4int,const G4VPhysicalVolume*) const;
    // -----------------------------------
    G4Material* ComputeMaterial(G4VPhysicalVolume *currentVol,
                                const G4int repNo, 
                                const G4VTouchable *parentTouch=0
                                        );
  // Required method, as it is the reason for this class.
  //   Must cope with parentTouch=0 for navigator's SetupHierarchy

    G4int       GetNumberOfMaterials() const;
    G4Material* GetMaterial(G4int idx) const;
    private:  // Dummy declarations to get rid of warnings ...

  void ComputeDimensions (G4Trd&,const G4int,const G4VPhysicalVolume*) 
    const {}
  void ComputeDimensions (G4Trap&,const G4int,const G4VPhysicalVolume*) 
    const {}
  void ComputeDimensions (G4Cons&,const G4int,const G4VPhysicalVolume*) 
    const {}
  void ComputeDimensions (G4Sphere&,const G4int,const G4VPhysicalVolume*) 
    const {}
  void ComputeDimensions (G4Orb&,const G4int,const G4VPhysicalVolume*) 
    const {}
  void ComputeDimensions (G4Ellipsoid&,const G4int,const G4VPhysicalVolume*) 
    const {}
  void ComputeDimensions (G4Torus&,const G4int,const G4VPhysicalVolume*) 
    const {}
  void ComputeDimensions (G4Para&,const G4int,const G4VPhysicalVolume*) 
    const {}
  void ComputeDimensions (G4Hype&,const G4int,const G4VPhysicalVolume*) 
    const {}
  void ComputeDimensions (G4Tubs&,const G4int,const G4VPhysicalVolume*) 
    const {}
  void ComputeDimensions (G4Polycone&,const G4int,const G4VPhysicalVolume*)
    const {}
  void ComputeDimensions (G4Polyhedra&,const G4int,const G4VPhysicalVolume*) const{}

  using G4VNestedParameterisation::ComputeMaterial;
private:
G4double dx,dy,dz;
G4int nz;
std::vector<G4double> pz;
std::vector<G4Material*> mat;
};
#endif