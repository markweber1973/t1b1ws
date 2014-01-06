#include "../t1b1dataprocessor/boulderscore.cpp"
#include <gtest/gtest.h>
#include <boost/scoped_ptr.hpp>

using namespace t1b1dataprocessor;

TEST(BoulderScoreTest, Construction) 
{
  ASSERT_NO_THROW(boost::scoped_ptr<BoulderScore> oneScore(new BoulderScore(1, false)));  
}

TEST(BoulderScoreTest, TopHitInvalid) 
{
  boost::scoped_ptr<BoulderScore> oneScore(new BoulderScore(1, false));
  ASSERT_THROW(oneScore->TopHit(0), std::exception);  
}

TEST(BoulderScoreTest, BonusHitInvalid) 
{
  boost::scoped_ptr<BoulderScore> oneScore(new BoulderScore(1, false));
  ASSERT_THROW(oneScore->BonusHit(0), std::exception);  
}

TEST(BoulderScoreTest, TopHitValid) 
{
  boost::scoped_ptr<BoulderScore> oneScore(new BoulderScore(1, false));
  oneScore->BonusHit(1);
  ASSERT_NO_THROW(oneScore->TopHit(1));  
}

TEST(BoulderScoreTest, TopHitWithoutBonus) 
{
  boost::scoped_ptr<BoulderScore> oneScore(new BoulderScore(1, false));
  ASSERT_THROW(oneScore->TopHit(1), std::exception);  
}

TEST(BoulderScoreTest, BonusHitValid) 
{
  boost::scoped_ptr<BoulderScore> oneScore(new BoulderScore(1, false));
  ASSERT_NO_THROW(oneScore->BonusHit(3));  
}

TEST(BoulderScoreTest, BonusHitGetters)
{
  boost::scoped_ptr<BoulderScore> oneScore(new BoulderScore(1, false));
  oneScore->BonusHit(5);
  EXPECT_FALSE(oneScore->IsTopHit());
  EXPECT_TRUE(oneScore->IsBonusHit());  
  EXPECT_TRUE(oneScore->GetBonusAttempts()==5);    
}

TEST(BoulderScoreTest, TopHitGetters)
{
  boost::scoped_ptr<BoulderScore> oneScore(new BoulderScore(1, false));
  oneScore->BonusHit(5);
  oneScore->TopHit(10);  
  EXPECT_TRUE(oneScore->IsTopHit());
  EXPECT_TRUE(oneScore->IsBonusHit());
  EXPECT_TRUE(oneScore->GetBonusAttempts()==5);
  EXPECT_TRUE(oneScore->GetTopAttempts()==10);
}

