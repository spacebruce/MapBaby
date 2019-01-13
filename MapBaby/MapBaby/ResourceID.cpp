#include "ResourceID.h"

namespace ResourceID
{
	ResourceID::Type Count = 0;
}

ResourceID::Type ResourceID::Create(void)
{
	++Count;
	return (Count);
}

void ResourceID::SetCount(const Type value)
{
	ResourceID::Count = 0;
}
