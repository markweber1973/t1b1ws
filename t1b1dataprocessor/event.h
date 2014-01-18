#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "phase.h"

namespace t1b1dataprocessor
{

class Event
{
public:
  Event(std::string name, unsigned int eventId);
  ~Event();
  
  friend std::ostream& operator<<(std::ostream& os, const Event& anEvent);
  void printOn(std::ostream&) const; 
  void AddPhase(boost::shared_ptr<Phase> phase);
  void AddBoulderScore(unsigned int phaseId, unsigned int roundId, boost::shared_ptr<BoulderScore> theScore, unsigned int startNumber);
  unsigned int GetEventId();
  
private:
  unsigned int m_eventId;
  std::string m_name;
  
  typedef std::map <unsigned int, boost::shared_ptr<Phase> > PhaseMap;		
  typedef std::pair<unsigned int, boost::shared_ptr<Phase> > PhasePair;	
  PhaseMap m_phaseMap;
};

}

#endif // EVENT_H
