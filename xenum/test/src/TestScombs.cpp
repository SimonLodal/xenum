/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */

// For debug only
#include <iostream>
#include <string>
#include <type_traits>

#include <gtest/gtest.h>

/// To get throwing getValue() and fromValue() instead of not
/// compiling them when they are "off".
#define _XENUM5_UNIT_TEST	1

#include <test/xenum/xenums/Scombs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenums with combinations of custom property options.
 */
class TestScombs : public ::testing::Test {
public:
	bool success;
};


/// Test basics of Scombs xenum.
TEST_F(TestScombs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_Scombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::Scombs::_size);
}

/// Function that only compiles if the constexpr getS0COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS0COSize() == 3, bool>::type cxpGetS0COSize() { return true; }
/// Function that only compiles if the constexpr getS0CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS0CO(), "13"), bool>::type cxpGetS0CO(void) { return true; }
/// Test custom properties S0* of Scombs xenum.
TEST_F(TestScombs, S0)
{
	xenums::Scomb value;

	// getS0COSize() at compile time
	EXPECT_EQ(true, cxpGetS0COSize<void>());
	// getS0CO() at compile time
	EXPECT_EQ(true, cxpGetS0CO<void>());

	// getS0OO()=off
	success = false;
	try { xenums::Scombs::V0.getS0OO(); }
	catch (std::logic_error e) { EXPECT_STREQ("getS0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V0
	value = xenums::Scombs::V0;
	EXPECT_STREQ("12", value.getS0EO());
	EXPECT_STREQ("13", value.getS0CO());
	EXPECT_EQ(3, value.getS0EOSize());
	EXPECT_EQ(3, value.getS0COSize());
	// V1
	value = xenums::Scombs::V1;
	EXPECT_STREQ("-12", value.getS0EO());
	EXPECT_STREQ("-13", value.getS0CO());
	EXPECT_EQ(4, value.getS0EOSize());
	EXPECT_EQ(4, value.getS0COSize());
	// V2
	value = xenums::Scombs::V2;
	EXPECT_STREQ("212", value.getS0EO());
	EXPECT_STREQ("213", value.getS0CO());
	EXPECT_EQ(4, value.getS0EOSize());
	EXPECT_EQ(4, value.getS0COSize());
}


/// Function that only compiles if the constexpr getS1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1COSize() == 3, bool>::type cxpGetS1COSize() { return true; }
/// Function that only compiles if the constexpr getS1COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1COSize(2) == 3, bool>::type cxpGetS1COSize1() { return true; }
/// Function that only compiles if the constexpr getS1CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CO(1), "-23"), bool>::type cxpGetS1CO(void) { return true; }
/// Test custom properties S1* of Scombs xenum.
TEST_F(TestScombs, S1)
{
	xenums::Scomb value;

	// getS1COSize() at compile time
	EXPECT_EQ(true, cxpGetS1COSize<void>());
	// getS1COSize(index1) at compile time
	EXPECT_EQ(true, cxpGetS1COSize1<void>());
	// getS1CO() at compile time
	EXPECT_EQ(true, cxpGetS1CO<void>());

	// getS1OO()=off
	success = false;
	try { xenums::Scombs::V0.getS1OO(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V0
	value = xenums::Scombs::V0;
	EXPECT_EQ(3, value.getS1EOSize());
	EXPECT_EQ(3, value.getS1COSize());

	EXPECT_STREQ("23", value.getS1EO(0));
	EXPECT_STREQ("25", value.getS1CO(0));
	EXPECT_EQ(3, value.getS1EOSize(0));
	EXPECT_EQ(3, value.getS1COSize(0));
	EXPECT_STREQ("-22", value.getS1EO(1));
	EXPECT_STREQ("-23", value.getS1CO(1));
	EXPECT_EQ(4, value.getS1EOSize(1));
	EXPECT_EQ(4, value.getS1COSize(1));
	EXPECT_STREQ("24", value.getS1EO(2));
	EXPECT_STREQ("26", value.getS1CO(2));
	EXPECT_EQ(3, value.getS1EOSize(2));
	EXPECT_EQ(3, value.getS1COSize(2));
	success = false;
	try { value.getS1EO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1CO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1EOSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1COSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1EOSize());
	EXPECT_EQ(0, value.getS1COSize());
	success = false;
	try { value.getS1EO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1CO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1EOSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1COSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Scombs::V2;
	EXPECT_EQ(1, value.getS1EOSize());
	EXPECT_EQ(1, value.getS1COSize());

	EXPECT_STREQ("-22", value.getS1EO(0));
	EXPECT_STREQ("-23", value.getS1CO(0));
	EXPECT_EQ(4, value.getS1EOSize(0));
	EXPECT_EQ(4, value.getS1COSize(0));
	success = false;
	try { value.getS1EO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1CO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1EOSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1COSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize() == 2, bool>::type cxpGetS2COSize() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize(0) == 3, bool>::type cxpGetS2COSize1() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize(0,2) == 3, bool>::type cxpGetS2COSize2() { return true; }
/// Function that only compiles if the constexpr getS2CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CO(1,0), "-33"), bool>::type cxpGetS2CO(void) { return true; }
/// Test custom properties S2* of Scombs xenum.
TEST_F(TestScombs, S2)
{
	xenums::Scomb value;

	// getS2COSize() at compile time
	EXPECT_EQ(true, cxpGetS2COSize<void>());
	// getS2COSize(index1) at compile time
	EXPECT_EQ(true, cxpGetS2COSize1<void>());
	// getS2COSize(index1,index2) at compile time
	EXPECT_EQ(true, cxpGetS2COSize2<void>());
	// getS2CO() at compile time
	EXPECT_EQ(true, cxpGetS2CO<void>());

	// getS2OO()=off
	success = false;
	try { xenums::Scombs::V0.getS2OO(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V0
	value = xenums::Scombs::V0;
	EXPECT_EQ(2, value.getS2EOSize());
	EXPECT_EQ(2, value.getS2COSize());

	EXPECT_EQ(3, value.getS2EOSize(0));
	EXPECT_EQ(3, value.getS2COSize(0));
	EXPECT_EQ(1, value.getS2EOSize(1));
	EXPECT_EQ(1, value.getS2COSize(1));
	success = false;
	try { value.getS2EOSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("33", value.getS2EO(0, 0));
	EXPECT_STREQ("35", value.getS2CO(0, 0));
	EXPECT_EQ(3, value.getS2EOSize(0, 0));
	EXPECT_EQ(3, value.getS2COSize(0, 0));
	EXPECT_STREQ("-32", value.getS2EO(0, 1));
	EXPECT_STREQ("-33", value.getS2CO(0, 1));
	EXPECT_EQ(4, value.getS2EOSize(0, 1));
	EXPECT_EQ(4, value.getS2COSize(0, 1));
	EXPECT_STREQ("34", value.getS2EO(0, 2));
	EXPECT_STREQ("36", value.getS2CO(0, 2));
	EXPECT_EQ(3, value.getS2EOSize(0, 2));
	EXPECT_EQ(3, value.getS2COSize(0, 2));
	success = false;
	try { value.getS2EO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EOSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-32", value.getS2EO(1, 0));
	EXPECT_STREQ("-33", value.getS2CO(1, 0));
	EXPECT_EQ(4, value.getS2EOSize(1, 0));
	EXPECT_EQ(4, value.getS2COSize(1, 0));
	success = false;
	try { value.getS2EO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EOSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2EO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EOSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS2EOSize());
	EXPECT_EQ(0, value.getS2COSize());

	success = false;
	try { value.getS2EOSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EOSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Scombs::V2;
	EXPECT_EQ(1, value.getS2EOSize());
	EXPECT_EQ(1, value.getS2COSize());

	EXPECT_EQ(0, value.getS2EOSize(0));
	EXPECT_EQ(0, value.getS2COSize(0));
	success = false;
	try { value.getS2EOSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EOSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


} // namespace xenum
} // namespace test
