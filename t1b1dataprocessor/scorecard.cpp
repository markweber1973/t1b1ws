#include <scorecard.h>
#include <iostream>
#include <boost/foreach.hpp>

namespace t1b1dataprocessor
{

ScoreCard::ScoreCard(boost::shared_ptr<EnrolledClimber> enrolledClimber)
{
  m_climber = enrolledClimber;
}

ScoreCard::ScoreCard(boost::shared_ptr<EnrolledClimber> enrolledClimber, unsigned int nrOfBoulders)
{
  m_climber = enrolledClimber;
  for (unsigned int x=1; x<=nrOfBoulders; x++)
  {
	  boost::shared_ptr<BoulderScore> localBoulderScore (new BoulderScore(x, false));
	  m_boulderScoreMap.insert(BoulderScorePair(x, localBoulderScore));  
  }
}

ScoreCard::ScoreCard(boost::shared_ptr<EnrolledClimber> enrolledClimber, unsigned int nrOfBoulders, unsigned int polePosition): m_polePosition(polePosition), m_isEmpty(true), m_rank(0)
{
  m_climber = enrolledClimber;
  for (unsigned int x=1; x<=nrOfBoulders; x++)
  {
	  boost::shared_ptr<BoulderScore> localBoulderScore (new BoulderScore(x, false));
	  m_boulderScoreMap.insert(BoulderScorePair(x, localBoulderScore));  
  }
}

ScoreCard::~ScoreCard()
{
}

class Criterium
{
public:
    bool operator()(const BoulderScore& left, const BoulderScore& right)const 
    { 
      return left.GetBoulderId()  < right.GetBoulderId();
    };
};

void ScoreCard::AddScore(boost::shared_ptr<BoulderScore> score)
{
  if (score->IsFinished()) m_isEmpty = false;
  m_boulderScoreMap[score->GetBoulderId()] = score;
}

bool ScoreCard::IsEmpty() const
{
  return m_isEmpty;
}

bool ScoreCard::IsFinished() const
{
  BOOST_FOREACH(BoulderScorePair localscore, m_boulderScoreMap)
  {
    if (!localscore.second->IsFinished())
    {
      return false;
    }
  }  
  return true;
}

void ScoreCard::SetRank(unsigned int rank)
{
  m_rank = rank;
}

unsigned int ScoreCard::GetRank()
{
  return(m_rank);
}

unsigned int ScoreCard::GetStartNumber()
{
  return m_climber->GetStartNumber();
}


bool ScoreCard::operator==(const ScoreCard& otherScoreCard) const
{
  return false;  
}

bool ScoreCard::operator!=(const ScoreCard& otherScoreCard) const
{
  return !(*this == otherScoreCard);
}

boost::shared_ptr<TotalScore> ScoreCard::GetTotalScore() const
{
  unsigned int nrOfTopHits = 0;
  unsigned int nrOfBonusHits = 0;
  unsigned int nrOfTopAttempts = 0;
  unsigned int nrOfBonusAttempts = 0;
   
  BOOST_FOREACH(BoulderScorePair localScore, m_boulderScoreMap)
  {
    if (localScore.second->IsTopHit())
    {
      nrOfTopHits++;
      nrOfTopAttempts+=localScore.second->GetTopAttempts();
    }
    if (localScore.second->IsBonusHit())
    {
      nrOfBonusHits++;
      nrOfBonusAttempts+=localScore.second->GetBonusAttempts();
    }
  }
  boost::shared_ptr<TotalScore> thisTotal (new TotalScore(nrOfTopHits, nrOfTopAttempts, nrOfBonusHits, nrOfBonusAttempts));
  return thisTotal;  
}

bool ScoreCard::operator<(const ScoreCard& otherScoreCard) const
{
  unsigned int nrOfTopHits = 0;
  unsigned int nrOfBonusHits = 0;
  unsigned int nrOfTopAttempts = 0;
  unsigned int nrOfBonusAttempts = 0;
  
  unsigned int thisNrOfFinishedBoulders = 0;
  BOOST_FOREACH(BoulderScorePair localScore, m_boulderScoreMap)
  {
    if (localScore.second->IsFinished())
    {
      thisNrOfFinishedBoulders++;
    }
    if (localScore.second->IsTopHit())
    {
      nrOfTopHits++;
      nrOfTopAttempts+=localScore.second->GetTopAttempts();
    }
    if (localScore.second->IsBonusHit())
    {
      nrOfBonusHits++;
      nrOfBonusAttempts+=localScore.second->GetBonusAttempts();
    }
  }
  boost::scoped_ptr<TotalScore> thisTotal (new TotalScore(nrOfTopHits, nrOfTopAttempts, nrOfBonusHits, nrOfBonusAttempts));
  nrOfTopHits = 0;
  nrOfBonusHits = 0;
  nrOfTopAttempts = 0;
  nrOfBonusAttempts = 0;
  
  unsigned int otherNrOfFinishedBoulders = 0;  
  BOOST_FOREACH(BoulderScorePair localScore, otherScoreCard.m_boulderScoreMap)
  {
    if (localScore.second->IsFinished())
    {
      otherNrOfFinishedBoulders++;
    }   
    if (localScore.second->IsTopHit())
    {
      nrOfTopHits++;
      nrOfTopAttempts+=localScore.second->GetTopAttempts();
    }
    if (localScore.second->IsBonusHit())
    {
      nrOfBonusHits++;
      nrOfBonusAttempts+=localScore.second->GetBonusAttempts();
    }
  }  
  boost::scoped_ptr<TotalScore> otherTotal (new TotalScore(nrOfTopHits, nrOfTopAttempts, nrOfBonusHits, nrOfBonusAttempts));  
  
  if (*thisTotal == *otherTotal)
  {
    if (thisNrOfFinishedBoulders < otherNrOfFinishedBoulders)
    {
      return true;
    }
    else
    {
      return m_polePosition > otherScoreCard.m_polePosition;
    }
  }
  else
  {
    return *thisTotal < *otherTotal;
  }
}

bool ScoreCard::operator>(const ScoreCard& otherScoreCard) const
{
  return (!(*this < otherScoreCard) && !(*this == otherScoreCard)); 
}

void ScoreCard::printOn(std::ostream& strm) const
{
  strm << "<scorecard>" << std::endl;
  strm << "<poleposition>" << m_polePosition << "</poleposition>" << std::endl;  
  if (m_isEmpty)
  {
    strm << "<rank>-</rank>" << std::endl;       
  }
  else
  {
    strm << "<rank>" << m_rank << "</rank>" << std::endl;   
  }
  
  strm << *m_climber;

  BOOST_FOREACH(BoulderScorePair localscore, m_boulderScoreMap)
  {
    strm << *(localscore.second);
  }
  strm << *GetTotalScore();
  strm << "</scorecard>" << std::endl;	
}

std::ostream& operator<<(std::ostream& os, const ScoreCard& aScoreCard)
{
  aScoreCard.printOn(os);
  return os;
}

}

