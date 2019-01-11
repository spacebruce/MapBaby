#pragma once

namespace Numbers
{
	template< typename T>
	struct Rectangle
	{
		T left, right, top, bottom;
		Rectangle(T left, T right, T top, T bottom)
		{
			this->left = left;
			this->right = right;
			this->top = top;
			this->bottom = bottom;
		}
	};

	template< typename T>
	struct Point
	{
		T x, y;
		Point(T x, T y)
		{
			this->x = x;
			this->y = y;
		}
	};

	template <typename T>
	T mapValue(const T value, const T fromLow, const T fromHigh, const T toLow, const T toHigh)
	{
		return ((value - fromLow) / (fromHigh - fromLow) * (toHigh - toLow)) + toLow;
	}

	template <typename T>
	T max(const T left, const T right)
	{
		return (left > right) ? left : right;
	}

	template <typename T>
	T min(const T left, const T right)
	{
		return (left < right) ? left : right;
	}

	template <typename T>
	T clamp(const T value, const T low, const T high)
	{
		return 
	}
}