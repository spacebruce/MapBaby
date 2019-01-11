#pragma once

namespace Numbers
{
	template <typename T>
	T mapValue(const T value, const T fromLow, const T fromHigh, const T toLow, const T toHigh)
	{
		return ((value - fromLow) / (fromHigh - fromLow) * (toHigh - toLow)) + toLow;
	}
}