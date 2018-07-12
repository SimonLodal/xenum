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
		(OffOff, int, -1200, 2, (off,off)),	\
		(OffExt, int, -1201, 2, (off,ext)),	\
		(OffInl, int, -1202, 2, (off,inl)),	\
		(OffCxp, int, -1203, 2, (off,cxp)),	\
		(ExtOff, int, -1204, 2, (ext,off)),	\
		(ExtExt, int, -1205, 2, (ext,ext)),	\
		(ExtInl, int, -1206, 2, (ext,inl)),	\
		(ExtCxp, int, -1207, 2, (ext,cxp)),	\
		(CxpOff, int, -1208, 2, (cxp,off)),	\
		(CxpExt, int, -1209, 2, (cxp,ext)),	\
		(CxpInl, int, -1210, 2, (cxp,inl)),	\
		(CxpCxp, int, -1211, 2, (cxp,cxp))	\
	))						\
	V(C, V0						\
		/* depth=2 */				\
		, ((1200,,1201),())	/* OffOff */	\
		, ((1202,,1203),())	/* OffExt */	\
		, ((1204,,1205),())	/* OffInl */	\
		, ((1206,,1207),())	/* OffCxp */	\
		, ((1210,,1211),())	/* ExtOff */	\
		, ((1212,,1213),())	/* ExtExt */	\
		, ((1214,,1215),())	/* ExtInl */	\
		, ((1216,,1217),())	/* ExtCxp */	\
		, ((1220,,1221),())	/* CxpOff */	\
		, ((1222,,1223),())	/* CxpExt */	\
		, ((1224,,1225),())	/* CxpInl */	\
		, ((1226,,1227),())	/* CxpCxp */	\
	)						\
	V(C, V1						\
		/* depth=2 */				\
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
		/* depth=2 */				\
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

XENUM5_DECLARE(P2combs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_P2COMBS_HPP
