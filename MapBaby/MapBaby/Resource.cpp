#include "Resource.h"

Resource::Resource()
{
}

Resource::~Resource()
{
}

ResourceID::Type Resource::getID() const
{
	return this->ID;
}