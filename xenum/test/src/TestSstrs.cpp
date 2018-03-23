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
#include <test/xenum/xenums/Sstrs.hpp>

namespace test {
namespace xenum {


/**
 * Test xenum with custom string properties defined in source file.
 */
class TestSstrs : public ::testing::Test {
public:
	bool success;

	xenums::Sstr ovalue;
};


TEST_F(TestSstrs, Sstrs)
{
	EXPECT_EQ(1, sizeof(xenums::Sstrs::index_t));
//	std::cout<<"Sstrs::size = "<<xenums::Sstrs::size<<std::endl;
//	for (auto sstr : xenums::Sstrs()) {
// 		std::cout<<"sstr: "<<xenums::Sstr(sstr)<<std::endl;
// 	}
}


#if SSTRS_DEPTH == 0
TEST_F(TestSstrs, D0Values)
{
	// P0
	ovalue = xenums::Sstrs::V0;
	EXPECT_EQ(1, ovalue.getP0());
	ovalue = xenums::Sstrs::V1;
	EXPECT_EQ(2, ovalue.getP0());
	ovalue = xenums::Sstrs::V2;
	EXPECT_EQ(-1, ovalue.getP0());
	ovalue = xenums::Sstrs::V3;
	EXPECT_EQ(3, ovalue.getP0());

	// P1
	ovalue = xenums::Sstrs::V0;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_STREQ("s1", ovalue.getP1());
	ovalue = xenums::Sstrs::V1;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_STREQ("s2", ovalue.getP1());
	ovalue = xenums::Sstrs::V2;
	EXPECT_EQ(5, ovalue.getP1Size());
	EXPECT_STREQ("foo0", ovalue.getP1());
	ovalue = xenums::Sstrs::V3;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_STREQ("s3", ovalue.getP1());
}


#elif SSTRS_DEPTH == 1
TEST_F(TestSstrs, D1Values)
{
	// P0
	ovalue = xenums::Sstrs::V0;
	EXPECT_EQ(3, ovalue.getP0Size());
	EXPECT_EQ(1, ovalue.getP0(0));
	EXPECT_EQ(2, ovalue.getP0(1));
	EXPECT_EQ(3, ovalue.getP0(2));

	ovalue = xenums::Sstrs::V1;
	EXPECT_EQ(1, ovalue.getP0Size());
	EXPECT_EQ(4, ovalue.getP0(0));

	ovalue = xenums::Sstrs::V2;
	EXPECT_EQ(0, ovalue.getP0Size());

	ovalue = xenums::Sstrs::V3;
	EXPECT_EQ(2, ovalue.getP0Size());
	EXPECT_EQ(5, ovalue.getP0(0));
	EXPECT_EQ(6, ovalue.getP0(1));

	// P1
	ovalue = xenums::Sstrs::V0;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_EQ(3, ovalue.getP1Size(0));
	EXPECT_STREQ("s1", ovalue.getP1(0));
	EXPECT_EQ(3, ovalue.getP1Size(1));
	EXPECT_STREQ("s2", ovalue.getP1(1));
	EXPECT_EQ(3, ovalue.getP1Size(2));
	EXPECT_STREQ("s3", ovalue.getP1(2));

	ovalue = xenums::Sstrs::V1;
	EXPECT_EQ(1, ovalue.getP1Size());
 	EXPECT_EQ(3, ovalue.getP1Size(0));
 	EXPECT_STREQ("s4", ovalue.getP1(0));

	ovalue = xenums::Sstrs::V2;
	EXPECT_EQ(0, ovalue.getP1Size());

	ovalue = xenums::Sstrs::V3;
	EXPECT_EQ(2, ovalue.getP1Size());
 	EXPECT_EQ(3, ovalue.getP1Size(0));
 	EXPECT_STREQ("s5", ovalue.getP1(0));
 	EXPECT_EQ(3, ovalue.getP1Size(1));
 	EXPECT_STREQ("s6", ovalue.getP1(1));
}


#elif SSTRS_DEPTH == 2
TEST_F(TestSstrs, D2Values)
{
	// P0
	ovalue = xenums::Sstrs::V0;
	EXPECT_EQ(2, ovalue.getP0Size());
	EXPECT_EQ(1, ovalue.getP0Size(0));
	EXPECT_EQ(1, ovalue.getP0(0, 0));
	EXPECT_EQ(2, ovalue.getP0Size(1));
	EXPECT_EQ(2, ovalue.getP0(1, 0));
	EXPECT_EQ(3, ovalue.getP0(1, 1));

	ovalue = xenums::Sstrs::V1;
	EXPECT_EQ(3, ovalue.getP0Size());
	EXPECT_EQ(1, ovalue.getP0Size(0));
	EXPECT_EQ(4, ovalue.getP0(0, 0));
	EXPECT_EQ(1, ovalue.getP0Size(1));
	EXPECT_EQ(5, ovalue.getP0(1, 0));
	EXPECT_EQ(3, ovalue.getP0Size(2));
	EXPECT_EQ(6, ovalue.getP0(2, 0));
	EXPECT_EQ(7, ovalue.getP0(2, 1));
	EXPECT_EQ(8, ovalue.getP0(2, 2));

	ovalue = xenums::Sstrs::V2;
	EXPECT_EQ(0, ovalue.getP0Size());

	ovalue = xenums::Sstrs::V3;
	EXPECT_EQ(3, ovalue.getP0Size());
	EXPECT_EQ(1, ovalue.getP0Size(0));
	EXPECT_EQ(-1, ovalue.getP0(0, 0));
	EXPECT_EQ(0, ovalue.getP0Size(1));
	EXPECT_EQ(1, ovalue.getP0Size(2));
	EXPECT_EQ(-1, ovalue.getP0(2, 0));

	// P1
	ovalue = xenums::Sstrs::V0;
	EXPECT_EQ(2, ovalue.getP1Size());
	EXPECT_EQ(1, ovalue.getP1Size(0));
	EXPECT_EQ(3, ovalue.getP1Size(0, 0));
	EXPECT_STREQ("s1", ovalue.getP1(0, 0));
	EXPECT_EQ(2, ovalue.getP1Size(1));
	EXPECT_EQ(3, ovalue.getP1Size(1, 0));
	EXPECT_STREQ("s2", ovalue.getP1(1, 0));
	EXPECT_EQ(3, ovalue.getP1Size(1, 1));
	EXPECT_STREQ("s3", ovalue.getP1(1, 1));

	ovalue = xenums::Sstrs::V1;
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

	ovalue = xenums::Sstrs::V2;
	EXPECT_EQ(0, ovalue.getP1Size());

	ovalue = xenums::Sstrs::V3;
	EXPECT_EQ(3, ovalue.getP1Size());
	EXPECT_EQ(1, ovalue.getP1Size(0));
	EXPECT_EQ(5, ovalue.getP1Size(0, 0));
	EXPECT_STREQ("foo2", ovalue.getP1(0, 0));
	EXPECT_EQ(0, ovalue.getP1Size(1));
	EXPECT_EQ(1, ovalue.getP1Size(2));
	EXPECT_EQ(5, ovalue.getP1Size(2, 0));
	EXPECT_STREQ("foo2", ovalue.getP1(2, 0));
}


#endif // SSTRS_DEPTH


} // namespace xenum
} // namespace test
