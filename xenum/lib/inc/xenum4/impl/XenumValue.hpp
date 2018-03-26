/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM4_IMPL_XENUMVALUE_HPP
#define _XENUM4_IMPL_XENUMVALUE_HPP

namespace xenum4 {


/**
 * Enum-value class.
 * Wraps a native enum value. Can never have an invalid value.
 * @param XenumStore The xenum store class, containing the native C++ enum.
 */
template<class XenumStore>
class XenumValue {
public:
	/// The container class.
	typedef XenumStore store_t;
	/// Integer type used for enum values.
	using index_t = typename XenumStore::_index_t;
	/// The native C++ enum class.
	using Enum = typename XenumStore::_Enum;

public:
	/// Default ctor. Initialized with first native enum value.
	constexpr XenumValue(void) noexcept : value(static_cast<Enum>(0)) {}

	/// Ctor, initializing to a native enum value.
	constexpr XenumValue(Enum value) noexcept : value(value) {}

	/// Copy ctor.
	constexpr XenumValue(const XenumValue& other) noexcept : value(other.value) {}

	/// Assign from native enum value.
	XenumValue& operator= (Enum other) noexcept { value = other; return *this; }

	/// Assign from other XenumValue object.
	XenumValue& operator= (const XenumValue& other) noexcept { value = other.value; return *this; }

public:
	/// @return Native enum value.
	constexpr Enum operator() (void) const noexcept { return value; }

	/// @return Index of this enum value in it's enum class.
	constexpr index_t getIndex(void) const noexcept { return static_cast<index_t>(value); }

	/// @return Identifier of this enum value.
	constexpr const char* getIdentifier(void) const noexcept { return XenumStore::_getIdentifier(value); }

public:
	/// @name Comparison operators
	///@{
	constexpr bool operator== (const XenumValue& other) const noexcept { return value == other.value; }
	constexpr bool operator== (const Enum other) const noexcept { return value == other; }
	constexpr bool operator!= (const XenumValue& other) const noexcept { return value != other.value; }
	constexpr bool operator!= (const Enum other) const noexcept { return value != other; }
	constexpr bool operator< (const XenumValue& other) const noexcept { return value < other.value; }
	constexpr bool operator< (const Enum other) const noexcept { return value < other; }
	constexpr bool operator<= (const XenumValue& other) const noexcept { return value <= other.value; }
	constexpr bool operator<= (const Enum other) const noexcept { return value <= other; }
	constexpr bool operator> (const XenumValue& other) const noexcept { return value > other.value; }
	constexpr bool operator> (const Enum other) const noexcept { return value > other; }
	constexpr bool operator>= (const XenumValue& other) const noexcept { return value >= other.value; }
	constexpr bool operator>= (const Enum other) const noexcept { return value >= other; }
	///@}
protected:
	/// The native enum value that this object wraps.
	Enum value;
};


} // namespace xenum4
#endif // _XENUM4_IMPL_XENUMVALUE_HPP
