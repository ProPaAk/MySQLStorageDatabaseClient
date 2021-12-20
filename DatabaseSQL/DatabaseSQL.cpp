#include "DatabaseSQL.h"
#include <sstream>

DatabaseSQL::DatabaseSQL(
	const char* HOST,
	const char* USERNAME,
	char* PASSWORD,
	const char* DATABASE_NAME,
	const unsigned int PORT,
	const char* UNIX_SOCKET,
	const unsigned long CLIENT_FLAG
) :
	HOST(HOST),
	USERNAME(USERNAME),
	PASSWORD(PASSWORD),
	DATABASE_NAME(DATABASE_NAME),
	PORT(PORT),
	UNIX_SOCKET(UNIX_SOCKET),
	CLIENT_FLAG(CLIENT_FLAG) 
{
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, HOST, USERNAME, PASSWORD, 
		DATABASE_NAME, PORT, UNIX_SOCKET, CLIENT_FLAG);
	if (!conn) {
		throw std::runtime_error("Database connection error!");
	}
	productTableProcessor = new ProductTableProcessor(conn);
	manufacturerTableProcessor = new ManufacturerTableProcessor(conn);
}

DatabaseSQL::~DatabaseSQL() {
	delete productTableProcessor;
	delete manufacturerTableProcessor;
}

ProductTableProcessor& DatabaseSQL::productTable() {	
	return *productTableProcessor;
}

ManufacturerTableProcessor& DatabaseSQL::manufacturerTable() {
	return *manufacturerTableProcessor;
}
