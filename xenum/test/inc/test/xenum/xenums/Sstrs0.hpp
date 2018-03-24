/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_SSTRS0_HPP
#define TEST_XENUM_XENUMS_SSTRS0_HPP

#include <cstdint>
#include <xenum3/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum with custom string properties defined in source file (depth=0).
 */
#define XENUM_DECL_Sstrs0 (test::xenum::xenums::, Sstrs0, Sstr0, , , (			\
		(P0, int, -1),								\
		(P1, cstring, "foo0")							\
	))
#define XENUM_VALS_Sstrs0(V,C)				\
	V(C, V0, 1, "s1")				\
	V(C, V1, 2, "s2")				\
	V(C, V2)					\
	V(C, V3, 3, "s3")				\


XENUM3_DECLARE(Sstrs0)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_SSTRS0_HPP
