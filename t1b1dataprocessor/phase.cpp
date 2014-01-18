#include "phase.h"
#include <boost/foreach.hpp>
#include <boost/iterator/indirect_iterator.hpp>

namespace t1b1dataprocessor
{

Phase::Phase(std::string name, unsigned int sequence, unsigned int phaseId): m_name(name), m_sequence(sequence), m_phaseId(phaseId)
{
}

Phase::~Phase()
{
}

void Phase::AddRound(boost::shared_ptr<Round> round)

{
  m_roundMap[round->GetRoundId()] = round;
}

void Phase::AddBoulderScore(unsigned int startNumber, unsigned int roundId, boost::shared_ptr<BoulderScore> theScore)
{
  m_roundMap[roundId]->AddBoulderScore(startNumber, theScore);
}

void Phase::printOn(std::ostream& strm) const
{
	strm << "<phase>" << std::endl;
	strm << "<phasename>"   << m_name.c_str()   << "</phasename>"   << std::endl;

  std::vector<boost::shared_ptr<Round> > localRoundsVector; 
  for (auto& x: m_roundMap) 
  {
    localRoundsVector.push_back(x.second);
  }
//  std::sort(localRoundsVector.begin(), localRoundsVector.end());
  std::sort(boost::make_indirect_iterator(localRoundsVector.begin()), 
            boost::make_indirect_iterator(localRoundsVector.end()), 
            std::less<Round>());  


	strm << "<rounds>" << std::endl;  
  BOOST_FOREACH(boost::shared_ptr<Round> localRound, localRoundsVector)
  {
    strm << *localRound;
  }
	strm << "</rounds>" << std::endl;    
	strm << "</phase>" << std::endl;	
}

bool Phase::operator<(const Phase& otherPhase) const
{
  return m_sequence < otherPhase.m_sequence;
}

std::ostream& operator<<(std::ostream& os, const Phase& aPhase)
{
  aPhase.printOn(os);
  return os;    
}

bool Phase::IsFinished() const
{
  for (auto& x: m_roundMap) 
  {
    if (!x.second->IsFinished())
    {
      return false;
    }
  }   
  return true;
}

unsigned int Phase::GetPhaseId()
{
  return m_phaseId;
}

}

