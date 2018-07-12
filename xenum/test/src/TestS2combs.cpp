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
	try { success = false; xenums::S2combs::V0.getS2OO(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S2combs::_fromS2OO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S2combs::_fromS2OO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=ext
TEST_F(TestS2combs, OffExt)
{
	// getValue=off
	try { success = false; xenums::S2combs::V0.getS2OE(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS2OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1202";
	EXPECT_EQ(true, xenums::S2combs::_fromS2OE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2OE(strval));
	strval = "1203";
	EXPECT_EQ(true, xenums::S2combs::_fromS2OE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2OE(strval));
	// Not unique, but both are in V0.
	strval = "-1201";
	EXPECT_EQ(true, xenums::S2combs::_fromS2OE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2OE(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromS2OE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromS2OE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=off, fromValue=inl
TEST_F(TestS2combs, OffInl)
{
	// getValue=off
	try { success = false; xenums::S2combs::V0.getS2OI(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS2OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1204";
	EXPECT_EQ(true, xenums::S2combs::_fromS2OI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2OI(strval));
	strval = "1205";
	EXPECT_EQ(true, xenums::S2combs::_fromS2OI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2OI(strval));
	// Not unique, but both are in V0.
	strval = "-1202";
	EXPECT_EQ(true, xenums::S2combs::_fromS2OI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2OI(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromS2OI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromS2OI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromS2OC()
/// @{
constexpr char S2OCv0[] = "1206";
constexpr char S2OCv1[] = "-1203";
constexpr char S2OCv2[] = "1207";
constexpr char S2OCv3[] = "1205";
constexpr char S2OCv4[] = "1208";
constexpr char S2OCv5[] = "42";
/// @}
/// Function that only compiles if cxpFromS2OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromS2OC(S2OCv0) == xenums::S2combs::V0, bool>::type cxpFromS2OC0(void) { return true; }
/// Function that only compiles if cxpFromS2OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromS2OC(S2OCv1) == xenums::S2combs::V0, bool>::type cxpFromS2OC1(void) { return true; }
/// Function that only compiles if cxpFromS2OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromS2OC(S2OCv2) == xenums::S2combs::V0, bool>::type cxpFromS2OC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromS2OC3(unsigned v) { return false; }
/// Function that only exists if cxpFromS2OC(V) returns with success, and returns true if so; for testing that cxpFromS2OC() fails correctly at compile time.
template<const char* V> bool cxpFromS2OC3(typename std::enable_if<xenums::S2combs::_cxpFromS2OC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=off, fromValue=cxp
TEST_F(TestS2combs, OffCxp)
{
	// getValue=off
	try { success = false; xenums::S2combs::V0.getS2OC(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS2OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS2OC0<void>());
	EXPECT_EQ(true, cxpFromS2OC1<void>());
	EXPECT_EQ(true, cxpFromS2OC2<void>());
	EXPECT_EQ(true, cxpFromS2OC3<S2OCv0>(0));
	EXPECT_EQ(true, cxpFromS2OC3<S2OCv1>(0));
	EXPECT_EQ(true, cxpFromS2OC3<S2OCv2>(0));
	EXPECT_EQ(false, cxpFromS2OC3<S2OCv3>(0));
	EXPECT_EQ(false, cxpFromS2OC3<S2OCv4>(0));
	EXPECT_EQ(false, cxpFromS2OC3<S2OCv5>(0));

	// fromValue
	strval = "1206";
	EXPECT_EQ(true, xenums::S2combs::_fromS2OC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2OC(strval));
	strval = "1207";
	EXPECT_EQ(true, xenums::S2combs::_fromS2OC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2OC(strval));
	// Not unique, but both are in V0.
	strval = "-1203";
	EXPECT_EQ(true, xenums::S2combs::_fromS2OC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2OC(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromS2OC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromS2OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1206";
	EXPECT_EQ(true, xenums::S2combs::_cxpFromS2OC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_cxpFromS2OC(strval));
	strval = "1207";
	EXPECT_EQ(true, xenums::S2combs::_cxpFromS2OC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_cxpFromS2OC(strval));
	// Not unique, but both are in V0.
	strval = "-1203";
	EXPECT_EQ(true, xenums::S2combs::_cxpFromS2OC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_cxpFromS2OC(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_cxpFromS2OC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_cxpFromS2OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=ext ============================================

/// Test xenum with identifier features: getValue=ext, fromValue=off
TEST_F(TestS2combs, ExtOff)
{
	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getS2EOSize());
	EXPECT_EQ(3, value.getS2EOSize(0));
	EXPECT_EQ(1, value.getS2EOSize(1));
	try { success = false; value.getS2EOSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1210", value.getS2EO(0, 0));
	EXPECT_EQ(5, value.getS2EOSize(0, 0));
	EXPECT_STREQ("-1204", value.getS2EO(0, 1));
	EXPECT_EQ(6, value.getS2EOSize(0, 1));
	EXPECT_STREQ("1211", value.getS2EO(0, 2));
	EXPECT_EQ(5, value.getS2EOSize(0, 2));
	try { success = false; value.getS2EO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EOSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1204", value.getS2EO(1, 0));
	EXPECT_EQ(6, value.getS2EOSize(1, 0));
	try { success = false; value.getS2EO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EOSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getS2EO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EOSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getS2EOSize());
	try { success = false; value.getS2EOSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EOSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getS2EOSize());
	EXPECT_EQ(0, value.getS2EOSize(0));
	try { success = false; value.getS2EOSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EOSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S2combs::_fromS2EO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S2combs::_fromS2EO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=ext
TEST_F(TestS2combs, ExtExt)
{
	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getS2EESize());
	EXPECT_EQ(3, value.getS2EESize(0));
	EXPECT_EQ(1, value.getS2EESize(1));
	try { success = false; value.getS2EESize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1212", value.getS2EE(0, 0));
	EXPECT_EQ(5, value.getS2EESize(0, 0));
	EXPECT_STREQ("-1205", value.getS2EE(0, 1));
	EXPECT_EQ(6, value.getS2EESize(0, 1));
	EXPECT_STREQ("1213", value.getS2EE(0, 2));
	EXPECT_EQ(5, value.getS2EESize(0, 2));
	try { success = false; value.getS2EE(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EESize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1205", value.getS2EE(1, 0));
	EXPECT_EQ(6, value.getS2EESize(1, 0));
	try { success = false; value.getS2EE(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EESize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getS2EE(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EESize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getS2EESize());
	try { success = false; value.getS2EESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EESize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getS2EESize());
	EXPECT_EQ(0, value.getS2EESize(0));
	try { success = false; value.getS2EESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EESize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1212";
	EXPECT_EQ(true, xenums::S2combs::_fromS2EE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2EE(strval));
	strval = "1213";
	EXPECT_EQ(true, xenums::S2combs::_fromS2EE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2EE(strval));
	// Not unique, but both are in V0.
	strval = "-1205";
	EXPECT_EQ(true, xenums::S2combs::_fromS2EE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2EE(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromS2EE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromS2EE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: getValue=ext, fromValue=inl
TEST_F(TestS2combs, ExtInl)
{
	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getS2EISize());
	EXPECT_EQ(3, value.getS2EISize(0));
	EXPECT_EQ(1, value.getS2EISize(1));
	try { success = false; value.getS2EISize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1214", value.getS2EI(0, 0));
	EXPECT_EQ(5, value.getS2EISize(0, 0));
	EXPECT_STREQ("-1206", value.getS2EI(0, 1));
	EXPECT_EQ(6, value.getS2EISize(0, 1));
	EXPECT_STREQ("1215", value.getS2EI(0, 2));
	EXPECT_EQ(5, value.getS2EISize(0, 2));
	try { success = false; value.getS2EI(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EISize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1206", value.getS2EI(1, 0));
	EXPECT_EQ(6, value.getS2EISize(1, 0));
	try { success = false; value.getS2EI(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EISize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getS2EI(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EISize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getS2EISize());
	try { success = false; value.getS2EISize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EISize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getS2EISize());
	EXPECT_EQ(0, value.getS2EISize(0));
	try { success = false; value.getS2EISize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EISize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1214";
	EXPECT_EQ(true, xenums::S2combs::_fromS2EI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2EI(strval));
	strval = "1215";
	EXPECT_EQ(true, xenums::S2combs::_fromS2EI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2EI(strval));
	// Not unique, but both are in V0.
	strval = "-1206";
	EXPECT_EQ(true, xenums::S2combs::_fromS2EI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2EI(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromS2EI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromS2EI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromS2EC()
/// @{
constexpr char S2ECv0[] = "1216";
constexpr char S2ECv1[] = "-1207";
constexpr char S2ECv2[] = "1217";
constexpr char S2ECv3[] = "1215";
constexpr char S2ECv4[] = "1218";
constexpr char S2ECv5[] = "42";
/// @}
/// Function that only compiles if cxpFromS2EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromS2EC(S2ECv0) == xenums::S2combs::V0, bool>::type cxpFromS2EC0(void) { return true; }
/// Function that only compiles if cxpFromS2EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromS2EC(S2ECv1) == xenums::S2combs::V0, bool>::type cxpFromS2EC1(void) { return true; }
/// Function that only compiles if cxpFromS2EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromS2EC(S2ECv2) == xenums::S2combs::V0, bool>::type cxpFromS2EC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromS2EC3(unsigned v) { return false; }
/// Function that only exists if cxpFromS2EC(V) returns with success, and returns true if so; for testing that cxpFromS2EC() fails correctly at compile time.
template<const char* V> bool cxpFromS2EC3(typename std::enable_if<xenums::S2combs::_cxpFromS2EC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=ext, fromValue=cxp
TEST_F(TestS2combs, ExtCxp)
{
	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getS2ECSize());
	EXPECT_EQ(3, value.getS2ECSize(0));
	EXPECT_EQ(1, value.getS2ECSize(1));
	try { success = false; value.getS2ECSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1216", value.getS2EC(0, 0));
	EXPECT_EQ(5, value.getS2ECSize(0, 0));
	EXPECT_STREQ("-1207", value.getS2EC(0, 1));
	EXPECT_EQ(6, value.getS2ECSize(0, 1));
	EXPECT_STREQ("1217", value.getS2EC(0, 2));
	EXPECT_EQ(5, value.getS2ECSize(0, 2));
	try { success = false; value.getS2EC(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2ECSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1207", value.getS2EC(1, 0));
	EXPECT_EQ(6, value.getS2ECSize(1, 0));
	try { success = false; value.getS2EC(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2ECSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getS2EC(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2ECSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getS2ECSize());
	try { success = false; value.getS2ECSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2ECSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getS2ECSize());
	EXPECT_EQ(0, value.getS2ECSize(0));
	try { success = false; value.getS2ECSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2EC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2ECSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS2EC0<void>());
	EXPECT_EQ(true, cxpFromS2EC1<void>());
	EXPECT_EQ(true, cxpFromS2EC2<void>());
	EXPECT_EQ(true, cxpFromS2EC3<S2ECv0>(0));
	EXPECT_EQ(true, cxpFromS2EC3<S2ECv1>(0));
	EXPECT_EQ(true, cxpFromS2EC3<S2ECv2>(0));
	EXPECT_EQ(false, cxpFromS2EC3<S2ECv3>(0));
	EXPECT_EQ(false, cxpFromS2EC3<S2ECv4>(0));
	EXPECT_EQ(false, cxpFromS2EC3<S2ECv5>(0));

	// fromValue
	strval = "1216";
	EXPECT_EQ(true, xenums::S2combs::_fromS2EC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2EC(strval));
	strval = "1217";
	EXPECT_EQ(true, xenums::S2combs::_fromS2EC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2EC(strval));
	// Not unique, but both are in V0.
	strval = "-1207";
	EXPECT_EQ(true, xenums::S2combs::_fromS2EC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2EC(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromS2EC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromS2EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1216";
	EXPECT_EQ(true, xenums::S2combs::_cxpFromS2EC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_cxpFromS2EC(strval));
	strval = "1217";
	EXPECT_EQ(true, xenums::S2combs::_cxpFromS2EC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_cxpFromS2EC(strval));
	// Not unique, but both are in V0.
	strval = "-1207";
	EXPECT_EQ(true, xenums::S2combs::_cxpFromS2EC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_cxpFromS2EC(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_cxpFromS2EC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_cxpFromS2EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= get=cxp ============================================

/// Function that only compiles if the constexpr getS2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2COSize() == 2, bool>::type cxpGetS2COSize0() { return true; }
/// Function that only compiles if the constexpr getS2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V1.getS2COSize() == 0, bool>::type cxpGetS2COSize1() { return true; }
/// Function that only compiles if the constexpr getS2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getS2COSize() == 1, bool>::type cxpGetS2COSize2() { return true; }

/// Function that only compiles if the constexpr getS2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2COSize(0) == 3, bool>::type cxpGetS2COSize00() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2COSize(1) == 1, bool>::type cxpGetS2COSize01() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getS2COSize(0) == 0, bool>::type cxpGetS2COSize20() { return true; }

/// Function that only compiles if the constexpr getS2COSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2COSize(0,0) == 5, bool>::type cxpGetS2COSize000() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2COSize(0,1) == 6, bool>::type cxpGetS2COSize001() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2COSize(0,2) == 5, bool>::type cxpGetS2COSize002() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2COSize(1,0) == 6, bool>::type cxpGetS2COSize010() { return true; }

/// Function that only compiles if the constexpr getS2CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CO(0,0), "1220"), bool>::type cxpGetS2CO000(void) { return true; }
/// Function that only compiles if the constexpr getS2CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CO(0,1), "-1208"), bool>::type cxpGetS2CO001(void) { return true; }
/// Function that only compiles if the constexpr getS2CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CO(0,2), "1221"), bool>::type cxpGetS2CO002(void) { return true; }
/// Function that only compiles if the constexpr getS2CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CO(1,0), "-1208"), bool>::type cxpGetS2CO010(void) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=off
TEST_F(TestS2combs, CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS2COSize0<void>());
	EXPECT_EQ(true, cxpGetS2COSize1<void>());
	EXPECT_EQ(true, cxpGetS2COSize2<void>());
	EXPECT_EQ(true, cxpGetS2COSize00<void>());
	EXPECT_EQ(true, cxpGetS2COSize01<void>());
	EXPECT_EQ(true, cxpGetS2COSize20<void>());
	EXPECT_EQ(true, cxpGetS2COSize000<void>());
	EXPECT_EQ(true, cxpGetS2COSize001<void>());
	EXPECT_EQ(true, cxpGetS2COSize002<void>());
	EXPECT_EQ(true, cxpGetS2COSize010<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS2CO000<void>());
	EXPECT_EQ(true, cxpGetS2CO001<void>());
	EXPECT_EQ(true, cxpGetS2CO002<void>());
	EXPECT_EQ(true, cxpGetS2CO010<void>());

	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getS2COSize());
	EXPECT_EQ(3, value.getS2COSize(0));
	EXPECT_EQ(1, value.getS2COSize(1));
	try { success = false; value.getS2COSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1220", value.getS2CO(0, 0));
	EXPECT_EQ(5, value.getS2COSize(0, 0));
	EXPECT_STREQ("-1208", value.getS2CO(0, 1));
	EXPECT_EQ(6, value.getS2COSize(0, 1));
	EXPECT_STREQ("1221", value.getS2CO(0, 2));
	EXPECT_EQ(5, value.getS2COSize(0, 2));
	try { success = false; value.getS2CO(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2COSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1208", value.getS2CO(1, 0));
	EXPECT_EQ(6, value.getS2COSize(1, 0));
	try { success = false; value.getS2CO(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2COSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getS2CO(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2COSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getS2COSize());
	try { success = false; value.getS2COSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2COSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getS2COSize());
	EXPECT_EQ(0, value.getS2COSize(0));
	try { success = false; value.getS2COSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CO(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2COSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S2combs::_fromS2CO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S2combs::_fromS2CO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS2CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CESize() == 2, bool>::type cxpGetS2CESize0() { return true; }
/// Function that only compiles if the constexpr getS2CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V1.getS2CESize() == 0, bool>::type cxpGetS2CESize1() { return true; }
/// Function that only compiles if the constexpr getS2CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getS2CESize() == 1, bool>::type cxpGetS2CESize2() { return true; }

/// Function that only compiles if the constexpr getS2CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CESize(0) == 3, bool>::type cxpGetS2CESize00() { return true; }
/// Function that only compiles if the constexpr getS2CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CESize(1) == 1, bool>::type cxpGetS2CESize01() { return true; }
/// Function that only compiles if the constexpr getS2CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getS2CESize(0) == 0, bool>::type cxpGetS2CESize20() { return true; }

/// Function that only compiles if the constexpr getS2CESize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CESize(0,0) == 5, bool>::type cxpGetS2CESize000() { return true; }
/// Function that only compiles if the constexpr getS2CESize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CESize(0,1) == 6, bool>::type cxpGetS2CESize001() { return true; }
/// Function that only compiles if the constexpr getS2CESize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CESize(0,2) == 5, bool>::type cxpGetS2CESize002() { return true; }
/// Function that only compiles if the constexpr getS2CESize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CESize(1,0) == 6, bool>::type cxpGetS2CESize010() { return true; }

/// Function that only compiles if the constexpr getS2CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CE(0,0), "1222"), bool>::type cxpGetS2CE000(void) { return true; }
/// Function that only compiles if the constexpr getS2CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CE(0,1), "-1209"), bool>::type cxpGetS2CE001(void) { return true; }
/// Function that only compiles if the constexpr getS2CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CE(0,2), "1223"), bool>::type cxpGetS2CE002(void) { return true; }
/// Function that only compiles if the constexpr getS2CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CE(1,0), "-1209"), bool>::type cxpGetS2CE010(void) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=ext
TEST_F(TestS2combs, CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS2CESize0<void>());
	EXPECT_EQ(true, cxpGetS2CESize1<void>());
	EXPECT_EQ(true, cxpGetS2CESize2<void>());
	EXPECT_EQ(true, cxpGetS2CESize00<void>());
	EXPECT_EQ(true, cxpGetS2CESize01<void>());
	EXPECT_EQ(true, cxpGetS2CESize20<void>());
	EXPECT_EQ(true, cxpGetS2CESize000<void>());
	EXPECT_EQ(true, cxpGetS2CESize001<void>());
	EXPECT_EQ(true, cxpGetS2CESize002<void>());
	EXPECT_EQ(true, cxpGetS2CESize010<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS2CE000<void>());
	EXPECT_EQ(true, cxpGetS2CE001<void>());
	EXPECT_EQ(true, cxpGetS2CE002<void>());
	EXPECT_EQ(true, cxpGetS2CE010<void>());

	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getS2CESize());
	EXPECT_EQ(3, value.getS2CESize(0));
	EXPECT_EQ(1, value.getS2CESize(1));
	try { success = false; value.getS2CESize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1222", value.getS2CE(0, 0));
	EXPECT_EQ(5, value.getS2CESize(0, 0));
	EXPECT_STREQ("-1209", value.getS2CE(0, 1));
	EXPECT_EQ(6, value.getS2CESize(0, 1));
	EXPECT_STREQ("1223", value.getS2CE(0, 2));
	EXPECT_EQ(5, value.getS2CESize(0, 2));
	try { success = false; value.getS2CE(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CESize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1209", value.getS2CE(1, 0));
	EXPECT_EQ(6, value.getS2CESize(1, 0));
	try { success = false; value.getS2CE(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CESize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getS2CE(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CESize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getS2CESize());
	try { success = false; value.getS2CESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CESize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getS2CESize());
	EXPECT_EQ(0, value.getS2CESize(0));
	try { success = false; value.getS2CESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CE(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CESize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1222";
	EXPECT_EQ(true, xenums::S2combs::_fromS2CE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2CE(strval));
	strval = "1223";
	EXPECT_EQ(true, xenums::S2combs::_fromS2CE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2CE(strval));
	// Not unique, but both are in V0.
	strval = "-1209";
	EXPECT_EQ(true, xenums::S2combs::_fromS2CE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2CE(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromS2CE(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromS2CE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS2CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CISize() == 2, bool>::type cxpGetS2CISize0() { return true; }
/// Function that only compiles if the constexpr getS2CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V1.getS2CISize() == 0, bool>::type cxpGetS2CISize1() { return true; }
/// Function that only compiles if the constexpr getS2CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getS2CISize() == 1, bool>::type cxpGetS2CISize2() { return true; }

/// Function that only compiles if the constexpr getS2CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CISize(0) == 3, bool>::type cxpGetS2CISize00() { return true; }
/// Function that only compiles if the constexpr getS2CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CISize(1) == 1, bool>::type cxpGetS2CISize01() { return true; }
/// Function that only compiles if the constexpr getS2CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getS2CISize(0) == 0, bool>::type cxpGetS2CISize20() { return true; }

/// Function that only compiles if the constexpr getS2CISize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CISize(0,0) == 5, bool>::type cxpGetS2CISize000() { return true; }
/// Function that only compiles if the constexpr getS2CISize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CISize(0,1) == 6, bool>::type cxpGetS2CISize001() { return true; }
/// Function that only compiles if the constexpr getS2CISize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CISize(0,2) == 5, bool>::type cxpGetS2CISize002() { return true; }
/// Function that only compiles if the constexpr getS2CISize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CISize(1,0) == 6, bool>::type cxpGetS2CISize010() { return true; }

/// Function that only compiles if the constexpr getS2CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CI(0,0), "1224"), bool>::type cxpGetS2CI000(void) { return true; }
/// Function that only compiles if the constexpr getS2CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CI(0,1), "-1210"), bool>::type cxpGetS2CI001(void) { return true; }
/// Function that only compiles if the constexpr getS2CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CI(0,2), "1225"), bool>::type cxpGetS2CI002(void) { return true; }
/// Function that only compiles if the constexpr getS2CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CI(1,0), "-1210"), bool>::type cxpGetS2CI010(void) { return true; }

/// Test xenum with identifier features: getValue=cxp, fromValue=inl
TEST_F(TestS2combs, CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS2CISize0<void>());
	EXPECT_EQ(true, cxpGetS2CISize1<void>());
	EXPECT_EQ(true, cxpGetS2CISize2<void>());
	EXPECT_EQ(true, cxpGetS2CISize00<void>());
	EXPECT_EQ(true, cxpGetS2CISize01<void>());
	EXPECT_EQ(true, cxpGetS2CISize20<void>());
	EXPECT_EQ(true, cxpGetS2CISize000<void>());
	EXPECT_EQ(true, cxpGetS2CISize001<void>());
	EXPECT_EQ(true, cxpGetS2CISize002<void>());
	EXPECT_EQ(true, cxpGetS2CISize010<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS2CI000<void>());
	EXPECT_EQ(true, cxpGetS2CI001<void>());
	EXPECT_EQ(true, cxpGetS2CI002<void>());
	EXPECT_EQ(true, cxpGetS2CI010<void>());

	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getS2CISize());
	EXPECT_EQ(3, value.getS2CISize(0));
	EXPECT_EQ(1, value.getS2CISize(1));
	try { success = false; value.getS2CISize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1224", value.getS2CI(0, 0));
	EXPECT_EQ(5, value.getS2CISize(0, 0));
	EXPECT_STREQ("-1210", value.getS2CI(0, 1));
	EXPECT_EQ(6, value.getS2CISize(0, 1));
	EXPECT_STREQ("1225", value.getS2CI(0, 2));
	EXPECT_EQ(5, value.getS2CISize(0, 2));
	try { success = false; value.getS2CI(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CISize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1210", value.getS2CI(1, 0));
	EXPECT_EQ(6, value.getS2CISize(1, 0));
	try { success = false; value.getS2CI(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CISize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getS2CI(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CISize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getS2CISize());
	try { success = false; value.getS2CISize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CISize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getS2CISize());
	EXPECT_EQ(0, value.getS2CISize(0));
	try { success = false; value.getS2CISize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CI(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CISize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1224";
	EXPECT_EQ(true, xenums::S2combs::_fromS2CI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2CI(strval));
	strval = "1225";
	EXPECT_EQ(true, xenums::S2combs::_fromS2CI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2CI(strval));
	// Not unique, but both are in V0.
	strval = "-1210";
	EXPECT_EQ(true, xenums::S2combs::_fromS2CI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2CI(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromS2CI(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromS2CI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS2CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CCSize() == 2, bool>::type cxpGetS2CCSize0() { return true; }
/// Function that only compiles if the constexpr getS2CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V1.getS2CCSize() == 0, bool>::type cxpGetS2CCSize1() { return true; }
/// Function that only compiles if the constexpr getS2CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getS2CCSize() == 1, bool>::type cxpGetS2CCSize2() { return true; }

/// Function that only compiles if the constexpr getS2CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CCSize(0) == 3, bool>::type cxpGetS2CCSize00() { return true; }
/// Function that only compiles if the constexpr getS2CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CCSize(1) == 1, bool>::type cxpGetS2CCSize01() { return true; }
/// Function that only compiles if the constexpr getS2CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V2.getS2CCSize(0) == 0, bool>::type cxpGetS2CCSize20() { return true; }

/// Function that only compiles if the constexpr getS2CCSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CCSize(0,0) == 5, bool>::type cxpGetS2CCSize000() { return true; }
/// Function that only compiles if the constexpr getS2CCSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CCSize(0,1) == 6, bool>::type cxpGetS2CCSize001() { return true; }
/// Function that only compiles if the constexpr getS2CCSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CCSize(0,2) == 5, bool>::type cxpGetS2CCSize002() { return true; }
/// Function that only compiles if the constexpr getS2CCSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::V0.getS2CCSize(1,0) == 6, bool>::type cxpGetS2CCSize010() { return true; }

/// Function that only compiles if the constexpr getS2CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CC(0,0), "1226"), bool>::type cxpGetS2CC000(void) { return true; }
/// Function that only compiles if the constexpr getS2CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CC(0,1), "-1211"), bool>::type cxpGetS2CC001(void) { return true; }
/// Function that only compiles if the constexpr getS2CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CC(0,2), "1227"), bool>::type cxpGetS2CC002(void) { return true; }
/// Function that only compiles if the constexpr getS2CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S2combs::V0.getS2CC(1,0), "-1211"), bool>::type cxpGetS2CC010(void) { return true; }

/// Values for testing cxpFromS2CC()
/// @{
constexpr char S2CCv0[] = "1226";
constexpr char S2CCv1[] = "-1211";
constexpr char S2CCv2[] = "1227";
constexpr char S2CCv3[] = "1225";
constexpr char S2CCv4[] = "1228";
constexpr char S2CCv5[] = "42";
/// @}
/// Function that only compiles if cxpFromS2CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromS2CC(S2CCv0) == xenums::S2combs::V0, bool>::type cxpFromS2CC0(void) { return true; }
/// Function that only compiles if cxpFromS2CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromS2CC(S2CCv1) == xenums::S2combs::V0, bool>::type cxpFromS2CC1(void) { return true; }
/// Function that only compiles if cxpFromS2CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S2combs::_cxpFromS2CC(S2CCv2) == xenums::S2combs::V0, bool>::type cxpFromS2CC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromS2CC3(unsigned v) { return false; }
/// Function that only exists if cxpFromS2CC(V) returns with success, and returns true if so; for testing that cxpFromS2CC() fails correctly at compile time.
template<const char* V> bool cxpFromS2CC3(typename std::enable_if<xenums::S2combs::_cxpFromS2CC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: getValue=cxp, fromValue=cxp
TEST_F(TestS2combs, CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS2CCSize0<void>());
	EXPECT_EQ(true, cxpGetS2CCSize1<void>());
	EXPECT_EQ(true, cxpGetS2CCSize2<void>());
	EXPECT_EQ(true, cxpGetS2CCSize00<void>());
	EXPECT_EQ(true, cxpGetS2CCSize01<void>());
	EXPECT_EQ(true, cxpGetS2CCSize20<void>());
	EXPECT_EQ(true, cxpGetS2CCSize000<void>());
	EXPECT_EQ(true, cxpGetS2CCSize001<void>());
	EXPECT_EQ(true, cxpGetS2CCSize002<void>());
	EXPECT_EQ(true, cxpGetS2CCSize010<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS2CC000<void>());
	EXPECT_EQ(true, cxpGetS2CC001<void>());
	EXPECT_EQ(true, cxpGetS2CC002<void>());
	EXPECT_EQ(true, cxpGetS2CC010<void>());

	// getValue()
	// V0
	value = xenums::S2combs::V0;
	EXPECT_EQ(2, value.getS2CCSize());
	EXPECT_EQ(3, value.getS2CCSize(0));
	EXPECT_EQ(1, value.getS2CCSize(1));
	try { success = false; value.getS2CCSize(2); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("1226", value.getS2CC(0, 0));
	EXPECT_EQ(5, value.getS2CCSize(0, 0));
	EXPECT_STREQ("-1211", value.getS2CC(0, 1));
	EXPECT_EQ(6, value.getS2CCSize(0, 1));
	EXPECT_STREQ("1227", value.getS2CC(0, 2));
	EXPECT_EQ(5, value.getS2CCSize(0, 2));
	try { success = false; value.getS2CC(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CCSize(0, 3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	EXPECT_STREQ("-1211", value.getS2CC(1, 0));
	EXPECT_EQ(6, value.getS2CCSize(1, 0));
	try { success = false; value.getS2CC(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CCSize(1, 1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	try { success = false; value.getS2CC(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CCSize(2, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V1
	value = xenums::S2combs::V1;
	EXPECT_EQ(0, value.getS2CCSize());
	try { success = false; value.getS2CCSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CCSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// V2
	value = xenums::S2combs::V2;
	EXPECT_EQ(1, value.getS2CCSize());
	EXPECT_EQ(0, value.getS2CCSize(0));
	try { success = false; value.getS2CCSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CC(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS2CCSize(0, 0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS2CC0<void>());
	EXPECT_EQ(true, cxpFromS2CC1<void>());
	EXPECT_EQ(true, cxpFromS2CC2<void>());
	EXPECT_EQ(true, cxpFromS2CC3<S2CCv0>(0));
	EXPECT_EQ(true, cxpFromS2CC3<S2CCv1>(0));
	EXPECT_EQ(true, cxpFromS2CC3<S2CCv2>(0));
	EXPECT_EQ(false, cxpFromS2CC3<S2CCv3>(0));
	EXPECT_EQ(false, cxpFromS2CC3<S2CCv4>(0));
	EXPECT_EQ(false, cxpFromS2CC3<S2CCv5>(0));

	// fromValue
	strval = "1226";
	EXPECT_EQ(true, xenums::S2combs::_fromS2CC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2CC(strval));
	strval = "1227";
	EXPECT_EQ(true, xenums::S2combs::_fromS2CC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2CC(strval));
	// Not unique, but both are in V0.
	strval = "-1211";
	EXPECT_EQ(true, xenums::S2combs::_fromS2CC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_fromS2CC(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_fromS2CC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_fromS2CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1226";
	EXPECT_EQ(true, xenums::S2combs::_cxpFromS2CC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_cxpFromS2CC(strval));
	strval = "1227";
	EXPECT_EQ(true, xenums::S2combs::_cxpFromS2CC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_cxpFromS2CC(strval));
	// Not unique, but both are in V0.
	strval = "-1211";
	EXPECT_EQ(true, xenums::S2combs::_cxpFromS2CC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V0);
	EXPECT_EQ(value, xenums::S2combs::_cxpFromS2CC(strval));

	value = xenums::S2combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S2combs::_cxpFromS2CC(strval, value));
	EXPECT_EQ(value, xenums::S2combs::V2);
	try { success = false; xenums::S2combs::_cxpFromS2CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
