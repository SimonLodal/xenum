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


/// Test xenum with identifier features: getIdentifier=off, fromIdentifier=ext
TEST_F(TestIcombs, IdentOffExt)
{
	xenums::IdentOffExt::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentOffExt::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffExt::Icombs::_size);
	// getIdentifier(): Not present.
	// fromIdentifier
	ident = "OffExt0";
	EXPECT_EQ(true, xenums::IdentOffExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::OffExt0);
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::_fromIdentifier(ident));
	ident = "OffExt1";
	EXPECT_EQ(true, xenums::IdentOffExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::OffExt0);
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::_fromIdentifier(ident));
	ident = "OffExt2";
	EXPECT_EQ(true, xenums::IdentOffExt::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::OffExt0);
	EXPECT_EQ(value, xenums::IdentOffExt::Icombs::_fromIdentifier(ident));
}


/// Test xenum with identifier features: getIdentifier=off, fromIdentifier=inl
TEST_F(TestIcombs, IdentOffInl)
{
	xenums::IdentOffInl::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentOffInl::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffInl::Icombs::_size);
	// getIdentifier(): Not present.
	// fromIdentifier
	ident = "OffInl0";
	EXPECT_EQ(true, xenums::IdentOffInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::OffInl0);
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::_fromIdentifier(ident));
	ident = "OffInl1";
	EXPECT_EQ(true, xenums::IdentOffInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::OffInl0);
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::_fromIdentifier(ident));
	ident = "OffInl2";
	EXPECT_EQ(true, xenums::IdentOffInl::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::OffInl0);
	EXPECT_EQ(value, xenums::IdentOffInl::Icombs::_fromIdentifier(ident));
}


/// Test xenum with identifier features: getIdentifier=off, fromIdentifier=cxp
TEST_F(TestIcombs, IdentOffCxp)
{
	xenums::IdentOffCxp::Icomb value;
#if _XENUM5_DEBUG_STORE
	xenums::_xenum5_store_IdentOffCxp::_dbginfo();
#endif
	EXPECT_EQ(3, xenums::IdentOffCxp::Icombs::_size);
	// getIdentifier(): Not present.
	// fromIdentifier
	ident = "OffCxp0";
	EXPECT_EQ(true, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp0);
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident));
	ident = "OffCxp1";
	EXPECT_EQ(true, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp0);
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident));
	ident = "OffCxp2";
	EXPECT_EQ(true, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident, value));
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::OffCxp0);
	EXPECT_EQ(value, xenums::IdentOffCxp::Icombs::_fromIdentifier(ident));
}


// FIXME: Test all the others too.




} // namespace xenum
} // namespace test
