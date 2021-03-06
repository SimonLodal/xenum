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


/// Function that only compiles if the constexpr fromIndex() actually works at compile time.
template <class T> typename std::enable_if<xenums::Fruits::_fromIndex(1) == xenums::Fruits::pear, bool>::type cxpFromIndex(void) { return true; }
/// Test fromIndex().
TEST_F(TestCntnr, FromIndex)
{
	xenums::Fruit fruit;

	// fromIndex() at compile time
	EXPECT_EQ(true, cxpFromIndex<void>());

	for (size_t index=0; index<xenums::Fruits::_size; index++) {
		EXPECT_EQ(true, xenums::Fruits::_fromIndex(index, fruit));
		EXPECT_EQ(index, fruit.getIndex());
		EXPECT_EQ(fruit, xenums::Fruits::_fromIndex(index));
	}
	EXPECT_EQ(false, xenums::Fruits::_fromIndex(xenums::Fruits::_size, fruit));
	EXPECT_EQ(xenums::Fruits::_size-1, fruit.getIndex()); // unchanged since last loop

	success = false;
	try { xenums::Fruits::_fromIndex(xenums::Fruits::_size); }
	catch (std::out_of_range e) { EXPECT_STREQ("Index >= size.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test fromIdentifier().
TEST_F(TestCntnr, FromIdentifier)
{
	xenums::Fruit fruit1, fruit2;
	for (size_t index=0; index<xenums::Fruits::_size; index++) {
		EXPECT_EQ(true, xenums::Fruits::_fromIndex(index, fruit1));
		std::string ident = fruit1.getIdentifier();
		EXPECT_EQ(true, xenums::Fruits::_fromIdentifier(ident.c_str(), fruit2));
		EXPECT_EQ(fruit2, fruit1);
		EXPECT_EQ(fruit1, xenums::Fruits::_fromIdentifier(ident.c_str()));
	}
	EXPECT_EQ(false, xenums::Fruits::_fromIdentifier("non-existing identifier", fruit1));
	EXPECT_EQ(fruit2, fruit1); // untouched fruit1

	success = false;
	try { xenums::Fruits::_fromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test enum-value iteration().
TEST_F(TestCntnr, Iteration)
{
	size_t index;

	// New-style iteration
	index = 0;
	for (xenums::Number number : xenums::Numbers()) {
	//for (auto number : xenums::Numbers()) {
		EXPECT_EQ(index, number.getIndex());
		index++;
	}
	EXPECT_EQ(index, xenums::Numbers::_size);

	// Old-style iteration
	index = 0;
	for (xenums::Numbers::iterator iter = xenums::Numbers::begin();
	     iter != xenums::Numbers::end(); ++iter) {
		//EXPECT_EQ(index, (*iter).getIndex());
		xenums::Number number = *iter;
		EXPECT_EQ(index, number.getIndex());
		index++;
	}
	EXPECT_EQ(index, xenums::Numbers::_size);
}


} // namespace xenum
} // namespace test
