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

/// Function that only compiles if the constexpr getS0CSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS0CSize() == 2, bool>::type cxpGetS0CSize() { return true; }
/// Function that only compiles if the constexpr getS0C() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS0C(), "1"), bool>::type cxpGetS0C(void) { return true; }
/// Test custom properties S0* of Scombs xenum.
TEST_F(TestScombs, S0)
{
	xenums::Scomb value;

	// getS0CSize() at compile time
	EXPECT_EQ(true, cxpGetS0CSize<void>());
	// getS0C() at compile time
	EXPECT_EQ(true, cxpGetS0C<void>());

	// V0
	value = xenums::Scombs::V0;
	EXPECT_STREQ("0", value.getS0E());
	EXPECT_STREQ("1", value.getS0C());
	EXPECT_EQ(2, value.getS0ESize());
	EXPECT_EQ(2, value.getS0CSize());
	// V1
	value = xenums::Scombs::V1;
	EXPECT_STREQ("-1", value.getS0E());
	EXPECT_STREQ("-2", value.getS0C());
	EXPECT_EQ(3, value.getS0ESize());
	EXPECT_EQ(3, value.getS0CSize());
	// V2
	value = xenums::Scombs::V2;
	EXPECT_STREQ("10", value.getS0E());
	EXPECT_STREQ("11", value.getS0C());
	EXPECT_EQ(3, value.getS0ESize());
	EXPECT_EQ(3, value.getS0CSize());
}


/// Function that only compiles if the constexpr getS1CSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CSize() == 3, bool>::type cxpGetS1CSize() { return true; }
/// Function that only compiles if the constexpr getS1CSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CSize(2) == 2, bool>::type cxpGetS1CSize1() { return true; }
/// Function that only compiles if the constexpr getS1C() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1C(1), "-4"), bool>::type cxpGetS1C(void) { return true; }
/// Test custom properties S1* of Scombs xenum.
TEST_F(TestScombs, S1)
{
	xenums::Scomb value;

	// getS1CSize() at compile time
	EXPECT_EQ(true, cxpGetS1CSize<void>());
	// getS1CSize(index1) at compile time
	EXPECT_EQ(true, cxpGetS1CSize1<void>());
	// getS1C() at compile time
	EXPECT_EQ(true, cxpGetS1C<void>());

	// V0
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
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
	value = xenums::Scombs::V2;
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
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CSize() == 2, bool>::type cxpGetS2CSize() { return true; }
/// Function that only compiles if the constexpr getS2CSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CSize(0) == 3, bool>::type cxpGetS2CSize1() { return true; }
/// Function that only compiles if the constexpr getS2CSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CSize(0,2) == 2, bool>::type cxpGetS2CSize2() { return true; }
/// Function that only compiles if the constexpr getS2C() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2C(1,0), "-6"), bool>::type cxpGetS2C(void) { return true; }
/// Test custom properties S2* of Scombs xenum.
TEST_F(TestScombs, S2)
{
	xenums::Scomb value;

	// getS2CSize() at compile time
	EXPECT_EQ(true, cxpGetS2CSize<void>());
	// getS2CSize(index1) at compile time
	EXPECT_EQ(true, cxpGetS2CSize1<void>());
	// getS2CSize(index1,index2) at compile time
	EXPECT_EQ(true, cxpGetS2CSize2<void>());
	// getS2C() at compile time
	EXPECT_EQ(true, cxpGetS2C<void>());

	// V0
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
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
	value = xenums::Scombs::V2;
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
