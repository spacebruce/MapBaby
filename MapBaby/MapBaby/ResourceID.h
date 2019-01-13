#pragma once
#include <cstdint>

namespace ResourceID
{
	using Type = std::uint32_t;
	extern Type Count;

	Type Create(void);
	void SetCount(const Type value);
}