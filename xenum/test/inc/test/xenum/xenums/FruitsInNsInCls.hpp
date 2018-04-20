/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_FRUITSINNSINCLS_HPP
#define TEST_XENUM_XENUMS_FRUITSINNSINCLS_HPP

#include <cstdint>
#include <xenum4/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/// Empty wrapper class, for unit testing declaration of an xenum inside a class.
class WrapInNs {
public:
/// Xenum for unit testing, declared inside namespace and class.
#define XENUM_DECL_Fruits_InNsInCls (test::xenum::xenums::WrapInNs::, Fruits, Fruit, uint64_t)
/// Declaration of the xenum values.
#define XENUM_VALS_Fruits_InNsInCls(V,C)	\
	V(C, plum)				\
	V(C, mango)				\
	V(C, melon)				\
	V(C, kiwi)				\
	V(C, guava)
XENUM4_DECLARE(Fruits_InNsInCls)
};


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_FRUITSINNSINCLS_HPP
