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
		(OffOff, cstring, "-1100", 1, (off,off)),	\
		(OffExt, cstring, "-1101", 1, (off,ext)),	\
		(OffInl, cstring, "-1102", 1, (off,inl)),	\
		(OffCxp, cstring, "-1103", 1, (off,cxp)),	\
		(ExtOff, cstring, "-1104", 1, (ext,off)),	\
		(ExtExt, cstring, "-1105", 1, (ext,ext)),	\
		(ExtInl, cstring, "-1106", 1, (ext,inl)),	\
		(ExtCxp, cstring, "-1107", 1, (ext,cxp)),	\
		(CxpOff, cstring, "-1108", 1, (cxp,off)),	\
		(CxpExt, cstring, "-1109", 1, (cxp,ext)),	\
		(CxpInl, cstring, "-1110", 1, (cxp,inl)),	\
		(CxpCxp, cstring, "-1111", 1, (cxp,cxp))	\
	))						\
	V(C, V0						\
		/* depth=1 */				\
		, ("1100", , "1101")	/* OffOff */	\
		, ("1102", , "1103")	/* OffExt */	\
		, ("1104", , "1105")	/* OffInl */	\
		, ("1106", , "1107")	/* OffCxp */	\
		, ("1110", , "1111")	/* ExtOff */	\
		, ("1112", , "1113")	/* ExtExt */	\
		, ("1114", , "1115")	/* ExtInl */	\
		, ("1116", , "1117")	/* ExtCxp */	\
		, ("1120", , "1121")	/* CxpOff */	\
		, ("1122", , "1123")	/* CxpExt */	\
		, ("1124", , "1125")	/* CxpInl */	\
		, ("1126", , "1127")	/* CxpCxp */	\
	)						\
	V(C, V1						\
		/* depth=1 */				\
		,			/* OffOff */	\
		,			/* OffExt */	\
		,			/* OffInl */	\
		,			/* OffCxp */	\
		,			/* ExtOff */	\
		,			/* ExtExt */	\
		,			/* ExtInl */	\
		,			/* ExtCxp */	\
		,			/* CxpOff */	\
		,			/* CxpExt */	\
		,			/* CxpInl */	\
		,			/* CxpCxp */	\
	)						\
	V(C, V2						\
		/* depth=1 */				\
		, ()			/* OffOff */	\
		, ()			/* OffExt */	\
		, ()			/* OffInl */	\
		, ()			/* OffCxp */	\
		, ()			/* ExtOff */	\
		, ()			/* ExtExt */	\
		, ()			/* ExtInl */	\
		, ()			/* ExtCxp */	\
		, ()			/* CxpOff */	\
		, ()			/* CxpExt */	\
		, ()			/* CxpInl */	\
		, ()			/* CxpCxp */	\
	)						\

XENUM5_DECLARE(S1combs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_S1COMBS_HPP
