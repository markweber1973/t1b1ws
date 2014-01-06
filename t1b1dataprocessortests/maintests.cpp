// tests.cpp
#include "../t1b1dataprocessor/climber.cpp"


#include "../t1b1dataprocessor/enrolledclimber.cpp"



#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

using namespace t1b1dataprocessor;

TEST(ClimberTest, FirstName) {
	std::string testName = "piet";	
	Climber* testClimber = new Climber();	
	testClimber->SetFirstname(testName);
	ASSERT_EQ(testName.compare(testClimber->GetFirstname()), 0);
}

TEST(ClimberTest, Sex) {
	Climber* testClimber = new Climber();	
	testClimber->SetSex(female);
	EXPECT_TRUE(testClimber->GetSex() == female);
	EXPECT_FALSE(testClimber->GetSex() == male);	
}

TEST(ClimberTest, LastName) {
	std::string testName = "piet";
	Climber* testClimber = new Climber();	
	testClimber->SetLastname(testName);
	ASSERT_EQ(testName.compare(testClimber->GetLastname()), 0);
}

TEST(ClimberTest, Nationality) {
	std::string testString = "NED";
	Climber* testClimber = new Climber();	
	testClimber->SetNationality(testString);
	ASSERT_EQ(testString.compare(testClimber->GetNationality()), 0);
}

TEST(ClimberTest, IsEqualOperators) {
    boost::shared_ptr<Climber> oneClimber(new Climber);
    boost::shared_ptr<Climber> twoClimber(new Climber);	
    boost::shared_ptr<Climber> threeClimber(new Climber);

	oneClimber->SetFirstname("Piet");
	twoClimber->SetFirstname("piet");
	threeClimber->SetFirstname("appie");
	
	EXPECT_TRUE((*oneClimber) == (*twoClimber));
	EXPECT_TRUE((*oneClimber) != (*threeClimber));	
}

TEST(ClimberTest, SmallerOperator) {
    boost::shared_ptr<Climber> oneClimber(new Climber);
    boost::shared_ptr<Climber> twoClimber(new Climber);	

	oneClimber->SetFirstname("aaa");
	oneClimber->SetLastname("aaa");
	
	twoClimber->SetFirstname("bbb");	
	twoClimber->SetLastname("AAA");
	
	EXPECT_TRUE((*oneClimber) < (*twoClimber));
	EXPECT_FALSE((*oneClimber) == (*twoClimber));
	
	oneClimber->SetLastname("Ccc");
	
	EXPECT_FALSE((*oneClimber) < (*twoClimber));
	
	twoClimber->SetFirstname("aaa");	
	EXPECT_TRUE((*oneClimber) != (*twoClimber));
	
}

TEST(ClimberTest, LargerOperator) {
    boost::shared_ptr<Climber> oneClimber(new Climber);
    boost::shared_ptr<Climber> twoClimber(new Climber);	

	oneClimber->SetFirstname("aaa");
	oneClimber->SetLastname("aaa");
	
	twoClimber->SetFirstname("bbb");	
	twoClimber->SetLastname("AAA");
	
	EXPECT_FALSE((*oneClimber) == (*twoClimber));
	EXPECT_FALSE((*oneClimber) == (*twoClimber));
	oneClimber->SetLastname("Ccc");
	
	EXPECT_TRUE((*oneClimber) > (*twoClimber));
	
	twoClimber->SetFirstname("aaa");	
	EXPECT_TRUE((*oneClimber) != (*twoClimber));
	
}





int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


