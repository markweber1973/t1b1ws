#include <score.h>
#include <totalscore.h>
#include <primitivetotalscore.h>
#include <stdexcept>

#include <iostream>
using namespace std;

namespace t1b1dataprocessor
{

TotalScore::TotalScore(unsigned int topHits,   unsigned int topAttempts, 
                       unsigned int bonusHits, unsigned int bonusAttempts)
{    
  if (topHits > topAttempts) throw invalid_argument("more top hits than attempts is impossible");
  if (bonusHits > bonusAttempts) throw invalid_argument("more bonus hits than attempts is impossible");  
  if (topHits > bonusHits) throw invalid_argument("more top hits than bonus hits is impossible");  
  if ((topHits == bonusHits) && (bonusAttempts > topAttempts))
  {
    throw invalid_argument("equal nr of bonus and top hits, but more bonus attempts is invalid");    
  }
  m_topScore.reset(new PrimitiveTotalScore(topHits, topAttempts, "T"));
  m_bonusScore.reset(new PrimitiveTotalScore(bonusHits, bonusAttempts, "B"));  
}


bool TotalScore::operator==(const TotalScore& otherScore) const
{
  return ((*m_topScore == *otherScore.m_topScore) && 
         ((*m_bonusScore == *otherScore.m_bonusScore)));
}

bool TotalScore::operator!=(const TotalScore& otherScore) const
{
  return (!(*m_topScore == *otherScore.m_topScore));
}

bool TotalScore::operator<(const TotalScore& otherScore) const
{
  return (
    (*m_topScore < *otherScore.m_topScore) || 
    (
     (*m_topScore == *otherScore.m_topScore) && 
     (*m_bonusScore < *otherScore.m_bonusScore)
    ));
}

bool TotalScore::operator>(const TotalScore& otherScore) const
{
	return ((!(*m_topScore < *otherScore.m_topScore)) && (*m_topScore != *otherScore.m_topScore));
}

void TotalScore::printOn(std::ostream& strm) const
{
	strm << "<totalscore>" << std::endl;
  strm << "<nroftops>"; m_topScore->GetHits();	strm << "</nroftops>" << std::endl;
  strm << "<nrofbonusses>"; m_bonusScore->GetHits();	strm << "</nrofbonusses>" << std::endl;
  strm << "<nroftopattempts>"; m_topScore->GetAttempts();	strm << "</nroftopattempts>" << std::endl;  
  strm << "<nrofbonusattempts>"; m_bonusScore->GetAttempts();	strm << "</nrofbonusattempts>" << std::endl;
	
  strm << "<stringvalue>";  
  strm << m_topScore->GetHits();  strm << "T"; strm << m_topScore->GetAttempts();
  strm << " ";
  strm << m_bonusScore->GetHits(); strm << "B"; strm << m_bonusScore->GetAttempts();
	strm << "</stringvalue>" << std::endl;
	strm << "</totalscore>" << std::endl;	
}

std::ostream& operator<<(std::ostream& os, const TotalScore& aScore)
{
	aScore.printOn(os);
  return os;
}

}

