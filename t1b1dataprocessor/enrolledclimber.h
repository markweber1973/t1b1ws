#ifndef ENROLLEDCLIMBER_H
#define ENROLLEDCLIMBER_H

#include <boost/shared_ptr.hpp>
#include <climber.h>

namespace t1b1dataprocessor
{

class EnrolledClimber {

public:
	EnrolledClimber(unsigned int startNumber, boost::shared_ptr<Climber> climber);
	~EnrolledClimber();
  
  friend std::ostream& operator<<(std::ostream& os, const EnrolledClimber& aClimber);
  void printOn(std::ostream&) const;
  
private:
  boost::shared_ptr<Climber> m_climber;
  unsigned int m_startnumber;
};

}

#endif // ENROLLEDCLIMBER_H
