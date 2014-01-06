#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <subscore.h>
#include <boost/shared_ptr.hpp>

namespace t1b1dataprocessor
{
class Score {

public:
	Score();
	~Score();

//  Climber operator+(const Score& otherScore) const;
  bool operator==(const Score& otherScore) const;
  bool operator!=(const Score& otherScore) const;  
  bool operator<(const Score& otherScore) const;
  bool operator>(const Score& otherScore) const;
  friend std::ostream& operator<<(std::ostream& os, const Score& aScore);
  void printOn(std::ostream&) const;
  
  void SetTopReached();
  void SetBonusReached();
  bool GetTopReached() const;
  bool GetBonusReached() const ;
  void SetTopAttempts(unsigned int attempts);
  void SetBonusAttempts(unsigned int attempts);  
  unsigned int GetTopAttempts() const;
  unsigned int GetBonusAttempts() const;  
  bool ScoreIsValid() const;
  std::string Score2String();

  private: 
  boost::shared_ptr<SubScore> m_topScore;
  boost::shared_ptr<SubScore> m_bonusScore;  
};

}

#endif // SCORE_H
