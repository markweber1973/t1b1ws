#include "../t1b1dataprocessor/totalscore.cpp"
#include <gtest/gtest.h>
#include <boost/scoped_ptr.hpp>

using namespace t1b1dataprocessor;


TEST(TotalScoreTest, ValidAllConstructions) 
{
  unsigned int tops = 0;
  unsigned int topAttempts = 0;
  unsigned int bonusses = 0;
  unsigned int bonusAttempts = 0;
  
  for (tops = 0; tops <= 5; tops++)
  {
    for (topAttempts = 0; topAttempts <= 5; topAttempts++)
    {
      for (bonusses = 0; bonusses <= 5; bonusses++)
      {
        for (bonusAttempts = 0; bonusAttempts <= 5; bonusAttempts++)
        {
          if ((tops > topAttempts) || 
              (bonusses > bonusAttempts) || 
              (tops > bonusses) || 
              ((tops == bonusses) && (bonusAttempts > topAttempts)))
          {
            ASSERT_THROW(boost::scoped_ptr<TotalScore> oneScore(new TotalScore(tops,topAttempts,bonusses,bonusAttempts)), std::exception); 
          }
          else
          {
            ASSERT_NO_THROW(boost::scoped_ptr<TotalScore> oneScore(new TotalScore(tops,topAttempts,bonusses,bonusAttempts))); 
          }
        }
      }    
    }
  } 
}
