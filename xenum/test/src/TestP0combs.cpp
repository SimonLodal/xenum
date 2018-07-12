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

#include <test/xenum/xenums/Pcombs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenums with combinations of custom property options.
 */
class TestP0combs : public ::testing::Test {
public:
	bool success;
	xenums::Pcomb value;
	int intval;
};


/// Test custom properties P0* of Pcombs xenum.
TEST_F(TestP0combs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_Pcombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::Pcombs::_size);
}


// ========================================= Depth=0 ============================================
// =========================== depth=0 get=off ===============================

/// Test xenum with identifier features: depth=0, getValue=off, fromValue=off
TEST_F(TestP0combs, P0OffOff)
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
TEST_F(TestP0combs, P0OffExt)
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
TEST_F(TestP0combs, P0OffInl)
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


/// Function that only compiles if cxpFromP0OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::_cxpFromP0OC(1003) == xenums::Pcombs::V0, bool>::type cxpFromP0OC0(void) { return true; }
/// Function that only compiles if cxpFromP0OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::_cxpFromP0OC(-1003) == xenums::Pcombs::V1, bool>::type cxpFromP0OC1(void) { return true; }
/// Function that only compiles if cxpFromP0OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::_cxpFromP0OC(1023) == xenums::Pcombs::V2, bool>::type cxpFromP0OC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromP0OC3(unsigned v) { return false; }
/// Function that only exists if cxpFromP0OC(V) returns with success, and returns true if so; for testing that cxpFromP0OC() fails correctly at compile time.
template<int V> bool cxpFromP0OC3(typename std::enable_if<xenums::Pcombs::_cxpFromP0OC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=0, getValue=off, fromValue=cxp
TEST_F(TestP0combs, P0OffCxp)
{
	// getValue=off
	try { success = false; xenums::Pcombs::V0.getP0OC(); }
	catch (std::logic_error e) { EXPECT_STREQ("getP0OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromP0OC0<void>());
	EXPECT_EQ(true, cxpFromP0OC1<void>());
	EXPECT_EQ(true, cxpFromP0OC2<void>());
	EXPECT_EQ(false, cxpFromP0OC3<1002>(0));
	EXPECT_EQ(true, cxpFromP0OC3<1003>(0));
	EXPECT_EQ(true, cxpFromP0OC3<1023>(0));
	EXPECT_EQ(false, cxpFromP0OC3<1024>(0));
	EXPECT_EQ(false, cxpFromP0OC3<42>(0));

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

	// cxpFromValue() at runtime
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
TEST_F(TestP0combs, P0ExtOff)
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
TEST_F(TestP0combs, P0ExtExt)
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
TEST_F(TestP0combs, P0ExtInl)
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


/// Function that only compiles if cxpFromP0EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::_cxpFromP0EC(1007) == xenums::Pcombs::V0, bool>::type cxpFromP0EC0(void) { return true; }
/// Function that only compiles if cxpFromP0EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::_cxpFromP0EC(-1007) == xenums::Pcombs::V1, bool>::type cxpFromP0EC1(void) { return true; }
/// Function that only compiles if cxpFromP0EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::_cxpFromP0EC(1027) == xenums::Pcombs::V2, bool>::type cxpFromP0EC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromP0EC3(unsigned v) { return false; }
/// Function that only exists if cxpFromP0EC(V) returns with success, and returns true if so; for testing that cxpFromP0EC() fails correctly at compile time.
template<int V> bool cxpFromP0EC3(typename std::enable_if<xenums::Pcombs::_cxpFromP0EC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=cxp
TEST_F(TestP0combs, P0ExtCxp)
{
	// getValue()
	EXPECT_EQ(1007, xenums::Pcombs::V0.getP0EC());
	EXPECT_EQ(-1007, xenums::Pcombs::V1.getP0EC());
	EXPECT_EQ(1027, xenums::Pcombs::V2.getP0EC());

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromP0EC0<void>());
	EXPECT_EQ(true, cxpFromP0EC1<void>());
	EXPECT_EQ(true, cxpFromP0EC2<void>());
	EXPECT_EQ(false, cxpFromP0EC3<1006>(0));
	EXPECT_EQ(true, cxpFromP0EC3<1007>(0));
	EXPECT_EQ(true, cxpFromP0EC3<1027>(0));
	EXPECT_EQ(false, cxpFromP0EC3<1028>(0));
	EXPECT_EQ(false, cxpFromP0EC3<42>(0));

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

	// cxpFromValue() at runtime
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
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP0CO() == 1008, bool>::type cxpGetP0CO0(void) { return true; }
/// Function that only compiles if the constexpr getP0CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V1.getP0CO() == -1008, bool>::type cxpGetP0CO1(void) { return true; }
/// Function that only compiles if the constexpr getP0CO() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V2.getP0CO() == 1028, bool>::type cxpGetP0CO2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=off
TEST_F(TestP0combs, P0CxpOff)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP0CO0<void>());
	EXPECT_EQ(true, cxpGetP0CO1<void>());
	EXPECT_EQ(true, cxpGetP0CO2<void>());

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
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP0CE() == 1009, bool>::type cxpGetP0CE0(void) { return true; }
/// Function that only compiles if the constexpr getP0CE() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V1.getP0CE() == -1009, bool>::type cxpGetP0CE1(void) { return true; }
/// Function that only compiles if the constexpr getP0CE() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V2.getP0CE() == 1029, bool>::type cxpGetP0CE2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=ext
TEST_F(TestP0combs, P0CxpExt)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP0CE0<void>());
	EXPECT_EQ(true, cxpGetP0CE1<void>());
	EXPECT_EQ(true, cxpGetP0CE2<void>());

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
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP0CI() == 1010, bool>::type cxpGetP0CI0(void) { return true; }
/// Function that only compiles if the constexpr getP0CI() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V1.getP0CI() == -1010, bool>::type cxpGetP0CI1(void) { return true; }
/// Function that only compiles if the constexpr getP0CI() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V2.getP0CI() == 1030, bool>::type cxpGetP0CI2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=inl
TEST_F(TestP0combs, P0CxpInl)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP0CI0<void>());
	EXPECT_EQ(true, cxpGetP0CI1<void>());
	EXPECT_EQ(true, cxpGetP0CI2<void>());

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
template <class T> typename std::enable_if<xenums::Pcombs::V0.getP0CC() == 1011, bool>::type cxpGetP0CC0(void) { return true; }
/// Function that only compiles if the constexpr getP0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V1.getP0CC() == -1011, bool>::type cxpGetP0CC1(void) { return true; }
/// Function that only compiles if the constexpr getP0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::V2.getP0CC() == 1031, bool>::type cxpGetP0CC2(void) { return true; }
/// Function that only compiles if cxpFromP0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::_cxpFromP0CC(1011) == xenums::Pcombs::V0, bool>::type cxpFromP0CC0(void) { return true; }
/// Function that only compiles if cxpFromP0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::_cxpFromP0CC(-1011) == xenums::Pcombs::V1, bool>::type cxpFromP0CC1(void) { return true; }
/// Function that only compiles if cxpFromP0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Pcombs::_cxpFromP0CC(1031) == xenums::Pcombs::V2, bool>::type cxpFromP0CC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromP0CC3(unsigned v) { return false; }
/// Function that only exists if cxpFromP0CC(V) returns with success, and returns true if so; for testing that cxpFromP0CC() fails correctly at compile time.
template<int V> bool cxpFromP0CC3(typename std::enable_if<xenums::Pcombs::_cxpFromP0CC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=cxp
TEST_F(TestP0combs, P0CxpCxp)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP0CC0<void>());
	EXPECT_EQ(true, cxpGetP0CC1<void>());
	EXPECT_EQ(true, cxpGetP0CC2<void>());

	// getValue()
	EXPECT_EQ(1011, xenums::Pcombs::V0.getP0CC());
	EXPECT_EQ(-1011, xenums::Pcombs::V1.getP0CC());
	EXPECT_EQ(1031, xenums::Pcombs::V2.getP0CC());

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromP0CC0<void>());
	EXPECT_EQ(true, cxpFromP0CC1<void>());
	EXPECT_EQ(true, cxpFromP0CC2<void>());
	EXPECT_EQ(false, cxpFromP0CC3<1010>(0));
	EXPECT_EQ(true, cxpFromP0CC3<1011>(0));
	EXPECT_EQ(true, cxpFromP0CC3<1031>(0));
	EXPECT_EQ(false, cxpFromP0CC3<1032>(0));
	EXPECT_EQ(false, cxpFromP0CC3<42>(0));

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

	// cxpFromValue() at runtime
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



} // namespace xenum
} // namespace test
