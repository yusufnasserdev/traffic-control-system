#pragma once
typedef unsigned short int ushort;

class Date
{

public:
	Date(ushort day, ushort month, ushort year);
	~Date();

private:
	ushort day, month, year;

private:
	bool valid_day(ushort day, ushort month_end);
	bool valid_date();
	bool leap_year(ushort year);
};

