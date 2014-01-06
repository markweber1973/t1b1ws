#ifndef SUBSCORE_H
#define SUBSCORE_H

namespace t1b1dataprocessor
{

class SubScore {

  public:

    SubScore() {m_hits=0;m_attempts=0;};
    ~SubScore() {};

    bool operator==(const SubScore& otherScore) const;
    bool operator!=(const SubScore& otherScore) const;  
    bool operator<(const SubScore& otherScore)  const;
    bool operator>(const SubScore& otherScore)  const;    
    bool operator<=(const SubScore& otherScore)  const;
    bool operator>=(const SubScore& otherScore)  const;    


    unsigned int GetHits()                      const {return m_hits;};
    unsigned int GetAttempts()                  const {return m_attempts;};
    unsigned int AddHit()                             {m_hits++;};
    unsigned int AddAttempts(unsigned int attempts)   {m_attempts+=attempts;};
    
  private:
    unsigned int m_hits;
    unsigned int m_attempts;
};

}

#endif // SUBSCORE_H
