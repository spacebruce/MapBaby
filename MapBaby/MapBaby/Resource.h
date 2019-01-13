#pragma once
#include "ResourceID.h"

class Resource
{
private:
	ResourceID::Type ID = ResourceID::Create();
public:
	ResourceID::Type getID();

	Resource();
	~Resource();
};