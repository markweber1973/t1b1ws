#include <climber.h> 
#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>

namespace t1b1dataprocessor
{

Climber::Climber()
{
	m_firstname = "noinit";
	m_lastname  = "noinit";
	m_sex = noinit;
	m_nationality = "noinit";
}

Climber::~Climber()
{
}

bool Climber::operator==(const Climber& otherClimber) const
{
	std::string thisFirstName ;
	boost::to_upper(thisFirstName.assign(m_firstname));
	std::string thisLastName ;
	boost::to_upper(thisLastName.assign(m_lastname));		
	std::string otherFirstName ;
	boost::to_upper(otherFirstName.assign(otherClimber.GetFirstname()));
	std::string otherLastName ;
	boost::to_upper(otherLastName.assign(otherClimber.GetLastname()));	
	return ((thisFirstName.compare(otherFirstName) == 0) && (thisLastName.compare(otherLastName) == 0));
}

bool Climber::operator!=(const Climber& otherClimber) const
{
	return !(*this == otherClimber);
}

bool Climber::operator<(const Climber& otherClimber) const
{
	std::string thisFirstName ;
	boost::to_upper(thisFirstName.assign(m_firstname));
	std::string thisLastName ;
	boost::to_upper(thisLastName.assign(m_lastname));		
	std::string otherFirstName ;
	boost::to_upper(otherFirstName.assign(otherClimber.GetFirstname()));
	std::string otherLastName ;
	boost::to_upper(otherLastName.assign(otherClimber.GetLastname()));	
	
	if (thisLastName.compare(otherLastName) == 0) return (thisFirstName.compare(otherFirstName) < 0);
	else return (thisLastName.compare(otherLastName) < 0);
}

bool Climber::operator>(const Climber& otherClimber) const
{
	std::string thisFirstName ;
	boost::to_upper(thisFirstName.assign(m_firstname));
	std::string thisLastName ;
	boost::to_upper(thisLastName.assign(m_lastname));		
	std::string otherFirstName ;
	boost::to_upper(otherFirstName.assign(otherClimber.GetFirstname()));
	std::string otherLastName ;
	boost::to_upper(otherLastName.assign(otherClimber.GetLastname()));
	
	if (thisLastName.compare(otherLastName) == 0) return (thisFirstName.compare(otherFirstName) > 0);
	else return (thisLastName.compare(otherLastName) > 0);
}

void Climber::printOn(std::ostream& strm) const
{
	strm << "<climber>" << std::endl;
	strm << "<firstname>"   << m_firstname.c_str()   << "</firstname>"   << std::endl;
	strm << "<lastname>"    << m_lastname.c_str()    << "</lastname>"    << std::endl;
	strm << "<nationality>" << m_nationality.c_str() << "</nationality>" << std::endl;
	strm << "<sex>";
	if (m_sex == female) {strm << "F";} else if (m_sex == male) {strm << "M";} else {strm << "noinit";};	
	strm << "</sex>"     << std::endl;	
	strm << "</climber>" << std::endl;	
}

std::ostream& operator<<(std::ostream& os, const Climber& aClimber)
{
	aClimber.printOn(os);
    return os;
}

void Climber::SetFirstname(std::string name)
{
	m_firstname.assign(name);
}

std::string Climber::GetFirstname() const
{
	return m_firstname;
}

void Climber::SetLastname(std::string name)
{
	m_lastname.assign(name);
}

std::string Climber::GetLastname() const
{
	return m_lastname;
}

void Climber::SetNationality(std::string nationality)
{
	m_nationality.assign(nationality);
}

std::string Climber::GetNationality() const
{
	return m_nationality;
}

Sex Climber::GetSex() const
{
	return m_sex;
}

void Climber::SetSex(Sex sex)
{
	m_sex = sex;
}
}

