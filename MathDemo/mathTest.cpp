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
	vector2<float> floatCtorNonArgumentTest{};
	REQUIRE(floatCtorNonArgumentTest.x == 0.f);
	REQUIRE(floatCtorNonArgumentTest.y == 0.f);
	vector2<float> floatCtorTest{ 1.f };
	REQUIRE(floatCtorTest.x == 1.f);
	REQUIRE(floatCtorTest.y == 1.f);
	vector2<float> floatCtorTest2{ 2.f, 3.f };
	REQUIRE(floatCtorTest2.x == 2.f);
	REQUIRE(floatCtorTest2.y == 3.f);

	vector2<float> intCtorNonArgumentTest{};
	REQUIRE(intCtorNonArgumentTest.x == 0);
	REQUIRE(intCtorNonArgumentTest.y == 0);
	vector2<int> intCtorTest{ 1 };
	REQUIRE(intCtorTest.x == 1);
	REQUIRE(intCtorTest.y == 1);
	vector2<int> intCtorTest2{ 34, 5 };
	REQUIRE(intCtorTest2.x == 34);
	REQUIRE(intCtorTest2.y == 5);
}

TEST_CASE("Vector2 Assignment Operators")
{
	// Assignment Operator+
	vector2<float> floatAdditionTest1{ 1.f };
	floatAdditionTest1 += vector2<float>{ 1.f };
	vector2<float> floatAdditionAnswer{ 2.f };
	REQUIRE((floatAdditionTest1) == floatAdditionAnswer);



	// Assignment Operator-
	vector2<float> floatSubtractionTest1{ 1.f };
	floatSubtractionTest1 -= vector2<float> { 1.f };
	vector2<float> floatSubtractionAnswer{ 0.f };
	REQUIRE((floatSubtractionTest1) == floatSubtractionAnswer);

	vector2<float> floatSubtractionTest2{ 1.f };
	floatSubtractionTest2 -= vector2<float> { -3.f };
	vector2<float> floatSubtractionAnswer2{ 4.f };
	REQUIRE((floatSubtractionTest2) == floatSubtractionAnswer2);


	// Assignment Operator*
	vector2<float> multipleWithFloatTest{ 2.f };
	multipleWithFloatTest *= float{ 3.f };
	vector2<float> multipleWithFloatAnswer{ 6.f };
	REQUIRE((multipleWithFloatTest) == multipleWithFloatAnswer);

	// Assignment Operator/
	vector2<float> divideWithFloatTest{ 10.f };
	divideWithFloatTest /= float { 2.f };
	vector2<float> divideWithFloatAnswer{ 5.f };
	REQUIRE((divideWithFloatTest) == divideWithFloatAnswer);
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

	vector2<float> multipleWithFloatTest2{ 3.f };
	float scaler2{ 5.f };
	vector2<float> multipleWithFloatAnswer2{ 15.f };
	REQUIRE((scaler2 * multipleWithFloatTest2) == multipleWithFloatAnswer2);

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
	vector3<float> floatCtorTestNonArgument{ };
	REQUIRE(floatCtorTestNonArgument.x == 0.f);
	REQUIRE(floatCtorTestNonArgument.y == 0.f);
	REQUIRE(floatCtorTestNonArgument.z == 0.f);
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

TEST_CASE("Vector3 Assignment Operations")
{
	// Assignment Operator+
	vector3<float> floatAdditionTest1{ 1.f };
	floatAdditionTest1 += vector3<float>{ 1.f };
	vector3<float> floatAdditionAnswer{ 2.f };
	REQUIRE((floatAdditionTest1) == floatAdditionAnswer);

	floatAdditionTest1 += vector3<float> { -1.f };
	vector3<float> floatAdditionAnswer2{ 1.f };
	REQUIRE((floatAdditionTest1) == floatAdditionAnswer2);
	
	// Assignment Operator-
	vector3<float> floatSubtractionTest1{ 1.f };
	floatSubtractionTest1 -= vector3<float> { 1.f };
	vector3<float> floatSubtractionAnswer{ 0.f };
	REQUIRE((floatSubtractionTest1) == floatSubtractionAnswer);

	vector3<float> floatSubtractionTest2{ 1.f };
	floatSubtractionTest2 -= vector3<float> { -3.f };
	vector3<float> floatSubtractionAnswer2{ 4.f };
	REQUIRE((floatSubtractionTest2) == floatSubtractionAnswer2);
	
	// Assignment Operator*
	vector3<float> floatMultiplicationTest1{ 2.f };
	floatMultiplicationTest1 *= float {5.f };
	vector3<float> floatMultiplicationAnswer{ 10.f };
	REQUIRE((floatMultiplicationTest1) == floatMultiplicationAnswer);


	// Assignment operator/
	vector3<float> divideWithFloatTest{ 10.f };
	divideWithFloatTest /= float { 2.f };
	vector3<float> divideWithFloatAnswer{ 5.f };
	REQUIRE((divideWithFloatTest) == divideWithFloatAnswer);

}

TEST_CASE("Vector3 Basic Operations")
{
	// Operator+
	vector3<float> floatAdditionTest1{ 1.f };
	vector3<float> floatAdditionTest2{ 1.f };
	vector3<float> floatAdditionAnswer{ 2.f };
	REQUIRE((floatAdditionTest1 + floatAdditionTest2) == floatAdditionAnswer);

	vector3<float> floatAdditionTest3{ -1.f };
	vector3<float> floatAdditionAnswer2{ 0.f };
	REQUIRE((floatAdditionTest1 + floatAdditionTest3) == floatAdditionAnswer2);

	// Operator-
	vector3<float> floatSubtractionTest1{ 1.f };
	vector3<float> floatSubtractionTest2{ 1.f };
	vector3<float> floatSubtractionAnswer{ 0.f };
	REQUIRE((floatSubtractionTest1 - floatSubtractionTest2) == floatSubtractionAnswer);

	vector3<float> floatSubtractionTest3{ -3.f };
	vector3<float> floatSubtractionAnswer2{ 4.f };
	REQUIRE((floatSubtractionTest1 - floatSubtractionTest3) == floatSubtractionAnswer2);

	// Operator*
	vector3<float> floatMultiplicationTest1{ 2.f };
	const float scaler = 5.f;
	vector3<float> floatMultiplicationAnswer{ 10.f };
	REQUIRE((floatMultiplicationTest1 * scaler) == floatMultiplicationAnswer);

	vector3<float> floatMultiplicationTest2{ 2.f };
	float scaler2{ 3.f };
	vector3<float> floatMultiplicationAnswer2{ 6.f };
	REQUIRE((scaler2 * floatMultiplicationTest2) == floatMultiplicationAnswer2);

	// operator/
	vector3<float> divideWithFloatTest{ 10.f };
	float divisor{ 2.f };
	vector3<float> divideWithFloatAnswer{ 5.f };
	REQUIRE((divideWithFloatTest / divisor) == divideWithFloatAnswer);

	// unary operator -
	vector3<float> flipTest{ -5.f };
	vector3<float> flipAnswer{ 5.f };
	REQUIRE(-flipTest == flipAnswer);

	// operator ==
	vector3<float> equalTest{ 1.f };
	bool isEqual = (equalTest == equalTest);
	REQUIRE(isEqual == true);

	// operator !=
	vector3<float> notEqualTest{ 10.f };
	vector3<float> notEqualTest2{ 302.f };
	bool isNotEqual = (notEqualTest != notEqualTest2);
	REQUIRE(isNotEqual == true);
}

TEST_CASE("Vector3 Advanced Functions")
{
	// dot
	vector3<float> dot_test1{ 2.f, 3.f, 4.f };
	vector3<float> dot_test2{ 5.f, 6.f, 7.f };
	float dot_result{ 56 };
	REQUIRE(dot(dot_test1, dot_test2) == dot_result);

	// cross
	vector3<float> cross_test{ 1.f, 2.f, 3.f };
	vector3<float> cross_test2{ 0.f, 4.f, 10.f };
	vector3<float> cross_result{ 8.f, -10.f, 4.f };
	REQUIRE(cross(cross_test, cross_test2) == cross_result);

	// magnitudeSquared
	vector3<float> magnitudeSquaredTest{ 10.f };
	float magnitudeSquaredAnswer{ 300.f };
	REQUIRE(magnitudeSquared(magnitudeSquaredTest) == magnitudeSquaredAnswer);

	vector3<float> magnitudeSquaredTest2{ 0.f };
	float magnitudeSquaredAnswer2{ 0.f };
	REQUIRE(magnitudeSquared(magnitudeSquaredTest2) == magnitudeSquaredAnswer2);

	vector3<float> magnitudeSquaredTest3{ 20.f, -20.f, 40.f };
	float magnitudeSquaredAnswer3{ 2400.f };
	REQUIRE(magnitudeSquared(magnitudeSquaredTest3) == magnitudeSquaredAnswer3);

	// magnitude
	vector3<float> magnitudeTest{ 3.f, 4.f, 5.f };
	float magnitudeAnswer{ 5.f*sqrtf(2.f) };
	REQUIRE(magnitude(magnitudeTest) == magnitudeAnswer);

	vector3<float> magnitudeTest2{ 20.f, 0.f, 0.f };
	float magnitudeAnswer2{ 20.f };
	REQUIRE(magnitude(magnitudeTest2) == magnitudeAnswer2);

	vector3<float> magnitudeTest3{ 0.f, 20.f, 0.f };
	float magnitudeAnswer3{ 20.f };
	REQUIRE(magnitude(magnitudeTest3) == magnitudeAnswer3);

	vector3<float> magnitudeTest4{ 0.f, 0.f, 20.f };
	float magnitudeAnswer4{ 20.f };
	REQUIRE(magnitude(magnitudeTest4) == magnitudeAnswer4);



	// normalize
	vector3<float> normalizeTest{ 1.f };
	vector3<float> normalizeAnswer{ 1.f / sqrtf(3.f) };
	REQUIRE(normalize(normalizeTest) == normalizeAnswer);

	vector3<float> normalizeTest2{ 5.f, 0.f, 0.f };
	vector3<float> normalizeAnswer2{ 1.f, 0.f, 0.f };
	REQUIRE(normalize(normalizeTest2) == normalizeAnswer2);

	// distanceBetweenSquared
	vector3<float> distanceSqTest{ 0.f, 1.f, 0.f };
	vector3<float> distanceSqTest2{ 0.f, 5.f, 0.f };
	float distanceSqAnswer{ 16.f };
	REQUIRE(distanceBetweenSquared(distanceSqTest, distanceSqTest2) == distanceSqAnswer);

	vector3<float> distanceSqTest3{ 5.f, 10.f, 20.f };
	vector3<float> distanceSqTest4{ 1.f, 9.f, 10.f };
	float distanceSqAnswer2{ 117.f };
	REQUIRE(distanceBetweenSquared(distanceSqTest3, distanceSqTest4) == distanceSqAnswer2);

	// distanceBetween
	vector3<float> distanceTest{ 1.f, 5.f, 5.f };
	vector3<float> distanceTest2{ 5.f, 1.f, 9.f };
	float distanceAnswer{ 4.f * sqrtf(3.f) };
	REQUIRE(distanceBetween(distanceTest, distanceTest2) == distanceAnswer);

	vector3<float> distanceTest3{ 10.f, 13.f, 18.f };
	vector3<float> distanceTest4{ 6.f, 10.f, 13.f };
	float distanceAnswer2{ 5.f*sqrtf(2.f) };
	REQUIRE(distanceBetween(distanceTest3, distanceTest4) == distanceAnswer2);

	// angleBetween
	float angle = angleBetween(vector3<float>(1.f, 0.f, 0.f), vector3<float>(0.f, 1.f, 0.f));
	REQUIRE(angle == MATH::PI / 2);
}

TEST_CASE("Matrix Constructors")
{
	vector3<float> first = { 1.f,2.f,3.f };
	vector3<float> second = { 4.f,5.f,6.f };
	vector3<float> third = { 7.f,8.f,9.f };
	matrix3<float> ctor_test1(first, second, third);

	REQUIRE(ctor_test1.column0.x == 1.f);
	REQUIRE(ctor_test1.column0.y == 2.f);
	REQUIRE(ctor_test1.column0.z == 3.f);
								 
	REQUIRE(ctor_test1.column1.x == 4.f);
	REQUIRE(ctor_test1.column1.y == 5.f);
	REQUIRE(ctor_test1.column1.z == 6.f);
								 
	REQUIRE(ctor_test1.column2.x == 7.f);
	REQUIRE(ctor_test1.column2.y == 8.f);
	REQUIRE(ctor_test1.column2.z == 9.f);

	matrix3<float> ctor_test2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);

	REQUIRE(ctor_test2.column0.x == 1.f);
	REQUIRE(ctor_test2.column0.y == 2.f);
	REQUIRE(ctor_test2.column0.z == 3.f);
								 
	REQUIRE(ctor_test2.column1.x == 4.f);
	REQUIRE(ctor_test2.column1.y == 5.f);
	REQUIRE(ctor_test2.column1.z == 6.f);
								 
	REQUIRE(ctor_test2.column2.x == 7.f);
	REQUIRE(ctor_test2.column2.y == 8.f);
	REQUIRE(ctor_test2.column2.z == 9.f);
}

TEST_CASE("Matrix3 Basic Operations")
{
	// Operator ()
	matrix3<float> mat_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 0.f, -1.f);


	REQUIRE(mat_test(0, 0) == 1.f);
	REQUIRE(mat_test(0, 1) == 2.f);
	REQUIRE(mat_test(0, 2) == 3.f);
	REQUIRE(mat_test(1, 0) == 4.f);
	REQUIRE(mat_test(1, 1) == 5.f);
	REQUIRE(mat_test(1, 2) == 6.f);
	REQUIRE(mat_test(2, 0) == 7.f);
	REQUIRE(mat_test(2, 1) == 0.f);
	REQUIRE(mat_test(2, 2) == -1.f);

	// matrix3 operator*
	matrix3<float> mat_multiple_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	matrix3<float> mat_multiple_test2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	matrix3<float> mat_multiple_result = mat_multiple_test * mat_multiple_test2;

	matrix3<float> result(30.f, 36.f, 42.f, 66.f, 81.f, 96.f, 102.f, 126.f, 150.f);

	REQUIRE(mat_multiple_result == result);

	// arbitrary number calculations
	matrix3<float> mat_multiple_test3(1.f, 0.f, 3.f, -56.f, 88.f, -6.f, -14.f, 463.f, 9.f);
	matrix3<float> mat_multiple_test4(1.f, 0.f, -60.f, -4.f, 0.f, 0.f, 0.f, 73.f, 9.f);
	matrix3<float> mat_multiple_result2 = mat_multiple_test3 * mat_multiple_test4;

	matrix3<float> result2(841.f, -27780.f, -537.f, -4.f, 0.f, -12.f, -4214.f, 10591.f, -357.f);

	REQUIRE(mat_multiple_result2 == result2);

	// matrix3 operator*=
	matrix3<float> mat_multiple_assign_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	matrix3<float> mat_multiple_assign_test2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	mat_multiple_assign_test *= mat_multiple_assign_test2;

	matrix3<float> mat_multiple_assign_result(30.f, 36.f, 42.f, 66.f, 81.f, 96.f, 102.f, 126.f, 150.f);

	REQUIRE(mat_multiple_assign_test == mat_multiple_assign_result);

	matrix3<float> mat_multiple_assign_test3(1.f, 0.f, 3.f, -56.f, 88.f, -6.f, -14.f, 463.f, 9.f);
	matrix3<float> mat_multiple_assign_test4(1.f, 0.f, -60.f, -4.f, 0.f, 0.f, 0.f, 73.f, 9.f);
	mat_multiple_assign_test3 *= mat_multiple_assign_test4;

	matrix3<float> mat_multiple_assign_result2(841.f, -27780.f, -537.f, -4.f, 0.f, -12.f, -4214.f, 10591.f, -357.f);

	REQUIRE(mat_multiple_assign_test3 == mat_multiple_assign_result2);

	// matrix3 operator==
	matrix3<float> mat_equal_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	REQUIRE(mat_equal_test == mat_equal_test);

	// matrix3 operator* with vec
	matrix3<float> mat_multiple_vec_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	vector3<float> mat_multiple_vec_test2(1.f, 2.f, 3.f);
	vector3<float> my_multiple_vec_result = mat_multiple_vec_test * mat_multiple_vec_test2;

	vector3<float> multiple_vec_result = { 30.f, 36.f, 42.f };

	REQUIRE(my_multiple_vec_result == multiple_vec_result);


	matrix3<float> mat_test2(-30.f, 12.f, 0.f, -20.f, 593.f, 0.f, 0.f, 23.f, 23.f);
	vector3<float> vec_test2(0.f, -12.f, 23.f);
	vector3<float> my_multiple_result2 = mat_test2 * vec_test2;

	vector3<float> multiple_result2(240.f, -6587.f, 529.f);

	REQUIRE(my_multiple_result2 == multiple_result2);
}

TEST_CASE("matrix3 transpose")
{
	matrix3<float> mat_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	matrix3<float> result(1.f, 4.f, 7.f, 2.f, 5.f, 8.f, 3.f, 6.f, 9.f);
	mat_test = MATRIX3::transpose(mat_test);

	REQUIRE(mat_test == result);
}

TEST_CASE("matrix3 rotation")
{
	matrix3<float> test = MATRIX3::build_rotation(30.f);;

	matrix3<float> result(cos(30.f), sin(30.f), 0.f, -sin(30.f), cos(30.f), 0.f, 0.f, 0.f, 1.f);

	REQUIRE(test == result);
}

TEST_CASE("matrix3 identity")
{
	matrix3<float> test = MATRIX3::build_identity<float>();

	matrix3<float> result(1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f);

	REQUIRE(test == result);
}

TEST_CASE("matrix3 scale_2float")
{
	matrix3<float> test = MATRIX3::build_scale<float>(10.f, 20.f);

	matrix3<float> result(10.f, 0.f, 0.f, 0.f, 20.f, 0.f, 0.f, 0.f, 1.f);

	REQUIRE(test == result);
}

TEST_CASE("matrix3 scale_1float")
{
	matrix3<float> test = MATRIX3::build_scale<float>(10.f);

	matrix3<float> result(10.f, 0.f, 0.f, 0.f, 10.f, 0.f, 0.f, 0.f, 1.f);

	REQUIRE(test == result);
}

TEST_CASE("matrix3 scale_vector")
{
	matrix3<float> test = MATRIX3::build_scale<float>({ 10.f,20.f });

	matrix3<float> result(10.f, 0.f, 0.f, 0.f, 20.f, 0.f, 0.f, 0.f, 1.f);

	REQUIRE(test == result);
}

TEST_CASE("matrix3 translation_2float")
{
	matrix3<float> test = MATRIX3::build_translation<float>(10.f, 25.f);

	matrix3<float> result(1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 10.f, 25.f, 1.f);

	REQUIRE(test == result);
}


TEST_CASE("matrix3 translation_vector")
{
	matrix3<float> test = MATRIX3::build_translation<float>({ 10.f, 25.f });

	matrix3<float> result(1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 10.f, 25.f, 1.f);

	REQUIRE(test == result);
}