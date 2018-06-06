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

/// Test custom properties P0* of Pcombs xenum.
TEST_F(TestPcombs, P0)
{
	xenums::Pcomb value;

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


/// Test custom properties P1* of Pcombs xenum.
TEST_F(TestPcombs, P1)
{
	xenums::Pcomb value;

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


/// Test custom properties P2* of Pcombs xenum.
TEST_F(TestPcombs, P2)
{
	xenums::Pcomb value;

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


/// Test custom properties S0* of Pcombs xenum.
TEST_F(TestPcombs, S0)
{
	xenums::Pcomb value;

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


/// Test custom properties S1* of Pcombs xenum.
TEST_F(TestPcombs, S1)
{
	xenums::Pcomb value;

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


/// Test custom properties S2* of Pcombs xenum.
TEST_F(TestPcombs, S2)
{
	xenums::Pcomb value;

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
