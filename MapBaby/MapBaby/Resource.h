#pragma once
#include "ResourceID.h"

class Resource
{
private:
	ResourceID::Type ID = ResourceID::Invalid;
public:
	ResourceID::Type getID() const;

	Resource() = default;
	Resource(ResourceID::Type ID);

	virtual ~Resource();
};