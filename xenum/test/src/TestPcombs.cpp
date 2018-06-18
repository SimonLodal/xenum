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

/// Function that only compiles if the constexpr getP0C() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V1.getP0C() == -13, bool>::type cxpGetP0C(void) { return true; }
/// Test custom properties P0* of Pcombs xenum.
TEST_F(TestPcombs, P0)
{
	xenums::Pcomb value;

	// getP0C() at compile time
	EXPECT_EQ(true, cxpGetP0C<void>());

	// getP0O()=off
	success = false;
	try { xenums::Pcombs::V0.getP0O(); }
	catch (std::logic_error e) { EXPECT_STREQ("getP0O() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(12, value.getP0E());
	EXPECT_EQ(13, value.getP0C());

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(-12, value.getP0E());
	EXPECT_EQ(-13, value.getP0C());

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(212, value.getP0E());
	EXPECT_EQ(213, value.getP0C());
}


/// Function that only compiles if the constexpr getP1CSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1CSize() == 3, bool>::type cxpGetP1CSize(void) { return true; }
/// Function that only compiles if the constexpr getP1C() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1C(2) == 26, bool>::type cxpGetP1C(void) { return true; }
/// Test custom properties P1* of Pcombs xenum.
TEST_F(TestPcombs, P1)
{
	xenums::Pcomb value;

	// getP1CSize() at compile time
	EXPECT_EQ(true, cxpGetP1CSize<void>());
	// getP1C() at compile time
	EXPECT_EQ(true, cxpGetP1C<void>());

	// getP1O()=off
	success = false;
	try { xenums::Pcombs::V0.getP1O(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP1O() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1ESize());
	EXPECT_EQ(3, value.getP1CSize());

	EXPECT_EQ(23, value.getP1E(0));
	EXPECT_EQ(25, value.getP1C(0));
	EXPECT_EQ(-22, value.getP1E(1));
	EXPECT_EQ(-23, value.getP1C(1));
	EXPECT_EQ(24, value.getP1E(2));
	EXPECT_EQ(26, value.getP1C(2));
	success = false;
	try { value.getP1E(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP1C(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1ESize());
	EXPECT_EQ(0, value.getP1CSize());
	success = false;
	try { value.getP1E(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP1C(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1ESize());
	EXPECT_EQ(1, value.getP1CSize());

	EXPECT_EQ(-22, value.getP1E(0));
	EXPECT_EQ(-23, value.getP1C(0));
	success = false;
	try { value.getP1E(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP1C(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP2CSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CSize() == 2, bool>::type cxpGetP2CSize() { return true; }
/// Function that only compiles if the constexpr getP2CSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CSize(0) == 3, bool>::type cxpGetP2CSize1() { return true; }
/// Function that only compiles if the constexpr getP2C() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2C(1,0) == -33, bool>::type cxpGetP2C(void) { return true; }
/// Test custom properties P2* of Pcombs xenum.
TEST_F(TestPcombs, P2)
{
	xenums::Pcomb value;

	// getP2CSize() at compile time
	EXPECT_EQ(true, cxpGetP2CSize<void>());
	// getP2CSize(index1) at compile time
	EXPECT_EQ(true, cxpGetP2CSize1<void>());
	// getP2C() at compile time
	EXPECT_EQ(true, cxpGetP2C<void>());

	// getP2O()=off
	success = false;
	try { xenums::Pcombs::V0.getP2O(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP2O() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2ESize());
	EXPECT_EQ(2, value.getP2CSize());

	EXPECT_EQ(3, value.getP2ESize(0));
	EXPECT_EQ(3, value.getP2CSize(0));
	EXPECT_EQ(1, value.getP2ESize(1));
	EXPECT_EQ(1, value.getP2CSize(1));

	success = false;
	try { value.getP2ESize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2CSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(33, value.getP2E(0, 0));
	EXPECT_EQ(35, value.getP2C(0, 0));
	EXPECT_EQ(-32, value.getP2E(0, 1));
	EXPECT_EQ(-33, value.getP2C(0, 1));
	EXPECT_EQ(34, value.getP2E(0, 2));
	EXPECT_EQ(36, value.getP2C(0, 2));
	success = false;
	try { value.getP2E(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2C(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-32, value.getP2E(1, 0));
	EXPECT_EQ(-33, value.getP2C(1, 0));
	success = false;
	try { value.getP2E(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2C(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getP2E(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2C(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2ESize());
	EXPECT_EQ(0, value.getP2CSize());

	success = false;
	try { value.getP2ESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2CSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getP2E(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2C(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2ESize());
	EXPECT_EQ(1, value.getP2CSize());

	EXPECT_EQ(0, value.getP2ESize(0));
	EXPECT_EQ(0, value.getP2CSize(0));
	success = false;
	try { value.getP2ESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2CSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getP2E(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2C(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


} // namespace xenum
} // namespace test
