#include "../t1b1dataprocessor/primitivescore.cpp"
#include <gtest/gtest.h>
#include <boost/scoped_ptr.hpp>

using namespace t1b1dataprocessor;


TEST(PrimitiveScoreTest, SmallerThan) 
{
  boost::scoped_ptr<PrimitiveScore> oneScore(new PrimitiveScore(true, 1, "B"));
  boost::scoped_ptr<PrimitiveScore> twoScore(new PrimitiveScore(true, 1, "B"));
  boost::scoped_ptr<PrimitiveScore> threeScore(new PrimitiveScore(true, 2, "B"));
  boost::scoped_ptr<PrimitiveScore> fourScore(new PrimitiveScore(false, 0, "B"));
  
	EXPECT_FALSE((*oneScore)  < (*twoScore));          
	EXPECT_TRUE((*threeScore)  < (*twoScore));          
	EXPECT_FALSE((*oneScore)  < (*threeScore));          
	EXPECT_TRUE((*fourScore)  < (*threeScore));          
	EXPECT_TRUE((*fourScore)  < (*oneScore));          
}

TEST(PrimitiveScoreTest, InvalidConstruction) 
{
  ASSERT_THROW(boost::scoped_ptr<PrimitiveScore> fiveScore(new PrimitiveScore(false, 10, "B")), std::exception);  
}

TEST(PrimitiveScoreTest, TestOutputOperator) 
{
  boost::scoped_ptr<PrimitiveScore> oneScore(new PrimitiveScore(true, 1, "B"));
  boost::scoped_ptr<PrimitiveScore> twoScore(new PrimitiveScore(false, 0, "T"));
  
  std::ostringstream stream;
  stream << *twoScore << *oneScore;
  std::string str =  stream.str();
  str.compare("B1");
  EXPECT_TRUE(str.compare("T-B1") == 0);
}