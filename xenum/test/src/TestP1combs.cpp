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
	// getValue=off
	try { success = false; xenums::P1combs::V0.getOffOff(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P1combs::_fromOffOff(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P1combs::_fromOffOff(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromOffOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=ext
TEST_F(TestP1combs, OffExt)
{
	// getValue=off
	try { success = false; xenums::P1combs::V0.getOffExt(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffExt() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1102;
	EXPECT_EQ(true, xenums::P1combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromOffExt(intval));
	// Not unique
	//intval = -1101;
	//EXPECT_EQ(true, xenums::P1combs::_fromOffExt(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromOffExt(intval));
	intval = 1103;
	EXPECT_EQ(true, xenums::P1combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromOffExt(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromOffExt(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromOffExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=inl
TEST_F(TestP1combs, OffInl)
{
	// getValue()=off
	try { success = false; xenums::P1combs::V0.getOffInl(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffInl() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1104;
	EXPECT_EQ(true, xenums::P1combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromOffInl(intval));
	// Not unique
	//intval = -1102;
	//EXPECT_EQ(true, xenums::P1combs::_fromOffInl(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromOffInl(intval));
	intval = 1105;
	EXPECT_EQ(true, xenums::P1combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromOffInl(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromOffInl(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromOffInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromOffCxp(1106) == xenums::P1combs::V0, bool>::type cxpFromOffCxp0(void) { return true; }
/// Function that only compiles if cxpFromOffCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromOffCxp(1107) == xenums::P1combs::V0, bool>::type cxpFromOffCxp1(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromOffCxp2(unsigned v) { return false; }
/// Function that only exists if cxpFromOffCxp(V) returns with success, and returns true if so; for testing that cxpFromOffCxp() fails correctly at compile time.
template<int V> bool cxpFromOffCxp2(typename std::enable_if<xenums::P1combs::_cxpFromOffCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=off, fromValue=cxp
TEST_F(TestP1combs, OffCxp)
{
	// getValue()=off
	try { success = false; xenums::P1combs::V0.getOffCxp(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getOffCxp() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromOffCxp0<void>());
	EXPECT_EQ(true, cxpFromOffCxp1<void>());
	EXPECT_EQ(false, cxpFromOffCxp2<1105>(0));
	EXPECT_EQ(true, cxpFromOffCxp2<1106>(0));
	EXPECT_EQ(true, cxpFromOffCxp2<1107>(0));
	EXPECT_EQ(false, cxpFromOffCxp2<1108>(0));
	EXPECT_EQ(false, cxpFromOffCxp2<42>(0));

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::P1combs::V0, xenums::P1combs::_cxpFromOffCxp(1106));
	// Not unique
	//EXPECT_EQ(xenums::P1combs::V0|V2, xenums::P1combs::_cxpFromOffCxp(-1103));
	EXPECT_EQ(xenums::P1combs::V0, xenums::P1combs::_cxpFromOffCxp(1107));
	try { success = false; xenums::P1combs::_cxpFromOffCxp(42); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1106;
	EXPECT_EQ(true, xenums::P1combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromOffCxp(intval));
	// Not unique
	//intval = -1103;
	//EXPECT_EQ(true, xenums::P1combs::_fromOffCxp(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromOffCxp(intval));
	intval = 1107;
	EXPECT_EQ(true, xenums::P1combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromOffCxp(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromOffCxp(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromOffCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'OffCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=ext ============================================

/// Test xenum with identifier features: getValue=ext, fromValue=off
TEST_F(TestP1combs, ExtOff)
{
	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getExtOffSize());
	EXPECT_EQ(1110, value.getExtOff(0));
	EXPECT_EQ(-1104, value.getExtOff(1));
	EXPECT_EQ(1111, value.getExtOff(2));
	try { success = false; value.getExtOff(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getExtOffSize());
	try { success = false; value.getExtOff(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getExtOffSize());
	EXPECT_EQ(-1104, value.getExtOff(0));
	try { success = false; value.getExtOff(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P1combs::_fromExtOff(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P1combs::_fromExtOff(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromExtOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=ext
TEST_F(TestP1combs, ExtExt)
{
	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getExtExtSize());
	EXPECT_EQ(1112, value.getExtExt(0));
	EXPECT_EQ(-1105, value.getExtExt(1));
	EXPECT_EQ(1113, value.getExtExt(2));
	try { success = false; value.getExtExt(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getExtExtSize());
	try { success = false; value.getExtExt(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getExtExtSize());
	EXPECT_EQ(-1105, value.getExtExt(0));
	try { success = false; value.getExtExt(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1112;
	EXPECT_EQ(true, xenums::P1combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromExtExt(intval));
	// Not unique
	//intval = -1105;
	//EXPECT_EQ(true, xenums::P1combs::_fromExtExt(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromExtExt(intval));
	intval = 1113;
	EXPECT_EQ(true, xenums::P1combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromExtExt(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromExtExt(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromExtExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=inl
TEST_F(TestP1combs, ExtInl)
{
	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getExtInlSize());
	EXPECT_EQ(1114, value.getExtInl(0));
	EXPECT_EQ(-1106, value.getExtInl(1));
	EXPECT_EQ(1115, value.getExtInl(2));
	try { success = false; value.getExtInl(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getExtInlSize());
	try { success = false; value.getExtInl(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getExtInlSize());
	EXPECT_EQ(-1106, value.getExtInl(0));
	try { success = false; value.getExtInl(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1114;
	EXPECT_EQ(true, xenums::P1combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromExtInl(intval));
	// Not unique
	//intval = -1106;
	//EXPECT_EQ(true, xenums::P1combs::_fromExtInl(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V1);
	//EXPECT_EQ(value, xenums::P1combs::_fromExtInl(intval));
	intval = 1115;
	EXPECT_EQ(true, xenums::P1combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromExtInl(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromExtInl(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromExtInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromExtCxp(1116) == xenums::P1combs::V0, bool>::type cxpFromExtCxp0(void) { return true; }
/// Function that only compiles if cxpFromExtCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromExtCxp(1117) == xenums::P1combs::V0, bool>::type cxpFromExtCxp1(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromExtCxp2(unsigned v) { return false; }
/// Function that only exists if cxpFromExtCxp(V) returns with success, and returns true if so; for testing that cxpFromExtCxp() fails correctly at compile time.
template<int V> bool cxpFromExtCxp2(typename std::enable_if<xenums::P1combs::_cxpFromExtCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=ext, fromValue=cxp
TEST_F(TestP1combs, ExtCxp)
{
	// getValue()
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getExtCxpSize());
	EXPECT_EQ(1116, value.getExtCxp(0));
	EXPECT_EQ(-1107, value.getExtCxp(1));
	EXPECT_EQ(1117, value.getExtCxp(2));
	try { success = false; value.getExtCxp(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getExtCxpSize());
	try { success = false; value.getExtCxp(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getExtCxpSize());
	EXPECT_EQ(-1107, value.getExtCxp(0));
	try { success = false; value.getExtCxp(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromExtCxp0<void>());
	EXPECT_EQ(true, cxpFromExtCxp1<void>());
	EXPECT_EQ(false, cxpFromExtCxp2<1115>(0));
	EXPECT_EQ(true, cxpFromExtCxp2<1116>(0));
	EXPECT_EQ(true, cxpFromExtCxp2<1117>(0));
	EXPECT_EQ(false, cxpFromExtCxp2<1118>(0));
	EXPECT_EQ(false, cxpFromExtCxp2<42>(0));

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::P1combs::V0, xenums::P1combs::_cxpFromExtCxp(1116));
	// Not unique
	//EXPECT_EQ(xenums::P1combs::V0|V2, xenums::P1combs::_cxpFromExtCxp(-1107));
	EXPECT_EQ(xenums::P1combs::V0, xenums::P1combs::_cxpFromExtCxp(1117));
	try { success = false; xenums::P1combs::_cxpFromExtCxp(42); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1116;
	EXPECT_EQ(true, xenums::P1combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromExtCxp(intval));
	// Not unique
	//intval = -1107;
	//EXPECT_EQ(true, xenums::P1combs::_fromExtCxp(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromExtCxp(intval));
	intval = 1117;
	EXPECT_EQ(true, xenums::P1combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromExtCxp(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromExtCxp(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromExtCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'ExtCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=cxp ============================================

/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpOffSize() == 3, bool>::type cxpGetCxpOffSize0(void) { return true; }
/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V1.getCxpOffSize() == 0, bool>::type cxpGetCxpOffSize1(void) { return true; }
/// Function that only compiles if the constexpr getCxpOffSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getCxpOffSize() == 1, bool>::type cxpGetCxpOffSize2(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpOff(0) == 1120, bool>::type cxpGetCxpOff0(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpOff(1) == -1108, bool>::type cxpGetCxpOff1(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpOff(2) == 1121, bool>::type cxpGetCxpOff2(void) { return true; }
/// Function that only compiles if the constexpr getCxpOff() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getCxpOff(0) == -1108, bool>::type cxpGetCxpOff3(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=off
TEST_F(TestP1combs, CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpOffSize0<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize1<void>());
	EXPECT_EQ(true, cxpGetCxpOffSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpOff0<void>());
	EXPECT_EQ(true, cxpGetCxpOff1<void>());
	EXPECT_EQ(true, cxpGetCxpOff2<void>());
	EXPECT_EQ(true, cxpGetCxpOff3<void>());

	// getValue() at runtime
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getCxpOffSize());
	EXPECT_EQ(1120, value.getCxpOff(0));
	EXPECT_EQ(-1108, value.getCxpOff(1));
	EXPECT_EQ(1121, value.getCxpOff(2));
	try { success = false; value.getCxpOff(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getCxpOffSize());
	try { success = false; value.getCxpOff(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getCxpOffSize());
	EXPECT_EQ(-1108, value.getCxpOff(0));
	try { success = false; value.getCxpOff(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P1combs::_fromCxpOff(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P1combs::_fromCxpOff(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromCxpOff() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpExtSize() == 3, bool>::type cxpGetCxpExtSize0(void) { return true; }
/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V1.getCxpExtSize() == 0, bool>::type cxpGetCxpExtSize1(void) { return true; }
/// Function that only compiles if the constexpr getCxpExtSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getCxpExtSize() == 1, bool>::type cxpGetCxpExtSize2(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpExt(0) == 1122, bool>::type cxpGetCxpExt0(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpExt(1) == -1109, bool>::type cxpGetCxpExt1(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpExt(2) == 1123, bool>::type cxpGetCxpExt2(void) { return true; }
/// Function that only compiles if the constexpr getCxpExt() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getCxpExt(0) == -1109, bool>::type cxpGetCxpExt3(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=ext
TEST_F(TestP1combs, CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpExtSize0<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize1<void>());
	EXPECT_EQ(true, cxpGetCxpExtSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpExt0<void>());
	EXPECT_EQ(true, cxpGetCxpExt1<void>());
	EXPECT_EQ(true, cxpGetCxpExt2<void>());
	EXPECT_EQ(true, cxpGetCxpExt3<void>());

	// getValue() at runtime
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getCxpExtSize());
	EXPECT_EQ(1122, value.getCxpExt(0));
	EXPECT_EQ(-1109, value.getCxpExt(1));
	EXPECT_EQ(1123, value.getCxpExt(2));
	try { success = false; value.getCxpExt(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getCxpExtSize());
	try { success = false; value.getCxpExt(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getCxpExtSize());
	EXPECT_EQ(-1109, value.getCxpExt(0));
	try { success = false; value.getCxpExt(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1122;
	EXPECT_EQ(true, xenums::P1combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromCxpExt(intval));
	// Not unique
	//intval = -1109;
	//EXPECT_EQ(true, xenums::P1combs::_fromCxpExt(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromCxpExt(intval));
	intval = 1123;
	EXPECT_EQ(true, xenums::P1combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromCxpExt(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromCxpExt(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromCxpExt(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpExt'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpInlSize() == 3, bool>::type cxpGetCxpInlSize0(void) { return true; }
/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V1.getCxpInlSize() == 0, bool>::type cxpGetCxpInlSize1(void) { return true; }
/// Function that only compiles if the constexpr getCxpInlSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getCxpInlSize() == 1, bool>::type cxpGetCxpInlSize2(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpInl(0) == 1124, bool>::type cxpGetCxpInl0(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpInl(1) == -1110, bool>::type cxpGetCxpInl1(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpInl(2) == 1125, bool>::type cxpGetCxpInl2(void) { return true; }
/// Function that only compiles if the constexpr getCxpInl() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getCxpInl(0) == -1110, bool>::type cxpGetCxpInl3(void) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=inl
TEST_F(TestP1combs, CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpInlSize0<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize1<void>());
	EXPECT_EQ(true, cxpGetCxpInlSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpInl0<void>());
	EXPECT_EQ(true, cxpGetCxpInl1<void>());
	EXPECT_EQ(true, cxpGetCxpInl2<void>());
	EXPECT_EQ(true, cxpGetCxpInl3<void>());

	// getValue() at runtime
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getCxpInlSize());
	EXPECT_EQ(1124, value.getCxpInl(0));
	EXPECT_EQ(-1110, value.getCxpInl(1));
	EXPECT_EQ(1125, value.getCxpInl(2));
	try { success = false; value.getCxpInl(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getCxpInlSize());
	try { success = false; value.getCxpInl(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getCxpInlSize());
	EXPECT_EQ(-1110, value.getCxpInl(0));
	try { success = false; value.getCxpInl(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1124;
	EXPECT_EQ(true, xenums::P1combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromCxpInl(intval));
	// Not unique
	//intval = -1110;
	//EXPECT_EQ(true, xenums::P1combs::_fromCxpInl(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromCxpInl(intval));
	intval = 1125;
	EXPECT_EQ(true, xenums::P1combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromCxpInl(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromCxpInl(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromCxpInl(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpInl'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpCxpSize() == 3, bool>::type cxpGetCxpCxpSize0(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V1.getCxpCxpSize() == 0, bool>::type cxpGetCxpCxpSize1(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxpSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getCxpCxpSize() == 1, bool>::type cxpGetCxpCxpSize2(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpCxp(0) == 1126, bool>::type cxpGetCxpCxp0(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpCxp(1) == -1111, bool>::type cxpGetCxpCxp1(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V0.getCxpCxp(2) == 1127, bool>::type cxpGetCxpCxp2(void) { return true; }
/// Function that only compiles if the constexpr getCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::V2.getCxpCxp(0) == -1111, bool>::type cxpGetCxpCxp3(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromCxpCxp(1126) == xenums::P1combs::V0, bool>::type cxpFromCxpCxp0(void) { return true; }
/// Function that only compiles if cxpFromCxpCxp() actually works at compile time.
template <class T> typename std::enable_if<xenums::P1combs::_cxpFromCxpCxp(1127) == xenums::P1combs::V0, bool>::type cxpFromCxpCxp1(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromCxpCxp2(unsigned v) { return false; }
/// Function that only exists if cxpFromCxpCxp(V) returns with success, and returns true if so; for testing that cxpFromCxpCxp() fails correctly at compile time.
template<int V> bool cxpFromCxpCxp2(typename std::enable_if<xenums::P1combs::_cxpFromCxpCxp(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=cxp
TEST_F(TestP1combs, CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetCxpCxpSize0<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize1<void>());
	EXPECT_EQ(true, cxpGetCxpCxpSize2<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetCxpCxp0<void>());
	EXPECT_EQ(true, cxpGetCxpCxp1<void>());
	EXPECT_EQ(true, cxpGetCxpCxp2<void>());
	EXPECT_EQ(true, cxpGetCxpCxp3<void>());

	// getValue() at runtime
	// V0
	value = xenums::P1combs::V0;
	EXPECT_EQ(3, value.getCxpCxpSize());
	EXPECT_EQ(1126, value.getCxpCxp(0));
	EXPECT_EQ(-1111, value.getCxpCxp(1));
	EXPECT_EQ(1127, value.getCxpCxp(2));
	try { success = false; value.getCxpCxp(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::P1combs::V1;
	EXPECT_EQ(0, value.getCxpCxpSize());
	try { success = false; value.getCxpCxp(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::P1combs::V2;
	EXPECT_EQ(1, value.getCxpCxpSize());
	EXPECT_EQ(-1111, value.getCxpCxp(0));
	try { success = false; value.getCxpCxp(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromCxpCxp0<void>());
	EXPECT_EQ(true, cxpFromCxpCxp1<void>());
	EXPECT_EQ(false, cxpFromCxpCxp2<1125>(0));
	EXPECT_EQ(true, cxpFromCxpCxp2<1126>(0));
	EXPECT_EQ(true, cxpFromCxpCxp2<1127>(0));
	EXPECT_EQ(false, cxpFromCxpCxp2<1128>(0));
	EXPECT_EQ(false, cxpFromCxpCxp2<42>(0));

	// cxpFromValue() at runtime
	EXPECT_EQ(xenums::P1combs::V0, xenums::P1combs::_cxpFromCxpCxp(1126));
	// Not unique
	//EXPECT_EQ(xenums::P1combs::V0|V2, xenums::P1combs::_cxpFromCxpCxp(-1111));
	EXPECT_EQ(xenums::P1combs::V0, xenums::P1combs::_cxpFromCxpCxp(1127));
	try { success = false; xenums::P1combs::_cxpFromCxpCxp(42); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue()
	intval = 1126;
	EXPECT_EQ(true, xenums::P1combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromCxpCxp(intval));
	// Not unique
	//intval = -1111;
	//EXPECT_EQ(true, xenums::P1combs::_fromCxpCxp(intval, value));
	//EXPECT_EQ(value, xenums::P1combs::V0|V2);
	//EXPECT_EQ(value, xenums::P1combs::_fromCxpCxp(intval));
	intval = 1127;
	EXPECT_EQ(true, xenums::P1combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V0);
	EXPECT_EQ(value, xenums::P1combs::_fromCxpCxp(intval));

	value = xenums::P1combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P1combs::_fromCxpCxp(intval, value));
	EXPECT_EQ(value, xenums::P1combs::V2);
	try { success = false; xenums::P1combs::_fromCxpCxp(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'CxpCxp'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
