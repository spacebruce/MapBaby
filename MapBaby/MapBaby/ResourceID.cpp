#include "ResourceID.h"

namespace ResourceID
{
	ResourceID::Type Count = 1;
}

ResourceID::Type ResourceID::Create(void)
{
	++Count;
	return (Count);
}

void ResourceID::setCount(const Type value)
{
	ResourceID::Count = value;
}

void ResourceID::setMax(const Type value)
{
	ResourceID::Count = (value >= ResourceID::Count) ? (value + 1) : ResourceID::Count;
}
