/*	sinil.gang		rtd99062@gmail.com
 *	vector2.cpp
 *	Source file for vector2
 *	CS200 Class Project
 */

#include <vector2.hpp>
#include <cmath>		// for std::abs(), std::cos(), std::sin(), std::sqrt(), std::acos()
#include <limits>			// for std::numeric_limits<float>::epsilon()

namespace Graphics
{
	template <typename T>
	vector2<T> operator-(const vector2<T>& v) noexcept
	{
		return vector2<T>(-v.x, -v.y);
	}

	template <typename T>
	vector2<T> operator+(const vector2<T>& lhs, const vector2<T>& rhs) noexcept
	{
		return vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	template <typename T>
	vector2<T> operator-(const vector2<T>& lhs, const vector2<T>& rhs) noexcept
	{
		return vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	template <typename T>
	vector2<T> operator*(const vector2<T>& lhs, float scale) noexcept
	{
		return vector2<T>(lhs.x * scale, lhs.y * scale);
	}

	template <typename T>
	vector2<T> operator/(const vector2<T>& v, float divisor)
	{
		if (divisor == 0)
		{
			throw "Divided by 0";
		}
		return vector2<T>(v.x / divisor, v.y / divisor);
	}

	template <typename T>
	bool operator==(const vector2<T>& lhs, const vector2<T>& rhs) noexcept
	{
		return (
			std::abs(lhs.x - rhs.x) <= std::numeric_limits<T>::epsilon() &&
			std::abs(lhs.y - rhs.y) <= std::numeric_limits<T>::epsilon()
			);
	}

	template <typename T>
	T dot(vector2<T> lhs, vector2<T> rhs) noexcept
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	template <typename T>
	vector2<T> perpendicularTo(vector2<T> vector) noexcept
	{
		return vector2<T>(-vector.y, vector.x);
	}

	template <typename T>
	T magnitudeSquared(vector2<T> vector) noexcept
	{
		return dot(vector, vector);
	}

	template <typename T>
	float magnitude(vector2<T> vector) noexcept
	{
		return std::sqrt(magnitudeSquared(vector));
	}

	template <typename T>
	vector2<T> normalize(vector2<T> vector) noexcept
	{
		return vector / magnitude(vector);
	}

	template <typename T>
	T distanceBetweenSquared(vector2<T> lhs, vector2<T> rhs) noexcept
	{
		return magnitudeSquared(lhs - rhs);
	}

	template <typename T>
	float distanceBetween(vector2<T> lhs, vector2<T> rhs) noexcept
	{
		return std::sqrt(distanceBetweenSquared(lhs, rhs));
	}

	template <typename T>
	float angleBetween(vector2<T> lhs, vector2<T> rhs)
	{
		const float magnitudeOfLhs = magnitude(lhs);
		if (magnitudeOfLhs == 0)
		{
			throw "Magnitude of 1st parameter is zero. It cause dividing by zero";
		}
		const float magnitudeOfRhs = magnitude(rhs);
		if (magnitudeOfRhs)
		{
			throw "Magnitude of 2nd parameter is zero. It cause dividing by zero";
		}

		return std::acos(dot(lhs, rhs) / magnitudeOfLhs / magnitudeOfRhs);
	}

	template <typename T>
	vector2<T> rotateBy(float angleInRadians, vector2<T> vector2) noexcept
	{
		const float cos = std::cos(angleInRadians);
		const float sin = std::sin(angleInRadians);
		return vector2(
			cos*vector2.x - sin * vector2.y,
			sin*vector2.x + cos * vector2.y
		);
	}
}
