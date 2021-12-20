#pragma once
#include <stdexcept>
//TODO : classes for any SQL exceptions

class SQLErrorException : public std::runtime_error {
public:
	const char* METHOD_NAME;
	const unsigned int SQL_ERROR_ID;
	const char* SQL_ERROR_MESSAGE;

	SQLErrorException(const char* METHOD_NAME, const unsigned int SQL_ERROR_ID,
		const char* SQL_ERROR_MESSAGE) :
		runtime_error("SQL error"),
		METHOD_NAME(METHOD_NAME),
		SQL_ERROR_ID(SQL_ERROR_ID),
		SQL_ERROR_MESSAGE(SQL_ERROR_MESSAGE) {}		

	/*SQLErrorException(const char* METHOD_NAME, const unsigned int SQL_ERROR_ID,
		const char* SQL_ERROR_MESSAGE, const unsigned int ID) : runtime_error("SQL error"), 
		METHOD_NAME(METHOD_NAME), SQL_ERROR_ID(SQL_ERROR_ID), 
		SQL_ERROR_MESSAGE(SQL_ERROR_MESSAGE), ID(ID){}*/
};
