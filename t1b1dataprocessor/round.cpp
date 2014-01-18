#include "round.h"
#include "scorecard.h"
#include <boost/foreach.hpp>
#include <boost/iterator/indirect_iterator.hpp>

namespace t1b1dataprocessor
{
	

Round::Round(std::string name, unsigned int sequence, unsigned int nrOfBoulders, unsigned int roundId): 
  m_name(name), m_sequence(sequence), m_nrOfBoulders(nrOfBoulders), m_roundId(roundId)
{
}

Round::~Round()
{
}

unsigned int Round::GetRoundId() const
{
  return m_roundId;  
}

void Round::AddScoreCard(boost::shared_ptr<ScoreCard> scorecard)
{  
  m_scoreCardMap[scorecard->GetStartNumber()] = scorecard; 
}

void Round::AddBoulderScore(unsigned int startNumber, boost::shared_ptr<BoulderScore> theScore)
{
  m_scoreCardMap[startNumber]->AddScore(theScore);
}

void Round::PrintScoreCards(std::ostream& strm) const
{
  std::vector<boost::shared_ptr<ScoreCard> > localVector;
  for (auto& x: m_scoreCardMap) 
  {
    localVector.push_back(x.second);
  }

  std::sort(boost::make_indirect_iterator(localVector.begin()), 
            boost::make_indirect_iterator(localVector.end()), 
            std::greater<ScoreCard>());
  
  unsigned int rank = 1;
  std::vector<boost::shared_ptr<ScoreCard> >::iterator scoreCardIt = localVector.begin();

  unsigned int vectorSize = localVector.size();

  for (unsigned int x = 0; x < vectorSize; x++)
  {
    localVector.at(x)->SetRank(rank);
    if (x+1 < vectorSize)
    {
      if (!localVector.at(x)->IsEmpty() && !localVector.at(x+1)->IsEmpty())
      {
        boost::shared_ptr<TotalScore> oneScore = localVector.at(x)->GetTotalScore();
        boost::shared_ptr<TotalScore> twoScore = localVector.at(x+1)->GetTotalScore();          
        if ( (*oneScore) > (*twoScore))
        {
          rank++;
        }        
      }
    }
  }  
  
  BOOST_FOREACH(boost::shared_ptr<ScoreCard> localcard, localVector)
  {
    strm << *localcard;
  }  
}

void Round::printOn(std::ostream& strm) const
{
	strm << "<round>" << std::endl;
	strm << "<name>"   << m_name.c_str()   << "</name>"   << std::endl;
  if (IsFinished())
  {
	  strm << "<roundfinished>Round finished</roundfinished>" << std::endl;
  }
  else
  {
	  strm << "<roundfinished>Round not finished</roundfinished>" << std::endl;
  }
  for (unsigned int x = 1; x <= m_nrOfBoulders; x++)
  {
    strm << "<boulder>" << std::endl;    
    strm << "<number>" << x << "</number>" << std::endl;    
    strm << "</boulder>" << std::endl;        
  }

	strm << "<scorecards>" << std::endl;  
  PrintScoreCards(strm);

	strm << "</scorecards>" << std::endl;    
	strm << "</round>" << std::endl;	
}

bool Round::operator<(const Round& otherRound) const
{
  return m_sequence < otherRound.m_sequence;
}

std::ostream& operator<<(std::ostream& os, const Round& aRound)
{
  aRound.printOn(os);
  return os;
}

bool Round::IsFinished() const
{
  for (auto& x: m_scoreCardMap) 
  {
    if (!x.second->IsFinished())
    {
      return false;
    }
  }   
  return true;  
}

}

