/*	sinil.gang		rtd99062@gmail.com
 *	vector3.hpp
 *	Header file for vector3
 *	CS200 Class Project
 */
#pragma once
#pragma warning(push)
#pragma warning(disable : 4201)	// warning C4201 : nameless struct / union

	template<typename T>
	struct vector3
	{
		union
		{
			struct
			{
				T x, y, z;
			};
			struct
			{
				T r, g, b;
			};
			struct
			{
				T width, height, depth;
			};
			T elements[3];
		};

		constexpr vector3<T>() noexcept :vector3<T>(static_cast<T>(0)){};
		constexpr explicit vector3<T>(T repeatedFloat) noexcept : x(repeatedFloat), y(repeatedFloat), z(repeatedFloat) {};
		constexpr vector3<T>(T x, T y, T z) : x(x), y(y), z(z) {};
	};

	template<typename T>
	constexpr void operator+=(vector3<T> & v, const vector3<T> & addingVector) noexcept { v = v + addingVector; };
	template<typename T>
	constexpr void operator-=(vector3<T> & v, const vector3<T> & subtractingVector) noexcept { v = v - subtractingVector; };
	template<typename T>
	constexpr void operator*=(vector3<T> & v, float scale) noexcept { v = v * scale; };
	template<typename T>
	constexpr void operator/=(vector3<T> & v, float divisor) { v = v / divisor; };

	template<typename T>
	constexpr vector3<T> operator-(const vector3<T> & v) noexcept;

	template<typename T>
	constexpr vector3<T> operator+(const vector3<T> & lhs, const vector3<T> & rhs) noexcept;
	template<typename T>
	constexpr vector3<T> operator-(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	constexpr vector3<T> operator*(const vector3<T> & v, float scale) noexcept;
	template<typename T>
	constexpr vector3<T> operator*(float scale, const vector3<T> & v) noexcept;
	template<typename T>
	constexpr vector3<T> operator/(const vector3<T> & v, float divisor);

	template<typename T>
	constexpr bool operator==(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	constexpr bool operator!=(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;


	template<typename T>
	constexpr T dot(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	constexpr vector3<T>             cross(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	constexpr T magnitudeSquared(const vector3<T>& lhs) noexcept;
	template<typename T>
	constexpr float magnitude(const vector3<T>& lhs) noexcept;
	template<typename T>
	constexpr vector3<T>             normalize(const vector3<T>& lhs) noexcept;
	template<typename T>
	constexpr T distanceBetweenSquared(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	constexpr float distanceBetween(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	constexpr float angleBetween(const vector3<T>& lhs, const vector3<T>& rhs);

#pragma warning(pop)

#include <limits>		// std::numeric_limits<float>::epsilon()
#include <cmath>	// for std::sqrt(), std::abs(), and std::acos()
#include <vector3.inl>