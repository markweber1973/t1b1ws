#include "round.h"
#include "scorecard.h"
#include <boost/foreach.hpp>
#include <boost/iterator/indirect_iterator.hpp>

namespace t1b1dataprocessor
{
	

Round::Round(std::string name, unsigned int nrOfBoulders): m_nrOfBoulders(nrOfBoulders), m_name(name)
{
}

Round::~Round()
{
}

void Round::AddScoreCard(boost::shared_ptr<ScoreCard> scorecard)
{  
  m_scorecards.push_back(scorecard); 
  std::sort(boost::make_indirect_iterator(m_scorecards.begin()), 
            boost::make_indirect_iterator(m_scorecards.end()), 
            std::greater<ScoreCard>());
  
  unsigned int rank = 1;
  std::vector<boost::shared_ptr<ScoreCard> >::iterator scoreCardIt = m_scorecards.begin();

  unsigned int vectorSize = m_scorecards.size();

  for (unsigned int x = 0; x < vectorSize; x++)
  {
    m_scorecards.at(x)->SetRank(rank);
    if (x+1 < vectorSize)
    {
      if (!m_scorecards.at(x)->IsEmpty() && !m_scorecards.at(x+1)->IsEmpty())
      {
        boost::shared_ptr<TotalScore> oneScore = m_scorecards.at(x)->GetTotalScore();
        boost::shared_ptr<TotalScore> twoScore = m_scorecards.at(x+1)->GetTotalScore();          
        if ( (*oneScore) > (*twoScore))
        {
          rank++;
        }        
      }
    }
  }  
}

void Round::printOn(std::ostream& strm) const
{
	strm << "<round>" << std::endl;
	strm << "<name>"   << m_name.c_str()   << "</name>"   << std::endl;
	strm << "<scorecards>" << std::endl;  
  BOOST_FOREACH(boost::shared_ptr<ScoreCard> localcard, m_scorecards)
  {
    strm << *localcard;
  }
	strm << "</scorecards>" << std::endl;    
	strm << "</round>" << std::endl;	
}

std::ostream& operator<<(std::ostream& os, const Round& aRound)
{
  aRound.printOn(os);
  return os;
}

}

