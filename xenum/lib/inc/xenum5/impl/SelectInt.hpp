/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM5_IMPL_SELECTINT_HPP
#define _XENUM5_IMPL_SELECTINT_HPP

namespace xenum5 {


/**
 * Select an integer type large enough to hold a given max value.
 * Selects an unsigned type by default.
 * @param maxValue Maximum value the integer type must be able to hold.
 * @param makeSigned Force the selected type to be signed. Else it becomes unsigned.
 * @param compatSigned If unsigned type is selected, make sure it is compatible with
 *	a signed type of the same size, that is, that it does not use the highest
 *	bit; else the next larger unsigned type will be selected.
 */
template<uint64_t maxValue, bool makeSigned = false, bool compatSigned = false>
struct SelectInt {
	static_assert(!((maxValue > 0x7fffffffffffffff) && makeSigned), "maxValue to large to be held in an int64_t.");
	static_assert(!((maxValue > 0x7fffffffffffffff) && compatSigned), "maxValue to large to be held in an uint64_t compatible with int64_t.");
	using type =
	typename std::conditional<
		makeSigned,
		// Signed
		typename std::conditional<(maxValue > 0x7fffffff), int64_t,
		typename std::conditional<(maxValue > 0x7fff), int32_t,
		typename std::conditional<(maxValue > 0x7f), int16_t, int8_t
		>::type
		>::type
		>::type
		,
		typename std::conditional<
			compatSigned,
			// Unsigned, signed-compatible
			typename std::conditional<(maxValue > 0x7fffffff), uint64_t,
			typename std::conditional<(maxValue > 0x7fff), uint32_t,
			typename std::conditional<(maxValue > 0x7f), uint16_t, uint8_t
			>::type
			>::type
			>::type
			,
			// Unsigned
			typename std::conditional<(maxValue > 0xffffffff), uint64_t,
			typename std::conditional<(maxValue > 0xffff), uint32_t,
			typename std::conditional<(maxValue > 0xff), uint16_t, uint8_t
			>::type
			>::type
			>::type
		>::type
	>::type;
};


} // namespace xenum5
#endif // _XENUM5_IMPL_SELECTINT_HPP
