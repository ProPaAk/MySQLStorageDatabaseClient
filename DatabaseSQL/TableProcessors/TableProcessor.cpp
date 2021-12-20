#include "TableProcessor.h"
#include <sstream>

TableProcessor::TableProcessor(MYSQL* conn) : conn(conn) {}

void TableProcessor::handleSQLError(const char* methodName) {
	throw SQLErrorException(methodName, mysql_errno(conn), mysql_error(conn));
}

void TableProcessor::handleNoDataByIdError(const char* methodName, unsigned int id) {	
	throw GetDataErrorException(methodName, GetDataErrorException::ErrorType::NO_DATA_FOUND_BY_ID, id);
}

void TableProcessor::handleNoDataAllError(const char* methodName) {
	throw SQLErrorException(methodName, mysql_errno(conn), mysql_error(conn));
}