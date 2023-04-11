#pragma once
#include <string>

class Model
{

private:
	size_t m_model_id;
	std::string m_manufacturer,
		m_model_name;

public:

	/**
	* @brief Constructs a model with the given inputs
	*
	* @param model_id — The id of the model
	* @param manufacturer — The manufacturer of the model
	* @param model_name — The name of the model
	*/
	Model(size_t model_id, std::string manufacturer, std::string model_name);

	/**
	* @brief Destructor
	*/
	~Model();

};

