#include "Model.h"

Model::Model(size_t model_id, std::string manufacturer, std::string model_name) 
	: m_model_id(model_id), m_manufacturer(manufacturer), m_model_name(model_name)
{
}

Model::~Model()
{
}
