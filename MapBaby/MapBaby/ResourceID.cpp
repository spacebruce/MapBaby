#include "ResourceID.h"

ResourceID::ResourceID()
{
	auto time = std::chrono::high_resolution_clock::now();
	auto duration = time.time_since_epoch();
	auto ticks = duration.count();

	this->value = static_cast<Type>(ticks);
}

ResourceID::ResourceID(const Type value)
{
	this->value = value;
}

ResourceID::Type ResourceID::get() const
{
	return this->value;
}

ResourceID::operator Type() const
{
	return this->value;
}

bool ResourceID::isInvalid() const
{
	return(value == 0);
}

