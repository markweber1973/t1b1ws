#include "../t1b1dataprocessor/scorecard.cpp"
#include "../t1b1dataprocessor/climber.h"
#include <gtest/gtest.h>
#include <boost/scoped_ptr.hpp>

using namespace t1b1dataprocessor;


TEST(ScoreCardTest, SmallerThan) 
{
  boost::shared_ptr<Climber> oneClimber(new Climber(1));
  oneClimber->SetFirstname("Mark");
  oneClimber->SetLastname("Weber");
  oneClimber->SetSex(male);
  oneClimber->SetNationality("NED");
  boost::shared_ptr<EnrolledClimber> oneEnrolledClimber(new EnrolledClimber(10, oneClimber));
  boost::scoped_ptr<ScoreCard> oneScoreCard(new ScoreCard(oneEnrolledClimber));
  
  boost::shared_ptr<BoulderScore> oneBoulderScore(new BoulderScore(1, false));
  oneBoulderScore->BonusHit(1);
  oneBoulderScore->TopHit(1);
  oneScoreCard->AddScore(oneBoulderScore);

  boost::shared_ptr<BoulderScore> twoBoulderScore(new BoulderScore(2, false));
  twoBoulderScore->BonusHit(1);
  twoBoulderScore->TopHit(1);
  oneScoreCard->AddScore(twoBoulderScore);
  
 
  boost::shared_ptr<Climber> twoClimber(new Climber(2));
  twoClimber->SetFirstname("Piet");
  twoClimber->SetLastname("Snot");
  twoClimber->SetSex(male);
  twoClimber->SetNationality("NED");
  boost::shared_ptr<EnrolledClimber> twoEnrolledClimber(new EnrolledClimber(10, twoClimber));
  boost::scoped_ptr<ScoreCard> twoScoreCard(new ScoreCard(twoEnrolledClimber));
  
  boost::shared_ptr<BoulderScore> threeBoulderScore(new BoulderScore(1, false));
  threeBoulderScore->BonusHit(2);
  threeBoulderScore->TopHit(2);
  twoScoreCard->AddScore(threeBoulderScore);

  boost::shared_ptr<BoulderScore> fourBoulderScore(new BoulderScore(2, false));
  fourBoulderScore->BonusHit(2);
  fourBoulderScore->TopHit(2);
  twoScoreCard->AddScore(fourBoulderScore);

  EXPECT_TRUE(*twoScoreCard < *oneScoreCard);
}


TEST(ScoreCardTest, PolePosition) 
{
  boost::shared_ptr<Climber> oneClimber(new Climber(4));
  oneClimber->SetFirstname("Mark");
  oneClimber->SetLastname("Weber");
  oneClimber->SetSex(male);
  oneClimber->SetNationality("NED");
  boost::shared_ptr<EnrolledClimber> oneEnrolledClimber(new EnrolledClimber(10, oneClimber));
  boost::scoped_ptr<ScoreCard> oneScoreCard(new ScoreCard(oneEnrolledClimber, 2, 1));
  EXPECT_TRUE(oneScoreCard->IsEmpty());

  boost::shared_ptr<BoulderScore> oneBoulderScore(new BoulderScore(1, true));
  oneBoulderScore->BonusHit(1);
  oneBoulderScore->TopHit(1);
  oneScoreCard->AddScore(oneBoulderScore);
  EXPECT_FALSE(oneScoreCard->IsEmpty());
  
  boost::shared_ptr<BoulderScore> twoBoulderScore(new BoulderScore(2, false));
  twoBoulderScore->BonusHit(1);
  twoBoulderScore->TopHit(1);
  oneScoreCard->AddScore(twoBoulderScore);
  EXPECT_FALSE(oneScoreCard->IsFinished());
 
  boost::shared_ptr<Climber> twoClimber(new Climber(5));
  twoClimber->SetFirstname("Piet");
  twoClimber->SetLastname("Snot");
  twoClimber->SetSex(male);
  twoClimber->SetNationality("NED");
  boost::shared_ptr<EnrolledClimber> twoEnrolledClimber(new EnrolledClimber(10, twoClimber));
  boost::scoped_ptr<ScoreCard> twoScoreCard(new ScoreCard(twoEnrolledClimber, 2, 2));
  
  boost::shared_ptr<BoulderScore> threeBoulderScore(new BoulderScore(1, true));
  threeBoulderScore->BonusHit(1);
  threeBoulderScore->TopHit(1);
  twoScoreCard->AddScore(threeBoulderScore);

  boost::shared_ptr<BoulderScore> fourBoulderScore(new BoulderScore(2, true));
  fourBoulderScore->BonusHit(1);
  fourBoulderScore->TopHit(1);
  twoScoreCard->AddScore(fourBoulderScore);
  EXPECT_TRUE(twoScoreCard->IsFinished());
  EXPECT_TRUE(*twoScoreCard < *oneScoreCard);
}

