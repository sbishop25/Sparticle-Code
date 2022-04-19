#ifndef analysis_LeptonAnalysis_h
#define analysis_LeptonAnalysis_h

#include "SampleAnalyzer/Process/Analyzer/AnalyzerBase.h"

namespace MA5
{
class LeptonAnalysis : public AnalyzerBase
{
  INIT_ANALYSIS(LeptonAnalysis,"LeptonAnalysis")

 public:
  virtual bool Initialize(const MA5::Configuration& cfg, const std::map<std::string,std::string>& parameters);
  virtual void Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files);
  virtual bool Execute(SampleFormat& sample, const EventFormat& event);

 private:
};
}

#endif
