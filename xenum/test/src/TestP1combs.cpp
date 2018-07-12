/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * FIXME: Test bool fromValue()
 */

// For debug only
#include <iostream>
#include <string>
#include <type_traits>

#include <gtest/gtest.h>

/// To get throwing getValue() and fromValue() instead of not
/// compiling them when they are "off".
#define _XENUM5_UNIT_TEST	1

#include <test/xenum/xenums/P1combs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenums with combinations of custom property options.
 */
class TestP1combs : public ::testing::Test {
public:
	bool success;
	xenums::P1comb value;
	int intval;
};


/// Test custom properties P0* of P1combs xenum.
TEST_F(TestP1combs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_P1combs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::P1combs::_size);
}



// ========================================= get=off ============================================

/// Test xenum with identifier features: getValue=off, fromValue=off
TEST_F(TestP1combs, OffOff)
{
	// getValue()=off
	try { success = false; xenums::P1combs::V0.getP1OO(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P1combs::_fromP1OO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P1combs::_fromP1OO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=ext
TEST_F(TestP1combs, OffExt)
{
	// getValue()=off
	try { success = false; xenums::P1combs::V0.getP1OE(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP1OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1102;
	EXPECT_EQ(true, xenums::P1combs::_fromP1OE(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1OE(intval));
	// Not unique
	//intval = -1101;
	//EXPECT_EQ(true, xenums::P1combs::_fromP1OE(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromP1OE(intval));
	intval = 1103;
	EXPECT_EQ(true, xenums::P1combs::_fromP1OE(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1OE(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromP1OE(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromP1OE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=inl
TEST_F(TestP1combs, OffInl)
{
	// getValue()=off
	try { success = false; xenums::P1combs::V0.getP1OI(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP1OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1104;
	EXPECT_EQ(true, xenums::P1combs::_fromP1OI(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1OI(intval));
	// Not unique
	//intval = -1102;
	//EXPECT_EQ(true, xenums::P1combs::_fromP1OI(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromP1OI(intval));
	intval = 1105;
	EXPECT_EQ(true, xenums::P1combs::_fromP1OI(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1OI(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromP1OI(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromP1OI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromP1OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromP1OC(1106) == xenums::P1combs::V0, bool>::type cxpFromP1OC0(void) { return true; }
/// Function that only compiles if cxpFromP1OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromP1OC(1107) == xenums::P1combs::V0, bool>::type cxpFromP1OC1(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromP1OC2(unsigned v) { return false; }
/// Function that only exists if cxpFromP1OC(V) returns with success, and returns true if so; for testing that cxpFromP1OC() fails correctly at compile time.
template<int V> bool cxpFromP1OC2(typename std::enable_if<xenums::P1combs::_cxpFromP1OC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=off, fromValue=cxp
TEST_F(TestP1combs, OffCxp)
{
	// getValue()=off
	try { success = false; xenums::P1combs::V0.getP1OC(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP1OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromP1OC0<void>());
	EXPECT_EQ(true, cxpFromP1OC1<void>());
	EXPECT_EQ(false, cxpFromP1OC2<1105>(0));
	EXPECT_EQ(true, cxpFromP1OC2<1106>(0));
	EXPECT_EQ(true, cxpFromP1OC2<1107>(0));
	EXPECT_EQ(false, cxpFromP1OC2<1108>(0));
	EXPECT_EQ(false, cxpFromP1OC2<42>(0));

	// fromValue
	intval = 1106;
	EXPECT_EQ(true, xenums::P1combs::_fromP1OC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1OC(intval));
	// Not unique
	//intval = -1103;
	//EXPECT_EQ(true, xenums::P1combs::_fromP1OC(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromP1OC(intval));
	intval = 1107;
	EXPECT_EQ(true, xenums::P1combs::_fromP1OC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1OC(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromP1OC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromP1OC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	intval = 1106;
	EXPECT_EQ(true, xenums::P1combs::_cxpFromP1OC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_cxpFromP1OC(intval));
	// Not unique
	//intval = -1103;
	//EXPECT_EQ(true, xenums::P1combs::_cxpFromP1OC(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_cxpFromP1OC(intval));
	intval = 1107;
	EXPECT_EQ(true, xenums::P1combs::_cxpFromP1OC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_cxpFromP1OC(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_cxpFromP1OC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_cxpFromP1OC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=ext ============================================

/// Test xenum with identifier features: getValue=ext, fromValue=off
TEST_F(TestP1combs, ExtOff)
{
	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getP1EOSize());
	EXPECT_EQ(1110, value.getP1EO(0));
	EXPECT_EQ(-1104, value.getP1EO(1));
	EXPECT_EQ(1111, value.getP1EO(2));
	try { success = false; value.getP1EO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getP1EOSize());
	try { success = false; value.getP1EO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getP1EOSize());
	EXPECT_EQ(-1104, value.getP1EO(0));
	try { success = false; value.getP1EO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P1combs::_fromP1EO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P1combs::_fromP1EO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=ext
TEST_F(TestP1combs, ExtExt)
{
	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getP1EESize());
	EXPECT_EQ(1112, value.getP1EE(0));
	EXPECT_EQ(-1105, value.getP1EE(1));
	EXPECT_EQ(1113, value.getP1EE(2));
	try { success = false; value.getP1EE(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getP1EESize());
	try { success = false; value.getP1EE(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getP1EESize());
	EXPECT_EQ(-1105, value.getP1EE(0));
	try { success = false; value.getP1EE(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1112;
	EXPECT_EQ(true, xenums::P1combs::_fromP1EE(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1EE(intval));
	// Not unique
	//intval = -1105;
	//EXPECT_EQ(true, xenums::P1combs::_fromP1EE(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromP1EE(intval));
	intval = 1113;
	EXPECT_EQ(true, xenums::P1combs::_fromP1EE(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1EE(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromP1EE(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromP1EE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=inl
TEST_F(TestP1combs, ExtInl)
{
	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getP1EISize());
	EXPECT_EQ(1114, value.getP1EI(0));
	EXPECT_EQ(-1106, value.getP1EI(1));
	EXPECT_EQ(1115, value.getP1EI(2));
	try { success = false; value.getP1EI(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getP1EISize());
	try { success = false; value.getP1EI(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getP1EISize());
	EXPECT_EQ(-1106, value.getP1EI(0));
	try { success = false; value.getP1EI(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1114;
	EXPECT_EQ(true, xenums::P1combs::_fromP1EI(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1EI(intval));
	// Not unique
	//intval = -1106;
	//EXPECT_EQ(true, xenums::P1combs::_fromP1EI(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V1);
	//EXPECT_EQ(value, xenums::P1combs::_fromP1EI(intval));
	intval = 1115;
	EXPECT_EQ(true, xenums::P1combs::_fromP1EI(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1EI(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromP1EI(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromP1EI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromP1EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromP1EC(1116) == xenums::P1combs::V0, bool>::type cxpFromP1EC0(void) { return true; }
/// Function that only compiles if cxpFromP1EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromP1EC(1117) == xenums::P1combs::V0, bool>::type cxpFromP1EC1(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromP1EC2(unsigned v) { return false; }
/// Function that only exists if cxpFromP1EC(V) returns with success, and returns true if so; for testing that cxpFromP1EC() fails correctly at compile time.
template<int V> bool cxpFromP1EC2(typename std::enable_if<xenums::P1combs::_cxpFromP1EC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=ext, fromValue=cxp
TEST_F(TestP1combs, ExtCxp)
{
	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getP1ECSize());
	EXPECT_EQ(1116, value.getP1EC(0));
	EXPECT_EQ(-1107, value.getP1EC(1));
	EXPECT_EQ(1117, value.getP1EC(2));
	try { success = false; value.getP1EC(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getP1ECSize());
	try { success = false; value.getP1EC(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getP1ECSize());
	EXPECT_EQ(-1107, value.getP1EC(0));
	try { success = false; value.getP1EC(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromP1EC0<void>());
	EXPECT_EQ(true, cxpFromP1EC1<void>());
	EXPECT_EQ(false, cxpFromP1EC2<1115>(0));
	EXPECT_EQ(true, cxpFromP1EC2<1116>(0));
	EXPECT_EQ(true, cxpFromP1EC2<1117>(0));
	EXPECT_EQ(false, cxpFromP1EC2<1118>(0));
	EXPECT_EQ(false, cxpFromP1EC2<42>(0));

	// fromValue
	intval = 1116;
	EXPECT_EQ(true, xenums::P1combs::_fromP1EC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1EC(intval));
	// Not unique
	//intval = -1107;
	//EXPECT_EQ(true, xenums::P1combs::_fromP1EC(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromP1EC(intval));
	intval = 1117;
	EXPECT_EQ(true, xenums::P1combs::_fromP1EC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1EC(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromP1EC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromP1EC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	intval = 1116;
	EXPECT_EQ(true, xenums::P1combs::_cxpFromP1EC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_cxpFromP1EC(intval));
	// Not unique
	//intval = -1107;
	//EXPECT_EQ(true, xenums::P1combs::_cxpFromP1EC(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_cxpFromP1EC(intval));
	intval = 1117;
	EXPECT_EQ(true, xenums::P1combs::_cxpFromP1EC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_cxpFromP1EC(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_cxpFromP1EC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_cxpFromP1EC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=cxp ============================================

/// Function that only compiles if the constexpr getP1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1COSize() == 3, bool>::type cxpGetP1COSize0(void) { return true; }
/// Function that only compiles if the constexpr getP1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V1.getP1COSize() == 0, bool>::type cxpGetP1COSize1(void) { return true; }
/// Function that only compiles if the constexpr getP1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getP1COSize() == 1, bool>::type cxpGetP1COSize2(void) { return true; }
/// Function that only compiles if the constexpr getP1CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CO(0) == 1120, bool>::type cxpGetP1CO0(void) { return true; }
/// Function that only compiles if the constexpr getP1CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CO(1) == -1108, bool>::type cxpGetP1CO1(void) { return true; }
/// Function that only compiles if the constexpr getP1CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CO(2) == 1121, bool>::type cxpGetP1CO2(void) { return true; }
/// Function that only compiles if the constexpr getP1CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getP1CO(0) == -1108, bool>::type cxpGetP1CO3(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=off
TEST_F(TestP1combs, CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP1COSize0<void>());
	EXPECT_EQ(true, cxpGetP1COSize1<void>());
	EXPECT_EQ(true, cxpGetP1COSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP1CO0<void>());
	EXPECT_EQ(true, cxpGetP1CO1<void>());
	EXPECT_EQ(true, cxpGetP1CO2<void>());
	EXPECT_EQ(true, cxpGetP1CO3<void>());

	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getP1COSize());
	EXPECT_EQ(1120, value.getP1CO(0));
	EXPECT_EQ(-1108, value.getP1CO(1));
	EXPECT_EQ(1121, value.getP1CO(2));
	try { success = false; value.getP1CO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getP1COSize());
	try { success = false; value.getP1CO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getP1COSize());
	EXPECT_EQ(-1108, value.getP1CO(0));
	try { success = false; value.getP1CO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P1combs::_fromP1CO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P1combs::_fromP1CO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP1CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP1CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CESize() == 3, bool>::type cxpGetP1CESize0(void) { return true; }
/// Function that only compiles if the constexpr getP1CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V1.getP1CESize() == 0, bool>::type cxpGetP1CESize1(void) { return true; }
/// Function that only compiles if the constexpr getP1CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getP1CESize() == 1, bool>::type cxpGetP1CESize2(void) { return true; }
/// Function that only compiles if the constexpr getP1CE() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CE(0) == 1122, bool>::type cxpGetP1CE0(void) { return true; }
/// Function that only compiles if the constexpr getP1CE() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CE(1) == -1109, bool>::type cxpGetP1CE1(void) { return true; }
/// Function that only compiles if the constexpr getP1CE() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CE(2) == 1123, bool>::type cxpGetP1CE2(void) { return true; }
/// Function that only compiles if the constexpr getP1CE() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getP1CE(0) == -1109, bool>::type cxpGetP1CE3(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=ext
TEST_F(TestP1combs, CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP1CESize0<void>());
	EXPECT_EQ(true, cxpGetP1CESize1<void>());
	EXPECT_EQ(true, cxpGetP1CESize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP1CE0<void>());
	EXPECT_EQ(true, cxpGetP1CE1<void>());
	EXPECT_EQ(true, cxpGetP1CE2<void>());
	EXPECT_EQ(true, cxpGetP1CE3<void>());

	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getP1CESize());
	EXPECT_EQ(1122, value.getP1CE(0));
	EXPECT_EQ(-1109, value.getP1CE(1));
	EXPECT_EQ(1123, value.getP1CE(2));
	try { success = false; value.getP1CE(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getP1CESize());
	try { success = false; value.getP1CE(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getP1CESize());
	EXPECT_EQ(-1109, value.getP1CE(0));
	try { success = false; value.getP1CE(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1122;
	EXPECT_EQ(true, xenums::P1combs::_fromP1CE(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1CE(intval));
	// Not unique
	//intval = -1109;
	//EXPECT_EQ(true, xenums::P1combs::_fromP1CE(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromP1CE(intval));
	intval = 1123;
	EXPECT_EQ(true, xenums::P1combs::_fromP1CE(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1CE(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromP1CE(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromP1CE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP1CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CISize() == 3, bool>::type cxpGetP1CISize0(void) { return true; }
/// Function that only compiles if the constexpr getP1CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V1.getP1CISize() == 0, bool>::type cxpGetP1CISize1(void) { return true; }
/// Function that only compiles if the constexpr getP1CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getP1CISize() == 1, bool>::type cxpGetP1CISize2(void) { return true; }
/// Function that only compiles if the constexpr getP1CI() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CI(0) == 1124, bool>::type cxpGetP1CI0(void) { return true; }
/// Function that only compiles if the constexpr getP1CI() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CI(1) == -1110, bool>::type cxpGetP1CI1(void) { return true; }
/// Function that only compiles if the constexpr getP1CI() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CI(2) == 1125, bool>::type cxpGetP1CI2(void) { return true; }
/// Function that only compiles if the constexpr getP1CI() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getP1CI(0) == -1110, bool>::type cxpGetP1CI3(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=inl
TEST_F(TestP1combs, CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP1CISize0<void>());
	EXPECT_EQ(true, cxpGetP1CISize1<void>());
	EXPECT_EQ(true, cxpGetP1CISize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP1CI0<void>());
	EXPECT_EQ(true, cxpGetP1CI1<void>());
	EXPECT_EQ(true, cxpGetP1CI2<void>());
	EXPECT_EQ(true, cxpGetP1CI3<void>());

	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getP1CISize());
	EXPECT_EQ(1124, value.getP1CI(0));
	EXPECT_EQ(-1110, value.getP1CI(1));
	EXPECT_EQ(1125, value.getP1CI(2));
	try { success = false; value.getP1CI(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getP1CISize());
	try { success = false; value.getP1CI(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getP1CISize());
	EXPECT_EQ(-1110, value.getP1CI(0));
	try { success = false; value.getP1CI(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1124;
	EXPECT_EQ(true, xenums::P1combs::_fromP1CI(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1CI(intval));
	// Not unique
	//intval = -1110;
	//EXPECT_EQ(true, xenums::P1combs::_fromP1CI(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromP1CI(intval));
	intval = 1125;
	EXPECT_EQ(true, xenums::P1combs::_fromP1CI(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1CI(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromP1CI(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromP1CI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP1CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CCSize() == 3, bool>::type cxpGetP1CCSize0(void) { return true; }
/// Function that only compiles if the constexpr getP1CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V1.getP1CCSize() == 0, bool>::type cxpGetP1CCSize1(void) { return true; }
/// Function that only compiles if the constexpr getP1CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getP1CCSize() == 1, bool>::type cxpGetP1CCSize2(void) { return true; }
/// Function that only compiles if the constexpr getP1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CC(0) == 1126, bool>::type cxpGetP1CC0(void) { return true; }
/// Function that only compiles if the constexpr getP1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CC(1) == -1111, bool>::type cxpGetP1CC1(void) { return true; }
/// Function that only compiles if the constexpr getP1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getP1CC(2) == 1127, bool>::type cxpGetP1CC2(void) { return true; }
/// Function that only compiles if the constexpr getP1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getP1CC(0) == -1111, bool>::type cxpGetP1CC3(void) { return true; }
/// Function that only compiles if cxpFromP1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromP1CC(1126) == xenums::P1combs::V0, bool>::type cxpFromP1CC0(void) { return true; }
/// Function that only compiles if cxpFromP1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromP1CC(1127) == xenums::P1combs::V0, bool>::type cxpFromP1CC1(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromP1CC2(unsigned v) { return false; }
/// Function that only exists if cxpFromP1CC(V) returns with success, and returns true if so; for testing that cxpFromP1CC() fails correctly at compile time.
template<int V> bool cxpFromP1CC2(typename std::enable_if<xenums::P1combs::_cxpFromP1CC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=cxp
TEST_F(TestP1combs, CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP1CCSize0<void>());
	EXPECT_EQ(true, cxpGetP1CCSize1<void>());
	EXPECT_EQ(true, cxpGetP1CCSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP1CC0<void>());
	EXPECT_EQ(true, cxpGetP1CC1<void>());
	EXPECT_EQ(true, cxpGetP1CC2<void>());
	EXPECT_EQ(true, cxpGetP1CC3<void>());

	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getP1CCSize());
	EXPECT_EQ(1126, value.getP1CC(0));
	EXPECT_EQ(-1111, value.getP1CC(1));
	EXPECT_EQ(1127, value.getP1CC(2));
	try { success = false; value.getP1CC(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getP1CCSize());
	try { success = false; value.getP1CC(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getP1CCSize());
	EXPECT_EQ(-1111, value.getP1CC(0));
	try { success = false; value.getP1CC(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromP1CC0<void>());
	EXPECT_EQ(true, cxpFromP1CC1<void>());
	EXPECT_EQ(false, cxpFromP1CC2<1125>(0));
	EXPECT_EQ(true, cxpFromP1CC2<1126>(0));
	EXPECT_EQ(true, cxpFromP1CC2<1127>(0));
	EXPECT_EQ(false, cxpFromP1CC2<1128>(0));
	EXPECT_EQ(false, cxpFromP1CC2<42>(0));

	// fromValue
	intval = 1126;
	EXPECT_EQ(true, xenums::P1combs::_fromP1CC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1CC(intval));
	// Not unique
	//intval = -1111;
	//EXPECT_EQ(true, xenums::P1combs::_fromP1CC(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromP1CC(intval));
	intval = 1127;
	EXPECT_EQ(true, xenums::P1combs::_fromP1CC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromP1CC(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromP1CC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromP1CC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	intval = 1126;
	EXPECT_EQ(true, xenums::P1combs::_cxpFromP1CC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_cxpFromP1CC(intval));
	// Not unique
	//intval = -1111;
	//EXPECT_EQ(true, xenums::P1combs::_cxpFromP1CC(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_cxpFromP1CC(intval));
	intval = 1127;
	EXPECT_EQ(true, xenums::P1combs::_cxpFromP1CC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_cxpFromP1CC(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_cxpFromP1CC(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_cxpFromP1CC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P1CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
