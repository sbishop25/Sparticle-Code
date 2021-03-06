//Modify include statements when running
#include "SampleAnalyzer/User/Analyzer/LeptonAnalysis.h"
#include <TFile.h>
#include <TH1F.h>
using namespace MA5;
using namespace std;
template<typename T1, typename T2> std::vector<const T1*>
  Removal(std::vector<const T1*>&, std::vector<const T2*>&, const MAdouble64 &);

// -----------------------------------------------------------------------------
// Initialize
// function called one time at the beginning of the analysis
// -----------------------------------------------------------------------------
bool LeptonAnalysis::Initialize(const MA5::Configuration& cfg, const std::map<std::string,std::string>& parameters)
{

  INFO << "   <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endmsg;
  INFO << "   <>  Analysis : ATLAS-SUSY-2018-32, arXiv:1908.08215                 <>" << endmsg;
  INFO << "   <>             (Ewkinos/sleptons: dilepton)                         <>" << endmsg;
  INFO << "   <>  Recaster : J.Y. Araz, B. Fuks                                   <>" << endmsg;
  INFO << "   <>  Contact  : jack.araz@durham.ac.uk, fuks@lpthe.jussieu.fr        <>" << endmsg;
  INFO << "   <>                                                                  <>" << endmsg;
  INFO << "   <>  Based on MadAnalysis 5 v1.8                                     <>" << endmsg;
  INFO << "   <>      DOI: XX.YYYY/ZZZ                                            <>" << endmsg;
  INFO << "   <>                                                                  <>" << endmsg;
  INFO << "   <>  Modified by N. Kirby, S. Bishop 2022                            <>" << endmsg;
  INFO << "   <>  For more information, see                                       <>" << endmsg;
  INFO << "   <>  http://madanalysis.irmp.ucl.ac.be/wiki/PublicAnalysisDatabase   <>" << endmsg;
  INFO << "   <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endmsg;

  // Declaration of the signal regions
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_100_105");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_105_110");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_110_120");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_120_140");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_140_160");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_160_180");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_180_220");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_220_260");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_260_inf");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_100_inf");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_160_inf");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_100_120");
  // Manager()->AddRegionSelection("SR_DF_0J_MT2_120_160");
  //
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_100_105");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_105_110");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_110_120");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_120_140");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_140_160");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_160_180");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_180_220");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_220_260");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_260_inf");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_100_inf");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_160_inf");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_100_120");
  // Manager()->AddRegionSelection("SR_DF_1J_MT2_120_160");

  // Manager()->AddRegionSelection("SR_SF_0J_MT2_100_105");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_105_110");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_110_120");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_120_140");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_140_160");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_160_180");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_180_220");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_220_260");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_260_inf");
  Manager()->AddRegionSelection("SR_0J_ee");
  Manager()->AddRegionSelection("SR_0J_em");
  Manager()->AddRegionSelection("SR_0J_mm");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_160_inf");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_100_120");
  // Manager()->AddRegionSelection("SR_SF_0J_MT2_120_160");

  // Manager()->AddRegionSelection("SR_SF_1J_MT2_100_105");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_105_110");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_110_120");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_120_140");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_140_160");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_160_180");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_180_220");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_220_260");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_260_inf");
  // Manager()->AddRegionSelection("SR_1J");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_160_inf");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_100_120");
  // Manager()->AddRegionSelection("SR_SF_1J_MT2_120_160");

  // Declaration of the preselection cuts
  Manager()->AddCut("OS dilep. with $p^l_T>25$ [GeV]");
  Manager()->AddCut("$m_{l_1,l_2}>25$ [GeV]");
  Manager()->AddCut("b veto");

  // SF vs DF  and Njet cuts
  // std::string SF[]      = {  "SR_SF_0J_MT2_100_105", "SR_SF_0J_MT2_105_110",
  //     "SR_SF_0J_MT2_110_120", "SR_SF_0J_MT2_120_140", "SR_SF_0J_MT2_140_160",
  //     "SR_SF_0J_MT2_160_180", "SR_SF_0J_MT2_180_220", "SR_SF_0J_MT2_220_260",
  //     "SR_SF_0J_MT2_260_inf", "SR_SF_0J_MT2_100_inf", "SR_SF_0J_MT2_160_inf",
  //     "SR_SF_0J_MT2_100_120", "SR_SF_0J_MT2_120_160", "SR_SF_1J_MT2_100_105",
  //     "SR_SF_1J_MT2_105_110", "SR_SF_1J_MT2_110_120", "SR_SF_1J_MT2_120_140",
  //     "SR_SF_1J_MT2_140_160", "SR_SF_1J_MT2_160_180", "SR_SF_1J_MT2_180_220",
  //     "SR_SF_1J_MT2_220_260", "SR_SF_1J_MT2_260_inf", "SR_SF_1J_MT2_100_inf",
  //     "SR_SF_1J_MT2_160_inf", "SR_SF_1J_MT2_100_120", "SR_SF_1J_MT2_120_160" };
  // std::string DF[]      = {  "SR_DF_0J_MT2_100_105", "SR_DF_0J_MT2_105_110",
  //     "SR_DF_0J_MT2_110_120", "SR_DF_0J_MT2_120_140", "SR_DF_0J_MT2_140_160",
  //     "SR_DF_0J_MT2_160_180", "SR_DF_0J_MT2_180_220", "SR_DF_0J_MT2_220_260",
  //     "SR_DF_0J_MT2_260_inf", "SR_DF_0J_MT2_100_inf", "SR_DF_0J_MT2_160_inf",
  //     "SR_DF_0J_MT2_100_120", "SR_DF_0J_MT2_120_160", "SR_DF_1J_MT2_100_105",
  //     "SR_DF_1J_MT2_105_110", "SR_DF_1J_MT2_110_120", "SR_DF_1J_MT2_120_140",
  //     "SR_DF_1J_MT2_140_160", "SR_DF_1J_MT2_160_180", "SR_DF_1J_MT2_180_220",
  //     "SR_DF_1J_MT2_220_260", "SR_DF_1J_MT2_260_inf", "SR_DF_1J_MT2_100_inf",
  //     "SR_DF_1J_MT2_160_inf", "SR_DF_1J_MT2_100_120", "SR_DF_1J_MT2_120_160" };
  //
  // std::string SF0J[]    = {  "SR_SF_0J_MT2_100_105", "SR_SF_0J_MT2_105_110",
  //    "SR_SF_0J_MT2_110_120", "SR_SF_0J_MT2_120_140", "SR_SF_0J_MT2_140_160",
  //    "SR_SF_0J_MT2_160_180", "SR_SF_0J_MT2_180_220", "SR_SF_0J_MT2_220_260",
  //    "SR_SF_0J_MT2_260_inf", "SR_SF_0J_MT2_100_inf", "SR_SF_0J_MT2_160_inf",
  //    "SR_SF_0J_MT2_100_120", "SR_SF_0J_MT2_120_160"};
  // std::string SF1J[]    = {  "SR_SF_1J_MT2_100_105",
  //    "SR_SF_1J_MT2_105_110", "SR_SF_1J_MT2_110_120", "SR_SF_1J_MT2_120_140",
  //    "SR_SF_1J_MT2_140_160", "SR_SF_1J_MT2_160_180", "SR_SF_1J_MT2_180_220",
  //    "SR_SF_1J_MT2_220_260", "SR_SF_1J_MT2_260_inf", "SR_SF_1J_MT2_100_inf",
  //    "SR_SF_1J_MT2_160_inf", "SR_SF_1J_MT2_100_120", "SR_SF_1J_MT2_120_160"};
  //
  // std::string DF0J[]    = {  "SR_DF_0J_MT2_100_105", "SR_DF_0J_MT2_105_110",
  //    "SR_DF_0J_MT2_110_120", "SR_DF_0J_MT2_120_140", "SR_DF_0J_MT2_140_160",
  //    "SR_DF_0J_MT2_160_180", "SR_DF_0J_MT2_180_220", "SR_DF_0J_MT2_220_260",
  //    "SR_DF_0J_MT2_260_inf", "SR_DF_0J_MT2_100_inf", "SR_DF_0J_MT2_160_inf",
  //    "SR_DF_0J_MT2_100_120", "SR_DF_0J_MT2_120_160"};
  // std::string DF1J[]    = {  "SR_DF_1J_MT2_100_105",
  //    "SR_DF_1J_MT2_105_110", "SR_DF_1J_MT2_110_120", "SR_DF_1J_MT2_120_140",
  //    "SR_DF_1J_MT2_140_160", "SR_DF_1J_MT2_160_180", "SR_DF_1J_MT2_180_220",
  //    "SR_DF_1J_MT2_220_260", "SR_DF_1J_MT2_260_inf", "SR_DF_1J_MT2_100_inf",
  //    "SR_DF_1J_MT2_160_inf", "SR_DF_1J_MT2_100_120", "SR_DF_1J_MT2_120_160"};

  Manager()->AddCut("2_Electrons", "SR_0J_ee");
  Manager()->AddCut("2_Muons", "SR_0J_mm");
  Manager()->AddCut("1_Electron_1_Muon", "SR_0J_em");
  // Manager()->AddCut("DF dilep. \\& $N_j=1$", DF1J);
  // Manager()->AddCut("SF dilep. \\& $N_j=0$", SF0J);
  // Manager()->AddCut("SF dilep. \\& $N_j=1$", SF1J);

  // Manager()->AddCut("$m_{l_1,l_2} > 100$ [GeV]",   DF);
  // Manager()->AddCut("$m_{l_1,l_2} > 121.2$ [GeV]", SF);

  // Other preselection cuts
  Manager()->AddCut("$\\slashed{E}_T > 110$ [GeV]");
  Manager()->AddCut("$\\slashed{E}_T$ Sig. $> 10$ [$\\sqrt{\\rm GeV}$]");

  // MT2 cuts
  // std::string mt2_100_105[] = {"SR_DF_0J_MT2_100_105", "SR_DF_1J_MT2_100_105",
  //    "SR_SF_0J_MT2_100_105", "SR_SF_1J_MT2_100_105"};
  // std::string mt2_105_110[] = {"SR_DF_0J_MT2_105_110", "SR_DF_1J_MT2_105_110",
  //    "SR_SF_0J_MT2_105_110", "SR_SF_1J_MT2_105_110"};
  // std::string mt2_110_120[] = {"SR_DF_0J_MT2_110_120", "SR_DF_1J_MT2_110_120",
  //    "SR_SF_0J_MT2_110_120", "SR_SF_1J_MT2_110_120"};
  // std::string mt2_120_140[] = {"SR_DF_0J_MT2_120_140", "SR_DF_1J_MT2_120_140",
  //    "SR_SF_0J_MT2_120_140", "SR_SF_1J_MT2_120_140"};
  // std::string mt2_140_160[] = {"SR_DF_0J_MT2_140_160", "SR_DF_1J_MT2_140_160",
  //    "SR_SF_0J_MT2_140_160", "SR_SF_1J_MT2_140_160"};
  // std::string mt2_160_180[] = {"SR_DF_0J_MT2_160_180", "SR_DF_1J_MT2_160_180",
  //    "SR_SF_0J_MT2_160_180", "SR_SF_1J_MT2_160_180"};
  // std::string mt2_180_220[] = {"SR_DF_0J_MT2_180_220", "SR_DF_1J_MT2_180_220",
  //    "SR_SF_0J_MT2_180_220", "SR_SF_1J_MT2_180_220"};
  // std::string mt2_220_260[] = {"SR_DF_0J_MT2_220_260", "SR_DF_1J_MT2_220_260",
  //    "SR_SF_0J_MT2_220_260", "SR_SF_1J_MT2_220_260"};
  // std::string mt2_260_inf[] = {"SR_DF_0J_MT2_260_inf", "SR_DF_1J_MT2_260_inf",
  //    "SR_SF_0J_MT2_260_inf", "SR_SF_1J_MT2_260_inf"};
  // std::string mt2_100_inf[] = {"SR_DF_0J_MT2_100_inf", "SR_DF_1J_MT2_100_inf",
  //    "SR_SF_0J_MT2_100_inf", "SR_SF_1J_MT2_100_inf"};
  // std::string mt2_160_inf[] = {"SR_DF_0J_MT2_160_inf", "SR_DF_1J_MT2_160_inf",
  //    "SR_SF_0J_MT2_160_inf", "SR_SF_1J_MT2_160_inf"};
  // std::string mt2_100_120[] = {"SR_DF_0J_MT2_100_120", "SR_DF_1J_MT2_100_120",
  //    "SR_SF_0J_MT2_100_120", "SR_SF_1J_MT2_100_120"};
  // std::string mt2_120_160[] = {"SR_DF_0J_MT2_120_160", "SR_DF_1J_MT2_120_160",
  //    "SR_SF_0J_MT2_120_160", "SR_SF_1J_MT2_120_160"};
  //
  // Manager()->AddCut("$M_{T2} \\in [100, 105]$ [GeV]",     mt2_100_105);
  // Manager()->AddCut("$M_{T2} \\in [105, 110]$ [GeV]",     mt2_105_110);
  // Manager()->AddCut("$M_{T2} \\in [110, 120]$ [GeV]",     mt2_110_120);
  // Manager()->AddCut("$M_{T2} \\in [120, 140]$ [GeV]",     mt2_120_140);
  // Manager()->AddCut("$M_{T2} \\in [140, 160]$ [GeV]",     mt2_140_160);
  // Manager()->AddCut("$M_{T2} \\in [160, 180]$ [GeV]",     mt2_160_180);
  // Manager()->AddCut("$M_{T2} \\in [180, 220]$ [GeV]",     mt2_180_220);
  // Manager()->AddCut("$M_{T2} \\in [220, 260]$ [GeV]",     mt2_220_260);
  // Manager()->AddCut("$M_{T2} \\in [260, \\infty[$ [GeV]", mt2_260_inf);
  Manager()->AddCut("$M_{T2} \\in [100, \\infty[$ [GeV]");
  // Manager()->AddCut("$M_{T2} \\in [160, \\infty[$ [GeV]", mt2_160_inf);
  // Manager()->AddCut("$M_{T2} \\in [100, 120]$ [GeV]",     mt2_100_120);
  // Manager()->AddCut("$M_{T2} \\in [120, 160]$ [GeV]",     mt2_120_160);

  // Histogram declaration
  // Manager()->AddHisto("MT2-SF-0J",9, 100., 280., SF0J);
  // Manager()->AddHisto("MT2-SF-1J",9, 100., 280., SF1J);
  // Manager()->AddHisto("MT2-DF-0J",9, 100., 280., DF0J);
  // Manager()->AddHisto("MT2-DF-1J",9, 100., 280., DF1J);
Manager()->AddHisto("MT2_0J_ee",9, 100., 280., "SR_0J_ee");
Manager()->AddHisto("MT2_0J_em",9, 100., 280., "SR_0J_em");
Manager()->AddHisto("MT2_0J_mm",9, 100., 280., "SR_0J_mm");


// plot_MET1 = new TH1F("plot_MET1", "MT2_0J_ee", 9, 100, 280);
// plot_MET2 = new TH1F("plot_MET2", "MT2_0J_em", 9, 100, 280);
// plot_MET3 = new TH1F("plot_MET3", "MT2_0J_mm", 9, 100, 280);

// plot_MET2 = new TH1F("plot_MET2", "MT2-SF-1J", 9, 100, 280);
// plot_MET3 = new TH1F("plot_MET3", "MT2-DF-0J", 9, 100, 280);
// plot_MET4 = new TH1F("plot_MET4", "MT2-DF-1J", 9, 100, 280);

  // Exit
  return true;
}

// -----------------------------------------------------------------------------
// Finalize
// function called one time at the end of the analysis
// -----------------------------------------------------------------------------
void LeptonAnalysis::Finalize(const SampleFormat& summary,
                                  const std::vector<SampleFormat>& files){
// TFile* output = new TFile("output.root", "RECREATE");
// plot_MET1->Write();
// plot_MET2->Write();
// plot_MET3->Write();
// // plot_MET4->Write();
// output->Close();
}

// -----------------------------------------------------------------------------
// Execute
// function called each time one event is read
// -----------------------------------------------------------------------------
bool LeptonAnalysis::Execute(SampleFormat& sample, const EventFormat& event)
{
  // Event weight
  MAdouble64 myWeight;
  if(Configuration().IsNoEventWeight()) myWeight=1.;
  else if(event.mc()->weight()!=0.) myWeight=event.mc()->weight();
  else { return false; }
  Manager()->InitializeForNewEvent(myWeight);

  // Security for empty events
  if (event.rec()==0) return true;

  // Electrons
  std::vector<const RecLeptonFormat*> SignalElectrons;
  for(MAuint32 i=0; i<event.rec()->electrons().size(); i++)
  {
    const RecLeptonFormat *Lep = &(event.rec()->electrons()[i]);

    // Kinematics
    MAdouble64 eta = Lep->abseta();
    MAdouble64 pt  = Lep->pt();

    // Isolation
    MAdouble64 iso_dR     = std::min(10./pt,0.2);
    MAdouble64 iso_tracks = PHYSICS->Isol->tracker->relIsolation(Lep, event.rec(), iso_dR, 0.);
    MAdouble64 iso_all    = PHYSICS->Isol->calorimeter->relIsolation(Lep, event.rec(), 0.2, 0.);
    MAbool     iso        = (iso_tracks<0.15 && iso_all<0.20);
    if (pt>200.) { iso    = (iso_all<std::max(0.015*pt, 3.5)); }

    // Signal leptons
    if(eta<2.47 && pt>10. && iso) { SignalElectrons.push_back(Lep);}
  }


  // Muons
  std::vector<const RecLeptonFormat*> SignalMuons;
  for(MAuint32 i=0; i<event.rec()->muons().size(); i++)
  {
    const RecLeptonFormat *Lep = &(event.rec()->muons()[i]);

    // Kinematics
    MAdouble64 eta = Lep->abseta();
    MAdouble64 pt  = Lep->pt();

    // Isolation
    MAdouble64 iso_dR     = std::min(10./pt,0.3);
    MAdouble64 iso_tracks = PHYSICS->Isol->tracker->relIsolation(Lep, event.rec(), iso_dR, 0.);
    MAdouble64 iso_all    = PHYSICS->Isol->calorimeter->relIsolation(Lep, event.rec(), 0.2, 0.);
    MAbool     iso        = (iso_tracks<0.15 && iso_all<0.30);

    // Signal leptons
    if(eta<2.7 && pt>10. && iso) { SignalMuons.push_back(Lep);}
  }

  // Jets
  std::vector <const RecJetFormat*> Jets;
  for(MAuint32 i=0; i<event.rec()->jets().size(); i++)
  {
    const RecJetFormat *Jet = &(event.rec()->jets()[i]);
    MAdouble64 eta = Jet->abseta();
    MAdouble64 pt  = Jet->pt();
    if(pt>20. && eta<2.4) { Jets.push_back(Jet); }
  }

  // Object overlap removal
  Jets = PHYSICS->Isol->JetCleaning(Jets, SignalElectrons, 0.2);
  Jets = PHYSICS->Isol->JetCleaning(Jets, SignalMuons, 0.4);
  SignalElectrons = Removal(SignalElectrons, SignalMuons, 0.2);

  // Bjets and HT
  MAuint32 nb = 0;
  MAdouble64 HT= 0.;
  for (MAuint32 i=0; i<Jets.size(); i++)
  {
    if(Jets[i]->btag()) { nb++; }
    HT += Jets[i]->pt();
  }



  // Leptons
  std::vector<const RecLeptonFormat*> SignalLeptons;
  for(MAuint32 i=0; i<SignalMuons.size(); i++)
    { SignalLeptons.push_back(SignalMuons[i]); }
  for(MAuint32 i=0; i<SignalElectrons.size(); i++)
    { SignalLeptons.push_back(SignalElectrons[i]); }
  SORTER->sort(SignalLeptons, PTordering);

  // MET
  MAdouble64 MET = event.rec()->MET().pt();

  // DiLepton reconstruction
  MAuint32 hasOS   = 0;
  MAuint32 hasOSSF = 0;
  MAuint32 hasOSOF = 0;
  for (MAuint32 lid = 0; lid < SignalLeptons.size(); lid++)
  {
    for (MAuint32 sid = 0; (sid < SignalLeptons.size()) && (sid != lid); sid++)
    {
        int sumflvr = -(SignalLeptons[lid]->isMuon())     * 13 * SignalLeptons[lid]->charge() -\
                       (SignalLeptons[lid]->isElectron()) * 11 * SignalLeptons[lid]->charge() -\
                       (SignalLeptons[sid]->isMuon())     * 13 * SignalLeptons[sid]->charge() -\
                       (SignalLeptons[sid]->isElectron()) * 11 * SignalLeptons[sid]->charge();
        // OS: 0, 2,  OSSF : 0
        // SSOF : 24, SSSF : 22, 26
        // SSOF : 24, OSOF : 2
        if (std::abs(sumflvr) == 0)      {hasOSSF++; hasOS++;}
        else if (std::abs(sumflvr) == 2) {hasOSOF++; hasOS++;}
    }
  }


// DETERMINE WHICH LEPTONS ARE IN EVENT

MAuint32 numElectron   = 0;
MAuint32 numMuon = 0;

for (MAuint32 lep = 0; lep < SignalLeptons.size(); lep++){
  if (SignalLeptons[lep]->isElectron()) {
    numElectron++;
  }
  else if (SignalLeptons[lep]->isMuon()) {
    numMuon++;
  }
}


  //==================//
  //==== Cut Flow ====//
  //==================//

  // Trigger efficiency
  Manager()->SetCurrentEventWeight(myWeight*0.85);

  MAbool is_pt = false;
  if (SignalLeptons.size()>1) is_pt = (SignalLeptons[1]->pt()>25.);
  if(!Manager()->ApplyCut(hasOS==1 && SignalLeptons.size()==2 && is_pt,
                          "OS dilep. with $p^l_T>25$ [GeV]")) return true;


  MAdouble64 mll = (SignalLeptons[0]->momentum() + SignalLeptons[1]->momentum()).M();
  if(!Manager()->ApplyCut(mll>25.,"$m_{l_1,l_2}>25$ [GeV]")) return true;

  if(!Manager()->ApplyCut(nb==0,"b veto")) return true;

  // SF vs DF & Njets
  MAuint32 nj = Jets.size();

  // // SF-DF & Njet cuts
  // if(!Manager()->ApplyCut(hasOSOF==1 && nj==0, "DF dilep. \\& $N_j=0$")) return true;
  // if(!Manager()->ApplyCut(hasOSOF==1 && nj==1, "DF dilep. \\& $N_j=1$")) return true;
  // if(!Manager()->ApplyCut(hasOSSF==1 && nj==0, "SF dilep. \\& $N_j=0$")) return true;
  // if(!Manager()->ApplyCut(hasOSSF==1 && nj==1, "SF dilep. \\& $N_j=1$")) return true;
  //
  // if(!Manager()->ApplyCut(mll>100.,  "$m_{l_1,l_2} > 100$ [GeV]"))   return true;
  // if(!Manager()->ApplyCut(mll>121.2, "$m_{l_1,l_2} > 121.2$ [GeV]")) return true;


// OUR LEPTON CUTS
  if(!Manager()->ApplyCut(numElectron==2 && numMuon==0, "2_Electrons")) return true;
  if(!Manager()->ApplyCut(numElectron==1 && numMuon==1, "1_Electron_1_Muon")) return true;
  if(!Manager()->ApplyCut(numElectron==0 && numMuon==2, "2_Muons")) return true;


  // Other preselection cuts
  MAdouble64 METSig = 11.;
  if (HT>0) METSig = MET/sqrt(HT);
  if(!Manager()->ApplyCut(MET>110.,   "$\\slashed{E}_T > 110$ [GeV]"))                      return true;
  if(!Manager()->ApplyCut(METSig>10., "$\\slashed{E}_T$ Sig. $> 10$ [$\\sqrt{\\rm GeV}$]")) return true;

  // Histograms
  MAdouble64 mt2 = PHYSICS->Transverse->MT2(SignalLeptons[0],SignalLeptons[1],event.rec()->MET(),0.);
  Manager()->FillHisto("MT2_0J_ee",mt2);
  Manager()->FillHisto("MT2_0J_em",mt2);
  Manager()->FillHisto("MT2_0J_mm",mt2);
  // Manager()->FillHisto("MT2-DF-1J",mt2);
// if (nj == 0 && numElectron==2 && numMuon==0) {
//   plot_MET1->Fill(mt2);
// }
// if (nj == 0 && numElectron==1 && numMuon==1) {
//   plot_MET2->Fill(mt2);
// }
// if (nj == 0 && numElectron==0 && numMuon==2) {
//   plot_MET3->Fill(mt2);
// }
// if (nj == 1 && hasOSOF == 1) {
//   plot_MET4->Fill(mt2);
// }


  // MT2
  // if(!Manager()->ApplyCut(mt2>100. && mt2<105.,"$M_{T2} \\in [100, 105]$ [GeV]"))     return true;
  // if(!Manager()->ApplyCut(mt2>105. && mt2<110.,"$M_{T2} \\in [105, 110]$ [GeV]"))     return true;
  // if(!Manager()->ApplyCut(mt2>110. && mt2<120.,"$M_{T2} \\in [110, 120]$ [GeV]"))     return true;
  // if(!Manager()->ApplyCut(mt2>120. && mt2<140.,"$M_{T2} \\in [120, 140]$ [GeV]"))     return true;
  // if(!Manager()->ApplyCut(mt2>140. && mt2<160.,"$M_{T2} \\in [140, 160]$ [GeV]"))     return true;
  // if(!Manager()->ApplyCut(mt2>160. && mt2<180.,"$M_{T2} \\in [160, 180]$ [GeV]"))     return true;
  // if(!Manager()->ApplyCut(mt2>180. && mt2<220.,"$M_{T2} \\in [180, 220]$ [GeV]"))     return true;
  // if(!Manager()->ApplyCut(mt2>220. && mt2<260.,"$M_{T2} \\in [220, 260]$ [GeV]"))     return true;
  // if(!Manager()->ApplyCut(mt2>260.            ,"$M_{T2} \\in [260, \\infty[$ [GeV]")) return true;
  if(!Manager()->ApplyCut(mt2>100.            ,"$M_{T2} \\in [100, \\infty[$ [GeV]")) return true;
  // if(!Manager()->ApplyCut(mt2>160.            ,"$M_{T2} \\in [160, \\infty[$ [GeV]")) return true;
  // if(!Manager()->ApplyCut(mt2>100. && mt2<120.,"$M_{T2} \\in [100, 120]$ [GeV]"))     return true;
  // if(!Manager()->ApplyCut(mt2>120. && mt2<160.,"$M_{T2} \\in [120, 160]$ [GeV]"))     return true;

  // Exit
  return true;
}

// Overlap Removal
template<typename T1, typename T2> std::vector<const T1*>
  Removal(std::vector<const T1*> &v1, std::vector<const T2*> &v2, const MAdouble64 &drmin)
{
  // Determining with objects should be removed
  std::vector<bool> mask(v1.size(),false);
  for (MAuint32 j=0;j<v1.size();j++)
    for (MAuint32 i=0;i<v2.size();i++)
      if (v2[i]->dr(v1[j]) < drmin)
      {
        mask[j]=true;
        break;
      }

  // Building the cleaned container
  std::vector<const T1*> cleaned_v1;
  for (MAuint32 i=0;i<v1.size();i++)
    if (!mask[i]) cleaned_v1.push_back(v1[i]);

  return cleaned_v1;
}
