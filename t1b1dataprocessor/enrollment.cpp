#include <enrollment.h>

namespace t1b1dataprocessor
{

Enrollment::Enrollment(unsigned int startnumber, boost::shared_ptr<Climber> climber)
{
	m_startnumber = startnumber;
	m_climber = climber;
}

Enrollment::~Enrollment()
{
}

}

