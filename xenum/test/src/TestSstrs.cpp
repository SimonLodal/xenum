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
#include <test/xenum/xenums/Sstrs0.hpp>
#include <test/xenum/xenums/Sstrs1.hpp>
#include <test/xenum/xenums/Sstrs2.hpp>

namespace test {
namespace xenum {


/**
 * Test xenum with custom string properties defined in source file.
 */
class TestSstrs : public ::testing::Test {
public:
	bool success;
};


TEST_F(TestSstrs, D0Values)
{
	xenums::Sstr0 value;

	// P0
	value = xenums::Sstrs0::V0;
	EXPECT_EQ(1, value.getP0());
	value = xenums::Sstrs0::V1;
	EXPECT_EQ(2, value.getP0());
	value = xenums::Sstrs0::V2;
	EXPECT_EQ(-1, value.getP0());
	value = xenums::Sstrs0::V3;
	EXPECT_EQ(3, value.getP0());

	// P1
	value = xenums::Sstrs0::V0;
	EXPECT_EQ(3, value.getP1Size());
	EXPECT_STREQ("s1", value.getP1());
	value = xenums::Sstrs0::V1;
	EXPECT_EQ(3, value.getP1Size());
	EXPECT_STREQ("s2", value.getP1());
	value = xenums::Sstrs0::V2;
	EXPECT_EQ(5, value.getP1Size());
	EXPECT_STREQ("foo0", value.getP1());
	value = xenums::Sstrs0::V3;
	EXPECT_EQ(3, value.getP1Size());
	EXPECT_STREQ("s3", value.getP1());
}


TEST_F(TestSstrs, D1Values)
{
	xenums::Sstr1 value;

	// P0
	value = xenums::Sstrs1::V0;
	EXPECT_EQ(3, value.getP0Size());
	EXPECT_EQ(1, value.getP0(0));
	EXPECT_EQ(2, value.getP0(1));
	EXPECT_EQ(3, value.getP0(2));

	value = xenums::Sstrs1::V1;
	EXPECT_EQ(1, value.getP0Size());
	EXPECT_EQ(4, value.getP0(0));

	value = xenums::Sstrs1::V2;
	EXPECT_EQ(0, value.getP0Size());

	value = xenums::Sstrs1::V3;
	EXPECT_EQ(2, value.getP0Size());
	EXPECT_EQ(5, value.getP0(0));
	EXPECT_EQ(6, value.getP0(1));

	// P1
	value = xenums::Sstrs1::V0;
	EXPECT_EQ(3, value.getP1Size());
	EXPECT_EQ(3, value.getP1Size(0));
	EXPECT_STREQ("s1", value.getP1(0));
	EXPECT_EQ(3, value.getP1Size(1));
	EXPECT_STREQ("s2", value.getP1(1));
	EXPECT_EQ(3, value.getP1Size(2));
	EXPECT_STREQ("s3", value.getP1(2));

	value = xenums::Sstrs1::V1;
	EXPECT_EQ(1, value.getP1Size());
 	EXPECT_EQ(3, value.getP1Size(0));
 	EXPECT_STREQ("s4", value.getP1(0));

	value = xenums::Sstrs1::V2;
	EXPECT_EQ(0, value.getP1Size());

	value = xenums::Sstrs1::V3;
	EXPECT_EQ(2, value.getP1Size());
 	EXPECT_EQ(3, value.getP1Size(0));
 	EXPECT_STREQ("s5", value.getP1(0));
 	EXPECT_EQ(3, value.getP1Size(1));
 	EXPECT_STREQ("s6", value.getP1(1));
}


TEST_F(TestSstrs, D2Values)
{
	xenums::Sstr2 value;

	// P0
	value = xenums::Sstrs2::V0;
	EXPECT_EQ(2, value.getP0Size());
	EXPECT_EQ(1, value.getP0Size(0));
	EXPECT_EQ(1, value.getP0(0, 0));
	EXPECT_EQ(2, value.getP0Size(1));
	EXPECT_EQ(2, value.getP0(1, 0));
	EXPECT_EQ(3, value.getP0(1, 1));

	value = xenums::Sstrs2::V1;
	EXPECT_EQ(3, value.getP0Size());
	EXPECT_EQ(1, value.getP0Size(0));
	EXPECT_EQ(4, value.getP0(0, 0));
	EXPECT_EQ(1, value.getP0Size(1));
	EXPECT_EQ(5, value.getP0(1, 0));
	EXPECT_EQ(3, value.getP0Size(2));
	EXPECT_EQ(6, value.getP0(2, 0));
	EXPECT_EQ(7, value.getP0(2, 1));
	EXPECT_EQ(8, value.getP0(2, 2));

	value = xenums::Sstrs2::V2;
	EXPECT_EQ(0, value.getP0Size());

	value = xenums::Sstrs2::V3;
	EXPECT_EQ(3, value.getP0Size());
	EXPECT_EQ(1, value.getP0Size(0));
	EXPECT_EQ(-1, value.getP0(0, 0));
	EXPECT_EQ(0, value.getP0Size(1));
	EXPECT_EQ(1, value.getP0Size(2));
	EXPECT_EQ(-1, value.getP0(2, 0));

	// P1
	value = xenums::Sstrs2::V0;
	EXPECT_EQ(2, value.getP1Size());
	EXPECT_EQ(1, value.getP1Size(0));
	EXPECT_EQ(3, value.getP1Size(0, 0));
	EXPECT_STREQ("s1", value.getP1(0, 0));
	EXPECT_EQ(2, value.getP1Size(1));
	EXPECT_EQ(3, value.getP1Size(1, 0));
	EXPECT_STREQ("s2", value.getP1(1, 0));
	EXPECT_EQ(3, value.getP1Size(1, 1));
	EXPECT_STREQ("s3", value.getP1(1, 1));

	value = xenums::Sstrs2::V1;
	EXPECT_EQ(3, value.getP1Size());
	EXPECT_EQ(1, value.getP1Size(0));
	EXPECT_EQ(3, value.getP1Size(0, 0));
	EXPECT_STREQ("s4", value.getP1(0, 0));
	EXPECT_EQ(1, value.getP1Size(1));
	EXPECT_EQ(3, value.getP1Size(1, 0));
	EXPECT_STREQ("s5", value.getP1(1, 0));
	EXPECT_EQ(3, value.getP1Size(2));
	EXPECT_EQ(3, value.getP1Size(2, 0));
	EXPECT_STREQ("s6", value.getP1(2, 0));
	EXPECT_EQ(3, value.getP1Size(2, 1));
	EXPECT_STREQ("s7", value.getP1(2, 1));
	EXPECT_EQ(3, value.getP1Size(2, 2));
	EXPECT_STREQ("s8", value.getP1(2, 2));

	value = xenums::Sstrs2::V2;
	EXPECT_EQ(0, value.getP1Size());

	value = xenums::Sstrs2::V3;
	EXPECT_EQ(3, value.getP1Size());
	EXPECT_EQ(1, value.getP1Size(0));
	EXPECT_EQ(5, value.getP1Size(0, 0));
	EXPECT_STREQ("foo2", value.getP1(0, 0));
	EXPECT_EQ(0, value.getP1Size(1));
	EXPECT_EQ(1, value.getP1Size(2));
	EXPECT_EQ(5, value.getP1Size(2, 0));
	EXPECT_STREQ("foo2", value.getP1(2, 0));
}


} // namespace xenum
} // namespace test
