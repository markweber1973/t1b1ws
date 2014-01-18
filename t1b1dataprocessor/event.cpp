#include "event.h"
#include <boost/foreach.hpp>
#include <boost/iterator/indirect_iterator.hpp>

namespace t1b1dataprocessor
{

Event::Event(std::string name, unsigned int eventId): m_name(name), m_eventId(eventId)
{
}

Event::~Event()
{
}

void Event::AddPhase(boost::shared_ptr<Phase> phase)
{
  m_phaseMap[phase->GetPhaseId()] = phase;
}

unsigned int Event::GetEventId()
{
  return m_eventId;
}

void Event::AddBoulderScore(unsigned int phaseId, unsigned int roundId, boost::shared_ptr<BoulderScore> theScore, unsigned int startNumber)
{
  m_phaseMap[phaseId]->AddBoulderScore(startNumber, roundId, theScore);
}

void Event::printOn(std::ostream& strm) const
{
	strm << "<event>" << std::endl;
	strm << "<name>"   << m_name.c_str()   << "</name>"   << std::endl;

	strm << "<phases>" << std::endl;  
  
  
  std::vector<boost::shared_ptr<Phase> > localVector;
  for (auto& x: m_phaseMap) 
  {
    localVector.push_back(x.second);
  }
  std::sort(boost::make_indirect_iterator(localVector.begin()), 
            boost::make_indirect_iterator(localVector.end()), 
            std::less<Phase>());  
  
  BOOST_FOREACH(boost::shared_ptr<Phase> localphase, localVector)
  {
    strm << *localphase;
  }
	strm << "</phases>" << std::endl;    
	strm << "</event>" << std::endl;	
}

std::ostream& operator<<(std::ostream& os, const Event& aEvent)
{
  aEvent.printOn(os);
  return os;
}

}

