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


// ========================================= Depth=2 ============================================
// =========================== depth=2 get=off ===============================

/// Test xenum with identifier features: depth=2, getValue=off, fromValue=off
TEST_F(TestP2combs, P2OffOff)
{
	// getValue=off
	try { success = false; xenums::P2combs::V0.getP2OO(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P2combs::_fromP2OO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P2combs::_fromP2OO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=off, fromValue=ext
TEST_F(TestP2combs, P2OffExt)
{
	// getValue=off
	try { success = false; xenums::P2combs::V0.getP2OE(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP2OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1202;
	EXPECT_EQ(true, xenums::P2combs::_fromP2OE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2OE(intval));
	intval = 1203;
	EXPECT_EQ(true, xenums::P2combs::_fromP2OE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2OE(intval));
	// Not unique, but both are in V0
	intval = -1201;
	EXPECT_EQ(true, xenums::P2combs::_fromP2OE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2OE(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromP2OE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromP2OE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=off, fromValue=inl
TEST_F(TestP2combs, P2OffInl)
{
	// getValue=off
	try { success = false; xenums::P2combs::V0.getP2OI(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP2OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1204;
	EXPECT_EQ(true, xenums::P2combs::_fromP2OI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2OI(intval));
	intval = 1205;
	EXPECT_EQ(true, xenums::P2combs::_fromP2OI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2OI(intval));
	// Not unique, but both are in V0
	intval = -1202;
	EXPECT_EQ(true, xenums::P2combs::_fromP2OI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2OI(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromP2OI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromP2OI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromP2OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromP2OC(1206) == xenums::P2combs::V0, bool>::type cxpFromP2OC0(void) { return true; }
/// Function that only compiles if cxpFromP2OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromP2OC(1207) == xenums::P2combs::V0, bool>::type cxpFromP2OC1(void) { return true; }
/// Function that only compiles if cxpFromP2OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromP2OC(-1203) == xenums::P2combs::V0, bool>::type cxpFromP2OC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromP2OC3(unsigned v) { return false; }
/// Function that only exists if cxpFromP2OC(V) returns with success, and returns true if so; for testing that cxpFromP2OC() fails correctly at compile time.
template<int V> bool cxpFromP2OC3(typename std::enable_if<xenums::P2combs::_cxpFromP2OC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=2, getValue=off, fromValue=cxp
TEST_F(TestP2combs, P2OffCxp)
{
	// getValue=off
	try { success = false; xenums::P2combs::V0.getP2OC(0,0); }
	catch (std::logic_error e) { EXPECT_STREQ("getP2OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromP2OC0<void>());
	EXPECT_EQ(true, cxpFromP2OC1<void>());
	EXPECT_EQ(true, cxpFromP2OC2<void>());
	EXPECT_EQ(false, cxpFromP2OC3<1205>(0));
	EXPECT_EQ(true, cxpFromP2OC3<1206>(0));
	EXPECT_EQ(true, cxpFromP2OC3<1207>(0));
	EXPECT_EQ(false, cxpFromP2OC3<1208>(0));
	EXPECT_EQ(false, cxpFromP2OC3<42>(0));

	// fromValue
	intval = 1206;
	EXPECT_EQ(true, xenums::P2combs::_fromP2OC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2OC(intval));
	intval = 1207;
	EXPECT_EQ(true, xenums::P2combs::_fromP2OC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2OC(intval));
	// Not unique, but both are in V0
	intval = -1203;
	EXPECT_EQ(true, xenums::P2combs::_fromP2OC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2OC(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromP2OC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromP2OC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	intval = 1206;
	EXPECT_EQ(true, xenums::P2combs::_cxpFromP2OC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_cxpFromP2OC(intval));
	intval = 1207;
	EXPECT_EQ(true, xenums::P2combs::_cxpFromP2OC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_cxpFromP2OC(intval));
	// Not unique, but both are in V0
	intval = -1203;
	EXPECT_EQ(true, xenums::P2combs::_cxpFromP2OC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_cxpFromP2OC(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_cxpFromP2OC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_cxpFromP2OC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=2 get=ext ===============================

/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=off
TEST_F(TestP2combs, P2ExtOff)
{
	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getP2EOSize());
	EXPECT_EQ(3, value.getP2EOSize(0));
	EXPECT_EQ(1, value.getP2EOSize(1));
	try { success = false; value.getP2EOSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1210, value.getP2EO(0, 0));
	EXPECT_EQ(-1204, value.getP2EO(0, 1));
	EXPECT_EQ(1211, value.getP2EO(0, 2));
	try { success = false; value.getP2EO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1204, value.getP2EO(1, 0));
	try { success = false; value.getP2EO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2EO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getP2EOSize());
	try { success = false; value.getP2EOSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getP2EOSize());
	EXPECT_EQ(0, value.getP2EOSize(0));
	try { success = false; value.getP2EOSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P2combs::_fromP2EO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P2combs::_fromP2EO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=ext
TEST_F(TestP2combs, P2ExtExt)
{
	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getP2EESize());
	EXPECT_EQ(3, value.getP2EESize(0));
	EXPECT_EQ(1, value.getP2EESize(1));
	try { success = false; value.getP2EESize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1212, value.getP2EE(0, 0));
	EXPECT_EQ(-1205, value.getP2EE(0, 1));
	EXPECT_EQ(1213, value.getP2EE(0, 2));
	try { success = false; value.getP2EE(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1205, value.getP2EE(1, 0));
	try { success = false; value.getP2EE(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2EE(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getP2EESize());
	try { success = false; value.getP2EESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getP2EESize());
	EXPECT_EQ(0, value.getP2EESize(0));
	try { success = false; value.getP2EESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1212;
	EXPECT_EQ(true, xenums::P2combs::_fromP2EE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2EE(intval));
	intval = 1213;
	EXPECT_EQ(true, xenums::P2combs::_fromP2EE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2EE(intval));
	// Not unique, but both are in V0
	intval = -1205;
	EXPECT_EQ(true, xenums::P2combs::_fromP2EE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2EE(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromP2EE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromP2EE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=inl
TEST_F(TestP2combs, P2ExtInl)
{
	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getP2EISize());
	EXPECT_EQ(3, value.getP2EISize(0));
	EXPECT_EQ(1, value.getP2EISize(1));
	try { success = false; value.getP2EISize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1214, value.getP2EI(0, 0));
	EXPECT_EQ(-1206, value.getP2EI(0, 1));
	EXPECT_EQ(1215, value.getP2EI(0, 2));
	try { success = false; value.getP2EI(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1206, value.getP2EI(1, 0));
	try { success = false; value.getP2EI(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2EI(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getP2EISize());
	try { success = false; value.getP2EISize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getP2EISize());
	EXPECT_EQ(0, value.getP2EISize(0));
	try { success = false; value.getP2EISize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1214;
	EXPECT_EQ(true, xenums::P2combs::_fromP2EI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2EI(intval));
	intval = 1215;
	EXPECT_EQ(true, xenums::P2combs::_fromP2EI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2EI(intval));
	// Not unique, but both are in V0
	intval = -1206;
	EXPECT_EQ(true, xenums::P2combs::_fromP2EI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2EI(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromP2EI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromP2EI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromP2EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromP2EC(1216) == xenums::P2combs::V0, bool>::type cxpFromP2EC0(void) { return true; }
/// Function that only compiles if cxpFromP2EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromP2EC(1217) == xenums::P2combs::V0, bool>::type cxpFromP2EC1(void) { return true; }
/// Function that only compiles if cxpFromP2EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromP2EC(-1207) == xenums::P2combs::V0, bool>::type cxpFromP2EC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromP2EC3(unsigned v) { return false; }
/// Function that only exists if cxpFromP2EC(V) returns with success, and returns true if so; for testing that cxpFromP2EC() fails correctly at compile time.
template<int V> bool cxpFromP2EC3(typename std::enable_if<xenums::P2combs::_cxpFromP2EC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=cxp
TEST_F(TestP2combs, P2ExtCxp)
{
	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getP2ECSize());
	EXPECT_EQ(3, value.getP2ECSize(0));
	EXPECT_EQ(1, value.getP2ECSize(1));
	try { success = false; value.getP2ECSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1216, value.getP2EC(0, 0));
	EXPECT_EQ(-1207, value.getP2EC(0, 1));
	EXPECT_EQ(1217, value.getP2EC(0, 2));
	try { success = false; value.getP2EC(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1207, value.getP2EC(1, 0));
	try { success = false; value.getP2EC(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2EC(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getP2ECSize());
	try { success = false; value.getP2ECSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getP2ECSize());
	EXPECT_EQ(0, value.getP2ECSize(0));
	try { success = false; value.getP2ECSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2EC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromP2EC0<void>());
	EXPECT_EQ(true, cxpFromP2EC1<void>());
	EXPECT_EQ(true, cxpFromP2EC2<void>());
	EXPECT_EQ(false, cxpFromP2EC3<1215>(0));
	EXPECT_EQ(true, cxpFromP2EC3<1216>(0));
	EXPECT_EQ(true, cxpFromP2EC3<1217>(0));
	EXPECT_EQ(false, cxpFromP2EC3<1218>(0));
	EXPECT_EQ(false, cxpFromP2EC3<42>(0));

	// fromValue
	intval = 1216;
	EXPECT_EQ(true, xenums::P2combs::_fromP2EC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2EC(intval));
	intval = 1217;
	EXPECT_EQ(true, xenums::P2combs::_fromP2EC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2EC(intval));
	// Not unique, but both are in V0
	intval = -1207;
	EXPECT_EQ(true, xenums::P2combs::_fromP2EC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2EC(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromP2EC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromP2EC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	intval = 1216;
	EXPECT_EQ(true, xenums::P2combs::_cxpFromP2EC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_cxpFromP2EC(intval));
	intval = 1217;
	EXPECT_EQ(true, xenums::P2combs::_cxpFromP2EC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_cxpFromP2EC(intval));
	// Not unique, but both are in V0
	intval = -1207;
	EXPECT_EQ(true, xenums::P2combs::_cxpFromP2EC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_cxpFromP2EC(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_cxpFromP2EC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_cxpFromP2EC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=2 get=cxp ===============================

/// Function that only compiles if the constexpr getP2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2COSize() == 2, bool>::type cxpGetP2COSize0() { return true; }
/// Function that only compiles if the constexpr getP2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V1.getP2COSize() == 0, bool>::type cxpGetP2COSize1() { return true; }
/// Function that only compiles if the constexpr getP2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getP2COSize() == 1, bool>::type cxpGetP2COSize2() { return true; }

/// Function that only compiles if the constexpr getP2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2COSize(0) == 3, bool>::type cxpGetP2COSize00() { return true; }
/// Function that only compiles if the constexpr getP2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2COSize(1) == 1, bool>::type cxpGetP2COSize01() { return true; }
/// Function that only compiles if the constexpr getP2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getP2COSize(0) == 0, bool>::type cxpGetP2COSize20() { return true; }

/// Function that only compiles if the constexpr getP2CO(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CO(0,0) == 1220, bool>::type cxpGetP2CO000(void) { return true; }
/// Function that only compiles if the constexpr getP2CO(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CO(0,1) == -1208, bool>::type cxpGetP2CO001(void) { return true; }
/// Function that only compiles if the constexpr getP2CO(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CO(0,2) == 1221, bool>::type cxpGetP2CO002(void) { return true; }
/// Function that only compiles if the constexpr getP2CO(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CO(1,0) == -1208, bool>::type cxpGetP2CO010(void) { return true; }

/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=off
TEST_F(TestP2combs, P2CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP2COSize0<void>());
	EXPECT_EQ(true, cxpGetP2COSize1<void>());
	EXPECT_EQ(true, cxpGetP2COSize2<void>());
	EXPECT_EQ(true, cxpGetP2COSize00<void>());
	EXPECT_EQ(true, cxpGetP2COSize01<void>());
	EXPECT_EQ(true, cxpGetP2COSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP2CO000<void>());
	EXPECT_EQ(true, cxpGetP2CO001<void>());
	EXPECT_EQ(true, cxpGetP2CO002<void>());
	EXPECT_EQ(true, cxpGetP2CO010<void>());

	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getP2COSize());
	EXPECT_EQ(3, value.getP2COSize(0));
	EXPECT_EQ(1, value.getP2COSize(1));
	try { success = false; value.getP2COSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1220, value.getP2CO(0, 0));
	EXPECT_EQ(-1208, value.getP2CO(0, 1));
	EXPECT_EQ(1221, value.getP2CO(0, 2));
	try { success = false; value.getP2CO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1208, value.getP2CO(1, 0));
	try { success = false; value.getP2CO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2CO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getP2COSize());
	try { success = false; value.getP2COSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getP2COSize());
	EXPECT_EQ(0, value.getP2COSize(0));
	try { success = false; value.getP2COSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::P2combs::_fromP2CO(42); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::P2combs::_fromP2CO(42, value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromP2CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP2CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CESize() == 2, bool>::type cxpGetP2CESize0() { return true; }
/// Function that only compiles if the constexpr getP2CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V1.getP2CESize() == 0, bool>::type cxpGetP2CESize1() { return true; }
/// Function that only compiles if the constexpr getP2CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getP2CESize() == 1, bool>::type cxpGetP2CESize2() { return true; }

/// Function that only compiles if the constexpr getP2CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CESize(0) == 3, bool>::type cxpGetP2CESize00() { return true; }
/// Function that only compiles if the constexpr getP2CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CESize(1) == 1, bool>::type cxpGetP2CESize01() { return true; }
/// Function that only compiles if the constexpr getP2CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getP2CESize(0) == 0, bool>::type cxpGetP2CESize20() { return true; }

/// Function that only compiles if the constexpr getP2CE(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CE(0,0) == 1222, bool>::type cxpGetP2CE000(void) { return true; }
/// Function that only compiles if the constexpr getP2CE(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CE(0,1) == -1209, bool>::type cxpGetP2CE001(void) { return true; }
/// Function that only compiles if the constexpr getP2CE(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CE(0,2) == 1223, bool>::type cxpGetP2CE002(void) { return true; }
/// Function that only compiles if the constexpr getP2CE(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CE(1,0) == -1209, bool>::type cxpGetP2CE010(void) { return true; }

/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=ext
TEST_F(TestP2combs, P2CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP2CESize0<void>());
	EXPECT_EQ(true, cxpGetP2CESize1<void>());
	EXPECT_EQ(true, cxpGetP2CESize2<void>());
	EXPECT_EQ(true, cxpGetP2CESize00<void>());
	EXPECT_EQ(true, cxpGetP2CESize01<void>());
	EXPECT_EQ(true, cxpGetP2CESize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP2CE000<void>());
	EXPECT_EQ(true, cxpGetP2CE001<void>());
	EXPECT_EQ(true, cxpGetP2CE002<void>());
	EXPECT_EQ(true, cxpGetP2CE010<void>());

	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getP2CESize());
	EXPECT_EQ(3, value.getP2CESize(0));
	EXPECT_EQ(1, value.getP2CESize(1));
	try { success = false; value.getP2CESize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1222, value.getP2CE(0, 0));
	EXPECT_EQ(-1209, value.getP2CE(0, 1));
	EXPECT_EQ(1223, value.getP2CE(0, 2));
	try { success = false; value.getP2CE(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1209, value.getP2CE(1, 0));
	try { success = false; value.getP2CE(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2CE(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getP2CESize());
	try { success = false; value.getP2CESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getP2CESize());
	EXPECT_EQ(0, value.getP2CESize(0));
	try { success = false; value.getP2CESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1222;
	EXPECT_EQ(true, xenums::P2combs::_fromP2CE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2CE(intval));
	intval = 1223;
	EXPECT_EQ(true, xenums::P2combs::_fromP2CE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2CE(intval));
	// Not unique, but both are in V0
	intval = -1209;
	EXPECT_EQ(true, xenums::P2combs::_fromP2CE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2CE(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromP2CE(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromP2CE(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP2CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CISize() == 2, bool>::type cxpGetP2CISize0() { return true; }
/// Function that only compiles if the constexpr getP2CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V1.getP2CISize() == 0, bool>::type cxpGetP2CISize1() { return true; }
/// Function that only compiles if the constexpr getP2CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getP2CISize() == 1, bool>::type cxpGetP2CISize2() { return true; }

/// Function that only compiles if the constexpr getP2CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CISize(0) == 3, bool>::type cxpGetP2CISize00() { return true; }
/// Function that only compiles if the constexpr getP2CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CISize(1) == 1, bool>::type cxpGetP2CISize01() { return true; }
/// Function that only compiles if the constexpr getP2CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getP2CISize(0) == 0, bool>::type cxpGetP2CISize20() { return true; }

/// Function that only compiles if the constexpr getP2CI(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CI(0,0) == 1224, bool>::type cxpGetP2CI000(void) { return true; }
/// Function that only compiles if the constexpr getP2CI(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CI(0,1) == -1210, bool>::type cxpGetP2CI001(void) { return true; }
/// Function that only compiles if the constexpr getP2CI(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CI(0,2) == 1225, bool>::type cxpGetP2CI002(void) { return true; }
/// Function that only compiles if the constexpr getP2CI(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CI(1,0) == -1210, bool>::type cxpGetP2CI010(void) { return true; }

/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=inl
TEST_F(TestP2combs, P2CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP2CISize0<void>());
	EXPECT_EQ(true, cxpGetP2CISize1<void>());
	EXPECT_EQ(true, cxpGetP2CISize2<void>());
	EXPECT_EQ(true, cxpGetP2CISize00<void>());
	EXPECT_EQ(true, cxpGetP2CISize01<void>());
	EXPECT_EQ(true, cxpGetP2CISize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP2CI000<void>());
	EXPECT_EQ(true, cxpGetP2CI001<void>());
	EXPECT_EQ(true, cxpGetP2CI002<void>());
	EXPECT_EQ(true, cxpGetP2CI010<void>());

	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getP2CISize());
	EXPECT_EQ(3, value.getP2CISize(0));
	EXPECT_EQ(1, value.getP2CISize(1));
	try { success = false; value.getP2CISize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1224, value.getP2CI(0, 0));
	EXPECT_EQ(-1210, value.getP2CI(0, 1));
	EXPECT_EQ(1225, value.getP2CI(0, 2));
	try { success = false; value.getP2CI(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1210, value.getP2CI(1, 0));
	try { success = false; value.getP2CI(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2CI(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getP2CISize());
	try { success = false; value.getP2CISize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getP2CISize());
	EXPECT_EQ(0, value.getP2CISize(0));
	try { success = false; value.getP2CISize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	intval = 1224;
	EXPECT_EQ(true, xenums::P2combs::_fromP2CI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2CI(intval));
	intval = 1225;
	EXPECT_EQ(true, xenums::P2combs::_fromP2CI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2CI(intval));
	// Not unique, but both are in V0
	intval = -1210;
	EXPECT_EQ(true, xenums::P2combs::_fromP2CI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2CI(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromP2CI(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromP2CI(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getP2CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CCSize() == 2, bool>::type cxpGetP2CCSize0() { return true; }
/// Function that only compiles if the constexpr getP2CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V1.getP2CCSize() == 0, bool>::type cxpGetP2CCSize1() { return true; }
/// Function that only compiles if the constexpr getP2CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getP2CCSize() == 1, bool>::type cxpGetP2CCSize2() { return true; }

/// Function that only compiles if the constexpr getP2CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CCSize(0) == 3, bool>::type cxpGetP2CCSize00() { return true; }
/// Function that only compiles if the constexpr getP2CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CCSize(1) == 1, bool>::type cxpGetP2CCSize01() { return true; }
/// Function that only compiles if the constexpr getP2CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V2.getP2CCSize(0) == 0, bool>::type cxpGetP2CCSize20() { return true; }

/// Function that only compiles if the constexpr getP2CC(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CC(0,0) == 1226, bool>::type cxpGetP2CC000(void) { return true; }
/// Function that only compiles if the constexpr getP2CC(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CC(0,1) == -1211, bool>::type cxpGetP2CC001(void) { return true; }
/// Function that only compiles if the constexpr getP2CC(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CC(0,2) == 1227, bool>::type cxpGetP2CC002(void) { return true; }
/// Function that only compiles if the constexpr getP2CC(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::V0.getP2CC(1,0) == -1211, bool>::type cxpGetP2CC010(void) { return true; }

/// Function that only compiles if cxpFromP2CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromP2CC(1226) == xenums::P2combs::V0, bool>::type cxpFromP2CC0(void) { return true; }
/// Function that only compiles if cxpFromP2CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromP2CC(1227) == xenums::P2combs::V0, bool>::type cxpFromP2CC1(void) { return true; }
/// Function that only compiles if cxpFromP2CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::P2combs::_cxpFromP2CC(-1211) == xenums::P2combs::V0, bool>::type cxpFromP2CC2(void) { return true; }

/// Fallback function that always exists and always returns false.
template<int V> bool cxpFromP2CC3(unsigned v) { return false; }
/// Function that only exists if cxpFromP2CC(V) returns with success, and returns true if so; for testing that cxpFromP2CC() fails correctly at compile time.
template<int V> bool cxpFromP2CC3(typename std::enable_if<xenums::P2combs::_cxpFromP2CC(V).toTrue(), int>::type) { return true; }

/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=cxp
TEST_F(TestP2combs, P2CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetP2CCSize0<void>());
	EXPECT_EQ(true, cxpGetP2CCSize1<void>());
	EXPECT_EQ(true, cxpGetP2CCSize2<void>());
	EXPECT_EQ(true, cxpGetP2CCSize00<void>());
	EXPECT_EQ(true, cxpGetP2CCSize01<void>());
	EXPECT_EQ(true, cxpGetP2CCSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetP2CC000<void>());
	EXPECT_EQ(true, cxpGetP2CC001<void>());
	EXPECT_EQ(true, cxpGetP2CC002<void>());
	EXPECT_EQ(true, cxpGetP2CC010<void>());

	// getValue()
	// V0
	value = xenums::P2combs::V0;
	EXPECT_EQ(2, value.getP2CCSize());
	EXPECT_EQ(3, value.getP2CCSize(0));
	EXPECT_EQ(1, value.getP2CCSize(1));
	try { success = false; value.getP2CCSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(1226, value.getP2CC(0, 0));
	EXPECT_EQ(-1211, value.getP2CC(0, 1));
	EXPECT_EQ(1227, value.getP2CC(0, 2));
	try { success = false; value.getP2CC(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_EQ(-1211, value.getP2CC(1, 0));
	try { success = false; value.getP2CC(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getP2CC(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::P2combs::V1;
	EXPECT_EQ(0, value.getP2CCSize());
	try { success = false; value.getP2CCSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::P2combs::V2;
	EXPECT_EQ(1, value.getP2CCSize());
	EXPECT_EQ(0, value.getP2CCSize(0));
	try { success = false; value.getP2CCSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getP2CC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromP2CC0<void>());
	EXPECT_EQ(true, cxpFromP2CC1<void>());
	EXPECT_EQ(true, cxpFromP2CC2<void>());
	EXPECT_EQ(false, cxpFromP2CC3<1225>(0));
	EXPECT_EQ(true, cxpFromP2CC3<1226>(0));
	EXPECT_EQ(true, cxpFromP2CC3<1227>(0));
	EXPECT_EQ(false, cxpFromP2CC3<1228>(0));
	EXPECT_EQ(false, cxpFromP2CC3<42>(0));

	// fromValue
	intval = 1226;
	EXPECT_EQ(true, xenums::P2combs::_fromP2CC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2CC(intval));
	intval = 1227;
	EXPECT_EQ(true, xenums::P2combs::_fromP2CC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2CC(intval));
	// Not unique, but both are in V0
	intval = -1211;
	EXPECT_EQ(true, xenums::P2combs::_fromP2CC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_fromP2CC(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_fromP2CC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_fromP2CC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	intval = 1226;
	EXPECT_EQ(true, xenums::P2combs::_cxpFromP2CC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_cxpFromP2CC(intval));
	intval = 1227;
	EXPECT_EQ(true, xenums::P2combs::_cxpFromP2CC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_cxpFromP2CC(intval));
	// Not unique, but both are in V0
	intval = -1211;
	EXPECT_EQ(true, xenums::P2combs::_cxpFromP2CC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V0);
	EXPECT_EQ(value, xenums::P2combs::_cxpFromP2CC(intval));

	value = xenums::P2combs::V2;
	intval = 42;
	EXPECT_EQ(false, xenums::P2combs::_cxpFromP2CC(intval, value));
	EXPECT_EQ(value, xenums::P2combs::V2);
	try { success = false; xenums::P2combs::_cxpFromP2CC(intval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'P2CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
