/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_SCOMBS_HPP
#define TEST_XENUM_XENUMS_SCOMBS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum for testing all combinations of custom property options:
 * - 1 data type: cstring
 * - 3 depths (0..2)
 * - 3 getter implementations: off (future), ext, cxp
 * - 4 lookup implementations: off, ext, inl, cxp
 * All these have different code paths in the generators so it is important to test them all.
 * Default values and empty arrays are also tested in each combination.
 */
#define XENUM5_Scombs(D,V,C)				\
	D(C, test::xenum::xenums::, Scombs, Scomb, , ,	\
	(						\
		/* depth=0 */				\
		(S0OO, cstring, "-1000", 0, (off,off)),	\
		(S0OE, cstring, "-1001", 0, (off,ext)),	\
		(S0OI, cstring, "-1002", 0, (off,inl)),	\
		(S0OC, cstring, "-1003", 0, (off,cxp)),	\
		(S0EO, cstring, "-1004", 0, (ext,off)),	\
		(S0EE, cstring, "-1005", 0, (ext,ext)),	\
		(S0EI, cstring, "-1006", 0, (ext,inl)),	\
		(S0EC, cstring, "-1007", 0, (ext,cxp)),	\
		(S0CO, cstring, "-1008", 0, (cxp,off)),	\
		(S0CE, cstring, "-1009", 0, (cxp,ext)),	\
		(S0CI, cstring, "-1010", 0, (cxp,inl)),	\
		(S0CC, cstring, "-1011", 0, (cxp,cxp)),	\
		/* depth=1 */				\
		(S1OO, cstring, "-1100", 1, (off,off)),	\
		(S1OE, cstring, "-1101", 1, (off,ext)),	\
		(S1OI, cstring, "-1102", 1, (off,inl)),	\
		(S1OC, cstring, "-1103", 1, (off,cxp)),	\
		(S1EO, cstring, "-1104", 1, (ext,off)),	\
		(S1EE, cstring, "-1105", 1, (ext,ext)),	\
		(S1EI, cstring, "-1106", 1, (ext,inl)),	\
		(S1EC, cstring, "-1107", 1, (ext,cxp)),	\
		(S1CO, cstring, "-1108", 1, (cxp,off)),	\
		(S1CE, cstring, "-1109", 1, (cxp,ext)),	\
		(S1CI, cstring, "-1110", 1, (cxp,inl)),	\
		(S1CC, cstring, "-1111", 1, (cxp,cxp)),	\
		/* depth=2 */				\
		(S2OO, cstring, "-1200", 2, (off,off)),	\
		(S2OE, cstring, "-1201", 2, (off,ext)),	\
		(S2OI, cstring, "-1202", 2, (off,inl)),	\
		(S2OC, cstring, "-1203", 2, (off,cxp)),	\
		(S2EO, cstring, "-1204", 2, (ext,off)),	\
		(S2EE, cstring, "-1205", 2, (ext,ext)),	\
		(S2EI, cstring, "-1206", 2, (ext,inl)),	\
		(S2EC, cstring, "-1207", 2, (ext,cxp)),	\
		(S2CO, cstring, "-1208", 2, (cxp,off)),	\
		(S2CE, cstring, "-1209", 2, (cxp,ext)),	\
		(S2CI, cstring, "-1210", 2, (cxp,inl)),	\
		(S2CC, cstring, "-1211", 2, (cxp,cxp))	\
	))						\
	V(C, V0						\
		/* depth=0 */				\
		, "1000"		/* S00O */	\
		, "1001"		/* S00E */	\
		, "1002"		/* S00I */	\
		, "1003"		/* S00C */	\
		, "1004"		/* S0EO */	\
		, "1005"		/* S0EE */	\
		, "1006"		/* S0EI */	\
		, "1007"		/* S0EC */	\
		, "1008"		/* S0CO */	\
		, "1009"		/* S0CE */	\
		, "1010"		/* S0CI */	\
		, "1011"		/* S0CC */	\
		/* depth=1 */				\
		, ("1100", , "1101")	/* S1OO */	\
		, ("1102", , "1103")	/* S1OE */	\
		, ("1104", , "1105")	/* S1OI */	\
		, ("1106", , "1107")	/* S1OC */	\
		, ("1110", , "1111")	/* S1EO */	\
		, ("1112", , "1113")	/* S1EE */	\
		, ("1114", , "1115")	/* S1EI */	\
		, ("1116", , "1117")	/* S1EC */	\
		, ("1120", , "1121")	/* S1CO */	\
		, ("1122", , "1123")	/* S1CE */	\
		, ("1124", , "1125")	/* S1CI */	\
		, ("1126", , "1127")	/* S1CC */	\
		/* depth=2 */				\
		, (("1200",,"1201"),())	/* S2OO */	\
		, (("1202",,"1203"),())	/* S2OE */	\
		, (("1204",,"1205"),())	/* S2OI */	\
		, (("1206",,"1207"),())	/* S2OC */	\
		, (("1210",,"1211"),())	/* S2EO */	\
		, (("1212",,"1213"),())	/* S2EE */	\
		, (("1214",,"1215"),())	/* S2EI */	\
		, (("1216",,"1217"),())	/* S2EC */	\
		, (("1220",,"1221"),())	/* S2CO */	\
		, (("1222",,"1223"),())	/* S2CE */	\
		, (("1224",,"1225"),())	/* S2CI */	\
		, (("1226",,"1227"),())	/* S2CC */	\
	)						\
	V(C, V1						\
		/* depth=0 */				\
		,			/* S00O */	\
		,			/* S00E */	\
		,			/* S00I */	\
		,			/* S00C */	\
		,			/* S0EO */	\
		,			/* S0EE */	\
		,			/* S0EI */	\
		,			/* S0EC */	\
		,			/* S0CO */	\
		,			/* S0CE */	\
		,			/* S0CI */	\
		,			/* S0CC */	\
		/* depth=1 */				\
		,			/* S1OO */	\
		,			/* S1OE */	\
		,			/* S1OI */	\
		,			/* S1OC */	\
		,			/* S1EO */	\
		,			/* S1EE */	\
		,			/* S1EI */	\
		,			/* S1EC */	\
		,			/* S1CO */	\
		,			/* S1CE */	\
		,			/* S1CI */	\
		,			/* S1CC */	\
		/* depth=2 */				\
		,			/* S2OO */	\
		,			/* S2OE */	\
		,			/* S2OI */	\
		,			/* S2OC */	\
		,			/* S2EO */	\
		,			/* S2EE */	\
		,			/* S2EI */	\
		,			/* S2EC */	\
		,			/* S2CO */	\
		,			/* S2CE */	\
		,			/* S2CI */	\
		,			/* S2CC */	\
	)						\
	V(C, V2						\
		/* depth=0 */				\
		, "1020"		/* S00O */	\
		, "1021"		/* S00E */	\
		, "1022"		/* S00I */	\
		, "1023"		/* S00C */	\
		, "1024"		/* S0EO */	\
		, "1025"		/* S0EE */	\
		, "1026"		/* S0EI */	\
		, "1027"		/* S0EC */	\
		, "1028"		/* S0CO */	\
		, "1029"		/* S0CE */	\
		, "1030"		/* S0CI */	\
		, "1031"		/* S0CC */	\
		/* depth=1 */				\
		, ()			/* S1OO */	\
		, ()			/* S1OE */	\
		, ()			/* S1OI */	\
		, ()			/* S1OC */	\
		, ()			/* S1EO */	\
		, ()			/* S1EE */	\
		, ()			/* S1EI */	\
		, ()			/* S1EC */	\
		, ()			/* S1CO */	\
		, ()			/* S1CE */	\
		, ()			/* S1CI */	\
		, ()			/* S1CC */	\
		/* depth=2 */				\
		, ()			/* S2OO */	\
		, ()			/* S2OE */	\
		, ()			/* S2OI */	\
		, ()			/* S2OC */	\
		, ()			/* S2EO */	\
		, ()			/* S2EE */	\
		, ()			/* S2EI */	\
		, ()			/* S2EC */	\
		, ()			/* S2CO */	\
		, ()			/* S2CE */	\
		, ()			/* S2CI */	\
		, ()			/* S2CC */	\
	)						\

XENUM5_DECLARE(Scombs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_SCOMBS_HPP
