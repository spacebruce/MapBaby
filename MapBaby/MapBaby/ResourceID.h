#pragma once
#include <cstdint>
#include <ctime>

namespace ResourceID
{
	using Type = std::uint32_t;
	using TypeHalf = std::uint16_t;
	constexpr static Type Invalid = 0;

	extern Type Count;

	Type Create(void);
}