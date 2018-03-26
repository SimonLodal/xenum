/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */

// For debug only
#include <iostream>
#include <string>
#include <type_traits>

#include <gtest/gtest.h>
#include <test/xenum/xenums/FruitsNoNsNoCls.hpp>
#include <test/xenum/xenums/FruitsNoNsInCls.hpp>
#include <test/xenum/xenums/FruitsInNsNoCls.hpp>
#include <test/xenum/xenums/FruitsInNsInCls.hpp>
#include <test/xenum/xenums/Numbers.hpp>
#include <xenum4/XenumSet.hpp>

namespace test {
namespace xenum {


/**
 * Test the XenumSet.
 */
class TestXenumSet : public ::testing::Test {
public:
	bool success;

};


TEST_F(TestXenumSet, CtorAdd)
{
//	::_XENUM4_NS::XenumSet<xenums::Fruits> fruitsSet({xenums::Fruits::tomato, xenums::Fruits::lemon});
//	::_XENUM4_NS::XenumSet<xenums::Numbers> numbersSet({xenums::Numbers::n0001});
}


TEST_F(TestXenumSet, AddRemoveContainsCompareFruits)
{
	::_XENUM4_NS::XenumSet<xenums::Fruits> fruitsSet;
	::_XENUM4_NS::XenumSet<xenums::Fruits> allSet;
	::_XENUM4_NS::XenumSet<xenums::Fruits> noneSet;

	allSet.addAll();
	noneSet.removeAll();

	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::tomato));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::pear));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lime));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lemon));
	EXPECT_NE(fruitsSet, allSet);
	EXPECT_EQ(fruitsSet, noneSet);

	// add
	fruitsSet.add(xenums::Fruits::tomato);
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::tomato));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::pear));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lime));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lemon));
	EXPECT_NE(fruitsSet, allSet);
	EXPECT_NE(fruitsSet, noneSet);

	// add again => no change
	fruitsSet.add(xenums::Fruits::tomato);
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::tomato));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::pear));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lime));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lemon));
	EXPECT_NE(fruitsSet, allSet);
	EXPECT_NE(fruitsSet, noneSet);

	fruitsSet.add(xenums::Fruits::pear);
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::tomato));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::pear));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lime));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lemon));
	EXPECT_NE(fruitsSet, allSet);
	EXPECT_NE(fruitsSet, noneSet);

	fruitsSet.add({xenums::Fruits::lime, xenums::Fruits::lemon});
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::tomato));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::pear));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::lime));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::lemon));
	EXPECT_EQ(fruitsSet, allSet);
	EXPECT_NE(fruitsSet, noneSet);

	// remove
	fruitsSet.remove(xenums::Fruits::tomato);
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::tomato));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::pear));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::lime));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::lemon));
	EXPECT_NE(fruitsSet, allSet);
	EXPECT_NE(fruitsSet, noneSet);

	// remove again => no change
	fruitsSet.remove(xenums::Fruits::tomato);
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::tomato));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::pear));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::lime));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::lemon));
	EXPECT_NE(fruitsSet, allSet);
	EXPECT_NE(fruitsSet, noneSet);

	fruitsSet.remove({xenums::Fruits::pear, xenums::Fruits::lime});
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::tomato));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::pear));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lime));
	EXPECT_EQ(true, fruitsSet.contains(xenums::Fruits::lemon));
	EXPECT_NE(fruitsSet, allSet);
	EXPECT_NE(fruitsSet, noneSet);

	fruitsSet.remove(xenums::Fruits::lemon);
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::tomato));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::pear));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lime));
	EXPECT_EQ(false, fruitsSet.contains(xenums::Fruits::lemon));
	EXPECT_NE(fruitsSet, allSet);
	EXPECT_EQ(fruitsSet, noneSet);
}


TEST_F(TestXenumSet, AddRemoveContainsNumbers)
{
	size_t index;
	::_XENUM4_NS::XenumSet<xenums::Numbers> numbersSet;
	::_XENUM4_NS::XenumSet<xenums::Numbers> allSet;
	::_XENUM4_NS::XenumSet<xenums::Numbers> noneSet;

	allSet.addAll();
	noneSet.removeAll();

	// Check empty
	for (index=0; index<xenums::Numbers::size; index++) {
		EXPECT_EQ(false, numbersSet.contains(xenums::Numbers::fromIndex(index)));
	}
	EXPECT_EQ(numbersSet, noneSet);

	// Add all, backwards
	for (index=xenums::Numbers::size; index>0; index--) {
		numbersSet.add(xenums::Numbers::fromIndex(index-1));
		EXPECT_EQ(true, numbersSet.contains(xenums::Numbers::fromIndex(index-1)));
		/*
		for (size_t index2=0; index2<index-1; index2++) {
			ASSERT_EQ(false, numbersSet.contains(xenums::Numbers::fromIndex(index2)));
		}
		for (size_t index2=index-1; index2<xenums::Numbers::size; index2++) {
			ASSERT_EQ(true, numbersSet.contains(xenums::Numbers::fromIndex(index2)));
		}
		*/
	}
	// Check all contained
	for (index=0; index<xenums::Numbers::size; index++) {
		EXPECT_EQ(true, numbersSet.contains(xenums::Numbers::fromIndex(index)));
	}
	EXPECT_EQ(numbersSet, allSet);

	// Remove all, forwards
	for (index=0; index<xenums::Numbers::size; index++) {
		numbersSet.remove(xenums::Numbers::fromIndex(index));
		EXPECT_EQ(false, numbersSet.contains(xenums::Numbers::fromIndex(index)));
		/*
		for (size_t index2=0; index2<index+1; index2++) {
			ASSERT_EQ(false, numbersSet.contains(xenums::Numbers::fromIndex(index2)));
		}
		for (size_t index2=index+1; index2<xenums::Numbers::size; index2++) {
			ASSERT_EQ(true, numbersSet.contains(xenums::Numbers::fromIndex(index2)));
		}
		*/
	}

	// Check empty
	for (index=0; index<xenums::Numbers::size; index++) {
		EXPECT_EQ(false, numbersSet.contains(xenums::Numbers::fromIndex(index)));
	}
	EXPECT_EQ(numbersSet, noneSet);
}


TEST_F(TestXenumSet, CopyAssign)
{
	::_XENUM4_NS::XenumSet<xenums::Numbers> numbers1;
	size_t index;

	numbers1.add({xenums::Numbers::n0001,
		      xenums::Numbers::n1234,
		      xenums::Numbers::n4100});

	::_XENUM4_NS::XenumSet<xenums::Numbers> numbers2(numbers1);
	for (index=0; index<xenums::Numbers::size; index++) {
		xenums::Number number = xenums::Numbers::fromIndex(index);
		if (number == xenums::Numbers::n0001 ||
		    number == xenums::Numbers::n1234 ||
		    number == xenums::Numbers::n4100)
			EXPECT_EQ(true, numbers2.contains(number));
		else
			EXPECT_EQ(false, numbers2.contains(number));
	}

	numbers2.add(xenums::Numbers::n2345);
	EXPECT_NE(numbers2, numbers1);

	::_XENUM4_NS::XenumSet<xenums::Numbers> numbers3;
	numbers3 = numbers2;
	EXPECT_EQ(numbers3, numbers2);
	EXPECT_NE(numbers3, numbers1);
}


TEST_F(TestXenumSet, Comparison)
{
	::_XENUM4_NS::XenumSet<xenums::Numbers> numbers1, numbers2;
	size_t index, lastIndex;

	EXPECT_EQ(true, numbers1 == numbers2);
	EXPECT_EQ(false, numbers1 != numbers2);
	numbers1.add(xenums::Numbers::n0001);
	EXPECT_EQ(false, numbers1 == numbers2);
	EXPECT_EQ(true, numbers1 != numbers2);
	numbers2.add(xenums::Numbers::n0001);
	EXPECT_EQ(true, numbers1 == numbers2);
	EXPECT_EQ(false, numbers1 != numbers2);

	EXPECT_EQ(true, numbers1 == numbers2);
	EXPECT_EQ(false, numbers1 != numbers2);
	numbers1.add(xenums::Numbers::n1234);
	EXPECT_EQ(false, numbers1 == numbers2);
	EXPECT_EQ(true, numbers1 != numbers2);
	numbers2.add(xenums::Numbers::n1234);
	EXPECT_EQ(true, numbers1 == numbers2);
	EXPECT_EQ(false, numbers1 != numbers2);

	numbers2.add(xenums::Numbers::n4100);
	EXPECT_EQ(false, numbers1 == numbers2);
	EXPECT_EQ(true, numbers1 != numbers2);
	numbers1.add(xenums::Numbers::n4100);
	EXPECT_EQ(true, numbers1 == numbers2);
	EXPECT_EQ(false, numbers1 != numbers2);

	// Add/check every 5th number
	lastIndex = 0;
	for (index=1; index<xenums::Numbers::size; index+=5) {
		numbers1.add(xenums::Numbers::fromIndex(index));
		EXPECT_EQ(false, numbers1 == numbers2);
		EXPECT_EQ(true, numbers1 != numbers2);
		lastIndex = index;
	}
	for (index=1; index<lastIndex; index+=5) {
		numbers2.add(xenums::Numbers::fromIndex(index));
		EXPECT_EQ(false, numbers1 == numbers2);
		EXPECT_EQ(true, numbers1 != numbers2);
	}
	numbers2.add(xenums::Numbers::fromIndex(lastIndex));
	EXPECT_EQ(true, numbers1 == numbers2);
	EXPECT_EQ(false, numbers1 != numbers2);
}


TEST_F(TestXenumSet, ContainsSet)
{
	::_XENUM4_NS::XenumSet<xenums::Numbers> numbers1, numbers2, all, none;
	size_t index;

	all.addAll();
	none.removeAll();
	EXPECT_EQ(false, all.containsAny(none));
	EXPECT_EQ(false, all.containsAll(none));
	EXPECT_EQ(false, none.containsAny(all));
	EXPECT_EQ(false, none.containsAll(all));
	EXPECT_EQ(true, all.containsAny(all));
	EXPECT_EQ(true, all.containsAll(all));
	EXPECT_EQ(false, none.containsAny(none));
	EXPECT_EQ(false, none.containsAll(none));

	EXPECT_EQ(false, numbers1.containsAny(numbers2));
	EXPECT_EQ(false, numbers1.containsAll(numbers2));

	numbers1.add(xenums::Numbers::fromIndex(0));
	numbers2.add(xenums::Numbers::fromIndex(1));

	EXPECT_EQ(false, numbers1.containsAny(numbers2));
	EXPECT_EQ(false, numbers1.containsAll(numbers2));
	EXPECT_EQ(false, numbers2.containsAny(numbers1));
	EXPECT_EQ(false, numbers2.containsAll(numbers1));

	EXPECT_EQ(true, numbers1.containsAny(all));
	EXPECT_EQ(false, numbers1.containsAll(all));
	EXPECT_EQ(false, numbers1.containsAny(none));
	EXPECT_EQ(false, numbers1.containsAll(none));

	EXPECT_EQ(true, all.containsAny(numbers1));
	EXPECT_EQ(true, all.containsAll(numbers1));
	EXPECT_EQ(false, none.containsAny(numbers1));
	EXPECT_EQ(false, none.containsAll(numbers1));

	// Add every other value to either set.
	for (index=2; index<xenums::Numbers::size; index+=2)
		numbers1.add(xenums::Numbers::fromIndex(index));
	for (index=3; index<xenums::Numbers::size; index+=2)
		numbers2.add(xenums::Numbers::fromIndex(index));

	EXPECT_EQ(false, numbers1.containsAny(numbers2));
	EXPECT_EQ(false, numbers1.containsAll(numbers2));
	EXPECT_EQ(false, numbers2.containsAny(numbers1));
	EXPECT_EQ(false, numbers2.containsAll(numbers1));

	EXPECT_EQ(true, numbers2.containsAny(all));
	EXPECT_EQ(false, numbers2.containsAll(all));
	EXPECT_EQ(false, numbers2.containsAny(none));
	EXPECT_EQ(false, numbers2.containsAll(none));

	EXPECT_EQ(true, all.containsAny(numbers2));
	EXPECT_EQ(true, all.containsAll(numbers2));
	EXPECT_EQ(false, none.containsAny(numbers2));
	EXPECT_EQ(false, none.containsAll(numbers2));

	// Add every other value to either set.
	for (index=0; index<xenums::Numbers::size; index+=2)
		numbers2.add(xenums::Numbers::fromIndex(index));
	for (index=1; index<xenums::Numbers::size; index+=2)
		numbers1.add(xenums::Numbers::fromIndex(index));

	EXPECT_EQ(numbers1, all);
	EXPECT_EQ(numbers2, all);

	EXPECT_EQ(true, numbers1.containsAny(numbers2));
	EXPECT_EQ(true, numbers1.containsAll(numbers2));
	EXPECT_EQ(true, numbers2.containsAny(numbers1));
	EXPECT_EQ(true, numbers2.containsAll(numbers1));

	EXPECT_EQ(true, numbers1.containsAny(all));
	EXPECT_EQ(true, numbers1.containsAll(all));
	EXPECT_EQ(false, numbers1.containsAny(none));
	EXPECT_EQ(false, numbers1.containsAll(none));

	EXPECT_EQ(true, all.containsAny(numbers1));
	EXPECT_EQ(true, all.containsAll(numbers1));
	EXPECT_EQ(false, none.containsAny(numbers1));
	EXPECT_EQ(false, none.containsAll(numbers1));


}


TEST_F(TestXenumSet, Iteration)
{
	::_XENUM4_NS::XenumSet<xenums::Numbers> numbersSet;
	size_t index;

	EXPECT_EQ(true, numbersSet.begin() == numbersSet.end());

	::_XENUM4_NS::XenumSet<xenums::Numbers>::iterator iter = numbersSet.end();
	xenums::Number number1;
	success = false;
	try {
		number1 = *iter;
	}
	catch (std::out_of_range e) {
		EXPECT_STREQ("Index >= size.", e.what());
		success = true;
	}
	EXPECT_EQ(true, success);
	EXPECT_EQ(number1, xenums::Numbers::n0001);

	numbersSet.add({xenums::Numbers::n4100,
		        xenums::Numbers::n3050,
		        xenums::Numbers::n0001,
		        xenums::Numbers::n0120,
		        xenums::Numbers::n0010});

	// New-style iteration
	index = 0;
	for (xenums::Number number : numbersSet) {
		switch (index) {
		case 0:
			EXPECT_EQ(number, xenums::Numbers::n0001);
			break;
		case 1:
			EXPECT_EQ(number, xenums::Numbers::n0010);
			break;
		case 2:
			EXPECT_EQ(number, xenums::Numbers::n0120);
			break;
		case 3:
			EXPECT_EQ(number, xenums::Numbers::n3050);
			break;
		case 4:
			EXPECT_EQ(number, xenums::Numbers::n4100);
			break;
		default:
			break;
		}
		index++;
	}
	EXPECT_EQ(5, index);

	// Old-style iteration
	index = 0;
	for (::_XENUM4_NS::XenumSet<xenums::Numbers>::iterator iter = numbersSet.begin();
	     iter != numbersSet.end(); iter++, index++) {
		const xenums::Number number = *iter;
		switch (index) {
		case 0:
			EXPECT_EQ(number, xenums::Numbers::n0001);
			break;
		case 1:
			EXPECT_EQ(number, xenums::Numbers::n0010);
			break;
		case 2:
			EXPECT_EQ(number, xenums::Numbers::n0120);
			break;
		case 3:
			EXPECT_EQ(number, xenums::Numbers::n3050);
			break;
		case 4:
			EXPECT_EQ(number, xenums::Numbers::n4100);
			break;
		default:
			break;
		}
	}
	EXPECT_EQ(5, index);
}


TEST_F(TestXenumSet, OutputNumbers)
{
	::_XENUM4_NS::XenumSet<xenums::Numbers> numbersSet;
	numbersSet.add({xenums::Numbers::n3050,
		        xenums::Numbers::n0120,
		        xenums::Numbers::n0010});
	std::stringstream stm;
	stm << numbersSet;
	EXPECT_STREQ(stm.str().c_str(), "[n0010,n0120,n3050]");
}


} // namespace xenum
} // namespace test
