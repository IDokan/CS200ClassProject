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
#include "Vector2.hpp"


TEST_CASE("Contructors")
{
	vector2<float> floatCtorTest{ 1.f };
	vector2<float> floatCtorAnswer{ 1.f };
	REQUIRE(floatCtorTest == floatCtorAnswer);

	vector2<int> intCtorTest{ 1 };
	vector2<int> intCtorAnswer{ 1 };
	REQUIRE(intCtorTest == intCtorAnswer);

	
}

TEST_CASE("Operators")
{
	// Operator+
	vector2<float> floatAdditionTest1{ 1.f };
	vector2<float> floatAdditionTest2{ 1.f };
	vector2<float> floatAdditionAnswer{ 2.f };
	REQUIRE((floatAdditionTest1 + floatAdditionTest2) == floatAdditionAnswer);

	vector2<float> floatAdditionTest3{ -1.f };
	vector2<float> floatAdditionAnswer2{ 0.f };
	REQUIRE((floatAdditionTest1 + floatAdditionTest3) == floatAdditionAnswer2);
	
	vector2<int> intAdditionTest1{ 1 };
	vector2<int> intAdditionTest2{ 1 };
	vector2<int> intAdditionAnswer{ 2 };
	REQUIRE((intAdditionTest1 + intAdditionTest2) == intAdditionAnswer);

	vector2<int> intAdditionTest3{ -1 };
	vector2<int> intAdditionAnswer2{ 0 };
	REQUIRE((intAdditionTest1 + intAdditionTest3) == intAdditionAnswer2);



	// Operator-
	vector2<float> floatSubtractionTest1{ 1.f };
	vector2<float> floatSubtractionTest2{ 1.f };
	vector2<float> floatSubtractionAnswer{ 0.f };
	REQUIRE((floatSubtractionTest1 - floatSubtractionTest2) == floatSubtractionAnswer);

	vector2<float> floatSubtractionTest3{ -3.f };
	vector2<float> floatSubtractionAnswer2{ 4.f };
	REQUIRE((floatSubtractionTest1 - floatSubtractionTest3) == floatSubtractionAnswer2);

	vector2<int> intSubtractionTest1{ 1 };
	vector2<int> intSubtractionTest2{ 1 };
	vector2<int> intSubtractionAnswer{ 0 };
	REQUIRE((intSubtractionTest1 - intSubtractionTest2) == intSubtractionAnswer);

	vector2<int> intSubtractionTest3{ -3 };
	vector2<int> intSubtractionAnswer2{ 4 };
	REQUIRE((intSubtractionTest1 - intSubtractionTest3) == intSubtractionAnswer2);



	// Operator*
	vector2<float> floatMultiplicationTest1{ 1.f };
	vector2<float> floatMultiplicationTest2{ 1.f };
	vector2<float> floatMultiplicationAnswer{ 0.f };
	REQUIRE((floatMultiplicationTest1 * floatMultiplicationTest2) == floatMultiplicationAnswer);

	vector2<float> floatMultiplicationTest3{ -3.f };
	vector2<float> floatMultiplicationAnswer2{ 4.f };
	REQUIRE((floatMultiplicationTest1 * floatMultiplicationTest3) == floatMultiplicationAnswer2);

	vector2<int> intMultiplicationTest1{ 1 };
	vector2<int> intMultiplicationTest2{ 1 };
	vector2<int> intMultiplicationAnswer{ 0 };
	REQUIRE((intMultiplicationTest1 * intMultiplicationTest2) == intMultiplicationAnswer);

	vector2<int> intMultiplicationTest3{ -3 };
	vector2<int> intMultiplicationAnswer2{ 4 };
	REQUIRE((intMultiplicationTest1 * intMultiplicationTest3) == intMultiplicationAnswer2);
}
