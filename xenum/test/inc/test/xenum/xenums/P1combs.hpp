/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_P1COMBS_HPP
#define TEST_XENUM_XENUMS_P1COMBS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum for testing combinations of custom property options:
 * - 1 data type: plain (int)
 * - 1 depth: 1
 * - 3 getter implementations: off, ext, cxp
 * - 4 lookup implementations: off, ext, inl, cxp
 * All these have different code paths in the generators so it is important to test them all.
 * Default values and empty arrays are also tested in each combination.
 */
#define XENUM5_P1combs(D,V,C)				\
	D(C, test::xenum::xenums::, P1combs, P1comb, , ,\
	(						\
		/* depth=1 */				\
		(P1OO, int, -1100, 1, (off,off)),	\
		(P1OE, int, -1101, 1, (off,ext)),	\
		(P1OI, int, -1102, 1, (off,inl)),	\
		(P1OC, int, -1103, 1, (off,cxp)),	\
		(P1EO, int, -1104, 1, (ext,off)),	\
		(P1EE, int, -1105, 1, (ext,ext)),	\
		(P1EI, int, -1106, 1, (ext,inl)),	\
		(P1EC, int, -1107, 1, (ext,cxp)),	\
		(P1CO, int, -1108, 1, (cxp,off)),	\
		(P1CE, int, -1109, 1, (cxp,ext)),	\
		(P1CI, int, -1110, 1, (cxp,inl)),	\
		(P1CC, int, -1111, 1, (cxp,cxp))	\
	))						\
	V(C, V0						\
		/* depth=1 */				\
		, (1100, , 1101)	/* P1OO */	\
		, (1102, , 1103)	/* P1OE */	\
		, (1104, , 1105)	/* P1OI */	\
		, (1106, , 1107)	/* P1OC */	\
		, (1110, , 1111)	/* P1EO */	\
		, (1112, , 1113)	/* P1EE */	\
		, (1114, , 1115)	/* P1EI */	\
		, (1116, , 1117)	/* P1EC */	\
		, (1120, , 1121)	/* P1CO */	\
		, (1122, , 1123)	/* P1CE */	\
		, (1124, , 1125)	/* P1CI */	\
		, (1126, , 1127)	/* P1CC */	\
	)						\
	V(C, V1						\
		/* depth=1 */				\
		,			/* P1OO */	\
		,			/* P1OE */	\
		,			/* P1OI */	\
		,			/* P1OC */	\
		,			/* P1EO */	\
		,			/* P1EE */	\
		,			/* P1EI */	\
		,			/* P1EC */	\
		,			/* P1CO */	\
		,			/* P1CE */	\
		,			/* P1CI */	\
		,			/* P1CC */	\
	)						\
	V(C, V2						\
		/* depth=1 */				\
		, ()			/* P1OO */	\
		, ()			/* P1OE */	\
		, ()			/* P1OI */	\
		, ()			/* P1OC */	\
		, ()			/* P1EO */	\
		, ()			/* P1EE */	\
		, ()			/* P1EI */	\
		, ()			/* P1EC */	\
		, ()			/* P1CO */	\
		, ()			/* P1CE */	\
		, ()			/* P1CI */	\
		, ()			/* P1CC */	\
	)						\

XENUM5_DECLARE(P1combs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_P1COMBS_HPP
