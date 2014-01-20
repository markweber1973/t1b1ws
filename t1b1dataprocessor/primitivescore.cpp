#include "primitivescore.h"
using namespace std;
#include <stdexcept>
#include <iostream>

namespace t1b1dataprocessor
{

PrimitiveScore::PrimitiveScore(bool hit, unsigned attempts, std::string prefix): 
  m_finished(false), m_hit(hit), m_attempts(attempts), m_prefix(prefix)
{
  if (!m_hit && attempts != 0)
  {
    throw invalid_argument("attempts shall be zero when not hit");
  }
}

PrimitiveScore::~PrimitiveScore()
{
}

bool PrimitiveScore::operator<(const PrimitiveScore& otherPrimitiveScore) const
{  
  return ((!m_hit && otherPrimitiveScore.m_hit) || 
          ((m_hit && otherPrimitiveScore.m_hit) && 
           (m_attempts > otherPrimitiveScore.m_attempts)));
}

bool PrimitiveScore::operator==(const PrimitiveScore& otherPrimitiveScore) const
{  
  return (
    (m_hit && otherPrimitiveScore.m_hit) && (m_attempts == otherPrimitiveScore.m_attempts) ||
    (!m_hit && !otherPrimitiveScore.m_hit)	
	);
}

void PrimitiveScore::printOn(std::ostream& strm) const
{
    if (m_finished)
    {
      strm << m_prefix;
      if (m_hit) strm << m_attempts;
      else strm << "-";
    }
    else
    {
      strm << "  ";
    }
}

std::ostream& operator<<(std::ostream& os, const PrimitiveScore& aPrimitiveScore)
{
	aPrimitiveScore.printOn(os);
  return os;
}

}

