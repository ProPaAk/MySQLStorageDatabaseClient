#pragma once
#include <string>

struct ManufacturerData {
	unsigned int id;
	std::string name;
	unsigned int deliveryTime;
	std::string description;	

	ManufacturerData(
		unsigned int id, 
		std::string name,
		unsigned int deliveryTime,
		std::string description

	) :
		id(id),
		name(name),
		deliveryTime(deliveryTime),
		description(description)
	{}
	ManufacturerData(		 
		std::string name,
		unsigned int deliveryTime,
		std::string description
	) :
		id(0),
		name(name),
		deliveryTime(deliveryTime),
		description(description)
	{}

};
	// TODO: overload operetor<<
