/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_FRUITSNONSINCLS_HPP
#define TEST_XENUM_XENUMS_FRUITSNONSINCLS_HPP

#include <cstdint>
#include <xenum3/Xenum.hpp>


class XenumWrapNoNs {
public:
#define XENUM_DECL_Fruits_NoNsInCls (XenumWrapNoNs::, Fruits, Fruit)
#define XENUM_VALS_Fruits_NoNsInCls(V,C)	\
	V(C, banana)				\
	V(C, orange)				\
	V(C, peanut)
XENUM3_DECLARE(Fruits_NoNsInCls)
};


#endif // TEST_XENUM_XENUMS_FRUITSNONSINCLS_HPP
