#include "../t1b1dataprocessor/scorecard.cpp"
#include "../t1b1dataprocessor/climber.h"
#include <gtest/gtest.h>
#include <boost/scoped_ptr.hpp>

using namespace t1b1dataprocessor;


TEST(ScoreCardTest, SmallerThan) 
{
  boost::shared_ptr<Climber> oneClimber(new Climber());
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
  
 
  boost::shared_ptr<Climber> twoClimber(new Climber());
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

