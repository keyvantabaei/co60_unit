
#include "k1DC.hh"
#include "G4SDManager.hh"
#include "k1Geometery.cc"
// #include "chamberSD.hh"
#include "phantomSD.hh"

k1DC::k1DC():G4VUserDetectorConstruction(),_phantom_size(G4ThreeVector(0,0,0))
{
}
k1DC::~k1DC()
{
}

G4VPhysicalVolume* k1DC::Construct()
{
  //phantom size
    SetPhantomSize(G4ThreeVector(10*cm,10*cm,10*cm));
    SetCellCount(G4ThreeVector(50,50,50));
    //detector size
    G4ThreeVector detector_size=G4ThreeVector(4*mm,4*mm,_phantom_size.z());
    //geo class
    Geometery geo;
    //world
    Struct _world =geo.Box("world","air",G4ThreeVector(2*m,2*m,2*m),G4ThreeVector(),0);

    //co 60 source capsol
        
      // _phantom_detector= geo.HollowBox("waterphantom","water",G4ThreeVector(10*cm,10*cm,10*cm),G4ThreeVector(5*cm,5*cm,5*cm),G4ThreeVector(2*cm,2*cm,2*cm),G4ThreeVector(0,0,0),_world._logic)._logic;

        //source capsul
          //  geo.Box("world2","vaccum",G4ThreeVector(3.67*cm,3.67*cm,3.67*cm),G4ThreeVector(5*cm,0,3.67*cm/2),_world._logic);
          G4double cap_lenght=3.67*cm;
          G4double cap_steel_lenght=2.44*cm;
          G4double cap_radius=1.83*cm;
          G4double cap_steel_radius=1.5*cm;
          G4double cap_thickness=cap_radius-cap_steel_radius;
          G4double cap_tungsten_radius=1.5*cm;
          G4double cap_tungsten_lenght=0.12*cm;
          G4double steel_front_plate_thichness=0.11*cm;
          G4double source_lenght=1*cm;





           

          G4double a=35*cm;
          G4double b=35*cm;
          G4double SSD=80*cm;
          // G4double x0=0;
          // G4double x1=0;
          // G4int i=0;
          // do{
          //     x1=i;
          //     x0=(4*x1-a)/2;
          //     i++;
          // }while(x1-x0>2.5);


          // x0=10;
          // x1=17.5;

          G4double secondary_trapzoid_y=19.93*cm;
          G4double secondary_trapzoid_z=b;
          G4double secondary_trapzoid_x0=7*cm;
          G4double secondary_trapzoid_x1=10*cm;
          G4double originX=secondary_trapzoid_x1/4-secondary_trapzoid_x0/4+secondary_trapzoid_x1/2;
          G4ThreeVector housing_size=G4ThreeVector(3*cap_lenght,3*cap_lenght,3*cap_lenght);


          G4double primary_trapzoid_y=6.3*cm;
          G4double primary_trapzoid_z=b;
          G4double primary_trapzoid_x0=7*cm;
          G4double primary_trapzoid_x1=10*cm;
          G4double PoriginX=primary_trapzoid_x1/4-primary_trapzoid_x0/4+primary_trapzoid_x1/2;
          G4double opening=a/2-(secondary_trapzoid_x1-secondary_trapzoid_x0)*(SSD-primary_trapzoid_y)/secondary_trapzoid_y;

          G4cout<<"------------------------------>> open ="<<opening/cm<<G4endl;



    //   // head housing
      geo.HeadHousing("housing","pb",housing_size,std::make_tuple(0,1.1*cap_radius,1.1*cap_lenght,0,360*deg),G4ThreeVector(0,0,1.1*cap_lenght/2-housing_size.z()/2-.01*cm),G4ThreeVector(0,0,housing_size.z()/2),_world._logic)._logic;
    //  _phantom_detector=geo.Box("scoring plane","vaccum",G4ThreeVector(a,b,1*mm),G4ThreeVector(0,0,-1*cm),_world._logic)._logic;

    // //source capsol
    Struct _tube= geo.HollowCylander("capsul","steel",std::make_tuple(0,cap_radius,cap_lenght,0,360*deg),std::make_tuple(0,cap_steel_radius,cap_steel_lenght+cap_tungsten_lenght+source_lenght,0,360*deg),G4ThreeVector(0,0,steel_front_plate_thichness/2),G4ThreeVector(0,0,cap_lenght/2),G4ThreeVector(0,0,0),_world._logic);
    geo.Tube("steel1","steel",0,cap_steel_radius,cap_steel_lenght,0,360*deg,G4ThreeVector(0,0,cap_steel_lenght+steel_front_plate_thichness+source_lenght  - cap_steel_lenght/2),G4ThreeVector(),_world._logic);
    geo.Tube("tungsten","tungsten",0,cap_tungsten_radius,cap_tungsten_lenght,0,360*deg,G4ThreeVector(0,0,cap_lenght-cap_tungsten_lenght/2 ),G4ThreeVector(),_world._logic);
      //  primary
    geo.GenericTrapezoid("T1","tungsten",primary_trapzoid_z,primary_trapzoid_y,primary_trapzoid_x0,primary_trapzoid_x1,G4ThreeVector(-PoriginX-opening-.5*cm,0,-primary_trapzoid_y/2),G4ThreeVector(-90*deg,0,0),_world._logic)._logic;
    geo.GenericTrapezoid("T2","tungsten",primary_trapzoid_z,primary_trapzoid_y,primary_trapzoid_x0,primary_trapzoid_x1,G4ThreeVector(PoriginX+opening+.5*cm,0,-primary_trapzoid_y/2),G4ThreeVector(-90*deg,180*deg,0),_world._logic)._logic;
    //secondary
    geo.GenericTrapezoid("T3","pb",secondary_trapzoid_z,secondary_trapzoid_y,secondary_trapzoid_x0,secondary_trapzoid_x1,G4ThreeVector(-opening-originX,0,-secondary_trapzoid_y/2-primary_trapzoid_y),G4ThreeVector(-90*deg,0,0),_world._logic)._logic;
    geo.GenericTrapezoid("T3","pb",secondary_trapzoid_z,secondary_trapzoid_y,secondary_trapzoid_x0,secondary_trapzoid_x1,G4ThreeVector(opening+originX,0,-secondary_trapzoid_y/2-primary_trapzoid_y),G4ThreeVector(-90*deg,-180*deg,0),_world._logic)._logic;
    _phantom_detector=geo.Tube("phantom","vaccum",0,17.5*cm,1*cm,0,360*deg,G4ThreeVector(0,0,-SSD),G4ThreeVector(),_world._logic)._logic;



//phantom
    // Struct _phantom= geo.Box("waterphantom","water",_phantom_size,G4ThreeVector(0,0,-secondary_trapzoid_y-primary_trapzoid_y-(SSD-secondary_trapzoid_y-primary_trapzoid_y)),_world._logic);
    // _phantom_detector=_phantom._logic;
    // _phantom_detector=geo.NestedParameterization(_phantom_detector,_phantom_size,_cell_count,"water");

return _world._physical;
}
void k1DC::ConstructSDandField()
{
  // chamberSD* _ion_chamber_SD = new phantomSD("k1/chamberSD","charge");
  phantomSD* _water_phantom_SD = new phantomSD("k1/phantomSD","edep");
  // G4SDManager::GetSDMpointer()->AddNewDetector(_ion_chamber_SD);
  G4SDManager::GetSDMpointer()->AddNewDetector(_water_phantom_SD);
  // SetSensitiveDetector(_ion_chamber,_ion_chamber_SD);
  SetSensitiveDetector(_phantom_detector,_water_phantom_SD);

}