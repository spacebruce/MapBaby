#pragma once
#include <cstdint>

namespace ResourceID
{
	using Type = std::uint32_t;
	extern Type Count;

	Type Create(void);

	void setCount(const Type value);
	void setMax(const Type value);
}