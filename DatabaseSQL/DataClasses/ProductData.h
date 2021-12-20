#pragma once
#include <string>

struct ProductData {
	unsigned int id;
	std::string name;
	std::string manufacturer;
	std::string material;
	unsigned int count;
	double price;

	ProductData(
		unsigned int id, 
		std::string name, 
		std::string manufacturer,
		std::string material,
		unsigned int count,
		double price
	) : 
		id(id), 
		name(name), 
		manufacturer(manufacturer),
		material(material),	
		count(count),
		price(price)
	{}
	ProductData(
		std::string name,
		std::string manufacturer,
		std::string material,
		unsigned int count,
		double price
	) :
		id(0),
		name(name),
		manufacturer(manufacturer),
		material(material),
		count(count),
		price(price)
	{}
};
// TODO: overload operetor<<
