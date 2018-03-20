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
		(P1, cstring, "foo")							\
	))
#define XENUM_VALS_Sstrs(V,C)				\
	V(C, V0, 1, "a")				\
	V(C, V1, 2, "bc")				\
	V(C, V2)					\
	V(C, V3, 3, "def")				\


#elif SSTRS_DEPTH == 1
#define XENUM_DECL_Sstrs (test::xenum::xenums::, Sstrs, Sstr, , , (			\
		(P0, int, -1, 1),							\
		(P1, cstring, , 1)							\
	))
#define XENUM_VALS_Sstrs(V,C)				\
	V(C, V0, (1,2,3)	,("a", "b"))		\
	V(C, V1, (4)		,("cd"))		\
	V(C, V2)					\
	V(C, V3, (5,6)		,("efg","hij","klm"))	\


#elif SSTRS_DEPTH == 2
#define XENUM_DECL_Sstrs (test::xenum::xenums::, Sstrs, Sstr, , , (			\
		(P0, int, -1, 2),							\
		(P1, cstring, , 2)							\
	))
#define XENUM_VALS_Sstrs(V,C)					\
	V(C, V0, ((1),(2,3))		,(("a"),("b","c")))	\
	V(C, V1, ((4),(5),(6,7,8))	,(("def")))		\
	V(C, V2)						\
	V(C, V3, ((),(),())		,(("ghi","jkl","mno")))	\

#endif


XENUM3_DECLARE(Sstrs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_SSTRS_HPP
