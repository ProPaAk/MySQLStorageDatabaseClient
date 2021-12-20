#include "ManufacturerTableProcessor.h"
#include <sstream>
#include <mysql.h>

ManufacturerData ManufacturerTableProcessor::getManufacturerById(unsigned int id) {
	std::stringstream query;
	query << "SELECT * FROM " << MANUFACTURER_TABLE
		<< " WHERE " << MANUFACTURER_ID << " = " << id << ';';
	int qstate = mysql_query(conn, query.str().c_str());
	if (!qstate) {
		MYSQL_RES* res = mysql_store_result(conn);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(res)) {
			return ManufacturerData(std::stoi(row[0]), row[1],
				std::stoi(row[2]), row[3]);
		}
		handleNoDataByIdError("getManufacturerById", id);
	}
	handleSQLError("getManufacturerById");
}

std::vector<ManufacturerData> ManufacturerTableProcessor::getAllManufacturers() {
	std::stringstream query;
	query << "SELECT * FROM " << MANUFACTURER_TABLE << ';';
	int qstate = mysql_query(conn, query.str().c_str());
	if (!qstate) {
		std::vector<ManufacturerData> data;
		MYSQL_RES* res = mysql_store_result(conn);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(res)) {
			data.emplace_back(ManufacturerData(std::stoi(row[0]), row[1],
				std::stoi(row[2]), row[3]));
		}
		if (!data.size()) {
			handleNoDataAllError("getAllManufacturers");
		}
		return data;
	}
	handleSQLError("getAllManufacturers");
}

//void ManufacturerTableProcessor::addManufacturer(const ManufacturerData& data) {
//	std::stringstream query;
//	query << "INSERT INTO " << MANUFACTURER_TABLE << "("
//		<< MANUFACTURER_DELIVERY_TIME << ","
//		<< MANUFACTURER_DESCRIPTION << ","
//		<< MANUFACTURER_NAME << ")"
//		<< "VALUES( '" << data.deliveryTime << "' ,"
//		<< "'" << data.description << "' ,"
//		<< "'" << data.name << "'" << ");";
//	int qstate = mysql_query(conn, query.str().c_str());
//	if (qstate) {
//		handleSQLError("addManufacturer");
//	}
//}
//
//void ManufacturerTableProcessor::deleteManufacturerById(unsigned int id) {
//	std::stringstream query;
//	query << "DELETE FROM " << MANUFACTURER_TABLE
//		<< " WHERE( " << MANUFACTURER_ID << " = " << id << " );";
//	int qstate = mysql_query(conn, query.str().c_str());
//	if (qstate) {
//		handleSQLError("deleteManufacturerById");
//	}
//}
//
//void ManufacturerTableProcessor::changeManufacturer(const ManufacturerData& data) {
//	std::stringstream query;
//	query << "UPDATE " << MANUFACTURER_TABLE
//		<< " SET " << MANUFACTURER_ID << " = " << data.id << " , "
//		<< MANUFACTURER_NAME << " = '" << data.name << "' , "
//		<< MANUFACTURER_DELIVERY_TIME << " = " << data.deliveryTime << " , "
//		<< MANUFACTURER_DESCRIPTION << " = '" << data.description << "'"
//		<< " WHERE( " << MANUFACTURER_ID << " = " << data.id << " );";
//	int qstate = mysql_query(conn, query.str().c_str());
//	if (qstate) {
//		handleSQLError("changeManufacturer");
//	}
//}
