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

#include <test/xenum/xenums/P2combs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenums with combinations of custom property options.
 */
class TestP2combs : public ::testing::Test {
public:
	bool success;
	xenums::P2comb value;
	int intval;
};


/// Test custom properties P0* of P2combs xenum.
TEST_F(TestP2combs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_P2combs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::P2combs::_size);
}



// ========================================= get=off ============================================

/// Test xenum with identifier features: getValue=off, fromValue=off
TEST_F(TestP2combs, OffOff)
{
	// getValue=off
	try { success = false; xenums::P2combs::V0.getOffOff(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P2combs::_fromOffOff(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P2combs::_fromOffOff(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=ext
TEST_F(TestP2combs, OffExt)
{
	// getValue=off
	try { success = false; xenums::P2combs::V0.getOffExt(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffExt() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1202;
	EXPECT_EQ(true, xenums::P2combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromOffExt(intval));
	intval = 1203;
	EXPECT_EQ(true, xenums::P2combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromOffExt(intval));
	// Not unique, but both are in V0
	intval = -1201;
	EXPECT_EQ(true, xenums::P2combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromOffExt(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromOffExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	intval = 0;
	EXPECT_EQ(false, xenums::P2combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromOffExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=inl
TEST_F(TestP2combs, OffInl)
{
	// getValue=off
	try { success = false; xenums::P2combs::V0.getOffInl(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffInl() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1204;
	EXPECT_EQ(true, xenums::P2combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromOffInl(intval));
	intval = 1205;
	EXPECT_EQ(true, xenums::P2combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromOffInl(intval));
	// Not unique, but both are in V0
	intval = -1202;
	EXPECT_EQ(true, xenums::P2combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromOffInl(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromOffInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	intval = 0;
	EXPECT_EQ(false, xenums::P2combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromOffInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromOffCxp(1206) == xenums::P2combs::V0, bool>::type cxpFromOffCxp0(void) { return true; }
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromOffCxp(1207) == xenums::P2combs::V0, bool>::type cxpFromOffCxp1(void) { return true; }
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromOffCxp(-1203) == xenums::P2combs::V0, bool>::type cxpFromOffCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromOffCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromOffCxp(V) returns with success, and returns true if so; for testing that cxpFromOffCxp() fails correctly at compile time.
template<int V> bool cxpFromOffCxp3(typename std::enable_if<xenums::P2combs::_cxpFromOffCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=off, fromValue=cxp
TEST_F(TestP2combs, OffCxp)
{
	// getValue=off
	try { success = false; xenums::P2combs::V0.getOffCxp(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffCxp() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromOffCxp0<void>());
	EXPECT_EQ(true, cxpFromOffCxp1<void>());
	EXPECT_EQ(true, cxpFromOffCxp2<void>());
	EXPECT_EQ(false, cxpFromOffCxp3<1205>(0));
	EXPECT_EQ(true, cxpFromOffCxp3<1206>(0));
	EXPECT_EQ(true, cxpFromOffCxp3<1207>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<1208>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<42>(0));
	EXPECT_EQ(false, cxpFromOffCxp3<0>(0));

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::P2combs::V0, xenums::P2combs::_cxpFromOffCxp(1206));
	// Not unique, but both are in V0
	EXPECT_EQ(xenums::P2combs::V0, xenums::P2combs::_cxpFromOffCxp(-1203));
	EXPECT_EQ(xenums::P2combs::V0, xenums::P2combs::_cxpFromOffCxp(1207));
	try { success = false; xenums::P2combs::_cxpFromOffCxp(42); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P2combs::_cxpFromOffCxp(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1206;
	EXPECT_EQ(true, xenums::P2combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromOffCxp(intval));
	intval = 1207;
	EXPECT_EQ(true, xenums::P2combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromOffCxp(intval));
	// Not unique, but both are in V0
	intval = -1203;
	EXPECT_EQ(true, xenums::P2combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromOffCxp(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromOffCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	intval = 0;
	EXPECT_EQ(false, xenums::P2combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromOffCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=ext ============================================

/// Test xenum with identifier features: getValue=ext, fromValue=off
TEST_F(TestP2combs, ExtOff)
{
	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getExtOffSize());
	EXPECT_EQ(3, value.getExtOffSize(0));
	EXPECT_EQ(1, value.getExtOffSize(1));
	try { success = false; value.getExtOffSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1210, value.getExtOff(0, 0));
	EXPECT_EQ(-1204, value.getExtOff(0, 1));
	EXPECT_EQ(1211, value.getExtOff(0, 2));
	try { success = false; value.getExtOff(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1204, value.getExtOff(1, 0));
	try { success = false; value.getExtOff(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getExtOff(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getExtOffSize());
	try { success = false; value.getExtOffSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOff(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getExtOffSize());
	EXPECT_EQ(0, value.getExtOffSize(0));
	try { success = false; value.getExtOffSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtOff(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P2combs::_fromExtOff(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P2combs::_fromExtOff(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=ext
TEST_F(TestP2combs, ExtExt)
{
	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getExtExtSize());
	EXPECT_EQ(3, value.getExtExtSize(0));
	EXPECT_EQ(1, value.getExtExtSize(1));
	try { success = false; value.getExtExtSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1212, value.getExtExt(0, 0));
	EXPECT_EQ(-1205, value.getExtExt(0, 1));
	EXPECT_EQ(1213, value.getExtExt(0, 2));
	try { success = false; value.getExtExt(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1205, value.getExtExt(1, 0));
	try { success = false; value.getExtExt(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getExtExt(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getExtExtSize());
	try { success = false; value.getExtExtSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExt(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getExtExtSize());
	EXPECT_EQ(0, value.getExtExtSize(0));
	try { success = false; value.getExtExtSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtExt(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1212;
	EXPECT_EQ(true, xenums::P2combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromExtExt(intval));
	intval = 1213;
	EXPECT_EQ(true, xenums::P2combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromExtExt(intval));
	// Not unique, but both are in V0
	intval = -1205;
	EXPECT_EQ(true, xenums::P2combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromExtExt(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromExtExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	intval = 0;
	EXPECT_EQ(false, xenums::P2combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromExtExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=inl
TEST_F(TestP2combs, ExtInl)
{
	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getExtInlSize());
	EXPECT_EQ(3, value.getExtInlSize(0));
	EXPECT_EQ(1, value.getExtInlSize(1));
	try { success = false; value.getExtInlSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1214, value.getExtInl(0, 0));
	EXPECT_EQ(-1206, value.getExtInl(0, 1));
	EXPECT_EQ(1215, value.getExtInl(0, 2));
	try { success = false; value.getExtInl(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1206, value.getExtInl(1, 0));
	try { success = false; value.getExtInl(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getExtInl(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getExtInlSize());
	try { success = false; value.getExtInlSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInl(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getExtInlSize());
	EXPECT_EQ(0, value.getExtInlSize(0));
	try { success = false; value.getExtInlSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtInl(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1214;
	EXPECT_EQ(true, xenums::P2combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromExtInl(intval));
	intval = 1215;
	EXPECT_EQ(true, xenums::P2combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromExtInl(intval));
	// Not unique, but both are in V0
	intval = -1206;
	EXPECT_EQ(true, xenums::P2combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromExtInl(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromExtInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	intval = 0;
	EXPECT_EQ(false, xenums::P2combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromExtInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromExtCxp(1216) == xenums::P2combs::V0, bool>::type cxpFromExtCxp0(void) { return true; }
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromExtCxp(1217) == xenums::P2combs::V0, bool>::type cxpFromExtCxp1(void) { return true; }
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromExtCxp(-1207) == xenums::P2combs::V0, bool>::type cxpFromExtCxp2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromExtCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromExtCxp(V) returns with success, and returns true if so; for testing that cxpFromExtCxp() fails correctly at compile time.
template<int V> bool cxpFromExtCxp3(typename std::enable_if<xenums::P2combs::_cxpFromExtCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=ext, fromValue=cxp
TEST_F(TestP2combs, ExtCxp)
{
	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getExtCxpSize());
	EXPECT_EQ(3, value.getExtCxpSize(0));
	EXPECT_EQ(1, value.getExtCxpSize(1));
	try { success = false; value.getExtCxpSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1216, value.getExtCxp(0, 0));
	EXPECT_EQ(-1207, value.getExtCxp(0, 1));
	EXPECT_EQ(1217, value.getExtCxp(0, 2));
	try { success = false; value.getExtCxp(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1207, value.getExtCxp(1, 0));
	try { success = false; value.getExtCxp(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getExtCxp(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getExtCxpSize());
	try { success = false; value.getExtCxpSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxp(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getExtCxpSize());
	EXPECT_EQ(0, value.getExtCxpSize(0));
	try { success = false; value.getExtCxpSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getExtCxp(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromExtCxp0<void>());
	EXPECT_EQ(true, cxpFromExtCxp1<void>());
	EXPECT_EQ(true, cxpFromExtCxp2<void>());
	EXPECT_EQ(false, cxpFromExtCxp3<1215>(0));
	EXPECT_EQ(true, cxpFromExtCxp3<1216>(0));
	EXPECT_EQ(true, cxpFromExtCxp3<1217>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<1218>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<42>(0));
	EXPECT_EQ(false, cxpFromExtCxp3<0>(0));

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::P2combs::V0, xenums::P2combs::_cxpFromExtCxp(1216));
	// Not unique, but both are in V0
	EXPECT_EQ(xenums::P2combs::V0, xenums::P2combs::_cxpFromExtCxp(-1207));
	EXPECT_EQ(xenums::P2combs::V0, xenums::P2combs::_cxpFromExtCxp(1217));
	try { success = false; xenums::P2combs::_cxpFromExtCxp(42); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P2combs::_cxpFromExtCxp(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1216;
	EXPECT_EQ(true, xenums::P2combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromExtCxp(intval));
	intval = 1217;
	EXPECT_EQ(true, xenums::P2combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromExtCxp(intval));
	// Not unique, but both are in V0
	intval = -1207;
	EXPECT_EQ(true, xenums::P2combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromExtCxp(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromExtCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	intval = 0;
	EXPECT_EQ(false, xenums::P2combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromExtCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=cxp ============================================

/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpOffSize() == 2, bool>::type cxpGetCxpOffSize0() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V1.getCxpOffSize() == 0, bool>::type cxpGetCxpOffSize1() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getCxpOffSize() == 1, bool>::type cxpGetCxpOffSize2() { return true; }

/// Function that only compiles if the constexpr getCxpOffSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpOffSize(0) == 3, bool>::type cxpGetCxpOffSize00() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpOffSize(1) == 1, bool>::type cxpGetCxpOffSize01() { return true; }
/// Function that only compiles if the constexpr getCxpOffSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getCxpOffSize(0) == 0, bool>::type cxpGetCxpOffSize20() { return true; }

/// Function that only compiles if the constexpr getCxpOff(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpOff(0,0) == 1220, bool>::type cxpGetCxpOff000(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpOff(0,1) == -1208, bool>::type cxpGetCxpOff001(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpOff(0,2) == 1221, bool>::type cxpGetCxpOff002(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpOff(1,0) == -1208, bool>::type cxpGetCxpOff010(void) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=off
TEST_F(TestP2combs, CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpOffSize0<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize1<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize2<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize00<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize01<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpOff000<void>());
	EXPECT_EQ(true, cxpGetCxpOff001<void>());
	EXPECT_EQ(true, cxpGetCxpOff002<void>());
	EXPECT_EQ(true, cxpGetCxpOff010<void>());

	// getValue() at runtime
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getCxpOffSize());
	EXPECT_EQ(3, value.getCxpOffSize(0));
	EXPECT_EQ(1, value.getCxpOffSize(1));
	try { success = false; value.getCxpOffSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1220, value.getCxpOff(0, 0));
	EXPECT_EQ(-1208, value.getCxpOff(0, 1));
	EXPECT_EQ(1221, value.getCxpOff(0, 2));
	try { success = false; value.getCxpOff(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1208, value.getCxpOff(1, 0));
	try { success = false; value.getCxpOff(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getCxpOff(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getCxpOffSize());
	try { success = false; value.getCxpOffSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOff(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getCxpOffSize());
	EXPECT_EQ(0, value.getCxpOffSize(0));
	try { success = false; value.getCxpOffSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpOff(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P2combs::_fromCxpOff(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P2combs::_fromCxpOff(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpExtSize() == 2, bool>::type cxpGetCxpExtSize0() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V1.getCxpExtSize() == 0, bool>::type cxpGetCxpExtSize1() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getCxpExtSize() == 1, bool>::type cxpGetCxpExtSize2() { return true; }

/// Function that only compiles if the constexpr getCxpExtSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpExtSize(0) == 3, bool>::type cxpGetCxpExtSize00() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpExtSize(1) == 1, bool>::type cxpGetCxpExtSize01() { return true; }
/// Function that only compiles if the constexpr getCxpExtSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getCxpExtSize(0) == 0, bool>::type cxpGetCxpExtSize20() { return true; }

/// Function that only compiles if the constexpr getCxpExt(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpExt(0,0) == 1222, bool>::type cxpGetCxpExt000(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpExt(0,1) == -1209, bool>::type cxpGetCxpExt001(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpExt(0,2) == 1223, bool>::type cxpGetCxpExt002(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpExt(1,0) == -1209, bool>::type cxpGetCxpExt010(void) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=ext
TEST_F(TestP2combs, CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpExtSize0<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize1<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize2<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize00<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize01<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpExt000<void>());
	EXPECT_EQ(true, cxpGetCxpExt001<void>());
	EXPECT_EQ(true, cxpGetCxpExt002<void>());
	EXPECT_EQ(true, cxpGetCxpExt010<void>());

	// getValue() at runtime
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getCxpExtSize());
	EXPECT_EQ(3, value.getCxpExtSize(0));
	EXPECT_EQ(1, value.getCxpExtSize(1));
	try { success = false; value.getCxpExtSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1222, value.getCxpExt(0, 0));
	EXPECT_EQ(-1209, value.getCxpExt(0, 1));
	EXPECT_EQ(1223, value.getCxpExt(0, 2));
	try { success = false; value.getCxpExt(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1209, value.getCxpExt(1, 0));
	try { success = false; value.getCxpExt(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getCxpExt(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getCxpExtSize());
	try { success = false; value.getCxpExtSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExt(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getCxpExtSize());
	EXPECT_EQ(0, value.getCxpExtSize(0));
	try { success = false; value.getCxpExtSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpExt(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1222;
	EXPECT_EQ(true, xenums::P2combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromCxpExt(intval));
	intval = 1223;
	EXPECT_EQ(true, xenums::P2combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromCxpExt(intval));
	// Not unique, but both are in V0
	intval = -1209;
	EXPECT_EQ(true, xenums::P2combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromCxpExt(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromCxpExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	intval = 0;
	EXPECT_EQ(false, xenums::P2combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromCxpExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpInlSize() == 2, bool>::type cxpGetCxpInlSize0() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V1.getCxpInlSize() == 0, bool>::type cxpGetCxpInlSize1() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getCxpInlSize() == 1, bool>::type cxpGetCxpInlSize2() { return true; }

/// Function that only compiles if the constexpr getCxpInlSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpInlSize(0) == 3, bool>::type cxpGetCxpInlSize00() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpInlSize(1) == 1, bool>::type cxpGetCxpInlSize01() { return true; }
/// Function that only compiles if the constexpr getCxpInlSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getCxpInlSize(0) == 0, bool>::type cxpGetCxpInlSize20() { return true; }

/// Function that only compiles if the constexpr getCxpInl(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpInl(0,0) == 1224, bool>::type cxpGetCxpInl000(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpInl(0,1) == -1210, bool>::type cxpGetCxpInl001(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpInl(0,2) == 1225, bool>::type cxpGetCxpInl002(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpInl(1,0) == -1210, bool>::type cxpGetCxpInl010(void) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=inl
TEST_F(TestP2combs, CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpInlSize0<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize1<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize2<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize00<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize01<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpInl000<void>());
	EXPECT_EQ(true, cxpGetCxpInl001<void>());
	EXPECT_EQ(true, cxpGetCxpInl002<void>());
	EXPECT_EQ(true, cxpGetCxpInl010<void>());

	// getValue() at runtime
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getCxpInlSize());
	EXPECT_EQ(3, value.getCxpInlSize(0));
	EXPECT_EQ(1, value.getCxpInlSize(1));
	try { success = false; value.getCxpInlSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1224, value.getCxpInl(0, 0));
	EXPECT_EQ(-1210, value.getCxpInl(0, 1));
	EXPECT_EQ(1225, value.getCxpInl(0, 2));
	try { success = false; value.getCxpInl(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1210, value.getCxpInl(1, 0));
	try { success = false; value.getCxpInl(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getCxpInl(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getCxpInlSize());
	try { success = false; value.getCxpInlSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInl(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getCxpInlSize());
	EXPECT_EQ(0, value.getCxpInlSize(0));
	try { success = false; value.getCxpInlSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpInl(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1224;
	EXPECT_EQ(true, xenums::P2combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromCxpInl(intval));
	intval = 1225;
	EXPECT_EQ(true, xenums::P2combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromCxpInl(intval));
	// Not unique, but both are in V0
	intval = -1210;
	EXPECT_EQ(true, xenums::P2combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromCxpInl(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromCxpInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	intval = 0;
	EXPECT_EQ(false, xenums::P2combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromCxpInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpCxpSize() == 2, bool>::type cxpGetCxpCxpSize0() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V1.getCxpCxpSize() == 0, bool>::type cxpGetCxpCxpSize1() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getCxpCxpSize() == 1, bool>::type cxpGetCxpCxpSize2() { return true; }

/// Function that only compiles if the constexpr getCxpCxpSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpCxpSize(0) == 3, bool>::type cxpGetCxpCxpSize00() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpCxpSize(1) == 1, bool>::type cxpGetCxpCxpSize01() { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getCxpCxpSize(0) == 0, bool>::type cxpGetCxpCxpSize20() { return true; }

/// Function that only compiles if the constexpr getCxpCxp(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpCxp(0,0) == 1226, bool>::type cxpGetCxpCxp000(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpCxp(0,1) == -1211, bool>::type cxpGetCxpCxp001(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpCxp(0,2) == 1227, bool>::type cxpGetCxpCxp002(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getCxpCxp(1,0) == -1211, bool>::type cxpGetCxpCxp010(void) { return true; }

/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromCxpCxp(1226) == xenums::P2combs::V0, bool>::type cxpFromCxpCxp0(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromCxpCxp(1227) == xenums::P2combs::V0, bool>::type cxpFromCxpCxp1(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromCxpCxp(-1211) == xenums::P2combs::V0, bool>::type cxpFromCxpCxp2(void) { return true; }

/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromCxpCxp3(unsigned v) { return false; }
/// Function that only exists if cxpFromCxpCxp(V) returns with success, and returns true if so; for testing that cxpFromCxpCxp() fails correctly at compile time.
template<int V> bool cxpFromCxpCxp3(typename std::enable_if<xenums::P2combs::_cxpFromCxpCxp(V).toTrue(), int>::type) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=cxp
TEST_F(TestP2combs, CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpCxpSize0<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize1<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize2<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize00<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize01<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpCxp000<void>());
	EXPECT_EQ(true, cxpGetCxpCxp001<void>());
	EXPECT_EQ(true, cxpGetCxpCxp002<void>());
	EXPECT_EQ(true, cxpGetCxpCxp010<void>());

	// getValue() at runtime
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getCxpCxpSize());
	EXPECT_EQ(3, value.getCxpCxpSize(0));
	EXPECT_EQ(1, value.getCxpCxpSize(1));
	try { success = false; value.getCxpCxpSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1226, value.getCxpCxp(0, 0));
	EXPECT_EQ(-1211, value.getCxpCxp(0, 1));
	EXPECT_EQ(1227, value.getCxpCxp(0, 2));
	try { success = false; value.getCxpCxp(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1211, value.getCxpCxp(1, 0));
	try { success = false; value.getCxpCxp(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getCxpCxp(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getCxpCxpSize());
	try { success = false; value.getCxpCxpSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxp(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getCxpCxpSize());
	EXPECT_EQ(0, value.getCxpCxpSize(0));
	try { success = false; value.getCxpCxpSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getCxpCxp(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromCxpCxp0<void>());
	EXPECT_EQ(true, cxpFromCxpCxp1<void>());
	EXPECT_EQ(true, cxpFromCxpCxp2<void>());
	EXPECT_EQ(false, cxpFromCxpCxp3<1225>(0));
	EXPECT_EQ(true, cxpFromCxpCxp3<1226>(0));
	EXPECT_EQ(true, cxpFromCxpCxp3<1227>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<1228>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<42>(0));
	EXPECT_EQ(false, cxpFromCxpCxp3<0>(0));

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::P2combs::V0, xenums::P2combs::_cxpFromCxpCxp(1226));
	// Not unique, but both are in V0
	EXPECT_EQ(xenums::P2combs::V0, xenums::P2combs::_cxpFromCxpCxp(-1211));
	EXPECT_EQ(xenums::P2combs::V0, xenums::P2combs::_cxpFromCxpCxp(1227));
	try { success = false; xenums::P2combs::_cxpFromCxpCxp(42); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P2combs::_cxpFromCxpCxp(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1226;
	EXPECT_EQ(true, xenums::P2combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromCxpCxp(intval));
	intval = 1227;
	EXPECT_EQ(true, xenums::P2combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromCxpCxp(intval));
	// Not unique, but both are in V0
	intval = -1211;
	EXPECT_EQ(true, xenums::P2combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromCxpCxp(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromCxpCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	intval = 0;
	EXPECT_EQ(false, xenums::P2combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromCxpCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
