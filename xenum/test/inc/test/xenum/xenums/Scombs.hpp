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
		/* cstring, depth=0, (ext) */		\
		(S0E, cstring, "-1", 0, (ext)),		\
		/* cstring, depth=0, (cxp) */		\
		(S0C, cstring, "-2", 0, (cxp)),		\
		/* cstring, depth=1, (ext) */		\
		(S1E, cstring, "-3", 1, (ext)),		\
		/* cstring, depth=1, (cxp) */		\
		(S1C, cstring, "-4", 1, (cxp)),		\
		/* cstring, depth=2, (ext) */		\
		(S2E, cstring, "-5", 2, (ext)),		\
		/* cstring, depth=2, (cxp) */		\
		(S2C, cstring, "-6", 2, (cxp))		\
	))						\
	V(C, V0						\
		, "0"			/* S0E */	\
		, "1"			/* S0C */	\
		, ("2", , "3")		/* S1E */	\
		, ("4", , "5")		/* S1C */	\
		, (("6",,"7"),())	/* S2E */	\
		, (("8",,"9"),())	/* S2C */	\
	)						\
	V(C, V1						\
		, 			/* S0E */	\
		, 			/* S0C */	\
		, 			/* S1E */	\
		, 			/* S1C */	\
		,			/* S2E */	\
		,			/* S2C */	\
	)						\
	V(C, V2						\
		, "10"			/* S0E */	\
		, "11"			/* S0C */	\
		, ()			/* S1E */	\
		, ()			/* S1C */	\
		, ()			/* S2E */	\
		, ()			/* S2C */	\
	)						\

XENUM5_DECLARE(Scombs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_SCOMBS_HPP
