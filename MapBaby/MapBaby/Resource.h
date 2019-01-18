#pragma once
#include "ResourceID.h"

class Resource
{
private:
	ResourceID ID = ResourceID();
public:
	ResourceID getID() const;

	Resource() = default;
	Resource(ResourceID ID);

	virtual ~Resource();
};