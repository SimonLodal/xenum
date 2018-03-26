/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_SSTRS2_HPP
#define TEST_XENUM_XENUMS_SSTRS2_HPP

#include <cstdint>
#include <xenum3/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum with custom string properties defined in source file (depth=2).
 */
#define XENUM_DECL_Sstrs2 (test::xenum::xenums::, Sstrs2, Sstr2, , , (			\
		(P0, int, -1, 2),							\
		(P1, cstring, "foo2", 2)						\
	))
#define XENUM_VALS_Sstrs2(V,C)					\
	V(C, V0, ((1),(2,3))		,(("s1"),("s2","s3")))	\
	V(C, V1, ((4),(5),(6,7,8))	,(("s4"),("s5"),("s6","s7","s8")))	\
	V(C, V2)						\
	V(C, V3, ((),,())		,((),,()))		\


XENUM3_DECLARE(Sstrs2)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_SSTRS2_HPP
