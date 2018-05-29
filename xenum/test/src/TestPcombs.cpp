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
	EXPECT_EQ(0, value.getP0S());
	EXPECT_EQ(1, value.getP0H());

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(-1, value.getP0S());
	EXPECT_EQ(-2, value.getP0H());

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(10, value.getP0S());
	EXPECT_EQ(11, value.getP0H());
}


/// Test custom properties P1* of Pcombs xenum.
TEST_F(TestPcombs, P1)
{
	xenums::Pcomb value;

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1SSize());
	EXPECT_EQ(3, value.getP1HSize());

	EXPECT_EQ(2, value.getP1S(0));
	EXPECT_EQ(4, value.getP1H(0));
	EXPECT_EQ(-3, value.getP1S(1));
	EXPECT_EQ(-4, value.getP1H(1));
	EXPECT_EQ(3, value.getP1S(2));
	EXPECT_EQ(5, value.getP1H(2));
	success = false;
	try { value.getP1S(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP1H(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1SSize());
	EXPECT_EQ(0, value.getP1HSize());
	success = false;
	try { value.getP1S(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP1H(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1SSize());
	EXPECT_EQ(1, value.getP1HSize());

	EXPECT_EQ(-3, value.getP1S(0));
	EXPECT_EQ(-4, value.getP1H(0));
	success = false;
	try { value.getP1S(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP1H(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test custom properties P2* of Pcombs xenum.
TEST_F(TestPcombs, P2)
{
	xenums::Pcomb value;

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2SSize());
	EXPECT_EQ(2, value.getP2HSize());

	EXPECT_EQ(3, value.getP2SSize(0));
	EXPECT_EQ(3, value.getP2HSize(0));
	EXPECT_EQ(1, value.getP2SSize(1));
	EXPECT_EQ(1, value.getP2HSize(1));

	success = false;
	try { value.getP2SSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2HSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(6, value.getP2S(0, 0));
	EXPECT_EQ(8, value.getP2H(0, 0));
	EXPECT_EQ(-5, value.getP2S(0, 1));
	EXPECT_EQ(-6, value.getP2H(0, 1));
	EXPECT_EQ(7, value.getP2S(0, 2));
	EXPECT_EQ(9, value.getP2H(0, 2));
	success = false;
	try { value.getP2S(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2H(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-5, value.getP2S(1, 0));
	EXPECT_EQ(-6, value.getP2H(1, 0));
	success = false;
	try { value.getP2S(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2H(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getP2S(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2H(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2SSize());
	EXPECT_EQ(0, value.getP2HSize());

	success = false;
	try { value.getP2SSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2HSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getP2S(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2H(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2SSize());
	EXPECT_EQ(1, value.getP2HSize());

	EXPECT_EQ(0, value.getP2SSize(0));
	EXPECT_EQ(0, value.getP2HSize(0));
	success = false;
	try { value.getP2SSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2HSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getP2S(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getP2H(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test custom properties S0* of Pcombs xenum.
TEST_F(TestPcombs, S0)
{
	xenums::Pcomb value;

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_STREQ("0", value.getS0S());
	EXPECT_STREQ("1", value.getS0H());
	EXPECT_EQ(2, value.getS0SSize());
	EXPECT_EQ(2, value.getS0HSize());
	// V1
	value = xenums::Pcombs::V1;
	EXPECT_STREQ("-1", value.getS0S());
	EXPECT_STREQ("-2", value.getS0H());
	EXPECT_EQ(3, value.getS0SSize());
	EXPECT_EQ(3, value.getS0HSize());
	// V2
	value = xenums::Pcombs::V2;
	EXPECT_STREQ("10", value.getS0S());
	EXPECT_STREQ("11", value.getS0H());
	EXPECT_EQ(3, value.getS0SSize());
	EXPECT_EQ(3, value.getS0HSize());
}


/// Test custom properties S1* of Pcombs xenum.
TEST_F(TestPcombs, S1)
{
	xenums::Pcomb value;

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getS1SSize());
	EXPECT_EQ(3, value.getS1HSize());

	EXPECT_STREQ("2", value.getS1S(0));
	EXPECT_STREQ("4", value.getS1H(0));
	EXPECT_EQ(2, value.getS1SSize(0));
	EXPECT_EQ(2, value.getS1HSize(0));
	EXPECT_STREQ("-3", value.getS1S(1));
	EXPECT_STREQ("-4", value.getS1H(1));
	EXPECT_EQ(3, value.getS1SSize(1));
	EXPECT_EQ(3, value.getS1HSize(1));
	EXPECT_STREQ("3", value.getS1S(2));
	EXPECT_STREQ("5", value.getS1H(2));
	EXPECT_EQ(2, value.getS1SSize(2));
	EXPECT_EQ(2, value.getS1HSize(2));
	success = false;
	try { value.getS1S(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1H(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1SSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1HSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getS1SSize());
	EXPECT_EQ(0, value.getS1HSize());
	success = false;
	try { value.getS1S(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1H(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1SSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1HSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getS1SSize());
	EXPECT_EQ(1, value.getS1HSize());

	EXPECT_STREQ("-3", value.getS1S(0));
	EXPECT_STREQ("-4", value.getS1H(0));
	EXPECT_EQ(3, value.getS1SSize(0));
	EXPECT_EQ(3, value.getS1HSize(0));
	success = false;
	try { value.getS1S(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1H(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1SSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1HSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test custom properties S2* of Pcombs xenum.
TEST_F(TestPcombs, S2)
{
	xenums::Pcomb value;

	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getS2SSize());
	EXPECT_EQ(2, value.getS2HSize());

	EXPECT_EQ(3, value.getS2SSize(0));
	EXPECT_EQ(3, value.getS2HSize(0));
	EXPECT_EQ(1, value.getS2SSize(1));
	EXPECT_EQ(1, value.getS2HSize(1));
	success = false;
	try { value.getS2SSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2HSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("6", value.getS2S(0, 0));
	EXPECT_STREQ("8", value.getS2H(0, 0));
	EXPECT_EQ(2, value.getS2SSize(0, 0));
	EXPECT_EQ(2, value.getS2HSize(0, 0));
	EXPECT_STREQ("-5", value.getS2S(0, 1));
	EXPECT_STREQ("-6", value.getS2H(0, 1));
	EXPECT_EQ(3, value.getS2SSize(0, 1));
	EXPECT_EQ(3, value.getS2HSize(0, 1));
	EXPECT_STREQ("7", value.getS2S(0, 2));
	EXPECT_STREQ("9", value.getS2H(0, 2));
	EXPECT_EQ(2, value.getS2SSize(0, 2));
	EXPECT_EQ(2, value.getS2HSize(0, 2));
	success = false;
	try { value.getS2S(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2H(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2SSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2HSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-5", value.getS2S(1, 0));
	EXPECT_STREQ("-6", value.getS2H(1, 0));
	EXPECT_EQ(3, value.getS2SSize(1, 0));
	EXPECT_EQ(3, value.getS2HSize(1, 0));
	success = false;
	try { value.getS2S(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2H(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2SSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2HSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2S(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2H(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2SSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2HSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getS2SSize());
	EXPECT_EQ(0, value.getS2HSize());

	success = false;
	try { value.getS2SSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2HSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2S(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2H(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2SSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2HSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getS2SSize());
	EXPECT_EQ(1, value.getS2HSize());

	EXPECT_EQ(0, value.getS2SSize(0));
	EXPECT_EQ(0, value.getS2HSize(0));
	success = false;
	try { value.getS2SSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2HSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2S(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2H(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2SSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2HSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


} // namespace xenum
} // namespace test
