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
	xenums::Pcomb value;
	int intval;
};


/// Test custom properties P0* of Pcombs xenum.
TEST_F(TestPcombs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_Pcombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::Pcombs::_size);
}


// ========================================= Depth=0 ============================================
// =========================== depth=0 get=off ===============================

/// Test xenum with identifier features: depth=0, getValue=off, fromValue=off
TEST_F(TestPcombs, P0OffOff)
{
	// getValue=off
	try { success = false; xenums::Pcombs::V0.getP0OO(); }
	catch (std::logic_error e) { EXPECT_STREQ("getP0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::Pcombs::_fromP0OO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Pcombs::_fromP0OO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=off, fromValue=ext
TEST_F(TestPcombs, P0OffExt)
{
	// getValue=off
	try { success = false; xenums::Pcombs::V0.getP0OE(); }
	catch (std::logic_error e) { EXPECT_STREQ("getP0OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1001;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0OE(intval));
	intval = -1001;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0OE(intval));
	intval = 1021;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0OE(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP0OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP0OE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=off, fromValue=inl
TEST_F(TestPcombs, P0OffInl)
{
	// getValue=off
	try { success = false; xenums::Pcombs::V0.getP0OI(); }
	catch (std::logic_error e) { EXPECT_STREQ("getP0OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1002;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0OI(intval));
	intval = -1002;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0OI(intval));
	intval = 1022;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0OI(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP0OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP0OI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=off, fromValue=cxp
TEST_F(TestPcombs, P0OffCxp)
{
	// getValue=off
	try { success = false; xenums::Pcombs::V0.getP0OC(); }
	catch (std::logic_error e) { EXPECT_STREQ("getP0OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

// FIXME: fromValue() at compile time.

	// fromValue
	intval = 1003;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0OC(intval));
	intval = -1003;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0OC(intval));
	intval = 1023;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0OC(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP0OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP0OC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue (at runtime)
	intval = 1003;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP0OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP0OC(intval));
	intval = -1003;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP0OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP0OC(intval));
	intval = 1023;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP0OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP0OC(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_cxpFromP0OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_cxpFromP0OC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=0 get=ext ===============================

/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=off
TEST_F(TestPcombs, P0ExtOff)
{
	// getValue()
	EXPECT_EQ(1004, xenums::Pcombs::V0.getP0EO());
	EXPECT_EQ(-1004, xenums::Pcombs::V1.getP0EO());
	EXPECT_EQ(1024, xenums::Pcombs::V2.getP0EO());

	// fromValue=off
	try { success = false; xenums::Pcombs::_fromP0EO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP0EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Pcombs::_fromP0EO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP0EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=ext
TEST_F(TestPcombs, P0ExtExt)
{
	// getValue()
	EXPECT_EQ(1005, xenums::Pcombs::V0.getP0EE());
	EXPECT_EQ(-1005, xenums::Pcombs::V1.getP0EE());
	EXPECT_EQ(1025, xenums::Pcombs::V2.getP0EE());

	// fromValue
	intval = 1005;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0EE(intval));
	intval = -1005;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0EE(intval));
	intval = 1025;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0EE(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP0EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP0EE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=inl
TEST_F(TestPcombs, P0ExtInl)
{
	// getValue()
	EXPECT_EQ(1006, xenums::Pcombs::V0.getP0EI());
	EXPECT_EQ(-1006, xenums::Pcombs::V1.getP0EI());
	EXPECT_EQ(1026, xenums::Pcombs::V2.getP0EI());

	// fromValue
	intval = 1006;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0EI(intval));
	intval = -1006;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0EI(intval));
	intval = 1026;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0EI(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP0EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP0EI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=cxp
TEST_F(TestPcombs, P0ExtCxp)
{
	// getValue()
	EXPECT_EQ(1007, xenums::Pcombs::V0.getP0EC());
	EXPECT_EQ(-1007, xenums::Pcombs::V1.getP0EC());
	EXPECT_EQ(1027, xenums::Pcombs::V2.getP0EC());

// FIXME: fromValue() at compile time.

	// fromValue
	intval = 1007;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0EC(intval));
	intval = -1007;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0EC(intval));
	intval = 1027;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0EC(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP0EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP0EC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue (at runtime)
	intval = 1007;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP0EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP0EC(intval));
	intval = -1007;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP0EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP0EC(intval));
	intval = 1027;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP0EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP0EC(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_cxpFromP0EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_cxpFromP0EC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=0 get=cxp ===============================

/// Function that only compiles if the constexpr getP0CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP0CO() == 1008, bool>::type cxpGetP0CO(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=off
TEST_F(TestPcombs, P0CxpOff)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP0CO<void>());

	// getValue()
	EXPECT_EQ(1008, xenums::Pcombs::V0.getP0CO());
	EXPECT_EQ(-1008, xenums::Pcombs::V1.getP0CO());
	EXPECT_EQ(1028, xenums::Pcombs::V2.getP0CO());

	// fromValue=off
	try { success = false; xenums::Pcombs::_fromP0CO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP0CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Pcombs::_fromP0CO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP0CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP0CE() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP0CE() == 1009, bool>::type cxpGetP0CE(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=ext
TEST_F(TestPcombs, P0CxpExt)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP0CE<void>());

	// getValue()
	EXPECT_EQ(1009, xenums::Pcombs::V0.getP0CE());
	EXPECT_EQ(-1009, xenums::Pcombs::V1.getP0CE());
	EXPECT_EQ(1029, xenums::Pcombs::V2.getP0CE());

	// fromValue
	intval = 1009;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0CE(intval));
	intval = -1009;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0CE(intval));
	intval = 1029;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0CE(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP0CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP0CE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP0CI() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP0CI() == 1010, bool>::type cxpGetP0CI(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=inl
TEST_F(TestPcombs, P0CxpInl)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP0CI<void>());

	// getValue()
	EXPECT_EQ(1010, xenums::Pcombs::V0.getP0CI());
	EXPECT_EQ(-1010, xenums::Pcombs::V1.getP0CI());
	EXPECT_EQ(1030, xenums::Pcombs::V2.getP0CI());

	// fromValue
	intval = 1010;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0CI(intval));
	intval = -1010;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0CI(intval));
	intval = 1030;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0CI(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP0CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP0CI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP0CC() == 1011, bool>::type cxpGetP0CC(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=cxp
TEST_F(TestPcombs, P0CxpCxp)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP0CC<void>());

	// getValue()
	EXPECT_EQ(1011, xenums::Pcombs::V0.getP0CC());
	EXPECT_EQ(-1011, xenums::Pcombs::V1.getP0CC());
	EXPECT_EQ(1031, xenums::Pcombs::V2.getP0CC());

// FIXME: fromValue() at compile time.

	// fromValue
	intval = 1011;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0CC(intval));
	intval = -1011;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0CC(intval));
	intval = 1031;
	EXPECT_EQ(true, xenums::Pcombs::_fromP0CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_fromP0CC(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP0CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP0CC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue (at runtime)
	intval = 1011;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP0CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP0CC(intval));
	intval = -1011;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP0CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V1);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP0CC(intval));
	intval = 1031;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP0CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP0CC(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_cxpFromP0CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_cxpFromP0CC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P0CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= Depth=1 ============================================
// =========================== depth=1 get=off ===============================

/// Test xenum with identifier features: depth=1, getValue=off, fromValue=off
TEST_F(TestPcombs, P1OffOff)
{
	// getValue()=off
	try { success = false; xenums::Pcombs::V0.getP1OO(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::Pcombs::_fromP1OO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Pcombs::_fromP1OO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=off, fromValue=ext
TEST_F(TestPcombs, P1OffExt)
{
	// getValue()=off
	try { success = false; xenums::Pcombs::V0.getP1OE(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP1OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1102;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1OE(intval));
	// Not unique
	//intval = -1101;
	//EXPECT_EQ(true, xenums::Pcombs::_fromP1OE(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_fromP1OE(intval));
	intval = 1103;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1OE(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP1OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP1OE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=off, fromValue=inl
TEST_F(TestPcombs, P1OffInl)
{
	// getValue()=off
	try { success = false; xenums::Pcombs::V0.getP1OI(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP1OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1104;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1OI(intval));
	// Not unique
	//intval = -1102;
	//EXPECT_EQ(true, xenums::Pcombs::_fromP1OI(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_fromP1OI(intval));
	intval = 1105;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1OI(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP1OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP1OI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=off, fromValue=cxp
TEST_F(TestPcombs, P1OffCxp)
{
	// getValue()=off
	try { success = false; xenums::Pcombs::V0.getP1OC(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP1OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

// FIXME: fromValue() at compile time.

	// fromValue
	intval = 1106;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1OC(intval));
	// Not unique
	//intval = -1103;
	//EXPECT_EQ(true, xenums::Pcombs::_fromP1OC(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_fromP1OC(intval));
	intval = 1107;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1OC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP1OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP1OC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue (at runtime)
	intval = 1106;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP1OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP1OC(intval));
	// Not unique
	//intval = -1103;
	//EXPECT_EQ(true, xenums::Pcombs::_cxpFromP1OC(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_cxpFromP1OC(intval));
	intval = 1107;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP1OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP1OC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_cxpFromP1OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_cxpFromP1OC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


// =========================== depth=1 get=ext ===============================
/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=off
TEST_F(TestPcombs, P1ExtOff)
{
	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1EOSize());
	EXPECT_EQ(1110, value.getP1EO(0));
	EXPECT_EQ(-1104, value.getP1EO(1));
	EXPECT_EQ(1111, value.getP1EO(2));
	try { success = false; value.getP1EO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1EOSize());
	try { success = false; value.getP1EO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1EOSize());
	EXPECT_EQ(-1104, value.getP1EO(0));
	try { success = false; value.getP1EO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::Pcombs::_fromP1EO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Pcombs::_fromP1EO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=ext
TEST_F(TestPcombs, P1ExtExt)
{
	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1EESize());
	EXPECT_EQ(1112, value.getP1EE(0));
	EXPECT_EQ(-1105, value.getP1EE(1));
	EXPECT_EQ(1113, value.getP1EE(2));
	try { success = false; value.getP1EE(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1EESize());
	try { success = false; value.getP1EE(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1EESize());
	EXPECT_EQ(-1105, value.getP1EE(0));
	try { success = false; value.getP1EE(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1112;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1EE(intval));
	// Not unique
	//intval = -1105;
	//EXPECT_EQ(true, xenums::Pcombs::_fromP1EE(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_fromP1EE(intval));
	intval = 1113;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1EE(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP1EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP1EE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=inl
TEST_F(TestPcombs, P1ExtInl)
{
	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1EISize());
	EXPECT_EQ(1114, value.getP1EI(0));
	EXPECT_EQ(-1106, value.getP1EI(1));
	EXPECT_EQ(1115, value.getP1EI(2));
	try { success = false; value.getP1EI(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1EISize());
	try { success = false; value.getP1EI(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1EISize());
	EXPECT_EQ(-1106, value.getP1EI(0));
	try { success = false; value.getP1EI(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1114;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1EI(intval));
	// Not unique
	//intval = -1106;
	//EXPECT_EQ(true, xenums::Pcombs::_fromP1EI(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V1);
	//EXPECT_EQ(value, xenums::Pcombs::_fromP1EI(intval));
	intval = 1115;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1EI(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP1EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP1EI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=cxp
TEST_F(TestPcombs, P1ExtCxp)
{
	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1ECSize());
	EXPECT_EQ(1116, value.getP1EC(0));
	EXPECT_EQ(-1107, value.getP1EC(1));
	EXPECT_EQ(1117, value.getP1EC(2));
	try { success = false; value.getP1EC(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1ECSize());
	try { success = false; value.getP1EC(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1ECSize());
	EXPECT_EQ(-1107, value.getP1EC(0));
	try { success = false; value.getP1EC(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

// FIXME: fromValue() at compile time.

	// fromValue
	intval = 1116;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1EC(intval));
	// Not unique
	//intval = -1107;
	//EXPECT_EQ(true, xenums::Pcombs::_fromP1EC(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_fromP1EC(intval));
	intval = 1117;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1EC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP1EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP1EC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue (at runtime)
	intval = 1116;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP1EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP1EC(intval));
	// Not unique
	//intval = -1107;
	//EXPECT_EQ(true, xenums::Pcombs::_cxpFromP1EC(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_cxpFromP1EC(intval));
	intval = 1117;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP1EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP1EC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_cxpFromP1EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_cxpFromP1EC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=1 get=cxp ===============================
/// Function that only compiles if the constexpr getP1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1COSize() == 3, bool>::type cxpGetP1COSize(void) { return true; }
/// Function that only compiles if the constexpr getP1CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1CO(2) == 1121, bool>::type cxpGetP1CO(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=off
TEST_F(TestPcombs, P1CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP1COSize<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP1CO<void>());

	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1COSize());
	EXPECT_EQ(1120, value.getP1CO(0));
	EXPECT_EQ(-1108, value.getP1CO(1));
	EXPECT_EQ(1121, value.getP1CO(2));
	try { success = false; value.getP1CO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1COSize());
	try { success = false; value.getP1CO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1COSize());
	EXPECT_EQ(-1108, value.getP1CO(0));
	try { success = false; value.getP1CO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::Pcombs::_fromP1CO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Pcombs::_fromP1CO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP1CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1CESize() == 3, bool>::type cxpGetP1CESize(void) { return true; }
/// Function that only compiles if the constexpr getP1CE() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1CE(2) == 1123, bool>::type cxpGetP1CE(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=ext
TEST_F(TestPcombs, P1CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP1CESize<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP1CE<void>());

	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1CESize());
	EXPECT_EQ(1122, value.getP1CE(0));
	EXPECT_EQ(-1109, value.getP1CE(1));
	EXPECT_EQ(1123, value.getP1CE(2));
	try { success = false; value.getP1CE(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1CESize());
	try { success = false; value.getP1CE(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1CESize());
	EXPECT_EQ(-1109, value.getP1CE(0));
	try { success = false; value.getP1CE(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1122;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1CE(intval));
	// Not unique
	//intval = -1109;
	//EXPECT_EQ(true, xenums::Pcombs::_fromP1CE(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_fromP1CE(intval));
	intval = 1123;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1CE(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP1CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP1CE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP1CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1CISize() == 3, bool>::type cxpGetP1CISize(void) { return true; }
/// Function that only compiles if the constexpr getP1CI() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1CI(2) == 1125, bool>::type cxpGetP1CI(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=inl
TEST_F(TestPcombs, P1CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP1CISize<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP1CI<void>());

	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1CISize());
	EXPECT_EQ(1124, value.getP1CI(0));
	EXPECT_EQ(-1110, value.getP1CI(1));
	EXPECT_EQ(1125, value.getP1CI(2));
	try { success = false; value.getP1CI(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1CISize());
	try { success = false; value.getP1CI(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1CISize());
	EXPECT_EQ(-1110, value.getP1CI(0));
	try { success = false; value.getP1CI(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1124;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1CI(intval));
	// Not unique
	//intval = -1110;
	//EXPECT_EQ(true, xenums::Pcombs::_fromP1CI(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_fromP1CI(intval));
	intval = 1125;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1CI(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP1CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP1CI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP1CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1CCSize() == 3, bool>::type cxpGetP1CCSize(void) { return true; }
/// Function that only compiles if the constexpr getP1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP1CC(2) == 1127, bool>::type cxpGetP1CC(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=cxp
TEST_F(TestPcombs, P1CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP1CCSize<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP1CC<void>());

	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(3, value.getP1CCSize());
	EXPECT_EQ(1126, value.getP1CC(0));
	EXPECT_EQ(-1111, value.getP1CC(1));
	EXPECT_EQ(1127, value.getP1CC(2));
	try { success = false; value.getP1CC(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP1CCSize());
	try { success = false; value.getP1CC(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP1CCSize());
	EXPECT_EQ(-1111, value.getP1CC(0));
	try { success = false; value.getP1CC(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

// FIXME: fromValue() at compile time.

	// fromValue
	intval = 1126;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1CC(intval));
	// Not unique
	//intval = -1111;
	//EXPECT_EQ(true, xenums::Pcombs::_fromP1CC(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_fromP1CC(intval));
	intval = 1127;
	EXPECT_EQ(true, xenums::Pcombs::_fromP1CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP1CC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP1CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP1CC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue (at runtime)
	intval = 1126;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP1CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP1CC(intval));
	// Not unique
	//intval = -1111;
	//EXPECT_EQ(true, xenums::Pcombs::_cxpFromP1CC(intval, value));
	//EXPECT_EQ(value, xenums::Pcombs::V0|V2);
	//EXPECT_EQ(value, xenums::Pcombs::_cxpFromP1CC(intval));
	intval = 1127;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP1CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP1CC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_cxpFromP1CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_cxpFromP1CC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= Depth=2 ============================================
// =========================== depth=2 get=off ===============================

/// Test xenum with identifier features: depth=2, getValue=off, fromValue=off
TEST_F(TestPcombs, P2OffOff)
{
	// getValue=off
	try { success = false; xenums::Pcombs::V0.getP2OO(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::Pcombs::_fromP2OO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Pcombs::_fromP2OO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=off, fromValue=ext
TEST_F(TestPcombs, P2OffExt)
{
	// getValue=off
	try { success = false; xenums::Pcombs::V0.getP2OE(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP2OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1202;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2OE(intval));
	intval = 1203;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2OE(intval));
	// Not unique, but both are in V0
	intval = -1201;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2OE(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP2OE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP2OE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=off, fromValue=inl
TEST_F(TestPcombs, P2OffInl)
{
	// getValue=off
	try { success = false; xenums::Pcombs::V0.getP2OI(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP2OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1204;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2OI(intval));
	intval = 1205;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2OI(intval));
	// Not unique, but both are in V0
	intval = -1202;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2OI(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP2OI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP2OI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=off, fromValue=cxp
TEST_F(TestPcombs, P2OffCxp)
{
	// getValue=off
	try { success = false; xenums::Pcombs::V0.getP2OC(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP2OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

// FIXME: fromValue() at compile time.

	// fromValue
	intval = 1206;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2OC(intval));
	intval = 1207;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2OC(intval));
	// Not unique, but both are in V0
	intval = -1203;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2OC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP2OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP2OC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue (at runtime)
	intval = 1206;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP2OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP2OC(intval));
	intval = 1207;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP2OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP2OC(intval));
	// Not unique, but both are in V0
	intval = -1203;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP2OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP2OC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_cxpFromP2OC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_cxpFromP2OC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=2 get=ext ===============================

/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=off
TEST_F(TestPcombs, P2ExtOff)
{
	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2EOSize());
	EXPECT_EQ(3, value.getP2EOSize(0));
	EXPECT_EQ(1, value.getP2EOSize(1));
	try { success = false; value.getP2EOSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1210, value.getP2EO(0, 0));
	EXPECT_EQ(-1204, value.getP2EO(0, 1));
	EXPECT_EQ(1211, value.getP2EO(0, 2));
	try { success = false; value.getP2EO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1204, value.getP2EO(1, 0));
	try { success = false; value.getP2EO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2EO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2EOSize());
	try { success = false; value.getP2EOSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2EOSize());
	EXPECT_EQ(0, value.getP2EOSize(0));
	try { success = false; value.getP2EOSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::Pcombs::_fromP2EO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Pcombs::_fromP2EO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=ext
TEST_F(TestPcombs, P2ExtExt)
{
	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2EESize());
	EXPECT_EQ(3, value.getP2EESize(0));
	EXPECT_EQ(1, value.getP2EESize(1));
	try { success = false; value.getP2EESize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1212, value.getP2EE(0, 0));
	EXPECT_EQ(-1205, value.getP2EE(0, 1));
	EXPECT_EQ(1213, value.getP2EE(0, 2));
	try { success = false; value.getP2EE(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1205, value.getP2EE(1, 0));
	try { success = false; value.getP2EE(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2EE(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2EESize());
	try { success = false; value.getP2EESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2EESize());
	EXPECT_EQ(0, value.getP2EESize(0));
	try { success = false; value.getP2EESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1212;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2EE(intval));
	intval = 1213;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2EE(intval));
	// Not unique, but both are in V0
	intval = -1205;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2EE(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP2EE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP2EE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=inl
TEST_F(TestPcombs, P2ExtInl)
{
	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2EISize());
	EXPECT_EQ(3, value.getP2EISize(0));
	EXPECT_EQ(1, value.getP2EISize(1));
	try { success = false; value.getP2EISize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1214, value.getP2EI(0, 0));
	EXPECT_EQ(-1206, value.getP2EI(0, 1));
	EXPECT_EQ(1215, value.getP2EI(0, 2));
	try { success = false; value.getP2EI(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1206, value.getP2EI(1, 0));
	try { success = false; value.getP2EI(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2EI(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2EISize());
	try { success = false; value.getP2EISize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2EISize());
	EXPECT_EQ(0, value.getP2EISize(0));
	try { success = false; value.getP2EISize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1214;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2EI(intval));
	intval = 1215;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2EI(intval));
	// Not unique, but both are in V0
	intval = -1206;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2EI(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP2EI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP2EI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=cxp
TEST_F(TestPcombs, P2ExtCxp)
{
	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2ECSize());
	EXPECT_EQ(3, value.getP2ECSize(0));
	EXPECT_EQ(1, value.getP2ECSize(1));
	try { success = false; value.getP2ECSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1216, value.getP2EC(0, 0));
	EXPECT_EQ(-1207, value.getP2EC(0, 1));
	EXPECT_EQ(1217, value.getP2EC(0, 2));
	try { success = false; value.getP2EC(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1207, value.getP2EC(1, 0));
	try { success = false; value.getP2EC(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2EC(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2ECSize());
	try { success = false; value.getP2ECSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2ECSize());
	EXPECT_EQ(0, value.getP2ECSize(0));
	try { success = false; value.getP2ECSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

// FIXME: fromValue() at compile time.

	// fromValue
	intval = 1216;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2EC(intval));
	intval = 1217;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2EC(intval));
	// Not unique, but both are in V0
	intval = -1207;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2EC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP2EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP2EC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue (at runtime)
	intval = 1216;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP2EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP2EC(intval));
	intval = 1217;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP2EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP2EC(intval));
	// Not unique, but both are in V0
	intval = -1207;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP2EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP2EC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_cxpFromP2EC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_cxpFromP2EC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=2 get=cxp ===============================

/// Function that only compiles if the constexpr getP2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2COSize() == 2, bool>::type cxpGetP2COSize() { return true; }
/// Function that only compiles if the constexpr getP2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2COSize(0) == 3, bool>::type cxpGetP2COSize1() { return true; }
/// Function that only compiles if the constexpr getP2CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CO(1,0) == -1208, bool>::type cxpGetP2CO(void) { return true; }
/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=off
TEST_F(TestPcombs, P2CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP2COSize<void>());
	// getValueSize(index1) at compile time
	EXPECT_EQ(true, cxpGetP2COSize1<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP2CO<void>());

	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2COSize());
	EXPECT_EQ(3, value.getP2COSize(0));
	EXPECT_EQ(1, value.getP2COSize(1));
	try { success = false; value.getP2COSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1220, value.getP2CO(0, 0));
	EXPECT_EQ(-1208, value.getP2CO(0, 1));
	EXPECT_EQ(1221, value.getP2CO(0, 2));
	try { success = false; value.getP2CO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1208, value.getP2CO(1, 0));
	try { success = false; value.getP2CO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2CO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2COSize());
	try { success = false; value.getP2COSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2COSize());
	EXPECT_EQ(0, value.getP2COSize(0));
	try { success = false; value.getP2COSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::Pcombs::_fromP2CO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Pcombs::_fromP2CO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP2CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CESize() == 2, bool>::type cxpGetP2CESize() { return true; }
/// Function that only compiles if the constexpr getP2CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CESize(0) == 3, bool>::type cxpGetP2CESize1() { return true; }
/// Function that only compiles if the constexpr getP2CE() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CE(1,0) == -1209, bool>::type cxpGetP2CE(void) { return true; }
/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=ext
TEST_F(TestPcombs, P2CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP2CESize<void>());
	// getValueSize(index1) at compile time
	EXPECT_EQ(true, cxpGetP2CESize1<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP2CE<void>());

	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2CESize());
	EXPECT_EQ(3, value.getP2CESize(0));
	EXPECT_EQ(1, value.getP2CESize(1));
	try { success = false; value.getP2CESize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1222, value.getP2CE(0, 0));
	EXPECT_EQ(-1209, value.getP2CE(0, 1));
	EXPECT_EQ(1223, value.getP2CE(0, 2));
	try { success = false; value.getP2CE(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1209, value.getP2CE(1, 0));
	try { success = false; value.getP2CE(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2CE(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2CESize());
	try { success = false; value.getP2CESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2CESize());
	EXPECT_EQ(0, value.getP2CESize(0));
	try { success = false; value.getP2CESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1222;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2CE(intval));
	intval = 1223;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2CE(intval));
	// Not unique, but both are in V0
	intval = -1209;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2CE(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP2CE(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP2CE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP2CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CISize() == 2, bool>::type cxpGetP2CISize() { return true; }
/// Function that only compiles if the constexpr getP2CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CISize(0) == 3, bool>::type cxpGetP2CISize1() { return true; }
/// Function that only compiles if the constexpr getP2CI() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CI(1,0) == -1210, bool>::type cxpGetP2CI(void) { return true; }
/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=inl
TEST_F(TestPcombs, P2CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP2CISize<void>());
	// getValueSize(index1) at compile time
	EXPECT_EQ(true, cxpGetP2CISize1<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP2CI<void>());

	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2CISize());
	EXPECT_EQ(3, value.getP2CISize(0));
	EXPECT_EQ(1, value.getP2CISize(1));
	try { success = false; value.getP2CISize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1224, value.getP2CI(0, 0));
	EXPECT_EQ(-1210, value.getP2CI(0, 1));
	EXPECT_EQ(1225, value.getP2CI(0, 2));
	try { success = false; value.getP2CI(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1210, value.getP2CI(1, 0));
	try { success = false; value.getP2CI(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2CI(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2CISize());
	try { success = false; value.getP2CISize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2CISize());
	EXPECT_EQ(0, value.getP2CISize(0));
	try { success = false; value.getP2CISize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1224;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2CI(intval));
	intval = 1225;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2CI(intval));
	// Not unique, but both are in V0
	intval = -1210;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2CI(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP2CI(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP2CI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP2CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CCSize() == 2, bool>::type cxpGetP2CCSize() { return true; }
/// Function that only compiles if the constexpr getP2CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CCSize(0) == 3, bool>::type cxpGetP2CCSize1() { return true; }
/// Function that only compiles if the constexpr getP2CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP2CC(1,0) == -1211, bool>::type cxpGetP2CC(void) { return true; }
/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=cxp
TEST_F(TestPcombs, P2CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP2CCSize<void>());
	// getValueSize(index1) at compile time
	EXPECT_EQ(true, cxpGetP2CCSize1<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP2CC<void>());

	// getValue()
	// V0
	value = xenums::Pcombs::V0;
	EXPECT_EQ(2, value.getP2CCSize());
	EXPECT_EQ(3, value.getP2CCSize(0));
	EXPECT_EQ(1, value.getP2CCSize(1));
	try { success = false; value.getP2CCSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1226, value.getP2CC(0, 0));
	EXPECT_EQ(-1211, value.getP2CC(0, 1));
	EXPECT_EQ(1227, value.getP2CC(0, 2));
	try { success = false; value.getP2CC(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1211, value.getP2CC(1, 0));
	try { success = false; value.getP2CC(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2CC(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Pcombs::V1;
	EXPECT_EQ(0, value.getP2CCSize());
	try { success = false; value.getP2CCSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Pcombs::V2;
	EXPECT_EQ(1, value.getP2CCSize());
	EXPECT_EQ(0, value.getP2CCSize(0));
	try { success = false; value.getP2CCSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

// FIXME: fromValue() at compile time.

	// fromValue
	intval = 1226;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2CC(intval));
	intval = 1227;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2CC(intval));
	// Not unique, but both are in V0
	intval = -1211;
	EXPECT_EQ(true, xenums::Pcombs::_fromP2CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_fromP2CC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_fromP2CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_fromP2CC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue (at runtime)
	intval = 1226;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP2CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP2CC(intval));
	intval = 1227;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP2CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP2CC(intval));
	// Not unique, but both are in V0
	intval = -1211;
	EXPECT_EQ(true, xenums::Pcombs::_cxpFromP2CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V0);
	EXPECT_EQ(value, xenums::Pcombs::_cxpFromP2CC(intval));

	value = xenums::Pcombs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::Pcombs::_cxpFromP2CC(intval, value));
	EXPECT_EQ(value, xenums::Pcombs::V2);
	try { success = false; xenums::Pcombs::_cxpFromP2CC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
