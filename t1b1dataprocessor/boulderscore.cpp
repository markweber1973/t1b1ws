#include <boulderscore.h>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace t1b1dataprocessor
{

BoulderScore::BoulderScore(unsigned int boulderId, bool finished)
{
  m_finished = finished;
  m_boulderId = boulderId;
  m_topScore.reset(new PrimitiveScore(false, 0, "T"));
  m_bonusScore.reset(new PrimitiveScore(false, 0, "B"));   
}

BoulderScore::~BoulderScore()
{
}

bool BoulderScore::IsFinished()
{
  return m_finished;
}

void BoulderScore::TopHit(const unsigned int attempts)
{
  if (attempts == 0) throw invalid_argument("TopHit with 0 attempts is invalid");
  if (!m_bonusScore->IsHit()) throw logic_error("TopHit with no bonus hit is invalid");
  m_topScore.reset(new PrimitiveScore(true, attempts, "T")); 
}

void BoulderScore::BonusHit(const unsigned int attempts)
{
  if (attempts == 0) throw invalid_argument("BonusHit with 0 attempts is invalid"); 
  m_bonusScore.reset(new PrimitiveScore(true, attempts, "B")); 
}
  
void BoulderScore::printOn(std::ostream& strm) const
{
	strm << "<boulderscore>" << std::endl;
  strm << "<id>"    << m_boulderId   << "</id>"    << std::endl;
  strm << "<finished>";   if (m_finished) {strm << "Y";} else {strm << "N";};	  strm << "</finished>"   << std::endl;
	strm << "<value>" << *m_topScore << *m_bonusScore << "</value>" << std::endl;
	strm << "</boulderscore>" << std::endl;	
}

std::ostream& operator<<(std::ostream& os, const BoulderScore& aScore)
{
	aScore.printOn(os);
  return os;
}

}

