#include "Resource.h"

Resource::Resource(ResourceID ID)
{
	this->ID = ID;
}

Resource::~Resource()
{
}

ResourceID Resource::getID() const
{
	return this->ID;
}