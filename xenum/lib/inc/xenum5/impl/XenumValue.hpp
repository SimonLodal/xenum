/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM5_IMPL_XENUMVALUE_HPP
#define _XENUM5_IMPL_XENUMVALUE_HPP

namespace xenum5 {


/**
 * Enum-value base class.
 * Thin wrapper around a native enum value.
 * Can never have an invalid value.
 * @param XenumStore The xenum store class, containing the native C++ enum.
 * @param enableGetIdentifier 0=off, 1|2=inline, 3=constexpr
 */
template<class XenumStore, int enableGetIdentifier>
class XenumValue {
protected:
	/// The internal store class.
	using Store = XenumStore;
public:
	/// Integer type used for enum values.
	using Index = typename XenumStore::Index;
	/// The native C++ enum class.
	using Enum = typename XenumStore::Enum;

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
	constexpr Index getIndex(void) const noexcept { return XenumStore::getIndex(value); }

	/// @return Identifier (name) of this enum value.
	template<int doEnable = enableGetIdentifier>
	typename std::enable_if<doEnable==1||doEnable==2, const char*>::type
	getIdentifier(void) const noexcept { return XenumStore::getIdentifier(value); }

	/// @return Identifier (name) of this enum value.
	template<int doEnable = enableGetIdentifier>
	constexpr typename std::enable_if<doEnable==3, const char*>::type
	getIdentifier(void) const noexcept { return XenumStore::getIdentifier(value); }

#ifdef _XENUM5_UNIT_TEST
	/// Fake getIdentifier() that just throws, for testing the case where it should not exist.
	/// It is not possible for a unit test to detect if a class member exists, but it can
	/// test if it throws.
	template<int doEnable = enableGetIdentifier>
	typename std::enable_if<doEnable==0, const char*>::type
	getIdentifier(void) const { throw std::logic_error("getIdentifier() is configured 'off'."); }

	/// Used by unit test to convert just any xenumvalue to 'true'.
	constexpr bool toTrue(void) const { return true; }
#endif

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


} // namespace xenum5
#endif // _XENUM5_IMPL_XENUMVALUE_HPP
