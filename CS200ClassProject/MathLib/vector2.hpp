/*	sinil.gang		rtd99062@gmail.com
 *	vector2.hpp
 *	Header file for vector2
 *	CS200 Class Project
 */
#pragma once
#pragma warning(push)
#pragma warning(disable : 4201)	// warning C4201 : nameless struct / union

namespace Graphics
{
	template <typename T>
	struct [[nodiscard]] vector2
	{
		union
		{
			struct
			{
				T x, y;
			};
			struct
			{
				T u, v;
			};
			struct
			{
				T width, height;
			};
			T elements[2];
		};

	constexpr vector2() noexcept = default;
	constexpr explicit vector2(T repeatedFloat) noexcept : x(repeatedFloat), y(repeatedFloat) {};
	constexpr vector2(T x, T y) noexcept : x(x), y(y) {};
	};

	template <typename T>
	constexpr void operator+=(vector2<T>& v, const vector2<T>& addingVector) noexcept { v = v + addingVector; };
	template <typename T>
	constexpr void operator-=(vector2<T>& v, const vector2<T>& subtractingVector) noexcept { v = v - subtractingVector; };
	template <typename T>
	constexpr void operator*=(vector2<T>& v, float scale) noexcept { v = v * scale; };
	template <typename T>
	constexpr void operator/=(vector2<T>& v, float divisor) noexcept { v = v / divisor; };

	template <typename T>
	constexpr vector2<T> operator-(const vector2<T>& v) noexcept;

	template <typename T>
	constexpr vector2<T> operator+(const vector2<T>& lhs, const vector2<T>& rhs) noexcept;
	template <typename T>
	constexpr vector2<T> operator-(const vector2<T>& lhs, const vector2<T>& rhs) noexcept;
	template <typename T>
	constexpr vector2<T> operator*(const vector2<T>& lhs, float scale) noexcept;
	template <typename T>
	constexpr  vector2<T> operator*(float scale, const vector2<T>& rhs) noexcept { return rhs * scale; };
	template <typename T>
	constexpr vector2<T> operator/(const vector2<T>& v, float divisor);

	template<typename T>
	constexpr bool operator==(const vector2<T>& lhs, const vector2<T>& rhs) noexcept;
	template<typename T>
	constexpr bool operator!=(const vector2<T>& lhs, const vector2<T>& rhs) noexcept { return !(lhs == rhs); };

	template<typename T>
	constexpr T dot(vector2<T> lhs, vector2<T> rhs) noexcept;
	template<typename T>
	constexpr vector2<T> perpendicularTo(vector2<T> vector) noexcept;
	template<typename T>
	constexpr T magnitudeSquared(vector2<T> vector) noexcept;
	template<typename T>
	constexpr float magnitude(vector2<T> vector) noexcept;
	template<typename T>
	constexpr vector2<T> normalize(vector2<T> vector) noexcept;
	template<typename T>
	constexpr T distanceBetweenSquared(vector2<T> lhs, vector2<T> rhs) noexcept;
	template<typename T>
	constexpr float distanceBetween(vector2<T> lhs, vector2<T> rhs) noexcept;
	template<typename T>
	constexpr float angleBetween(vector2<T> lhs, vector2<T> rhs);
	template<typename T>
	constexpr vector2<T> rotateBy(float angleInRadians, vector2<T> vector2) noexcept;
}

#pragma warning(pop)

#include <cmath>		// for std::abs(), std::cos(), std::sin(), std::sqrt(), std::acos()
#include <limits>			// for std::numeric_limits<float>::epsilon()
#include <vector2.inl>