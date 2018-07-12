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



// ========================================= get=off ============================================

/// Test xenum with identifier features: getValue=off, fromValue=off
TEST_F(TestS0combs, OffOff)
{
	// getValue=off
	try { success = false; xenums::S0combs::V0.getOffOff(); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S0combs::_fromOffOff("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S0combs::_fromOffOff("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=ext
TEST_F(TestS0combs, OffExt)
{
	// getValue=off
	try { success = false; xenums::S0combs::V0.getOffExt(); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffExt() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1001";
	EXPECT_EQ(true, xenums::S0combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromOffExt(strval));
	strval = "-1001";
	EXPECT_EQ(true, xenums::S0combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromOffExt(strval));
	strval = "1021";
	EXPECT_EQ(true, xenums::S0combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromOffExt(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromOffExt(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=inl
TEST_F(TestS0combs, OffInl)
{
	// getValue=off
	try { success = false; xenums::S0combs::V0.getOffInl(); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffInl() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1002";
	EXPECT_EQ(true, xenums::S0combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromOffInl(strval));
	strval = "-1002";
	EXPECT_EQ(true, xenums::S0combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromOffInl(strval));
	strval = "1022";
	EXPECT_EQ(true, xenums::S0combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromOffInl(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromOffInl(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromOffCxp()
/// @{
constexpr char OffCxpv0[] = "1003";
constexpr char OffCxpv1[] = "-1003";
constexpr char OffCxpv2[] = "1023";
constexpr char OffCxpv3[] = "1002";
constexpr char OffCxpv4[] = "1024";
constexpr char OffCxpv5[] = "42";
/// @}
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromOffCxp(OffCxpv0) == xenums::S0combs::V0, bool>::type cxpFromOffCxp0(void) { return true; }
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromOffCxp(OffCxpv1) == xenums::S0combs::V1, bool>::type cxpFromOffCxp1(void) { return true; }
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromOffCxp(OffCxpv2) == xenums::S0combs::V2, bool>::type cxpFromOffCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromOffCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromOffCxp(V) returns with success, and returns true if so; for testing that cxpFromOffCxp() fails correctly at compile time.
template<const char* V> bool cxpFromOffCxp3(typename std::enable_if<xenums::S0combs::_cxpFromOffCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=off, fromValue=cxp
TEST_F(TestS0combs, OffCxp)
{
	// getValue=off
	try { success = false; xenums::S0combs::V0.getOffCxp(); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffCxp() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromOffCxp0<void>());
	EXPECT_EQ(true, cxpFromOffCxp1<void>());
	EXPECT_EQ(true, cxpFromOffCxp2<void>());
	EXPECT_EQ(true, cxpFromOffCxp3<OffCxpv0>(0));
	EXPECT_EQ(true, cxpFromOffCxp3<OffCxpv1>(0));
	EXPECT_EQ(true, cxpFromOffCxp3<OffCxpv2>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<OffCxpv3>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<OffCxpv4>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<OffCxpv5>(0));

	// fromValue
	strval = "1003";
	EXPECT_EQ(true, xenums::S0combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromOffCxp(strval));
	strval = "-1003";
	EXPECT_EQ(true, xenums::S0combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromOffCxp(strval));
	strval = "1023";
	EXPECT_EQ(true, xenums::S0combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromOffCxp(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromOffCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1003";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromOffCxp(strval));
	strval = "-1003";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromOffCxp(strval));
	strval = "1023";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromOffCxp(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_cxpFromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_cxpFromOffCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=ext ============================================

/// Test xenum with identifier features: getValue=ext, fromValue=off
TEST_F(TestS0combs, ExtOff)
{
	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1004", value.getExtOff());
	EXPECT_EQ(5, value.getExtOffSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1004", value.getExtOff());
	EXPECT_EQ(6, value.getExtOffSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1024", value.getExtOff());
	EXPECT_EQ(5, value.getExtOffSize());

	// fromValue=off
	try { success = false; xenums::S0combs::_fromExtOff("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S0combs::_fromExtOff("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=ext
TEST_F(TestS0combs, ExtExt)
{
	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1005", value.getExtExt());
	EXPECT_EQ(5, value.getExtExtSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1005", value.getExtExt());
	EXPECT_EQ(6, value.getExtExtSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1025", value.getExtExt());
	EXPECT_EQ(5, value.getExtExtSize());

	// fromValue
	strval = "1005";
	EXPECT_EQ(true, xenums::S0combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromExtExt(strval));
	strval = "-1005";
	EXPECT_EQ(true, xenums::S0combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromExtExt(strval));
	strval = "1025";
	EXPECT_EQ(true, xenums::S0combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromExtExt(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromExtExt(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=inl
TEST_F(TestS0combs, ExtInl)
{
	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1006", value.getExtInl());
	EXPECT_EQ(5, value.getExtInlSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1006", value.getExtInl());
	EXPECT_EQ(6, value.getExtInlSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1026", value.getExtInl());
	EXPECT_EQ(5, value.getExtInlSize());

	// fromValue
	strval = "1006";
	EXPECT_EQ(true, xenums::S0combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromExtInl(strval));
	strval = "-1006";
	EXPECT_EQ(true, xenums::S0combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromExtInl(strval));
	strval = "1026";
	EXPECT_EQ(true, xenums::S0combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromExtInl(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromExtInl(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromExtCxp()
/// @{
constexpr char ExtCxpv0[] = "1007";
constexpr char ExtCxpv1[] = "-1007";
constexpr char ExtCxpv2[] = "1027";
constexpr char ExtCxpv3[] = "1006";
constexpr char ExtCxpv4[] = "1028";
constexpr char ExtCxpv5[] = "42";
/// @}
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromExtCxp(ExtCxpv0) == xenums::S0combs::V0, bool>::type cxpFromExtCxp0(void) { return true; }
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromExtCxp(ExtCxpv1) == xenums::S0combs::V1, bool>::type cxpFromExtCxp1(void) { return true; }
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromExtCxp(ExtCxpv2) == xenums::S0combs::V2, bool>::type cxpFromExtCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromExtCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromExtCxp(V) returns with success, and returns true if so; for testing that cxpFromExtCxp() fails correctly at compile time.
template<const char* V> bool cxpFromExtCxp3(typename std::enable_if<xenums::S0combs::_cxpFromExtCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=ext, fromValue=cxp
TEST_F(TestS0combs, ExtCxp)
{
	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1007", value.getExtCxp());
	EXPECT_EQ(5, value.getExtCxpSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1007", value.getExtCxp());
	EXPECT_EQ(6, value.getExtCxpSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1027", value.getExtCxp());
	EXPECT_EQ(5, value.getExtCxpSize());

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromExtCxp0<void>());
	EXPECT_EQ(true, cxpFromExtCxp1<void>());
	EXPECT_EQ(true, cxpFromExtCxp2<void>());
	EXPECT_EQ(true, cxpFromExtCxp3<ExtCxpv0>(0));
	EXPECT_EQ(true, cxpFromExtCxp3<ExtCxpv1>(0));
	EXPECT_EQ(true, cxpFromExtCxp3<ExtCxpv2>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<ExtCxpv3>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<ExtCxpv4>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<ExtCxpv5>(0));

	// fromValue
	strval = "1007";
	EXPECT_EQ(true, xenums::S0combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromExtCxp(strval));
	strval = "-1007";
	EXPECT_EQ(true, xenums::S0combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromExtCxp(strval));
	strval = "1027";
	EXPECT_EQ(true, xenums::S0combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromExtCxp(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromExtCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1007";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromExtCxp(strval));
	strval = "-1007";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromExtCxp(strval));
	strval = "1027";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromExtCxp(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_cxpFromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_cxpFromExtCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=cxp ============================================

/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V0.getCxpOffSize() == 5, bool>::type cxpGetCxpOffSize0() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V1.getCxpOffSize() == 6, bool>::type cxpGetCxpOffSize1() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V2.getCxpOffSize() == 5, bool>::type cxpGetCxpOffSize2() { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V0.getCxpOff(), "1008"), bool>::type cxpGetCxpOff0(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V1.getCxpOff(), "-1008"), bool>::type cxpGetCxpOff1(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V2.getCxpOff(), "1028"), bool>::type cxpGetCxpOff2(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=off
TEST_F(TestS0combs, CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpOffSize0<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize1<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpOff0<void>());
	EXPECT_EQ(true, cxpGetCxpOff1<void>());
	EXPECT_EQ(true, cxpGetCxpOff2<void>());

	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1008", value.getCxpOff());
	EXPECT_EQ(5, value.getCxpOffSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1008", value.getCxpOff());
	EXPECT_EQ(6, value.getCxpOffSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1028", value.getCxpOff());
	EXPECT_EQ(5, value.getCxpOffSize());

	// fromValue=off
	try { success = false; xenums::S0combs::_fromCxpOff("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S0combs::_fromCxpOff("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V0.getCxpExtSize() == 5, bool>::type cxpGetCxpExtSize0() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V1.getCxpExtSize() == 6, bool>::type cxpGetCxpExtSize1() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V2.getCxpExtSize() == 5, bool>::type cxpGetCxpExtSize2() { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V0.getCxpExt(), "1009"), bool>::type cxpGetCxpExt0(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V1.getCxpExt(), "-1009"), bool>::type cxpGetCxpExt1(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V2.getCxpExt(), "1029"), bool>::type cxpGetCxpExt2(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=ext
TEST_F(TestS0combs, CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpExtSize0<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize1<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpExt0<void>());
	EXPECT_EQ(true, cxpGetCxpExt1<void>());
	EXPECT_EQ(true, cxpGetCxpExt2<void>());

	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1009", value.getCxpExt());
	EXPECT_EQ(5, value.getCxpExtSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1009", value.getCxpExt());
	EXPECT_EQ(6, value.getCxpExtSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1029", value.getCxpExt());
	EXPECT_EQ(5, value.getCxpExtSize());

	// fromValue
	strval = "1009";
	EXPECT_EQ(true, xenums::S0combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromCxpExt(strval));
	strval = "-1009";
	EXPECT_EQ(true, xenums::S0combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromCxpExt(strval));
	strval = "1029";
	EXPECT_EQ(true, xenums::S0combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromCxpExt(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromCxpExt(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V0.getCxpInlSize() == 5, bool>::type cxpGetCxpInlSize0() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V1.getCxpInlSize() == 6, bool>::type cxpGetCxpInlSize1() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V2.getCxpInlSize() == 5, bool>::type cxpGetCxpInlSize2() { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V0.getCxpInl(), "1010"), bool>::type cxpGetCxpInl0(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V1.getCxpInl(), "-1010"), bool>::type cxpGetCxpInl1(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V2.getCxpInl(), "1030"), bool>::type cxpGetCxpInl2(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=inl
TEST_F(TestS0combs, CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpInlSize0<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize1<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpInl0<void>());
	EXPECT_EQ(true, cxpGetCxpInl1<void>());
	EXPECT_EQ(true, cxpGetCxpInl2<void>());

	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1010", value.getCxpInl());
	EXPECT_EQ(5, value.getCxpInlSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1010", value.getCxpInl());
	EXPECT_EQ(6, value.getCxpInlSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1030", value.getCxpInl());
	EXPECT_EQ(5, value.getCxpInlSize());

	// fromValue
	strval = "1010";
	EXPECT_EQ(true, xenums::S0combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromCxpInl(strval));
	strval = "-1010";
	EXPECT_EQ(true, xenums::S0combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromCxpInl(strval));
	strval = "1030";
	EXPECT_EQ(true, xenums::S0combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromCxpInl(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromCxpInl(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V0.getCxpCxpSize() == 5, bool>::type cxpGetCxpCxpSize0() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V1.getCxpCxpSize() == 6, bool>::type cxpGetCxpCxpSize1() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::V2.getCxpCxpSize() == 5, bool>::type cxpGetCxpCxpSize2() { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V0.getCxpCxp(), "1011"), bool>::type cxpGetCxpCxp0(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V1.getCxpCxp(), "-1011"), bool>::type cxpGetCxpCxp1(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S0combs::V2.getCxpCxp(), "1031"), bool>::type cxpGetCxpCxp2(void) { return true; }
/// Values for testing cxpFromCxpCxp()
/// @{
constexpr char CxpCxpv0[] = "1011";
constexpr char CxpCxpv1[] = "-1011";
constexpr char CxpCxpv2[] = "1031";
constexpr char CxpCxpv3[] = "1010";
constexpr char CxpCxpv4[] = "1032";
constexpr char CxpCxpv5[] = "42";
/// @}
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromCxpCxp("1011") == xenums::S0combs::V0, bool>::type cxpFromCxpCxp0(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromCxpCxp("-1011") == xenums::S0combs::V1, bool>::type cxpFromCxpCxp1(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S0combs::_cxpFromCxpCxp("1031") == xenums::S0combs::V2, bool>::type cxpFromCxpCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromCxpCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromCxpCxp(V) returns with success, and returns true if so; for testing that cxpFromCxpCxp() fails correctly at compile time.
template<const char* V> bool cxpFromCxpCxp3(typename std::enable_if<xenums::S0combs::_cxpFromCxpCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=cxp
TEST_F(TestS0combs, CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpCxpSize0<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize1<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpCxp0<void>());
	EXPECT_EQ(true, cxpGetCxpCxp1<void>());
	EXPECT_EQ(true, cxpGetCxpCxp2<void>());

	// getValue()
	// V0
	value = xenums::S0combs::V0;
	EXPECT_STREQ("1011", value.getCxpCxp());
	EXPECT_EQ(5, value.getCxpCxpSize());
	// V1
	value = xenums::S0combs::V1;
	EXPECT_STREQ("-1011", value.getCxpCxp());
	EXPECT_EQ(6, value.getCxpCxpSize());
	// V2
	value = xenums::S0combs::V2;
	EXPECT_STREQ("1031", value.getCxpCxp());
	EXPECT_EQ(5, value.getCxpCxpSize());

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromCxpCxp0<void>());
	EXPECT_EQ(true, cxpFromCxpCxp1<void>());
	EXPECT_EQ(true, cxpFromCxpCxp2<void>());
	EXPECT_EQ(true, cxpFromCxpCxp3<CxpCxpv0>(0));
	EXPECT_EQ(true, cxpFromCxpCxp3<CxpCxpv1>(0));
	EXPECT_EQ(true, cxpFromCxpCxp3<CxpCxpv2>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<CxpCxpv3>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<CxpCxpv4>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<CxpCxpv5>(0));

	// fromValue
	strval = "1011";
	EXPECT_EQ(true, xenums::S0combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_fromCxpCxp(strval));
	strval = "-1011";
	EXPECT_EQ(true, xenums::S0combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_fromCxpCxp(strval));
	strval = "1031";
	EXPECT_EQ(true, xenums::S0combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_fromCxpCxp(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_fromCxpCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1011";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V0);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromCxpCxp(strval));
	strval = "-1011";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V1);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromCxpCxp(strval));
	strval = "1031";
	EXPECT_EQ(true, xenums::S0combs::_cxpFromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	EXPECT_EQ(value, xenums::S0combs::_cxpFromCxpCxp(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::S0combs::_cxpFromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S0combs::V2);
	try { success = false; xenums::S0combs::_cxpFromCxpCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
