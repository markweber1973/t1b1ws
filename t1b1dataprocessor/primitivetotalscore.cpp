#include "primitivetotalscore.h"
using namespace std;
#include <stdexcept>
#include <iostream>

namespace t1b1dataprocessor
{

PrimitiveTotalScore::PrimitiveTotalScore(unsigned int hits, unsigned attempts, std::string prefix)
{
  m_hits = hits;
  m_attempts = attempts;
  m_prefix = prefix;
  if (m_hits > attempts)
  {
    throw invalid_argument("more hits than attempts is impossible");
  }  
}

PrimitiveTotalScore::~PrimitiveTotalScore()
{
}

bool PrimitiveTotalScore::operator<(const PrimitiveTotalScore& otherPrimitiveTotalScore) const
{  
  return ((m_hits < otherPrimitiveTotalScore.m_hits) ||
         ((m_hits == otherPrimitiveTotalScore.m_hits) && (m_attempts > otherPrimitiveTotalScore.m_attempts)));
}

bool PrimitiveTotalScore::operator==(const PrimitiveTotalScore& otherPrimitiveTotalScore) const
{  
  return ((m_hits == otherPrimitiveTotalScore.m_hits) && (m_attempts == otherPrimitiveTotalScore.m_attempts));
}

bool PrimitiveTotalScore::operator!=(const PrimitiveTotalScore& otherPrimitiveTotalScore) const
{  
  return (!(*this == otherPrimitiveTotalScore));
}

bool PrimitiveTotalScore::operator>(const PrimitiveTotalScore& otherPrimitiveTotalScore) const
{  
  return ((*this != otherPrimitiveTotalScore) && (!(*this<otherPrimitiveTotalScore)));
}

void PrimitiveTotalScore::printOn(std::ostream& strm) const
{
  strm << m_hits << m_prefix << m_attempts;
}

std::ostream& operator<<(std::ostream& os, const PrimitiveTotalScore& aPrimitiveTotalScore)
{
	aPrimitiveTotalScore.printOn(os);
  return os;
}

}

