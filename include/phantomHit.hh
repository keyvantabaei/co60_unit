#ifndef phantomHit_h
#define phantomHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"

class phantomHit : public G4VHit
{
public:
//Construct and De-Construct Methods
phantomHit();
virtual ~phantomHit();
phantomHit(const phantomHit&);

//Virtual Method
virtual void Print();
virtual void Draw();

//operators
const phantomHit& operator=(const phantomHit&);
G4bool operator==(const phantomHit&) const;
inline void* operator new (size_t);
inline void operator delete(void*);

void Set_Histogram_ALLPHOTONS_Energy(G4double e){_all_energy=e;}
G4double Get_Histogram_ALLPHOTONS_Energy(){return _all_energy;}

void Set_Histogram_SCATTERED_Energy(G4double e){_sacattered_energy=e;}
G4double Get_Histogram_SCATTERED_Energy(){return _sacattered_energy;}

void Set_Histogram_ELECTRONS_Energy(G4double e){_electron_energy=e;}
G4double Get_Histogram_ELECTRONS_Energy(){return _electron_energy;}

std::tuple<G4double,G4double> Get_CopyNo_Dose_tuple(){return CopyNo_Dose;}


private:
std::tuple<G4double,G4double> CopyNo_Dose;
G4double _all_energy;
G4double _sacattered_energy;
G4double _electron_energy;

};

typedef G4THitsCollection<phantomHit> phantomHC;
extern G4ThreadLocal G4Allocator<phantomHit>* phantomAllocator;
inline void* phantomHit::operator new (size_t)
{
if(!phantomAllocator)
phantomAllocator = new G4Allocator<phantomHit>;
return (void*)phantomAllocator->MallocSingle();
}

inline void phantomHit::operator delete(void *hit)
{
    phantomAllocator->FreeSingle((phantomHit*) hit);
}
#endif