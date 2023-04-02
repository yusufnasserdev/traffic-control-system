#pragma once
#include <string>
#include "Date.h"


class Driver
{
public:
	Driver(std::string name, Date b_date);
	~Driver();

private:
	size_t license_number, owned_cars_number;
	std::string name;
	Date birth_date;
};

