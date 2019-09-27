/*	sinil.gang		rtd99062@gmail.com
 *	angles.hpp
 *	Header file for angles
 *	CS200 Class Project
 */
#pragma once

namespace MATH
{
	constexpr float PI = 3.1415926535897932384626433832795f;
	constexpr float HALF_PI = PI / 2.0f;
	constexpr float QUARTER_PI = PI / 4.0f;
	constexpr float TWO_PI = 2.0f * PI;

	constexpr float toRadians(float angleInDegrees) { return angleInDegrees * PI / 180.0f; }
	constexpr float toDegrees(float angleInRadians) { return angleInRadians * 180.0f / PI; }
}