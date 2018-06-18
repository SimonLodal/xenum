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
		/* depth=0, (off) */			\
		(P0O, int, -11, 0, (off)),		\
		/* depth=0, (ext) */			\
		(P0E, int, -12, 0, (ext)),		\
		/* depth=0, (cxp) */			\
		(P0C, int, -13, 0, (cxp)),		\
		/* depth=1, (off) */			\
		(P1O, int, -21, 1, (off)),		\
		/* depth=1, (ext) */			\
		(P1E, int, -22, 1, (ext)),		\
		/* depth=1, (cxp) */			\
		(P1C, int, -23, 1, (cxp)),		\
		/* depth=2, (ext) */			\
		(P2O, int, -31, 2, (off)),		\
		/* depth=2, (off) */			\
		(P2E, int, -32, 2, (ext)),		\
		/* depth=2, (cxp) */			\
		(P2C, int, -33, 2, (cxp))		\
	))						\
	V(C, V0						\
		, 11			/* P00 */	\
		, 12			/* P0E */	\
		, 13			/* P0C */	\
		, (21, , 22)		/* P1O */	\
		, (23, , 24)		/* P1E */	\
		, (25, , 26)		/* P1C */	\
		, ((31,,32),())		/* P2E */	\
		, ((33,,34),())		/* P2O */	\
		, ((35,,36),())		/* P2C */	\
	)						\
	V(C, V1						\
		, 			/* P0O */	\
		, 			/* P0E */	\
		, 			/* P0C */	\
		, 			/* P1O */	\
		, 			/* P1E */	\
		, 			/* P1C */	\
		,			/* P2O */	\
		,			/* P2E */	\
		,			/* P2C */	\
	)						\
	V(C, V2						\
		, 211			/* P0O */	\
		, 212			/* P0E */	\
		, 213			/* P0C */	\
		, ()			/* P1O */	\
		, ()			/* P1E */	\
		, ()			/* P1C */	\
		, ()			/* P2O */	\
		, ()			/* P2E */	\
		, ()			/* P2C */	\
	)						\

XENUM5_DECLARE(Pcombs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_PCOMBS_HPP
