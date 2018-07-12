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
		(P0CC, int, -1011, 0, (cxp,cxp))	\
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
		, 1030			/* P0CI */	\
		, 1031			/* P0CC */	\
	)						\

XENUM5_DECLARE(P0combs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_P0COMBS_HPP
