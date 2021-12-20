#pragma once
#include <mysql.h>
#include "DatabaseSQL/Exceptions/SQLErrorException.h"
#include "DatabaseSQL/Exceptions/GetDataErrorException.h"

class TableProcessor{
protected:
	MYSQL* conn;

	TableProcessor(MYSQL* conn);

	//Error handling
	void handleSQLError(const char* methodName);
	void handleNoDataByIdError(const char* methodName, unsigned int id);
	void handleNoDataAllError(const char* methodName);
};

