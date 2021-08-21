#include "Parameterisation.hh"


#include "G4Box.hh"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"

Parameterisation::Parameterisation(const G4ThreeVector& voxelsize,G4int NZ,std::vector<G4Material*>& Mat):
G4VNestedParameterisation(),dx(voxelsize.x()),dy(voxelsize.y()),dz(voxelsize.z()),nz(NZ),mat(Mat)
{
  // در این جا z ها محاسبه میشه
pz.clear();
G4double z;
for(G4int i=0;i<nz;i++)
{
  z=(1-nz+2*i)*dz;
  pz.push_back(z);
}
}

Parameterisation::~Parameterisation(){pz.clear();}

void Parameterisation::ComputeTransformation(const G4int copyNo,G4VPhysicalVolume* pv) const
{
//G4cout<<"NV barabar as="<<nv<<"startz:"<<startz<<"spacing:"<<spacing<<G4endl;
  // در این متد مختصات فیزیکی و چرخش المان و مبدا اون تعیین میشه
  G4ThreeVector origin(0,0,pz[copyNo]);
  pv->SetTranslation(origin);
  pv->SetRotation(0);
}

void Parameterisation::ComputeDimensions(G4Box& box,const G4int,const G4VPhysicalVolume*) const
{
  // در این متد المان یا وکسل ساخته میشه
box.SetXHalfLength(dx);
box.SetYHalfLength(dy);
box.SetZHalfLength(dz);
}










G4Material* Parameterisation
::ComputeMaterial(G4VPhysicalVolume* /*currentVol*/, const G4int, 
                  const G4VTouchable* parentTouch)
{
  //  در این متد باید تعیین کنیم کدوم وکسل چه ماده ایی داشته باشه
  //  parentTouchبا داشتن کپی نامبر و 
    //و دستورات شرظی
    if(parentTouch==0) return mat[0]; // protection for initialization and
                                     // vis at idle stat

  return mat[0];
}


G4int Parameterisation::GetNumberOfMaterials() const{
   return mat.size();
}


G4Material* Parameterisation::GetMaterial(G4int /*copyNo*/) const{
   return mat[0];
}