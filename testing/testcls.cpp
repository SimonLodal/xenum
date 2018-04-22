/**
 * Testing xenum before creating generator code for it.
 */

#include <xenum5/Xenum.hpp>


/* ============================== DECLARATION ============================== */

class WrapCls {
public:
class _XenumCntnr_Fruits; 
class _XenumStore_Fruits { 
friend class _XenumCntnr_Fruits; 
public: 
	 static constexpr const size_t size = 0 +1 +1 +1; 
	 typedef ::xenum5::SelectInt<size>::type index_t; 
	 enum class Enum : index_t { 
		 banana, 
		 orange, 
		 peanut, 
	 }; 
	 typedef struct { 
		 char banana[sizeof("banana")]; 
		 char orange[sizeof("orange")]; 
		 char peanut[sizeof("peanut")]; 
	 } IdentPool; 
	 static const IdentPool identPool; 
	 typedef ::xenum5::SelectInt<sizeof(IdentPool)>::type IdentOffset; 
	 static const IdentOffset identOffsets[size]; 
	 static constexpr const IdentOffset* getIdentOffset(Enum value) noexcept { return &identOffsets[static_cast<index_t>(value)]; } 
	 static constexpr index_t getIndex(Enum value) noexcept { return static_cast<index_t>(value); } 
	 static constexpr const char* getIdentifier(Enum value) noexcept { return &((const char*)&identPool)[*getIdentOffset(value)]; } 
	 static Enum fromIndex(index_t index); 
	 static bool fromIndex(index_t index, ::xenum5::XenumValue<_XenumStore_Fruits>& value) noexcept; 
	 static Enum fromIdentifier(const char* identifier); 
	 static bool fromIdentifier(const char* identifier, ::xenum5::XenumValue<_XenumStore_Fruits>& value) noexcept; 
}; 
#if 0
// Simple typedef of XenumValue
typedef ::xenum5::XenumValue<_XenumStore_Fruits> Fruit;

#elseif 0
// Class inherited from XenumValue
//class _XenumValue_Fruit : public xenum5::XenumValue<_XenumStore_Fruits> {
template<class XenumStore>
class _XenumValue_Fruit : public ::xenum5::XenumValue<XenumStore> {
public: 
	constexpr _XenumValue_Fruit(void) noexcept
	: ::xenum5::XenumValue<XenumStore>::XenumValue()
	{ static_assert(true, "false"); }

	constexpr _XenumValue_Fruit(typename ::xenum5::XenumValue<XenumStore>::Enum value) noexcept
	: ::xenum5::XenumValue<XenumStore>::XenumValue(value)
	{ static_assert(true, "false"); }

// 	constexpr _XenumValue_Fruit(const _XenumValue_Fruit& other) noexcept
// 	: ::xenum5::XenumValue<XenumStore>::XenumValue(other)
// 	{ static_assert(true, "false"); }
}; 
typedef _XenumValue_Fruit<_XenumStore_Fruits> Fruit;
//typedef _XenumValue_Fruit Fruit; 

#else
// Complete value class template, not inherited.
template<class XenumStore>
class _XenumValue_Fruit {
public:
	/// The container class.
	typedef XenumStore store_t;
	/// Integer type used for enum values.
	using index_t = typename XenumStore::index_t;
	/// The native C++ enum class.
	using Enum = typename XenumStore::Enum;

public:
	/// Default ctor. Initialized with first native enum value.
	constexpr _XenumValue_Fruit(void) noexcept : value(static_cast<Enum>(0)) {}

	/// Ctor, initializing to a native enum value.
	constexpr _XenumValue_Fruit(Enum value) noexcept : value(value) {}

	/// Copy ctor.
	constexpr _XenumValue_Fruit(const _XenumValue_Fruit& other) noexcept : value(other.value) {}

	/// Assign from native enum value.
	_XenumValue_Fruit& operator= (Enum other) noexcept { value = other; return *this; }

	/// Assign from other _XenumValue_Fruit object.
	_XenumValue_Fruit& operator= (const _XenumValue_Fruit& other) noexcept { value = other.value; return *this; }

public:
	/// @return Native enum value.
	constexpr Enum operator() (void) const noexcept { return value; }

	/// @return Index of this enum value in it's enum class.
	constexpr index_t getIndex(void) const noexcept { return static_cast<index_t>(value); }

	/// @return Identifier of this enum value.
	constexpr const char* getIdentifier(void) const noexcept { return XenumStore::getIdentifier(value); }

public:
	/// @name Comparison operators
	///@{
	constexpr bool operator== (const _XenumValue_Fruit& other) const noexcept { return value == other.value; }
	constexpr bool operator== (const Enum other) const noexcept { return value == other; }
	constexpr bool operator!= (const _XenumValue_Fruit& other) const noexcept { return value != other.value; }
	constexpr bool operator!= (const Enum other) const noexcept { return value != other; }
	constexpr bool operator< (const _XenumValue_Fruit& other) const noexcept { return value < other.value; }
	constexpr bool operator< (const Enum other) const noexcept { return value < other; }
	constexpr bool operator<= (const _XenumValue_Fruit& other) const noexcept { return value <= other.value; }
	constexpr bool operator<= (const Enum other) const noexcept { return value <= other; }
	constexpr bool operator> (const _XenumValue_Fruit& other) const noexcept { return value > other.value; }
	constexpr bool operator> (const Enum other) const noexcept { return value > other; }
	constexpr bool operator>= (const _XenumValue_Fruit& other) const noexcept { return value >= other.value; }
	constexpr bool operator>= (const Enum other) const noexcept { return value >= other; }
	///@}
protected:
	/// The native enum value that this object wraps.
	Enum value;
};

typedef _XenumValue_Fruit<_XenumStore_Fruits> Fruit;

#endif // value class


#if 1
class _XenumCntnr_Fruits { 
public: 
	 typedef Fruit _value_t; 
public: 
	 static constexpr const size_t _size = _XenumStore_Fruits::size; 
	 using _index_t = typename _XenumStore_Fruits::index_t; 
	 using _Enum = typename _XenumStore_Fruits::Enum; 
public: 
#if 1
	 static constexpr const Fruit banana = _Enum::banana;
//	 static constexpr const Fruit orange = _Enum::orange; 
//	 static constexpr const Fruit peanut = _Enum::peanut; 
#endif
public: 
	 constexpr _XenumCntnr_Fruits (void) noexcept {} 
public: 
	 static Fruit _fromIndex(_index_t index) { return _XenumStore_Fruits::fromIndex(index); } 
	 static bool _fromIndex(_index_t index, Fruit& value) noexcept { return _XenumStore_Fruits::fromIndex(index, value); } 
	 static Fruit _fromIdentifier(const char* identifier) { return _XenumStore_Fruits::fromIdent(identifier); } 
	 static bool _fromIdentifier(const char* identifier, Fruit& value) noexcept { return _XenumStore_Fruits::fromIdent(identifier, value); } 
public: 
	 typedef ::xenum5::XenumCntnrIterator<_XenumCntnr_Fruits> iterator; 
	 static iterator begin(void) noexcept { return iterator(0); } 
	 static iterator end(void) noexcept { return iterator(_size); } 
}; 
typedef _XenumCntnr_Fruits Fruits; 
#endif



}; // class WrapCls


/* ============================== DEFINITION ============================== */












int main(int argc, char* argv[])
{
	std::cout<<"xenum testcls..."<<std::endl;
}
