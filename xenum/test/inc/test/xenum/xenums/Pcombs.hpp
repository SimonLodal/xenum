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
		/* depth=0, (off,off) */		\
		(P0OO, int, -11, 0, (off,off)),		\
		/* depth=0, (ext,off) */		\
		(P0EO, int, -12, 0, (ext,off)),		\
		/* depth=0, (cxp,off) */		\
		(P0CO, int, -13, 0, (cxp,off)),		\
		/* depth=1, (off,off) */		\
		(P1OO, int, -21, 1, (off,off)),		\
		/* depth=1, (ext,off) */		\
		(P1EO, int, -22, 1, (ext,off)),		\
		/* depth=1, (cxp,off) */		\
		(P1CO, int, -23, 1, (cxp,off)),		\
		/* depth=2, (off,off) */		\
		(P2OO, int, -31, 2, (off,off)),		\
		/* depth=2, (ext,off) */		\
		(P2EO, int, -32, 2, (ext,off)),		\
		/* depth=2, (cxp,off) */		\
		(P2CO, int, -33, 2, (cxp,off))		\
	))						\
	V(C, V0						\
		, 11			/* P00O */	\
		, 12			/* P0EO */	\
		, 13			/* P0CO */	\
		, (21, , 22)		/* P1OO */	\
		, (23, , 24)		/* P1EO */	\
		, (25, , 26)		/* P1CO */	\
		, ((31,,32),())		/* P2EO */	\
		, ((33,,34),())		/* P2OO */	\
		, ((35,,36),())		/* P2CO */	\
	)						\
	V(C, V1						\
		, 			/* P0OO */	\
		, 			/* P0EO */	\
		, 			/* P0CO */	\
		, 			/* P1OO */	\
		, 			/* P1EO */	\
		, 			/* P1CO */	\
		,			/* P2OO */	\
		,			/* P2EO */	\
		,			/* P2CO */	\
	)						\
	V(C, V2						\
		, 211			/* P0OO */	\
		, 212			/* P0EO */	\
		, 213			/* P0CO */	\
		, ()			/* P1OO */	\
		, ()			/* P1EO */	\
		, ()			/* P1CO */	\
		, ()			/* P2OO */	\
		, ()			/* P2EO */	\
		, ()			/* P2CO */	\
	)						\

XENUM5_DECLARE(Pcombs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_PCOMBS_HPP
