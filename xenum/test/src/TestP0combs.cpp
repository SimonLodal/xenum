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

#include <test/xenum/xenums/P0combs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenums with combinations of custom property options.
 */
class TestP0combs : public ::testing::Test {
public:
	bool success;
	xenums::P0comb value;
	int intval;
};


/// Test custom properties P0* of P0combs xenum.
TEST_F(TestP0combs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_P0combs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::P0combs::_size);
}



// ========================================= get=off ============================================

/// Test xenum with identifier features: getValue=off, fromValue=off
TEST_F(TestP0combs, OffOff)
{
	// getValue=off
	try { success = false; xenums::P0combs::V0.getOffOff(); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P0combs::_fromOffOff(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P0combs::_fromOffOff(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=ext
TEST_F(TestP0combs, OffExt)
{
	// getValue=off
	try { success = false; xenums::P0combs::V0.getOffExt(); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffExt() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1001;
	EXPECT_EQ(true, xenums::P0combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V0);
	EXPECT_EQ(value, xenums::P0combs::_fromOffExt(intval));
	intval = -1001;
	EXPECT_EQ(true, xenums::P0combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V1);
	EXPECT_EQ(value, xenums::P0combs::_fromOffExt(intval));
	intval = 1021;
	EXPECT_EQ(true, xenums::P0combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	EXPECT_EQ(value, xenums::P0combs::_fromOffExt(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::P0combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	try { success = false; xenums::P0combs::_fromOffExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=inl
TEST_F(TestP0combs, OffInl)
{
	// getValue=off
	try { success = false; xenums::P0combs::V0.getOffInl(); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffInl() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1002;
	EXPECT_EQ(true, xenums::P0combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V0);
	EXPECT_EQ(value, xenums::P0combs::_fromOffInl(intval));
	intval = -1002;
	EXPECT_EQ(true, xenums::P0combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V1);
	EXPECT_EQ(value, xenums::P0combs::_fromOffInl(intval));
	intval = 1022;
	EXPECT_EQ(true, xenums::P0combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	EXPECT_EQ(value, xenums::P0combs::_fromOffInl(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::P0combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	try { success = false; xenums::P0combs::_fromOffInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::_cxpFromOffCxp(1003) == xenums::P0combs::V0, bool>::type cxpFromOffCxp0(void) { return true; }
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::_cxpFromOffCxp(-1003) == xenums::P0combs::V1, bool>::type cxpFromOffCxp1(void) { return true; }
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::_cxpFromOffCxp(1023) == xenums::P0combs::V2, bool>::type cxpFromOffCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromOffCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromOffCxp(V) returns with success, and returns true if so; for testing that cxpFromOffCxp() fails correctly at compile time.
template<int V> bool cxpFromOffCxp3(typename std::enable_if<xenums::P0combs::_cxpFromOffCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=off, fromValue=cxp
TEST_F(TestP0combs, OffCxp)
{
	// getValue=off
	try { success = false; xenums::P0combs::V0.getOffCxp(); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffCxp() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromOffCxp0<void>());
	EXPECT_EQ(true, cxpFromOffCxp1<void>());
	EXPECT_EQ(true, cxpFromOffCxp2<void>());
	EXPECT_EQ(false, cxpFromOffCxp3<1002>(0));
	EXPECT_EQ(true, cxpFromOffCxp3<1003>(0));
	EXPECT_EQ(true, cxpFromOffCxp3<1023>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<1024>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<42>(0));

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::P0combs::V0, xenums::P0combs::_cxpFromOffCxp(1003));
	EXPECT_EQ(xenums::P0combs::V1, xenums::P0combs::_cxpFromOffCxp(-1003));
	EXPECT_EQ(xenums::P0combs::V2, xenums::P0combs::_cxpFromOffCxp(1023));
	try { success = false; xenums::P0combs::_cxpFromOffCxp(42); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1003;
	EXPECT_EQ(true, xenums::P0combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V0);
	EXPECT_EQ(value, xenums::P0combs::_fromOffCxp(intval));
	intval = -1003;
	EXPECT_EQ(true, xenums::P0combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V1);
	EXPECT_EQ(value, xenums::P0combs::_fromOffCxp(intval));
	intval = 1023;
	EXPECT_EQ(true, xenums::P0combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	EXPECT_EQ(value, xenums::P0combs::_fromOffCxp(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::P0combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	try { success = false; xenums::P0combs::_fromOffCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=ext ============================================

/// Test xenum with identifier features: getValue=ext, fromValue=off
TEST_F(TestP0combs, ExtOff)
{
	// getValue()
	EXPECT_EQ(1004, xenums::P0combs::V0.getExtOff());
	EXPECT_EQ(-1004, xenums::P0combs::V1.getExtOff());
	EXPECT_EQ(1024, xenums::P0combs::V2.getExtOff());

	// fromValue=off
	try { success = false; xenums::P0combs::_fromExtOff(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P0combs::_fromExtOff(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=ext
TEST_F(TestP0combs, ExtExt)
{
	// getValue()
	EXPECT_EQ(1005, xenums::P0combs::V0.getExtExt());
	EXPECT_EQ(-1005, xenums::P0combs::V1.getExtExt());
	EXPECT_EQ(1025, xenums::P0combs::V2.getExtExt());

	// fromValue()
	intval = 1005;
	EXPECT_EQ(true, xenums::P0combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V0);
	EXPECT_EQ(value, xenums::P0combs::_fromExtExt(intval));
	intval = -1005;
	EXPECT_EQ(true, xenums::P0combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V1);
	EXPECT_EQ(value, xenums::P0combs::_fromExtExt(intval));
	intval = 1025;
	EXPECT_EQ(true, xenums::P0combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	EXPECT_EQ(value, xenums::P0combs::_fromExtExt(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::P0combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	try { success = false; xenums::P0combs::_fromExtExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=inl
TEST_F(TestP0combs, ExtInl)
{
	// getValue()
	EXPECT_EQ(1006, xenums::P0combs::V0.getExtInl());
	EXPECT_EQ(-1006, xenums::P0combs::V1.getExtInl());
	EXPECT_EQ(1026, xenums::P0combs::V2.getExtInl());

	// fromValue()
	intval = 1006;
	EXPECT_EQ(true, xenums::P0combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V0);
	EXPECT_EQ(value, xenums::P0combs::_fromExtInl(intval));
	intval = -1006;
	EXPECT_EQ(true, xenums::P0combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V1);
	EXPECT_EQ(value, xenums::P0combs::_fromExtInl(intval));
	intval = 1026;
	EXPECT_EQ(true, xenums::P0combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	EXPECT_EQ(value, xenums::P0combs::_fromExtInl(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::P0combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	try { success = false; xenums::P0combs::_fromExtInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::_cxpFromExtCxp(1007) == xenums::P0combs::V0, bool>::type cxpFromExtCxp0(void) { return true; }
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::_cxpFromExtCxp(-1007) == xenums::P0combs::V1, bool>::type cxpFromExtCxp1(void) { return true; }
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::_cxpFromExtCxp(1027) == xenums::P0combs::V2, bool>::type cxpFromExtCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromExtCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromExtCxp(V) returns with success, and returns true if so; for testing that cxpFromExtCxp() fails correctly at compile time.
template<int V> bool cxpFromExtCxp3(typename std::enable_if<xenums::P0combs::_cxpFromExtCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=ext, fromValue=cxp
TEST_F(TestP0combs, ExtCxp)
{
	// getValue()
	EXPECT_EQ(1007, xenums::P0combs::V0.getExtCxp());
	EXPECT_EQ(-1007, xenums::P0combs::V1.getExtCxp());
	EXPECT_EQ(1027, xenums::P0combs::V2.getExtCxp());

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromExtCxp0<void>());
	EXPECT_EQ(true, cxpFromExtCxp1<void>());
	EXPECT_EQ(true, cxpFromExtCxp2<void>());
	EXPECT_EQ(false, cxpFromExtCxp3<1006>(0));
	EXPECT_EQ(true, cxpFromExtCxp3<1007>(0));
	EXPECT_EQ(true, cxpFromExtCxp3<1027>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<1028>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<42>(0));

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::P0combs::V0, xenums::P0combs::_cxpFromExtCxp(1007));
	EXPECT_EQ(xenums::P0combs::V1, xenums::P0combs::_cxpFromExtCxp(-1007));
	EXPECT_EQ(xenums::P0combs::V2, xenums::P0combs::_cxpFromExtCxp(1027));
	try { success = false; xenums::P0combs::_cxpFromExtCxp(42); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1007;
	EXPECT_EQ(true, xenums::P0combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V0);
	EXPECT_EQ(value, xenums::P0combs::_fromExtCxp(intval));
	intval = -1007;
	EXPECT_EQ(true, xenums::P0combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V1);
	EXPECT_EQ(value, xenums::P0combs::_fromExtCxp(intval));
	intval = 1027;
	EXPECT_EQ(true, xenums::P0combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	EXPECT_EQ(value, xenums::P0combs::_fromExtCxp(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::P0combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	try { success = false; xenums::P0combs::_fromExtCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=cxp ============================================

/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V0.getCxpOff() == 1008, bool>::type cxpGetCxpOff0(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V1.getCxpOff() == -1008, bool>::type cxpGetCxpOff1(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V2.getCxpOff() == 1028, bool>::type cxpGetCxpOff2(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=off
TEST_F(TestP0combs, CxpOff)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpOff0<void>());
	EXPECT_EQ(true, cxpGetCxpOff1<void>());
	EXPECT_EQ(true, cxpGetCxpOff2<void>());

	// getValue()
	EXPECT_EQ(1008, xenums::P0combs::V0.getCxpOff());
	EXPECT_EQ(-1008, xenums::P0combs::V1.getCxpOff());
	EXPECT_EQ(1028, xenums::P0combs::V2.getCxpOff());

	// fromValue=off
	try { success = false; xenums::P0combs::_fromCxpOff(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P0combs::_fromCxpOff(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V0.getCxpExt() == 1009, bool>::type cxpGetCxpExt0(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V1.getCxpExt() == -1009, bool>::type cxpGetCxpExt1(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V2.getCxpExt() == 1029, bool>::type cxpGetCxpExt2(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=ext
TEST_F(TestP0combs, CxpExt)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpExt0<void>());
	EXPECT_EQ(true, cxpGetCxpExt1<void>());
	EXPECT_EQ(true, cxpGetCxpExt2<void>());

	// getValue() at runtime
	EXPECT_EQ(1009, xenums::P0combs::V0.getCxpExt());
	EXPECT_EQ(-1009, xenums::P0combs::V1.getCxpExt());
	EXPECT_EQ(1029, xenums::P0combs::V2.getCxpExt());

	// fromValue()
	intval = 1009;
	EXPECT_EQ(true, xenums::P0combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V0);
	EXPECT_EQ(value, xenums::P0combs::_fromCxpExt(intval));
	intval = -1009;
	EXPECT_EQ(true, xenums::P0combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V1);
	EXPECT_EQ(value, xenums::P0combs::_fromCxpExt(intval));
	intval = 1029;
	EXPECT_EQ(true, xenums::P0combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	EXPECT_EQ(value, xenums::P0combs::_fromCxpExt(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::P0combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	try { success = false; xenums::P0combs::_fromCxpExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V0.getCxpInl() == 1010, bool>::type cxpGetCxpInl0(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V1.getCxpInl() == -1010, bool>::type cxpGetCxpInl1(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V2.getCxpInl() == 1030, bool>::type cxpGetCxpInl2(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=inl
TEST_F(TestP0combs, CxpInl)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpInl0<void>());
	EXPECT_EQ(true, cxpGetCxpInl1<void>());
	EXPECT_EQ(true, cxpGetCxpInl2<void>());

	// getValue() at runtime
	EXPECT_EQ(1010, xenums::P0combs::V0.getCxpInl());
	EXPECT_EQ(-1010, xenums::P0combs::V1.getCxpInl());
	EXPECT_EQ(1030, xenums::P0combs::V2.getCxpInl());

	// fromValue()
	intval = 1010;
	EXPECT_EQ(true, xenums::P0combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V0);
	EXPECT_EQ(value, xenums::P0combs::_fromCxpInl(intval));
	intval = -1010;
	EXPECT_EQ(true, xenums::P0combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V1);
	EXPECT_EQ(value, xenums::P0combs::_fromCxpInl(intval));
	intval = 1030;
	EXPECT_EQ(true, xenums::P0combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	EXPECT_EQ(value, xenums::P0combs::_fromCxpInl(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::P0combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	try { success = false; xenums::P0combs::_fromCxpInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V0.getCxpCxp() == 1011, bool>::type cxpGetCxpCxp0(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V1.getCxpCxp() == -1011, bool>::type cxpGetCxpCxp1(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::V2.getCxpCxp() == 1031, bool>::type cxpGetCxpCxp2(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::_cxpFromCxpCxp(1011) == xenums::P0combs::V0, bool>::type cxpFromCxpCxp0(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::_cxpFromCxpCxp(-1011) == xenums::P0combs::V1, bool>::type cxpFromCxpCxp1(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P0combs::_cxpFromCxpCxp(1031) == xenums::P0combs::V2, bool>::type cxpFromCxpCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromCxpCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromCxpCxp(V) returns with success, and returns true if so; for testing that cxpFromCxpCxp() fails correctly at compile time.
template<int V> bool cxpFromCxpCxp3(typename std::enable_if<xenums::P0combs::_cxpFromCxpCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=cxp
TEST_F(TestP0combs, CxpCxp)
{
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpCxp0<void>());
	EXPECT_EQ(true, cxpGetCxpCxp1<void>());
	EXPECT_EQ(true, cxpGetCxpCxp2<void>());

	// getValue() at runtime
	EXPECT_EQ(1011, xenums::P0combs::V0.getCxpCxp());
	EXPECT_EQ(-1011, xenums::P0combs::V1.getCxpCxp());
	EXPECT_EQ(1031, xenums::P0combs::V2.getCxpCxp());

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromCxpCxp0<void>());
	EXPECT_EQ(true, cxpFromCxpCxp1<void>());
	EXPECT_EQ(true, cxpFromCxpCxp2<void>());
	EXPECT_EQ(false, cxpFromCxpCxp3<1010>(0));
	EXPECT_EQ(true, cxpFromCxpCxp3<1011>(0));
	EXPECT_EQ(true, cxpFromCxpCxp3<1031>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<1032>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<42>(0));

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::P0combs::V0, xenums::P0combs::_cxpFromCxpCxp(1011));
	EXPECT_EQ(xenums::P0combs::V1, xenums::P0combs::_cxpFromCxpCxp(-1011));
	EXPECT_EQ(xenums::P0combs::V2, xenums::P0combs::_cxpFromCxpCxp(1031));
	try { success = false; xenums::P0combs::_cxpFromCxpCxp(42); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1011;
	EXPECT_EQ(true, xenums::P0combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V0);
	EXPECT_EQ(value, xenums::P0combs::_fromCxpCxp(intval));
	intval = -1011;
	EXPECT_EQ(true, xenums::P0combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V1);
	EXPECT_EQ(value, xenums::P0combs::_fromCxpCxp(intval));
	intval = 1031;
	EXPECT_EQ(true, xenums::P0combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	EXPECT_EQ(value, xenums::P0combs::_fromCxpCxp(intval));
	intval = 42;
	EXPECT_EQ(false, xenums::P0combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P0combs::V2);
	try { success = false; xenums::P0combs::_fromCxpCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
