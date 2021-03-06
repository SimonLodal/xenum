/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_FRUITSNONSINCLS_HPP
#define TEST_XENUM_XENUMS_FRUITSNONSINCLS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

/// Empty wrapper class, for unit testing declaration of an xenum inside a class.
class XenumWrapNoNs {
public:

/// Xenum for unit testing, declared outside namespace, but inside a class.
#define XENUM5_Fruits_NoNsInCls(D,V,C)		\
	D(C, XenumWrapNoNs::, Fruits, Fruit)	\
	V(C, banana)				\
	V(C, orange)				\
	V(C, peanut)
XENUM5_DECLARE(Fruits_NoNsInCls)

};


#endif // TEST_XENUM_XENUMS_FRUITSNONSINCLS_HPP
