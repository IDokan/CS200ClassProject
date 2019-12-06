/*	sinil.gang		rtd99062@gmail.com
 *	vector3.cpp
 *	Source file for vector3
 *	CS200 Class Project
 */
#pragma once


	template <typename T>
	constexpr vector3<T> operator-(const vector3<T>& v) noexcept
	{
		return vector3(-v.x, -v.y, -v.z);
	}

	template <typename T>
	constexpr vector3<T> operator+(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}

	template <typename T>
	constexpr vector3<T> operator-(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	template <typename T>
	constexpr vector3<T> operator*(const vector3<T>& v, float scale) noexcept
	{
		return vector3(v.x * scale, v.y * scale, v.z * scale);
	}

	template <typename T>
	constexpr vector3<T> operator*(float scale, const vector3<T>& v) noexcept
	{
		return v * scale;
	}

	template <typename T>
	constexpr vector3<T> operator/(const vector3<T>& v, float divisor)
	{
		if (divisor == 0)
		{
			throw "Divided by Zero";
		}
		return vector3(v.x / divisor, v.y / divisor, v.z / divisor);
	}

	template <typename T>
	constexpr bool operator==(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return (
			std::abs(lhs.x - rhs.x) <= std::numeric_limits<T>::epsilon() &&
			std::abs(lhs.y - rhs.y) <= std::numeric_limits<T>::epsilon() &&
			std::abs(lhs.z - rhs.z) <= std::numeric_limits<T>::epsilon()
			);
	}


	template <typename T>
	constexpr bool operator!=(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return !(lhs == rhs);
	}

	template <typename T>
	constexpr T dot(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	template <typename T>
	constexpr vector3<T> cross(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return vector3(lhs.y * rhs.z - lhs.z * rhs.y, -(lhs.x * rhs.z - lhs.z * rhs.x), lhs.x * rhs.y - lhs.y * rhs.x);
	}

	template <typename T>
	constexpr T magnitudeSquared(const vector3<T>& lhs) noexcept
	{
		return dot(lhs, lhs);
	}

	template <typename T>
	constexpr float magnitude(const vector3<T>& lhs) noexcept
	{
		return std::sqrt(magnitudeSquared(lhs));
	}

	template <typename T>
	constexpr vector3<T> normalize(const vector3<T>& lhs) noexcept
	{
		return lhs / magnitude(lhs);
	}

	template <typename T>
	constexpr T distanceBetweenSquared(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return magnitudeSquared(lhs - rhs);
	}

	template <typename T>
	constexpr float distanceBetween(const vector3<T>& lhs, const vector3<T>& rhs) noexcept
	{
		return std::sqrt(distanceBetweenSquared(lhs, rhs));
	}

	template <typename T>
	constexpr float angleBetween(const vector3<T>& lhs, const vector3<T>& rhs)
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