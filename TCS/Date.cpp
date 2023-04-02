#include "Date.h"

Date::Date(ushort day, ushort month, ushort year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date()
{
}

bool Date::valid_day(ushort day, ushort month_end)
{
	if (day > 0 && day <= month_end)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::valid_date()
{
	if (this->year > 0)
	{
		if (this->month > 0 && this->month < 13)
		{
			switch (this->month)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				return valid_day(this->day, 31);
				break;
			case 2:
				if (leap_year(this->year))
				{
					return valid_day(this->day, 29);
				}
				else
				{
					return valid_day(this->day, 28);
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				return valid_day(this->day, 30);
				break;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool Date::leap_year(ushort year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}