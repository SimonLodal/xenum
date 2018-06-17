/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_PCOMBS_HPP
#define TEST_XENUM_XENUMS_PCOMBS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum for testing all combinations of custom property options:
 * - 1 data type: plain (int)
 * - 3 depths (0..2)
 * - 3 getter implementations: off (future), ext, cxp
 * - 4 lookup implementations: off, ext, inl, cxp
 * All these have different code paths in the generators so it is important to test them all.
 * Default values and empty arrays are also tested in each combination.
 */
#define XENUM5_Pcombs(D,V,C)				\
	D(C, test::xenum::xenums::, Pcombs, Pcomb, , ,	\
	(						\
		/* plain, depth=0, (ext) */		\
		(P0E, int, -1, 0, (ext)),		\
		/* plain, depth=0, (cxp) */		\
		(P0C, int, -2, 0, (cxp)),		\
		/* plain, depth=1, (ext) */		\
		(P1E, int, -3, 1, (ext)),		\
		/* plain, depth=1, (cxp) */		\
		(P1C, int, -4, 1, (cxp)),		\
		/* plain, depth=2, (ext) */		\
		(P2E, int, -5, 2, (ext)),		\
		/* plain, depth=2, (cxp) */		\
		(P2C, int, -6, 2, (cxp))		\
	))						\
	V(C, V0						\
		, 0			/* P0E */	\
		, 1			/* P0C */	\
		, (2, , 3)		/* P1E */	\
		, (4, , 5)		/* P1C */	\
		, ((6,,7),())		/* P2E */	\
		, ((8,,9),())		/* P2C */	\
	)						\
	V(C, V1						\
		, 			/* P0E */	\
		, 			/* P0C */	\
		, 			/* P1E */	\
		, 			/* P1C */	\
		,			/* P2E */	\
		,			/* P2C */	\
	)						\
	V(C, V2						\
		, 10			/* P0E */	\
		, 11			/* P0C */	\
		, ()			/* P1E */	\
		, ()			/* P1C */	\
		, ()			/* P2E */	\
		, ()			/* P2C */	\
	)						\

XENUM5_DECLARE(Pcombs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_PCOMBS_HPP
