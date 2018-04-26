/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM5_IMPL_XENUMCNTNRITERATOR_HPP
#define _XENUM5_IMPL_XENUMCNTNRITERATOR_HPP

namespace xenum5 {


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
	using Value = typename XenumCntnr::_value_t;
	/// Integer type used for enum values.
	using Index = typename XenumCntnr::_index_t;
	/// The native C++ enum class.
	using Enum = typename XenumCntnr::_enum;
public:
	/// Default ctor, initializes to first value in the enum.
	XenumCntnrIterator(void) noexcept : index(0) {}

	/// Ctor with initialization to a specific enum-value.
	XenumCntnrIterator(const Value& value) noexcept : index(value.getIndex()) {}

	/// Prefix increment operator.
	XenumCntnrIterator& operator++(void) noexcept { index++; return *this; }

	/// Comparison operator.
	bool operator!=(const XenumCntnrIterator& other) noexcept { return index != other.index; }

	/// Dereference operator.
	Value operator*(void) { return XenumCntnr::_fromIndex(index); }
protected:
	/// Ctor with initialization to a specific index.
	/// Not bounds-checked before dereferenced.
	XenumCntnrIterator(Index index) noexcept : index(index) {}

	/// Allow begin() to use the protected ctor.
	friend XenumCntnrIterator XenumCntnr::begin(void) noexcept;

	/// Allow end() to use the protected ctor.
	friend XenumCntnrIterator XenumCntnr::end(void) noexcept;
protected:
	/// Current position.
	Index index;
};


} // namespace xenum5
#endif // _XENUM5_IMPL_XENUMVALUE_HPP
