/*	sinil.gang		rtd99062@gmail.com
 *	matrix3.hpp
 *	Header file for matrix3
 *	CS200 Class Project
 */
#pragma once
#include <vector3.hpp>
#pragma warning(push)
#pragma warning(disable : 4201)	// warning C4201 : nameless struct / union

	template<typename T>
	struct [[nodiscard]] matrix3
	{
		union
		{
			T elements[3][3];
			struct
			{
				vector3<T> column0;
				vector3<T> column1;
				vector3<T> column2;
			};
		};

	constexpr matrix3() noexcept :column0(), column1(), column2() {};
	constexpr matrix3(vector3<T> firstColumn, vector3<T> secondColumn, vector3<T> thirdColumn) noexcept : column0(firstColumn), column1(secondColumn), column2(thirdColumn) {};
	constexpr matrix3(T column0_row0, T column0_row1, T column0_row2, T column1_row0, T column1_row1,
		T column1_row2, T column2_row0, T column2_row1, T column2_row2) noexcept
		: column0(column0_row0, column0_row1, column0_row2),
		column1(column1_row0, column1_row1, column1_row2),
		column2(column2_row0, column2_row1, column2_row2) {};

	constexpr T  operator()(int column, int row) const;
	constexpr T& operator()(int column, int row);
	};

	template<typename T>
	constexpr matrix3<T> operator*(const matrix3<T>& m1, const matrix3<T>& m2) noexcept;
	template<typename T>
	constexpr void    operator*=(matrix3<T>& m1, const matrix3<T>& m2) noexcept;
	template<typename T>
	constexpr vector3<T> operator*(const matrix3<T>& m, vector3<T> v) noexcept;
	template<typename T>
	constexpr bool operator==(const matrix3<T>& lhs, const matrix3 <T>& rhs);

	template<typename>
	struct vector2;
	namespace MATRIX3
	{
		template<typename T>
		constexpr matrix3<T> transpose(const matrix3<T>& m) noexcept;
		constexpr matrix3<float> build_rotation(float angle_in_radians) noexcept;
		template<typename T>
		constexpr matrix3<T> build_identity() noexcept;
		template<typename T>
		constexpr matrix3<T> build_scale(float scale_x, float scale_y) noexcept;
		template<typename T>
		constexpr matrix3<T> build_scale(float scale) noexcept;
		template<typename T>
		constexpr matrix3<T> build_scale(const vector2<T>& scale) noexcept;
		template<typename T>
		constexpr matrix3<T> build_translation(float translate_x, float translate_y) noexcept;
		template<typename T>
		constexpr matrix3<T> build_translation(const vector2<T>& translation) noexcept;
	}
#pragma warning(pop)

#include <angles.hpp>
#include <limits>		// std::numeric_limits<float>::epsilon()
#include <cmath>		// std::cos(), std::sin()
#include <matrix3.inl>