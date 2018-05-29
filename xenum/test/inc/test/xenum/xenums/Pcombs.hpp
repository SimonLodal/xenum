/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_PCOMBS_HPP
#define TEST_XENUM_XENUMS_PCOMBS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * Xenum for testing all combinations of custom property options:
 * - Data type
 * - Depth
 * - Getters implementation: off, std, inl, ce
 * All these have different code paths in the generators so it is important to test them all.
 * Default values and empty arrays are also tested in each combination.
 */
#define XENUM5_Pcombs(D,V,C)				\
	D(C, test::xenum::xenums::, Pcombs, Pcomb, , ,	\
	(						\
		/* plain, depth=0, source */		\
		(P0S, int, -1, 0, (0)),			\
		/* plain, depth=0, header */		\
		(P0H, int, -2, 0, (1)),			\
		/* plain, depth=1, source */		\
		(P1S, int, -3, 1, (0)),			\
		/* plain, depth=1, header */		\
		(P1H, int, -4, 1, (1)),			\
		/* plain, depth=2, source */		\
		(P2S, int, -5, 2, (0)),			\
		/* plain, depth=2, header */		\
		(P2H, int, -6, 2, (1)),			\
		/* cstring, depth=0, source */		\
		(S0S, cstring, "-1", 0, (0)),		\
		/* cstring, depth=0, header */		\
		(S0H, cstring, "-2", 0, (1)),		\
		/* cstring, depth=1, source */		\
		(S1S, cstring, "-3", 1, (0)),		\
		/* cstring, depth=1, header */		\
		(S1H, cstring, "-4", 1, (1)),		\
		/* cstring, depth=2, source */		\
		(S2S, cstring, "-5", 2, (0)),		\
		/* cstring, depth=2, header */		\
		(S2H, cstring, "-6", 2, (1))		\
	))						\
	V(C, V0						\
		, 0			/* P0S */	\
		, 1			/* P0H */	\
		, (2, , 3)		/* P1S */	\
		, (4, , 5)		/* P1H */	\
		, ((6,,7),())		/* P2S */	\
		, ((8,,9),())		/* P2H */	\
		, "0"			/* S0S */	\
		, "1"			/* S0H */	\
		, ("2", , "3")		/* S1S */	\
		, ("4", , "5")		/* S1H */	\
		, (("6",,"7"),())	/* S2S */	\
		, (("8",,"9"),())	/* S2H */	\
	)						\
	V(C, V1						\
		, 			/* P0S */	\
		, 			/* P0H */	\
		, 			/* P1S */	\
		, 			/* P1H */	\
		,			/* P2S */	\
		,			/* P2H */	\
		, 			/* S0S */	\
		, 			/* S0H */	\
		, 			/* S1S */	\
		, 			/* S1H */	\
		,			/* S2S */	\
		,			/* S2H */	\
	)						\
	V(C, V2						\
		, 10			/* P0S */	\
		, 11			/* P0H */	\
		, ()			/* P1S */	\
		, ()			/* P1H */	\
		, ()			/* P2S */	\
		, ()			/* P2H */	\
		, "10"			/* S0S */	\
		, "11"			/* S0H */	\
		, ()			/* S1S */	\
		, ()			/* S1H */	\
		, ()			/* S2S */	\
		, ()			/* S2H */	\
	)						\

XENUM5_DECLARE(Pcombs)


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_PCOMBS_HPP
