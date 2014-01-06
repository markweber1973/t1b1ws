#include "../t1b1dataprocessor/subscore.cpp"
#include <gtest/gtest.h>

#include <boost/shared_ptr.hpp>

using namespace t1b1dataprocessor;


TEST(SubScoreTest, Equality) 
{
  boost::shared_ptr<SubScore> oneScore(new SubScore());
  boost::shared_ptr<SubScore> twoScore(new SubScore());

	EXPECT_TRUE((*oneScore)   == (*twoScore));          
  
  oneScore->AddHit();
  oneScore->AddAttempts(5);

  twoScore->AddHit();
  twoScore->AddAttempts(5);

	EXPECT_TRUE((*oneScore)   == (*twoScore));          
	EXPECT_FALSE((*oneScore)  != (*twoScore));          
	EXPECT_FALSE((*oneScore)  < (*twoScore));          
	EXPECT_FALSE((*oneScore)  > (*twoScore));            
	EXPECT_TRUE((*oneScore)  <= (*twoScore));          
	EXPECT_TRUE((*oneScore)  >= (*twoScore));            
  
  twoScore->AddAttempts(1);
	EXPECT_FALSE((*oneScore)   == (*twoScore));          
	EXPECT_TRUE((*oneScore)  != (*twoScore));          
	EXPECT_FALSE((*oneScore)  < (*twoScore));          
	EXPECT_TRUE((*oneScore)  > (*twoScore));            
	EXPECT_FALSE((*oneScore)  <= (*twoScore));          
	EXPECT_TRUE((*oneScore)  >= (*twoScore));            

  oneScore->AddAttempts(1);  
	EXPECT_TRUE((*oneScore)   == (*twoScore));          
	EXPECT_FALSE((*oneScore)  != (*twoScore));          
	EXPECT_FALSE((*oneScore)  < (*twoScore));          
	EXPECT_FALSE((*oneScore)  > (*twoScore));            
	EXPECT_TRUE((*oneScore)  <= (*twoScore));          
	EXPECT_TRUE((*oneScore)  >= (*twoScore));            

  twoScore->AddHit();
	EXPECT_FALSE((*oneScore)   == (*twoScore));          
	EXPECT_TRUE((*oneScore)  != (*twoScore));          
	EXPECT_TRUE((*oneScore)  < (*twoScore));          
	EXPECT_FALSE((*oneScore)  > (*twoScore));            
	EXPECT_TRUE((*oneScore)  <= (*twoScore));          
	EXPECT_FALSE((*oneScore)  >= (*twoScore));            

  twoScore->AddAttempts(5);
	EXPECT_FALSE((*oneScore)   == (*twoScore));          
	EXPECT_TRUE((*oneScore)  != (*twoScore));          
	EXPECT_TRUE((*oneScore)  < (*twoScore));          
	EXPECT_FALSE((*oneScore)  > (*twoScore));            
	EXPECT_TRUE((*oneScore)  <= (*twoScore));          
	EXPECT_FALSE((*oneScore)  >= (*twoScore));            

}

TEST(SubScoreTest, Larger) {

	SubScore* oneScore = new SubScore();	
	SubScore* twoScore = new SubScore();	  

  oneScore->AddHit();
  oneScore->AddAttempts(5);

  twoScore->AddHit();
  twoScore->AddAttempts(5);

	EXPECT_TRUE((*oneScore)   == (*twoScore));          
	EXPECT_FALSE((*oneScore)  != (*twoScore));          
	EXPECT_FALSE((*oneScore)  < (*twoScore));          
	EXPECT_FALSE((*oneScore)  > (*twoScore));            
	EXPECT_TRUE((*oneScore)  <= (*twoScore));          
	EXPECT_TRUE((*oneScore)  >= (*twoScore));            
  
  twoScore->AddAttempts(1);
	EXPECT_FALSE((*oneScore)   == (*twoScore));          
	EXPECT_TRUE((*oneScore)  != (*twoScore));          
	EXPECT_FALSE((*oneScore)  < (*twoScore));          
	EXPECT_TRUE((*oneScore)  > (*twoScore));            
	EXPECT_FALSE((*oneScore)  <= (*twoScore));          
	EXPECT_TRUE((*oneScore)  >= (*twoScore));            

  oneScore->AddAttempts(1);  
	EXPECT_TRUE((*oneScore)   == (*twoScore));          
	EXPECT_FALSE((*oneScore)  != (*twoScore));          
	EXPECT_FALSE((*oneScore)  < (*twoScore));          
	EXPECT_FALSE((*oneScore)  > (*twoScore));            
	EXPECT_TRUE((*oneScore)  <= (*twoScore));          
	EXPECT_TRUE((*oneScore)  >= (*twoScore));            

  twoScore->AddHit();
	EXPECT_FALSE((*oneScore)   == (*twoScore));          
	EXPECT_TRUE((*oneScore)  != (*twoScore));          
	EXPECT_TRUE((*oneScore)  < (*twoScore));          
	EXPECT_FALSE((*oneScore)  > (*twoScore));            
	EXPECT_TRUE((*oneScore)  <= (*twoScore));          
	EXPECT_FALSE((*oneScore)  >= (*twoScore));            

  twoScore->AddAttempts(5);
	EXPECT_FALSE((*oneScore)   == (*twoScore));          
	EXPECT_TRUE((*oneScore)  != (*twoScore));          
	EXPECT_TRUE((*oneScore)  < (*twoScore));          
	EXPECT_FALSE((*oneScore)  > (*twoScore));            
	EXPECT_TRUE((*oneScore)  <= (*twoScore));          
	EXPECT_FALSE((*oneScore)  >= (*twoScore));            

}
