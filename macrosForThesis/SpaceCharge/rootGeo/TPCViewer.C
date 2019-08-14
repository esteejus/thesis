
void TPCViewer()
{
  //  plottingEngine.SetDefaultStyle();
  /*
  // Create the ROOT geometry.
  TGeoManager* geoman = new TGeoManager("world", "geometry");
  // Create the ROOT material and medium.
  // For simplicity we use the predefined material "Vacuum".
  TGeoMaterial* matVacuum = new TGeoMaterial("Vacuum", 0, 0, 0);
  TGeoMedium*  medVacuum = new TGeoMedium("Vacuum", 1, matVacuum);
  // Dimensions of the tube
  double rMin = 0., rMax = 0.5, halfLength = 10.;
  // In this simple case, the tube is also the top volume.
  TGeoVolume* top = geoman->MakeTube("TOP", medVacuum, rMin, rMax, halfLength);
  */

  double rw = 10;
  //  double radius_i = 1283.39;
  //  double radius_o = 1283.39 + rw;
  double radius_i = 12.39;
  double radius_o = 12.39 + rw;
  double dz = 20;

  double offy = -20;
  double offz = 30;
  
  TGeoMaterial* matVacuum = new TGeoMaterial("Vacuum", 0, 0, 0);
  TGeoMedium*  medVacuum = new TGeoMedium("Vacuum", 1, matVacuum);
  //  TGeoVolume *beam = gGeoManager -> MakeTubs("beam",medVacuum,radius_i,radius_o,dz,0,270);
  //  TGeoTranslation *transBeam = new TGeoTranslation(0,offy,offz);
  //  TGeoRotation *rot = new TGeoRotation("ROT",10,0,0);
  //  TGeoCombiTrans *transBeam = new TGeoCombiTrans("somename",0,offy,offz,rot);
 //  TGeoVolume *beam = gGeoManager -> MakeTube("beam",medVacuum,radius_i,radius_o,dz);
  //TGeoVolume *beam = gGeoManager -> MakeTube("TUBE",medVacuum, 2,3,2);

  TFile *f_man = TFile::Open("geomSpiRIT.man.root");
  TFile *f_top = TFile::Open("geomSpiRIT.root");
  TGeoManager* geoman = (TGeoManager *)f_man->Get("SpiRIT");
  TGeoVolume* top     = (TGeoVolume *)f_top->Get("top");
  gGeoManager ->SetTopVolume(top);

  //  TGeoVolume *beam = gGeoManager -> MakeTube("TUBE",medVacuum, 2,3,.1);
  //  beam->SetLineWidth(2);
  //  beam->SetLineColor(2);
  //  top->AddNodeOverlap(beam,1,transBeam);
  //  top->AddNodeOverlap(beam,1,rot);
  //  top->AddNodeOverlap(beam,1,new TGeoCombiTrans("somename",0,offy,offz,rot) );
  gGeoManager ->CloseGeometry();
  gGeoManager -> CheckOverlaps();

  gGeoManager -> SetTopVisible(true);

  top->Draw("ogl");

}
