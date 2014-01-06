#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <boost/shared_ptr.hpp>

class Climber;

namespace t1b1dataprocessor
{

class Enrollment {

public:
  Enrollment(unsigned int startnumber, boost::shared_ptr<Climber> climber);
  ~Enrollment();
private:
  boost::shared_ptr<Climber> m_climber;
  unsigned int m_startnumber;

};

}

#endif // ENROLLMENT_H
