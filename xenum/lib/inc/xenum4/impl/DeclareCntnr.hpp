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
	_XENUM4_DECL_GET_CNTNRNAME(DECL)

//	BOOST_PP_CAT(_Xenum4Cntnr_, _XENUM4_DECL_GET_CNTNRNAME(DECL))


// ==============================================================================================
/**
 * Main entry function.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR(CTXT, DECL)							\
	_XENUM4_DOC(Enum container class.							_XENUM4_NWLN \
		Contains all the enum values as value objects, lookup functions, and iteration.)\
	class _XENUM4_CNTNR_NAME(DECL) {							_XENUM4_NWLN \
		_XENUM4_INDENT_INC								\
		_XENUM4_DECLC_VALUE_T(CTXT, DECL)						\
		_XENUM4_DECLC_ENUM(CTXT, DECL)							\
		_XENUM4_DECLC_ENUM_OBJS(CTXT)							\
		_XENUM4_DECLC_FUNCS(CTXT, DECL)							\
		_XENUM4_INDENT_DEC								\
	};											_XENUM4_NWLN
//	typedef _XENUM4_CNTNR_NAME(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL);

// ==============================================================================================
/**
 * Declare the value class type.
 * Not used here, but useful for XenumSet and others.
 * @hideinitializer
 */
#define _XENUM4_DECLC_VALUE_T(CTXT, DECL)							\
_XENUM4_INDENT_SUB										\
public:												_XENUM4_NWLN \
	_XENUM4_DOC(The enum-value class.)							\
	typedef _XENUM4_DECL_GET_VALUENAME(DECL) _Value;					_XENUM4_NWLN


// ==============================================================================================
/**
 * Copy native enum declaration from store class.
 * @hideinitializer
 */
#define _XENUM4_DECLC_ENUM(CTXT, DECL)								\
_XENUM4_INDENT_SUB										\
public:												_XENUM4_NWLN \
	_XENUM4_DOC(@copydoc _XENUM4_STORE_NAME(DECL)::size)					\
	static constexpr const size_t _size = _XENUM4_STORE_NAME(DECL)::size;			_XENUM4_NWLN \
	_XENUM4_DOC(@copydoc _XENUM4_STORE_NAME(DECL)::Index)					\
	using _Index = typename _XENUM4_STORE_NAME(DECL)::Index;				_XENUM4_NWLN \
	_XENUM4_DOC(@copydoc _XENUM4_STORE_NAME(DECL)::Enum)					\
	using _Enum = typename _XENUM4_STORE_NAME(DECL)::Enum;					_XENUM4_NWLN \


// ==============================================================================================
/**
 * Declare the static enum-value objects.
 * @hideinitializer
 */
// FIXME: Add some doxygen group wrapper so each value does not have to be documented.
#define _XENUM4_DECLC_ENUM_OBJS(CTXT)								\
_XENUM4_INDENT_SUB										\
public:												_XENUM4_NWLN \
	_XENUM4_CALL_VALS(_XENUM4_DECLC_ENUM_OBJ, CTXT)

/**
 * Callback worker for _XENUM4_DECLC_ENUM_OBJS().
 * @hideinitializer
 */
#define _XENUM4_DECLC_ENUM_OBJ(CTXT, IDENT, ...)						\
	static constexpr const _XENUM4_DECL_GET_VALUENAME(_XENUM4_CTXT_GET_DECL(CTXT))		\
		IDENT = _Enum::IDENT;								_XENUM4_NWLN


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
_XENUM4_INDENT_SUB										\
public:												_XENUM4_NWLN \
	_XENUM4_DOC(Ctor. Do not use, except when iterating the enum-values.			_XENUM4_NWLN \
		All members of this class are static, so there is no				_XENUM4_NWLN \
		need to instantiate an object; just address the members				_XENUM4_NWLN \
		directly as CREALNAME::SomeValue.						_XENUM4_NWLN \
		However, range-based loops require an object, so use:				_XENUM4_NWLN \
		_XENUM4_INDENT_INC								\
		@code										_XENUM4_NWLN \
		for (VALUENAME enumValue : CREALNAME()) { ... }					_XENUM4_NWLN \
		@endcode)									\
	constexpr CREALNAME (void) noexcept {}							_XENUM4_NWLN \
	/* Wrapper for store class lookup functions. */						\
_XENUM4_INDENT_SUB										\
public:												_XENUM4_NWLN \
	_XENUM4_DOC(@copydoc STORENAME::fromIndex(Index index))					\
	static VALUENAME _fromIndex(_Index index)						\
		{ return STORENAME::fromIndex(index); }						_XENUM4_NWLN \
	_XENUM4_DOC(@copydoc STORENAME::fromIndex(Index index, VALUENAME& value) noexcept)	\
	static bool _fromIndex(_Index index, VALUENAME& value) noexcept				\
		{ return STORENAME::fromIndex(index, value); }					_XENUM4_NWLN \
	_XENUM4_DOC(@copydoc STORENAME::fromIdent(const char* identifier))			\
	static VALUENAME _fromIdentifier(const char* identifier)				\
		{ return STORENAME::fromIdent(identifier); }					_XENUM4_NWLN \
	_XENUM4_DOC(@copydoc STORENAME::fromIdent(const char* identifier, VALUENAME& value) noexcept)	\
	static bool _fromIdentifier(const char* identifier, VALUENAME& value) noexcept		\
		{ return STORENAME::fromIdent(identifier, value); }				_XENUM4_NWLN \
	/* Iteration support. */								\
_XENUM4_INDENT_SUB										\
public:												_XENUM4_NWLN \
	_XENUM4_DOC(Iterator type for this container; for iterating the enum values.)		\
	typedef ::_XENUM4_NS::XenumCntnrIterator<CREALNAME> iterator;				_XENUM4_NWLN \
	_XENUM4_DOC(Get iterator to beginning (before the first enum-value).)			\
	static iterator begin(void) noexcept { return iterator(0); }				_XENUM4_NWLN \
	_XENUM4_DOC(Get iterator to end (past the last enum-value).)				\
	static iterator end(void) noexcept { return iterator(_size); }				_XENUM4_NWLN


#endif // _XENUM4_IMPL_DECLARE_CNTNR_HPP
