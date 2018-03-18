/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_FRUITSNONSNOCLS_HPP
#define TEST_XENUM_XENUMS_FRUITSNONSNOCLS_HPP

#include <cstdint>
#include <xenum3/Xenum.hpp>

/*
		((Foo, int, , 1))		\
		((Bar, int, , 2))		\
*/
#define XENUM_DECL_Fruits_NoNsNoCls ( , XenumFruits, XenumFruit, , , )
#define XENUM_VALS_Fruits_NoNsNoCls(V,C)	\
	V(C, apple)		\
	V(C, grape)
XENUM3_DECLARE(Fruits_NoNsNoCls)
/*
	V(C, apple, (1), ((11)))		\
	V(C, grape, (2,3,4), ((22,23),(24,25,26)))
*/

#endif // TEST_XENUM_XENUMS_FRUITSNONSNOCLS_HPP
