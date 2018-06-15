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


/// Test the SelectInt template.
TEST_F(TestXenums, SelectInt)
{
	// 8 bits
	constexpr uint64_t value0 = 0x7f;
	using type000 = ::_XENUM5_NS::SelectInt<value0, false, false>::type;
	EXPECT_EQ(1, sizeof(type000));
	EXPECT_EQ(false, std::is_signed<type000>::value);

	using type001 = ::_XENUM5_NS::SelectInt<value0, false, true>::type;
	EXPECT_EQ(1, sizeof(type001));
	EXPECT_EQ(false, std::is_signed<type001>::value);

	using type010 = ::_XENUM5_NS::SelectInt<value0, true, false>::type;
	EXPECT_EQ(1, sizeof(type010));
	EXPECT_EQ(true, std::is_signed<type010>::value);

	using type011 = ::_XENUM5_NS::SelectInt<value0, true, true>::type;
	EXPECT_EQ(1, sizeof(type011));
	EXPECT_EQ(true, std::is_signed<type011>::value);

	// 8/16 bits
	constexpr uint64_t value1 = 0xff;
	using type100 = ::_XENUM5_NS::SelectInt<value1, false, false>::type;
	EXPECT_EQ(1, sizeof(type100));
	EXPECT_EQ(false, std::is_signed<type100>::value);

	using type101 = ::_XENUM5_NS::SelectInt<value1, false, true>::type;
	EXPECT_EQ(2, sizeof(type101));
	EXPECT_EQ(false, std::is_signed<type101>::value);

	using type110 = ::_XENUM5_NS::SelectInt<value1, true, false>::type;
	EXPECT_EQ(2, sizeof(type110));
	EXPECT_EQ(true, std::is_signed<type110>::value);

	using type111 = ::_XENUM5_NS::SelectInt<value1, true, true>::type;
	EXPECT_EQ(2, sizeof(type111));
	EXPECT_EQ(true, std::is_signed<type111>::value);

	// 16 bits
	constexpr uint64_t value2 = 0x7fff;
	using type200 = ::_XENUM5_NS::SelectInt<value2, false, false>::type;
	EXPECT_EQ(2, sizeof(type200));
	EXPECT_EQ(false, std::is_signed<type200>::value);

	using type201 = ::_XENUM5_NS::SelectInt<value2, false, true>::type;
	EXPECT_EQ(2, sizeof(type201));
	EXPECT_EQ(false, std::is_signed<type201>::value);

	using type210 = ::_XENUM5_NS::SelectInt<value2, true, false>::type;
	EXPECT_EQ(2, sizeof(type210));
	EXPECT_EQ(true, std::is_signed<type210>::value);

	using type211 = ::_XENUM5_NS::SelectInt<value2, true, true>::type;
	EXPECT_EQ(2, sizeof(type211));
	EXPECT_EQ(true, std::is_signed<type211>::value);

	// 16/32 bits
	constexpr uint64_t value3 = 0xffff;
	using type300 = ::_XENUM5_NS::SelectInt<value3, false, false>::type;
	EXPECT_EQ(2, sizeof(type300));
	EXPECT_EQ(false, std::is_signed<type300>::value);

	using type301 = ::_XENUM5_NS::SelectInt<value3, false, true>::type;
	EXPECT_EQ(4, sizeof(type301));
	EXPECT_EQ(false, std::is_signed<type301>::value);

	using type310 = ::_XENUM5_NS::SelectInt<value3, true, false>::type;
	EXPECT_EQ(4, sizeof(type310));
	EXPECT_EQ(true, std::is_signed<type310>::value);

	using type311 = ::_XENUM5_NS::SelectInt<value3, true, true>::type;
	EXPECT_EQ(4, sizeof(type311));
	EXPECT_EQ(true, std::is_signed<type311>::value);

	// 32 bits
	constexpr uint64_t value4 = 0x7fffffff;
	using type400 = ::_XENUM5_NS::SelectInt<value4, false, false>::type;
	EXPECT_EQ(4, sizeof(type400));
	EXPECT_EQ(false, std::is_signed<type400>::value);

	using type401 = ::_XENUM5_NS::SelectInt<value4, false, true>::type;
	EXPECT_EQ(4, sizeof(type401));
	EXPECT_EQ(false, std::is_signed<type401>::value);

	using type410 = ::_XENUM5_NS::SelectInt<value4, true, false>::type;
	EXPECT_EQ(4, sizeof(type410));
	EXPECT_EQ(true, std::is_signed<type410>::value);

	using type411 = ::_XENUM5_NS::SelectInt<value4, true, true>::type;
	EXPECT_EQ(4, sizeof(type411));
	EXPECT_EQ(true, std::is_signed<type411>::value);

	// 32/64 bits
	constexpr uint64_t value5 = 0xffffffff;
	using type500 = ::_XENUM5_NS::SelectInt<value5, false, false>::type;
	EXPECT_EQ(4, sizeof(type500));
	EXPECT_EQ(false, std::is_signed<type500>::value);

	using type501 = ::_XENUM5_NS::SelectInt<value5, false, true>::type;
	EXPECT_EQ(8, sizeof(type501));
	EXPECT_EQ(false, std::is_signed<type501>::value);

	using type510 = ::_XENUM5_NS::SelectInt<value5, true, false>::type;
	EXPECT_EQ(8, sizeof(type510));
	EXPECT_EQ(true, std::is_signed<type510>::value);

	using type511 = ::_XENUM5_NS::SelectInt<value5, true, true>::type;
	EXPECT_EQ(8, sizeof(type511));
	EXPECT_EQ(true, std::is_signed<type511>::value);

	// 64 bits
	constexpr uint64_t value6 = 0x7fffffffffffffff;
	using type600 = ::_XENUM5_NS::SelectInt<value6, false, false>::type;
	EXPECT_EQ(8, sizeof(type600));
	EXPECT_EQ(false, std::is_signed<type600>::value);

	using type601 = ::_XENUM5_NS::SelectInt<value6, false, true>::type;
	EXPECT_EQ(8, sizeof(type601));
	EXPECT_EQ(false, std::is_signed<type601>::value);

	using type610 = ::_XENUM5_NS::SelectInt<value6, true, false>::type;
	EXPECT_EQ(8, sizeof(type610));
	EXPECT_EQ(true, std::is_signed<type610>::value);

	using type611 = ::_XENUM5_NS::SelectInt<value6, true, true>::type;
	EXPECT_EQ(8, sizeof(type611));
	EXPECT_EQ(true, std::is_signed<type611>::value);

	// 64/128 bits
	constexpr uint64_t value7 = 0x8000000000000000;

	using type700 = ::_XENUM5_NS::SelectInt<value7, false, false>::type;
	EXPECT_EQ(8, sizeof(type700));
	EXPECT_EQ(false, std::is_signed<type700>::value);

	// 128-bit ints not supported. Compiler should fail on static_assert.
	//using type701 = ::_XENUM5_NS::SelectInt<value7, false, true>::type;
	//EXPECT_EQ(16, sizeof(type701));
	//EXPECT_EQ(false, std::is_signed<type701>::value);

	//using type710 = ::_XENUM5_NS::SelectInt<value7, true, false>::type;
	//EXPECT_EQ(16, sizeof(type710));
	//EXPECT_EQ(true, std::is_signed<type710>::value);

	//using type711 = ::_XENUM5_NS::SelectInt<value7, true, true>::type;
	//EXPECT_EQ(16, sizeof(type711));
	//EXPECT_EQ(true, std::is_signed<type711>::value);

	// Boundary check.
	constexpr uint64_t value8 = 0xffffffffffffffff;

	using type800 = ::_XENUM5_NS::SelectInt<value8, false, false>::type;
	EXPECT_EQ(8, sizeof(type800));
	EXPECT_EQ(false, std::is_signed<type800>::value);
}


/// Function that only compiles if the constexpr _size is really constexpr.
template <class T> typename std::enable_if<XenumFruits::_size == 2, bool>::type cxpSizeNoNsNoCls(void) { return true; }
/// Test basics of the FruitsNoNsNoCls xenum.
TEST_F(TestXenums, FruitsNoNsNoCls)
{
	EXPECT_EQ(1, sizeof(XenumFruits::_index_t));
	EXPECT_EQ(false, std::is_signed<XenumFruits::_index_t>::value);
	EXPECT_EQ(true, cxpSizeNoNsNoCls<void>());
	EXPECT_EQ(2, XenumFruits::_size);
	XenumFruit fruit0 = XenumFruits::apple;
	XenumFruit fruit1 = XenumFruits::grape;
	EXPECT_EQ(0, fruit0.getIndex());
	EXPECT_EQ(1, fruit1.getIndex());
}


/// Function that only compiles if the constexpr _size is really constexpr.
template <class T> typename std::enable_if<XenumWrapNoNs::Fruits::_size == 3, bool>::type cxpSizeNoNsInCls(void) { return true; }
/// Test basics of the FruitsNoNsInCls xenum.
TEST_F(TestXenums, FruitsNoNsInCls)
{
	EXPECT_EQ(1, sizeof(XenumWrapNoNs::Fruits::_index_t));
	EXPECT_EQ(false, std::is_signed<XenumWrapNoNs::Fruits::_index_t>::value);
	EXPECT_EQ(true, cxpSizeNoNsInCls<void>());
	EXPECT_EQ(3, XenumWrapNoNs::Fruits::_size);
	XenumWrapNoNs::Fruit fruit0 = XenumWrapNoNs::Fruits::banana;
	XenumWrapNoNs::Fruit fruit1 = XenumWrapNoNs::Fruits::orange;
	XenumWrapNoNs::Fruit fruit2 = XenumWrapNoNs::Fruits::peanut;
	EXPECT_EQ(0, fruit0.getIndex());
	EXPECT_EQ(1, fruit1.getIndex());
	EXPECT_EQ(2, fruit2.getIndex());
}


/// Function that only compiles if the constexpr _size is really constexpr.
template <class T> typename std::enable_if<xenums::Fruits::_size == 4, bool>::type cxpSizeInNsNoCls(void) { return true; }
/// Test basics of the FruitsInNsNoCls xenum.
TEST_F(TestXenums, FruitsInNsNoCls)
{
	EXPECT_EQ(4, sizeof(xenums::Fruits::_index_t));
	EXPECT_EQ(false, std::is_signed<xenums::Fruits::_index_t>::value);
	EXPECT_EQ(true, cxpSizeInNsNoCls<void>());
	EXPECT_EQ(4, xenums::Fruits::_size);
	xenums::Fruit fruit0 = xenums::Fruits::tomato;
	xenums::Fruit fruit1 = xenums::Fruits::pear;
	xenums::Fruit fruit2 = xenums::Fruits::lime;
	xenums::Fruit fruit3 = xenums::Fruits::lemon;
	EXPECT_EQ(0, fruit0.getIndex());
	EXPECT_EQ(1, fruit1.getIndex());
	EXPECT_EQ(2, fruit2.getIndex());
	EXPECT_EQ(3, fruit3.getIndex());
}


/// Function that only compiles if the constexpr _size is really constexpr.
template <class T> typename std::enable_if<xenums::WrapInNs::Fruits::_size == 5, bool>::type cxpSizeInNsInCls(void) { return true; }
/// Test basics of the FruitsInNsInCls xenum.
TEST_F(TestXenums, FruitsInNsInCls)
{
	EXPECT_EQ(8, sizeof(xenums::WrapInNs::Fruits::_index_t));
	EXPECT_EQ(false, std::is_signed<xenums::WrapInNs::Fruits::_index_t>::value);
	EXPECT_EQ(true, cxpSizeInNsInCls<void>());
	EXPECT_EQ(5, xenums::WrapInNs::Fruits::_size);
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


/// Test basics of the Numbers xenum.
TEST_F(TestXenums, Numbers)
{
	EXPECT_EQ(2, sizeof(xenums::Numbers::_index_t));
	EXPECT_EQ(false, std::is_signed<xenums::Numbers::_index_t>::value);
	EXPECT_EQ(4100, xenums::Numbers::_size);
	xenums::Number number0001 = xenums::Numbers::n0001;
	xenums::Number number0200 = xenums::Numbers::n0200;
	xenums::Number number1768 = xenums::Numbers::n1718;
	xenums::Number number4100 = xenums::Numbers::n4100;
	EXPECT_LT(number0001, number0200);
	EXPECT_LT(number0200, number1768);
	EXPECT_LT(number1768, number4100);
	//std::cout<<"hasProps="<<xenums::Numbers::hasProps()<<std::endl;
}


/// Test basics of the IcmpTypes xenum.
TEST_F(TestXenums, IcmpTypes)
{
	EXPECT_EQ(1, sizeof(xenums::IcmpTypes::_index_t));
	EXPECT_EQ(false, std::is_signed<xenums::IcmpTypes::_index_t>::value);
	EXPECT_EQ(35, xenums::IcmpTypes::_size);
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
	//std::cout<<"NfNameValuesSize = "<<xenums::IcmpTypes::NfNameValuesSize<<std::endl;
}


/// Test basics of the IcmoCodes xenum.
TEST_F(TestXenums, IcmpCodes)
{
	EXPECT_EQ(1, sizeof(xenums::IcmpCodes::_index_t));
	EXPECT_EQ(false, std::is_signed<xenums::IcmpCodes::_index_t>::value);
	EXPECT_EQ(35, xenums::IcmpCodes::_size);
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
