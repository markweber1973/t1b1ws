#include "databaseconnector.h"
#include <cppconn/statement.h>


namespace t1b1dataprocessor
{

databaseconnector::databaseconnector()
{
  m_driver = get_driver_instance();
  m_connection = m_driver->connect("localhost", "mark", "mark");	
  m_connection->setSchema("T1B1");
}

databaseconnector::~databaseconnector()
{
  delete m_connection;
}

sql::ResultSet* databaseconnector::executeQuery(std::string query)
{
  sql::Statement *stmt;
  sql::ResultSet* res;
  stmt = m_connection->createStatement();
  res = stmt->executeQuery(query);
  delete stmt;
  return res;
}

}

