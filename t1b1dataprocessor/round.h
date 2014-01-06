
#ifndef ROUND_H
#define ROUND_H
#include <string>
#include "scorecard.h"

namespace t1b1dataprocessor
{

class Round
{
public:
  Round(std::string name, unsigned int nrOfBoulders);
  void AddScoreCard(boost::shared_ptr<ScoreCard> scorecard);
	~Round();
  
  friend std::ostream& operator<<(std::ostream& os, const Round& aRound);
  void printOn(std::ostream&) const;
  
private:
  std::string m_name;
  unsigned int m_nrOfBoulders;
  std::vector<boost::shared_ptr<ScoreCard> > m_scorecards;
};

}

#endif // ROUND_H
