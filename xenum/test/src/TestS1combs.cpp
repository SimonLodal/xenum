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

#include <test/xenum/xenums/S1combs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenums with combinations of custom property options.
 */
class TestS1combs : public ::testing::Test {
public:
	bool success;
	xenums::S1comb value;
	const char* strval;
};


/// Test basics of S1combs xenum.
TEST_F(TestS1combs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_S1combs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::S1combs::_size);
}



// ========================================= get=off ============================================

/// Test xenum with identifier features: getValue=off, fromValue=off
TEST_F(TestS1combs, OffOff)
{
	// getValue=off
	try { success = false; xenums::S1combs::V0.getOffOff(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S1combs::_fromOffOff("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S1combs::_fromOffOff("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=ext
TEST_F(TestS1combs, OffExt)
{
	// getValue=off
	try { success = false; xenums::S1combs::V0.getOffExt(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffExt() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1102";
	EXPECT_EQ(true, xenums::S1combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromOffExt(strval));
	// Not unique
	//strval = "-1101";
	//EXPECT_EQ(true, xenums::S1combs::_fromOffExt(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromOffExt(strval));
	strval = "1103";
	EXPECT_EQ(true, xenums::S1combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromOffExt(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromOffExt(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=inl
TEST_F(TestS1combs, OffInl)
{
	// getValue=off
	try { success = false; xenums::S1combs::V0.getOffInl(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffInl() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1104";
	EXPECT_EQ(true, xenums::S1combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromOffInl(strval));
	// Not unique
	//strval = "-1102";
	//EXPECT_EQ(true, xenums::S1combs::_fromOffInl(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromOffInl(strval));
	strval = "1105";
	EXPECT_EQ(true, xenums::S1combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromOffInl(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromOffInl(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromOffCxp()
constexpr char OffCxpv0[] = "1106";
//constexpr char OffCxpv1[] = "-1103";
constexpr char OffCxpv2[] = "1107";
constexpr char OffCxpv3[] = "1105";
constexpr char OffCxpv4[] = "1108";
constexpr char OffCxpv5[] = "42";
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromOffCxp(OffCxpv0) == xenums::S1combs::V0, bool>::type cxpFromOffCxp0(void) { return true; }
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromOffCxp(OffCxpv2) == xenums::S1combs::V0, bool>::type cxpFromOffCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromOffCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromOffCxp(V) returns with success, and returns true if so; for testing that cxpFromOffCxp() fails correctly at compile time.
template<const char* V> bool cxpFromOffCxp3(typename std::enable_if<xenums::S1combs::_cxpFromOffCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=off, fromValue=cxp
TEST_F(TestS1combs, OffCxp)
{
	// getValue=off
	try { success = false; xenums::S1combs::V0.getOffCxp(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffCxp() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromOffCxp0<void>());
	EXPECT_EQ(true, cxpFromOffCxp2<void>());
	EXPECT_EQ(true, cxpFromOffCxp3<OffCxpv0>(0));
	//EXPECT_EQ(true, cxpFromOffCxp3<OffCxpv1>(0));
	EXPECT_EQ(true, cxpFromOffCxp3<OffCxpv2>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<OffCxpv3>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<OffCxpv4>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<OffCxpv5>(0));

	// fromValue
	strval = "1106";
	EXPECT_EQ(true, xenums::S1combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromOffCxp(strval));
	// Not unique
	//strval = "-1103";
	//EXPECT_EQ(true, xenums::S1combs::_fromOffCxp(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromOffCxp(strval));
	strval = "1107";
	EXPECT_EQ(true, xenums::S1combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromOffCxp(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromOffCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1106";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromOffCxp(strval));
	// Not unique
	//strval = "-1103";
	//EXPECT_EQ(true, xenums::S1combs::_cxpFromOffCxp(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_cxpFromOffCxp(strval));
	strval = "1107";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromOffCxp(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_cxpFromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_cxpFromOffCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=ext ============================================

/// Test xenum with identifier features: getValue=ext, fromValue=off
TEST_F(TestS1combs, ExtOff)
{
	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getExtOffSize());
	EXPECT_STREQ("1110", value.getExtOff(0));
	EXPECT_EQ(5, value.getExtOffSize(0));
	EXPECT_STREQ("-1104", value.getExtOff(1));
	EXPECT_EQ(6, value.getExtOffSize(1));
	EXPECT_STREQ("1111", value.getExtOff(2));
	EXPECT_EQ(5, value.getExtOffSize(2));
	try { success = false; value.getExtOff(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOffSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getExtOffSize());
	try { success = false; value.getExtOff(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOffSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getExtOffSize());
	EXPECT_STREQ("-1104", value.getExtOff(0));
	EXPECT_EQ(6, value.getExtOffSize(0));
	try { success = false; value.getExtOff(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOffSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S1combs::_fromExtOff("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S1combs::_fromExtOff("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=ext
TEST_F(TestS1combs, ExtExt)
{
	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getExtExtSize());
	EXPECT_STREQ("1112", value.getExtExt(0));
	EXPECT_EQ(5, value.getExtExtSize(0));
	EXPECT_STREQ("-1105", value.getExtExt(1));
	EXPECT_EQ(6, value.getExtExtSize(1));
	EXPECT_STREQ("1113", value.getExtExt(2));
	EXPECT_EQ(5, value.getExtExtSize(2));
	try { success = false; value.getExtExt(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExtSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getExtExtSize());
	try { success = false; value.getExtExt(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExtSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getExtExtSize());
	EXPECT_STREQ("-1105", value.getExtExt(0));
	EXPECT_EQ(6, value.getExtExtSize(0));
	try { success = false; value.getExtExt(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExtSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1112";
	EXPECT_EQ(true, xenums::S1combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromExtExt(strval));
	// Not unique
	//strval = "-1105";
	//EXPECT_EQ(true, xenums::S1combs::_fromExtExt(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromExtExt(strval));
	strval = "1113";
	EXPECT_EQ(true, xenums::S1combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromExtExt(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromExtExt(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=inl
TEST_F(TestS1combs, ExtInl)
{
	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getExtInlSize());
	EXPECT_STREQ("1114", value.getExtInl(0));
	EXPECT_EQ(5, value.getExtInlSize(0));
	EXPECT_STREQ("-1106", value.getExtInl(1));
	EXPECT_EQ(6, value.getExtInlSize(1));
	EXPECT_STREQ("1115", value.getExtInl(2));
	EXPECT_EQ(5, value.getExtInlSize(2));
	try { success = false; value.getExtInl(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInlSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getExtInlSize());
	try { success = false; value.getExtInl(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInlSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getExtInlSize());
	EXPECT_STREQ("-1106", value.getExtInl(0));
	EXPECT_EQ(6, value.getExtInlSize(0));
	try { success = false; value.getExtInl(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInlSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1114";
	EXPECT_EQ(true, xenums::S1combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromExtInl(strval));
	// Not unique
	//strval = "-1106";
	//EXPECT_EQ(true, xenums::S1combs::_fromExtInl(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromExtInl(strval));
	strval = "1115";
	EXPECT_EQ(true, xenums::S1combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromExtInl(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromExtInl(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromExtCxp()
constexpr char ExtCxpv0[] = "1116";
//constexpr char ExtCxpv1[] = "-1107";
constexpr char ExtCxpv2[] = "1117";
constexpr char ExtCxpv3[] = "1115";
constexpr char ExtCxpv4[] = "1118";
constexpr char ExtCxpv5[] = "42";
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromExtCxp(ExtCxpv0) == xenums::S1combs::V0, bool>::type cxpFromExtCxp0(void) { return true; }
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromExtCxp(ExtCxpv2) == xenums::S1combs::V0, bool>::type cxpFromExtCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromExtCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromExtCxp(V) returns with success, and returns true if so; for testing that cxpFromExtCxp() fails correctly at compile time.
template<const char* V> bool cxpFromExtCxp3(typename std::enable_if<xenums::S1combs::_cxpFromExtCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=ext, fromValue=cxp
TEST_F(TestS1combs, ExtCxp)
{
	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getExtCxpSize());
	EXPECT_STREQ("1116", value.getExtCxp(0));
	EXPECT_EQ(5, value.getExtCxpSize(0));
	EXPECT_STREQ("-1107", value.getExtCxp(1));
	EXPECT_EQ(6, value.getExtCxpSize(1));
	EXPECT_STREQ("1117", value.getExtCxp(2));
	EXPECT_EQ(5, value.getExtCxpSize(2));
	try { success = false; value.getExtCxp(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxpSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getExtCxpSize());
	try { success = false; value.getExtCxp(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxpSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getExtCxpSize());
	EXPECT_STREQ("-1107", value.getExtCxp(0));
	EXPECT_EQ(6, value.getExtCxpSize(0));
	try { success = false; value.getExtCxp(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxpSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromExtCxp0<void>());
	EXPECT_EQ(true, cxpFromExtCxp2<void>());
	EXPECT_EQ(true, cxpFromExtCxp3<ExtCxpv0>(0));
	//EXPECT_EQ(true, cxpFromExtCxp3<ExtCxpv1>(0));
	EXPECT_EQ(true, cxpFromExtCxp3<ExtCxpv2>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<ExtCxpv3>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<ExtCxpv4>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<ExtCxpv5>(0));

	// fromValue
	strval = "1116";
	EXPECT_EQ(true, xenums::S1combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromExtCxp(strval));
	// Not unique
	//strval = "-1107";
	//EXPECT_EQ(true, xenums::S1combs::_fromExtCxp(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromExtCxp(strval));
	strval = "1117";
	EXPECT_EQ(true, xenums::S1combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromExtCxp(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromExtCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1116";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromExtCxp(strval));
	// Not unique
	//strval = "-1107";
	//EXPECT_EQ(true, xenums::S1combs::_cxpFromExtCxp(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_cxpFromExtCxp(strval));
	strval = "1117";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromExtCxp(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_cxpFromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_cxpFromExtCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=cxp ============================================

/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpOffSize() == 3, bool>::type cxpGetCxpOffSize0() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V1.getCxpOffSize() == 0, bool>::type cxpGetCxpOffSize1() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getCxpOffSize() == 1, bool>::type cxpGetCxpOffSize2() { return true; }

/// Function that only compiles if the constexpr getCxpOffSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpOffSize(0) == 5, bool>::type cxpGetCxpOffSize00() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpOffSize(1) == 6, bool>::type cxpGetCxpOffSize01() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpOffSize(2) == 5, bool>::type cxpGetCxpOffSize02() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getCxpOffSize(0) == 6, bool>::type cxpGetCxpOffSize20() { return true; }

/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpOff(0), "1120"), bool>::type cxpGetCxpOff0(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpOff(1), "-1108"), bool>::type cxpGetCxpOff1(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpOff(2), "1121"), bool>::type cxpGetCxpOff2(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V2.getCxpOff(0), "-1108"), bool>::type cxpGetCxpOff3(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=off
TEST_F(TestS1combs, CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpOffSize0<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize1<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize2<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize00<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize01<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize02<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpOff0<void>());
	EXPECT_EQ(true, cxpGetCxpOff1<void>());
	EXPECT_EQ(true, cxpGetCxpOff2<void>());
	EXPECT_EQ(true, cxpGetCxpOff3<void>());

	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getCxpOffSize());
	EXPECT_STREQ("1120", value.getCxpOff(0));
	EXPECT_EQ(5, value.getCxpOffSize(0));
	EXPECT_STREQ("-1108", value.getCxpOff(1));
	EXPECT_EQ(6, value.getCxpOffSize(1));
	EXPECT_STREQ("1121", value.getCxpOff(2));
	EXPECT_EQ(5, value.getCxpOffSize(2));
	try { success = false; value.getCxpOff(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOffSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getCxpOffSize());
	try { success = false; value.getCxpOff(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOffSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getCxpOffSize());
	EXPECT_STREQ("-1108", value.getCxpOff(0));
	EXPECT_EQ(6, value.getCxpOffSize(0));
	try { success = false; value.getCxpOff(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOffSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S1combs::_fromCxpOff("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S1combs::_fromCxpOff("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpExtSize() == 3, bool>::type cxpGetCxpExtSize0() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V1.getCxpExtSize() == 0, bool>::type cxpGetCxpExtSize1() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getCxpExtSize() == 1, bool>::type cxpGetCxpExtSize2() { return true; }

/// Function that only compiles if the constexpr getCxpExtSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpExtSize(0) == 5, bool>::type cxpGetCxpExtSize00() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpExtSize(1) == 6, bool>::type cxpGetCxpExtSize01() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpExtSize(2) == 5, bool>::type cxpGetCxpExtSize02() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getCxpExtSize(0) == 6, bool>::type cxpGetCxpExtSize20() { return true; }

/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpExt(0), "1122"), bool>::type cxpGetCxpExt0(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpExt(1), "-1109"), bool>::type cxpGetCxpExt1(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpExt(2), "1123"), bool>::type cxpGetCxpExt2(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V2.getCxpExt(0), "-1109"), bool>::type cxpGetCxpExt3(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=ext
TEST_F(TestS1combs, CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpExtSize0<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize1<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize2<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize00<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize01<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize02<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpExt0<void>());
	EXPECT_EQ(true, cxpGetCxpExt1<void>());
	EXPECT_EQ(true, cxpGetCxpExt2<void>());
	EXPECT_EQ(true, cxpGetCxpExt3<void>());

	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getCxpExtSize());
	EXPECT_STREQ("1122", value.getCxpExt(0));
	EXPECT_EQ(5, value.getCxpExtSize(0));
	EXPECT_STREQ("-1109", value.getCxpExt(1));
	EXPECT_EQ(6, value.getCxpExtSize(1));
	EXPECT_STREQ("1123", value.getCxpExt(2));
	EXPECT_EQ(5, value.getCxpExtSize(2));
	try { success = false; value.getCxpExt(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExtSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getCxpExtSize());
	try { success = false; value.getCxpExt(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExtSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getCxpExtSize());
	EXPECT_STREQ("-1109", value.getCxpExt(0));
	EXPECT_EQ(6, value.getCxpExtSize(0));
	try { success = false; value.getCxpExt(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExtSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1122";
	EXPECT_EQ(true, xenums::S1combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromCxpExt(strval));
	// Not unique
	//strval = "-1109";
	//EXPECT_EQ(true, xenums::S1combs::_fromCxpExt(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromCxpExt(strval));
	strval = "1123";
	EXPECT_EQ(true, xenums::S1combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromCxpExt(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromCxpExt(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpInlSize() == 3, bool>::type cxpGetCxpInlSize0() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V1.getCxpInlSize() == 0, bool>::type cxpGetCxpInlSize1() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getCxpInlSize() == 1, bool>::type cxpGetCxpInlSize2() { return true; }

/// Function that only compiles if the constexpr getCxpInlSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpInlSize(0) == 5, bool>::type cxpGetCxpInlSize00() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpInlSize(1) == 6, bool>::type cxpGetCxpInlSize01() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpInlSize(2) == 5, bool>::type cxpGetCxpInlSize02() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getCxpInlSize(0) == 6, bool>::type cxpGetCxpInlSize20() { return true; }

/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpInl(0), "1124"), bool>::type cxpGetCxpInl0(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpInl(1), "-1110"), bool>::type cxpGetCxpInl1(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpInl(2), "1125"), bool>::type cxpGetCxpInl2(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V2.getCxpInl(0), "-1110"), bool>::type cxpGetCxpInl3(void) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=inl
TEST_F(TestS1combs, CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpInlSize0<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize1<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize2<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize00<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize01<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize02<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpInl0<void>());
	EXPECT_EQ(true, cxpGetCxpInl1<void>());
	EXPECT_EQ(true, cxpGetCxpInl2<void>());
	EXPECT_EQ(true, cxpGetCxpInl3<void>());

	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getCxpInlSize());
	EXPECT_STREQ("1124", value.getCxpInl(0));
	EXPECT_EQ(5, value.getCxpInlSize(0));
	EXPECT_STREQ("-1110", value.getCxpInl(1));
	EXPECT_EQ(6, value.getCxpInlSize(1));
	EXPECT_STREQ("1125", value.getCxpInl(2));
	EXPECT_EQ(5, value.getCxpInlSize(2));
	try { success = false; value.getCxpInl(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInlSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getCxpInlSize());
	try { success = false; value.getCxpInl(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInlSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getCxpInlSize());
	EXPECT_STREQ("-1110", value.getCxpInl(0));
	EXPECT_EQ(6, value.getCxpInlSize(0));
	try { success = false; value.getCxpInl(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInlSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1124";
	EXPECT_EQ(true, xenums::S1combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromCxpInl(strval));
	// Not unique
	//strval = "-1110";
	//EXPECT_EQ(true, xenums::S1combs::_fromCxpInl(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromCxpInl(strval));
	strval = "1125";
	EXPECT_EQ(true, xenums::S1combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromCxpInl(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromCxpInl(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpCxpSize() == 3, bool>::type cxpGetCxpCxpSize0() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V1.getCxpCxpSize() == 0, bool>::type cxpGetCxpCxpSize1() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getCxpCxpSize() == 1, bool>::type cxpGetCxpCxpSize2() { return true; }

/// Function that only compiles if the constexpr getCxpCxpSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpCxpSize(0) == 5, bool>::type cxpGetCxpCxpSize00() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpCxpSize(1) == 6, bool>::type cxpGetCxpCxpSize01() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getCxpCxpSize(2) == 5, bool>::type cxpGetCxpCxpSize02() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getCxpCxpSize(0) == 6, bool>::type cxpGetCxpCxpSize20() { return true; }

/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpCxp(0), "1126"), bool>::type cxpGetCxpCxp0(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpCxp(1), "-1111"), bool>::type cxpGetCxpCxp1(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getCxpCxp(2), "1127"), bool>::type cxpGetCxpCxp2(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V2.getCxpCxp(0), "-1111"), bool>::type cxpGetCxpCxp3(void) { return true; }

/// Values for testing cxpFromCxpCxp()
constexpr char CxpCxpv0[] = "1126";
//constexpr char CxpCxpv1[] = "-1111";
constexpr char CxpCxpv2[] = "1127";
constexpr char CxpCxpv3[] = "1125";
constexpr char CxpCxpv4[] = "1128";
constexpr char CxpCxpv5[] = "42";
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromCxpCxp(CxpCxpv0) == xenums::S1combs::V0, bool>::type cxpFromCxpCxp0(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromCxpCxp(CxpCxpv2) == xenums::S1combs::V0, bool>::type cxpFromCxpCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromCxpCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromCxpCxp(V) returns with success, and returns true if so; for testing that cxpFromCxpCxp() fails correctly at compile time.
template<const char* V> bool cxpFromCxpCxp3(typename std::enable_if<xenums::S1combs::_cxpFromCxpCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=cxp
TEST_F(TestS1combs, CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpCxpSize0<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize1<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize2<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize00<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize01<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize02<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpCxp0<void>());
	EXPECT_EQ(true, cxpGetCxpCxp1<void>());
	EXPECT_EQ(true, cxpGetCxpCxp2<void>());
	EXPECT_EQ(true, cxpGetCxpCxp3<void>());

	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getCxpCxpSize());
	EXPECT_STREQ("1126", value.getCxpCxp(0));
	EXPECT_EQ(5, value.getCxpCxpSize(0));
	EXPECT_STREQ("-1111", value.getCxpCxp(1));
	EXPECT_EQ(6, value.getCxpCxpSize(1));
	EXPECT_STREQ("1127", value.getCxpCxp(2));
	EXPECT_EQ(5, value.getCxpCxpSize(2));
	try { success = false; value.getCxpCxp(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxpSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getCxpCxpSize());
	try { success = false; value.getCxpCxp(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxpSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getCxpCxpSize());
	EXPECT_STREQ("-1111", value.getCxpCxp(0));
	EXPECT_EQ(6, value.getCxpCxpSize(0));
	try { success = false; value.getCxpCxp(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxpSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromCxpCxp0<void>());
	EXPECT_EQ(true, cxpFromCxpCxp2<void>());
	EXPECT_EQ(true, cxpFromCxpCxp3<CxpCxpv0>(0));
	//EXPECT_EQ(true, cxpFromCxpCxp3<CxpCxpv1>(0));
	EXPECT_EQ(true, cxpFromCxpCxp3<CxpCxpv2>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<CxpCxpv3>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<CxpCxpv4>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<CxpCxpv5>(0));

	// fromValue
	strval = "1126";
	EXPECT_EQ(true, xenums::S1combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromCxpCxp(strval));
	// Not unique
	//strval = "-1111";
	//EXPECT_EQ(true, xenums::S1combs::_fromCxpCxp(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromCxpCxp(strval));
	strval = "1127";
	EXPECT_EQ(true, xenums::S1combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromCxpCxp(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromCxpCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1126";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromCxpCxp(strval));
	// Not unique
	//strval = "-1111";
	//EXPECT_EQ(true, xenums::S1combs::_cxpFromCxpCxp(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_cxpFromCxpCxp(strval));
	strval = "1127";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromCxpCxp(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_cxpFromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_cxpFromCxpCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
