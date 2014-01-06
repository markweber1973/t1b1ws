#ifndef SCORECARD_H
#define SCORECARD_H

#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>
#include "enrolledclimber.h"
#include "boulderscore.h"
#include "totalscore.h"


namespace t1b1dataprocessor
{
	
class ScoreCard {

public:
  ScoreCard(boost::shared_ptr<EnrolledClimber> enrolledClimber);
  ScoreCard(boost::shared_ptr<EnrolledClimber> enrolledClimber, unsigned int nrOfBoulders);
  ScoreCard(boost::shared_ptr<EnrolledClimber> enrolledClimber, unsigned int nrOfBoulders, unsigned int polePosition);
  ~ScoreCard();
  
  bool operator==(const ScoreCard& otherScoreCard) const;
  bool operator!=(const ScoreCard& otherScoreCard) const;  
  bool operator<(const ScoreCard& otherScoreCard) const;
  bool operator>(const ScoreCard& otherScoreCard) const;
  
  friend std::ostream& operator<<(std::ostream& os, const ScoreCard& aScoreCard);
  void printOn(std::ostream&) const;
  
  void AddScore(boost::shared_ptr<BoulderScore> score);
  bool IsEmpty();
  void SetRank(unsigned int rank);
  unsigned int GetRank();  
  boost::shared_ptr<TotalScore> GetTotalScore() const;

private:

  boost::shared_ptr<EnrolledClimber> m_climber;    
  
  typedef std::map <unsigned int, boost::shared_ptr<BoulderScore> > BoulderScoreMap;		
  typedef std::pair<unsigned int, boost::shared_ptr<BoulderScore> > BoulderScorePair;	
  BoulderScoreMap m_boulderScoreMap;
  unsigned int m_polePosition;
  unsigned int m_rank;
  bool m_isEmpty;
 
};

}

#endif // SCORECARD_H
