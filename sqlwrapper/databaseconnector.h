#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <cppconn/driver.h>
#include <boost/shared_ptr.hpp>
#include <cppconn/resultset.h>

namespace t1b1dataprocessor
{

class databaseconnector {

public:
	databaseconnector();
	~databaseconnector();
	sql::ResultSet* executeQuery(std::string query);
private:
  sql::Driver* m_driver;
  sql::Connection* m_connection;
};

}

#endif // DATABASECONNECTOR_H
