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

#include <test/xenum/xenums/S2combs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenums with combinations of custom property options.
 */
class TestS2combs : public ::testing::Test {
public:
	bool success;
	xenums::S2comb value;
	const char* strval;
};


/// Test basics of S2combs xenum.
TEST_F(TestS2combs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_S2combs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::S2combs::_size);
}



// ========================================= get=off ============================================

/// Test xenum with identifier features: getValue=off, fromValue=off
TEST_F(TestS2combs, OffOff)
{
	// getValue=off
	try { success = false; xenums::S2combs::V0.getOffOff(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S2combs::_fromOffOff("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S2combs::_fromOffOff("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=ext
TEST_F(TestS2combs, OffExt)
{
	// getValue=off
	try { success = false; xenums::S2combs::V0.getOffExt(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffExt() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	strval = "1202";
	EXPECT_EQ(true, xenums::S2combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromOffExt(strval));
	strval = "1203";
	EXPECT_EQ(true, xenums::S2combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromOffExt(strval));
	// Not unique, but both are in V0.
	strval = "-1201";
	EXPECT_EQ(true, xenums::S2combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromOffExt(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromOffExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromOffExt(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=inl
TEST_F(TestS2combs, OffInl)
{
	// getValue=off
	try { success = false; xenums::S2combs::V0.getOffInl(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffInl() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	strval = "1204";
	EXPECT_EQ(true, xenums::S2combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromOffInl(strval));
	strval = "1205";
	EXPECT_EQ(true, xenums::S2combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromOffInl(strval));
	// Not unique, but both are in V0.
	strval = "-1202";
	EXPECT_EQ(true, xenums::S2combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromOffInl(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromOffInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromOffInl(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromOffCxp()
constexpr char OffCxpv0[] = "1206";
constexpr char OffCxpv1[] = "-1203";
constexpr char OffCxpv2[] = "1207";
constexpr char OffCxpv3[] = "1205";
constexpr char OffCxpv4[] = "1208";
constexpr char OffCxpv5[] = "42";
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromOffCxp(OffCxpv0) == xenums::S2combs::V0, bool>::type cxpFromOffCxp0(void) { return true; }
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromOffCxp(OffCxpv1) == xenums::S2combs::V0, bool>::type cxpFromOffCxp1(void) { return true; }
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromOffCxp(OffCxpv2) == xenums::S2combs::V0, bool>::type cxpFromOffCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromOffCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromOffCxp(V) returns with success, and returns true if so; for testing that cxpFromOffCxp() fails correctly at compile time.
template<const char* V> bool cxpFromOffCxp3(typename std::enable_if<xenums::S2combs::_cxpFromOffCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=off, fromValue=cxp
TEST_F(TestS2combs, OffCxp)
{
	// getValue=off
	try { success = false; xenums::S2combs::V0.getOffCxp(0, 0); }
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

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::S2combs::V0, xenums::S2combs::_cxpFromOffCxp("1206"));
	// Not unique, but both are in V0.
 	EXPECT_EQ(xenums::S2combs::V0, xenums::S2combs::_cxpFromOffCxp("-1203"));
 	EXPECT_EQ(xenums::S2combs::V0, xenums::S2combs::_cxpFromOffCxp("1207"));
	try { success = false; xenums::S2combs::_cxpFromOffCxp("42"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	strval = "1206";
	EXPECT_EQ(true, xenums::S2combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromOffCxp(strval));
	strval = "1207";
	EXPECT_EQ(true, xenums::S2combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromOffCxp(strval));
	// Not unique, but both are in V0.
	strval = "-1203";
	EXPECT_EQ(true, xenums::S2combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromOffCxp(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromOffCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromOffCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=ext ============================================

/// Test xenum with identifier features: getValue=ext, fromValue=off
TEST_F(TestS2combs, ExtOff)
{
	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getExtOffSize());
	EXPECT_EQ(3, value.getExtOffSize(0));
	EXPECT_EQ(1, value.getExtOffSize(1));
	try { success = false; value.getExtOffSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1210", value.getExtOff(0, 0));
	EXPECT_EQ(5, value.getExtOffSize(0, 0));
	EXPECT_STREQ("-1204", value.getExtOff(0, 1));
	EXPECT_EQ(6, value.getExtOffSize(0, 1));
	EXPECT_STREQ("1211", value.getExtOff(0, 2));
	EXPECT_EQ(5, value.getExtOffSize(0, 2));
	try { success = false; value.getExtOff(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOffSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1204", value.getExtOff(1, 0));
	EXPECT_EQ(6, value.getExtOffSize(1, 0));
	try { success = false; value.getExtOff(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOffSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getExtOff(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOffSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getExtOffSize());
	try { success = false; value.getExtOffSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOff(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOffSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getExtOffSize());
	EXPECT_EQ(0, value.getExtOffSize(0));
	try { success = false; value.getExtOffSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOff(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOffSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S2combs::_fromExtOff("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S2combs::_fromExtOff("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=ext
TEST_F(TestS2combs, ExtExt)
{
	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getExtExtSize());
	EXPECT_EQ(3, value.getExtExtSize(0));
	EXPECT_EQ(1, value.getExtExtSize(1));
	try { success = false; value.getExtExtSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1212", value.getExtExt(0, 0));
	EXPECT_EQ(5, value.getExtExtSize(0, 0));
	EXPECT_STREQ("-1205", value.getExtExt(0, 1));
	EXPECT_EQ(6, value.getExtExtSize(0, 1));
	EXPECT_STREQ("1213", value.getExtExt(0, 2));
	EXPECT_EQ(5, value.getExtExtSize(0, 2));
	try { success = false; value.getExtExt(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExtSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1205", value.getExtExt(1, 0));
	EXPECT_EQ(6, value.getExtExtSize(1, 0));
	try { success = false; value.getExtExt(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExtSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getExtExt(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExtSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getExtExtSize());
	try { success = false; value.getExtExtSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExt(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExtSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getExtExtSize());
	EXPECT_EQ(0, value.getExtExtSize(0));
	try { success = false; value.getExtExtSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExt(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExtSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	strval = "1212";
	EXPECT_EQ(true, xenums::S2combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromExtExt(strval));
	strval = "1213";
	EXPECT_EQ(true, xenums::S2combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromExtExt(strval));
	// Not unique, but both are in V0.
	strval = "-1205";
	EXPECT_EQ(true, xenums::S2combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromExtExt(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromExtExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromExtExt(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=inl
TEST_F(TestS2combs, ExtInl)
{
	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getExtInlSize());
	EXPECT_EQ(3, value.getExtInlSize(0));
	EXPECT_EQ(1, value.getExtInlSize(1));
	try { success = false; value.getExtInlSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1214", value.getExtInl(0, 0));
	EXPECT_EQ(5, value.getExtInlSize(0, 0));
	EXPECT_STREQ("-1206", value.getExtInl(0, 1));
	EXPECT_EQ(6, value.getExtInlSize(0, 1));
	EXPECT_STREQ("1215", value.getExtInl(0, 2));
	EXPECT_EQ(5, value.getExtInlSize(0, 2));
	try { success = false; value.getExtInl(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInlSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1206", value.getExtInl(1, 0));
	EXPECT_EQ(6, value.getExtInlSize(1, 0));
	try { success = false; value.getExtInl(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInlSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getExtInl(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInlSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getExtInlSize());
	try { success = false; value.getExtInlSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInl(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInlSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getExtInlSize());
	EXPECT_EQ(0, value.getExtInlSize(0));
	try { success = false; value.getExtInlSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInl(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInlSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	strval = "1214";
	EXPECT_EQ(true, xenums::S2combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromExtInl(strval));
	strval = "1215";
	EXPECT_EQ(true, xenums::S2combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromExtInl(strval));
	// Not unique, but both are in V0.
	strval = "-1206";
	EXPECT_EQ(true, xenums::S2combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromExtInl(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromExtInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromExtInl(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromExtCxp()
constexpr char ExtCxpv0[] = "1216";
constexpr char ExtCxpv1[] = "-1207";
constexpr char ExtCxpv2[] = "1217";
constexpr char ExtCxpv3[] = "1215";
constexpr char ExtCxpv4[] = "1218";
constexpr char ExtCxpv5[] = "42";
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromExtCxp(ExtCxpv0) == xenums::S2combs::V0, bool>::type cxpFromExtCxp0(void) { return true; }
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromExtCxp(ExtCxpv1) == xenums::S2combs::V0, bool>::type cxpFromExtCxp1(void) { return true; }
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromExtCxp(ExtCxpv2) == xenums::S2combs::V0, bool>::type cxpFromExtCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromExtCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromExtCxp(V) returns with success, and returns true if so; for testing that cxpFromExtCxp() fails correctly at compile time.
template<const char* V> bool cxpFromExtCxp3(typename std::enable_if<xenums::S2combs::_cxpFromExtCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=ext, fromValue=cxp
TEST_F(TestS2combs, ExtCxp)
{
	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getExtCxpSize());
	EXPECT_EQ(3, value.getExtCxpSize(0));
	EXPECT_EQ(1, value.getExtCxpSize(1));
	try { success = false; value.getExtCxpSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1216", value.getExtCxp(0, 0));
	EXPECT_EQ(5, value.getExtCxpSize(0, 0));
	EXPECT_STREQ("-1207", value.getExtCxp(0, 1));
	EXPECT_EQ(6, value.getExtCxpSize(0, 1));
	EXPECT_STREQ("1217", value.getExtCxp(0, 2));
	EXPECT_EQ(5, value.getExtCxpSize(0, 2));
	try { success = false; value.getExtCxp(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxpSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1207", value.getExtCxp(1, 0));
	EXPECT_EQ(6, value.getExtCxpSize(1, 0));
	try { success = false; value.getExtCxp(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxpSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getExtCxp(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxpSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getExtCxpSize());
	try { success = false; value.getExtCxpSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxp(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxpSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getExtCxpSize());
	EXPECT_EQ(0, value.getExtCxpSize(0));
	try { success = false; value.getExtCxpSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxp(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxpSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

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

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::S2combs::V0, xenums::S2combs::_cxpFromExtCxp("1216"));
	EXPECT_EQ(xenums::S2combs::V0, xenums::S2combs::_cxpFromExtCxp("1217"));
	// Not unique, but both are in V0.
	EXPECT_EQ(xenums::S2combs::V0, xenums::S2combs::_cxpFromExtCxp("-1207"));
	try { success = false; xenums::S2combs::_cxpFromExtCxp("42"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	strval = "1216";
	EXPECT_EQ(true, xenums::S2combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromExtCxp(strval));
	strval = "1217";
	EXPECT_EQ(true, xenums::S2combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromExtCxp(strval));
	// Not unique, but both are in V0.
	strval = "-1207";
	EXPECT_EQ(true, xenums::S2combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromExtCxp(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromExtCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromExtCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=cxp ============================================

/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpOffSize() == 2, bool>::type cxpGetCxpOffSize0() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V1.getCxpOffSize() == 0, bool>::type cxpGetCxpOffSize1() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getCxpOffSize() == 1, bool>::type cxpGetCxpOffSize2() { return true; }

/// Function that only compiles if the constexpr getCxpOffSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpOffSize(0) == 3, bool>::type cxpGetCxpOffSize00() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpOffSize(1) == 1, bool>::type cxpGetCxpOffSize01() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getCxpOffSize(0) == 0, bool>::type cxpGetCxpOffSize20() { return true; }

/// Function that only compiles if the constexpr getCxpOffSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpOffSize(0,0) == 5, bool>::type cxpGetCxpOffSize000() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpOffSize(0,1) == 6, bool>::type cxpGetCxpOffSize001() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpOffSize(0,2) == 5, bool>::type cxpGetCxpOffSize002() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpOffSize(1,0) == 6, bool>::type cxpGetCxpOffSize010() { return true; }

/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpOff(0,0), "1220"), bool>::type cxpGetCxpOff000(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpOff(0,1), "-1208"), bool>::type cxpGetCxpOff001(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpOff(0,2), "1221"), bool>::type cxpGetCxpOff002(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpOff(1,0), "-1208"), bool>::type cxpGetCxpOff010(void) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=off
TEST_F(TestS2combs, CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpOffSize0<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize1<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize2<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize00<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize01<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize20<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize000<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize001<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize002<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize010<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpOff000<void>());
	EXPECT_EQ(true, cxpGetCxpOff001<void>());
	EXPECT_EQ(true, cxpGetCxpOff002<void>());
	EXPECT_EQ(true, cxpGetCxpOff010<void>());

	// getValue() at runtime
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getCxpOffSize());
	EXPECT_EQ(3, value.getCxpOffSize(0));
	EXPECT_EQ(1, value.getCxpOffSize(1));
	try { success = false; value.getCxpOffSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1220", value.getCxpOff(0, 0));
	EXPECT_EQ(5, value.getCxpOffSize(0, 0));
	EXPECT_STREQ("-1208", value.getCxpOff(0, 1));
	EXPECT_EQ(6, value.getCxpOffSize(0, 1));
	EXPECT_STREQ("1221", value.getCxpOff(0, 2));
	EXPECT_EQ(5, value.getCxpOffSize(0, 2));
	try { success = false; value.getCxpOff(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOffSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1208", value.getCxpOff(1, 0));
	EXPECT_EQ(6, value.getCxpOffSize(1, 0));
	try { success = false; value.getCxpOff(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOffSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getCxpOff(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOffSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getCxpOffSize());
	try { success = false; value.getCxpOffSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOff(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOffSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getCxpOffSize());
	EXPECT_EQ(0, value.getCxpOffSize(0));
	try { success = false; value.getCxpOffSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOff(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOffSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S2combs::_fromCxpOff("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S2combs::_fromCxpOff("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpExtSize() == 2, bool>::type cxpGetCxpExtSize0() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V1.getCxpExtSize() == 0, bool>::type cxpGetCxpExtSize1() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getCxpExtSize() == 1, bool>::type cxpGetCxpExtSize2() { return true; }

/// Function that only compiles if the constexpr getCxpExtSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpExtSize(0) == 3, bool>::type cxpGetCxpExtSize00() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpExtSize(1) == 1, bool>::type cxpGetCxpExtSize01() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getCxpExtSize(0) == 0, bool>::type cxpGetCxpExtSize20() { return true; }

/// Function that only compiles if the constexpr getCxpExtSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpExtSize(0,0) == 5, bool>::type cxpGetCxpExtSize000() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpExtSize(0,1) == 6, bool>::type cxpGetCxpExtSize001() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpExtSize(0,2) == 5, bool>::type cxpGetCxpExtSize002() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpExtSize(1,0) == 6, bool>::type cxpGetCxpExtSize010() { return true; }

/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpExt(0,0), "1222"), bool>::type cxpGetCxpExt000(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpExt(0,1), "-1209"), bool>::type cxpGetCxpExt001(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpExt(0,2), "1223"), bool>::type cxpGetCxpExt002(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpExt(1,0), "-1209"), bool>::type cxpGetCxpExt010(void) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=ext
TEST_F(TestS2combs, CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpExtSize0<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize1<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize2<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize00<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize01<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize20<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize000<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize001<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize002<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize010<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpExt000<void>());
	EXPECT_EQ(true, cxpGetCxpExt001<void>());
	EXPECT_EQ(true, cxpGetCxpExt002<void>());
	EXPECT_EQ(true, cxpGetCxpExt010<void>());

	// getValue() at runtime
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getCxpExtSize());
	EXPECT_EQ(3, value.getCxpExtSize(0));
	EXPECT_EQ(1, value.getCxpExtSize(1));
	try { success = false; value.getCxpExtSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1222", value.getCxpExt(0, 0));
	EXPECT_EQ(5, value.getCxpExtSize(0, 0));
	EXPECT_STREQ("-1209", value.getCxpExt(0, 1));
	EXPECT_EQ(6, value.getCxpExtSize(0, 1));
	EXPECT_STREQ("1223", value.getCxpExt(0, 2));
	EXPECT_EQ(5, value.getCxpExtSize(0, 2));
	try { success = false; value.getCxpExt(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExtSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1209", value.getCxpExt(1, 0));
	EXPECT_EQ(6, value.getCxpExtSize(1, 0));
	try { success = false; value.getCxpExt(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExtSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getCxpExt(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExtSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getCxpExtSize());
	try { success = false; value.getCxpExtSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExt(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExtSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getCxpExtSize());
	EXPECT_EQ(0, value.getCxpExtSize(0));
	try { success = false; value.getCxpExtSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExt(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExtSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	strval = "1222";
	EXPECT_EQ(true, xenums::S2combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromCxpExt(strval));
	strval = "1223";
	EXPECT_EQ(true, xenums::S2combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromCxpExt(strval));
	// Not unique, but both are in V0.
	strval = "-1209";
	EXPECT_EQ(true, xenums::S2combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromCxpExt(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromCxpExt(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromCxpExt(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpInlSize() == 2, bool>::type cxpGetCxpInlSize0() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V1.getCxpInlSize() == 0, bool>::type cxpGetCxpInlSize1() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getCxpInlSize() == 1, bool>::type cxpGetCxpInlSize2() { return true; }

/// Function that only compiles if the constexpr getCxpInlSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpInlSize(0) == 3, bool>::type cxpGetCxpInlSize00() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpInlSize(1) == 1, bool>::type cxpGetCxpInlSize01() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getCxpInlSize(0) == 0, bool>::type cxpGetCxpInlSize20() { return true; }

/// Function that only compiles if the constexpr getCxpInlSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpInlSize(0,0) == 5, bool>::type cxpGetCxpInlSize000() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpInlSize(0,1) == 6, bool>::type cxpGetCxpInlSize001() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpInlSize(0,2) == 5, bool>::type cxpGetCxpInlSize002() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpInlSize(1,0) == 6, bool>::type cxpGetCxpInlSize010() { return true; }

/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpInl(0,0), "1224"), bool>::type cxpGetCxpInl000(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpInl(0,1), "-1210"), bool>::type cxpGetCxpInl001(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpInl(0,2), "1225"), bool>::type cxpGetCxpInl002(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpInl(1,0), "-1210"), bool>::type cxpGetCxpInl010(void) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=inl
TEST_F(TestS2combs, CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpInlSize0<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize1<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize2<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize00<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize01<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize20<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize000<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize001<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize002<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize010<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpInl000<void>());
	EXPECT_EQ(true, cxpGetCxpInl001<void>());
	EXPECT_EQ(true, cxpGetCxpInl002<void>());
	EXPECT_EQ(true, cxpGetCxpInl010<void>());

	// getValue() at runtime
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getCxpInlSize());
	EXPECT_EQ(3, value.getCxpInlSize(0));
	EXPECT_EQ(1, value.getCxpInlSize(1));
	try { success = false; value.getCxpInlSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1224", value.getCxpInl(0, 0));
	EXPECT_EQ(5, value.getCxpInlSize(0, 0));
	EXPECT_STREQ("-1210", value.getCxpInl(0, 1));
	EXPECT_EQ(6, value.getCxpInlSize(0, 1));
	EXPECT_STREQ("1225", value.getCxpInl(0, 2));
	EXPECT_EQ(5, value.getCxpInlSize(0, 2));
	try { success = false; value.getCxpInl(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInlSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1210", value.getCxpInl(1, 0));
	EXPECT_EQ(6, value.getCxpInlSize(1, 0));
	try { success = false; value.getCxpInl(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInlSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getCxpInl(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInlSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getCxpInlSize());
	try { success = false; value.getCxpInlSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInl(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInlSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getCxpInlSize());
	EXPECT_EQ(0, value.getCxpInlSize(0));
	try { success = false; value.getCxpInlSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInl(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInlSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	strval = "1224";
	EXPECT_EQ(true, xenums::S2combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromCxpInl(strval));
	strval = "1225";
	EXPECT_EQ(true, xenums::S2combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromCxpInl(strval));
	// Not unique, but both are in V0.
	strval = "-1210";
	EXPECT_EQ(true, xenums::S2combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromCxpInl(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromCxpInl(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromCxpInl(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpCxpSize() == 2, bool>::type cxpGetCxpCxpSize0() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V1.getCxpCxpSize() == 0, bool>::type cxpGetCxpCxpSize1() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getCxpCxpSize() == 1, bool>::type cxpGetCxpCxpSize2() { return true; }

/// Function that only compiles if the constexpr getCxpCxpSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpCxpSize(0) == 3, bool>::type cxpGetCxpCxpSize00() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpCxpSize(1) == 1, bool>::type cxpGetCxpCxpSize01() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getCxpCxpSize(0) == 0, bool>::type cxpGetCxpCxpSize20() { return true; }

/// Function that only compiles if the constexpr getCxpCxpSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpCxpSize(0,0) == 5, bool>::type cxpGetCxpCxpSize000() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpCxpSize(0,1) == 6, bool>::type cxpGetCxpCxpSize001() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpCxpSize(0,2) == 5, bool>::type cxpGetCxpCxpSize002() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getCxpCxpSize(1,0) == 6, bool>::type cxpGetCxpCxpSize010() { return true; }

/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpCxp(0,0), "1226"), bool>::type cxpGetCxpCxp000(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpCxp(0,1), "-1211"), bool>::type cxpGetCxpCxp001(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpCxp(0,2), "1227"), bool>::type cxpGetCxpCxp002(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getCxpCxp(1,0), "-1211"), bool>::type cxpGetCxpCxp010(void) { return true; }

/// Values for testing cxpFromCxpCxp()
constexpr char CxpCxpv0[] = "1226";
constexpr char CxpCxpv1[] = "-1211";
constexpr char CxpCxpv2[] = "1227";
constexpr char CxpCxpv3[] = "1225";
constexpr char CxpCxpv4[] = "1228";
constexpr char CxpCxpv5[] = "42";
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromCxpCxp(CxpCxpv0) == xenums::S2combs::V0, bool>::type cxpFromCxpCxp0(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromCxpCxp(CxpCxpv1) == xenums::S2combs::V0, bool>::type cxpFromCxpCxp1(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromCxpCxp(CxpCxpv2) == xenums::S2combs::V0, bool>::type cxpFromCxpCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromCxpCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromCxpCxp(V) returns with success, and returns true if so; for testing that cxpFromCxpCxp() fails correctly at compile time.
template<const char* V> bool cxpFromCxpCxp3(typename std::enable_if<xenums::S2combs::_cxpFromCxpCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=cxp
TEST_F(TestS2combs, CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpCxpSize0<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize1<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize2<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize00<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize01<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize20<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize000<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize001<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize002<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize010<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpCxp000<void>());
	EXPECT_EQ(true, cxpGetCxpCxp001<void>());
	EXPECT_EQ(true, cxpGetCxpCxp002<void>());
	EXPECT_EQ(true, cxpGetCxpCxp010<void>());

	// getValue() at runtime
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getCxpCxpSize());
	EXPECT_EQ(3, value.getCxpCxpSize(0));
	EXPECT_EQ(1, value.getCxpCxpSize(1));
	try { success = false; value.getCxpCxpSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1226", value.getCxpCxp(0, 0));
	EXPECT_EQ(5, value.getCxpCxpSize(0, 0));
	EXPECT_STREQ("-1211", value.getCxpCxp(0, 1));
	EXPECT_EQ(6, value.getCxpCxpSize(0, 1));
	EXPECT_STREQ("1227", value.getCxpCxp(0, 2));
	EXPECT_EQ(5, value.getCxpCxpSize(0, 2));
	try { success = false; value.getCxpCxp(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxpSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1211", value.getCxpCxp(1, 0));
	EXPECT_EQ(6, value.getCxpCxpSize(1, 0));
	try { success = false; value.getCxpCxp(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxpSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getCxpCxp(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxpSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getCxpCxpSize());
	try { success = false; value.getCxpCxpSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxp(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxpSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getCxpCxpSize());
	EXPECT_EQ(0, value.getCxpCxpSize(0));
	try { success = false; value.getCxpCxpSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxp(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxpSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

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

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::S2combs::V0, xenums::S2combs::_cxpFromCxpCxp("1226"));
	// Not unique, but both are in V0.
	EXPECT_EQ(xenums::S2combs::V0, xenums::S2combs::_cxpFromCxpCxp("-1211"));
	EXPECT_EQ(xenums::S2combs::V0, xenums::S2combs::_cxpFromCxpCxp("1227"));
	try { success = false; xenums::S2combs::_cxpFromCxpCxp("42"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	strval = "1226";
	EXPECT_EQ(true, xenums::S2combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromCxpCxp(strval));
	strval = "1227";
	EXPECT_EQ(true, xenums::S2combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromCxpCxp(strval));
	// Not unique, but both are in V0.
	strval = "-1211";
	EXPECT_EQ(true, xenums::S2combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromCxpCxp(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromCxpCxp(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromCxpCxp(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
