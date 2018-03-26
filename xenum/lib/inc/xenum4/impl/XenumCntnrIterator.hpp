/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM4_IMPL_XENUMCNTNRITERATOR_HPP
#define _XENUM4_IMPL_XENUMCNTNRITERATOR_HPP

namespace xenum4 {


/**
 * Iterator for xenum container classes.
 * Simple forward iterator (implicitly const), just enough to support range-based iteration.
 *
 * Created in each container class as 'iterator', so do not use this template directly.
 * @param XenumCntnr The xenum container class to create an iterator class for.
 */
template<class XenumCntnr>
class XenumCntnrIterator {
public:
	/// Enum-value class.
	using value_t = typename XenumCntnr::value_t;
	/// Integer type used for enum values.
	using index_t = typename XenumCntnr::index_t;
	/// The native C++ enum class.
	using Enum = typename XenumCntnr::Enum;
public:
	/// Default ctor, initializes to first value in the enum.
	XenumCntnrIterator(void) noexcept : index(0) {}

	/// Ctor with initialization to a specific enum-value.
	XenumCntnrIterator(const value_t& value) noexcept : index(value.getIndex()) {}

	/// Prefix increment operator.
	XenumCntnrIterator& operator++(void) noexcept { index++; return *this; }

	/// Comparison operator.
	bool operator!=(const XenumCntnrIterator& other) noexcept { return index != other.index; }

	/// Dereference operator.
	value_t operator*(void) { return XenumCntnr::fromIndex(index); }
protected:
	/// Ctor with initialization to a specific index.
	/// Not bounds-checked before dereferenced.
	XenumCntnrIterator(index_t index) noexcept : index(index) {}

	/// Allow begin() to use the protected ctor.
	friend XenumCntnrIterator XenumCntnr::begin(void);

	/// Allow end() to use the protected ctor.
	friend XenumCntnrIterator XenumCntnr::end(void);
protected:
	/// Current position.
	index_t index;
};


} // namespace xenum4
#endif // _XENUM4_IMPL_XENUMVALUE_HPP
