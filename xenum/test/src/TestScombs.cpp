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

#include <test/xenum/xenums/Scombs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenums with combinations of custom property options.
 */
class TestScombs : public ::testing::Test {
public:
	bool success;
	xenums::Scomb value;
};


/// Test basics of Scombs xenum.
TEST_F(TestScombs, Basics)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_Scombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::Scombs::_size);
}



// ========================================= Depth=0 ============================================
// =========================== depth=0 get=off ===============================

/// Test xenum with identifier features: depth=0, getValue=off, fromValue=off
TEST_F(TestScombs, S0OffOff)
{
	// getValue=off
	success = false;
	try { xenums::Scombs::V0.getS0OO(); }
	catch (std::logic_error e) { EXPECT_STREQ("getS0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	success = false;
	try { xenums::Scombs::_fromS0OO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { xenums::Scombs::_fromS0OO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=off, fromValue=ext
TEST_F(TestScombs, S0OffExt)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=0, getValue=off, fromValue=inl
TEST_F(TestScombs, S0OffInl)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=0, getValue=off, fromValue=cxp
TEST_F(TestScombs, S0OffCxp)
{
// FIXME: getValue
// FIXME: fromValue
}



// =========================== depth=0 get=ext ===============================

/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=off
TEST_F(TestScombs, S0ExtOff)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
	EXPECT_STREQ("1004", value.getS0EO());
	EXPECT_EQ(5, value.getS0EOSize());
	// V1
	value = xenums::Scombs::V1;
	EXPECT_STREQ("-1004", value.getS0EO());
	EXPECT_EQ(6, value.getS0EOSize());
	// V2
	value = xenums::Scombs::V2;
	EXPECT_STREQ("1024", value.getS0EO());
	EXPECT_EQ(5, value.getS0EOSize());

	// fromValue=off
	success = false;
	try { xenums::Scombs::_fromS0EO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { xenums::Scombs::_fromS0EO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=ext
TEST_F(TestScombs, S0ExtExt)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=inl
TEST_F(TestScombs, S0ExtInl)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=cxp
TEST_F(TestScombs, S0ExtCxp)
{
// FIXME: getValue
// FIXME: fromValue
}



// =========================== depth=0 get=cxp ===============================

/// Function that only compiles if the constexpr getS0COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS0COSize() == 5, bool>::type cxpGetS0COSize() { return true; }
/// Function that only compiles if the constexpr getS0CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS0CO(), "1008"), bool>::type cxpGetS0CO(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=off
TEST_F(TestScombs, S0CxpOff)
{
	// getS0COSize() at compile time
	EXPECT_EQ(true, cxpGetS0COSize<void>());
	// getS0CO() at compile time
	EXPECT_EQ(true, cxpGetS0CO<void>());

	// getValue()
	// V0
	value = xenums::Scombs::V0;
	EXPECT_STREQ("1008", value.getS0CO());
	EXPECT_EQ(5, value.getS0COSize());
	// V1
	value = xenums::Scombs::V1;
	EXPECT_STREQ("-1008", value.getS0CO());
	EXPECT_EQ(6, value.getS0COSize());
	// V2
	value = xenums::Scombs::V2;
	EXPECT_STREQ("1028", value.getS0CO());
	EXPECT_EQ(5, value.getS0COSize());

	// fromValue=off
	success = false;
	try { xenums::Scombs::_fromS0CO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { xenums::Scombs::_fromS0CO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=ext
TEST_F(TestScombs, S0CxpExt)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=inl
TEST_F(TestScombs, S0CxpInl)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=cxp
TEST_F(TestScombs, S0CxpCxp)
{
// FIXME: getValue
// FIXME: fromValue
}



// ========================================= Depth=1 ============================================
// =========================== depth=1 get=off ===============================

/// Test xenum with identifier features: depth=1, getValue=off, fromValue=off
TEST_F(TestScombs, S1OffOff)
{
	// getValue=off
	success = false;
	try { xenums::Scombs::V0.getS1OO(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	success = false;
	try { xenums::Scombs::_fromS1OO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { xenums::Scombs::_fromS1OO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=off, fromValue=ext
TEST_F(TestScombs, S1OffExt)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=1, getValue=off, fromValue=inl
TEST_F(TestScombs, S1OffInl)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=1, getValue=off, fromValue=cxp
TEST_F(TestScombs, S1OffCxp)
{
// FIXME: getValue
// FIXME: fromValue
}



// =========================== depth=1 get=ext ===============================

/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=off
TEST_F(TestScombs, S1ExtOff)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
	EXPECT_EQ(3, value.getS1EOSize());
	EXPECT_STREQ("1110", value.getS1EO(0));
	EXPECT_EQ(5, value.getS1EOSize(0));
	EXPECT_STREQ("-1104", value.getS1EO(1));
	EXPECT_EQ(6, value.getS1EOSize(1));
	EXPECT_STREQ("1111", value.getS1EO(2));
	EXPECT_EQ(5, value.getS1EOSize(2));
	success = false;
	try { value.getS1EO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1EOSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1EOSize());
	success = false;
	try { value.getS1EO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1EOSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Scombs::V2;
	EXPECT_EQ(1, value.getS1EOSize());
	EXPECT_STREQ("-1104", value.getS1EO(0));
	EXPECT_EQ(6, value.getS1EOSize(0));
	success = false;
	try { value.getS1EO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1EOSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	success = false;
	try { xenums::Scombs::_fromS1EO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { xenums::Scombs::_fromS1EO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=ext
TEST_F(TestScombs, S1ExtExt)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=inl
TEST_F(TestScombs, S1ExtInl)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=cxp
TEST_F(TestScombs, S1ExtCxp)
{
// FIXME: getValue
// FIXME: fromValue
}



// =========================== depth=1 get=cxp ===============================

/// Function that only compiles if the constexpr getS1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1COSize() == 3, bool>::type cxpGetS1COSize() { return true; }
/// Function that only compiles if the constexpr getS1COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1COSize(2) == 5, bool>::type cxpGetS1COSize1() { return true; }
/// Function that only compiles if the constexpr getS1CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CO(2), "1121"), bool>::type cxpGetS1CO(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=off
TEST_F(TestScombs, S1CxpOff)
{
	// getS1COSize() at compile time
	EXPECT_EQ(true, cxpGetS1COSize<void>());
	// getS1COSize(index1) at compile time
	EXPECT_EQ(true, cxpGetS1COSize1<void>());
	// getS1CO() at compile time
	EXPECT_EQ(true, cxpGetS1CO<void>());

	// getValue()
	// V0
	value = xenums::Scombs::V0;
	EXPECT_EQ(3, value.getS1COSize());
	EXPECT_STREQ("1120", value.getS1CO(0));
	EXPECT_EQ(5, value.getS1COSize(0));
	EXPECT_STREQ("-1108", value.getS1CO(1));
	EXPECT_EQ(6, value.getS1COSize(1));
	EXPECT_STREQ("1121", value.getS1CO(2));
	EXPECT_EQ(5, value.getS1COSize(2));
	success = false;
	try { value.getS1CO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1COSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1COSize());
	success = false;
	try { value.getS1CO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1COSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Scombs::V2;
	EXPECT_EQ(1, value.getS1COSize());
	EXPECT_STREQ("-1108", value.getS1CO(0));
	EXPECT_EQ(6, value.getS1COSize(0));
	success = false;
	try { value.getS1CO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS1COSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	success = false;
	try { xenums::Scombs::_fromS1CO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { xenums::Scombs::_fromS1CO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=ext
TEST_F(TestScombs, S1CxpExt)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=inl
TEST_F(TestScombs, S1CxpInl)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=cxp
TEST_F(TestScombs, S1CxpCxp)
{
// FIXME: getValue
// FIXME: fromValue
}



// ========================================= Depth=2 ============================================
// =========================== depth=2 get=off ===============================

/// Test xenum with identifier features: depth=2, getValue=off, fromValue=off
TEST_F(TestScombs, S2OffOff)
{
	// getValue=off
	success = false;
	try { xenums::Scombs::V0.getS2OO(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	success = false;
	try { xenums::Scombs::_fromS2OO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { xenums::Scombs::_fromS2OO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=off, fromValue=ext
TEST_F(TestScombs, S2OffExt)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=2, getValue=off, fromValue=inl
TEST_F(TestScombs, S2OffInl)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=2, getValue=off, fromValue=cxp
TEST_F(TestScombs, S2OffCxp)
{
// FIXME: getValue
// FIXME: fromValue
}



// =========================== depth=2 get=ext ===============================

/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=off
TEST_F(TestScombs, S2ExtOff)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
	EXPECT_EQ(2, value.getS2EOSize());
	EXPECT_EQ(3, value.getS2EOSize(0));
	EXPECT_EQ(1, value.getS2EOSize(1));
	success = false;
	try { value.getS2EOSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1210", value.getS2EO(0, 0));
	EXPECT_EQ(5, value.getS2EOSize(0, 0));
	EXPECT_STREQ("-1204", value.getS2EO(0, 1));
	EXPECT_EQ(6, value.getS2EOSize(0, 1));
	EXPECT_STREQ("1211", value.getS2EO(0, 2));
	EXPECT_EQ(5, value.getS2EOSize(0, 2));
	success = false;
	try { value.getS2EO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EOSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1204", value.getS2EO(1, 0));
	EXPECT_EQ(6, value.getS2EOSize(1, 0));
	success = false;
	try { value.getS2EO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EOSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2EO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EOSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS2EOSize());
	success = false;
	try { value.getS2EOSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EOSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Scombs::V2;
	EXPECT_EQ(1, value.getS2EOSize());
	EXPECT_EQ(0, value.getS2EOSize(0));
	success = false;
	try { value.getS2EOSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2EOSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	success = false;
	try { xenums::Scombs::_fromS2EO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { xenums::Scombs::_fromS2EO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=ext
TEST_F(TestScombs, S2ExtExt)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=inl
TEST_F(TestScombs, S2ExtInl)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=cxp
TEST_F(TestScombs, S2ExtCxp)
{
// FIXME: getValue
// FIXME: fromValue
}



// =========================== depth=2 get=cxp ===============================

/// Function that only compiles if the constexpr getS2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize() == 2, bool>::type cxpGetS2COSize() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize(0) == 3, bool>::type cxpGetS2COSize1() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize(0,2) == 5, bool>::type cxpGetS2COSize2() { return true; }
/// Function that only compiles if the constexpr getS2CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CO(1,0), "-1208"), bool>::type cxpGetS2CO(void) { return true; }
/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=off
TEST_F(TestScombs, S2CxpOff)
{
	// getS2COSize() at compile time
	EXPECT_EQ(true, cxpGetS2COSize<void>());
	// getS2COSize(index1) at compile time
	EXPECT_EQ(true, cxpGetS2COSize1<void>());
	// getS2COSize(index1,index2) at compile time
	EXPECT_EQ(true, cxpGetS2COSize2<void>());
	// getS2CO() at compile time
	EXPECT_EQ(true, cxpGetS2CO<void>());

	// getValue()
	// V0
	value = xenums::Scombs::V0;
	EXPECT_EQ(2, value.getS2COSize());
	EXPECT_EQ(3, value.getS2COSize(0));
	EXPECT_EQ(1, value.getS2COSize(1));
	success = false;
	try { value.getS2COSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1220", value.getS2CO(0, 0));
	EXPECT_EQ(5, value.getS2COSize(0, 0));
	EXPECT_STREQ("-1208", value.getS2CO(0, 1));
	EXPECT_EQ(6, value.getS2COSize(0, 1));
	EXPECT_STREQ("1221", value.getS2CO(0, 2));
	EXPECT_EQ(5, value.getS2COSize(0, 2));
	success = false;
	try { value.getS2CO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1208", value.getS2CO(1, 0));
	EXPECT_EQ(6, value.getS2COSize(1, 0));
	success = false;
	try { value.getS2CO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	success = false;
	try { value.getS2CO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS2COSize());
	success = false;
	try { value.getS2COSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::Scombs::V2;
	EXPECT_EQ(1, value.getS2COSize());
	EXPECT_EQ(0, value.getS2COSize(0));
	success = false;
	try { value.getS2COSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { value.getS2COSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	success = false;
	try { xenums::Scombs::_fromS2CO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	success = false;
	try { xenums::Scombs::_fromS2CO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=ext
TEST_F(TestScombs, S2CxpExt)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=inl
TEST_F(TestScombs, S2CxpInl)
{
// FIXME: getValue
// FIXME: fromValue
}


/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=cxp
TEST_F(TestScombs, S2CxpCxp)
{
// FIXME: getValue
// FIXME: fromValue
}



} // namespace xenum
} // namespace test
