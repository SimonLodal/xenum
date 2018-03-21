/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_SSTRS_HPP
#define TEST_XENUM_XENUMS_SSTRS_HPP

#include <cstdint>
#include <xenum3/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum with custom string properties defined in source file.
 */
#define SSTRS_DEPTH 2

#if SSTRS_DEPTH == 0
#define XENUM_DECL_Sstrs (test::xenum::xenums::, Sstrs, Sstr, , , (			\
		(P0, int, -1),								\
		(P1, cstring, "foo0")							\
	))
#define XENUM_VALS_Sstrs(V,C)				\
	V(C, V0, 1, "s1")				\
	V(C, V1, 2, "s2")				\
	V(C, V2)					\
	V(C, V3, 3, "s3")				\


#elif SSTRS_DEPTH == 1
#define XENUM_DECL_Sstrs (test::xenum::xenums::, Sstrs, Sstr, , , (			\
		(P0, int, -1, 1),							\
		(P1, cstring, "foo1", 1)						\
	))
#define XENUM_VALS_Sstrs(V,C)				\
	V(C, V0, (1,2,3)	,("s1","s2","s3"))	\
	V(C, V1, (4)		,("s4"))		\
	V(C, V2)					\
	V(C, V3, (5,6)		,("s5","s6"))		\


#elif SSTRS_DEPTH == 2
#define XENUM_DECL_Sstrs (test::xenum::xenums::, Sstrs, Sstr, , , (			\
		(P0, int, -1, 2),							\
		(P1, cstring, "foo2", 2)						\
	))
#define XENUM_VALS_Sstrs(V,C)					\
	V(C, V0, ((1),(2,3))		,(("s1"),("s2","s3")))	\
	V(C, V1, ((4),(5),(6,7,8))	,(("s4"),("s5"),("s6","s7","s8")))	\
	V(C, V2)						\
	V(C, V3, ((),,())		,((),,()))		\

#endif


XENUM3_DECLARE(Sstrs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_SSTRS_HPP
