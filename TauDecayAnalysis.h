#ifndef analysis_TauDecayAnalysis_h
#define analysis_TauDecayAnalysis_h

#include "SampleAnalyzer/Process/Analyzer/AnalyzerBase.h"

namespace MA5
{
class TauDecayAnalysis : public AnalyzerBase
{
  INIT_ANALYSIS(TauDecayAnalysis,"TauDecayAnalysis")

 public:
  virtual bool Initialize(const MA5::Configuration& cfg, const std::map<std::string,std::string>& parameters);
  virtual void Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files);
  virtual bool Execute(SampleFormat& sample, const EventFormat& event);

 private:
};
}

#endif
