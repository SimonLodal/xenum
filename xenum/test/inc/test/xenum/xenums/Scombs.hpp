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
		/* depth=0, (off,off) */		\
		(S0OO, cstring, "-11", 0, (off,off)),	\
		/* depth=0, (ext,off) */		\
		(S0EO, cstring, "-12", 0, (ext,off)),	\
		/* depth=0, (cxp,off) */		\
		(S0CO, cstring, "-13", 0, (cxp,off)),	\
		/* depth=1, (off,off) */		\
		(S1OO, cstring, "-21", 1, (off,off)),	\
		/* depth=1, (ext,off) */		\
		(S1EO, cstring, "-22", 1, (ext,off)),	\
		/* depth=1, (cxp,off) */		\
		(S1CO, cstring, "-23", 1, (cxp,off)),	\
		/* depth=2, (off,off) */		\
		(S2OO, cstring, "-31", 2, (off,off)),	\
		/* depth=2, (ext,off) */		\
		(S2EO, cstring, "-32", 2, (ext,off)),	\
		/* depth=2, (cxp,off) */		\
		(S2CO, cstring, "-33", 2, (cxp,off))	\
	))						\
	V(C, V0						\
		, "11"			/* S0OO */	\
		, "12"			/* S0EO */	\
		, "13"			/* S0CO */	\
		, ("21", , "22")	/* S1OO */	\
		, ("23", , "24")	/* S1EO */	\
		, ("25", , "26")	/* S1CO */	\
		, (("31",,"32"),())	/* S2OO */	\
		, (("33",,"34"),())	/* S2EO */	\
		, (("35",,"36"),())	/* S2CO */	\
	)						\
	V(C, V1						\
		, 			/* S0OO */	\
		, 			/* S0EO */	\
		, 			/* S0CO */	\
		, 			/* S1OO */	\
		, 			/* S1EO */	\
		, 			/* S1CO */	\
		,			/* S2OO */	\
		,			/* S2EO */	\
		,			/* S2CO */	\
	)						\
	V(C, V2						\
		, "211"			/* S0OO */	\
		, "212"			/* S0EO */	\
		, "213"			/* S0CO */	\
		, ()			/* S1OO */	\
		, ()			/* S1EO */	\
		, ()			/* S1CO */	\
		, ()			/* S2OO */	\
		, ()			/* S2EO */	\
		, ()			/* S2CO */	\
	)						\

XENUM5_DECLARE(Scombs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_SCOMBS_HPP
