#pragma once
#include <mysql.h>
#include "TableProcessors/ProductTableProcessor.h"
#include "TableProcessors/ManufacturerTableProcessor.h"

//TODO : working with a remote database

class DatabaseSQL {
	//Db connection parameters
	const char* HOST;
	const char* USERNAME;
	char* PASSWORD;
	const char* DATABASE_NAME;
	const unsigned int PORT;
	const char* UNIX_SOCKET;
	const unsigned long CLIENT_FLAG;	
	
	//Table data
	ProductTableProcessor* productTableProcessor;
	ManufacturerTableProcessor* manufacturerTableProcessor;

	//Variables
	MYSQL* conn;
public: 
	DatabaseSQL(
		const char* HOST,
		const char* USERNAME,
		char* PASSWORD,
		const char* DATABASE_NAME,
		const unsigned int PORT,
		const char* UNIX_SOCKET,
		const unsigned long CLIENT_FLAG
	);

	~DatabaseSQL();
	ProductTableProcessor& productTable();
	ManufacturerTableProcessor& manufacturerTable();
};

