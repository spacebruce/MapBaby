#include "Resource.h"

Resource::Resource()
{
	this->ID = ResourceID::Create();
}

Resource::Resource(ResourceID::Type ID)
{
	this->ID = ID;
	ResourceID::setMax(ID);
}

Resource::~Resource()
{
}

ResourceID::Type Resource::getID() const
{
	return this->ID;
}