#include <score.h>
#include <assert.h>
#include <iostream>

namespace t1b1dataprocessor
{

Score::Score()
{
  m_topScore.reset(new SubScore());
  m_bonusScore.reset(new SubScore());
}

Score::~Score()
{
}

bool Score::ScoreIsValid() const
{
  if (m_topScore->GetHits() == 1)
  {
    return (GetBonusReached() && (GetTopAttempts() > 0) && (GetBonusAttempts() > 0));
  }
  else if (GetBonusReached())
  {
    return (GetBonusAttempts() > 0);
  }
  else
  {
    return true;
  }
}

bool Score::operator==(const Score& otherScore) const
{
  assert(ScoreIsValid() && otherScore.ScoreIsValid());
  if (GetTopReached() && otherScore.GetTopReached())
  {
    return ((GetTopAttempts() == otherScore.GetTopAttempts()) && (GetBonusAttempts() == otherScore.GetBonusAttempts()));
  }
  else if ((GetBonusReached() && !GetTopReached()) && (otherScore.GetBonusReached() && !otherScore.GetTopReached()))
  {
    return (GetBonusAttempts() == otherScore.GetBonusAttempts());
  }
  else if (!GetBonusReached() && !GetTopReached() && !otherScore.GetBonusReached() && !otherScore.GetTopReached())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Score::operator!=(const Score& otherScore) const
{
  return !(*this == otherScore);
}

bool Score::operator<(const Score& otherScore) const
{
  if (GetTopReached() && otherScore.GetTopReached())
  {
    if (GetTopAttempts() > otherScore.GetTopAttempts())
    {
      return true;
    }
    else if (GetTopAttempts() < otherScore.GetTopAttempts())
    {
      return false;
    }
    else if (GetBonusAttempts() > otherScore.GetBonusAttempts())
    {
      return true;
    }
    else
    {
      return false;      
    }
  }
  else if (!GetTopReached() && otherScore.GetTopReached())
  {
    return true;
  }
  else if (GetTopReached() && !otherScore.GetTopReached())
  {
    return false;
  }
  else if (!GetBonusReached() && otherScore.GetBonusReached())
  {
    return true;   
  }
  else if (GetBonusReached() && !otherScore.GetBonusReached())    
  {
    return false;
  }
  else if (GetBonusReached() && otherScore.GetBonusReached()) 
  {
    if (GetBonusAttempts() > otherScore.GetBonusAttempts())
    {    
      return true;
    }
    else 
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

bool Score::operator>(const Score& otherScore) const
{
  return (!(*this < otherScore) && !(*this == otherScore));
}

void Score::SetTopReached()
{
  assert (0 == m_topScore->GetHits());
  m_topScore->AddHit();
}

void Score::SetBonusReached()
{
  assert (0 == m_bonusScore->GetHits());
  m_bonusScore->AddHit();
}

bool Score::GetTopReached() const
{
  return (1 == m_topScore->GetHits());
}

bool Score::GetBonusReached() const
{
  return (1 == m_bonusScore->GetHits());
}

void Score::SetTopAttempts(unsigned int attempts)
{
  assert(0 == m_topScore->GetAttempts());
  m_topScore->AddAttempts(attempts);
}

void Score::SetBonusAttempts(unsigned int attempts)
{
  assert(0 == m_bonusScore->GetAttempts());
  m_bonusScore->AddAttempts(attempts);
}

unsigned int Score::GetTopAttempts() const
{
  return m_topScore->GetAttempts();
}

unsigned int Score::GetBonusAttempts() const
{
  return m_bonusScore->GetAttempts();
}

void Score::printOn(std::ostream& strm) const
{
	strm << "<score>" << std::endl;
  strm << "<topped>";   if (GetTopReached()) {strm << "Y";} else {strm << "N";};	  strm << "</topped>"   << std::endl;
	strm << "<bonussed>";	if (GetBonusReached()) {strm << "Y";} else {strm << "N";};	strm << "</bonussed>" << std::endl;
	strm << "<topattempts>"    << GetTopAttempts()   << "</topattempts>"    << std::endl;
	strm << "<bonusattempts>"    << GetBonusAttempts()   << "</bonusattempts>"    << std::endl;
	
  strm << "<stringvalue>T";
  if (GetTopReached()) strm << GetTopAttempts();
  else strm << "-";
	strm << "B";  
  if (GetBonusReached()) strm << GetBonusAttempts();
  else strm << "-" << std::endl;;
	strm << "</stringvalue>" << std::endl;  
	strm << "</score>" << std::endl;	
}

std::ostream& operator<<(std::ostream& os, const Score& aScore)
{
	aScore.printOn(os);
  return os;
}
}

