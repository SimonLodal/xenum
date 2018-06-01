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
}
#endif


#if XENUM5_TEST_IdentExtInl
// FIXME: Do
#endif


#if XENUM5_TEST_IdentExtCxp
// FIXME: Do
#endif


#if XENUM5_TEST_IdentCxpOff
// FIXME: Do
#endif


#if XENUM5_TEST_IdentCxpExt
// FIXME: Do
#endif


#if XENUM5_TEST_IdentCxpInl
// FIXME: Do
#endif


#if XENUM5_TEST_IdentCxpCxp
// FIXME: Do
#endif


} // namespace xenum
} // namespace test
