/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_SSTRS1_HPP
#define TEST_XENUM_XENUMS_SSTRS1_HPP

#include <cstdint>
#include <xenum4/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum with custom string properties defined in source file (depth=1).
 */
#define XENUM_DECL_Sstrs1 (test::xenum::xenums::, Sstrs1, Sstr1, , , (			\
		(P0, int, -1, 1),							\
		(P1, cstring, "foo1", 1)						\
	))
#define XENUM_VALS_Sstrs1(V,C)				\
	V(C, V0, (1,2,3)	,("s1","s2","s3"))	\
	V(C, V1, (4)		,("s4"))		\
	V(C, V2)					\
	V(C, V3, (5,6)		,("s5","s6"))		\


XENUM4_DECLARE(Sstrs1)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_SSTRS1_HPP
