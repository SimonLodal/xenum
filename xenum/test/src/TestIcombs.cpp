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
	xenums::_xenum5_store_IdentOffOff::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffOff::Icombs::_size);
	// getIdentifier(): Not present.
	// fromIdentifier(): Not present.
}
#endif


#if XENUM5_TEST_IdentOffExt
/// Test xenum with identifier features: getIdentifier=off, fromIdentifier=ext
TEST_F(TestIcombs, IdentOffExt)
{
	xenums::IdentOffExt::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentOffExt::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffExt::Icombs::_size);
	// getIdentifier(): Not present.
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
	xenums::_xenum5_store_IdentOffInl::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffInl::Icombs::_size);
	// getIdentifier(): Not present.
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
/// Test xenum with identifier features: getIdentifier=off, fromIdentifier=cxp
TEST_F(TestIcombs, IdentOffCxp)
{
	xenums::IdentOffCxp::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentOffCxp::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffCxp::Icombs::_size);
	// getIdentifier(): Not present.
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
}
#endif


#if XENUM5_TEST_IdentExtOff
/// Test xenum with identifier features: getIdentifier=ext, fromIdentifier=off
TEST_F(TestIcombs, IdentExtOff)
{
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentExtOff::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentExtOff::Icombs::_size);
	// getIdentifier()
	EXPECT_STREQ("ExtOff0", xenums::IdentExtOff::Icombs::ExtOff0.getIdentifier());
	EXPECT_STREQ("ExtOff1", xenums::IdentExtOff::Icombs::ExtOff1.getIdentifier());
	EXPECT_STREQ("ExtOff2", xenums::IdentExtOff::Icombs::ExtOff2.getIdentifier());
	// fromIdentifier(): Not present.
}
#endif


#if XENUM5_TEST_IdentExtExt
/// Test xenum with identifier features: getIdentifier=ext, fromIdentifier=ext
TEST_F(TestIcombs, IdentExtExt)
{
	xenums::IdentExtExt::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentExtExt::_dbginfo();
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
	xenums::_xenum5_store_IdentExtInl::_dbginfo();
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
/// Test xenum with identifier features: getIdentifier=ext, fromIdentifier=cxp
TEST_F(TestIcombs, IdentExtCxp)
{
	xenums::IdentExtCxp::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentExtCxp::_dbginfo();
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
}
#endif


#if XENUM5_TEST_IdentCxpOff
// FIXME: Do
#endif


#if XENUM5_TEST_IdentCxpExt
/// Test xenum with identifier features: getIdentifier=cxp, fromIdentifier=ext
TEST_F(TestIcombs, IdentCxpExt)
{
	xenums::IdentCxpExt::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentCxpExt::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentCxpExt::Icombs::_size);
	// getIdentifier()
	EXPECT_STREQ("CxpExt0", xenums::IdentCxpExt::Icombs::CxpExt0.getIdentifier());
	EXPECT_STREQ("CxpExt1", xenums::IdentCxpExt::Icombs::CxpExt1.getIdentifier());
	EXPECT_STREQ("CxpExt2", xenums::IdentCxpExt::Icombs::CxpExt2.getIdentifier());
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
/// Test xenum with identifier features: getIdentifier=cxp, fromIdentifier=inl
TEST_F(TestIcombs, IdentCxpInl)
{
	xenums::IdentCxpInl::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentCxpInl::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentCxpInl::Icombs::_size);
	// getIdentifier()
	EXPECT_STREQ("CxpInl0", xenums::IdentCxpInl::Icombs::CxpInl0.getIdentifier());
	EXPECT_STREQ("CxpInl1", xenums::IdentCxpInl::Icombs::CxpInl1.getIdentifier());
	EXPECT_STREQ("CxpInl2", xenums::IdentCxpInl::Icombs::CxpInl2.getIdentifier());
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
/// Test xenum with identifier features: getIdentifier=cxp, fromIdentifier=cxp
TEST_F(TestIcombs, IdentCxpCxp)
{
	xenums::IdentCxpCxp::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentCxpCxp::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentCxpCxp::Icombs::_size);
	// getIdentifier()
	EXPECT_STREQ("CxpCxp0", xenums::IdentCxpCxp::Icombs::CxpCxp0.getIdentifier());
	EXPECT_STREQ("CxpCxp1", xenums::IdentCxpCxp::Icombs::CxpCxp1.getIdentifier());
	EXPECT_STREQ("CxpCxp2", xenums::IdentCxpCxp::Icombs::CxpCxp2.getIdentifier());
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
}
#endif


} // namespace xenum
} // namespace test
