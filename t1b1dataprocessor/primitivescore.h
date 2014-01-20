#ifndef PRIMITIVESCORE_H
#define PRIMITIVESCORE_H

#include <string>

namespace t1b1dataprocessor
{

class PrimitiveScore {

public:
	PrimitiveScore(bool hit, unsigned int attempts, std::string prefix);
	~PrimitiveScore();
  
  bool operator<(const PrimitiveScore& otherPrimitiveScore) const;
  bool operator==(const PrimitiveScore& otherPrimitiveScore) const;
  
  friend std::ostream& operator<<(std::ostream& os, const PrimitiveScore& aPrimitiveScore);
  void printOn(std::ostream&) const;
  
  bool IsHit() const {return m_hit;};
  unsigned int GetAttempts() const {return m_attempts;};
  bool SetFinished() {m_finished = true;}

private:
  std::string m_prefix;
  bool m_hit;
  unsigned int m_attempts;
  bool m_finished;
};

}

#endif // PRIMITIVESCORE_H
