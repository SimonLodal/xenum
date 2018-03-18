/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */

// For debug only
#include <iostream>
#include <string>

#include <gtest/gtest.h>
#include <test/xenum/xenums/FruitsNoNsNoCls.hpp>
#include <test/xenum/xenums/FruitsInNsNoCls.hpp>
#include <test/xenum/xenums/Numbers.hpp>

namespace test {
namespace xenum {


/**
 * Test the general functionality of the enum-container class.
 */
class TestCntnr : public ::testing::Test {
public:
	bool success;
};


TEST_F(TestCntnr, FromIndex)
{
	xenums::Fruit fruit;
	xenums::Fruits::Enum value;
	for (size_t index=0; index<xenums::Fruits::size; index++) {
		EXPECT_EQ(true, xenums::Fruits::fromIndex(index, value));
		fruit = value;
		EXPECT_EQ(index, fruit.getIndex());
		EXPECT_EQ(value, xenums::Fruits::fromIndex(index));
	}
	EXPECT_EQ(false, xenums::Fruits::fromIndex(xenums::Fruits::size, value));
	fruit = value;
	EXPECT_EQ(xenums::Fruits::size-1, fruit.getIndex()); // unchanged since last loop
}


TEST_F(TestCntnr, FromIdentifier)
{
	xenums::Fruit fruit1, fruit2;
	xenums::Fruits::Enum value1, value2;
	for (size_t index=0; index<xenums::Fruits::size; index++) {
		EXPECT_EQ(true, xenums::Fruits::fromIndex(index, value1));
		fruit1 = value1;
		std::string ident = fruit1.getIdentifier();
		EXPECT_EQ(true, xenums::Fruits::fromIdentifier(ident.c_str(), value2));
		fruit2 = value2;
		EXPECT_EQ(value2, value1);
		EXPECT_EQ(fruit2, fruit1);
		EXPECT_EQ(value1, xenums::Fruits::fromIdentifier(ident.c_str()));
	}
	EXPECT_EQ(false, xenums::Fruits::fromIdentifier("non-existing identifier", value1));
	EXPECT_EQ(value2, value1); // untouched fruit1
}


TEST_F(TestCntnr, Iteration)
{
	size_t index;

	// New-style iteration
	index = 0;
	//for (xenum::Number number : xenum::Numbers()) {
	for (auto number : xenums::Numbers()) {
		EXPECT_EQ(index, (xenums::Numbers::index_t)number);
		index++;
	}
	EXPECT_EQ(index, xenums::Numbers::size);

	// Old-style iteration
	index = 0;
	for (xenums::Numbers::iterator iter = xenums::Numbers::begin();
	     iter != xenums::Numbers::end(); ++iter) {
		const xenums::Number number = *iter;
		EXPECT_EQ(index, number.getIndex());
		index++;
	}
	EXPECT_EQ(index, xenums::Numbers::size);
}


} // namespace xenum
} // namespace test
