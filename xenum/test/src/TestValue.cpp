/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */

// For debug only
#include <iostream>
#include <sstream>
#include <string>

#include <gtest/gtest.h>
#include <test/xenum/xenums/FruitsNoNsNoCls.hpp>
#include <test/xenum/xenums/FruitsInNsNoCls.hpp>

namespace test {
namespace xenum {


/**
 * Test the general functionality of the enum-value class.
 */
class TestValue : public ::testing::Test {
public:
	bool success;
};


/// Test that we do not accidentally enlarge the enum-value objects.
TEST_F(TestValue, Size)
{
	EXPECT_EQ(sizeof(XenumFruits::_Index), sizeof(XenumFruit));
	EXPECT_EQ(sizeof(xenums::Fruits::_Index), sizeof(xenums::Fruit));
}


/// Test ctors, copy and assignment operators.
TEST_F(TestValue, CtorAssign)
{
	// Default ctor
	xenums::Fruit fruit1;
	EXPECT_EQ(xenums::Fruits::tomato, fruit1);
	EXPECT_EQ(xenums::Fruits::_Enum::tomato, fruit1());
	EXPECT_EQ(0, fruit1.getIndex());

	// Ctor with native enum-value
	xenums::Fruit fruit2(xenums::Fruits::_Enum::pear);
	EXPECT_EQ(xenums::Fruits::pear, fruit2);
	EXPECT_EQ(xenums::Fruits::_Enum::pear, fruit2());
	EXPECT_EQ((xenums::Fruits::_Index)xenums::Fruits::_Enum::pear, fruit2.getIndex());

	// Assignment from native enum value
	xenums::Fruit fruit3;
	fruit3 = xenums::Fruits::_Enum::lemon;
	EXPECT_EQ(xenums::Fruits::lemon, fruit3);
	EXPECT_EQ(xenums::Fruits::_Enum::lemon, fruit3());
	EXPECT_EQ((xenums::Fruits::_Index)xenums::Fruits::_Enum::lemon, fruit3.getIndex());

	// Copy ctor
	xenums::Fruit fruit4(fruit2);
	EXPECT_EQ(xenums::Fruits::pear, fruit4);
	EXPECT_EQ(xenums::Fruits::_Enum::pear, fruit4());
	EXPECT_EQ((xenums::Fruits::_Index)xenums::Fruits::_Enum::pear, fruit4.getIndex());

	// Assignment from other enum-value object
	xenums::Fruit fruit5;
	fruit5 = fruit3;
	EXPECT_EQ(xenums::Fruits::lemon, fruit5);
	EXPECT_EQ(xenums::Fruits::_Enum::lemon, fruit5());
	EXPECT_EQ((xenums::Fruits::_Index)xenums::Fruits::_Enum::lemon, fruit5.getIndex());
}


/// Test that the enum-value identifiers are correct.
TEST_F(TestValue, Identifiers)
{
	xenums::Fruit fruit;
	EXPECT_STREQ("tomato", fruit.getIdentifier());
	fruit = xenums::Fruits::pear;
	EXPECT_STREQ("pear", fruit.getIdentifier());
	fruit = xenums::Fruits::lime;
	EXPECT_STREQ("lime", fruit.getIdentifier());
	fruit = xenums::Fruits::lemon;
	EXPECT_STREQ("lemon", fruit.getIdentifier());
}


/// Test that the ostream::operator<<() works.
TEST_F(TestValue, OstreamOutput)
{
	std::stringstream stm;
	stm << xenums::Fruit(xenums::Fruits::lemon);
	//stm << " and " << xenums::Fruits::lime;
	//EXPECT_STREQ("lemon and lime", stm.str().c_str());
	EXPECT_STREQ("lemon", stm.str().c_str());
}


/// Test comparison operators.
TEST_F(TestValue, Comparison)
{
	xenums::Fruit fruit1 = xenums::Fruits::tomato;
	xenums::Fruit fruit2(xenums::Fruits::_Enum::pear);
	xenums::Fruit fruit3(fruit2);
	xenums::Fruit fruit4 = xenums::Fruits::lemon;

	EXPECT_EQ(true, fruit1 == fruit1);
	EXPECT_EQ(true, fruit2 == fruit2);
	EXPECT_EQ(true, fruit3 == fruit3);
	EXPECT_EQ(true, fruit4 == fruit4);
	EXPECT_EQ(true, fruit1 == xenums::Fruits::_Enum::tomato);
	EXPECT_EQ(true, fruit2 == xenums::Fruits::_Enum::pear);
	EXPECT_EQ(true, fruit3 == xenums::Fruits::_Enum::pear);
	EXPECT_EQ(true, fruit4 == xenums::Fruits::_Enum::lemon);
	EXPECT_EQ(false, fruit1 == fruit2);
	EXPECT_EQ(false, fruit1 == fruit3);
	EXPECT_EQ(false, fruit1 == fruit4);
	EXPECT_EQ(true, fruit2 == fruit3);
	EXPECT_EQ(false, fruit2 == fruit4);
	EXPECT_EQ(false, fruit3 == fruit4);

	EXPECT_EQ(false, fruit1 != fruit1);
	EXPECT_EQ(false, fruit2 != fruit2);
	EXPECT_EQ(false, fruit3 != fruit3);
	EXPECT_EQ(false, fruit4 != fruit4);
	EXPECT_EQ(false, xenums::Fruits::_Enum::tomato != fruit1());
	EXPECT_EQ(false, xenums::Fruits::_Enum::pear != fruit2());
	EXPECT_EQ(false, xenums::Fruits::_Enum::pear != fruit3());
	EXPECT_EQ(false, xenums::Fruits::_Enum::lemon != fruit4());
	EXPECT_EQ(true, fruit2 != fruit1);
	EXPECT_EQ(true, fruit3 != fruit1);
	EXPECT_EQ(true, fruit4 != fruit1);
	EXPECT_EQ(false, fruit3 != fruit2);
	EXPECT_EQ(true, fruit4 != fruit2);
	EXPECT_EQ(true, fruit4 != fruit3);

	EXPECT_EQ(false, fruit1 < fruit1);
	EXPECT_EQ(false, fruit2 < fruit2);
	EXPECT_EQ(false, fruit3 < fruit3);
	EXPECT_EQ(false, fruit4 < fruit4);
	EXPECT_EQ(true, fruit1 < fruit2);
	EXPECT_EQ(false, fruit2 < fruit1);
	EXPECT_EQ(true, fruit1 < fruit3);
	EXPECT_EQ(false, fruit3 < fruit1);
	EXPECT_EQ(true, fruit1 < fruit4);
	EXPECT_EQ(false, fruit4 < fruit1);
	EXPECT_EQ(false, fruit2 < fruit3);
	EXPECT_EQ(false, fruit3 < fruit2);
	EXPECT_EQ(true, fruit2 < fruit4);
	EXPECT_EQ(false, fruit4 < fruit2);
	EXPECT_EQ(true, fruit3 < fruit4);
	EXPECT_EQ(false, fruit4 < fruit3);

	EXPECT_EQ(true, fruit1 <= fruit1);
	EXPECT_EQ(true, fruit2 <= fruit2);
	EXPECT_EQ(true, fruit3 <= fruit3);
	EXPECT_EQ(true, fruit4 <= fruit4);
	EXPECT_EQ(true, fruit1 <= fruit2);
	EXPECT_EQ(false, fruit2 <= fruit1);
	EXPECT_EQ(true, fruit1 <= fruit3);
	EXPECT_EQ(false, fruit3 <= fruit1);
	EXPECT_EQ(true, fruit1 <= fruit4);
	EXPECT_EQ(false, fruit4 <= fruit1);
	EXPECT_EQ(true, fruit2 <= fruit3);
	EXPECT_EQ(true, fruit3 <= fruit2);
	EXPECT_EQ(true, fruit2 <= fruit4);
	EXPECT_EQ(false, fruit4 <= fruit2);
	EXPECT_EQ(true, fruit3 <= fruit4);
	EXPECT_EQ(false, fruit4 <= fruit3);

	EXPECT_EQ(false, fruit1 > fruit1);
	EXPECT_EQ(false, fruit2 > fruit2);
	EXPECT_EQ(false, fruit3 > fruit3);
	EXPECT_EQ(false, fruit4 > fruit4);
	EXPECT_EQ(false, fruit1 > fruit2);
	EXPECT_EQ(true, fruit2 > fruit1);
	EXPECT_EQ(false, fruit1 > fruit3);
	EXPECT_EQ(true, fruit3 > fruit1);
	EXPECT_EQ(false, fruit1 > fruit4);
	EXPECT_EQ(true, fruit4 > fruit1);
	EXPECT_EQ(false, fruit2 > fruit3);
	EXPECT_EQ(false, fruit3 > fruit2);
	EXPECT_EQ(false, fruit2 > fruit4);
	EXPECT_EQ(true, fruit4 > fruit2);
	EXPECT_EQ(false, fruit3 > fruit4);
	EXPECT_EQ(true, fruit4 > fruit3);

	EXPECT_EQ(true, fruit1 >= fruit1);
	EXPECT_EQ(true, fruit2 >= fruit2);
	EXPECT_EQ(true, fruit3 >= fruit3);
	EXPECT_EQ(true, fruit4 >= fruit4);
	EXPECT_EQ(false, fruit1 >= fruit2);
	EXPECT_EQ(true, fruit2 >= fruit1);
	EXPECT_EQ(false, fruit1 >= fruit3);
	EXPECT_EQ(true, fruit3 >= fruit1);
	EXPECT_EQ(false, fruit1 >= fruit4);
	EXPECT_EQ(true, fruit4 >= fruit1);
	EXPECT_EQ(true, fruit2 >= fruit3);
	EXPECT_EQ(true, fruit3 >= fruit2);
	EXPECT_EQ(false, fruit2 >= fruit4);
	EXPECT_EQ(true, fruit4 >= fruit2);
	EXPECT_EQ(false, fruit3 >= fruit4);
	EXPECT_EQ(true, fruit4 >= fruit3);
}


/// Test switch() statement.
TEST_F(TestValue, Switch)
{
	xenums::Fruit fruit1(xenums::Fruits::_Enum::pear);

	switch (fruit1()) {
	// Must not compile; int-type not comparable to native enum type
	//case 1:
	// Must not compile; enumvalue object from other enum class
	//case XenumFruits::apple(): break;
	case xenums::Fruits::_Enum::tomato:
		success = false;
		break;
	case xenums::Fruits::pear():
		success = true;
		break;
	case xenums::Fruits::lime():
		success = false;
		break;
	default:
		success = false;
		break;
	}
	EXPECT_EQ(true, success);
}


} // namespace xenum
} // namespace test
