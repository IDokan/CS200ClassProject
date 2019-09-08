/*	sinil.gang		rtd99062@gmail.com
 *	vector3.hpp
 *	Header file for vector3
 *	CS200 Class Project
 */
#pragma once
#pragma warning(push)
#pragma warning(disable : 4201)	// warning C4201 : nameless struct / union

namespace Graphics
{
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

		vector3<T>() noexcept = default;
		explicit vector3<T>(T repeatedFloat) noexcept : x(repeatedFloat), y(repeatedFloat), z(repeatedFloat) {};
		vector3<T>(T x, T y, T z) : x(x), y(y), z(z) {};
	};

	template<typename T>
	inline void operator+=(vector3<T> & v, const vector3<T> & addingVector) noexcept { v = v + addingVector; };
	template<typename T>
	inline void operator-=(vector3<T> & v, const vector3<T> & subtractingVector) noexcept { v = v - subtractingVector; };
	template<typename T>
	inline void operator*=(vector3<T> & v, float scale) noexcept { v = v * scale; };
	template<typename T>
	inline void operator/=(vector3<T> & v, float divisor) { v = v / divisor; };

	template<typename T>
	vector3<T> operator-(const vector3<T> & v) noexcept;

	template<typename T>
	vector3<T> operator+(const vector3<T> & lhs, const vector3<T> & rhs) noexcept;
	template<typename T>
	vector3<T> operator-(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	vector3<T> operator*(const vector3<T> & v, float scale) noexcept;
	template<typename T>
	vector3<T> operator*(float scale, const vector3<T> & v) noexcept;
	template<typename T>
	vector3<T> operator/(const vector3<T> & v, float divisor);

	template<typename T>
	[[nodiscard]] bool operator==(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	[[nodiscard]] bool operator!=(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;


	template<typename T>
	[[nodiscard]] T dot(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	vector3<T>             cross(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	[[nodiscard]] T magnitude_squared(const vector3<T>& lhs) noexcept;
	template<typename T>
	[[nodiscard]] float magnitude(const vector3<T>& lhs) noexcept;
	template<typename T>
	vector3<T>             normalize(const vector3<T>& lhs) noexcept;
	template<typename T>
	[[nodiscard]] T distance_between_squared(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	[[nodiscard]] float distance_between(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
	template<typename T>
	[[nodiscard]] float angle_between(const vector3<T>& lhs, const vector3<T>& rhs) noexcept;
}

#pragma warning(pop)