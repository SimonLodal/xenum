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
		/* depth=0, (off) */			\
		(S0O, cstring, "-11", 0, (off)),	\
		/* depth=0, (ext) */			\
		(S0E, cstring, "-12", 0, (ext)),	\
		/* depth=0, (cxp) */			\
		(S0C, cstring, "-13", 0, (cxp)),	\
		/* depth=1, (off) */			\
		(S1O, cstring, "-21", 1, (off)),	\
		/* depth=1, (ext) */			\
		(S1E, cstring, "-22", 1, (ext)),	\
		/* depth=1, (cxp) */			\
		(S1C, cstring, "-23", 1, (cxp)),	\
		/* depth=2, (off) */			\
		(S2O, cstring, "-31", 2, (off)),	\
		/* depth=2, (ext) */			\
		(S2E, cstring, "-32", 2, (ext)),	\
		/* depth=2, (cxp) */			\
		(S2C, cstring, "-33", 2, (cxp))		\
	))						\
	V(C, V0						\
		, "11"			/* S0O */	\
		, "12"			/* S0E */	\
		, "13"			/* S0C */	\
		, ("21", , "22")	/* S1O */	\
		, ("23", , "24")	/* S1E */	\
		, ("25", , "26")	/* S1C */	\
		, (("31",,"32"),())	/* S2O */	\
		, (("33",,"34"),())	/* S2E */	\
		, (("35",,"36"),())	/* S2C */	\
	)						\
	V(C, V1						\
		, 			/* S0O */	\
		, 			/* S0E */	\
		, 			/* S0C */	\
		, 			/* S1O */	\
		, 			/* S1E */	\
		, 			/* S1C */	\
		,			/* S2O */	\
		,			/* S2E */	\
		,			/* S2C */	\
	)						\
	V(C, V2						\
		, "211"			/* S0O */	\
		, "212"			/* S0E */	\
		, "213"			/* S0C */	\
		, ()			/* S1O */	\
		, ()			/* S1E */	\
		, ()			/* S1C */	\
		, ()			/* S2O */	\
		, ()			/* S2E */	\
		, ()			/* S2C */	\
	)						\

XENUM5_DECLARE(Scombs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_SCOMBS_HPP
