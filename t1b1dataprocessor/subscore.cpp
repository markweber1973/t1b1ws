#include <subscore.h>

namespace t1b1dataprocessor
{
  
bool SubScore::operator==(const SubScore& otherScore) const
{
  return (m_hits == otherScore.GetHits()) && (m_attempts == otherScore.GetAttempts());
}

bool SubScore::operator!=(const SubScore& otherScore) const
{
  return !(*this == otherScore); 
}

bool SubScore::operator<(const SubScore& otherScore) const
{
  if (m_hits < otherScore.GetHits())
  {
    return true;
  }
  else if (m_hits >= otherScore.GetHits())
  {
    return false;   
  }
  else
  {
    return (m_attempts < otherScore.GetAttempts());
  }
}

bool SubScore::operator>(const SubScore& otherScore) const
{
  return (!(*this < otherScore) && !(*this == otherScore));
}

bool SubScore::operator>=(const SubScore& otherScore) const
{
  return !(*this < otherScore);
}

bool SubScore::operator<=(const SubScore& otherScore) const
{
  return !(*this > otherScore);
}


}

