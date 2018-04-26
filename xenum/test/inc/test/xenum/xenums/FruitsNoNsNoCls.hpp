/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_FRUITSNONSNOCLS_HPP
#define TEST_XENUM_XENUMS_FRUITSNONSNOCLS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

/// Xenum for unit testing, declared outside any namespace or class.
#define XENUM5_Fruits_NoNsNoCls(D,V,C)		\
	D(C, , XenumFruits, XenumFruit, , , )	\
	V(C, apple)				\
	V(C, grape)
XENUM5_DECLARE(Fruits_NoNsNoCls)


#endif // TEST_XENUM_XENUMS_FRUITSNONSNOCLS_HPP
