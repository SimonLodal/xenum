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
 * @return Name of the container class.
 * @hideinitializer
 */
#define _XENUM4_CNTNR_NAME(DECL)								\
	BOOST_PP_CAT(_XenumCntnr_, _XENUM4_DECL_GET_CNTNRNAME(DECL))


// ==============================================================================================
/**
 * Main entry function.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR(CTXT, DECL)							\
	class _XENUM4_CNTNR_NAME(DECL) {							NWLN \
		_XENUM4_DECLC_VALUE_T(CTXT, DECL)						\
		_XENUM4_DECLC_ENUM(CTXT, DECL)							\
		_XENUM4_DECLC_ENUM_OBJS(CTXT)							\
		_XENUM4_DECLC_FUNCS(CTXT, DECL)							\
	};											NWLN \
	typedef _XENUM4_CNTNR_NAME(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL);			NWLN


// ==============================================================================================
/**
 * Declare the value class type.
 * Not used here, but useful for XenumSet and others.
 * @hideinitializer
 */
#define _XENUM4_DECLC_VALUE_T(CTXT, DECL)							\
	public:											NWLN \
IND1		typedef _XENUM4_DECL_GET_VALUENAME(DECL) _value_t;				NWLN


// ==============================================================================================
/**
 * Copy native enum declaration from store class.
 * @hideinitializer
 */
#define _XENUM4_DECLC_ENUM(CTXT, DECL)								\
	public:											NWLN \
IND1		static constexpr const size_t _size = _XENUM4_STORE_NAME(DECL)::size;		NWLN \
IND1		using _index_t = typename _XENUM4_STORE_NAME(DECL)::index_t;			NWLN \
IND1		using _Enum = typename _XENUM4_STORE_NAME(DECL)::Enum;				NWLN \


// ==============================================================================================
/**
 * Declare the static enum-value objects.
 * @hideinitializer
 */
#define _XENUM4_DECLC_ENUM_OBJS(CTXT)								\
	public:											NWLN \
	_XENUM4_CALL_VALS(_XENUM4_DECLC_ENUM_OBJ, CTXT)

/**
 * Callback worker for _XENUM4_DECLC_ENUM_OBJS().
 * @hideinitializer
 */
#define _XENUM4_DECLC_ENUM_OBJ(CTXT, IDENT, ...)						\
IND1	static constexpr const _XENUM4_DECL_GET_VALUENAME(_XENUM4_CTXT_GET_DECL(CTXT))		\
	IDENT = _Enum::IDENT;									NWLN


// ==============================================================================================
/**
 * Declare ctors, comparison operators, other stuff.
 * @hideinitializer
 */
#define _XENUM4_DECLC_FUNCS(CTXT, DECL)								\
	_XENUM4_DECLC_FUNCS_I1(									\
		CTXT,										\
		_XENUM4_STORE_NAME(DECL),							\
		_XENUM4_CNTNR_NAME(DECL),							\
		_XENUM4_DECL_GET_VALUENAME(DECL)						\
	)

/**
 * Worker for _XENUM4_DECLC_FUNCS().
 * @hideinitializer
 */
#define _XENUM4_DECLC_FUNCS_I1(CTXT, STORENAME, CREALNAME, VALUENAME)				\
	public:											NWLN \
		/* Ctor. Do not use, except when iterating the enum-values. */			\
		/* All members of this class are static, so there is no */			\
		/* need to instantiate an object; just address the members */			\
		/* directly as $EnumCntnr::SomeValue. */					\
		/* However, range-based loops require an object, so use: */			\
		/* for (EnumValue enumValue : EnumCntnr()) { ... } */				\
IND1		constexpr CREALNAME (void) noexcept {}						NWLN \
	/* Wrapper for store class lookup functions. */						\
	public:											NWLN \
IND1		static VALUENAME _fromIndex(_index_t index)					\
			{ return STORENAME::fromIndex(index); }					NWLN \
IND1		static bool _fromIndex(_index_t index, VALUENAME& value) noexcept		\
			{ return STORENAME::fromIndex(index, value); }				NWLN \
IND1		static VALUENAME _fromIdentifier(const char* identifier)			\
			{ return STORENAME::fromIdent(identifier); }				NWLN \
IND1		static bool _fromIdentifier(const char* identifier, VALUENAME& value) noexcept	\
			{ return STORENAME::fromIdent(identifier, value); }			NWLN \
	/* Iteration support. */								\
	public:											NWLN \
		/* Iterator type for this container. */						\
IND1		typedef ::_XENUM4_NS::XenumCntnrIterator<CREALNAME> iterator;			NWLN \
		/* Get iterator to beginning (before the first enum-value). */			\
IND1		static iterator begin(void) noexcept { return iterator(0); }			NWLN \
		/* Get iterator to end (past the last enum-value). */				\
IND1		static iterator end(void) noexcept { return iterator(_size); }			NWLN


#endif // _XENUM4_IMPL_DECLARE_CNTNR_HPP
