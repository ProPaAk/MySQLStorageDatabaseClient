#include <iostream>
#include <string>

#include "DatabaseSQL/DatabaseSQL.h"
#include "UI/DatabaseConsoleUI.h"

//TODO : console output for all functions
//TODO : error handler
//TODO : multithreading
//TODO : authentification
//TODO : Cmake assembly

int main() {

	std::cout << "Enter password for root user" << std::endl;

	//================================
	char* pass = new char[10];	
	std::cin >> pass;
	const char* HOST = "localhost";
	const char* USERNAME = "root";	
	const char* DATABASE_NAME = "storage_database";
	const unsigned int PORT = 3306;
	const char* UNIX_SOCKET = NULL;
	const unsigned long CLIENT_FLAG = 0;	
	//==================================

	DatabaseSQL db( HOST , USERNAME, pass , DATABASE_NAME, PORT, UNIX_SOCKET, CLIENT_FLAG);
	//TODO : сделать ввод полей 
	DatabaseConsoleUI ui(db);
	ui.run();
	return 0;
}