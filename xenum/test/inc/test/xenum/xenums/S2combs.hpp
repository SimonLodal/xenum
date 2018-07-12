/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_S2COMBS_HPP
#define TEST_XENUM_XENUMS_S2COMBS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum for testing combinations of custom property options:
 * - 1 data type: cstring
 * - 1 depth: 2
 * - 3 getter implementations: off, ext, cxp
 * - 4 lookup implementations: off, ext, inl, cxp
 * All these have different code paths in the generators so it is important to test them all.
 * Default values and empty arrays are also tested in each combination.
 */
#define XENUM5_S2combs(D,V,C)				\
	D(C, test::xenum::xenums::, S2combs, S2comb, , ,\
	(						\
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

XENUM5_DECLARE(S2combs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_S2COMBS_HPP
