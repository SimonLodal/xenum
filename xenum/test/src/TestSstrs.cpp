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
	xenums::Sstr0 ovalue;

	// P0
	ovalue = xenums::Sstrs0::V0;
	EXPECT_EQ(1, ovalue.getP0());
	ovalue = xenums::Sstrs0::V1;
	EXPECT_EQ(2, ovalue.getP0());
	ovalue = xenums::Sstrs0::V2;
	EXPECT_EQ(-1, ovalue.getP0());
	ovalue = xenums::Sstrs0::V3;
	EXPECT_EQ(3, ovalue.getP0());

	// P1
	ovalue = xenums::Sstrs0::V0;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_STREQ("s1", ovalue.getP1());
	ovalue = xenums::Sstrs0::V1;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_STREQ("s2", ovalue.getP1());
	ovalue = xenums::Sstrs0::V2;
	EXPECT_EQ(5, ovalue.getP1Size());
	EXPECT_STREQ("foo0", ovalue.getP1());
	ovalue = xenums::Sstrs0::V3;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_STREQ("s3", ovalue.getP1());
}


TEST_F(TestSstrs, D1Values)
{
	xenums::Sstr1 ovalue;

	// P0
	ovalue = xenums::Sstrs1::V0;
	EXPECT_EQ(3, ovalue.getP0Size());
	EXPECT_EQ(1, ovalue.getP0(0));
	EXPECT_EQ(2, ovalue.getP0(1));
	EXPECT_EQ(3, ovalue.getP0(2));

	ovalue = xenums::Sstrs1::V1;
	EXPECT_EQ(1, ovalue.getP0Size());
	EXPECT_EQ(4, ovalue.getP0(0));

	ovalue = xenums::Sstrs1::V2;
	EXPECT_EQ(0, ovalue.getP0Size());

	ovalue = xenums::Sstrs1::V3;
	EXPECT_EQ(2, ovalue.getP0Size());
	EXPECT_EQ(5, ovalue.getP0(0));
	EXPECT_EQ(6, ovalue.getP0(1));

	// P1
	ovalue = xenums::Sstrs1::V0;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_EQ(3, ovalue.getP1Size(0));
	EXPECT_STREQ("s1", ovalue.getP1(0));
	EXPECT_EQ(3, ovalue.getP1Size(1));
	EXPECT_STREQ("s2", ovalue.getP1(1));
	EXPECT_EQ(3, ovalue.getP1Size(2));
	EXPECT_STREQ("s3", ovalue.getP1(2));

	ovalue = xenums::Sstrs1::V1;
	EXPECT_EQ(1, ovalue.getP1Size());
 	EXPECT_EQ(3, ovalue.getP1Size(0));
 	EXPECT_STREQ("s4", ovalue.getP1(0));

	ovalue = xenums::Sstrs1::V2;
	EXPECT_EQ(0, ovalue.getP1Size());

	ovalue = xenums::Sstrs1::V3;
	EXPECT_EQ(2, ovalue.getP1Size());
 	EXPECT_EQ(3, ovalue.getP1Size(0));
 	EXPECT_STREQ("s5", ovalue.getP1(0));
 	EXPECT_EQ(3, ovalue.getP1Size(1));
 	EXPECT_STREQ("s6", ovalue.getP1(1));
}


TEST_F(TestSstrs, D2Values)
{
	xenums::Sstr2 ovalue;

	// P0
	ovalue = xenums::Sstrs2::V0;
	EXPECT_EQ(2, ovalue.getP0Size());
	EXPECT_EQ(1, ovalue.getP0Size(0));
	EXPECT_EQ(1, ovalue.getP0(0, 0));
	EXPECT_EQ(2, ovalue.getP0Size(1));
	EXPECT_EQ(2, ovalue.getP0(1, 0));
	EXPECT_EQ(3, ovalue.getP0(1, 1));

	ovalue = xenums::Sstrs2::V1;
	EXPECT_EQ(3, ovalue.getP0Size());
	EXPECT_EQ(1, ovalue.getP0Size(0));
	EXPECT_EQ(4, ovalue.getP0(0, 0));
	EXPECT_EQ(1, ovalue.getP0Size(1));
	EXPECT_EQ(5, ovalue.getP0(1, 0));
	EXPECT_EQ(3, ovalue.getP0Size(2));
	EXPECT_EQ(6, ovalue.getP0(2, 0));
	EXPECT_EQ(7, ovalue.getP0(2, 1));
	EXPECT_EQ(8, ovalue.getP0(2, 2));

	ovalue = xenums::Sstrs2::V2;
	EXPECT_EQ(0, ovalue.getP0Size());

	ovalue = xenums::Sstrs2::V3;
	EXPECT_EQ(3, ovalue.getP0Size());
	EXPECT_EQ(1, ovalue.getP0Size(0));
	EXPECT_EQ(-1, ovalue.getP0(0, 0));
	EXPECT_EQ(0, ovalue.getP0Size(1));
	EXPECT_EQ(1, ovalue.getP0Size(2));
	EXPECT_EQ(-1, ovalue.getP0(2, 0));

	// P1
	ovalue = xenums::Sstrs2::V0;
	EXPECT_EQ(2, ovalue.getP1Size());
	EXPECT_EQ(1, ovalue.getP1Size(0));
	EXPECT_EQ(3, ovalue.getP1Size(0, 0));
	EXPECT_STREQ("s1", ovalue.getP1(0, 0));
	EXPECT_EQ(2, ovalue.getP1Size(1));
	EXPECT_EQ(3, ovalue.getP1Size(1, 0));
	EXPECT_STREQ("s2", ovalue.getP1(1, 0));
	EXPECT_EQ(3, ovalue.getP1Size(1, 1));
	EXPECT_STREQ("s3", ovalue.getP1(1, 1));

	ovalue = xenums::Sstrs2::V1;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_EQ(1, ovalue.getP1Size(0));
	EXPECT_EQ(3, ovalue.getP1Size(0, 0));
	EXPECT_STREQ("s4", ovalue.getP1(0, 0));
	EXPECT_EQ(1, ovalue.getP1Size(1));
	EXPECT_EQ(3, ovalue.getP1Size(1, 0));
	EXPECT_STREQ("s5", ovalue.getP1(1, 0));
	EXPECT_EQ(3, ovalue.getP1Size(2));
	EXPECT_EQ(3, ovalue.getP1Size(2, 0));
	EXPECT_STREQ("s6", ovalue.getP1(2, 0));
	EXPECT_EQ(3, ovalue.getP1Size(2, 1));
	EXPECT_STREQ("s7", ovalue.getP1(2, 1));
	EXPECT_EQ(3, ovalue.getP1Size(2, 2));
	EXPECT_STREQ("s8", ovalue.getP1(2, 2));

	ovalue = xenums::Sstrs2::V2;
	EXPECT_EQ(0, ovalue.getP1Size());

	ovalue = xenums::Sstrs2::V3;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_EQ(1, ovalue.getP1Size(0));
	EXPECT_EQ(5, ovalue.getP1Size(0, 0));
	EXPECT_STREQ("foo2", ovalue.getP1(0, 0));
	EXPECT_EQ(0, ovalue.getP1Size(1));
	EXPECT_EQ(1, ovalue.getP1Size(2));
	EXPECT_EQ(5, ovalue.getP1Size(2, 0));
	EXPECT_STREQ("foo2", ovalue.getP1(2, 0));
}


} // namespace xenum
} // namespace test
