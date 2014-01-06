#ifndef TOTALSCORE_H
#define TOTALSCORE_H

#include <score.h>
#include <subscore.h>
#include <boost/scoped_ptr.hpp>
#include "primitivetotalscore.h"


namespace t1b1dataprocessor
{


class TotalScore {

public:
	TotalScore(unsigned int topHits, unsigned int topAttempts, 
            unsigned int bonusHits, unsigned int bonusAttempts);
	~TotalScore() {};
  
  bool operator==(const TotalScore& otherScore) const;
  bool operator!=(const TotalScore& otherScore) const;  
  bool operator<(const TotalScore& otherScore) const;
  bool operator>(const TotalScore& otherScore) const;  

  friend std::ostream& operator<<(std::ostream& os, const TotalScore& aScore);
  void printOn(std::ostream&) const;

private:
  boost::scoped_ptr<PrimitiveTotalScore> m_topScore;
  boost::scoped_ptr<PrimitiveTotalScore> m_bonusScore;  
};

}

#endif // TOTALSCORE_H
