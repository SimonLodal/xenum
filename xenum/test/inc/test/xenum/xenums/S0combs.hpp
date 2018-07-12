/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_S0COMBS_HPP
#define TEST_XENUM_XENUMS_S0COMBS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum for testing combinations of custom property options:
 * - 1 data type: cstring
 * - 1 depth: 0
 * - 3 getter implementations: off, ext, cxp
 * - 4 lookup implementations: off, ext, inl, cxp
 * All these have different code paths in the generators so it is important to test them all.
 * Default values and empty arrays are also tested in each combination.
 */
#define XENUM5_S0combs(D,V,C)				\
	D(C, test::xenum::xenums::, S0combs, S0comb, , ,\
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
		(S0CC, cstring, "-1011", 0, (cxp,cxp))	\
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
	)						\

XENUM5_DECLARE(S0combs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_S0COMBS_HPP
