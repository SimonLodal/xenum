/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Declaration of the public container class class.
 */
#ifndef _XENUM4_IMPL_DECLARE_CNTNR_HPP
#define _XENUM4_IMPL_DECLARE_CNTNR_HPP


// ==============================================================================================
/**
 * Main entry function.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR(CTXT, DECL)							\
	class _XENUM4_DECL_GET_CNTNRNAME(DECL) {						NWLN \
		_XENUM4_DECLC_VALUE_T(CTXT, DECL)						\
		_XENUM4_DECLC_ENUM(CTXT, DECL)							\
		_XENUM4_DECLC_ENUM_COPY(CTXT)							\
		_XENUM4_DECLC_FUNCS(CTXT, DECL)							\
/* FIXME: Move content to store class, only leave wrappers. */					\
	_XENUM4_PROPS_DECLC(CTXT)								\
	};											NWLN


// ==============================================================================================
/**
 * Declare the value class type.
 * Not used here, but useful for XenumSet and others.
 * @hideinitializer
 */
// FIXME: Move to store class. Change XenumValue template parameter from cntnr to store class.
#define _XENUM4_DECLC_VALUE_T(CTXT, DECL)							\
	public:											NWLN \
IND1		typedef ::_XENUM4_NS::XenumValue<_XENUM4_DECL_GET_CNTNRNAME(DECL)> value_t;	NWLN \


// ==============================================================================================
/**
 * Copy native enum declaration from store class.
 * @hideinitializer
 */
// FIXME: Underscore prefix on everything.
#define _XENUM4_DECLC_ENUM(CTXT, DECL)								\
	public:											NWLN \
IND1		static constexpr const size_t size = _XENUM4_STORE_NAME(DECL)::_size;		NWLN \
IND1		using index_t = typename _XENUM4_STORE_NAME(DECL)::_index_t;			NWLN \
IND1		using Enum = typename _XENUM4_STORE_NAME(DECL)::_Enum;				NWLN \


// ==============================================================================================
/**
 * Declare the static enum-value copies.
 * @hideinitializer
 */
#define _XENUM4_DECLC_ENUM_COPY(CTXT)								\
	public:											NWLN \
	_XENUM4_CALL_VALS(_XENUM4_DECLC_ENUM_COPY_MEMBER, CTXT)

/**
 * Callback worker for _XENUM4_DECLC_ENUM_COPY().
 * @hideinitializer
 */
#define _XENUM4_DECLC_ENUM_COPY_MEMBER(CTXT, IDENT, ...)					\
IND1	static constexpr const Enum IDENT = Enum::IDENT;					NWLN


// ==============================================================================================
/**
 * Declare ctors, comparison operators, other stuff.
 * @hideinitializer
 */
// FIXME: Delete getIndex() and getIdentifier(), do not belong here.
// FIXME: Underscore prefix on everything.
#define _XENUM4_DECLC_FUNCS(CTXT, DECL)								\
	public:											NWLN \
		/* @return Index of an enum value. */						\
IND1		static constexpr index_t getIndex(Enum value) noexcept				\
			{ return static_cast<index_t>(value); }					NWLN \
		/* @return Identifier of an enum value. */					\
IND1		static constexpr const char* getIdentifier(Enum value) noexcept			\
			{ return _XENUM4_STORE_NAME(DECL) ::_getIdentifier(value); }		NWLN \
	public:											NWLN \
		/* Ctor. Do not use, except when iterating the enum-values. */			\
		/* All members of this class are static, so there is no */			\
		/* need to instantiate an object; just address the members */			\
		/* directly as $EnumCntnr::Some_Value. */					\
		/* However, range-based loops require an object, so use: */			\
		/* for (EnumValue enumValue : EnumCntnr()) { ... } */				\
IND1		constexpr _XENUM4_DECL_GET_CNTNRNAME(DECL)(void) noexcept {}			NWLN \
	/* Wrapper for store class lookup functions. */						\
	public:											NWLN \
IND1		static Enum fromIndex(index_t index)						NWLN \
			{ return _XENUM4_STORE_NAME(DECL)::_fromIndex(index); }			NWLN \
IND1		static bool fromIndex(index_t index, Enum& value) noexcept			NWLN \
			{ return _XENUM4_STORE_NAME(DECL)::_fromIndex(index, value); }		NWLN \
IND1		static Enum fromIdentifier(const char* identifier)				NWLN \
			{ return _XENUM4_STORE_NAME(DECL)::_fromIdent(identifier); }		NWLN \
IND1		static bool fromIdentifier(const char* identifier, Enum& value) noexcept	NWLN \
			{ return _XENUM4_STORE_NAME(DECL)::_fromIdent(identifier, value); }	NWLN \
	/* Iteration support. */								\
	public:											NWLN \
		/* Iterator type for this container. */						\
IND1		typedef ::_XENUM4_NS::XenumCntnrIterator<_XENUM4_DECL_GET_CNTNRNAME(DECL)> iterator; NWLN \
		/* Get iterator to beginning (before the first enum-value). */			\
IND1		static iterator begin(void) noexcept { return iterator(0); }			NWLN \
		/* Get iterator to end (past the last enum-value). */				\
IND1		static iterator end(void) noexcept { return iterator(size); }			NWLN


#endif // _XENUM4_IMPL_DECLARE_CNTNR_HPP
