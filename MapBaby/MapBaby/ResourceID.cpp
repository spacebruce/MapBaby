#include "ResourceID.h"

namespace ResourceID
{
	ResourceID::Type Count = 1;
}

ResourceID::Type ResourceID::Create(void)
{
	std::time_t timeValue;
	std::time_t time = std::time(&timeValue);
	ResourceID::TypeHalf half = time;
	ResourceID::Type result = (static_cast<Type>(half) << 24) + ResourceID::Count;
	ResourceID::Count++;
	return result;
}