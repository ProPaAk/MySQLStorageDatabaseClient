#pragma once
#include "DatabaseSQL\DatabaseSQL.h"

class DatabaseConsoleUI {
	DatabaseSQL& dbRef;

	//Product colum names
	const char* PRODUCT_TABLE = "Product table";
	const char* PRODUCT_ID_FIELD = "ID";
	const char* PRODUCT_NAME_FIELD = "Name";
	const char* PRODUCT_MANUFACTURER_FIELD = "Manufacturer";
	const char* PRODUCT_MATERIAL_FIELD = "Material";
	const char* PRODUCT_COUNT_FIELD = "Count";
	const char* PRODUCT_PRICE_FIELD = "Price";
	
	//Manufacturer colum names
	const char* MANUFATURER_TABLE = "Manufacturer table";
	const char* MANUFATURER_ID_FIELD = "ID";
	const char* MANUFATURER_NAME_FIELD = "Name";
	const char* MANUFATURER_DELIVERY_TIME_FIELD = "Delivery time";
	const char* MANUFATURER_DESCRIPTION_FIELD = "Description";	

	//UI
	enum UIState { STATE_MAIN_MENU, STATE_SEPARATE_TABLE_MENU, STATE_QUITING } uiState;

	void mainMenu();
	void quitMessage();
	void separateTableMenu();
	void getAllTablesFromDB();
	void getProductTableFromDB();
	void getManufacturerTableFromDB();	

public:

	DatabaseConsoleUI(DatabaseSQL& dbRef);
	void run();

};

