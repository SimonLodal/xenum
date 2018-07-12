/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_P2COMBS_HPP
#define TEST_XENUM_XENUMS_P2COMBS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum for testing combinations of custom property options:
 * - 1 data type: plain (int)
 * - 1 depth: 2
 * - 3 getter implementations: off, ext, cxp
 * - 4 lookup implementations: off, ext, inl, cxp
 * All these have different code paths in the generators so it is important to test them all.
 * Default values and empty arrays are also tested in each combination.
 */
#define XENUM5_P2combs(D,V,C)				\
	D(C, test::xenum::xenums::, P2combs, P2comb, , ,\
	(						\
		/* depth=2 */				\
		(P2OO, int, -1200, 2, (off,off)),	\
		(P2OE, int, -1201, 2, (off,ext)),	\
		(P2OI, int, -1202, 2, (off,inl)),	\
		(P2OC, int, -1203, 2, (off,cxp)),	\
		(P2EO, int, -1204, 2, (ext,off)),	\
		(P2EE, int, -1205, 2, (ext,ext)),	\
		(P2EI, int, -1206, 2, (ext,inl)),	\
		(P2EC, int, -1207, 2, (ext,cxp)),	\
		(P2CO, int, -1208, 2, (cxp,off)),	\
		(P2CE, int, -1209, 2, (cxp,ext)),	\
		(P2CI, int, -1210, 2, (cxp,inl)),	\
		(P2CC, int, -1211, 2, (cxp,cxp))	\
	))						\
	V(C, V0						\
		/* depth=2 */				\
		, ((1200,,1201),())	/* P2OO */	\
		, ((1202,,1203),())	/* P2OE */	\
		, ((1204,,1205),())	/* P2OI */	\
		, ((1206,,1207),())	/* P2OC */	\
		, ((1210,,1211),())	/* P2EO */	\
		, ((1212,,1213),())	/* P2EE */	\
		, ((1214,,1215),())	/* P2EI */	\
		, ((1216,,1217),())	/* P2EC */	\
		, ((1220,,1221),())	/* P2CO */	\
		, ((1222,,1223),())	/* P2CE */	\
		, ((1224,,1225),())	/* P2CI */	\
		, ((1226,,1227),())	/* P2CC */	\
	)						\
	V(C, V1						\
		/* depth=2 */				\
		,			/* P2OO */	\
		,			/* P2OE */	\
		,			/* P2OI */	\
		,			/* P2OC */	\
		,			/* P2EO */	\
		,			/* P2EE */	\
		,			/* P2EI */	\
		,			/* P2EC */	\
		,			/* P2CO */	\
		,			/* P2CE */	\
		,			/* P2CI */	\
		,			/* P2CC */	\
	)						\
	V(C, V2						\
		/* depth=2 */				\
		, ()			/* P2OO */	\
		, ()			/* P2OE */	\
		, ()			/* P2OI */	\
		, ()			/* P2OC */	\
		, ()			/* P2EO */	\
		, ()			/* P2EE */	\
		, ()			/* P2EI */	\
		, ()			/* P2EC */	\
		, ()			/* P2CO */	\
		, ()			/* P2CE */	\
		, ()			/* P2CI */	\
		, ()			/* P2CC */	\
	)						\

XENUM5_DECLARE(P2combs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_P2COMBS_HPP
