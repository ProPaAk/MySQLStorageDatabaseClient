#include "ProductTableProcessor.h"
#include <sstream>
#include <mysql.h>
#include <iostream>

ProductData ProductTableProcessor::getProductById(unsigned int id) {
	std::stringstream query;
	query << "SELECT * FROM " << PRODUCT_TABLE << " WHERE " << PRODUCT_ID
		<< " = " << id << ';';

	int qstate = mysql_query(conn, query.str().c_str());
	if (!qstate) {
		MYSQL_RES* res = mysql_store_result(conn);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(res)) {
			return ProductData(std::stoi(row[0]), row[1], row[2],
				row[3], std::stoi(row[4]), std::stod(row[5]));
			handleNoDataByIdError("getProductById", id);
		}
	}
	handleSQLError("getProductById");
}

std::vector<ProductData> ProductTableProcessor::getAllProducts() {
	std::stringstream query;
	query << "SELECT "<< PRODUCT_ID << ", " << PRODUCT_NAME << ", " 
		<< MANUFACTURER_NAME << ", " << MATERIAL_NAME << ", " 
		<< PRODUCT_COUNT << ", " << PRODUCT_PRICE <<" FROM " << PRODUCT_TABLE 
		<< " inner join " << MATERIAL_TABLE << " ON " 
		<< PRODUCT_MATERIAL_ID << " = " << MATERIAL_ID << " "
		<< " inner join " << MANUFACTURER_TABLE << " ON "
		<< PRODUCT_MANUFACTERER_ID << " = " << MANUFACTURER_ID << ';';

	int qstate = mysql_query(conn, query.str().c_str());
	if (!qstate) {
		std::vector<ProductData> data;
		MYSQL_RES* res = mysql_store_result(conn);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(res)) {
			data.emplace_back(ProductData(std::stoi(row[0]), row[1], row[2],
				row[3], std::stoi(row[4]), std::stod(row[5])));
		}
		if (!data.size()) {
			handleNoDataAllError("getAllProducts");
		}
		return data;
	}
	handleSQLError("getAllProducts");
}

//void ProductTableProcessor::addProduct(const ProductData& data) {
//	std::stringstream query;
//	query << "INSERT INTO " << PRODUCT_TABLE << " ( "
//		<< PRODUCT_NAME << " , "
//		<< PRODUCT_COUNT << " , "
//		<< PRODUCT_PRICE << " , "
//		<< PRODUCT_MATERIAL_ID << " , "
//		<< MANUFACTURER_ID << " ) "
//		<< " VALUES( '"
//		<< data.name << "' ,"
//		<< data.count << " , "
//		<< data.price << " , "
//		<< data.material << " , "
//		<< data.manufacturer << " );";
//	int qstate = mysql_query(conn, query.str().c_str());
//	if (qstate) {
//		std::stringstream error;
//		error << "Adding product error #" << mysql_errno(conn) << ". "
//			<< mysql_error(conn);
//		handleSQLError("addProduct");
//	}
//}
//
//void ProductTableProcessor::deleteProductById(unsigned int id) {
//	std::stringstream query;
//	query << "DELETE FROM " << PRODUCT_TABLE
//		<< " WHERE( " << PRODUCT_ID << " = " << id << " );";
//	int qstate = mysql_query(conn, query.str().c_str());
//	if (qstate) {
//		handleSQLError("deleteProductById");
//	}
//}
//
//void ProductTableProcessor::changeProduct(const ProductData& productData) {
//	std::stringstream query;
//	query << "UPDATE " << PRODUCT_TABLE
//		<< " SET " << PRODUCT_ID << " = " << productData.id << " , "
//		<< PRODUCT_NAME << " = '" << productData.name << "' , "
//		<< MANUFACTURER_ID << " = " << productData.manufacturer << " , "
//		<< PRODUCT_MATERIAL_ID << " = " << productData.material << " , "
//		<< PRODUCT_COUNT << " = " << productData.count << " , "
//		<< PRODUCT_PRICE << " = " << productData.price
//		<< " WHERE( " << PRODUCT_ID << " = " << productData.id << " );";
//	int qstate = mysql_query(conn, query.str().c_str());
//	if (qstate) {
//		handleSQLError("changeProduct");
//	}
//}