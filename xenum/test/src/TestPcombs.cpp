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

#include <test/xenum/xenums/Pcombs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenums with combinations of custom property options.
 */
class TestPcombs : public ::testing::Test {
public:
	bool success;
};


/// Test custom properties P0* of Pcombs xenum.
TEST_F(TestPcombs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_Pcombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::Pcombs::_size);
}

/// Function that only compiles if the constexpr getP0CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V1.getP0CO() == -13, bool>::type cxpGetP0CO(void) { return true; }
/// Test custom properties P0* of Pcombs xenum.
TEST_F(TestPcombs, P0)
{
	xenums::Pcomb value;

	// getP0CO() at compile time
	EXPECT_EQ(true, cxpGetP0CO<void>());

	// getP0OO()=off
	success = false;
	try { xenums::Pcombs::V0.getP0OO(); }
	catch (std::logic_error e) { EXPECT_STREQ("getP0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(12, value.getP0EO());
	EXPECT_EQ(13, value.getP0CO());

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(-12, value.getP0EO());
	EXPECT_EQ(-13, value.getP0CO());

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(212, value.getP0EO());
	EXPECT_EQ(213, value.getP0CO());
}


/// Function that only compiles if the constexpr getP1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1COSize() == 3, bool>::type cxpGetP1COSize(void) { return true; }
/// Function that only compiles if the constexpr getP1CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1CO(2) == 26, bool>::type cxpGetP1CO(void) { return true; }
/// Test custom properties P1* of Pcombs xenum.
TEST_F(TestPcombs, P1)
{
	xenums::Pcomb value;

	// getP1COSize() at compile time
	EXPECT_EQ(true, cxpGetP1COSize<void>());
	// getP1CO() at compile time
	EXPECT_EQ(true, cxpGetP1CO<void>());

	// getP1OO()=off
	success = false;
	try { xenums::Pcombs::V0.getP1OO(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1EOSize());
	EXPECT_EQ(3, value.getP1COSize());

	EXPECT_EQ(23, value.getP1EO(0));
	EXPECT_EQ(25, value.getP1CO(0));
	EXPECT_EQ(-22, value.getP1EO(1));
	EXPECT_EQ(-23, value.getP1CO(1));
	EXPECT_EQ(24, value.getP1EO(2));
	EXPECT_EQ(26, value.getP1CO(2));
	success = false;
	try { value.getP1EO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP1CO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1EOSize());
	EXPECT_EQ(0, value.getP1COSize());
	success = false;
	try { value.getP1EO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP1CO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1EOSize());
	EXPECT_EQ(1, value.getP1COSize());

	EXPECT_EQ(-22, value.getP1EO(0));
	EXPECT_EQ(-23, value.getP1CO(0));
	success = false;
	try { value.getP1EO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP1CO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2COSize() == 2, bool>::type cxpGetP2COSize() { return true; }
/// Function that only compiles if the constexpr getP2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2COSize(0) == 3, bool>::type cxpGetP2COSize1() { return true; }
/// Function that only compiles if the constexpr getP2CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CO(1,0) == -33, bool>::type cxpGetP2CO(void) { return true; }
/// Test custom properties P2* of Pcombs xenum.
TEST_F(TestPcombs, P2)
{
	xenums::Pcomb value;

	// getP2COSize() at compile time
	EXPECT_EQ(true, cxpGetP2COSize<void>());
	// getP2COSize(index1) at compile time
	EXPECT_EQ(true, cxpGetP2COSize1<void>());
	// getP2CO() at compile time
	EXPECT_EQ(true, cxpGetP2CO<void>());

	// getP2OO()=off
	success = false;
	try { xenums::Pcombs::V0.getP2OO(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2EOSize());
	EXPECT_EQ(2, value.getP2COSize());

	EXPECT_EQ(3, value.getP2EOSize(0));
	EXPECT_EQ(3, value.getP2COSize(0));
	EXPECT_EQ(1, value.getP2EOSize(1));
	EXPECT_EQ(1, value.getP2COSize(1));

	success = false;
	try { value.getP2EOSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2COSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(33, value.getP2EO(0, 0));
	EXPECT_EQ(35, value.getP2CO(0, 0));
	EXPECT_EQ(-32, value.getP2EO(0, 1));
	EXPECT_EQ(-33, value.getP2CO(0, 1));
	EXPECT_EQ(34, value.getP2EO(0, 2));
	EXPECT_EQ(36, value.getP2CO(0, 2));
	success = false;
	try { value.getP2EO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2CO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-32, value.getP2EO(1, 0));
	EXPECT_EQ(-33, value.getP2CO(1, 0));
	success = false;
	try { value.getP2EO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2CO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getP2EO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2CO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2EOSize());
	EXPECT_EQ(0, value.getP2COSize());

	success = false;
	try { value.getP2EOSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2COSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getP2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2EOSize());
	EXPECT_EQ(1, value.getP2COSize());

	EXPECT_EQ(0, value.getP2EOSize(0));
	EXPECT_EQ(0, value.getP2COSize(0));
	success = false;
	try { value.getP2EOSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2COSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getP2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


} // namespace xenum
} // namespace test
