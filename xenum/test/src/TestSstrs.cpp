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
	EXPECT_EQ(1, xenums::Sstrs::getP0(xenums::Sstrs::V0));
	EXPECT_EQ(2, xenums::Sstrs::getP0(xenums::Sstrs::V1));
	EXPECT_EQ(-1, xenums::Sstrs::getP0(xenums::Sstrs::V2));
	EXPECT_EQ(3, xenums::Sstrs::getP0(xenums::Sstrs::V3));

	// P1
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V0));
	EXPECT_STREQ("s1", xenums::Sstrs::getP1(xenums::Sstrs::V0));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V1));
	EXPECT_STREQ("s2", xenums::Sstrs::getP1(xenums::Sstrs::V1));
	EXPECT_EQ(5, xenums::Sstrs::getP1Size(xenums::Sstrs::V2));
	EXPECT_STREQ("foo0", xenums::Sstrs::getP1(xenums::Sstrs::V2));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V3));
	EXPECT_STREQ("s3", xenums::Sstrs::getP1(xenums::Sstrs::V3));
}


#elif SSTRS_DEPTH == 1
TEST_F(TestSstrs, D1Values)
{
	// P0
	EXPECT_EQ(3, xenums::Sstrs::getP0Size(xenums::Sstrs::V0));
	EXPECT_EQ(1, xenums::Sstrs::getP0(xenums::Sstrs::V0, 0));
	EXPECT_EQ(2, xenums::Sstrs::getP0(xenums::Sstrs::V0, 1));
	EXPECT_EQ(3, xenums::Sstrs::getP0(xenums::Sstrs::V0, 2));

	EXPECT_EQ(1, xenums::Sstrs::getP0Size(xenums::Sstrs::V1));
	EXPECT_EQ(4, xenums::Sstrs::getP0(xenums::Sstrs::V1, 0));

	EXPECT_EQ(0, xenums::Sstrs::getP0Size(xenums::Sstrs::V2));

	EXPECT_EQ(2, xenums::Sstrs::getP0Size(xenums::Sstrs::V3));
	EXPECT_EQ(5, xenums::Sstrs::getP0(xenums::Sstrs::V3, 0));
	EXPECT_EQ(6, xenums::Sstrs::getP0(xenums::Sstrs::V3, 1));

	// P1
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V0));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V0, 0));
	EXPECT_STREQ("s1", xenums::Sstrs::getP1(xenums::Sstrs::V0, 0));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V0, 1));
	EXPECT_STREQ("s2", xenums::Sstrs::getP1(xenums::Sstrs::V0, 1));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V0, 2));
	EXPECT_STREQ("s3", xenums::Sstrs::getP1(xenums::Sstrs::V0, 2));

	EXPECT_EQ(1, xenums::Sstrs::getP1Size(xenums::Sstrs::V1));
 	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V1, 0));
 	EXPECT_STREQ("s4", xenums::Sstrs::getP1(xenums::Sstrs::V1, 0));

	EXPECT_EQ(0, xenums::Sstrs::getP1Size(xenums::Sstrs::V2));

	EXPECT_EQ(2, xenums::Sstrs::getP1Size(xenums::Sstrs::V3));
 	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V3, 0));
 	EXPECT_STREQ("s5", xenums::Sstrs::getP1(xenums::Sstrs::V3, 0));
 	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V3, 1));
 	EXPECT_STREQ("s6", xenums::Sstrs::getP1(xenums::Sstrs::V3, 1));
}


#elif SSTRS_DEPTH == 2
TEST_F(TestSstrs, D2Values)
{
	// P0
	EXPECT_EQ(2, xenums::Sstrs::getP0Size(xenums::Sstrs::V0));
	EXPECT_EQ(1, xenums::Sstrs::getP0Size(xenums::Sstrs::V0, 0));
	EXPECT_EQ(1, xenums::Sstrs::getP0(xenums::Sstrs::V0, 0, 0));
	EXPECT_EQ(2, xenums::Sstrs::getP0Size(xenums::Sstrs::V0, 1));
	EXPECT_EQ(2, xenums::Sstrs::getP0(xenums::Sstrs::V0, 1, 0));
	EXPECT_EQ(3, xenums::Sstrs::getP0(xenums::Sstrs::V0, 1, 1));

	EXPECT_EQ(3, xenums::Sstrs::getP0Size(xenums::Sstrs::V1));
	EXPECT_EQ(1, xenums::Sstrs::getP0Size(xenums::Sstrs::V1, 0));
	EXPECT_EQ(4, xenums::Sstrs::getP0(xenums::Sstrs::V1, 0, 0));
	EXPECT_EQ(1, xenums::Sstrs::getP0Size(xenums::Sstrs::V1, 1));
	EXPECT_EQ(5, xenums::Sstrs::getP0(xenums::Sstrs::V1, 1, 0));
	EXPECT_EQ(3, xenums::Sstrs::getP0Size(xenums::Sstrs::V1, 2));
	EXPECT_EQ(6, xenums::Sstrs::getP0(xenums::Sstrs::V1, 2, 0));
	EXPECT_EQ(7, xenums::Sstrs::getP0(xenums::Sstrs::V1, 2, 1));
	EXPECT_EQ(8, xenums::Sstrs::getP0(xenums::Sstrs::V1, 2, 2));

	EXPECT_EQ(0, xenums::Sstrs::getP0Size(xenums::Sstrs::V2));

	EXPECT_EQ(3, xenums::Sstrs::getP0Size(xenums::Sstrs::V3));
	EXPECT_EQ(1, xenums::Sstrs::getP0Size(xenums::Sstrs::V3, 0));
	EXPECT_EQ(-1, xenums::Sstrs::getP0(xenums::Sstrs::V3, 0, 0));
	EXPECT_EQ(0, xenums::Sstrs::getP0Size(xenums::Sstrs::V3, 1));
	EXPECT_EQ(1, xenums::Sstrs::getP0Size(xenums::Sstrs::V3, 2));
	EXPECT_EQ(-1, xenums::Sstrs::getP0(xenums::Sstrs::V3, 2, 0));

	// P1
	EXPECT_EQ(2, xenums::Sstrs::getP1Size(xenums::Sstrs::V0));
	EXPECT_EQ(1, xenums::Sstrs::getP1Size(xenums::Sstrs::V0, 0));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V0, 0, 0));
	EXPECT_STREQ("s1", xenums::Sstrs::getP1(xenums::Sstrs::V0, 0, 0));
	EXPECT_EQ(2, xenums::Sstrs::getP1Size(xenums::Sstrs::V0, 1));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V0, 1, 0));
	EXPECT_STREQ("s2", xenums::Sstrs::getP1(xenums::Sstrs::V0, 1, 0));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V0, 1, 1));
	EXPECT_STREQ("s3", xenums::Sstrs::getP1(xenums::Sstrs::V0, 1, 1));

	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V1));
	EXPECT_EQ(1, xenums::Sstrs::getP1Size(xenums::Sstrs::V1, 0));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V1, 0, 0));
	EXPECT_STREQ("s4", xenums::Sstrs::getP1(xenums::Sstrs::V1, 0, 0));
	EXPECT_EQ(1, xenums::Sstrs::getP1Size(xenums::Sstrs::V1, 1));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V1, 1, 0));
	EXPECT_STREQ("s5", xenums::Sstrs::getP1(xenums::Sstrs::V1, 1, 0));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V1, 2));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V1, 2, 0));
	EXPECT_STREQ("s6", xenums::Sstrs::getP1(xenums::Sstrs::V1, 2, 0));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V1, 2, 1));
	EXPECT_STREQ("s7", xenums::Sstrs::getP1(xenums::Sstrs::V1, 2, 1));
	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V1, 2, 2));
	EXPECT_STREQ("s8", xenums::Sstrs::getP1(xenums::Sstrs::V1, 2, 2));

	EXPECT_EQ(0, xenums::Sstrs::getP1Size(xenums::Sstrs::V2));

	EXPECT_EQ(3, xenums::Sstrs::getP1Size(xenums::Sstrs::V3));
	EXPECT_EQ(1, xenums::Sstrs::getP1Size(xenums::Sstrs::V3, 0));
	EXPECT_EQ(5, xenums::Sstrs::getP1Size(xenums::Sstrs::V3, 0, 0));
	EXPECT_STREQ("foo2", xenums::Sstrs::getP1(xenums::Sstrs::V3, 0, 0));
	EXPECT_EQ(0, xenums::Sstrs::getP1Size(xenums::Sstrs::V3, 1));
	EXPECT_EQ(1, xenums::Sstrs::getP1Size(xenums::Sstrs::V3, 2));
	EXPECT_EQ(5, xenums::Sstrs::getP1Size(xenums::Sstrs::V3, 2, 0));
	EXPECT_STREQ("foo2", xenums::Sstrs::getP1(xenums::Sstrs::V3, 2, 0));
}


#endif // SSTRS_DEPTH


} // namespace xenum
} // namespace test
