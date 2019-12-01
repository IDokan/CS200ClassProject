//		TEST_CASE(/* String */)
//		{
//			REQUIRE(/* Statement that I want to test */);
//		}
//		
//		// Template Issue
//		// At least, both float and int.
//		// Maybe double...
//
//		Float is Okay and make sure to test every function

#define CATCH_CONFIG_MAIN
#include "Catch/catch.hpp"
#include <matrix3.hpp>
#include <vector2.hpp>
#include <angles.hpp>


TEST_CASE("Vector2 Contructors")
{
	vector2<float> floatCtorTest{ 1.f };
	REQUIRE(floatCtorTest.x == 1.f);
	REQUIRE(floatCtorTest.y == 1.f);
	vector2<float> floatCtorTest2{ 2.f, 3.f };
	REQUIRE(floatCtorTest2.x == 2.f);
	REQUIRE(floatCtorTest2.y == 3.f);

	vector2<int> intCtorTest{ 1 };
	REQUIRE(intCtorTest.x == 1);
	REQUIRE(intCtorTest.y == 1);
	vector2<int> intCtorTest2{ 34, 5 };
	REQUIRE(intCtorTest2.x == 34);
	REQUIRE(intCtorTest2.y == 5);
}

TEST_CASE("Vector2 Basic Operators")
{
	// Operator+
	vector2<float> floatAdditionTest1{ 1.f };
	vector2<float> floatAdditionTest2{ 1.f };
	vector2<float> floatAdditionAnswer{ 2.f };
	REQUIRE((floatAdditionTest1 + floatAdditionTest2) == floatAdditionAnswer);

	vector2<float> floatAdditionTest3{ -1.f };
	vector2<float> floatAdditionAnswer2{ 0.f };
	REQUIRE((floatAdditionTest1 + floatAdditionTest3) == floatAdditionAnswer2);



	// Operator-
	vector2<float> floatSubtractionTest1{ 1.f };
	vector2<float> floatSubtractionTest2{ 1.f };
	vector2<float> floatSubtractionAnswer{ 0.f };
	REQUIRE((floatSubtractionTest1 - floatSubtractionTest2) == floatSubtractionAnswer);

	vector2<float> floatSubtractionTest3{ -3.f };
	vector2<float> floatSubtractionAnswer2{ 4.f };
	REQUIRE((floatSubtractionTest1 - floatSubtractionTest3) == floatSubtractionAnswer2);

	// Operator*
	vector2<float> floatMultiplicationTest1{ 2.f };
	vector2<float> floatMultiplicationTest2{ 5.f };
	vector2<float> floatMultiplicationAnswer{ 10.f };
	REQUIRE((floatMultiplicationTest1 * floatMultiplicationTest2) == floatMultiplicationAnswer);

	vector2<float> multipleWithFloatTest{ 2.f };
	float scaler{ 3.f };
	vector2<float> multipleWithFloatAnswer{ 6.f };
	REQUIRE((multipleWithFloatTest * scaler) == multipleWithFloatAnswer);

	// operator/
	vector2<float> divideWithFloatTest{ 10.f };
	float divisor{ 2.f };
	vector2<float> divideWithFloatAnswer{ 5.f };
	REQUIRE((divideWithFloatTest / divisor) == divideWithFloatAnswer);

	// unary operator -
	vector2<float> flipTest{ -5.f };
	vector2<float> flipAnswer{ 5.f };
	REQUIRE(-flipTest == flipAnswer);

	// operator ==
	vector2<float> equalTest{ 1.f };
	bool isEqual = (equalTest == equalTest);
	REQUIRE(isEqual == true);

	// operator !=
	vector2<float> notEqualTest{ 10.f };
	vector2<float> notEqualTest2{ 302.f };
	bool isNotEqual = (notEqualTest != notEqualTest2);
	REQUIRE(isNotEqual == true);
}

TEST_CASE("Vector2 Advanced Functions")
{
	// dot
	vector2<float> dotTest1{ 2.f, 3.f };
	vector2<float> dotTest2{ 4.f, 5.f };
	float dotResult{23.f};
	REQUIRE(dot(dotTest1, dotTest2) == dotResult);

	// perpendicularTo
	vector2<float> perpendicularTest{ 2.f, 10.f };
	vector2<float> perpendicularAnswer{ -10.f, 2.f };
	REQUIRE(perpendicularTo(perpendicularTest) == perpendicularAnswer);

	vector2<float> perpendicularTest2{ 1.f, 0.f };
	vector2<float> perpendicularAnswer2{ -0.f, 1.f };
	REQUIRE(perpendicularTo(perpendicularTest2) == perpendicularAnswer2);

	// magnitudeSquared
	vector2<float> magnitudeSquaredTest{ 10.f };
	float magnitudeSquaredAnswer{ 200.f };
	REQUIRE(magnitudeSquared(magnitudeSquaredTest) == magnitudeSquaredAnswer);

	vector2<float> magnitudeSquaredTest2{ 0.f };
	float magnitudeSquaredAnswer2{ 0.f };
	REQUIRE(magnitudeSquared(magnitudeSquaredTest2) == magnitudeSquaredAnswer2);

	vector2<float> magnitudeSquaredTest3{ 20.f, -20.f };
	float magnitudeSquaredAnswer3{ 800.f };
	REQUIRE(magnitudeSquared(magnitudeSquaredTest3) == magnitudeSquaredAnswer3);

	// magnitude
	vector2<float> magnitudeTest{ 3.f, 4.f };
	float magnitudeAnswer{ 5.f };
	REQUIRE(magnitude(magnitudeTest) == magnitudeAnswer);

	vector2<float> magnitudeTest2{ 20.f, 0.f };
	float magnitudeAnswer2{ 20.f };
	REQUIRE(magnitude(magnitudeTest2) == magnitudeAnswer2);

	// normalize
	vector2<float> normalizeTest{ 1.f };
	vector2<float> normalizeAnswer{ 1.f/sqrtf(2) };
	REQUIRE(normalize(normalizeTest) == normalizeAnswer);

	vector2<float> normalizeTest2{ 5.f, 0.f };
	vector2<float> normalizeAnswer2{ 1.f, 0.f };
	REQUIRE(normalize(normalizeTest2) == normalizeAnswer2);

	// distanceBetweenSquared
	vector2<float> distanceSqTest{ 1.f, 0.f };
	vector2<float> distanceSqTest2{ 5.f, 0.f };
	float distanceSqAnswer{ 16.f };
	REQUIRE(distanceBetweenSquared(distanceSqTest, distanceSqTest2) == distanceSqAnswer);

	vector2<float> distanceSqTest3{ 5.f, 10.f };
	vector2<float> distanceSqTest4{ 1.f, 9.f };
	float distanceSqAnswer2{ 17.f };
	REQUIRE(distanceBetweenSquared(distanceSqTest3, distanceSqTest4) == distanceSqAnswer2);

	// distanceBetween
	vector2<float> distanceTest{ 1.f, 5.f };
	vector2<float> distanceTest2{ 5.f, 1.f };
	float distanceAnswer{ 4.f * sqrtf(2.f) };
	REQUIRE(distanceBetween(distanceTest, distanceTest2) == distanceAnswer);

	vector2<float> distanceTest3{ 10.f, 13.f };
	vector2<float> distanceTest4{ 6.f, 10.f };
	float distanceAnswer2{ 5.f };
	REQUIRE(distanceBetween(distanceTest3, distanceTest4) == distanceAnswer2);

	// angleBetween
	float angle = angleBetween(vector2<float>(1.f, 0.f), vector2<float>(0.f, 1.f));
	REQUIRE(angle == MATH::PI / 2);

	// rotateBy
	vector2<float> rotateTest{ 1.f, 0.f };
	vector2<float> rotateAnswer{ -1.f, 0.f };
	REQUIRE(rotateBy(MATH::PI, rotateTest) == rotateAnswer);

	vector2<float> rotateTest2{ 0.f, 1.f };
	vector2<float> rotateAnswer2{ -1.f, 0.f };
	REQUIRE(rotateBy(MATH::HALF_PI, rotateTest2) == rotateAnswer);
}

TEST_CASE("Vector3 Constructors")
{
	// Float Constructor
	vector3<float> floatCtorTest{ 1.f };
	REQUIRE(floatCtorTest.x == 1.f);
	REQUIRE(floatCtorTest.y == 1.f);
	REQUIRE(floatCtorTest.z == 1.f);
	vector3<float> floatCtorTest2{ 10.f, 20.f, 30.f };
	REQUIRE(floatCtorTest2.x == 10.f);
	REQUIRE(floatCtorTest2.y == 20.f);
	REQUIRE(floatCtorTest2.z == 30.f);
	vector3<float> floatCtorTest3{ floatCtorTest2 };
	REQUIRE(floatCtorTest3.x == 10.f);
	REQUIRE(floatCtorTest3.y == 20.f);
	REQUIRE(floatCtorTest3.z == 30.f);
	vector3<float> floatCtorTest4{ vector3{40.f, 50.f, 60.f} };
	REQUIRE(floatCtorTest4.x == 40.f);
	REQUIRE(floatCtorTest4.y == 50.f);
	REQUIRE(floatCtorTest4.z == 60.f);

	// integer constructor
	vector3<int> intCtorTest{ 1 };
	REQUIRE(intCtorTest.x == 1);
	REQUIRE(intCtorTest.y == 1);
	REQUIRE(intCtorTest.z == 1);

	vector3<int> intCtorTest2{ 2, 3, 4 };
	REQUIRE(intCtorTest2.x == 2);
	REQUIRE(intCtorTest2.y == 3);
	REQUIRE(intCtorTest2.z == 4);
}

TEST_CASE("Vector3 Basic Operations")
{
	
}