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
  try
  {
    sql::SQLString sqlString;
    sqlString = res->getString(fieldName);
 //   cout << fieldName<< std::endl;
    std::ostringstream stringStreamBuf;
    stringStreamBuf << sqlString;
    return (stringStreamBuf.str());	    
  }
  catch (...)
  {
    int x = 0;
  }

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

void CreateAllPhasesInEvent(Event& event)
{
  std::ostringstream oss;  
  oss<<"SELECT * FROM eventphaseenrollment RE WHERE (RE.`eventId`='"<<event.GetEventId()<<"')";

  sql::ResultSet *phasesResultset;
  phasesResultset = dbconnector->executeQuery(oss.str());

  while (phasesResultset->next()) 
  {
    std::string phaseId = GetWStringFromResultSet(phasesResultset, "phaseId");
    unsigned int sequence = GetUnsignedIntFromResultSet(phasesResultset, "sequence");    
    std::string phaseName = DeterminePhaseName(phaseId);
    //cout << phaseName << std::endl;
    int intPhaseId = GetUnsignedIntFromResultSet(phasesResultset, "phaseId");    
    boost::shared_ptr<Phase> localPhase(new Phase(phaseName, sequence, intPhaseId));   
    event.AddPhase(localPhase);

    std::ostringstream oss2;
    oss2<<"SELECT * FROM roundphaseenrollment RE WHERE (RE.`eventId`='"<<event.GetEventId()<<"' AND RE.`phaseId`='"<<phaseId<<"')";  
    sql::ResultSet *roundResultset;
    roundResultset = dbconnector->executeQuery(oss2.str());
    while (roundResultset->next()) 
    {
      std::string roundId = GetWStringFromResultSet(roundResultset, "roundId");
      std::string roundName = DetermineRoundName(roundId);
      //cout << roundName << std::endl;      
      unsigned int sequence = GetUnsignedIntFromResultSet(roundResultset, "sequence");
      unsigned int nrOfBoulders = GetUnsignedIntFromResultSet(roundResultset, "nrofboulders");
      unsigned int intRoundId = GetUnsignedIntFromResultSet(roundResultset, "roundId");
      boost::shared_ptr<Round> localRound( new Round(roundName, sequence, nrOfBoulders, intRoundId));
      localPhase->AddRound(localRound);

      std::ostringstream oss3;
      oss3<<"SELECT RPE.roundId, R.name, EER.startNumber, C.climberId, C.lastname, C.firstname, C.nationality, RE.poleposition \
             FROM roundphaseenrollment RPE JOIN rounds R ON \
             (RPE.eventId='"<<event.GetEventId()<<"' AND RPE.phaseId='"<<phaseId<<"'AND RPE.roundId='"<<roundId<< "') \
             JOIN roundenrollment RE ON (RE.roundId='"<<roundId<< "' AND RE.eventId='"<<event.GetEventId()<<"' AND RE.phaseId='"<<phaseId<<"')\
             JOIN eventenrollment EER ON EER.startNumber=RE.startNumber \
             JOIN climbers C on EER.climberId=C.climberId";

             
             
      sql::ResultSet *scoreResultset;
      scoreResultset = dbconnector->executeQuery(oss3.str());
           
      while (scoreResultset->next()) 
      {
        unsigned int climberId = GetUnsignedIntFromResultSet(scoreResultset, "climberId");
        unsigned int polePosition = GetUnsignedIntFromResultSet(scoreResultset, "poleposition");
        boost::shared_ptr<Climber> localClimber( new Climber(climberId));
        localClimber->SetFirstname(GetWStringFromResultSet(scoreResultset, "firstname"));
        localClimber->SetLastname(GetWStringFromResultSet(scoreResultset, "lastname"));
        localClimber->SetNationality(GetWStringFromResultSet(scoreResultset, "nationality"));
        

        std::string startNumber;
        startNumber = GetWStringFromResultSet(scoreResultset, "startnumber");
        
        boost::shared_ptr<EnrolledClimber> enrolledClimber(new EnrolledClimber(scoreResultset->getInt("startnumber"), localClimber));    
        boost::shared_ptr<ScoreCard> localScoreCard( new ScoreCard(enrolledClimber, localRound->GetNrOfBoulders(), polePosition));

        sql::ResultSet* hitScoreResultSet;
        std::ostringstream oss4;  
        oss4 << "SELECT S.finished, S.topped, S.topAttempts, S.bonussed, S.bonusAttempts, S.boulderNumber ";
        oss4 << "FROM scores S WHERE (S.eventId='"<<event.GetEventId()<<"' AND S.phaseId='"<<phaseId<<"' AND S.roundId='"<<roundId<<"' AND S.startNumber='"<<startNumber;
        oss4 << "')";

        std::string scoreQuery = oss4.str();
        hitScoreResultSet = dbconnector->executeQuery(scoreQuery);      
        while (hitScoreResultSet->next()) 
        {
          unsigned int boulderNumber = hitScoreResultSet->getInt("boulderNumber");

          bool finished = hitScoreResultSet->getInt("finished") == 1;
          boost::shared_ptr<BoulderScore> localScore (new BoulderScore( boulderNumber, finished));

          unsigned int bonussed = hitScoreResultSet->getInt("bonussed");
          unsigned int bonusAttempts = hitScoreResultSet->getInt("bonusAttempts");
          if (bonussed) localScore->BonusHit(bonusAttempts);      
          
          unsigned int topped = hitScoreResultSet->getInt("topped");
          unsigned int topAttempts = hitScoreResultSet->getInt("topAttempts");
          if (topped) localScore->TopHit(topAttempts);
          localScoreCard->AddScore(localScore);
        }
        localRound->AddScoreCard(localScoreCard);
      }                 
    }  
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
  CreateAllPhasesInEvent(localEvent);
  
  ofstream myfile;
  myfile.open ("climbers.xml");
  myfile << "<scoredata>" << std::endl;
  myfile << localEvent;
	myfile << "</scoredata>" << std::endl;
  myfile.close();
  
  return 0;
}

