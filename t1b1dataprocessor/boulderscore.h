#ifndef BOULDERSCORE_H
#define BOULDERSCORE_H

#include <boost/scoped_ptr.hpp>
#include "primitivescore.h"

namespace t1b1dataprocessor
{

class BoulderScore {

public:
	BoulderScore(unsigned int boulderId, bool finished);
	~BoulderScore();

  friend std::ostream& operator<<(std::ostream& os, const BoulderScore& aScore);
  void printOn(std::ostream&) const;
  
  void TopHit(const unsigned int attempts);
  bool IsTopHit() const {return m_topScore->IsHit();};
  unsigned int GetTopAttempts() const {return m_topScore->GetAttempts();};
  
  void BonusHit(const unsigned int attempts);
  bool IsBonusHit() const {return m_bonusScore->IsHit();};
  unsigned int GetBonusAttempts() const {return m_bonusScore->GetAttempts();};

  unsigned int GetBoulderId() const {return m_boulderId;} ;
  bool IsFinished();

private:
  boost::scoped_ptr<PrimitiveScore> m_bonusScore;
  boost::scoped_ptr<PrimitiveScore> m_topScore;
  bool m_finished;
  unsigned int m_boulderId;
};

}

#endif // BOULDERSCORE_H
