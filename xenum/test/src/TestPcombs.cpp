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
template <class T> typename std::enable_if<xenums::Pcombs::V1.getP0C() == -2, bool>::type cxpGetP0C(void) { return true; }
/// Test custom properties P0* of Pcombs xenum.
TEST_F(TestPcombs, P0)
{
	xenums::Pcomb value;

	// getP0C() at compile time
	EXPECT_EQ(true, cxpGetP0C<void>());

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(0, value.getP0E());
	EXPECT_EQ(1, value.getP0C());

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(-1, value.getP0E());
	EXPECT_EQ(-2, value.getP0C());

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(10, value.getP0E());
	EXPECT_EQ(11, value.getP0C());
}


/// Function that only compiles if the constexpr getP1CSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1CSize() == 3, bool>::type cxpGetP1CSize(void) { return true; }
/// Function that only compiles if the constexpr getP1C() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1C(2) == 5, bool>::type cxpGetP1C(void) { return true; }
/// Test custom properties P1* of Pcombs xenum.
TEST_F(TestPcombs, P1)
{
	xenums::Pcomb value;

	// getP1CSize() at compile time
	EXPECT_EQ(true, cxpGetP1CSize<void>());
	// getP1C() at compile time
	EXPECT_EQ(true, cxpGetP1C<void>());

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1ESize());
	EXPECT_EQ(3, value.getP1CSize());

	EXPECT_EQ(2, value.getP1E(0));
	EXPECT_EQ(4, value.getP1C(0));
	EXPECT_EQ(-3, value.getP1E(1));
	EXPECT_EQ(-4, value.getP1C(1));
	EXPECT_EQ(3, value.getP1E(2));
	EXPECT_EQ(5, value.getP1C(2));
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

	EXPECT_EQ(-3, value.getP1E(0));
	EXPECT_EQ(-4, value.getP1C(0));
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
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2C(1,0) == -6, bool>::type cxpGetP2C(void) { return true; }
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

	EXPECT_EQ(6, value.getP2E(0, 0));
	EXPECT_EQ(8, value.getP2C(0, 0));
	EXPECT_EQ(-5, value.getP2E(0, 1));
	EXPECT_EQ(-6, value.getP2C(0, 1));
	EXPECT_EQ(7, value.getP2E(0, 2));
	EXPECT_EQ(9, value.getP2C(0, 2));
	success = false;
	try { value.getP2E(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2C(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-5, value.getP2E(1, 0));
	EXPECT_EQ(-6, value.getP2C(1, 0));
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


/// Function that only compiles if the constexpr getS0CSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getS0CSize() == 2, bool>::type cxpGetS0CSize() { return true; }
/// Function that only compiles if the constexpr getS0C() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Pcombs::V0.getS0C(), "1"), bool>::type cxpGetS0C(void) { return true; }
/// Test custom properties S0* of Pcombs xenum.
TEST_F(TestPcombs, S0)
{
	xenums::Pcomb value;

	// getS0CSize() at compile time
	EXPECT_EQ(true, cxpGetS0CSize<void>());
	// getS0C() at compile time
	EXPECT_EQ(true, cxpGetS0C<void>());

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_STREQ("0", value.getS0E());
	EXPECT_STREQ("1", value.getS0C());
	EXPECT_EQ(2, value.getS0ESize());
	EXPECT_EQ(2, value.getS0CSize());
	// V1
	value = xenums::Pcombs::V1;
	EXPECT_STREQ("-1", value.getS0E());
	EXPECT_STREQ("-2", value.getS0C());
	EXPECT_EQ(3, value.getS0ESize());
	EXPECT_EQ(3, value.getS0CSize());
	// V2
	value = xenums::Pcombs::V2;
	EXPECT_STREQ("10", value.getS0E());
	EXPECT_STREQ("11", value.getS0C());
	EXPECT_EQ(3, value.getS0ESize());
	EXPECT_EQ(3, value.getS0CSize());
}


/// Function that only compiles if the constexpr getS1CSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getS1CSize() == 3, bool>::type cxpGetS1CSize() { return true; }
/// Function that only compiles if the constexpr getS1CSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getS1CSize(2) == 2, bool>::type cxpGetS1CSize1() { return true; }
/// Function that only compiles if the constexpr getS1C() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Pcombs::V0.getS1C(1), "-4"), bool>::type cxpGetS1C(void) { return true; }
/// Test custom properties S1* of Pcombs xenum.
TEST_F(TestPcombs, S1)
{
	xenums::Pcomb value;

	// getS1CSize() at compile time
	EXPECT_EQ(true, cxpGetS1CSize<void>());
	// getS1CSize(index1) at compile time
	EXPECT_EQ(true, cxpGetS1CSize1<void>());
	// getS1C() at compile time
	EXPECT_EQ(true, cxpGetS1C<void>());

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getS1ESize());
	EXPECT_EQ(3, value.getS1CSize());

	EXPECT_STREQ("2", value.getS1E(0));
	EXPECT_STREQ("4", value.getS1C(0));
	EXPECT_EQ(2, value.getS1ESize(0));
	EXPECT_EQ(2, value.getS1CSize(0));
	EXPECT_STREQ("-3", value.getS1E(1));
	EXPECT_STREQ("-4", value.getS1C(1));
	EXPECT_EQ(3, value.getS1ESize(1));
	EXPECT_EQ(3, value.getS1CSize(1));
	EXPECT_STREQ("3", value.getS1E(2));
	EXPECT_STREQ("5", value.getS1C(2));
	EXPECT_EQ(2, value.getS1ESize(2));
	EXPECT_EQ(2, value.getS1CSize(2));
	success = false;
	try { value.getS1E(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1C(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1ESize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1CSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getS1ESize());
	EXPECT_EQ(0, value.getS1CSize());
	success = false;
	try { value.getS1E(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1C(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1ESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1CSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getS1ESize());
	EXPECT_EQ(1, value.getS1CSize());

	EXPECT_STREQ("-3", value.getS1E(0));
	EXPECT_STREQ("-4", value.getS1C(0));
	EXPECT_EQ(3, value.getS1ESize(0));
	EXPECT_EQ(3, value.getS1CSize(0));
	success = false;
	try { value.getS1E(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1C(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1ESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1CSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS2CSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getS2CSize() == 2, bool>::type cxpGetS2CSize() { return true; }
/// Function that only compiles if the constexpr getS2CSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getS2CSize(0) == 3, bool>::type cxpGetS2CSize1() { return true; }
/// Function that only compiles if the constexpr getS2CSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getS2CSize(0,2) == 2, bool>::type cxpGetS2CSize2() { return true; }
/// Function that only compiles if the constexpr getS2C() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Pcombs::V0.getS2C(1,0), "-6"), bool>::type cxpGetS2C(void) { return true; }
/// Test custom properties S2* of Pcombs xenum.
TEST_F(TestPcombs, S2)
{
	xenums::Pcomb value;

	// getS2CSize() at compile time
	EXPECT_EQ(true, cxpGetS2CSize<void>());
	// getS2CSize(index1) at compile time
	EXPECT_EQ(true, cxpGetS2CSize1<void>());
	// getS2CSize(index1,index2) at compile time
	EXPECT_EQ(true, cxpGetS2CSize2<void>());
	// getS2C() at compile time
	EXPECT_EQ(true, cxpGetS2C<void>());

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getS2ESize());
	EXPECT_EQ(2, value.getS2CSize());

	EXPECT_EQ(3, value.getS2ESize(0));
	EXPECT_EQ(3, value.getS2CSize(0));
	EXPECT_EQ(1, value.getS2ESize(1));
	EXPECT_EQ(1, value.getS2CSize(1));
	success = false;
	try { value.getS2ESize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("6", value.getS2E(0, 0));
	EXPECT_STREQ("8", value.getS2C(0, 0));
	EXPECT_EQ(2, value.getS2ESize(0, 0));
	EXPECT_EQ(2, value.getS2CSize(0, 0));
	EXPECT_STREQ("-5", value.getS2E(0, 1));
	EXPECT_STREQ("-6", value.getS2C(0, 1));
	EXPECT_EQ(3, value.getS2ESize(0, 1));
	EXPECT_EQ(3, value.getS2CSize(0, 1));
	EXPECT_STREQ("7", value.getS2E(0, 2));
	EXPECT_STREQ("9", value.getS2C(0, 2));
	EXPECT_EQ(2, value.getS2ESize(0, 2));
	EXPECT_EQ(2, value.getS2CSize(0, 2));
	success = false;
	try { value.getS2E(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2C(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2ESize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-5", value.getS2E(1, 0));
	EXPECT_STREQ("-6", value.getS2C(1, 0));
	EXPECT_EQ(3, value.getS2ESize(1, 0));
	EXPECT_EQ(3, value.getS2CSize(1, 0));
	success = false;
	try { value.getS2E(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2C(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2ESize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2E(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2C(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2ESize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getS2ESize());
	EXPECT_EQ(0, value.getS2CSize());

	success = false;
	try { value.getS2ESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2E(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2C(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2ESize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getS2ESize());
	EXPECT_EQ(1, value.getS2CSize());

	EXPECT_EQ(0, value.getS2ESize(0));
	EXPECT_EQ(0, value.getS2CSize(0));
	success = false;
	try { value.getS2ESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2E(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2C(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2ESize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


} // namespace xenum
} // namespace test
