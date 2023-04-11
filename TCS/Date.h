#pragma once
typedef unsigned short int ushort;

class Date
{

private:
	ushort m_day,
		m_month,
		m_year;

public:

	/**
	* @brief Constructs a date with the given inputs
	*
	* @param day — The day of the date
	* @param month — The month of the date
	* @param year — The year of the date
	*/
	Date(ushort day, ushort month, ushort year);

	/**
	* @brief Destructor
	*/
	~Date();

public:


	/**
	* @brief Check if the date is valid
	* @return true if the date is valid, false otherwise
	*/
	bool is_valid();

private:

	/**
	* @brief Check if the day is valid
	* @param day — The day to check
	* @param month_end — The last day of the month
	* @return true if the day is valid, false otherwise
	*/
	bool valid_day(ushort day, ushort month_end);

	/**
	* @brief Check if the year is a leap year
	* @param year — The year to check
	* @return true if the year is a leap year, false otherwise
	*/
	bool leap_year(ushort year);
};

