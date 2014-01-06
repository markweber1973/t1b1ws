#ifndef PRIMITIVETOTALSCORE_H
#define PRIMITIVETOTALSCORE_H

#include <string>

namespace t1b1dataprocessor
{

class PrimitiveTotalScore {

public:
	PrimitiveTotalScore(unsigned int hits, unsigned int attempts, std::string prefix);
	~PrimitiveTotalScore();
  
  bool operator<(const PrimitiveTotalScore& otherPrimitiveTotalScore) const;
  bool operator==(const PrimitiveTotalScore& otherPrimitiveTotalScore) const;
  bool operator>(const PrimitiveTotalScore& otherPrimitiveTotalScore) const;
  bool operator!=(const PrimitiveTotalScore& otherPrimitiveTotalScore) const;
  
  friend std::ostream& operator<<(std::ostream& os, const PrimitiveTotalScore& aPrimitiveTotalScore);
  void printOn(std::ostream&) const;
  
  unsigned int GetHits() const {return m_hits;};
  unsigned int GetAttempts() const {return m_attempts;};

private:
  std::string m_prefix;
  unsigned int m_hits;
  unsigned int m_attempts;
};

}

#endif // PRIMITIVETOTALSCORE_H
