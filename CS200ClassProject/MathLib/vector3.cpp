/*	sinil.gang		rtd99062@gmail.com
 *	vector3.cpp
 *	Source file for vector3
 *	CS200 Class Project
 */
#include "vector3.hpp"
#include <limits>		// std::numeric_limits<float>::epsilon()
#include <cmath>	// for std::sqrt(), std::abs(), and std::acos()


namespace Graphics
{

	template <typename T>
	vector3<T> operator-(const vector3<T>& v) noexcept
	{
		return vector3(-v.x, -v.y, -v.z);
	}

	template <typename T>
	vector3<T> operator+(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}

	template <typename T>
	vector3<T> operator-(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return vector3(lhs.x - rhs.y, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	template <typename T>
	vector3<T> operator*(const vector3<T>& v, float scale) noexcept
	{
		return vector3(v.x * scale, v.y * scale, v.z * scale);
	}

	template <typename T>
	vector3<T> operator*(float scale, const vector3<T>& v) noexcept
	{
		return v * scale;
	}

	template <typename T>
	vector3<T> operator/(const vector3<T>& v, float divisor)
	{
		if (divisor == 0)
		{
			throw "Divided by Zero";
		}
		return vector3(v.x / divisor, v.y / divisor, v.z / divisor);
	}

	template <typename T>
	bool operator==(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return (
			std::abs(lhs.x - rhs.x) <= std::numeric_limits<T>::epsilon() &&
			std::abs(lhs.y - rhs.y) <= std::numeric_limits<T>::epsilon() &&
			std::abs(lhs.z - rhs.z) <= std::numeric_limits<T>::epsilon()
			);
	}


	template <typename T>
	bool operator!=(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return !(lhs == rhs);
	}

	template <typename T>
	T dot(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	template <typename T>
	vector3<T> cross(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return vector3(lhs.y * rhs.z - lhs.z * rhs.y, -(lhs.x * rhs.z - lhs.z * rhs.x), lhs.x * rhs.y - lhs.y * rhs.x);
	}

	template <typename T>
	T magnitude_squared(const vector3<T>& lhs) noexcept
	{
		return dot(lhs, lhs);
	}

	template <typename T>
	float magnitude(const vector3<T>& lhs) noexcept
	{
		return std::sqrt(magnitude_squared(lhs));
	}

	template <typename T>
	vector3<T> normalize(const vector3<T>& lhs) noexcept
	{
		return lhs / magnitude(lhs);
	}

	template <typename T>
	T distance_between_squared(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return magnitude_squared(lhs - rhs);
	}

	template <typename T>
	float distance_between(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		std::sqrt(distance_between_squared(lhs, rhs));
	}

	template <typename T>
	float angle_between(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		const float magnitudeOfLhs = magnitude(lhs);
		if (magnitudeOfLhs == 0)
		{
			throw "Magnitude of 1st parameter is zero. It cause dividing by zero";
		}
		const float magnitudeOfRhs = magnitude(rhs);
		if (magnitudeOfRhs == 0)
		{
			throw "Magnitude of 2nd parameter is zero. It cause dividing by zero";
		}

		return std::acos(dot(lhs, rhs) / magnitudeOfLhs / magnitudeOfRhs);
	}
}
