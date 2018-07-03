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

/// To get throwing getIdentifier() and fromIdentifier() instead of not
/// compiling them when they are "off".
#define _XENUM5_UNIT_TEST	1

#include <test/xenum/xenums/Icombs.hpp>

namespace test {
namespace xenum {

/**
 * Test xenums with combinations of identifier feature options.
 * Note: We can not test if a function does not exist, not can we test if it is constexpr
 * or not. We can only test if it works. This unit test is also just meant to verify that
 * all the different combinations generate valid code that compiles without error, but to
 * verify that the options actually do what they say, manual inspection is necessary.
 */
class TestIcombs : public ::testing::Test {
public:
	bool success;
	const char* ident;
};


#if XENUM5_TEST_IdentOffOff
/// Test xenum with identifier features: getIdentifier=off, fromIdentifier=off
TEST_F(TestIcombs, IdentOffOff)
{
#if _XENUM5_DEBUG_STORE
	xenums::IdentOffOff::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffOff::Icombs::_size);

	// getIdentifier(): Not present.
	success = false;
	try { xenums::IdentOffOff::Icombs::OffOff1.getIdentifier(); }
	catch (std::logic_error e) { EXPECT_STREQ("getIdentifier() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromIdentifier(): Not present.
	success = false;
	try { xenums::IdentOffOff::Icombs::_fromIdentifier("foo"); }
	catch (std::logic_error e) { EXPECT_STREQ("fromIdentifier() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	xenums::IdentOffOff::Icomb resval;
	success = false;
	try { xenums::IdentOffOff::Icombs::_fromIdentifier("foo", resval); }
	catch (std::logic_error e) { EXPECT_STREQ("fromIdentifier() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}
#endif


#if XENUM5_TEST_IdentOffExt
/// Test xenum with identifier features: getIdentifier=off, fromIdentifier=ext
TEST_F(TestIcombs, IdentOffExt)
{
	xenums::IdentOffExt::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::IdentOffExt::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffExt::Icombs::_size);

	// getIdentifier(): Not present.
	success = false;
	try { xenums::IdentOffExt::Icombs::OffExt1.getIdentifier(); }
	catch (std::logic_error e) { EXPECT_STREQ("getIdentifier() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromIdentifier()
	ident = "OffExt0";
	EXPECT_EQ(true, xenums::IdentOffExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::OffExt0);
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::_fromIdentifier(ident));
	ident = "OffExt1";
	EXPECT_EQ(true, xenums::IdentOffExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::OffExt1);
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::_fromIdentifier(ident));
	ident = "OffExt2";
	EXPECT_EQ(true, xenums::IdentOffExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::OffExt2);
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::_fromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentOffExt::Icombs::_fromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::OffExt2);
	success = false;
	try { xenums::IdentOffExt::Icombs::_fromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}
#endif


#if XENUM5_TEST_IdentOffInl
/// Test xenum with identifier features: getIdentifier=off, fromIdentifier=inl
TEST_F(TestIcombs, IdentOffInl)
{
	xenums::IdentOffInl::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::IdentOffInl::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffInl::Icombs::_size);

	// getIdentifier(): Not present.
	success = false;
	try { xenums::IdentOffInl::Icombs::OffInl1.getIdentifier(); }
	catch (std::logic_error e) { EXPECT_STREQ("getIdentifier() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromIdentifier()
	ident = "OffInl0";
	EXPECT_EQ(true, xenums::IdentOffInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::OffInl0);
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::_fromIdentifier(ident));
	ident = "OffInl1";
	EXPECT_EQ(true, xenums::IdentOffInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::OffInl1);
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::_fromIdentifier(ident));
	ident = "OffInl2";
	EXPECT_EQ(true, xenums::IdentOffInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::OffInl2);
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::_fromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentOffInl::Icombs::_fromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::OffInl2);
	success = false;
	try { xenums::IdentOffInl::Icombs::_fromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}
#endif


#if XENUM5_TEST_IdentOffCxp
/// Function that only compiles if cxpFromIdentifier() actually works at compile time.
template <class T> typename std::enable_if<xenums::IdentOffCxp::Icombs::_cxpFromIdentifier("OffCxp0") == xenums::IdentOffCxp::Icombs::OffCxp0, bool>::type cxpFromOffCxp0(void) { return true; }
/// Function that only compiles if cxpFromIdentifier() actually works at compile time.
template <class T> typename std::enable_if<xenums::IdentOffCxp::Icombs::_cxpFromIdentifier("OffCxp1") == xenums::IdentOffCxp::Icombs::OffCxp1, bool>::type cxpFromOffCxp1(void) { return true; }
/// Function that only compiles if cxpFromIdentifier() actually works at compile time.
template <class T> typename std::enable_if<xenums::IdentOffCxp::Icombs::_cxpFromIdentifier("OffCxp2") == xenums::IdentOffCxp::Icombs::OffCxp2, bool>::type cxpFromOffCxp2(void) { return true; }
/// Test xenum with identifier features: getIdentifier=off, fromIdentifier=cxp
TEST_F(TestIcombs, IdentOffCxp)
{
	xenums::IdentOffCxp::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::IdentOffCxp::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffCxp::Icombs::_size);

	// getIdentifier(): Not present.
	success = false;
	try { xenums::IdentOffCxp::Icombs::OffCxp1.getIdentifier(); }
	catch (std::logic_error e) { EXPECT_STREQ("getIdentifier() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// fromIdentifier()
	ident = "OffCxp0";
	EXPECT_EQ(true, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp0);
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident));
	ident = "OffCxp1";
	EXPECT_EQ(true, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp1);
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident));
	ident = "OffCxp2";
	EXPECT_EQ(true, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp2);
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentOffCxp::Icombs::_fromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp2);
	success = false;
	try { xenums::IdentOffCxp::Icombs::_fromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromIdentifier() at runtime
	ident = "OffCxp0";
	EXPECT_EQ(true, xenums::IdentOffCxp::Icombs::_cxpFromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp0);
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::_cxpFromIdentifier(ident));
	ident = "OffCxp1";
	EXPECT_EQ(true, xenums::IdentOffCxp::Icombs::_cxpFromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp1);
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::_cxpFromIdentifier(ident));
	ident = "OffCxp2";
	EXPECT_EQ(true, xenums::IdentOffCxp::Icombs::_cxpFromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp2);
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::_cxpFromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentOffCxp::Icombs::_cxpFromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp2);
	success = false;
	try { xenums::IdentOffCxp::Icombs::_cxpFromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromIdentifier() at compile time
	EXPECT_EQ(true, cxpFromOffCxp0<void>());
	EXPECT_EQ(true, cxpFromOffCxp1<void>());
	EXPECT_EQ(true, cxpFromOffCxp2<void>());
}
#endif


#if XENUM5_TEST_IdentExtOff
/// Test xenum with identifier features: getIdentifier=ext, fromIdentifier=off
TEST_F(TestIcombs, IdentExtOff)
{
#if _XENUM5_DEBUG_STORE
	xenums::IdentExtOff::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentExtOff::Icombs::_size);

	// getIdentifier()
	EXPECT_STREQ("ExtOff0", xenums::IdentExtOff::Icombs::ExtOff0.getIdentifier());
	EXPECT_STREQ("ExtOff1", xenums::IdentExtOff::Icombs::ExtOff1.getIdentifier());
	EXPECT_STREQ("ExtOff2", xenums::IdentExtOff::Icombs::ExtOff2.getIdentifier());

	// fromIdentifier(): Not present.
	success = false;
	try { xenums::IdentExtOff::Icombs::_fromIdentifier("foo"); }
	catch (std::logic_error e) { EXPECT_STREQ("fromIdentifier() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	xenums::IdentExtOff::Icomb resval;
	success = false;
	try { xenums::IdentExtOff::Icombs::_fromIdentifier("foo", resval); }
	catch (std::logic_error e) { EXPECT_STREQ("fromIdentifier() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}
#endif


#if XENUM5_TEST_IdentExtExt
/// Test xenum with identifier features: getIdentifier=ext, fromIdentifier=ext
TEST_F(TestIcombs, IdentExtExt)
{
	xenums::IdentExtExt::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::IdentExtExt::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentExtExt::Icombs::_size);

	// getIdentifier()
	EXPECT_STREQ("ExtExt0", xenums::IdentExtExt::Icombs::ExtExt0.getIdentifier());
	EXPECT_STREQ("ExtExt1", xenums::IdentExtExt::Icombs::ExtExt1.getIdentifier());
	EXPECT_STREQ("ExtExt2", xenums::IdentExtExt::Icombs::ExtExt2.getIdentifier());

	// fromIdentifier()
	ident = "ExtExt0";
	EXPECT_EQ(true, xenums::IdentExtExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtExt::Icombs::ExtExt0);
	EXPECT_EQ(value, xenums::IdentExtExt::Icombs::_fromIdentifier(ident));
	ident = "ExtExt1";
	EXPECT_EQ(true, xenums::IdentExtExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtExt::Icombs::ExtExt1);
	EXPECT_EQ(value, xenums::IdentExtExt::Icombs::_fromIdentifier(ident));
	ident = "ExtExt2";
	EXPECT_EQ(true, xenums::IdentExtExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtExt::Icombs::ExtExt2);
	EXPECT_EQ(value, xenums::IdentExtExt::Icombs::_fromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentExtExt::Icombs::_fromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentExtExt::Icombs::ExtExt2);
	success = false;
	try { xenums::IdentExtExt::Icombs::_fromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}
#endif


#if XENUM5_TEST_IdentExtInl
/// Test xenum with identifier features: getIdentifier=ext, fromIdentifier=inl
TEST_F(TestIcombs, IdentExtInl)
{
	xenums::IdentExtInl::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::IdentExtInl::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentExtInl::Icombs::_size);

	// getIdentifier()
	EXPECT_STREQ("ExtInl0", xenums::IdentExtInl::Icombs::ExtInl0.getIdentifier());
	EXPECT_STREQ("ExtInl1", xenums::IdentExtInl::Icombs::ExtInl1.getIdentifier());
	EXPECT_STREQ("ExtInl2", xenums::IdentExtInl::Icombs::ExtInl2.getIdentifier());

	// fromIdentifier()
	ident = "ExtInl0";
	EXPECT_EQ(true, xenums::IdentExtInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtInl::Icombs::ExtInl0);
	EXPECT_EQ(value, xenums::IdentExtInl::Icombs::_fromIdentifier(ident));
	ident = "ExtInl1";
	EXPECT_EQ(true, xenums::IdentExtInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtInl::Icombs::ExtInl1);
	EXPECT_EQ(value, xenums::IdentExtInl::Icombs::_fromIdentifier(ident));
	ident = "ExtInl2";
	EXPECT_EQ(true, xenums::IdentExtInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtInl::Icombs::ExtInl2);
	EXPECT_EQ(value, xenums::IdentExtInl::Icombs::_fromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentExtInl::Icombs::_fromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentExtInl::Icombs::ExtInl2);
	success = false;
	try { xenums::IdentExtInl::Icombs::_fromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}
#endif


#if XENUM5_TEST_IdentExtCxp
/// Function that only compiles if cxpFromIdentifier() actually works at compile time.
template <class T> typename std::enable_if<xenums::IdentExtCxp::Icombs::_cxpFromIdentifier("ExtCxp0") == xenums::IdentExtCxp::Icombs::ExtCxp0, bool>::type cxpFromExtCxp0(void) { return true; }
/// Function that only compiles if cxpFromIdentifier() actually works at compile time.
template <class T> typename std::enable_if<xenums::IdentExtCxp::Icombs::_cxpFromIdentifier("ExtCxp1") == xenums::IdentExtCxp::Icombs::ExtCxp1, bool>::type cxpFromExtCxp1(void) { return true; }
/// Function that only compiles if cxpFromIdentifier() actually works at compile time.
template <class T> typename std::enable_if<xenums::IdentExtCxp::Icombs::_cxpFromIdentifier("ExtCxp2") == xenums::IdentExtCxp::Icombs::ExtCxp2, bool>::type cxpFromExtCxp2(void) { return true; }
/// Test xenum with identifier features: getIdentifier=ext, fromIdentifier=cxp
TEST_F(TestIcombs, IdentExtCxp)
{
	xenums::IdentExtCxp::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::IdentExtCxp::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentExtCxp::Icombs::_size);

	// getIdentifier()
	EXPECT_STREQ("ExtCxp0", xenums::IdentExtCxp::Icombs::ExtCxp0.getIdentifier());
	EXPECT_STREQ("ExtCxp1", xenums::IdentExtCxp::Icombs::ExtCxp1.getIdentifier());
	EXPECT_STREQ("ExtCxp2", xenums::IdentExtCxp::Icombs::ExtCxp2.getIdentifier());

	// fromIdentifier()
	ident = "ExtCxp0";
	EXPECT_EQ(true, xenums::IdentExtCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::ExtCxp0);
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::_fromIdentifier(ident));
	ident = "ExtCxp1";
	EXPECT_EQ(true, xenums::IdentExtCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::ExtCxp1);
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::_fromIdentifier(ident));
	ident = "ExtCxp2";
	EXPECT_EQ(true, xenums::IdentExtCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::ExtCxp2);
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::_fromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentExtCxp::Icombs::_fromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::ExtCxp2);
	success = false;
	try { xenums::IdentExtCxp::Icombs::_fromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromIdentifier() at runtime
	ident = "ExtCxp0";
	EXPECT_EQ(true, xenums::IdentExtCxp::Icombs::_cxpFromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::ExtCxp0);
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::_cxpFromIdentifier(ident));
	ident = "ExtCxp1";
	EXPECT_EQ(true, xenums::IdentExtCxp::Icombs::_cxpFromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::ExtCxp1);
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::_cxpFromIdentifier(ident));
	ident = "ExtCxp2";
	EXPECT_EQ(true, xenums::IdentExtCxp::Icombs::_cxpFromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::ExtCxp2);
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::_cxpFromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentExtCxp::Icombs::_cxpFromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentExtCxp::Icombs::ExtCxp2);
	success = false;
	try { xenums::IdentExtCxp::Icombs::_cxpFromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromIdentifier() at compile time
	EXPECT_EQ(true, cxpFromExtCxp0<void>());
	EXPECT_EQ(true, cxpFromExtCxp1<void>());
	EXPECT_EQ(true, cxpFromExtCxp2<void>());
}
#endif


#if XENUM5_TEST_IdentCxpOff
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpOff::Icombs::CxpOff0.getIdentifier(), "CxpOff0"), bool>::type cxpGetCxpOff0(void) { return true; }
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpOff::Icombs::CxpOff1.getIdentifier(), "CxpOff1"), bool>::type cxpGetCxpOff1(void) { return true; }
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpOff::Icombs::CxpOff2.getIdentifier(), "CxpOff2"), bool>::type cxpGetCxpOff2(void) { return true; }
/// Test xenum with identifier features: getIdentifier=cxp, fromIdentifier=off
TEST_F(TestIcombs, IdentCxpOff)
{
	xenums::IdentCxpOff::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::IdentCxpOff::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentCxpOff::Icombs::_size);

	// getIdentifier()
	EXPECT_STREQ("CxpOff0", xenums::IdentCxpOff::Icombs::CxpOff0.getIdentifier());
	EXPECT_STREQ("CxpOff1", xenums::IdentCxpOff::Icombs::CxpOff1.getIdentifier());
	EXPECT_STREQ("CxpOff2", xenums::IdentCxpOff::Icombs::CxpOff2.getIdentifier());
	// getIdentifier() at compile time
	EXPECT_EQ(true, cxpGetCxpOff0<void>());
	EXPECT_EQ(true, cxpGetCxpOff1<void>());
	EXPECT_EQ(true, cxpGetCxpOff2<void>());

	// fromIdentifier(): Not present.
	success = false;
	try { xenums::IdentCxpOff::Icombs::_fromIdentifier("foo"); }
	catch (std::logic_error e) { EXPECT_STREQ("fromIdentifier() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
	xenums::IdentCxpOff::Icomb resval;
	success = false;
	try { xenums::IdentCxpOff::Icombs::_fromIdentifier("foo", resval); }
	catch (std::logic_error e) { EXPECT_STREQ("fromIdentifier() is configured 'off'.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}
#endif


#if XENUM5_TEST_IdentCxpExt
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpExt::Icombs::CxpExt0.getIdentifier(), "CxpExt0"), bool>::type cxpGetCxpExt0(void) { return true; }
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpExt::Icombs::CxpExt1.getIdentifier(), "CxpExt1"), bool>::type cxpGetCxpExt1(void) { return true; }
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpExt::Icombs::CxpExt2.getIdentifier(), "CxpExt2"), bool>::type cxpGetCxpExt2(void) { return true; }
/// Test xenum with identifier features: getIdentifier=cxp, fromIdentifier=ext
TEST_F(TestIcombs, IdentCxpExt)
{
	xenums::IdentCxpExt::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::IdentCxpExt::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentCxpExt::Icombs::_size);

	// getIdentifier()
	EXPECT_STREQ("CxpExt0", xenums::IdentCxpExt::Icombs::CxpExt0.getIdentifier());
	EXPECT_STREQ("CxpExt1", xenums::IdentCxpExt::Icombs::CxpExt1.getIdentifier());
	EXPECT_STREQ("CxpExt2", xenums::IdentCxpExt::Icombs::CxpExt2.getIdentifier());
	// getIdentifier() at compile time
	EXPECT_EQ(true, cxpGetCxpExt0<void>());
	EXPECT_EQ(true, cxpGetCxpExt1<void>());
	EXPECT_EQ(true, cxpGetCxpExt2<void>());

	// fromIdentifier()
	ident = "CxpExt0";
	EXPECT_EQ(true, xenums::IdentCxpExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpExt::Icombs::CxpExt0);
	EXPECT_EQ(value, xenums::IdentCxpExt::Icombs::_fromIdentifier(ident));
	ident = "CxpExt1";
	EXPECT_EQ(true, xenums::IdentCxpExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpExt::Icombs::CxpExt1);
	EXPECT_EQ(value, xenums::IdentCxpExt::Icombs::_fromIdentifier(ident));
	ident = "CxpExt2";
	EXPECT_EQ(true, xenums::IdentCxpExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpExt::Icombs::CxpExt2);
	EXPECT_EQ(value, xenums::IdentCxpExt::Icombs::_fromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentCxpExt::Icombs::_fromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentCxpExt::Icombs::CxpExt2);
	success = false;
	try { xenums::IdentCxpExt::Icombs::_fromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}
#endif


#if XENUM5_TEST_IdentCxpInl
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpInl::Icombs::CxpInl0.getIdentifier(), "CxpInl0"), bool>::type cxpGetCxpInl0(void) { return true; }
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpInl::Icombs::CxpInl1.getIdentifier(), "CxpInl1"), bool>::type cxpGetCxpInl1(void) { return true; }
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpInl::Icombs::CxpInl2.getIdentifier(), "CxpInl2"), bool>::type cxpGetCxpInl2(void) { return true; }
/// Test xenum with identifier features: getIdentifier=cxp, fromIdentifier=inl
TEST_F(TestIcombs, IdentCxpInl)
{
	xenums::IdentCxpInl::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::IdentCxpInl::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentCxpInl::Icombs::_size);

	// getIdentifier()
	EXPECT_STREQ("CxpInl0", xenums::IdentCxpInl::Icombs::CxpInl0.getIdentifier());
	EXPECT_STREQ("CxpInl1", xenums::IdentCxpInl::Icombs::CxpInl1.getIdentifier());
	EXPECT_STREQ("CxpInl2", xenums::IdentCxpInl::Icombs::CxpInl2.getIdentifier());
	// getIdentifier() at compile time
	EXPECT_EQ(true, cxpGetCxpInl0<void>());
	EXPECT_EQ(true, cxpGetCxpInl1<void>());
	EXPECT_EQ(true, cxpGetCxpInl2<void>());

	// fromIdentifier()
	ident = "CxpInl0";
	EXPECT_EQ(true, xenums::IdentCxpInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpInl::Icombs::CxpInl0);
	EXPECT_EQ(value, xenums::IdentCxpInl::Icombs::_fromIdentifier(ident));
	ident = "CxpInl1";
	EXPECT_EQ(true, xenums::IdentCxpInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpInl::Icombs::CxpInl1);
	EXPECT_EQ(value, xenums::IdentCxpInl::Icombs::_fromIdentifier(ident));
	ident = "CxpInl2";
	EXPECT_EQ(true, xenums::IdentCxpInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpInl::Icombs::CxpInl2);
	EXPECT_EQ(value, xenums::IdentCxpInl::Icombs::_fromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentCxpInl::Icombs::_fromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentCxpInl::Icombs::CxpInl2);
	success = false;
	try { xenums::IdentCxpInl::Icombs::_fromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);
}
#endif


#if XENUM5_TEST_IdentCxpCxp
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpCxp::Icombs::CxpCxp0.getIdentifier(), "CxpCxp0"), bool>::type cxpGetCxpCxp0(void) { return true; }
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpCxp::Icombs::CxpCxp1.getIdentifier(), "CxpCxp1"), bool>::type cxpGetCxpCxp1(void) { return true; }
/// Function that only compiles if the constexpr getIdentifier() actually works at compile time.
template <class T> typename std::enable_if<::_XENUM5_NS::cxpStrEqual(xenums::IdentCxpCxp::Icombs::CxpCxp2.getIdentifier(), "CxpCxp2"), bool>::type cxpGetCxpCxp2(void) { return true; }
/// Function that only compiles if cxpFromIdentifier() actually works at compile time.
template <class T> typename std::enable_if<xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier("CxpCxp0") == xenums::IdentCxpCxp::Icombs::CxpCxp0, bool>::type cxpFromCxpCxp0(void) { return true; }
/// Function that only compiles if cxpFromIdentifier() actually works at compile time.
template <class T> typename std::enable_if<xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier("CxpCxp1") == xenums::IdentCxpCxp::Icombs::CxpCxp1, bool>::type cxpFromCxpCxp1(void) { return true; }
/// Function that only compiles if cxpFromIdentifier() actually works at compile time.
template <class T> typename std::enable_if<xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier("CxpCxp2") == xenums::IdentCxpCxp::Icombs::CxpCxp2, bool>::type cxpFromCxpCxp2(void) { return true; }
/// Test xenum with identifier features: getIdentifier=cxp, fromIdentifier=cxp
TEST_F(TestIcombs, IdentCxpCxp)
{
	xenums::IdentCxpCxp::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::IdentCxpCxp::_xenum5_store_Icombs::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentCxpCxp::Icombs::_size);

	// getIdentifier()
	EXPECT_STREQ("CxpCxp0", xenums::IdentCxpCxp::Icombs::CxpCxp0.getIdentifier());
	EXPECT_STREQ("CxpCxp1", xenums::IdentCxpCxp::Icombs::CxpCxp1.getIdentifier());
	EXPECT_STREQ("CxpCxp2", xenums::IdentCxpCxp::Icombs::CxpCxp2.getIdentifier());
	// getIdentifier() at compile time
	EXPECT_EQ(true, cxpGetCxpCxp0<void>());
	EXPECT_EQ(true, cxpGetCxpCxp1<void>());
	EXPECT_EQ(true, cxpGetCxpCxp2<void>());

	// fromIdentifier()
	ident = "CxpCxp0";
	EXPECT_EQ(true, xenums::IdentCxpCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::CxpCxp0);
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::_fromIdentifier(ident));
	ident = "CxpCxp1";
	EXPECT_EQ(true, xenums::IdentCxpCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::CxpCxp1);
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::_fromIdentifier(ident));
	ident = "CxpCxp2";
	EXPECT_EQ(true, xenums::IdentCxpCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::CxpCxp2);
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::_fromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentCxpCxp::Icombs::_fromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::CxpCxp2);
	success = false;
	try { xenums::IdentCxpCxp::Icombs::_fromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromIdentifier() at runtime
	ident = "CxpCxp0";
	EXPECT_EQ(true, xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::CxpCxp0);
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier(ident));
	ident = "CxpCxp1";
	EXPECT_EQ(true, xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::CxpCxp1);
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier(ident));
	ident = "CxpCxp2";
	EXPECT_EQ(true, xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::CxpCxp2);
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier(ident));

	EXPECT_EQ(false, xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier("foo", value));
	EXPECT_EQ(value, xenums::IdentCxpCxp::Icombs::CxpCxp2);
	success = false;
	try { xenums::IdentCxpCxp::Icombs::_cxpFromIdentifier("foo"); }
	catch (std::out_of_range e) { EXPECT_STREQ("No such identifier.", e.what()); success = true; }
	EXPECT_EQ(true, success);

	// cxpFromIdentifier() at compile time
	EXPECT_EQ(true, cxpFromCxpCxp0<void>());
	EXPECT_EQ(true, cxpFromCxpCxp1<void>());
	EXPECT_EQ(true, cxpFromCxpCxp2<void>());
}
#endif


} // namespace xenum
} // namespace test
