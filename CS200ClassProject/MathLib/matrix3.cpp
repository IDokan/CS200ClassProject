/*	sinil.gang		rtd99062@gmail.com
 *	matrix3.cpp
 *	Source file for matrix3
 *	CS200 Class Project
 */
#include <matrix3.hpp>
#include <angles.hpp>
#include <vector2.hpp>
#include <limits>

namespace Graphics
{
	template <typename T>
	T matrix3<T>::operator()(int column, int row) const
	{
		return elements(column, row);
	}

	template <typename T>
	T& matrix3<T>::operator()(int column, int row)
	{
		if (column < 0 || column >= 3)
		{
			throw "Column calls invalidation";
		}
		if (row < 0 || row >= 3)
		{
			throw "Row calls invalidation";
		}
		return elements[column][row];
	}

	template <typename T>
	matrix3<T> operator*(const matrix3<T>& m1, const matrix3<T>& m2) noexcept
	{
		return matrix3(
			m1(0, 0) * m2(0, 0) + m1(1, 0) * m2(0, 1) + m1(2, 0) * m2(0, 2),
			m1(0, 1) * m2(0, 0) + m1(1, 1) * m2(0, 1) + m1(2, 1) * m2(0, 2),
			m1(0, 2) * m2(0, 0) + m1(1, 2) * m2(0, 1) + m1(2, 2) * m2(0, 2),
			m1(0, 0) * m2(1, 0) + m1(1, 0) * m2(1, 1) + m1(2, 0) * m2(1, 2),
			m1(0, 1) * m2(1, 0) + m1(1, 1) * m2(1, 1) + m1(2, 1) * m2(1, 2),
			m1(0, 2) * m2(1, 0) + m1(1, 2) * m2(1, 1) + m1(2, 2) * m2(1, 2),
			m1(0, 0) * m2(2, 0) + m1(1, 0) * m2(2, 1) + m1(2, 0) * m2(2, 2),
			m1(0, 1) * m2(2, 0) + m1(1, 1) * m2(2, 1) + m1(2, 1) * m2(2, 2),
			m1(0, 2) * m2(2, 0) + m1(1, 2) * m2(2, 1) + m1(2, 2) * m2(2, 2));
	}

	template <typename T>
	void operator*=(matrix3<T>& m1, const matrix3<T>& m2) noexcept
	{
		m1 = m1 * m2;
	}

	template <typename T>
	vector3<T> operator*(const matrix3<T>& m, vector3<T> v) noexcept
	{
		return vector3<T>(
			m(0, 0) * v.x + m(1, 0) * v.y + m(2, 0) * v.z,
			m(0, 1) * v.x + m(1, 1) * v.y + m(2, 1) * v.z,
			m(0, 2) * v.x + m(1, 2) * v.y + m(2, 2) * v.z);
	}

	template <typename T>
	matrix3<T> MATRIX3::transpose(const matrix3<T>& m) noexcept
	{
		return matrix3<T>(
			m(0, 0), m(1, 0), m(2, 0),
			m(0, 1), m(1, 1), m(2, 1),
			m(0, 2), m(1, 2), m(2, 2));
	}

	matrix3<float> MATRIX3::build_rotation(float angleInRadians) noexcept
	{
		// Return specific matrix at specific parameter without calculation.
		if (angleInRadians <= std::numeric_limits<float>::epsilon())
		{
			return build_identity<float>();
		}
		else if (angleInRadians <= HALF_PI + std::numeric_limits<float>::epsilon() &&
			angleInRadians >= HALF_PI - std::numeric_limits<float>::epsilon())
		{
			return matrix3<float>(
				0, 1, 0,
				-1, 0, 0,
				0, 0, 1);
		}
		else if (angleInRadians <= PI + std::numeric_limits<float>::epsilon() &&
			angleInRadians >= PI - std::numeric_limits<float>::epsilon())
		{
			return matrix3<float>(
				-1, 0, 0,
				0, -1, 0,
				0, 0, 1);
		}
		else if (angleInRadians <= PI + HALF_PI + std::numeric_limits<float>::epsilon() &&
			angleInRadians >= PI + HALF_PI - std::numeric_limits<float>::epsilon())
		{
			return matrix3<float>(
				0, -1, 0,
				1, 0, 0,
				0, 0, 1);
		}

		const float cos = std::cos(angleInRadians);
		const float sin = std::sin(angleInRadians);

		// If not, calculate followed parameter.
		return matrix3<float>(
			cos, sin, 0,
			-sin, cos, 0,
			0, 0, 1);
	}

	template <typename T>
	matrix3<T> MATRIX3::build_identity() noexcept
	{
		return matrix3<T>(
			1, 0, 0,
			0, 1, 0,
			0, 0, 1);
	}

	template <typename T>
	matrix3<T> MATRIX3::build_scale(float scale_x, float scale_y) noexcept
	{
		return matrix3<T>(
			scale_x, 0, 0,
			0, scale_y, 0,
			0, 0, 1);
	}

	template <typename T>
	matrix3<T> MATRIX3::build_scale(float scale) noexcept
	{
		return MATRIX3::build_scale(scale, scale);
	}

	template <typename T>
	matrix3<T> MATRIX3::build_scale(const vector2<T>& scale) noexcept
	{
		return MATRIX3::build_scale(scale.x, scale.y);
	}

	template <typename T>
	matrix3<T> MATRIX3::build_translation(float translate_x, float translate_y) noexcept
	{
		return matrix3<T>(
			1, 0, 0,
			0, 1, 0,
			translate_x, translate_y, 1);
	}

	template <typename T>
	matrix3<T> MATRIX3::build_translation(const vector2<T>& translation) noexcept
	{
		return MATRIX3::build_translation(translation.x, translation.y);
	}
}
