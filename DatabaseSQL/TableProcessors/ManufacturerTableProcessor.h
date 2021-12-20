#pragma once
#include <vector>
#include "DatabaseSQL/DataClasses/ManufacturerData.h"
#include "TableProcessor.h"

class ManufacturerTableProcessor : public TableProcessor {
	const char* MANUFACTURER_TABLE = "storage_database.manufacturer";
	const char* MANUFACTURER_ID = "manufacturer_id";
	const char* MANUFACTURER_NAME = "manufacturer_name";
	const char* MANUFACTURER_DELIVERY_TIME = "manufacturer_delivery_time";
	const char* MANUFACTURER_DESCRIPTION = "manufacturer_description";

	const char* MANUFACTURER_EMAIL_TABLE = "storage_database.manufacturer_email";
	const char* MANUFACTURER_EMAIL_ID = "manufacturer_email_id";
	const char* MANUFACTURER_EMAIL_VALUE = "manufacturer_email_value";

public:
	ManufacturerTableProcessor(MYSQL* conn) : TableProcessor(conn) {}
	std::vector<ManufacturerData> getAllManufacturers();
	ManufacturerData getManufacturerById(unsigned int id);
	//void addManufacturer(const ManufacturerData& data);
	//void deleteManufacturerById(unsigned int id);
	//void changeManufacturer(const ManufacturerData& data);
};

