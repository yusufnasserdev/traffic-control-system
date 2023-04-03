#include "Date.h"

Date::Date(ushort day, ushort month, ushort year)
	: m_day(day), m_month(month), m_year(year)
{
}

Date::~Date()
{
}

bool Date::valid_day(ushort day, ushort month_end)
{
	return (day > 0 && day <= month_end);
}

bool Date::is_valid()
{
	if (this->m_year > 0)
	{
		if (this->m_month > 0 && this->m_month < 13)
		{
			switch (this->m_month)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				return valid_day(this->m_day, 31);
				break;
			case 2:
				if (leap_year(this->m_year))
				{
					return valid_day(this->m_day, 29);
				}
				else
				{
					return valid_day(this->m_day, 28);
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				return valid_day(this->m_day, 30);
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
			return (year % 400 == 0);
		}

		return true;
	}

	return false;
}