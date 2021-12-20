#include "DatabaseConsoleUI.h"
#include <iomanip>
#include <iostream>
#include <thread>
#include <conio.h>

// TODO: keyboard event reader

DatabaseConsoleUI::DatabaseConsoleUI(DatabaseSQL& dbRef): dbRef(dbRef){}

void DatabaseConsoleUI::mainMenu() {
	std::cout << "Choose action by entering appropriate number:" << std::endl;
	std::cout << "1. Show all tables." << std::endl;
	std::cout << "2. Show separate table." << std::endl;
	std::cout << "0. Exit the programm." << std::endl;

	int i;
	std::cin >> i;
	switch (i) {
	case 0:  
		uiState = STATE_QUITING;
		break;
	case 1 : 
		getAllTablesFromDB();
		system("pause");
		break;
	case 2 :
		uiState = STATE_SEPARATE_TABLE_MENU;
		break;
	default: break;
	}	
}

void DatabaseConsoleUI::quitMessage(){
	std::cout << "Thank you, come back again!" << std::endl;
}

void DatabaseConsoleUI::separateTableMenu() {
	std::cout << "Choose action by entering appropriate number:" << std::endl;
	std::cout << "1. Show product table." << std::endl;
	std::cout << "2. Show manufacturer table." << std::endl;
	std::cout << "0. Exit to main menu." << std::endl;

	int i;
	std::cin >> i;
	switch (i) {
	case 0:
		uiState = STATE_MAIN_MENU;
		break;
	case 1:
		getProductTableFromDB();
		system("pause");
		break;
	case 2:
		getManufacturerTableFromDB();
		system("pause");
		break;
	default: break;
	}
}

void DatabaseConsoleUI::getAllTablesFromDB() {	
	getProductTableFromDB();
	std::cout << std::endl << std::endl;
	getManufacturerTableFromDB();
	uiState = STATE_MAIN_MENU;	
}
	
void DatabaseConsoleUI::getProductTableFromDB() {
	try	{
		std::cout << PRODUCT_TABLE << std::endl << std::left
			<< std::setw(5) << PRODUCT_ID_FIELD
			<< std::setw(20) << PRODUCT_NAME_FIELD
			<< std::setw(13) << PRODUCT_MANUFACTURER_FIELD
			<< std::setw(9) << PRODUCT_MATERIAL_FIELD
			<< std::setw(10) << PRODUCT_COUNT_FIELD
			<< std::setw(10) << PRODUCT_PRICE_FIELD << std::endl;

		std::vector<ProductData> productTableData = dbRef.productTable().getAllProducts();		
		for (auto& pd : productTableData) {
			std::cout << std::left
				<< std::setw(5) << pd.id << std::setw(20) << pd.name
				<< std::setw(13) << pd.manufacturer	<< std::setw(9) << pd.material
				<< std::setw(10) << pd.count << std::setw(10) << pd.price << std::endl;		
		}
	}
	catch (const std::exception&) {
		std::cout << "Error " << std::endl;
		return;
		// TODO : handle errors
	}	
}

void DatabaseConsoleUI::getManufacturerTableFromDB() {
	try {
		std::vector<ManufacturerData> manufacturerTableData 
			= dbRef.manufacturerTable().getAllManufacturers();
		std::cout << MANUFATURER_TABLE << std::endl << std::left
			<< std::setw(5) << MANUFATURER_ID_FIELD
			<< std::setw(20) << MANUFATURER_NAME_FIELD
			<< std::setw(14) << MANUFATURER_DELIVERY_TIME_FIELD
			<< std::setw(11) << MANUFATURER_DESCRIPTION_FIELD << std::endl;

		for (auto& md : manufacturerTableData) {
			std::cout << std::left
				<< std::setw(5) << md.id
				<< std::setw(20) << md.name
				<< std::setw(14) << md.deliveryTime
				<< std::setw(11) << md.description << std::endl;			
		}
	}
	catch (const SQLErrorException&) {
		std::cout << "Error " << std::endl; 
		return;
		// TODO : handle errors
	}	
}

void DatabaseConsoleUI::run() {	
	while (true) {		
		system("cls");
		switch (uiState) {
		case DatabaseConsoleUI::STATE_MAIN_MENU:
			mainMenu();
			break;
		case DatabaseConsoleUI::STATE_SEPARATE_TABLE_MENU:
			separateTableMenu();
			break;		
		case DatabaseConsoleUI::STATE_QUITING:
			quitMessage();
			return;
		default: return;
		}
	}
}
