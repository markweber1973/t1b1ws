#include <enrolledclimber.h>

namespace t1b1dataprocessor
{

EnrolledClimber::EnrolledClimber(unsigned int startNumber, boost::shared_ptr<Climber> climber)
{
  m_startnumber = startNumber;
  m_climber = climber;
}

EnrolledClimber::~EnrolledClimber()
{
}

void EnrolledClimber::printOn(std::ostream& strm) const
{
	strm << "<enrolledclimber>" << std::endl;
	strm << "<startnumber>" << m_startnumber << "</startnumber>" << std::endl; 
  strm << *m_climber;
	strm << "</enrolledclimber>" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const EnrolledClimber& aClimber)
{
	aClimber.printOn(os);
  return os;
}

}

