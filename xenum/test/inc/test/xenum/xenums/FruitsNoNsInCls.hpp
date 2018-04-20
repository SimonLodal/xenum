/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_FRUITSNONSINCLS_HPP
#define TEST_XENUM_XENUMS_FRUITSNONSINCLS_HPP

#include <cstdint>
#include <xenum4/Xenum.hpp>

/// Empty wrapper class, for unit testing declaration of an xenum inside a class.
class XenumWrapNoNs {
public:
/// Xenum for unit testing, declared outside namespace, but inside a class.
#define XENUM_DECL_Fruits_NoNsInCls (XenumWrapNoNs::, Fruits, Fruit)
/// Declaration of the xenum values.
#define XENUM_VALS_Fruits_NoNsInCls(V,C)	\
	V(C, banana)				\
	V(C, orange)				\
	V(C, peanut)
XENUM4_DECLARE(Fruits_NoNsInCls)
};


#endif // TEST_XENUM_XENUMS_FRUITSNONSINCLS_HPP
