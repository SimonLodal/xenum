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
	const char* strval;
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
	try { success = false; xenums::Scombs::V0.getS0OO(); }
	catch (std::logic_error e) { EXPECT_STREQ("getS0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::Scombs::_fromS0OO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Scombs::_fromS0OO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=off, fromValue=ext
TEST_F(TestScombs, S0OffExt)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS0OE(); }
	catch (std::logic_error e) { EXPECT_STREQ("getS0OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1001";
	EXPECT_EQ(true, xenums::Scombs::_fromS0OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS0OE(strval));
	strval = "-1001";
	EXPECT_EQ(true, xenums::Scombs::_fromS0OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_fromS0OE(strval));
	strval = "1021";
	EXPECT_EQ(true, xenums::Scombs::_fromS0OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_fromS0OE(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS0OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS0OE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=off, fromValue=inl
TEST_F(TestScombs, S0OffInl)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS0OI(); }
	catch (std::logic_error e) { EXPECT_STREQ("getS0OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1002";
	EXPECT_EQ(true, xenums::Scombs::_fromS0OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS0OI(strval));
	strval = "-1002";
	EXPECT_EQ(true, xenums::Scombs::_fromS0OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_fromS0OI(strval));
	strval = "1022";
	EXPECT_EQ(true, xenums::Scombs::_fromS0OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_fromS0OI(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS0OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS0OI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromS0OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS0OC("1003") == xenums::Scombs::V0, bool>::type cxpFromS0OC0(void) { return true; }
/// Function that only compiles if cxpFromS0OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS0OC("-1003") == xenums::Scombs::V1, bool>::type cxpFromS0OC1(void) { return true; }
/// Function that only compiles if cxpFromS0OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS0OC("1023") == xenums::Scombs::V2, bool>::type cxpFromS0OC2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=off, fromValue=cxp
TEST_F(TestScombs, S0OffCxp)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS0OC(); }
	catch (std::logic_error e) { EXPECT_STREQ("getS0OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS0OC0<void>());
	EXPECT_EQ(true, cxpFromS0OC1<void>());
	EXPECT_EQ(true, cxpFromS0OC2<void>());

	// fromValue
	strval = "1003";
	EXPECT_EQ(true, xenums::Scombs::_fromS0OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS0OC(strval));
	strval = "-1003";
	EXPECT_EQ(true, xenums::Scombs::_fromS0OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_fromS0OC(strval));
	strval = "1023";
	EXPECT_EQ(true, xenums::Scombs::_fromS0OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_fromS0OC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS0OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS0OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1003";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS0OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS0OC(strval));
	strval = "-1003";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS0OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS0OC(strval));
	strval = "1023";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS0OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS0OC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_cxpFromS0OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_cxpFromS0OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
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
	try { success = false; xenums::Scombs::_fromS0EO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Scombs::_fromS0EO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=ext
TEST_F(TestScombs, S0ExtExt)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
	EXPECT_STREQ("1005", value.getS0EE());
	EXPECT_EQ(5, value.getS0EESize());
	// V1
	value = xenums::Scombs::V1;
	EXPECT_STREQ("-1005", value.getS0EE());
	EXPECT_EQ(6, value.getS0EESize());
	// V2
	value = xenums::Scombs::V2;
	EXPECT_STREQ("1025", value.getS0EE());
	EXPECT_EQ(5, value.getS0EESize());

	// fromValue
	strval = "1005";
	EXPECT_EQ(true, xenums::Scombs::_fromS0EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS0EE(strval));
	strval = "-1005";
	EXPECT_EQ(true, xenums::Scombs::_fromS0EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_fromS0EE(strval));
	strval = "1025";
	EXPECT_EQ(true, xenums::Scombs::_fromS0EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_fromS0EE(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS0EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS0EE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=inl
TEST_F(TestScombs, S0ExtInl)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
	EXPECT_STREQ("1006", value.getS0EI());
	EXPECT_EQ(5, value.getS0EISize());
	// V1
	value = xenums::Scombs::V1;
	EXPECT_STREQ("-1006", value.getS0EI());
	EXPECT_EQ(6, value.getS0EISize());
	// V2
	value = xenums::Scombs::V2;
	EXPECT_STREQ("1026", value.getS0EI());
	EXPECT_EQ(5, value.getS0EISize());

	// fromValue
	strval = "1006";
	EXPECT_EQ(true, xenums::Scombs::_fromS0EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS0EI(strval));
	strval = "-1006";
	EXPECT_EQ(true, xenums::Scombs::_fromS0EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_fromS0EI(strval));
	strval = "1026";
	EXPECT_EQ(true, xenums::Scombs::_fromS0EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_fromS0EI(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS0EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS0EI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromS0EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS0EC("1007") == xenums::Scombs::V0, bool>::type cxpFromS0EC0(void) { return true; }
/// Function that only compiles if cxpFromS0EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS0EC("-1007") == xenums::Scombs::V1, bool>::type cxpFromS0EC1(void) { return true; }
/// Function that only compiles if cxpFromS0EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS0EC("1027") == xenums::Scombs::V2, bool>::type cxpFromS0EC2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=ext, fromValue=cxp
TEST_F(TestScombs, S0ExtCxp)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
	EXPECT_STREQ("1007", value.getS0EC());
	EXPECT_EQ(5, value.getS0ECSize());
	// V1
	value = xenums::Scombs::V1;
	EXPECT_STREQ("-1007", value.getS0EC());
	EXPECT_EQ(6, value.getS0ECSize());
	// V2
	value = xenums::Scombs::V2;
	EXPECT_STREQ("1027", value.getS0EC());
	EXPECT_EQ(5, value.getS0ECSize());

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS0EC0<void>());
	EXPECT_EQ(true, cxpFromS0EC1<void>());
	EXPECT_EQ(true, cxpFromS0EC2<void>());

	// fromValue
	strval = "1007";
	EXPECT_EQ(true, xenums::Scombs::_fromS0EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS0EC(strval));
	strval = "-1007";
	EXPECT_EQ(true, xenums::Scombs::_fromS0EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_fromS0EC(strval));
	strval = "1027";
	EXPECT_EQ(true, xenums::Scombs::_fromS0EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_fromS0EC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS0EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS0EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1007";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS0EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS0EC(strval));
	strval = "-1007";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS0EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS0EC(strval));
	strval = "1027";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS0EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS0EC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_cxpFromS0EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_cxpFromS0EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=0 get=cxp ===============================

/// Function that only compiles if the constexpr getS0COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS0COSize() == 5, bool>::type cxpGetS0COSize0() { return true; }
/// Function that only compiles if the constexpr getS0COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS0COSize() == 6, bool>::type cxpGetS0COSize1() { return true; }
/// Function that only compiles if the constexpr getS0COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS0COSize() == 5, bool>::type cxpGetS0COSize2() { return true; }
/// Function that only compiles if the constexpr getS0CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS0CO(), "1008"), bool>::type cxpGetS0CO0(void) { return true; }
/// Function that only compiles if the constexpr getS0CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V1.getS0CO(), "-1008"), bool>::type cxpGetS0CO1(void) { return true; }
/// Function that only compiles if the constexpr getS0CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V2.getS0CO(), "1028"), bool>::type cxpGetS0CO2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=off
TEST_F(TestScombs, S0CxpOff)
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
	try { success = false; xenums::Scombs::_fromS0CO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Scombs::_fromS0CO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS0CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS0CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS0CESize() == 5, bool>::type cxpGetS0CESize0() { return true; }
/// Function that only compiles if the constexpr getS0CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS0CESize() == 6, bool>::type cxpGetS0CESize1() { return true; }
/// Function that only compiles if the constexpr getS0CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS0CESize() == 5, bool>::type cxpGetS0CESize2() { return true; }
/// Function that only compiles if the constexpr getS0CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS0CE(), "1009"), bool>::type cxpGetS0CE0(void) { return true; }
/// Function that only compiles if the constexpr getS0CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V1.getS0CE(), "-1009"), bool>::type cxpGetS0CE1(void) { return true; }
/// Function that only compiles if the constexpr getS0CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V2.getS0CE(), "1029"), bool>::type cxpGetS0CE2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=ext
TEST_F(TestScombs, S0CxpExt)
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
	value = xenums::Scombs::V0;
	EXPECT_STREQ("1009", value.getS0CE());
	EXPECT_EQ(5, value.getS0CESize());
	// V1
	value = xenums::Scombs::V1;
	EXPECT_STREQ("-1009", value.getS0CE());
	EXPECT_EQ(6, value.getS0CESize());
	// V2
	value = xenums::Scombs::V2;
	EXPECT_STREQ("1029", value.getS0CE());
	EXPECT_EQ(5, value.getS0CESize());

	// fromValue
	strval = "1009";
	EXPECT_EQ(true, xenums::Scombs::_fromS0CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS0CE(strval));
	strval = "-1009";
	EXPECT_EQ(true, xenums::Scombs::_fromS0CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_fromS0CE(strval));
	strval = "1029";
	EXPECT_EQ(true, xenums::Scombs::_fromS0CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_fromS0CE(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS0CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS0CE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS0CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS0CISize() == 5, bool>::type cxpGetS0CISize0() { return true; }
/// Function that only compiles if the constexpr getS0CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS0CISize() == 6, bool>::type cxpGetS0CISize1() { return true; }
/// Function that only compiles if the constexpr getS0CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS0CISize() == 5, bool>::type cxpGetS0CISize2() { return true; }
/// Function that only compiles if the constexpr getS0CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS0CI(), "1010"), bool>::type cxpGetS0CI0(void) { return true; }
/// Function that only compiles if the constexpr getS0CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V1.getS0CI(), "-1010"), bool>::type cxpGetS0CI1(void) { return true; }
/// Function that only compiles if the constexpr getS0CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V2.getS0CI(), "1030"), bool>::type cxpGetS0CI2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=inl
TEST_F(TestScombs, S0CxpInl)
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
	value = xenums::Scombs::V0;
	EXPECT_STREQ("1010", value.getS0CI());
	EXPECT_EQ(5, value.getS0CISize());
	// V1
	value = xenums::Scombs::V1;
	EXPECT_STREQ("-1010", value.getS0CI());
	EXPECT_EQ(6, value.getS0CISize());
	// V2
	value = xenums::Scombs::V2;
	EXPECT_STREQ("1030", value.getS0CI());
	EXPECT_EQ(5, value.getS0CISize());

	// fromValue
	strval = "1010";
	EXPECT_EQ(true, xenums::Scombs::_fromS0CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS0CI(strval));
	strval = "-1010";
	EXPECT_EQ(true, xenums::Scombs::_fromS0CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_fromS0CI(strval));
	strval = "1030";
	EXPECT_EQ(true, xenums::Scombs::_fromS0CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_fromS0CI(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS0CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS0CI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS0CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS0CCSize() == 5, bool>::type cxpGetS0CCSize0() { return true; }
/// Function that only compiles if the constexpr getS0CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS0CCSize() == 6, bool>::type cxpGetS0CCSize1() { return true; }
/// Function that only compiles if the constexpr getS0CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS0CCSize() == 5, bool>::type cxpGetS0CCSize2() { return true; }
/// Function that only compiles if the constexpr getS0CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS0CC(), "1011"), bool>::type cxpGetS0CC0(void) { return true; }
/// Function that only compiles if the constexpr getS0CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V1.getS0CC(), "-1011"), bool>::type cxpGetS0CC1(void) { return true; }
/// Function that only compiles if the constexpr getS0CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V2.getS0CC(), "1031"), bool>::type cxpGetS0CC2(void) { return true; }
/// Function that only compiles if cxpFromS0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS0CC("1011") == xenums::Scombs::V0, bool>::type cxpFromS0CC0(void) { return true; }
/// Function that only compiles if cxpFromS0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS0CC("-1011") == xenums::Scombs::V1, bool>::type cxpFromS0CC1(void) { return true; }
/// Function that only compiles if cxpFromS0CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS0CC("1031") == xenums::Scombs::V2, bool>::type cxpFromS0CC2(void) { return true; }
/// Test xenum with identifier features: depth=0, getValue=cxp, fromValue=cxp
TEST_F(TestScombs, S0CxpCxp)
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
	value = xenums::Scombs::V0;
	EXPECT_STREQ("1011", value.getS0CC());
	EXPECT_EQ(5, value.getS0CCSize());
	// V1
	value = xenums::Scombs::V1;
	EXPECT_STREQ("-1011", value.getS0CC());
	EXPECT_EQ(6, value.getS0CCSize());
	// V2
	value = xenums::Scombs::V2;
	EXPECT_STREQ("1031", value.getS0CC());
	EXPECT_EQ(5, value.getS0CCSize());

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS0CC0<void>());
	EXPECT_EQ(true, cxpFromS0CC1<void>());
	EXPECT_EQ(true, cxpFromS0CC2<void>());

	// fromValue
	strval = "1011";
	EXPECT_EQ(true, xenums::Scombs::_fromS0CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS0CC(strval));
	strval = "-1011";
	EXPECT_EQ(true, xenums::Scombs::_fromS0CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_fromS0CC(strval));
	strval = "1031";
	EXPECT_EQ(true, xenums::Scombs::_fromS0CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_fromS0CC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS0CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS0CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1011";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS0CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS0CC(strval));
	strval = "-1011";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS0CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V1);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS0CC(strval));
	strval = "1031";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS0CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS0CC(strval));
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_cxpFromS0CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_cxpFromS0CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S0CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= Depth=1 ============================================
// =========================== depth=1 get=off ===============================

/// Test xenum with identifier features: depth=1, getValue=off, fromValue=off
TEST_F(TestScombs, S1OffOff)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS1OO(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::Scombs::_fromS1OO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Scombs::_fromS1OO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=off, fromValue=ext
TEST_F(TestScombs, S1OffExt)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS1OE(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS1OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1102";
	EXPECT_EQ(true, xenums::Scombs::_fromS1OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1OE(strval));
	// Not unique
	//strval = "-1101";
	//EXPECT_EQ(true, xenums::Scombs::_fromS1OE(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_fromS1OE(strval));
	strval = "1103";
	EXPECT_EQ(true, xenums::Scombs::_fromS1OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1OE(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS1OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS1OE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=off, fromValue=inl
TEST_F(TestScombs, S1OffInl)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS1OI(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS1OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1104";
	EXPECT_EQ(true, xenums::Scombs::_fromS1OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1OI(strval));
	// Not unique
	//strval = "-1102";
	//EXPECT_EQ(true, xenums::Scombs::_fromS1OI(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_fromS1OI(strval));
	strval = "1105";
	EXPECT_EQ(true, xenums::Scombs::_fromS1OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1OI(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS1OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS1OI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromS1OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS1OC("1106") == xenums::Scombs::V0, bool>::type cxpFromS1OC0(void) { return true; }
/// Function that only compiles if cxpFromS1OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS1OC("1107") == xenums::Scombs::V0, bool>::type cxpFromS1OC1(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=off, fromValue=cxp
TEST_F(TestScombs, S1OffCxp)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS1OC(0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS1OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS1OC0<void>());
	EXPECT_EQ(true, cxpFromS1OC1<void>());

	// fromValue
	strval = "1106";
	EXPECT_EQ(true, xenums::Scombs::_fromS1OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1OC(strval));
	// Not unique
	//strval = "-1103";
	//EXPECT_EQ(true, xenums::Scombs::_fromS1OC(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_fromS1OC(strval));
	strval = "1107";
	EXPECT_EQ(true, xenums::Scombs::_fromS1OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1OC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS1OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS1OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1106";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS1OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS1OC(strval));
	// Not unique
	//strval = "-1103";
	//EXPECT_EQ(true, xenums::Scombs::_cxpFromS1OC(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_cxpFromS1OC(strval));
	strval = "1107";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS1OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS1OC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_cxpFromS1OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_cxpFromS1OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
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
	try { success = false; value.getS1EO(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EOSize(3); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V1
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1EOSize());
	try { success = false; value.getS1EO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EOSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Scombs::V2;
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
	try { success = false; xenums::Scombs::_fromS1EO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Scombs::_fromS1EO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=ext
TEST_F(TestScombs, S1ExtExt)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1EESize());
	try { success = false; value.getS1EE(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Scombs::V2;
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
	EXPECT_EQ(true, xenums::Scombs::_fromS1EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1EE(strval));
	// Not unique
	//strval = "-1105";
	//EXPECT_EQ(true, xenums::Scombs::_fromS1EE(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_fromS1EE(strval));
	strval = "1113";
	EXPECT_EQ(true, xenums::Scombs::_fromS1EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1EE(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS1EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS1EE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=inl
TEST_F(TestScombs, S1ExtInl)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1EISize());
	try { success = false; value.getS1EI(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1EISize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Scombs::V2;
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
	EXPECT_EQ(true, xenums::Scombs::_fromS1EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1EI(strval));
	// Not unique
	//strval = "-1106";
	//EXPECT_EQ(true, xenums::Scombs::_fromS1EI(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_fromS1EI(strval));
	strval = "1115";
	EXPECT_EQ(true, xenums::Scombs::_fromS1EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1EI(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS1EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS1EI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromS1EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS1EC("1116") == xenums::Scombs::V0, bool>::type cxpFromS1EC0(void) { return true; }
/// Function that only compiles if cxpFromS1EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS1EC("1117") == xenums::Scombs::V0, bool>::type cxpFromS1EC1(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=ext, fromValue=cxp
TEST_F(TestScombs, S1ExtCxp)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1ECSize());
	try { success = false; value.getS1EC(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1ECSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Scombs::V2;
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
	EXPECT_EQ(true, cxpFromS1EC1<void>());

	// fromValue
	strval = "1116";
	EXPECT_EQ(true, xenums::Scombs::_fromS1EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1EC(strval));
	// Not unique
	//strval = "-1107";
	//EXPECT_EQ(true, xenums::Scombs::_fromS1EC(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_fromS1EC(strval));
	strval = "1117";
	EXPECT_EQ(true, xenums::Scombs::_fromS1EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1EC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS1EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS1EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1116";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS1EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS1EC(strval));
	// Not unique
	//strval = "-1107";
	//EXPECT_EQ(true, xenums::Scombs::_cxpFromS1EC(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_cxpFromS1EC(strval));
	strval = "1117";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS1EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS1EC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_cxpFromS1EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_cxpFromS1EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=1 get=cxp ===============================

/// Function that only compiles if the constexpr getS1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1COSize() == 3, bool>::type cxpGetS1COSize0() { return true; }
/// Function that only compiles if the constexpr getS1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS1COSize() == 0, bool>::type cxpGetS1COSize1() { return true; }
/// Function that only compiles if the constexpr getS1COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS1COSize() == 1, bool>::type cxpGetS1COSize2() { return true; }

/// Function that only compiles if the constexpr getS1COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1COSize(0) == 5, bool>::type cxpGetS1COSize00() { return true; }
/// Function that only compiles if the constexpr getS1COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1COSize(1) == 6, bool>::type cxpGetS1COSize01() { return true; }
/// Function that only compiles if the constexpr getS1COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1COSize(2) == 5, bool>::type cxpGetS1COSize02() { return true; }
/// Function that only compiles if the constexpr getS1COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS1COSize(0) == 6, bool>::type cxpGetS1COSize20() { return true; }

/// Function that only compiles if the constexpr getS1CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CO(0), "1120"), bool>::type cxpGetS1CO0(void) { return true; }
/// Function that only compiles if the constexpr getS1CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CO(1), "-1108"), bool>::type cxpGetS1CO1(void) { return true; }
/// Function that only compiles if the constexpr getS1CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CO(2), "1121"), bool>::type cxpGetS1CO2(void) { return true; }
/// Function that only compiles if the constexpr getS1CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V2.getS1CO(0), "-1108"), bool>::type cxpGetS1CO3(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=off
TEST_F(TestScombs, S1CxpOff)
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
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1COSize());
	try { success = false; value.getS1CO(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1COSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Scombs::V2;
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
	try { success = false; xenums::Scombs::_fromS1CO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Scombs::_fromS1CO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS1CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS1CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CESize() == 3, bool>::type cxpGetS1CESize0() { return true; }
/// Function that only compiles if the constexpr getS1CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS1CESize() == 0, bool>::type cxpGetS1CESize1() { return true; }
/// Function that only compiles if the constexpr getS1CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS1CESize() == 1, bool>::type cxpGetS1CESize2() { return true; }

/// Function that only compiles if the constexpr getS1CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CESize(0) == 5, bool>::type cxpGetS1CESize00() { return true; }
/// Function that only compiles if the constexpr getS1CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CESize(1) == 6, bool>::type cxpGetS1CESize01() { return true; }
/// Function that only compiles if the constexpr getS1CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CESize(2) == 5, bool>::type cxpGetS1CESize02() { return true; }
/// Function that only compiles if the constexpr getS1CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS1CESize(0) == 6, bool>::type cxpGetS1CESize20() { return true; }

/// Function that only compiles if the constexpr getS1CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CE(0), "1122"), bool>::type cxpGetS1CE0(void) { return true; }
/// Function that only compiles if the constexpr getS1CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CE(1), "-1109"), bool>::type cxpGetS1CE1(void) { return true; }
/// Function that only compiles if the constexpr getS1CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CE(2), "1123"), bool>::type cxpGetS1CE2(void) { return true; }
/// Function that only compiles if the constexpr getS1CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V2.getS1CE(0), "-1109"), bool>::type cxpGetS1CE3(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=ext
TEST_F(TestScombs, S1CxpExt)
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
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1CESize());
	try { success = false; value.getS1CE(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CESize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Scombs::V2;
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
	EXPECT_EQ(true, xenums::Scombs::_fromS1CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1CE(strval));
	// Not unique
	//strval = "-1109";
	//EXPECT_EQ(true, xenums::Scombs::_fromS1CE(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_fromS1CE(strval));
	strval = "1123";
	EXPECT_EQ(true, xenums::Scombs::_fromS1CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1CE(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS1CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS1CE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS1CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CISize() == 3, bool>::type cxpGetS1CISize0() { return true; }
/// Function that only compiles if the constexpr getS1CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS1CISize() == 0, bool>::type cxpGetS1CISize1() { return true; }
/// Function that only compiles if the constexpr getS1CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS1CISize() == 1, bool>::type cxpGetS1CISize2() { return true; }

/// Function that only compiles if the constexpr getS1CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CISize(0) == 5, bool>::type cxpGetS1CISize00() { return true; }
/// Function that only compiles if the constexpr getS1CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CISize(1) == 6, bool>::type cxpGetS1CISize01() { return true; }
/// Function that only compiles if the constexpr getS1CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CISize(2) == 5, bool>::type cxpGetS1CISize02() { return true; }
/// Function that only compiles if the constexpr getS1CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS1CISize(0) == 6, bool>::type cxpGetS1CISize20() { return true; }

/// Function that only compiles if the constexpr getS1CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CI(0), "1124"), bool>::type cxpGetS1CI0(void) { return true; }
/// Function that only compiles if the constexpr getS1CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CI(1), "-1110"), bool>::type cxpGetS1CI1(void) { return true; }
/// Function that only compiles if the constexpr getS1CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CI(2), "1125"), bool>::type cxpGetS1CI2(void) { return true; }
/// Function that only compiles if the constexpr getS1CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V2.getS1CI(0), "-1110"), bool>::type cxpGetS1CI3(void) { return true; }

/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=inl
TEST_F(TestScombs, S1CxpInl)
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
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1CISize());
	try { success = false; value.getS1CI(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CISize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Scombs::V2;
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
	EXPECT_EQ(true, xenums::Scombs::_fromS1CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1CI(strval));
	// Not unique
	//strval = "-1110";
	//EXPECT_EQ(true, xenums::Scombs::_fromS1CI(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_fromS1CI(strval));
	strval = "1125";
	EXPECT_EQ(true, xenums::Scombs::_fromS1CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1CI(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS1CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS1CI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS1CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CCSize() == 3, bool>::type cxpGetS1CCSize0() { return true; }
/// Function that only compiles if the constexpr getS1CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS1CCSize() == 0, bool>::type cxpGetS1CCSize1() { return true; }
/// Function that only compiles if the constexpr getS1CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS1CCSize() == 1, bool>::type cxpGetS1CCSize2() { return true; }

/// Function that only compiles if the constexpr getS1CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CCSize(0) == 5, bool>::type cxpGetS1CCSize00() { return true; }
/// Function that only compiles if the constexpr getS1CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CCSize(1) == 6, bool>::type cxpGetS1CCSize01() { return true; }
/// Function that only compiles if the constexpr getS1CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS1CCSize(2) == 5, bool>::type cxpGetS1CCSize02() { return true; }
/// Function that only compiles if the constexpr getS1CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS1CCSize(0) == 6, bool>::type cxpGetS1CCSize20() { return true; }

/// Function that only compiles if the constexpr getS1CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CC(0), "1126"), bool>::type cxpGetS1CC0(void) { return true; }
/// Function that only compiles if the constexpr getS1CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CC(1), "-1111"), bool>::type cxpGetS1CC1(void) { return true; }
/// Function that only compiles if the constexpr getS1CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS1CC(2), "1127"), bool>::type cxpGetS1CC2(void) { return true; }
/// Function that only compiles if the constexpr getS1CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V2.getS1CC(0), "-1111"), bool>::type cxpGetS1CC3(void) { return true; }

/// Function that only compiles if cxpFromS1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS1CC("1126") == xenums::Scombs::V0, bool>::type cxpFromS1CC0(void) { return true; }
/// Function that only compiles if cxpFromS1CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS1CC("1127") == xenums::Scombs::V0, bool>::type cxpFromS1CC1(void) { return true; }
/// Test xenum with identifier features: depth=1, getValue=cxp, fromValue=cxp
TEST_F(TestScombs, S1CxpCxp)
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
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
	EXPECT_EQ(0, value.getS1CCSize());
	try { success = false; value.getS1CC(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; value.getS1CCSize(0); }
	catch (std::out_of_range e) { EXPECT_STREQ("Offset >= size", e.what()); success = true; }
	EXPECT_EQ(true, success);
	// V2
	value = xenums::Scombs::V2;
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
	EXPECT_EQ(true, cxpFromS1CC1<void>());

	// fromValue
	strval = "1126";
	EXPECT_EQ(true, xenums::Scombs::_fromS1CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1CC(strval));
	// Not unique
	//strval = "-1111";
	//EXPECT_EQ(true, xenums::Scombs::_fromS1CC(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_fromS1CC(strval));
	strval = "1127";
	EXPECT_EQ(true, xenums::Scombs::_fromS1CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS1CC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS1CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS1CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1126";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS1CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS1CC(strval));
	// Not unique
	//strval = "-1111";
	//EXPECT_EQ(true, xenums::Scombs::_cxpFromS1CC(strval, value));
	//EXPECT_EQ(value, xenums::Scombs::V0|V2);
	//EXPECT_EQ(value, xenums::Scombs::_cxpFromS1CC(strval));
	strval = "1127";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS1CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS1CC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_cxpFromS1CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_cxpFromS1CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S1CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// ========================================= Depth=2 ============================================
// =========================== depth=2 get=off ===============================

/// Test xenum with identifier features: depth=2, getValue=off, fromValue=off
TEST_F(TestScombs, S2OffOff)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS2OO(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue=off
	try { success = false; xenums::Scombs::_fromS2OO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Scombs::_fromS2OO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2OO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=off, fromValue=ext
TEST_F(TestScombs, S2OffExt)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS2OE(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS2OE() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1202";
	EXPECT_EQ(true, xenums::Scombs::_fromS2OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2OE(strval));
	strval = "1203";
	EXPECT_EQ(true, xenums::Scombs::_fromS2OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2OE(strval));
	// Not unique, but both are in V0.
	strval = "-1201";
	EXPECT_EQ(true, xenums::Scombs::_fromS2OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2OE(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS2OE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS2OE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2OE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=off, fromValue=inl
TEST_F(TestScombs, S2OffInl)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS2OI(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS2OI() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromValue
	strval = "1204";
	EXPECT_EQ(true, xenums::Scombs::_fromS2OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2OI(strval));
	strval = "1205";
	EXPECT_EQ(true, xenums::Scombs::_fromS2OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2OI(strval));
	// Not unique, but both are in V0.
	strval = "-1202";
	EXPECT_EQ(true, xenums::Scombs::_fromS2OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2OI(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS2OI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS2OI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2OI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromS2OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS2OC("1206") == xenums::Scombs::V0, bool>::type cxpFromS2OC0(void) { return true; }
/// Function that only compiles if cxpFromS2OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS2OC("1207") == xenums::Scombs::V0, bool>::type cxpFromS2OC1(void) { return true; }
/// Function that only compiles if cxpFromS2OC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS2OC("-1203") == xenums::Scombs::V0, bool>::type cxpFromS2OC2(void) { return true; }
/// Test xenum with identifier features: depth=2, getValue=off, fromValue=cxp
TEST_F(TestScombs, S2OffCxp)
{
	// getValue=off
	try { success = false; xenums::Scombs::V0.getS2OC(0, 0); }
	catch (std::logic_error e) { EXPECT_STREQ("getS2OC() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at compile time
	EXPECT_EQ(true, cxpFromS2OC0<void>());
	EXPECT_EQ(true, cxpFromS2OC1<void>());
	EXPECT_EQ(true, cxpFromS2OC2<void>());

	// fromValue
	strval = "1206";
	EXPECT_EQ(true, xenums::Scombs::_fromS2OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2OC(strval));
	strval = "1207";
	EXPECT_EQ(true, xenums::Scombs::_fromS2OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2OC(strval));
	// Not unique, but both are in V0.
	strval = "-1203";
	EXPECT_EQ(true, xenums::Scombs::_fromS2OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2OC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS2OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS2OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1206";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS2OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS2OC(strval));
	strval = "1207";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS2OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS2OC(strval));
	// Not unique, but both are in V0.
	strval = "-1203";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS2OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS2OC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_cxpFromS2OC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_cxpFromS2OC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2OC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
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
	value = xenums::Scombs::V1;
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
	value = xenums::Scombs::V2;
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
	try { success = false; xenums::Scombs::_fromS2EO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Scombs::_fromS2EO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2EO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=ext
TEST_F(TestScombs, S2ExtExt)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
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
	value = xenums::Scombs::V2;
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
	EXPECT_EQ(true, xenums::Scombs::_fromS2EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2EE(strval));
	strval = "1213";
	EXPECT_EQ(true, xenums::Scombs::_fromS2EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2EE(strval));
	// Not unique, but both are in V0.
	strval = "-1205";
	EXPECT_EQ(true, xenums::Scombs::_fromS2EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2EE(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS2EE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS2EE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2EE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=inl
TEST_F(TestScombs, S2ExtInl)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
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
	value = xenums::Scombs::V2;
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
	EXPECT_EQ(true, xenums::Scombs::_fromS2EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2EI(strval));
	strval = "1215";
	EXPECT_EQ(true, xenums::Scombs::_fromS2EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2EI(strval));
	// Not unique, but both are in V0.
	strval = "-1206";
	EXPECT_EQ(true, xenums::Scombs::_fromS2EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2EI(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS2EI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS2EI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2EI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if cxpFromS2EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS2EC("1216") == xenums::Scombs::V0, bool>::type cxpFromS2EC0(void) { return true; }
/// Function that only compiles if cxpFromS2EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS2EC("1217") == xenums::Scombs::V0, bool>::type cxpFromS2EC1(void) { return true; }
/// Function that only compiles if cxpFromS2EC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS2EC("-1207") == xenums::Scombs::V0, bool>::type cxpFromS2EC2(void) { return true; }
/// Test xenum with identifier features: depth=2, getValue=ext, fromValue=cxp
TEST_F(TestScombs, S2ExtCxp)
{
	// getValue()
	// V0
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
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
	value = xenums::Scombs::V2;
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

	// fromValue
	strval = "1216";
	EXPECT_EQ(true, xenums::Scombs::_fromS2EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2EC(strval));
	strval = "1217";
	EXPECT_EQ(true, xenums::Scombs::_fromS2EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2EC(strval));
	// Not unique, but both are in V0.
	strval = "-1207";
	EXPECT_EQ(true, xenums::Scombs::_fromS2EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2EC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS2EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS2EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1216";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS2EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS2EC(strval));
	strval = "1217";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS2EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS2EC(strval));
	// Not unique, but both are in V0.
	strval = "-1207";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS2EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS2EC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_cxpFromS2EC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_cxpFromS2EC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2EC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



// =========================== depth=2 get=cxp ===============================

/// Function that only compiles if the constexpr getS2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize() == 2, bool>::type cxpGetS2COSize0() { return true; }
/// Function that only compiles if the constexpr getS2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS2COSize() == 0, bool>::type cxpGetS2COSize1() { return true; }
/// Function that only compiles if the constexpr getS2COSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS2COSize() == 1, bool>::type cxpGetS2COSize2() { return true; }

/// Function that only compiles if the constexpr getS2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize(0) == 3, bool>::type cxpGetS2COSize00() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize(1) == 1, bool>::type cxpGetS2COSize01() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS2COSize(0) == 0, bool>::type cxpGetS2COSize20() { return true; }

/// Function that only compiles if the constexpr getS2COSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize(0,0) == 5, bool>::type cxpGetS2COSize000() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize(0,1) == 6, bool>::type cxpGetS2COSize001() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize(0,2) == 5, bool>::type cxpGetS2COSize002() { return true; }
/// Function that only compiles if the constexpr getS2COSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2COSize(1,0) == 6, bool>::type cxpGetS2COSize010() { return true; }

/// Function that only compiles if the constexpr getS2CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CO(0,0), "1220"), bool>::type cxpGetS2CO000(void) { return true; }
/// Function that only compiles if the constexpr getS2CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CO(0,1), "-1208"), bool>::type cxpGetS2CO001(void) { return true; }
/// Function that only compiles if the constexpr getS2CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CO(0,2), "1221"), bool>::type cxpGetS2CO002(void) { return true; }
/// Function that only compiles if the constexpr getS2CO() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CO(1,0), "-1208"), bool>::type cxpGetS2CO010(void) { return true; }

/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=off
TEST_F(TestScombs, S2CxpOff)
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
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
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
	value = xenums::Scombs::V2;
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
	try { success = false; xenums::Scombs::_fromS2CO("42"); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	try { success = false; xenums::Scombs::_fromS2CO("42", value); }
	catch (std::logic_error e) { EXPECT_STREQ("_fromS2CO() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS2CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CESize() == 2, bool>::type cxpGetS2CESize0() { return true; }
/// Function that only compiles if the constexpr getS2CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS2CESize() == 0, bool>::type cxpGetS2CESize1() { return true; }
/// Function that only compiles if the constexpr getS2CESize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS2CESize() == 1, bool>::type cxpGetS2CESize2() { return true; }

/// Function that only compiles if the constexpr getS2CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CESize(0) == 3, bool>::type cxpGetS2CESize00() { return true; }
/// Function that only compiles if the constexpr getS2CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CESize(1) == 1, bool>::type cxpGetS2CESize01() { return true; }
/// Function that only compiles if the constexpr getS2CESize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS2CESize(0) == 0, bool>::type cxpGetS2CESize20() { return true; }

/// Function that only compiles if the constexpr getS2CESize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CESize(0,0) == 5, bool>::type cxpGetS2CESize000() { return true; }
/// Function that only compiles if the constexpr getS2CESize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CESize(0,1) == 6, bool>::type cxpGetS2CESize001() { return true; }
/// Function that only compiles if the constexpr getS2CESize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CESize(0,2) == 5, bool>::type cxpGetS2CESize002() { return true; }
/// Function that only compiles if the constexpr getS2CESize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CESize(1,0) == 6, bool>::type cxpGetS2CESize010() { return true; }

/// Function that only compiles if the constexpr getS2CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CE(0,0), "1222"), bool>::type cxpGetS2CE000(void) { return true; }
/// Function that only compiles if the constexpr getS2CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CE(0,1), "-1209"), bool>::type cxpGetS2CE001(void) { return true; }
/// Function that only compiles if the constexpr getS2CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CE(0,2), "1223"), bool>::type cxpGetS2CE002(void) { return true; }
/// Function that only compiles if the constexpr getS2CE() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CE(1,0), "-1209"), bool>::type cxpGetS2CE010(void) { return true; }

/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=ext
TEST_F(TestScombs, S2CxpExt)
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
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
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
	value = xenums::Scombs::V2;
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
	EXPECT_EQ(true, xenums::Scombs::_fromS2CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2CE(strval));
	strval = "1223";
	EXPECT_EQ(true, xenums::Scombs::_fromS2CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2CE(strval));
	// Not unique, but both are in V0.
	strval = "-1209";
	EXPECT_EQ(true, xenums::Scombs::_fromS2CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2CE(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS2CE(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS2CE(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2CE'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS2CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CISize() == 2, bool>::type cxpGetS2CISize0() { return true; }
/// Function that only compiles if the constexpr getS2CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS2CISize() == 0, bool>::type cxpGetS2CISize1() { return true; }
/// Function that only compiles if the constexpr getS2CISize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS2CISize() == 1, bool>::type cxpGetS2CISize2() { return true; }

/// Function that only compiles if the constexpr getS2CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CISize(0) == 3, bool>::type cxpGetS2CISize00() { return true; }
/// Function that only compiles if the constexpr getS2CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CISize(1) == 1, bool>::type cxpGetS2CISize01() { return true; }
/// Function that only compiles if the constexpr getS2CISize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS2CISize(0) == 0, bool>::type cxpGetS2CISize20() { return true; }

/// Function that only compiles if the constexpr getS2CISize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CISize(0,0) == 5, bool>::type cxpGetS2CISize000() { return true; }
/// Function that only compiles if the constexpr getS2CISize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CISize(0,1) == 6, bool>::type cxpGetS2CISize001() { return true; }
/// Function that only compiles if the constexpr getS2CISize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CISize(0,2) == 5, bool>::type cxpGetS2CISize002() { return true; }
/// Function that only compiles if the constexpr getS2CISize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CISize(1,0) == 6, bool>::type cxpGetS2CISize010() { return true; }

/// Function that only compiles if the constexpr getS2CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CI(0,0), "1224"), bool>::type cxpGetS2CI000(void) { return true; }
/// Function that only compiles if the constexpr getS2CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CI(0,1), "-1210"), bool>::type cxpGetS2CI001(void) { return true; }
/// Function that only compiles if the constexpr getS2CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CI(0,2), "1225"), bool>::type cxpGetS2CI002(void) { return true; }
/// Function that only compiles if the constexpr getS2CI() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CI(1,0), "-1210"), bool>::type cxpGetS2CI010(void) { return true; }

/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=inl
TEST_F(TestScombs, S2CxpInl)
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
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
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
	value = xenums::Scombs::V2;
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
	EXPECT_EQ(true, xenums::Scombs::_fromS2CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2CI(strval));
	strval = "1225";
	EXPECT_EQ(true, xenums::Scombs::_fromS2CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2CI(strval));
	// Not unique, but both are in V0.
	strval = "-1210";
	EXPECT_EQ(true, xenums::Scombs::_fromS2CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2CI(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS2CI(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS2CI(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2CI'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}


/// Function that only compiles if the constexpr getS2CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CCSize() == 2, bool>::type cxpGetS2CCSize0() { return true; }
/// Function that only compiles if the constexpr getS2CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V1.getS2CCSize() == 0, bool>::type cxpGetS2CCSize1() { return true; }
/// Function that only compiles if the constexpr getS2CCSize() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS2CCSize() == 1, bool>::type cxpGetS2CCSize2() { return true; }

/// Function that only compiles if the constexpr getS2CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CCSize(0) == 3, bool>::type cxpGetS2CCSize00() { return true; }
/// Function that only compiles if the constexpr getS2CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CCSize(1) == 1, bool>::type cxpGetS2CCSize01() { return true; }
/// Function that only compiles if the constexpr getS2CCSize(index1) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V2.getS2CCSize(0) == 0, bool>::type cxpGetS2CCSize20() { return true; }

/// Function that only compiles if the constexpr getS2CCSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CCSize(0,0) == 5, bool>::type cxpGetS2CCSize000() { return true; }
/// Function that only compiles if the constexpr getS2CCSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CCSize(0,1) == 6, bool>::type cxpGetS2CCSize001() { return true; }
/// Function that only compiles if the constexpr getS2CCSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CCSize(0,2) == 5, bool>::type cxpGetS2CCSize002() { return true; }
/// Function that only compiles if the constexpr getS2CCSize(index1,index2) actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::V0.getS2CCSize(1,0) == 6, bool>::type cxpGetS2CCSize010() { return true; }

/// Function that only compiles if the constexpr getS2CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CC(0,0), "1226"), bool>::type cxpGetS2CC000(void) { return true; }
/// Function that only compiles if the constexpr getS2CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CC(0,1), "-1211"), bool>::type cxpGetS2CC001(void) { return true; }
/// Function that only compiles if the constexpr getS2CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CC(0,2), "1227"), bool>::type cxpGetS2CC002(void) { return true; }
/// Function that only compiles if the constexpr getS2CC() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::Scombs::V0.getS2CC(1,0), "-1211"), bool>::type cxpGetS2CC010(void) { return true; }

/// Function that only compiles if cxpFromS2CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS2CC("1226") == xenums::Scombs::V0, bool>::type cxpFromS2CC0(void) { return true; }
/// Function that only compiles if cxpFromS2CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS2CC("1227") == xenums::Scombs::V0, bool>::type cxpFromS2CC1(void) { return true; }
/// Function that only compiles if cxpFromS2CC() actually works at compile time.
template <class T> typename std::enable_if<xenums::Scombs::_cxpFromS2CC("-1211") == xenums::Scombs::V0, bool>::type cxpFromS2CC2(void) { return true; }
/// Test xenum with identifier features: depth=2, getValue=cxp, fromValue=cxp
TEST_F(TestScombs, S2CxpCxp)
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
	value = xenums::Scombs::V0;
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
	value = xenums::Scombs::V1;
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
	value = xenums::Scombs::V2;
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

	// fromValue
	strval = "1226";
	EXPECT_EQ(true, xenums::Scombs::_fromS2CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2CC(strval));
	strval = "1227";
	EXPECT_EQ(true, xenums::Scombs::_fromS2CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2CC(strval));
	// Not unique, but both are in V0.
	strval = "-1211";
	EXPECT_EQ(true, xenums::Scombs::_fromS2CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_fromS2CC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_fromS2CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_fromS2CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromValue() at runtime
	strval = "1226";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS2CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS2CC(strval));
	strval = "1227";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS2CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS2CC(strval));
	// Not unique, but both are in V0.
	strval = "-1211";
	EXPECT_EQ(true, xenums::Scombs::_cxpFromS2CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V0);
	EXPECT_EQ(value, xenums::Scombs::_cxpFromS2CC(strval));

	value = xenums::Scombs::V2;
	strval = "42";
	EXPECT_EQ(false, xenums::Scombs::_cxpFromS2CC(strval, value));
	EXPECT_EQ(value, xenums::Scombs::V2);
	try { success = false; xenums::Scombs::_cxpFromS2CC(strval); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such value of custom property 'S2CC'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}



} // namespace xenum
} // namespace test
