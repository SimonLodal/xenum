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

#include <test/xenum/xenums/S0combs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenums with combinations of custom property options.
 */
class TestS0combs : public ::testing::Test {
public:
	bool success;
	xenums::S0comb value;
	const char* strval;
};


/// Test basics of S0combs xenum.
TEST_F(TestS0combs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_S0combs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::S0combs::_size);
}



// ========================================= Depth=0 ============================================
// =========================== depth=0 get=off ===============================

/// Test xenum with identifier features: depth=0, getValue=off, fromValue=off
TEST_F(TestS0combs, S0OffOff)
{
	// getValue=off
	try { success = false; xenums::S0combs::V0.getS0OO(); }
	catch (std::logic_error e) { EXPECT_STREQ("getS0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S0combs::_fromS0OO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S0combs::_fromS0OO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=off, fromValue=ext
TEST_F(TestS0combs, S0OffExt)
{
	// getValue=off
	try { success = false; xenums::S0combs::V0.getS0OE(); }
	catch (std::logic_error e) { EXPECT_STREQ("getS0OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1001";
	EXPECT_EQ(true, xenums::S0combs::_fromS0OE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromS0OE(strval));
	strval = "-1001";
	EXPECT_EQ(true, xenums::S0combs::_fromS0OE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromS0OE(strval));
	strval = "1021";
	EXPECT_EQ(true, xenums::S0combs::_fromS0OE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromS0OE(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromS0OE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromS0OE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=off, fromValue=inl
TEST_F(TestS0combs, S0OffInl)
{
	// getValue=off
	try { success = false; xenums::S0combs::V0.getS0OI(); }
	catch (std::logic_error e) { EXPECT_STREQ("getS0OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1002";
	EXPECT_EQ(true, xenums::S0combs::_fromS0OI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromS0OI(strval));
	strval = "-1002";
	EXPECT_EQ(true, xenums::S0combs::_fromS0OI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromS0OI(strval));
	strval = "1022";
	EXPECT_EQ(true, xenums::S0combs::_fromS0OI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromS0OI(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromS0OI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromS0OI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromS0OC()
/// @{
constexpr char S0OCv0[] = "1003";
constexpr char S0OCv1[] = "-1003";
constexpr char S0OCv2[] = "1023";
constexpr char S0OCv3[] = "1002";
constexpr char S0OCv4[] = "1024";
constexpr char S0OCv5[] = "42";
/// @}
/// Function that only compiles if cxpFromS0OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromS0OC(S0OCv0) == xenums::S0combs::V0, bool>::type cxpFromS0OC0(void) { return true; }
/// Function that only compiles if cxpFromS0OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromS0OC(S0OCv1) == xenums::S0combs::V1, bool>::type cxpFromS0OC1(void) { return true; }
/// Function that only compiles if cxpFromS0OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromS0OC(S0OCv2) == xenums::S0combs::V2, bool>::type cxpFromS0OC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromS0OC3(unsigned v) { return false; }
/// Function that only exists if cxpFromS0OC(V) returns with success, and returns true if so; for testing that cxpFromS0OC() fails correctly at compile time.
template<const char* V> bool cxpFromS0OC3(typename std::enable_if<xenums::S0combs::_cxpFromS0OC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=0, getValue=off, fromValue=cxp
TEST_F(TestS0combs, S0OffCxp)
{
	// getValue=off
	try { success = false; xenums::S0combs::V0.getS0OC(); }
	catch (std::logic_error e) { EXPECT_STREQ("getS0OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS0OC0<void>());
	EXPECT_EQ(true, cxpFromS0OC1<void>());
	EXPECT_EQ(true, cxpFromS0OC2<void>());
	EXPECT_EQ(true, cxpFromS0OC3<S0OCv0>(0));
	EXPECT_EQ(true, cxpFromS0OC3<S0OCv1>(0));
	EXPECT_EQ(true, cxpFromS0OC3<S0OCv2>(0));
	EXPECT_EQ(false, cxpFromS0OC3<S0OCv3>(0));
	EXPECT_EQ(false, cxpFromS0OC3<S0OCv4>(0));
	EXPECT_EQ(false, cxpFromS0OC3<S0OCv5>(0));

	// fromValue
	strval = "1003";
	EXPECT_EQ(true, xenums::S0combs::_fromS0OC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromS0OC(strval));
	strval = "-1003";
	EXPECT_EQ(true, xenums::S0combs::_fromS0OC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromS0OC(strval));
	strval = "1023";
	EXPECT_EQ(true, xenums::S0combs::_fromS0OC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromS0OC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromS0OC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromS0OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1003";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromS0OC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromS0OC(strval));
	strval = "-1003";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromS0OC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromS0OC(strval));
	strval = "1023";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromS0OC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromS0OC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_cxpFromS0OC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_cxpFromS0OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=0 get=ext ===============================

/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=off
TEST_F(TestS0combs, S0ExtOff)
{
	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1004", value.getS0EO());
	EXPECT_EQ(5, value.getS0EOSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1004", value.getS0EO());
	EXPECT_EQ(6, value.getS0EOSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1024", value.getS0EO());
	EXPECT_EQ(5, value.getS0EOSize());

	// fromValue=off
	try { success = false; xenums::S0combs::_fromS0EO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S0combs::_fromS0EO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=ext
TEST_F(TestS0combs, S0ExtExt)
{
	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1005", value.getS0EE());
	EXPECT_EQ(5, value.getS0EESize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1005", value.getS0EE());
	EXPECT_EQ(6, value.getS0EESize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1025", value.getS0EE());
	EXPECT_EQ(5, value.getS0EESize());

	// fromValue
	strval = "1005";
	EXPECT_EQ(true, xenums::S0combs::_fromS0EE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromS0EE(strval));
	strval = "-1005";
	EXPECT_EQ(true, xenums::S0combs::_fromS0EE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromS0EE(strval));
	strval = "1025";
	EXPECT_EQ(true, xenums::S0combs::_fromS0EE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromS0EE(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromS0EE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromS0EE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=inl
TEST_F(TestS0combs, S0ExtInl)
{
	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1006", value.getS0EI());
	EXPECT_EQ(5, value.getS0EISize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1006", value.getS0EI());
	EXPECT_EQ(6, value.getS0EISize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1026", value.getS0EI());
	EXPECT_EQ(5, value.getS0EISize());

	// fromValue
	strval = "1006";
	EXPECT_EQ(true, xenums::S0combs::_fromS0EI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromS0EI(strval));
	strval = "-1006";
	EXPECT_EQ(true, xenums::S0combs::_fromS0EI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromS0EI(strval));
	strval = "1026";
	EXPECT_EQ(true, xenums::S0combs::_fromS0EI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromS0EI(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromS0EI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromS0EI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromS0EC()
/// @{
constexpr char S0ECv0[] = "1007";
constexpr char S0ECv1[] = "-1007";
constexpr char S0ECv2[] = "1027";
constexpr char S0ECv3[] = "1006";
constexpr char S0ECv4[] = "1028";
constexpr char S0ECv5[] = "42";
/// @}
/// Function that only compiles if cxpFromS0EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromS0EC(S0ECv0) == xenums::S0combs::V0, bool>::type cxpFromS0EC0(void) { return true; }
/// Function that only compiles if cxpFromS0EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromS0EC(S0ECv1) == xenums::S0combs::V1, bool>::type cxpFromS0EC1(void) { return true; }
/// Function that only compiles if cxpFromS0EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromS0EC(S0ECv2) == xenums::S0combs::V2, bool>::type cxpFromS0EC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromS0EC3(unsigned v) { return false; }
/// Function that only exists if cxpFromS0EC(V) returns with success, and returns true if so; for testing that cxpFromS0EC() fails correctly at compile time.
template<const char* V> bool cxpFromS0EC3(typename std::enable_if<xenums::S0combs::_cxpFromS0EC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=cxp
TEST_F(TestS0combs, S0ExtCxp)
{
	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1007", value.getS0EC());
	EXPECT_EQ(5, value.getS0ECSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1007", value.getS0EC());
	EXPECT_EQ(6, value.getS0ECSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1027", value.getS0EC());
	EXPECT_EQ(5, value.getS0ECSize());

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS0EC0<void>());
	EXPECT_EQ(true, cxpFromS0EC1<void>());
	EXPECT_EQ(true, cxpFromS0EC2<void>());
	EXPECT_EQ(true, cxpFromS0EC3<S0ECv0>(0));
	EXPECT_EQ(true, cxpFromS0EC3<S0ECv1>(0));
	EXPECT_EQ(true, cxpFromS0EC3<S0ECv2>(0));
	EXPECT_EQ(false, cxpFromS0EC3<S0ECv3>(0));
	EXPECT_EQ(false, cxpFromS0EC3<S0ECv4>(0));
	EXPECT_EQ(false, cxpFromS0EC3<S0ECv5>(0));

	// fromValue
	strval = "1007";
	EXPECT_EQ(true, xenums::S0combs::_fromS0EC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromS0EC(strval));
	strval = "-1007";
	EXPECT_EQ(true, xenums::S0combs::_fromS0EC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromS0EC(strval));
	strval = "1027";
	EXPECT_EQ(true, xenums::S0combs::_fromS0EC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromS0EC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromS0EC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromS0EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1007";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromS0EC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromS0EC(strval));
	strval = "-1007";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromS0EC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromS0EC(strval));
	strval = "1027";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromS0EC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromS0EC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_cxpFromS0EC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_cxpFromS0EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=0 get=cxp ===============================

/// Function that only compiles if the constexpr getS0COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V0.getS0COSize() == 5, bool>::type cxpGetS0COSize0() { return true; }
/// Function that only compiles if the constexpr getS0COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V1.getS0COSize() == 6, bool>::type cxpGetS0COSize1() { return true; }
/// Function that only compiles if the constexpr getS0COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V2.getS0COSize() == 5, bool>::type cxpGetS0COSize2() { return true; }
/// Function that only compiles if the constexpr getS0CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V0.getS0CO(), "1008"), bool>::type cxpGetS0CO0(void) { return true; }
/// Function that only compiles if the constexpr getS0CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V1.getS0CO(), "-1008"), bool>::type cxpGetS0CO1(void) { return true; }
/// Function that only compiles if the constexpr getS0CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V2.getS0CO(), "1028"), bool>::type cxpGetS0CO2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=off
TEST_F(TestS0combs, S0CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS0COSize0<void>());
	EXPECT_EQ(true, cxpGetS0COSize1<void>());
	EXPECT_EQ(true, cxpGetS0COSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS0CO0<void>());
	EXPECT_EQ(true, cxpGetS0CO1<void>());
	EXPECT_EQ(true, cxpGetS0CO2<void>());

	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1008", value.getS0CO());
	EXPECT_EQ(5, value.getS0COSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1008", value.getS0CO());
	EXPECT_EQ(6, value.getS0COSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1028", value.getS0CO());
	EXPECT_EQ(5, value.getS0COSize());

	// fromValue=off
	try { success = false; xenums::S0combs::_fromS0CO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S0combs::_fromS0CO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS0CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V0.getS0CESize() == 5, bool>::type cxpGetS0CESize0() { return true; }
/// Function that only compiles if the constexpr getS0CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V1.getS0CESize() == 6, bool>::type cxpGetS0CESize1() { return true; }
/// Function that only compiles if the constexpr getS0CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V2.getS0CESize() == 5, bool>::type cxpGetS0CESize2() { return true; }
/// Function that only compiles if the constexpr getS0CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V0.getS0CE(), "1009"), bool>::type cxpGetS0CE0(void) { return true; }
/// Function that only compiles if the constexpr getS0CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V1.getS0CE(), "-1009"), bool>::type cxpGetS0CE1(void) { return true; }
/// Function that only compiles if the constexpr getS0CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V2.getS0CE(), "1029"), bool>::type cxpGetS0CE2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=ext
TEST_F(TestS0combs, S0CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS0CESize0<void>());
	EXPECT_EQ(true, cxpGetS0CESize1<void>());
	EXPECT_EQ(true, cxpGetS0CESize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS0CE0<void>());
	EXPECT_EQ(true, cxpGetS0CE1<void>());
	EXPECT_EQ(true, cxpGetS0CE2<void>());

	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1009", value.getS0CE());
	EXPECT_EQ(5, value.getS0CESize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1009", value.getS0CE());
	EXPECT_EQ(6, value.getS0CESize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1029", value.getS0CE());
	EXPECT_EQ(5, value.getS0CESize());

	// fromValue
	strval = "1009";
	EXPECT_EQ(true, xenums::S0combs::_fromS0CE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromS0CE(strval));
	strval = "-1009";
	EXPECT_EQ(true, xenums::S0combs::_fromS0CE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromS0CE(strval));
	strval = "1029";
	EXPECT_EQ(true, xenums::S0combs::_fromS0CE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromS0CE(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromS0CE(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromS0CE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS0CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V0.getS0CISize() == 5, bool>::type cxpGetS0CISize0() { return true; }
/// Function that only compiles if the constexpr getS0CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V1.getS0CISize() == 6, bool>::type cxpGetS0CISize1() { return true; }
/// Function that only compiles if the constexpr getS0CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V2.getS0CISize() == 5, bool>::type cxpGetS0CISize2() { return true; }
/// Function that only compiles if the constexpr getS0CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V0.getS0CI(), "1010"), bool>::type cxpGetS0CI0(void) { return true; }
/// Function that only compiles if the constexpr getS0CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V1.getS0CI(), "-1010"), bool>::type cxpGetS0CI1(void) { return true; }
/// Function that only compiles if the constexpr getS0CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V2.getS0CI(), "1030"), bool>::type cxpGetS0CI2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=inl
TEST_F(TestS0combs, S0CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS0CISize0<void>());
	EXPECT_EQ(true, cxpGetS0CISize1<void>());
	EXPECT_EQ(true, cxpGetS0CISize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS0CI0<void>());
	EXPECT_EQ(true, cxpGetS0CI1<void>());
	EXPECT_EQ(true, cxpGetS0CI2<void>());

	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1010", value.getS0CI());
	EXPECT_EQ(5, value.getS0CISize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1010", value.getS0CI());
	EXPECT_EQ(6, value.getS0CISize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1030", value.getS0CI());
	EXPECT_EQ(5, value.getS0CISize());

	// fromValue
	strval = "1010";
	EXPECT_EQ(true, xenums::S0combs::_fromS0CI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromS0CI(strval));
	strval = "-1010";
	EXPECT_EQ(true, xenums::S0combs::_fromS0CI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromS0CI(strval));
	strval = "1030";
	EXPECT_EQ(true, xenums::S0combs::_fromS0CI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromS0CI(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromS0CI(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromS0CI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS0CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V0.getS0CCSize() == 5, bool>::type cxpGetS0CCSize0() { return true; }
/// Function that only compiles if the constexpr getS0CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V1.getS0CCSize() == 6, bool>::type cxpGetS0CCSize1() { return true; }
/// Function that only compiles if the constexpr getS0CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V2.getS0CCSize() == 5, bool>::type cxpGetS0CCSize2() { return true; }
/// Function that only compiles if the constexpr getS0CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V0.getS0CC(), "1011"), bool>::type cxpGetS0CC0(void) { return true; }
/// Function that only compiles if the constexpr getS0CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V1.getS0CC(), "-1011"), bool>::type cxpGetS0CC1(void) { return true; }
/// Function that only compiles if the constexpr getS0CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V2.getS0CC(), "1031"), bool>::type cxpGetS0CC2(void) { return true; }
/// Values for testing cxpFromS0CC()
/// @{
constexpr char S0CCv0[] = "1011";
constexpr char S0CCv1[] = "-1011";
constexpr char S0CCv2[] = "1031";
constexpr char S0CCv3[] = "1010";
constexpr char S0CCv4[] = "1032";
constexpr char S0CCv5[] = "42";
/// @}
/// Function that only compiles if cxpFromS0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromS0CC("1011") == xenums::S0combs::V0, bool>::type cxpFromS0CC0(void) { return true; }
/// Function that only compiles if cxpFromS0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromS0CC("-1011") == xenums::S0combs::V1, bool>::type cxpFromS0CC1(void) { return true; }
/// Function that only compiles if cxpFromS0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromS0CC("1031") == xenums::S0combs::V2, bool>::type cxpFromS0CC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromS0CC3(unsigned v) { return false; }
/// Function that only exists if cxpFromS0CC(V) returns with success, and returns true if so; for testing that cxpFromS0CC() fails correctly at compile time.
template<const char* V> bool cxpFromS0CC3(typename std::enable_if<xenums::S0combs::_cxpFromS0CC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=cxp
TEST_F(TestS0combs, S0CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS0CCSize0<void>());
	EXPECT_EQ(true, cxpGetS0CCSize1<void>());
	EXPECT_EQ(true, cxpGetS0CCSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS0CC0<void>());
	EXPECT_EQ(true, cxpGetS0CC1<void>());
	EXPECT_EQ(true, cxpGetS0CC2<void>());

	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1011", value.getS0CC());
	EXPECT_EQ(5, value.getS0CCSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1011", value.getS0CC());
	EXPECT_EQ(6, value.getS0CCSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1031", value.getS0CC());
	EXPECT_EQ(5, value.getS0CCSize());

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS0CC0<void>());
	EXPECT_EQ(true, cxpFromS0CC1<void>());
	EXPECT_EQ(true, cxpFromS0CC2<void>());
	EXPECT_EQ(true, cxpFromS0CC3<S0CCv0>(0));
	EXPECT_EQ(true, cxpFromS0CC3<S0CCv1>(0));
	EXPECT_EQ(true, cxpFromS0CC3<S0CCv2>(0));
	EXPECT_EQ(false, cxpFromS0CC3<S0CCv3>(0));
	EXPECT_EQ(false, cxpFromS0CC3<S0CCv4>(0));
	EXPECT_EQ(false, cxpFromS0CC3<S0CCv5>(0));

	// fromValue
	strval = "1011";
	EXPECT_EQ(true, xenums::S0combs::_fromS0CC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromS0CC(strval));
	strval = "-1011";
	EXPECT_EQ(true, xenums::S0combs::_fromS0CC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromS0CC(strval));
	strval = "1031";
	EXPECT_EQ(true, xenums::S0combs::_fromS0CC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromS0CC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromS0CC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromS0CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1011";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromS0CC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromS0CC(strval));
	strval = "-1011";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromS0CC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromS0CC(strval));
	strval = "1031";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromS0CC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromS0CC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_cxpFromS0CC(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_cxpFromS0CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
