/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <gtest/gtest.h>
#include <databaseconnector.h>
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/thread/thread.hpp> 
#include <boost/lexical_cast.hpp>
#include <unistd.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <climber.h>
#include <score.h>
#include <phase.h>
#include <event.h>
#include <round.h>
#include <boulderscore.h>
#include <enrolledclimber.h>
#include <scorecard.h>
using namespace std;
using namespace t1b1dataprocessor;

typedef std::map <unsigned int, boost::shared_ptr<Round> > RoundMap;		
typedef std::pair<unsigned int, boost::shared_ptr<Round> > RoundPair;	
RoundMap roundMap;

typedef std::map <unsigned int, boost::shared_ptr<Round> > PhaseMap;		
typedef std::pair<unsigned int, boost::shared_ptr<Round> > PhasePair;	
PhaseMap phaseMap;

typedef std::map <unsigned int, RoundMap > PhaseRoundMap;		
typedef std::pair<unsigned int, RoundMap > PhaseRoundPair;	
PhaseRoundMap phaseRoundMap;

std::string GetWStringFromResultSet(sql::ResultSet* res, std::string fieldName)
{
	sql::SQLString sqlString;
	sqlString = res->getString(fieldName);
	
	std::ostringstream stringStreamBuf;
	stringStreamBuf << sqlString;
	return (stringStreamBuf.str());	
}

unsigned int GetUnsignedIntFromResultSet(sql::ResultSet* res, std::string fieldName)
{
	sql::SQLString sqlString;
	sqlString = res->getString(fieldName);
	
	std::ostringstream stringStreamBuf;
	stringStreamBuf << sqlString;
  unsigned int retVal = 0;
  try 
  {
    retVal = boost::lexical_cast<unsigned int>(stringStreamBuf.str());
  } 
  catch( boost::bad_lexical_cast const& ) 
  {
    std::cout << "Error: input string was not valid" << std::endl;
  }
	return (retVal);	
}


typedef boost::shared_ptr<Climber> Climber_ptr;
boost::shared_ptr<t1b1dataprocessor::databaseconnector> dbconnector(new databaseconnector);

std::string DetermineActivePhase()
{
  std::ostringstream oss;  
  std::string tmp;  
  oss<<"SELECT * FROM activephase";

  sql::ResultSet *resultSet;
  resultSet = dbconnector->executeQuery(oss.str());
  tmp = oss.str();
  resultSet->next();
  return (GetWStringFromResultSet(resultSet,"phaseId"));
}

std::string DetermineActiveEvent()
{
  std::ostringstream oss;  
  std::string tmp;
  oss<<"SELECT * FROM activeevent";

  sql::ResultSet *resultSet;
  resultSet = dbconnector->executeQuery(oss.str());
  tmp = oss.str();
  resultSet->next();
  return (GetWStringFromResultSet(resultSet,"eventId"));
}
  
  
std::string DetermineRoundName(std::string roundId)  
{  
  std::ostringstream oss;  
  std::string tmp;
  
  oss<<"SELECT * FROM rounds R WHERE (R.`roundId`='"<<roundId<<"')"; 

  sql::ResultSet *resultSet;
  resultSet = dbconnector->executeQuery(oss.str());
  tmp = oss.str();
  resultSet->next();
  return (GetWStringFromResultSet(resultSet,"name")); 
}

std::string DeterminePhaseName(std::string phaseId)  
{  
  std::ostringstream oss;  
  std::string tmp;
  
  oss<<"SELECT * FROM phases P WHERE (P.`phaseId`='"<<phaseId<<"')"; 

  sql::ResultSet *resultSet;
  resultSet = dbconnector->executeQuery(oss.str());
  tmp = oss.str(); 
  resultSet->next();
  return (GetWStringFromResultSet(resultSet,"name")); 
}
  
void DetermineActiveRounds()
{
  std::ostringstream oss;  
  std::string tmp;
  
  std::string activeEventId = DetermineActiveEvent();
  std::string activePhaseId = DetermineActivePhase();
  
  oss<<"SELECT * FROM roundphaseenrollment RE WHERE (RE.`eventId`='";
  oss<<activeEventId<<"' AND RE.`phaseId`='"<<activePhaseId<<"')";  
  
  sql::ResultSet *resultSet;
  resultSet = dbconnector->executeQuery(oss.str());
  tmp = oss.str();
  
  while (resultSet->next())  
  {
    std::string roundId = GetWStringFromResultSet(resultSet, "roundId");
    std::string roundName = DetermineRoundName(roundId);
    unsigned int iRoundId = 0;
    try 
    {
      iRoundId = boost::lexical_cast<unsigned int>(roundId);
      unsigned int nrOfBoulders = GetUnsignedIntFromResultSet(resultSet,"nrofboulders");
      unsigned int sequence = GetUnsignedIntFromResultSet(resultSet,"sequence");
      unsigned int roundId = GetUnsignedIntFromResultSet(resultSet,"roundId");      
      
      boost::shared_ptr<Round> localRound (new Round(roundName, sequence, nrOfBoulders, roundId));
      roundMap[iRoundId] = localRound;
    } 
    catch( boost::bad_lexical_cast const& ) 
    {
      std::cout << "Error: input string was not valid" << std::endl;
    }    
    
  }
}  

std::string DetermineRoundId(std::string eventId, std::string phaseId, std::string startNumber, unsigned int& polePosition)
{
  std::ostringstream oss;  
  std::string tmp;
  oss<<"SELECT * FROM roundenrollment RE WHERE (RE.`eventId`='";
  oss<<eventId<<"' AND RE.`phaseId`='"<<phaseId<<"' AND RE.`startNumber`='"<<startNumber<<"')";  
  sql::ResultSet *roundIdResultSet;
  roundIdResultSet = dbconnector->executeQuery(oss.str());
  tmp = oss.str();
  roundIdResultSet->next();
  polePosition = GetUnsignedIntFromResultSet(roundIdResultSet,"polePosition");
  return (GetWStringFromResultSet(roundIdResultSet,"roundId"));
}

void CreateAllPhases(std::string eventId)
{
  std::ostringstream oss;  
  std::string tmp;
  oss<<"SELECT * FROM eventphaseenrollment RE WHERE (RE.`eventId`='"<<eventId<<"')";

  sql::ResultSet *resultset;
  resultset = dbconnector->executeQuery(oss.str());

  while (resultset->next()) 
  {
    std::string phaseId = GetWStringFromResultSet(resultset, "phaseId");
    std::string phaseName = GetWStringFromResultSet(resultset, "phaseId");
  //  boost::shared_ptr<Phase> localPhase(new Phase())


//  Phase(std::string name, unsigned int sequence, unsigned int phaseId);
    
  }  
}

int main(int argc, char **argv) 
{
  unsigned int activeEventId;
  try
  {
    activeEventId = boost::lexical_cast<unsigned int>(DetermineActiveEvent());
  }
  catch (...)
  {
    
  }
  
  Event localEvent("Boulder1", activeEventId);
  sql::ResultSet *res;
  res = dbconnector->executeQuery("SELECT RPE.roundId, R.name, EER.startNumber, C.climberId, C.lastname, C.firstname, C.nationality, RE.poleposition FROM roundphaseenrollment RPE JOIN rounds R ON (RPE.eventId='7' AND RPE.phaseId='3'AND RPE.roundId=R.roundId) JOIN roundenrollment RE ON RE.roundId=RPE.roundId JOIN eventenrollment EER ON EER.startNumber=RE.startNumber JOIN climbers C on EER.climberId=C.climberId");  
  
  std::vector<Climber_ptr> climberList;
  ofstream myfile;
  myfile.open ("climbers.xml");
  myfile << "<scoredata>" << std::endl;

  DetermineActiveRounds(); 
 
  while (res->next()) 
  {
    unsigned int climberId = GetUnsignedIntFromResultSet(res, "climberId");    
    boost::shared_ptr<Climber> localClimber( new Climber(climberId));
    localClimber->SetFirstname(GetWStringFromResultSet(res, "firstname"));
    localClimber->SetLastname(GetWStringFromResultSet(res, "lastname"));
    localClimber->SetNationality(GetWStringFromResultSet(res, "nationality"));
    
    std::string roundId;
    std::string startNumber;
    startNumber = GetWStringFromResultSet(res, "startnumber");
    unsigned int polePosition = 0;
    roundId = DetermineRoundId("7","3",startNumber, polePosition);   
    unsigned int iRoundId = 0;
    try 
    {
      iRoundId = boost::lexical_cast<unsigned int>(roundId);
    } 
    catch( boost::bad_lexical_cast const& )
    {
      std::cout << "Error: input string was not valid" << std::endl;
    }
    
    boost::shared_ptr<EnrolledClimber> enrolledClimber(new EnrolledClimber(res->getInt("startnumber"), localClimber));    
    boost::shared_ptr<ScoreCard> localScoreCard( new ScoreCard(enrolledClimber, roundMap[iRoundId]->GetNrOfBoulders(), polePosition));

    sql::ResultSet* scoreResultSet;
    std::ostringstream oss;  
    oss << "SELECT S.finished, S.topped, S.topAttempts, S.bonussed, S.bonusAttempts, S.boulderNumber ";
    oss << "FROM scores S WHERE (S.eventId='7' AND S.phaseId='3' AND S.roundId='"<<roundId<<"' AND S.startNumber='"<<startNumber;
    oss << "')";

    std::string scoreQuery = oss.str();
    scoreResultSet = dbconnector->executeQuery(scoreQuery);      
    while (scoreResultSet->next()) 
    {
      unsigned int boulderNumber = scoreResultSet->getInt("boulderNumber");

      bool finished = scoreResultSet->getInt("finished") == 1;
      boost::shared_ptr<BoulderScore> localScore (new BoulderScore( boulderNumber, finished));

      unsigned int bonussed = scoreResultSet->getInt("bonussed");
      unsigned int bonusAttempts = scoreResultSet->getInt("bonusAttempts");
      if (bonussed) localScore->BonusHit(bonusAttempts);      
      
      unsigned int topped = scoreResultSet->getInt("topped");
      unsigned int topAttempts = scoreResultSet->getInt("topAttempts");
      if (topped) localScore->TopHit(topAttempts);
      localScoreCard->AddScore(localScore);
    }
    boost::shared_ptr<Round> tmpRound = roundMap.at(iRoundId);
    tmpRound->AddScoreCard(localScoreCard);
  }
  

  boost::shared_ptr<Phase> localPhase (new Phase("Finale", 1, 1));
  
  BOOST_FOREACH(RoundPair roundPair, roundMap)
  {
    localPhase->AddRound(roundPair.second);
  }
  localEvent.AddPhase(localPhase);
  myfile << localEvent;
  
	myfile << "</scoredata>" << std::endl;
  myfile.close();
  
  return 0;
}

