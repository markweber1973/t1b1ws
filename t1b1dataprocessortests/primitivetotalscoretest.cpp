#include "../t1b1dataprocessor/primitivetotalscore.cpp"
#include <gtest/gtest.h>
#include <boost/scoped_ptr.hpp>

using namespace t1b1dataprocessor;


TEST(PrimitiveTotalScoreTest, Equal) 
{
  boost::scoped_ptr<PrimitiveTotalScore> oneScore(new PrimitiveTotalScore(1, 1, "B"));
  boost::scoped_ptr<PrimitiveTotalScore> twoScore(new PrimitiveTotalScore(1, 1, "B"));
  boost::scoped_ptr<PrimitiveTotalScore> threeScore(new PrimitiveTotalScore(0, 0, "B"));
  boost::scoped_ptr<PrimitiveTotalScore> fourScore(new PrimitiveTotalScore(0, 0, "B"));
  
  EXPECT_TRUE((*oneScore)   == (*twoScore));
  EXPECT_TRUE((*threeScore) == (*fourScore));
}

TEST(PrimitiveTotalScoreTest, Unequality) 
{
  boost::scoped_ptr<PrimitiveTotalScore> oneScore(new PrimitiveTotalScore(1, 1, "B"));
  boost::scoped_ptr<PrimitiveTotalScore> twoScore(new PrimitiveTotalScore(1, 1, "B"));
  boost::scoped_ptr<PrimitiveTotalScore> threeScore(new PrimitiveTotalScore(0, 0, "B"));
  boost::scoped_ptr<PrimitiveTotalScore> fourScore(new PrimitiveTotalScore(0, 0, "B"));
  
  EXPECT_FALSE((*oneScore)  != (*twoScore));
  EXPECT_TRUE((*threeScore)  != (*twoScore));
}

TEST(PrimitiveTotalScoreTest, SmallerThan) 
{
  boost::scoped_ptr<PrimitiveTotalScore> oneScore(new PrimitiveTotalScore(1, 1, "B"));
  boost::scoped_ptr<PrimitiveTotalScore> twoScore(new PrimitiveTotalScore(1, 1, "B"));
  boost::scoped_ptr<PrimitiveTotalScore> threeScore(new PrimitiveTotalScore(1, 2, "B"));
  boost::scoped_ptr<PrimitiveTotalScore> fourScore(new PrimitiveTotalScore(2, 3, "B"));
  
	EXPECT_FALSE((*oneScore)   < (*twoScore));          
	EXPECT_TRUE ((*threeScore) < (*twoScore));          
	EXPECT_TRUE ((*oneScore)   < (*fourScore));          
	EXPECT_FALSE((*fourScore)  < (*threeScore));          
	EXPECT_FALSE((*fourScore)  < (*oneScore));          
}

TEST(PrimitiveTotalScoreTest, InvalidConstruction) 
{
  ASSERT_THROW(boost::scoped_ptr<PrimitiveTotalScore> fiveScore(new PrimitiveTotalScore(5, 4, "B")), std::exception);  
}

TEST(PrimitiveTotalScoreTest, TestOutputOperator) 
{
  boost::scoped_ptr<PrimitiveTotalScore> bonusScore(new PrimitiveTotalScore(1, 1, "B"));
  boost::scoped_ptr<PrimitiveTotalScore> topScore(new PrimitiveTotalScore(2, 5, "T"));
  
  std::ostringstream stream;
  stream << *topScore << " " << *bonusScore;
  std::string str =  stream.str();
  EXPECT_TRUE(str.compare("2T5 1B1") == 0);
}