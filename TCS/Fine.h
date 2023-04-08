#pragma once

#include "Dependencies.h"
#include "Date.h"

class Fine
{
public:
	Fine(float amount, std::string description, bool paid, Date date);
	~Fine();

	float get_amount() const;
	std::string get_description() const;
	bool is_paid() const;
	void pay();
	Date get_date() const;

private:
	float m_amount;
	std::string m_description;
	bool m_paid = false;
	Date m_date;
};

