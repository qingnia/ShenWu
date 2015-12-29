#include "DAO.h"
#include "cocos2d.h"

static DAO* dao = nullptr;

DAO::DAO()
{
}

DAO* DAO::getInstance()
{
	if (dao)
		return dao;
	dao = new DAO();
	if (dao && dao->init())
		return dao;
	else
	{
		delete dao;
		dao = NULL;
		return NULL;
	}
}

DAO::~DAO()
{
	mysql_close(connection);
}

bool DAO::init()
{
//	MYSQL mysql;
//	MYSQL* connection;
	mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, "192.168.1.254", "qingniao", "qingniao", "ShenWu", 0, 0, 0);
	if (!connection)
	{
		CCLOG("connection error, %s", mysql_error(&mysql));
		return false;
	}
	if (mysql_query(connection, "use ShenWu"))
	{
		CCLOG("user ShenWu error, %s", mysql_error(&mysql));
		return false;
	}
	if (mysql_query(connection, "SET NAMES utf8"))
	{
		CCLOG("character error, %s", mysql_error(&mysql));
		return false;
	}
	/**
	if (!mysql_query(connection, "select * from hero"))
	{
		MYSQL_RES* result = mysql_store_result(connection);
		MYSQL_ROW row = mysql_fetch_row(result);
		CCLOG("%s, %s, %s, %s", row[0], row[1], row[2], row[3]);
		mysql_free_result(result);
	}
	*/
	return true;
}

char* DAO::SimpleSelect(char* target, char* table)
{
	char SQL[128];
	memset(SQL, 0, 128);
	sprintf(SQL, "select %s from %s", target, table);
	return NULL;
}
char* DAO::SimpleDelete(char* target, char* table)
{
	return NULL;
}
char* DAO::SimpleInsert(char* target, char* table)
{
	return NULL;
}
char* DAO::SimpleUpdata(char* target, char* table)
{
	return NULL;
}
bool DAO::ExecSQLQuery(char* query)
{
	if (!mysql_query(connection, "select * from hero"))
		return true;
	else
		return false;
}
char* DAO::getRes(char* condition)
{
	MYSQL_RES* result = mysql_store_result(connection);
	MYSQL_ROW row = mysql_fetch_row(result);
	char* ret = (char*)malloc(128 * sizeof(char));
	memset(ret, 0, sizeof(char));
	while (row)
	{
		if (!strcmp(*row, condition))
			strcpy(ret, *row);
	}
	mysql_free_result(result);
	return ret;
}