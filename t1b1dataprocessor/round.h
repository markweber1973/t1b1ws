
#ifndef ROUND_H
#define ROUND_H
#include <string>
#include "scorecard.h"

namespace t1b1dataprocessor
{

class Round
{
public:
  Round(std::string name, unsigned int sequence, unsigned int nrOfBoulders, unsigned int roundId);
	~Round();
  
  bool operator<(const Round& otherRound) const;  
  friend std::ostream& operator<<(std::ostream& os, const Round& aRound);
  void printOn(std::ostream& strm) const;
  void PrintScoreCards(std::ostream& strm) const;
  
  void AddScoreCard(boost::shared_ptr<ScoreCard> scorecard);
  void AddBoulderScore(unsigned int startNumber, boost::shared_ptr<BoulderScore> theScore);
  boost::shared_ptr<BoulderScore> GetBoulderScore(unsigned int startNumber);  
  unsigned int GetNrOfBoulders() {return m_nrOfBoulders;};
  bool IsFinished() const;
  unsigned int GetRoundId() const;

private:
  std::string m_name;
  unsigned int m_roundId;
  unsigned int m_sequence;
  unsigned int m_nrOfBoulders; 
  
  typedef std::map <unsigned int, boost::shared_ptr<ScoreCard> > ScoreCardMap;		
  typedef std::pair<unsigned int, boost::shared_ptr<ScoreCard> > ScoreCardPair;	
  ScoreCardMap m_scoreCardMap;  
};

}

#endif // ROUND_H
