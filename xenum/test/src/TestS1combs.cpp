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



// ========================================= Depth=1 ============================================
// =========================== depth=1 get=off ===============================

/// Test xenum with identifier features: depth=1, getValue=off, fromValue=off
TEST_F(TestS1combs, S1OffOff)
{
	// getValue=off
	try { success = false; xenums::S1combs::V0.getS1OO(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S1combs::_fromS1OO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S1combs::_fromS1OO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=off, fromValue=ext
TEST_F(TestS1combs, S1OffExt)
{
	// getValue=off
	try { success = false; xenums::S1combs::V0.getS1OE(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS1OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1102";
	EXPECT_EQ(true, xenums::S1combs::_fromS1OE(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1OE(strval));
	// Not unique
	//strval = "-1101";
	//EXPECT_EQ(true, xenums::S1combs::_fromS1OE(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromS1OE(strval));
	strval = "1103";
	EXPECT_EQ(true, xenums::S1combs::_fromS1OE(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1OE(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromS1OE(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromS1OE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=off, fromValue=inl
TEST_F(TestS1combs, S1OffInl)
{
	// getValue=off
	try { success = false; xenums::S1combs::V0.getS1OI(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS1OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1104";
	EXPECT_EQ(true, xenums::S1combs::_fromS1OI(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1OI(strval));
	// Not unique
	//strval = "-1102";
	//EXPECT_EQ(true, xenums::S1combs::_fromS1OI(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromS1OI(strval));
	strval = "1105";
	EXPECT_EQ(true, xenums::S1combs::_fromS1OI(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1OI(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromS1OI(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromS1OI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromS1OC()
/// @{
constexpr char S1OCv0[] = "1106";
//constexpr char S1OCv1[] = "-1103";
constexpr char S1OCv2[] = "1107";
constexpr char S1OCv3[] = "1105";
constexpr char S1OCv4[] = "1108";
constexpr char S1OCv5[] = "42";
/// @}
/// Function that only compiles if cxpFromS1OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromS1OC(S1OCv0) == xenums::S1combs::V0, bool>::type cxpFromS1OC0(void) { return true; }
/// Function that only compiles if cxpFromS1OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromS1OC(S1OCv2) == xenums::S1combs::V0, bool>::type cxpFromS1OC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromS1OC3(unsigned v) { return false; }
/// Function that only exists if cxpFromS1OC(V) returns with success, and returns true if so; for testing that cxpFromS1OC() fails correctly at compile time.
template<const char* V> bool cxpFromS1OC3(typename std::enable_if<xenums::S1combs::_cxpFromS1OC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=1, getValue=off, fromValue=cxp
TEST_F(TestS1combs, S1OffCxp)
{
	// getValue=off
	try { success = false; xenums::S1combs::V0.getS1OC(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS1OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS1OC0<void>());
	EXPECT_EQ(true, cxpFromS1OC2<void>());
	EXPECT_EQ(true, cxpFromS1OC3<S1OCv0>(0));
	//EXPECT_EQ(true, cxpFromS1OC3<S1OCv1>(0));
	EXPECT_EQ(true, cxpFromS1OC3<S1OCv2>(0));
	EXPECT_EQ(false, cxpFromS1OC3<S1OCv3>(0));
	EXPECT_EQ(false, cxpFromS1OC3<S1OCv4>(0));
	EXPECT_EQ(false, cxpFromS1OC3<S1OCv5>(0));

	// fromValue
	strval = "1106";
	EXPECT_EQ(true, xenums::S1combs::_fromS1OC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1OC(strval));
	// Not unique
	//strval = "-1103";
	//EXPECT_EQ(true, xenums::S1combs::_fromS1OC(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromS1OC(strval));
	strval = "1107";
	EXPECT_EQ(true, xenums::S1combs::_fromS1OC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1OC(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromS1OC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromS1OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1106";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromS1OC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromS1OC(strval));
	// Not unique
	//strval = "-1103";
	//EXPECT_EQ(true, xenums::S1combs::_cxpFromS1OC(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_cxpFromS1OC(strval));
	strval = "1107";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromS1OC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromS1OC(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_cxpFromS1OC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_cxpFromS1OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=1 get=ext ===============================

/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=off
TEST_F(TestS1combs, S1ExtOff)
{
	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getS1EOSize());
	EXPECT_STREQ("1110", value.getS1EO(0));
	EXPECT_EQ(5, value.getS1EOSize(0));
	EXPECT_STREQ("-1104", value.getS1EO(1));
	EXPECT_EQ(6, value.getS1EOSize(1));
	EXPECT_STREQ("1111", value.getS1EO(2));
	EXPECT_EQ(5, value.getS1EOSize(2));
	try { success = false; value.getS1EO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EOSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getS1EOSize());
	try { success = false; value.getS1EO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EOSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getS1EOSize());
	EXPECT_STREQ("-1104", value.getS1EO(0));
	EXPECT_EQ(6, value.getS1EOSize(0));
	try { success = false; value.getS1EO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EOSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S1combs::_fromS1EO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S1combs::_fromS1EO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=ext
TEST_F(TestS1combs, S1ExtExt)
{
	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getS1EESize());
	EXPECT_STREQ("1112", value.getS1EE(0));
	EXPECT_EQ(5, value.getS1EESize(0));
	EXPECT_STREQ("-1105", value.getS1EE(1));
	EXPECT_EQ(6, value.getS1EESize(1));
	EXPECT_STREQ("1113", value.getS1EE(2));
	EXPECT_EQ(5, value.getS1EESize(2));
	try { success = false; value.getS1EE(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EESize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getS1EESize());
	try { success = false; value.getS1EE(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getS1EESize());
	EXPECT_STREQ("-1105", value.getS1EE(0));
	EXPECT_EQ(6, value.getS1EESize(0));
	try { success = false; value.getS1EE(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1112";
	EXPECT_EQ(true, xenums::S1combs::_fromS1EE(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1EE(strval));
	// Not unique
	//strval = "-1105";
	//EXPECT_EQ(true, xenums::S1combs::_fromS1EE(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromS1EE(strval));
	strval = "1113";
	EXPECT_EQ(true, xenums::S1combs::_fromS1EE(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1EE(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromS1EE(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromS1EE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=inl
TEST_F(TestS1combs, S1ExtInl)
{
	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getS1EISize());
	EXPECT_STREQ("1114", value.getS1EI(0));
	EXPECT_EQ(5, value.getS1EISize(0));
	EXPECT_STREQ("-1106", value.getS1EI(1));
	EXPECT_EQ(6, value.getS1EISize(1));
	EXPECT_STREQ("1115", value.getS1EI(2));
	EXPECT_EQ(5, value.getS1EISize(2));
	try { success = false; value.getS1EI(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EISize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getS1EISize());
	try { success = false; value.getS1EI(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EISize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getS1EISize());
	EXPECT_STREQ("-1106", value.getS1EI(0));
	EXPECT_EQ(6, value.getS1EISize(0));
	try { success = false; value.getS1EI(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EISize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1114";
	EXPECT_EQ(true, xenums::S1combs::_fromS1EI(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1EI(strval));
	// Not unique
	//strval = "-1106";
	//EXPECT_EQ(true, xenums::S1combs::_fromS1EI(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromS1EI(strval));
	strval = "1115";
	EXPECT_EQ(true, xenums::S1combs::_fromS1EI(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1EI(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromS1EI(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromS1EI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Values for testing cxpFromS1EC()
/// @{
constexpr char S1ECv0[] = "1116";
//constexpr char S1ECv1[] = "-1107";
constexpr char S1ECv2[] = "1117";
constexpr char S1ECv3[] = "1115";
constexpr char S1ECv4[] = "1118";
constexpr char S1ECv5[] = "42";
/// @}
/// Function that only compiles if cxpFromS1EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromS1EC(S1ECv0) == xenums::S1combs::V0, bool>::type cxpFromS1EC0(void) { return true; }
/// Function that only compiles if cxpFromS1EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromS1EC(S1ECv2) == xenums::S1combs::V0, bool>::type cxpFromS1EC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromS1EC3(unsigned v) { return false; }
/// Function that only exists if cxpFromS1EC(V) returns with success, and returns true if so; for testing that cxpFromS1EC() fails correctly at compile time.
template<const char* V> bool cxpFromS1EC3(typename std::enable_if<xenums::S1combs::_cxpFromS1EC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=cxp
TEST_F(TestS1combs, S1ExtCxp)
{
	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getS1ECSize());
	EXPECT_STREQ("1116", value.getS1EC(0));
	EXPECT_EQ(5, value.getS1ECSize(0));
	EXPECT_STREQ("-1107", value.getS1EC(1));
	EXPECT_EQ(6, value.getS1ECSize(1));
	EXPECT_STREQ("1117", value.getS1EC(2));
	EXPECT_EQ(5, value.getS1ECSize(2));
	try { success = false; value.getS1EC(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1ECSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getS1ECSize());
	try { success = false; value.getS1EC(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1ECSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getS1ECSize());
	EXPECT_STREQ("-1107", value.getS1EC(0));
	EXPECT_EQ(6, value.getS1ECSize(0));
	try { success = false; value.getS1EC(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1ECSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS1EC0<void>());
	EXPECT_EQ(true, cxpFromS1EC2<void>());
	EXPECT_EQ(true, cxpFromS1EC3<S1ECv0>(0));
	//EXPECT_EQ(true, cxpFromS1EC3<S1ECv1>(0));
	EXPECT_EQ(true, cxpFromS1EC3<S1ECv2>(0));
	EXPECT_EQ(false, cxpFromS1EC3<S1ECv3>(0));
	EXPECT_EQ(false, cxpFromS1EC3<S1ECv4>(0));
	EXPECT_EQ(false, cxpFromS1EC3<S1ECv5>(0));

	// fromValue
	strval = "1116";
	EXPECT_EQ(true, xenums::S1combs::_fromS1EC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1EC(strval));
	// Not unique
	//strval = "-1107";
	//EXPECT_EQ(true, xenums::S1combs::_fromS1EC(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromS1EC(strval));
	strval = "1117";
	EXPECT_EQ(true, xenums::S1combs::_fromS1EC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1EC(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromS1EC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromS1EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1116";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromS1EC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromS1EC(strval));
	// Not unique
	//strval = "-1107";
	//EXPECT_EQ(true, xenums::S1combs::_cxpFromS1EC(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_cxpFromS1EC(strval));
	strval = "1117";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromS1EC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromS1EC(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_cxpFromS1EC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_cxpFromS1EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=1 get=cxp ===============================

/// Function that only compiles if the constexpr getS1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1COSize() == 3, bool>::type cxpGetS1COSize0() { return true; }
/// Function that only compiles if the constexpr getS1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V1.getS1COSize() == 0, bool>::type cxpGetS1COSize1() { return true; }
/// Function that only compiles if the constexpr getS1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getS1COSize() == 1, bool>::type cxpGetS1COSize2() { return true; }

/// Function that only compiles if the constexpr getS1COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1COSize(0) == 5, bool>::type cxpGetS1COSize00() { return true; }
/// Function that only compiles if the constexpr getS1COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1COSize(1) == 6, bool>::type cxpGetS1COSize01() { return true; }
/// Function that only compiles if the constexpr getS1COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1COSize(2) == 5, bool>::type cxpGetS1COSize02() { return true; }
/// Function that only compiles if the constexpr getS1COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getS1COSize(0) == 6, bool>::type cxpGetS1COSize20() { return true; }

/// Function that only compiles if the constexpr getS1CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CO(0), "1120"), bool>::type cxpGetS1CO0(void) { return true; }
/// Function that only compiles if the constexpr getS1CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CO(1), "-1108"), bool>::type cxpGetS1CO1(void) { return true; }
/// Function that only compiles if the constexpr getS1CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CO(2), "1121"), bool>::type cxpGetS1CO2(void) { return true; }
/// Function that only compiles if the constexpr getS1CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V2.getS1CO(0), "-1108"), bool>::type cxpGetS1CO3(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=off
TEST_F(TestS1combs, S1CxpOff)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS1COSize0<void>());
	EXPECT_EQ(true, cxpGetS1COSize1<void>());
	EXPECT_EQ(true, cxpGetS1COSize2<void>());
	EXPECT_EQ(true, cxpGetS1COSize00<void>());
	EXPECT_EQ(true, cxpGetS1COSize01<void>());
	EXPECT_EQ(true, cxpGetS1COSize02<void>());
	EXPECT_EQ(true, cxpGetS1COSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS1CO0<void>());
	EXPECT_EQ(true, cxpGetS1CO1<void>());
	EXPECT_EQ(true, cxpGetS1CO2<void>());
	EXPECT_EQ(true, cxpGetS1CO3<void>());

	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getS1COSize());
	EXPECT_STREQ("1120", value.getS1CO(0));
	EXPECT_EQ(5, value.getS1COSize(0));
	EXPECT_STREQ("-1108", value.getS1CO(1));
	EXPECT_EQ(6, value.getS1COSize(1));
	EXPECT_STREQ("1121", value.getS1CO(2));
	EXPECT_EQ(5, value.getS1COSize(2));
	try { success = false; value.getS1CO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1COSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getS1COSize());
	try { success = false; value.getS1CO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1COSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getS1COSize());
	EXPECT_STREQ("-1108", value.getS1CO(0));
	EXPECT_EQ(6, value.getS1COSize(0));
	try { success = false; value.getS1CO(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1COSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::S1combs::_fromS1CO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::S1combs::_fromS1CO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS1CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CESize() == 3, bool>::type cxpGetS1CESize0() { return true; }
/// Function that only compiles if the constexpr getS1CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V1.getS1CESize() == 0, bool>::type cxpGetS1CESize1() { return true; }
/// Function that only compiles if the constexpr getS1CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getS1CESize() == 1, bool>::type cxpGetS1CESize2() { return true; }

/// Function that only compiles if the constexpr getS1CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CESize(0) == 5, bool>::type cxpGetS1CESize00() { return true; }
/// Function that only compiles if the constexpr getS1CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CESize(1) == 6, bool>::type cxpGetS1CESize01() { return true; }
/// Function that only compiles if the constexpr getS1CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CESize(2) == 5, bool>::type cxpGetS1CESize02() { return true; }
/// Function that only compiles if the constexpr getS1CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getS1CESize(0) == 6, bool>::type cxpGetS1CESize20() { return true; }

/// Function that only compiles if the constexpr getS1CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CE(0), "1122"), bool>::type cxpGetS1CE0(void) { return true; }
/// Function that only compiles if the constexpr getS1CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CE(1), "-1109"), bool>::type cxpGetS1CE1(void) { return true; }
/// Function that only compiles if the constexpr getS1CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CE(2), "1123"), bool>::type cxpGetS1CE2(void) { return true; }
/// Function that only compiles if the constexpr getS1CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V2.getS1CE(0), "-1109"), bool>::type cxpGetS1CE3(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=ext
TEST_F(TestS1combs, S1CxpExt)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS1CESize0<void>());
	EXPECT_EQ(true, cxpGetS1CESize1<void>());
	EXPECT_EQ(true, cxpGetS1CESize2<void>());
	EXPECT_EQ(true, cxpGetS1CESize00<void>());
	EXPECT_EQ(true, cxpGetS1CESize01<void>());
	EXPECT_EQ(true, cxpGetS1CESize02<void>());
	EXPECT_EQ(true, cxpGetS1CESize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS1CE0<void>());
	EXPECT_EQ(true, cxpGetS1CE1<void>());
	EXPECT_EQ(true, cxpGetS1CE2<void>());
	EXPECT_EQ(true, cxpGetS1CE3<void>());

	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getS1CESize());
	EXPECT_STREQ("1122", value.getS1CE(0));
	EXPECT_EQ(5, value.getS1CESize(0));
	EXPECT_STREQ("-1109", value.getS1CE(1));
	EXPECT_EQ(6, value.getS1CESize(1));
	EXPECT_STREQ("1123", value.getS1CE(2));
	EXPECT_EQ(5, value.getS1CESize(2));
	try { success = false; value.getS1CE(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CESize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getS1CESize());
	try { success = false; value.getS1CE(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getS1CESize());
	EXPECT_STREQ("-1109", value.getS1CE(0));
	EXPECT_EQ(6, value.getS1CESize(0));
	try { success = false; value.getS1CE(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CESize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1122";
	EXPECT_EQ(true, xenums::S1combs::_fromS1CE(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1CE(strval));
	// Not unique
	//strval = "-1109";
	//EXPECT_EQ(true, xenums::S1combs::_fromS1CE(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromS1CE(strval));
	strval = "1123";
	EXPECT_EQ(true, xenums::S1combs::_fromS1CE(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1CE(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromS1CE(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromS1CE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS1CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CISize() == 3, bool>::type cxpGetS1CISize0() { return true; }
/// Function that only compiles if the constexpr getS1CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V1.getS1CISize() == 0, bool>::type cxpGetS1CISize1() { return true; }
/// Function that only compiles if the constexpr getS1CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getS1CISize() == 1, bool>::type cxpGetS1CISize2() { return true; }

/// Function that only compiles if the constexpr getS1CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CISize(0) == 5, bool>::type cxpGetS1CISize00() { return true; }
/// Function that only compiles if the constexpr getS1CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CISize(1) == 6, bool>::type cxpGetS1CISize01() { return true; }
/// Function that only compiles if the constexpr getS1CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CISize(2) == 5, bool>::type cxpGetS1CISize02() { return true; }
/// Function that only compiles if the constexpr getS1CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getS1CISize(0) == 6, bool>::type cxpGetS1CISize20() { return true; }

/// Function that only compiles if the constexpr getS1CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CI(0), "1124"), bool>::type cxpGetS1CI0(void) { return true; }
/// Function that only compiles if the constexpr getS1CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CI(1), "-1110"), bool>::type cxpGetS1CI1(void) { return true; }
/// Function that only compiles if the constexpr getS1CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CI(2), "1125"), bool>::type cxpGetS1CI2(void) { return true; }
/// Function that only compiles if the constexpr getS1CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V2.getS1CI(0), "-1110"), bool>::type cxpGetS1CI3(void) { return true; }

/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=inl
TEST_F(TestS1combs, S1CxpInl)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS1CISize0<void>());
	EXPECT_EQ(true, cxpGetS1CISize1<void>());
	EXPECT_EQ(true, cxpGetS1CISize2<void>());
	EXPECT_EQ(true, cxpGetS1CISize00<void>());
	EXPECT_EQ(true, cxpGetS1CISize01<void>());
	EXPECT_EQ(true, cxpGetS1CISize02<void>());
	EXPECT_EQ(true, cxpGetS1CISize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS1CI0<void>());
	EXPECT_EQ(true, cxpGetS1CI1<void>());
	EXPECT_EQ(true, cxpGetS1CI2<void>());
	EXPECT_EQ(true, cxpGetS1CI3<void>());

	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getS1CISize());
	EXPECT_STREQ("1124", value.getS1CI(0));
	EXPECT_EQ(5, value.getS1CISize(0));
	EXPECT_STREQ("-1110", value.getS1CI(1));
	EXPECT_EQ(6, value.getS1CISize(1));
	EXPECT_STREQ("1125", value.getS1CI(2));
	EXPECT_EQ(5, value.getS1CISize(2));
	try { success = false; value.getS1CI(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CISize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getS1CISize());
	try { success = false; value.getS1CI(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CISize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getS1CISize());
	EXPECT_STREQ("-1110", value.getS1CI(0));
	EXPECT_EQ(6, value.getS1CISize(0));
	try { success = false; value.getS1CI(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CISize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1124";
	EXPECT_EQ(true, xenums::S1combs::_fromS1CI(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1CI(strval));
	// Not unique
	//strval = "-1110";
	//EXPECT_EQ(true, xenums::S1combs::_fromS1CI(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromS1CI(strval));
	strval = "1125";
	EXPECT_EQ(true, xenums::S1combs::_fromS1CI(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1CI(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromS1CI(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromS1CI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS1CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CCSize() == 3, bool>::type cxpGetS1CCSize0() { return true; }
/// Function that only compiles if the constexpr getS1CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V1.getS1CCSize() == 0, bool>::type cxpGetS1CCSize1() { return true; }
/// Function that only compiles if the constexpr getS1CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getS1CCSize() == 1, bool>::type cxpGetS1CCSize2() { return true; }

/// Function that only compiles if the constexpr getS1CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CCSize(0) == 5, bool>::type cxpGetS1CCSize00() { return true; }
/// Function that only compiles if the constexpr getS1CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CCSize(1) == 6, bool>::type cxpGetS1CCSize01() { return true; }
/// Function that only compiles if the constexpr getS1CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V0.getS1CCSize(2) == 5, bool>::type cxpGetS1CCSize02() { return true; }
/// Function that only compiles if the constexpr getS1CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::V2.getS1CCSize(0) == 6, bool>::type cxpGetS1CCSize20() { return true; }

/// Function that only compiles if the constexpr getS1CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CC(0), "1126"), bool>::type cxpGetS1CC0(void) { return true; }
/// Function that only compiles if the constexpr getS1CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CC(1), "-1111"), bool>::type cxpGetS1CC1(void) { return true; }
/// Function that only compiles if the constexpr getS1CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V0.getS1CC(2), "1127"), bool>::type cxpGetS1CC2(void) { return true; }
/// Function that only compiles if the constexpr getS1CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::S1combs::V2.getS1CC(0), "-1111"), bool>::type cxpGetS1CC3(void) { return true; }

/// Values for testing cxpFromS1CC()
/// @{
constexpr char S1CCv0[] = "1126";
//constexpr char S1CCv1[] = "-1111";
constexpr char S1CCv2[] = "1127";
constexpr char S1CCv3[] = "1125";
constexpr char S1CCv4[] = "1128";
constexpr char S1CCv5[] = "42";
/// @}
/// Function that only compiles if cxpFromS1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromS1CC(S1CCv0) == xenums::S1combs::V0, bool>::type cxpFromS1CC0(void) { return true; }
/// Function that only compiles if cxpFromS1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::S1combs::_cxpFromS1CC(S1CCv2) == xenums::S1combs::V0, bool>::type cxpFromS1CC2(void) { return true; }
/// Fallback function that always exists and always returns false.
template<const char* V> bool cxpFromS1CC3(unsigned v) { return false; }
/// Function that only exists if cxpFromS1CC(V) returns with success, and returns true if so; for testing that cxpFromS1CC() fails correctly at compile time.
template<const char* V> bool cxpFromS1CC3(typename std::enable_if<xenums::S1combs::_cxpFromS1CC(V).toTrue(), int>::type) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=cxp
TEST_F(TestS1combs, S1CxpCxp)
{
	// getValueSize() at compile time
	EXPECT_EQ(true, cxpGetS1CCSize0<void>());
	EXPECT_EQ(true, cxpGetS1CCSize1<void>());
	EXPECT_EQ(true, cxpGetS1CCSize2<void>());
	EXPECT_EQ(true, cxpGetS1CCSize00<void>());
	EXPECT_EQ(true, cxpGetS1CCSize01<void>());
	EXPECT_EQ(true, cxpGetS1CCSize02<void>());
	EXPECT_EQ(true, cxpGetS1CCSize20<void>());
	// getValue() at compile time
	EXPECT_EQ(true, cxpGetS1CC0<void>());
	EXPECT_EQ(true, cxpGetS1CC1<void>());
	EXPECT_EQ(true, cxpGetS1CC2<void>());
	EXPECT_EQ(true, cxpGetS1CC3<void>());

	// getValue()
	// V0
	value = xenums::S1combs::V0;
	EXPECT_EQ(3, value.getS1CCSize());
	EXPECT_STREQ("1126", value.getS1CC(0));
	EXPECT_EQ(5, value.getS1CCSize(0));
	EXPECT_STREQ("-1111", value.getS1CC(1));
	EXPECT_EQ(6, value.getS1CCSize(1));
	EXPECT_STREQ("1127", value.getS1CC(2));
	EXPECT_EQ(5, value.getS1CCSize(2));
	try { success = false; value.getS1CC(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CCSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::S1combs::V1;
	EXPECT_EQ(0, value.getS1CCSize());
	try { success = false; value.getS1CC(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CCSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::S1combs::V2;
	EXPECT_EQ(1, value.getS1CCSize());
	EXPECT_STREQ("-1111", value.getS1CC(0));
	EXPECT_EQ(6, value.getS1CCSize(0));
	try { success = false; value.getS1CC(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CCSize(1); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS1CC0<void>());
	EXPECT_EQ(true, cxpFromS1CC2<void>());
	EXPECT_EQ(true, cxpFromS1CC3<S1CCv0>(0));
	//EXPECT_EQ(true, cxpFromS1CC3<S1CCv1>(0));
	EXPECT_EQ(true, cxpFromS1CC3<S1CCv2>(0));
	EXPECT_EQ(false, cxpFromS1CC3<S1CCv3>(0));
	EXPECT_EQ(false, cxpFromS1CC3<S1CCv4>(0));
	EXPECT_EQ(false, cxpFromS1CC3<S1CCv5>(0));

	// fromValue
	strval = "1126";
	EXPECT_EQ(true, xenums::S1combs::_fromS1CC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1CC(strval));
	// Not unique
	//strval = "-1111";
	//EXPECT_EQ(true, xenums::S1combs::_fromS1CC(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_fromS1CC(strval));
	strval = "1127";
	EXPECT_EQ(true, xenums::S1combs::_fromS1CC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_fromS1CC(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_fromS1CC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_fromS1CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1126";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromS1CC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromS1CC(strval));
	// Not unique
	//strval = "-1111";
	//EXPECT_EQ(true, xenums::S1combs::_cxpFromS1CC(strval, value));
	//EXPECT_EQ(value, xenums::S1combs::V0|V2);
	//EXPECT_EQ(value, xenums::S1combs::_cxpFromS1CC(strval));
	strval = "1127";
	EXPECT_EQ(true, xenums::S1combs::_cxpFromS1CC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V0);
	EXPECT_EQ(value, xenums::S1combs::_cxpFromS1CC(strval));

	value = xenums::S1combs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::S1combs::_cxpFromS1CC(strval, value));
	EXPECT_EQ(value, xenums::S1combs::V2);
	try { success = false; xenums::S1combs::_cxpFromS1CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
