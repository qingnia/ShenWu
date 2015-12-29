#ifndef _DAO_H_
#define _DAO_H_

#include <WinSock2.h>
/**
typedef unsigned int SOCKET;
#ifndef my_socket_defined
#define my_socket unsigned int
#endif
*/
#include "mysql.h"

using namespace std;

class DAO
{
public:
	~DAO();
	static DAO* getInstance();

	bool ExecSQLQuery(char* query);
	char* getRes(char* condition);
	char* SimpleSelect(char* target, char* table);
	char* SimpleDelete(char* target, char* table);
	char* SimpleInsert(char* target, char* table);
	char* SimpleUpdata(char* target, char* table);
private:
	DAO();
	bool init();
	MYSQL mysql, *connection;
	
};

#endif