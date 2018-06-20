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
		/* depth=0 */				\
		(P0OO, int, -1000, 0, (off,off)),	\
		(P0OE, int, -1001, 0, (off,ext)),	\
		(P0OI, int, -1002, 0, (off,inl)),	\
		(P0OC, int, -1003, 0, (off,cxp)),	\
		(P0EO, int, -1004, 0, (ext,off)),	\
		(P0EE, int, -1005, 0, (ext,ext)),	\
		(P0EI, int, -1006, 0, (ext,inl)),	\
		(P0EC, int, -1007, 0, (ext,cxp)),	\
		(P0CO, int, -1008, 0, (cxp,off)),	\
		(P0CE, int, -1009, 0, (cxp,ext)),	\
		(P0CI, int, -1010, 0, (cxp,inl)),	\
		(P0CC, int, -1011, 0, (cxp,cxp)),	\
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
		(P1CC, int, -1111, 1, (cxp,cxp)),	\
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
		/* depth=0 */				\
		, 1000			/* P00O */	\
		, 1001			/* P00E */	\
		, 1002			/* P00I */	\
		, 1003			/* P00C */	\
		, 1004			/* P0EO */	\
		, 1005			/* P0EE */	\
		, 1006			/* P0EI */	\
		, 1007			/* P0EC */	\
		, 1008			/* P0CO */	\
		, 1009			/* P0CE */	\
		, 1010			/* P0CI */	\
		, 1011			/* P0CC */	\
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
		/* depth=0 */				\
		,			/* P00O */	\
		,			/* P00E */	\
		,			/* P00I */	\
		,			/* P00C */	\
		,			/* P0EO */	\
		,			/* P0EE */	\
		,			/* P0EI */	\
		,			/* P0EC */	\
		,			/* P0CO */	\
		,			/* P0CE */	\
		,			/* P0CI */	\
		,			/* P0CC */	\
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
		/* depth=0 */				\
		, 1020			/* P00O */	\
		, 1021			/* P00E */	\
		, 1022			/* P00I */	\
		, 1023			/* P00C */	\
		, 1024			/* P0EO */	\
		, 1025			/* P0EE */	\
		, 1026			/* P0EI */	\
		, 1027			/* P0EC */	\
		, 1028			/* P0CO */	\
		, 1029			/* P0CE */	\
		, 1020			/* P0CI */	\
		, 1021			/* P0CC */	\
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

XENUM5_DECLARE(Pcombs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_PCOMBS_HPP
