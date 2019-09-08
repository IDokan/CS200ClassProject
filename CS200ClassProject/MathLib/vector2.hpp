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

	vector2() noexcept = default;
	explicit vector2(T repeatedFloat) noexcept : x(repeatedFloat), y(repeatedFloat) {};
	vector2(T x, T y) noexcept : x(x), y(y) {};
	};

	template <typename T>
	inline void operator+=(vector2<T>& v, const vector2<T>& addingVector) noexcept { v = v + addingVector; };
	template <typename T>
	inline void operator-=(vector2<T>& v, const vector2<T>& subtractingVector) noexcept { v = v - subtractingVector; };
	template <typename T>
	inline void operator*=(vector2<T>& v, float scale) noexcept { v = v * scale; };
	template <typename T>
	inline void operator/=(vector2<T>& v, float divisor) noexcept { v = v / divisor; };

	template <typename T>
	inline vector2<T> operator-(const vector2<T>& v) noexcept;

	template <typename T>
	vector2<T> operator+(const vector2<T>& lhs, const vector2<T>& rhs) noexcept;
	template <typename T>
	vector2<T> operator-(const vector2<T>& lhs, const vector2<T>& rhs) noexcept;
	template <typename T>
	vector2<T> operator*(const vector2<T>& lhs, float scale) noexcept;
	template <typename T>
	inline vector2<T> operator*(float scale, const vector2<T>& rhs) noexcept { return rhs * scale; };
	template <typename T>
	vector2<T> operator/(const vector2<T>& v, float divisor);

	template<typename T>
	[[nodiscard]] bool operator==(const vector2<T>& lhs, const vector2<T>& rhs) noexcept;
	template<typename T>
	[[nodiscard]] inline bool operator!=(const vector2<T>& lhs, const vector2<T>& rhs) noexcept { return !(lhs == rhs); };

	template<typename T>
	[[nodiscard]] T dot(vector2<T> lhs, vector2<T> rhs) noexcept;
	template<typename T>
	vector2<T> perpendicularTo(vector2<T> vector) noexcept;
	template<typename T>
	[[nodiscard]] T magnitudeSquared(vector2<T> vector) noexcept;
	template<typename T>
	[[nodiscard]] float magnitude(vector2<T> vector) noexcept;
	template<typename T>
	vector2<T> normalize(vector2<T> vector) noexcept;
	template<typename T>
	[[nodiscard]] T distanceBetweenSquared(vector2<T> lhs, vector2<T> rhs) noexcept;
	template<typename T>
	[[nodiscard]] float distanceBetween(vector2<T> lhs, vector2<T> rhs) noexcept;
	template<typename T>
	[[nodiscard]] float angleBetween(vector2<T> lhs, vector2<T> rhs);
	template<typename T>
	vector2<T> rotateBy(float angleInRadians, vector2<T> vector2) noexcept;
}

#pragma warning(pop)