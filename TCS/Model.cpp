#include "Model.h"

Model::Model(size_t model_id, std::string manufacturer, std::string model_name) 
	: model_id(model_id), manufacturer(manufacturer), model_name(model_name)
{
}

Model::~Model()
{
}
