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
		(OffOff, int, -1100, 1, (off,off)),	\
		(OffExt, int, -1101, 1, (off,ext)),	\
		(OffInl, int, -1102, 1, (off,inl)),	\
		(OffCxp, int, -1103, 1, (off,cxp)),	\
		(ExtOff, int, -1104, 1, (ext,off)),	\
		(ExtExt, int, -1105, 1, (ext,ext)),	\
		(ExtInl, int, -1106, 1, (ext,inl)),	\
		(ExtCxp, int, -1107, 1, (ext,cxp)),	\
		(CxpOff, int, -1108, 1, (cxp,off)),	\
		(CxpExt, int, -1109, 1, (cxp,ext)),	\
		(CxpInl, int, -1110, 1, (cxp,inl)),	\
		(CxpCxp, int, -1111, 1, (cxp,cxp))	\
	))						\
	V(C, V0						\
		/* depth=1 */				\
		, (1100, , 1101)	/* OffOff */	\
		, (1102, , 1103)	/* OffExt */	\
		, (1104, , 1105)	/* OffInl */	\
		, (1106, , 1107)	/* OffCxp */	\
		, (1110, , 1111)	/* ExtOff */	\
		, (1112, , 1113)	/* ExtExt */	\
		, (1114, , 1115)	/* ExtInl */	\
		, (1116, , 1117)	/* ExtCxp */	\
		, (1120, , 1121)	/* CxpOff */	\
		, (1122, , 1123)	/* CxpExt */	\
		, (1124, , 1125)	/* CxpInl */	\
		, (1126, , 1127)	/* CxpCxp */	\
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

XENUM5_DECLARE(P1combs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_P1COMBS_HPP
