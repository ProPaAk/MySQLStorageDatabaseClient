#pragma once
#include <vector>
#include "DatabaseSQL/DataClasses/ProductData.h"
#include "TableProcessor.h"

class ProductTableProcessor : public TableProcessor {

	const char* PRODUCT_TABLE = "storage_database.product";
	const char* PRODUCT_ID = "product.product_id";
	const char* PRODUCT_NAME = "product.product_name";
	const char* PRODUCT_COUNT = "product.product_count";
	const char* PRODUCT_PRICE = "product.product_price";
	const char* PRODUCT_MANUFACTERER_ID = "product.manufacturer_id";
	const char* PRODUCT_MATERIAL_ID = "product.product_material_id";
	
	const char* MANUFACTURER_TABLE = "storage_database.manufacturer";
	const char* MANUFACTURER_ID = "manufacturer.manufacturer_id";
	const char* MANUFACTURER_NAME = "manufacturer.manufacturer_name";

	const char* MATERIAL_TABLE = "storage_database.product_material";
	const char* MATERIAL_ID = "product_material.product_material_id";
	const char* MATERIAL_NAME = "product_material.product_material_name";

public:	
	ProductTableProcessor(MYSQL* conn) : TableProcessor(conn) {}

	ProductData getProductById(unsigned int id);
	std::vector<ProductData> getAllProducts();
	//void addProduct(const ProductData& data);
	//void deleteProductById(unsigned int id);
	//void changeProduct(const ProductData& data);
};

