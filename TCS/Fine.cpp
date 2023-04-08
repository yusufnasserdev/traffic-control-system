#include "Fine.h"

Fine::Fine(float amount, std::string description, bool paid, Date date)
	: m_amount(amount), m_description(description), m_paid(paid), m_date(date)
{

}

Fine::~Fine()
{

}

inline float Fine::get_amount() const { return m_amount; }

inline std::string Fine::get_description() const { return m_description; }

inline bool Fine::is_paid() const { return m_paid; }

inline void Fine::pay() { m_paid = true; }

inline Date Fine::get_date() const { return m_date; }
