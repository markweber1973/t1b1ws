#ifndef PHASE_H
#define PHASE_H
#include <string>
#include "round.h"


namespace t1b1dataprocessor
{

class Phase
{
public:
  Phase(std::string name, unsigned int sequence, unsigned int phaseId);
  ~Phase();
  
  bool operator<(const Phase& otherPhase) const;  
  friend std::ostream& operator<<(std::ostream& os, const Phase& aPhase);
  void printOn(std::ostream&) const;
  
  void AddRound(boost::shared_ptr<Round> round);
  void AddBoulderScore(unsigned int startNumber, unsigned int roundId, boost::shared_ptr<BoulderScore> theScore); 
  
  bool IsFinished() const;
  unsigned int GetPhaseId();
private:
  unsigned int m_phaseId;
  std::string m_name;
  unsigned int m_sequence;
  
  typedef std::map <unsigned int, boost::shared_ptr<Round> > RoundMap;		
  typedef std::pair<unsigned int, boost::shared_ptr<Round> > RoundPair;	
  RoundMap m_roundMap; 
};

}

#endif // PHASE_H
