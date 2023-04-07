#pragma once
#include <string>

class Model
{
	public:
		Model(size_t model_id, std::string manufacturer, std::string model_name);
		~Model();

	private:
	size_t model_id;
	std::string manufacturer;
	std::string model_name;
};

