#pragma once
#include <stdexcept>
#include <string>

class GetDataErrorException : public std::runtime_error {
public:
	const char* METHOD_NAME;		
	enum class ErrorType { NO_DATA_FOUND, NO_DATA_FOUND_BY_ID } errorType;
	int id;

	GetDataErrorException(const char* METHOD_NAME) :
		METHOD_NAME(METHOD_NAME),
		runtime_error("SQL error"),
		errorType(ErrorType::NO_DATA_FOUND),
		id(0) {}

	GetDataErrorException(const char* METHOD_NAME, const ErrorType errorType, int id ) :
		METHOD_NAME(METHOD_NAME),
		runtime_error("SQL error"),
		errorType(errorType),
		id(id) {}
};
