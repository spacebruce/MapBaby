#pragma once

#include <cstdint>
#include <chrono>


class ResourceID
{
private:
	using Type = std::uint64_t;
	Type value = 0;

public:
	ResourceID(const Type value);
	ResourceID();

	Type get() const;
	bool isInvalid() const;

	explicit operator Type() const;
};

inline bool operator==(const ResourceID &left, const ResourceID &right)
{
	return(left.get() == right.get());
}

inline bool operator!=(const ResourceID &left, const ResourceID &right)
{
	return(left.get() != right.get());
}

inline bool operator>(const ResourceID &left, const ResourceID &right)
{
	return(left.get() > right.get());
}

inline bool operator<(const ResourceID &left, const ResourceID &right)
{
	return(left.get() < right.get());
}

inline bool operator>=(const ResourceID &left, const ResourceID &right)
{
	return(left.get() >= right.get());
}

inline bool operator<=(const ResourceID &left, const ResourceID &right)
{
	return(left.get() <= right.get());
}


