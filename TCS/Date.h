#pragma once
typedef unsigned short int ushort;

class Date
{

private:
	ushort m_day, m_month, m_year;

public:
	Date(ushort day, ushort month, ushort year);
	~Date();

public:
	bool is_valid();

private:
	bool valid_day(ushort day, ushort month_end);
	bool leap_year(ushort year);
};

