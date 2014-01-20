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


TEST(PrimitiveScoreTest, Equality) 
{
  boost::scoped_ptr<PrimitiveScore> oneScore(new PrimitiveScore(true, 1, "B"));
  boost::scoped_ptr<PrimitiveScore> twoScore(new PrimitiveScore(true, 1, "B"));
  boost::scoped_ptr<PrimitiveScore> threeScore(new PrimitiveScore(false, 0, "B"));
  boost::scoped_ptr<PrimitiveScore> fourScore(new PrimitiveScore(false, 0, "B"));
  
  EXPECT_TRUE((*oneScore)  == (*twoScore));
  EXPECT_TRUE((*threeScore)  == (*fourScore));
}

TEST(PrimitiveScoreTest, InvalidConstruction) 
{
  ASSERT_THROW(boost::scoped_ptr<PrimitiveScore> fiveScore(new PrimitiveScore(false, 10, "B")), std::exception);  
}

TEST(PrimitiveScoreTest, TestOutputOperatorNotFinished) 
{
  boost::scoped_ptr<PrimitiveScore> oneScore(new PrimitiveScore(true, 1, "B"));
  boost::scoped_ptr<PrimitiveScore> twoScore(new PrimitiveScore(false, 0, "T"));
  oneScore->SetFinished();  
  twoScore->SetFinished();  
  std::ostringstream stream;
  stream << *twoScore << *oneScore;
  std::string str =  stream.str();
  EXPECT_TRUE(str.compare("T-B1") == 0);
}

TEST(PrimitiveScoreTest, TestOutputOperatorFinished) 
{
  boost::scoped_ptr<PrimitiveScore> oneScore(new PrimitiveScore(false, 0, "B"));
  boost::scoped_ptr<PrimitiveScore> twoScore(new PrimitiveScore(false, 0, "T"));

  std::ostringstream stream;
  stream << *twoScore << *oneScore;
  std::string str =  stream.str();  
  cout << str << std::endl;  
  EXPECT_TRUE(str.compare("    ") == 0);
}