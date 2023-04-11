#include "Driver.h"

Driver::Driver(std::string name, Date b_date) 
	: m_name(name), m_birth_date(b_date)
{
	m_license_number = get_license_number();

}

Driver::~Driver()
{
}

void Driver::add_car()
{

}

size_t Driver::get_license_number()
{
	return 0;
}
