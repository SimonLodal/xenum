/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_P0COMBS_HPP
#define TEST_XENUM_XENUMS_P0COMBS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum for testing combinations of custom property options:
 * - 1 data type: plain (int)
 * - 1 depth: 0
 * - 3 getter implementations: off, ext, cxp
 * - 4 lookup implementations: off, ext, inl, cxp
 * All these have different code paths in the generators so it is important to test them all.
 * Default values and empty arrays are also tested in each combination.
 */
#define XENUM5_P0combs(D,V,C)				\
	D(C, test::xenum::xenums::, P0combs, P0comb, , ,\
	(						\
		/* depth=0 */				\
		(OffOff, int, -1000, 0, (off,off)),	\
		(OffExt, int, -1001, 0, (off,ext)),	\
		(OffInl, int, -1002, 0, (off,inl)),	\
		(OffCxp, int, -1003, 0, (off,cxp)),	\
		(ExtOff, int, -1004, 0, (ext,off)),	\
		(ExtExt, int, -1005, 0, (ext,ext)),	\
		(ExtInl, int, -1006, 0, (ext,inl)),	\
		(ExtCxp, int, -1007, 0, (ext,cxp)),	\
		(CxpOff, int, -1008, 0, (cxp,off)),	\
		(CxpExt, int, -1009, 0, (cxp,ext)),	\
		(CxpInl, int, -1010, 0, (cxp,inl)),	\
		(CxpCxp, int, -1011, 0, (cxp,cxp))	\
	))						\
	V(C, V0						\
		/* depth=0 */				\
		, 1000			/* OffOff */	\
		, 1001			/* OffExt */	\
		, 1002			/* OffInl */	\
		, 1003			/* OffCxp */	\
		, 1004			/* ExtOff */	\
		, 1005			/* ExtExt */	\
		, 1006			/* ExtInl */	\
		, 1007			/* ExtCxp */	\
		, 1008			/* CxpOff */	\
		, 1009			/* CxpExt */	\
		, 1010			/* CxpInl */	\
		, 1011			/* CxpCxp */	\
	)						\
	V(C, V1						\
		/* depth=0 */				\
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
		/* depth=0 */				\
		, 1020			/* OffOff */	\
		, 1021			/* OffExt */	\
		, 1022			/* OffInl */	\
		, 1023			/* OffCxp */	\
		, 1024			/* ExtOff */	\
		, 1025			/* ExtExt */	\
		, 1026			/* ExtInl */	\
		, 1027			/* ExtCxp */	\
		, 1028			/* CxpOff */	\
		, 1029			/* CxpExt */	\
		, 1030			/* CxpInl */	\
		, 1031			/* CxpCxp */	\
	)						\

XENUM5_DECLARE(P0combs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_P0COMBS_HPP
