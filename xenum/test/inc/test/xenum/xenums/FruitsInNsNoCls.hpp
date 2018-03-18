/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_FRUITSINNSNOCLS_HPP
#define TEST_XENUM_XENUMS_FRUITSINNSNOCLS_HPP

#include <cstdint>
#include <xenum3/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


#define XENUM_DECL_Fruits_InNsNoCls (test::xenum::xenums:: , Fruits, Fruit, uint32_t, )
#define XENUM_VALS_Fruits_InNsNoCls(V,C)	\
	V(C, tomato)				\
	V(C, pear)				\
	V(C, lime)				\
	V(C, lemon)
XENUM3_DECLARE(Fruits_InNsNoCls)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_FRUITSINNSNOCLS_HPP
