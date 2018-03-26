/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */

// For debug only
#include <iostream>
#include <string>
#include <type_traits>

#include <gtest/gtest.h>
#include <test/xenum/xenums/FruitsNoNsNoCls.hpp>
#include <test/xenum/xenums/FruitsNoNsInCls.hpp>
#include <test/xenum/xenums/FruitsInNsNoCls.hpp>
#include <test/xenum/xenums/FruitsInNsInCls.hpp>
#include <test/xenum/xenums/Numbers.hpp>
#include <test/xenum/xenums/Icmp.hpp>

namespace test {
namespace xenum {


/**
 * Test the test enums.
 */
class TestXenums : public ::testing::Test {
public:
	bool success;

};


TEST_F(TestXenums, SelectInt)
{
	// 8 bits
	constexpr uint64_t value0 = 0x7f;
	typedef ::_XENUM4_NS::SelectInt<value0, false, false>::type type000;
	EXPECT_EQ(1, sizeof(type000));
	EXPECT_EQ(false, std::is_signed<type000>::value);

	typedef ::_XENUM4_NS::SelectInt<value0, false, true>::type type001;
	EXPECT_EQ(1, sizeof(type001));
	EXPECT_EQ(false, std::is_signed<type001>::value);

	typedef ::_XENUM4_NS::SelectInt<value0, true, false>::type type010;
	EXPECT_EQ(1, sizeof(type010));
	EXPECT_EQ(true, std::is_signed<type010>::value);

	typedef ::_XENUM4_NS::SelectInt<value0, true, true>::type type011;
	EXPECT_EQ(1, sizeof(type011));
	EXPECT_EQ(true, std::is_signed<type011>::value);

	// 8/16 bits
	constexpr uint64_t value1 = 0xff;
	typedef ::_XENUM4_NS::SelectInt<value1, false, false>::type type100;
	EXPECT_EQ(1, sizeof(type100));
	EXPECT_EQ(false, std::is_signed<type100>::value);

	typedef ::_XENUM4_NS::SelectInt<value1, false, true>::type type101;
	EXPECT_EQ(2, sizeof(type101));
	EXPECT_EQ(false, std::is_signed<type101>::value);

	typedef ::_XENUM4_NS::SelectInt<value1, true, false>::type type110;
	EXPECT_EQ(2, sizeof(type110));
	EXPECT_EQ(true, std::is_signed<type110>::value);

	typedef ::_XENUM4_NS::SelectInt<value1, true, true>::type type111;
	EXPECT_EQ(2, sizeof(type111));
	EXPECT_EQ(true, std::is_signed<type111>::value);

	// 16 bits
	constexpr uint64_t value2 = 0x7fff;
	typedef ::_XENUM4_NS::SelectInt<value2, false, false>::type type200;
	EXPECT_EQ(2, sizeof(type200));
	EXPECT_EQ(false, std::is_signed<type200>::value);

	typedef ::_XENUM4_NS::SelectInt<value2, false, true>::type type201;
	EXPECT_EQ(2, sizeof(type201));
	EXPECT_EQ(false, std::is_signed<type201>::value);

	typedef ::_XENUM4_NS::SelectInt<value2, true, false>::type type210;
	EXPECT_EQ(2, sizeof(type210));
	EXPECT_EQ(true, std::is_signed<type210>::value);

	typedef ::_XENUM4_NS::SelectInt<value2, true, true>::type type211;
	EXPECT_EQ(2, sizeof(type211));
	EXPECT_EQ(true, std::is_signed<type211>::value);

	// 16/32 bits
	constexpr uint64_t value3 = 0xffff;
	typedef ::_XENUM4_NS::SelectInt<value3, false, false>::type type300;
	EXPECT_EQ(2, sizeof(type300));
	EXPECT_EQ(false, std::is_signed<type300>::value);

	typedef ::_XENUM4_NS::SelectInt<value3, false, true>::type type301;
	EXPECT_EQ(4, sizeof(type301));
	EXPECT_EQ(false, std::is_signed<type301>::value);

	typedef ::_XENUM4_NS::SelectInt<value3, true, false>::type type310;
	EXPECT_EQ(4, sizeof(type310));
	EXPECT_EQ(true, std::is_signed<type310>::value);

	typedef ::_XENUM4_NS::SelectInt<value3, true, true>::type type311;
	EXPECT_EQ(4, sizeof(type311));
	EXPECT_EQ(true, std::is_signed<type311>::value);

	// 32 bits
	constexpr uint64_t value4 = 0x7fffffff;
	typedef ::_XENUM4_NS::SelectInt<value4, false, false>::type type400;
	EXPECT_EQ(4, sizeof(type400));
	EXPECT_EQ(false, std::is_signed<type400>::value);

	typedef ::_XENUM4_NS::SelectInt<value4, false, true>::type type401;
	EXPECT_EQ(4, sizeof(type401));
	EXPECT_EQ(false, std::is_signed<type401>::value);

	typedef ::_XENUM4_NS::SelectInt<value4, true, false>::type type410;
	EXPECT_EQ(4, sizeof(type410));
	EXPECT_EQ(true, std::is_signed<type410>::value);

	typedef ::_XENUM4_NS::SelectInt<value4, true, true>::type type411;
	EXPECT_EQ(4, sizeof(type411));
	EXPECT_EQ(true, std::is_signed<type411>::value);

	// 32/64 bits
	constexpr uint64_t value5 = 0xffffffff;
	typedef ::_XENUM4_NS::SelectInt<value5, false, false>::type type500;
	EXPECT_EQ(4, sizeof(type500));
	EXPECT_EQ(false, std::is_signed<type500>::value);

	typedef ::_XENUM4_NS::SelectInt<value5, false, true>::type type501;
	EXPECT_EQ(8, sizeof(type501));
	EXPECT_EQ(false, std::is_signed<type501>::value);

	typedef ::_XENUM4_NS::SelectInt<value5, true, false>::type type510;
	EXPECT_EQ(8, sizeof(type510));
	EXPECT_EQ(true, std::is_signed<type510>::value);

	typedef ::_XENUM4_NS::SelectInt<value5, true, true>::type type511;
	EXPECT_EQ(8, sizeof(type511));
	EXPECT_EQ(true, std::is_signed<type511>::value);

	// 64 bits
	constexpr uint64_t value6 = 0x7fffffffffffffff;
	typedef ::_XENUM4_NS::SelectInt<value6, false, false>::type type600;
	EXPECT_EQ(8, sizeof(type600));
	EXPECT_EQ(false, std::is_signed<type600>::value);

	typedef ::_XENUM4_NS::SelectInt<value6, false, true>::type type601;
	EXPECT_EQ(8, sizeof(type601));
	EXPECT_EQ(false, std::is_signed<type601>::value);

	typedef ::_XENUM4_NS::SelectInt<value6, true, false>::type type610;
	EXPECT_EQ(8, sizeof(type610));
	EXPECT_EQ(true, std::is_signed<type610>::value);

	typedef ::_XENUM4_NS::SelectInt<value6, true, true>::type type611;
	EXPECT_EQ(8, sizeof(type611));
	EXPECT_EQ(true, std::is_signed<type611>::value);

	// 64/128 bits
	constexpr uint64_t value7 = 0x8000000000000000;

	typedef ::_XENUM4_NS::SelectInt<value7, false, false>::type type700;
	EXPECT_EQ(8, sizeof(type700));
	EXPECT_EQ(false, std::is_signed<type700>::value);

	// 128-bit ints not supported. Compiler should fail on static_assert.
	//typedef ::_XENUM4_NS::SelectInt<value7, false, true>::type type701;
	//EXPECT_EQ(16, sizeof(type701));
	//EXPECT_EQ(false, std::is_signed<type701>::value);

	//typedef ::_XENUM4_NS::SelectInt<value7, true, false>::type type710;
	//EXPECT_EQ(16, sizeof(type710));
	//EXPECT_EQ(true, std::is_signed<type710>::value);

	//typedef ::_XENUM4_NS::SelectInt<value7, true, true>::type type711;
	//EXPECT_EQ(16, sizeof(type711));
	//EXPECT_EQ(true, std::is_signed<type711>::value);

	// Boundary check.
	constexpr uint64_t value8 = 0xffffffffffffffff;

	typedef ::_XENUM4_NS::SelectInt<value8, false, false>::type type800;
	EXPECT_EQ(8, sizeof(type800));
	EXPECT_EQ(false, std::is_signed<type800>::value);
}


TEST_F(TestXenums, FruitsNoNsNoCls)
{
	EXPECT_EQ(1, sizeof(XenumFruits::index_t));
	EXPECT_EQ(false, std::is_signed<XenumFruits::index_t>::value);
	EXPECT_EQ(2, XenumFruits::size);
	XenumFruit fruit0 = XenumFruits::apple;
	XenumFruit fruit1 = XenumFruits::grape;
	EXPECT_EQ(0, fruit0.getIndex());
	EXPECT_EQ(1, fruit1.getIndex());
}


TEST_F(TestXenums, FruitsNoNsInCls)
{
	EXPECT_EQ(1, sizeof(XenumWrapNoNs::Fruits::index_t));
	EXPECT_EQ(false, std::is_signed<XenumWrapNoNs::Fruits::index_t>::value);
	EXPECT_EQ(3, XenumWrapNoNs::Fruits::size);
	XenumWrapNoNs::Fruit fruit0 = XenumWrapNoNs::Fruits::banana;
	XenumWrapNoNs::Fruit fruit1 = XenumWrapNoNs::Fruits::orange;
	XenumWrapNoNs::Fruit fruit2 = XenumWrapNoNs::Fruits::peanut;
	EXPECT_EQ(0, fruit0.getIndex());
	EXPECT_EQ(1, fruit1.getIndex());
	EXPECT_EQ(2, fruit2.getIndex());
}


TEST_F(TestXenums, FruitsInNsNoCls)
{
	EXPECT_EQ(4, sizeof(xenums::Fruits::index_t));
	EXPECT_EQ(false, std::is_signed<xenums::Fruits::index_t>::value);
	EXPECT_EQ(4, xenums::Fruits::size);
	xenums::Fruit fruit0 = xenums::Fruits::tomato;
	xenums::Fruit fruit1 = xenums::Fruits::pear;
	xenums::Fruit fruit2 = xenums::Fruits::lime;
	xenums::Fruit fruit3 = xenums::Fruits::lemon;
	EXPECT_EQ(0, fruit0.getIndex());
	EXPECT_EQ(1, fruit1.getIndex());
	EXPECT_EQ(2, fruit2.getIndex());
	EXPECT_EQ(3, fruit3.getIndex());
}


TEST_F(TestXenums, FruitsInNsInCls)
{
	EXPECT_EQ(8, sizeof(xenums::WrapInNs::Fruits::index_t));
	EXPECT_EQ(false, std::is_signed<xenums::WrapInNs::Fruits::index_t>::value);
	EXPECT_EQ(5, xenums::WrapInNs::Fruits::size);
	xenums::WrapInNs::Fruit fruit0 = xenums::WrapInNs::Fruits::plum;
	xenums::WrapInNs::Fruit fruit1 = xenums::WrapInNs::Fruits::mango;
	xenums::WrapInNs::Fruit fruit2 = xenums::WrapInNs::Fruits::melon;
	xenums::WrapInNs::Fruit fruit3 = xenums::WrapInNs::Fruits::kiwi;
	xenums::WrapInNs::Fruit fruit4 = xenums::WrapInNs::Fruits::guava;
	EXPECT_EQ(0, fruit0.getIndex());
	EXPECT_EQ(1, fruit1.getIndex());
	EXPECT_EQ(2, fruit2.getIndex());
	EXPECT_EQ(3, fruit3.getIndex());
	EXPECT_EQ(4, fruit4.getIndex());
	//std::cout<<"hasProps="<<xenums::WrapInNs::Fruits::hasProps()<<std::endl;
}


TEST_F(TestXenums, Numbers)
{
	EXPECT_EQ(2, sizeof(xenums::Numbers::index_t));
	EXPECT_EQ(false, std::is_signed<xenums::Numbers::index_t>::value);
	EXPECT_EQ(4100, xenums::Numbers::size);
	xenums::Number number0001 = xenums::Numbers::n0001;
	xenums::Number number0200 = xenums::Numbers::n0200;
	xenums::Number number1768 = xenums::Numbers::n1718;
	xenums::Number number4100 = xenums::Numbers::n4100;
	EXPECT_LT(number0001, number0200);
	EXPECT_LT(number0200, number1768);
	EXPECT_LT(number1768, number4100);
	//std::cout<<"hasProps="<<xenums::Numbers::hasProps()<<std::endl;
}


TEST_F(TestXenums, IcmpTypes)
{
	EXPECT_EQ(1, sizeof(xenums::IcmpTypes::index_t));
	EXPECT_EQ(false, std::is_signed<xenums::IcmpTypes::index_t>::value);
	EXPECT_EQ(35, xenums::IcmpTypes::size);
	xenums::IcmpType echoRequest = xenums::IcmpTypes::EchoRequest;
	xenums::IcmpType timestampRequest = xenums::IcmpTypes::TimestampRequest;
	xenums::IcmpType rplControl = xenums::IcmpTypes::RplControl;
	EXPECT_GT(rplControl, timestampRequest);
	EXPECT_GT(timestampRequest, echoRequest);

	EXPECT_EQ(true, echoRequest.getIpv4());
	EXPECT_EQ(true, echoRequest.getIpv6());
	EXPECT_EQ(true, timestampRequest.getIpv4());
	EXPECT_EQ(false, timestampRequest.getIpv6());
	EXPECT_EQ(false, rplControl.getIpv4());
	EXPECT_EQ(true, rplControl.getIpv6());

	//std::cout<<"hasProps="<<xenums::IcmpTypes::hasProps()<<std::endl;
	//std::cout<<"NfName_valuecount_ = "<<xenums::IcmpTypes::NfName_valuecount_<<std::endl;
}


TEST_F(TestXenums, IcmpCodes)
{
	EXPECT_EQ(1, sizeof(xenums::IcmpCodes::index_t));
	EXPECT_EQ(false, std::is_signed<xenums::IcmpCodes::index_t>::value);
	EXPECT_EQ(35, xenums::IcmpCodes::size);
	xenums::IcmpCode networkUnreachable = xenums::IcmpCodes::NetworkUnreachable;
	xenums::IcmpCode networkRedirect = xenums::IcmpCodes::NetworkRedirect;
	xenums::IcmpCode unknownNextHeader = xenums::IcmpCodes::UnknownNextHeader;
	EXPECT_GT(unknownNextHeader, networkRedirect);
	EXPECT_GT(networkRedirect, networkUnreachable);

	EXPECT_EQ(true, networkUnreachable.getIpv4());
	EXPECT_EQ(true, networkUnreachable.getIpv6());
	EXPECT_EQ(true, networkRedirect.getIpv4());
	EXPECT_EQ(false, networkRedirect.getIpv6());
	EXPECT_EQ(false, unknownNextHeader.getIpv4());
	EXPECT_EQ(true, unknownNextHeader.getIpv6());

	EXPECT_EQ(xenums::IcmpTypes::DestinationUnreachable, networkUnreachable.getIcmpType()());
	EXPECT_EQ(xenums::IcmpTypes::Redirect, networkRedirect.getIcmpType()());
	EXPECT_EQ(xenums::IcmpTypes::ParameterProblem, unknownNextHeader.getIcmpType()());
}


} // namespace xenum
} // namespace test
