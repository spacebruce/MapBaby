#pragma once
#include <cstdint>

namespace ResourceID
{
	using Type = std::uint32_t;
	constexpr static Type Invalid = 0;

	extern Type Count;

	Type Create(void);

	void setCount(const Type value);
	void setMax(const Type value);
}