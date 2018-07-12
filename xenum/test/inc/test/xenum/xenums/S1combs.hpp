/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_S1COMBS_HPP
#define TEST_XENUM_XENUMS_S1COMBS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum for testing combinations of custom property options:
 * - 1 data type: cstring
 * - 1 depth: 1
 * - 3 getter implementations: off, ext, cxp
 * - 4 lookup implementations: off, ext, inl, cxp
 * All these have different code paths in the generators so it is important to test them all.
 * Default values and empty arrays are also tested in each combination.
 */
#define XENUM5_S1combs(D,V,C)				\
	D(C, test::xenum::xenums::, S1combs, S1comb, , ,\
	(						\
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
		(S1CC, cstring, "-1111", 1, (cxp,cxp))	\
	))						\
	V(C, V0						\
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
	)						\
	V(C, V1						\
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
	)						\
	V(C, V2						\
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
	)						\

XENUM5_DECLARE(S1combs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_S1COMBS_HPP
