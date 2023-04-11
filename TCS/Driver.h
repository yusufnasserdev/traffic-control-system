#pragma once
#include <string>
#include "Date.h"


class Driver
{
private:
	size_t m_license_number,
		m_owned_cars_count;
	std::string m_name;
	Date m_birth_date;

public:

	/**
	* @brief Constructs a driver with the given inputs
	* 
	* @param name — The name of the driver
	* @param b_date — The birth date of the driver
	*/
	Driver(std::string name, Date b_date);

	/**
	* @brief Destructor
	*/
	~Driver();

	/**
	* @brief Adds a car to the driver
	*/
	void add_car();

private:
	/**
	* @brief — Generates a unique license number for the driver
	* @return —  The license number
	*/
	size_t get_license_number();
};

