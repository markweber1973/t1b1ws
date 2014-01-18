#ifndef CLIMBER_H
#define CLIMBER_H

#include <string>

namespace t1b1dataprocessor
{

typedef enum Sex
{
	female,
	male,
	noinit
} Sex;
	
class Climber {

public:
  Climber(unsigned int climberId);
  ~Climber();
	
  bool operator==(const Climber& otherClimber) const;
  bool operator!=(const Climber& otherClimber) const;  
  bool operator<(const Climber& otherClimber) const;
  bool operator>(const Climber& otherClimber) const;
  friend std::ostream& operator<<(std::ostream& os, const Climber& aClimber);
  void printOn(std::ostream&) const;

  void SetFirstname(std::string name);
  std::string GetFirstname() const;	
  void SetLastname(std::string name);
  std::string GetLastname() const;	  
  void SetNationality(std::string nationality);
  std::string GetNationality() const;
  
  void SetSex(Sex sex);
  Sex GetSex() const;
private:

  unsigned int m_climberId;
  std::string m_firstname;
  std::string m_lastname; 
  std::string m_nationality; 
  Sex m_sex;
};

}

#endif // CLIMBER_H
