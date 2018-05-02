/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Declaration of the public container class class.
 */
#ifndef _XENUM5_IMPL_DECLARE_CNTNR_HPP
#define _XENUM5_IMPL_DECLARE_CNTNR_HPP


// ==============================================================================================
/**
 * @return Name of the container class.
 */
#define _XENUM5_CNTNR_NAME(DECL)								\
	_XENUM5_DECL_GET_CNTNRNAME(DECL)

//	BOOST_PP_CAT(_Xenum5Cntnr_, _XENUM5_DECL_GET_CNTNRNAME(DECL))


// ==============================================================================================
/**
 * Main entry function.
 */
#define _XENUM5_DECLARE_CNTNR(CTXT, DECL)							\
	_XENUM5_DOC(Container class for xenum _XENUM5_DECL_GET_CNTNRNAME(DECL).			_XENUM5_NWLN \
		Contains all the enum values as value objects, lookup functions, and iteration.)\
	class _XENUM5_CNTNR_NAME(DECL) {							_XENUM5_NWLN \
	public:											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_INDENT_SUB _XENUM5_CMNT(Main)						\
		_XENUM5_DECLC_VALUE_T(CTXT, DECL)						\
		_XENUM5_DECLC_ENUM(CTXT, DECL)							\
		_XENUM5_DECLC_ENUM_OBJS(CTXT)							\
		_XENUM5_DECLC_FUNCS(CTXT, DECL)							\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN
//	typedef _XENUM5_CNTNR_NAME(DECL) _XENUM5_DECL_GET_CNTNRNAME(DECL);

// ==============================================================================================
/**
 * Declare the value class type.
 * Not used here, but useful for XenumSet and others.
 */
#define _XENUM5_DECLC_VALUE_T(CTXT, DECL)							\
	_XENUM5_DOC(The enum-value class.)							\
	typedef _XENUM5_DECL_GET_VALUENAME(DECL) _value_t;					_XENUM5_NWLN


// ==============================================================================================
/**
 * Copy native enum declaration from store class.
 */
#define _XENUM5_DECLC_ENUM(CTXT, DECL)								\
	_XENUM5_DOC(Number of enum values in this enum class.)					\
	static constexpr const size_t _size = _XENUM5_STORE_NAME(DECL)::size;			_XENUM5_NWLN \
	_XENUM5_DOC(Integer type used for enum values.)						\
	using _index_t = typename _XENUM5_STORE_NAME(DECL)::Index;				_XENUM5_NWLN \
	_XENUM5_DOC(The native enum class.)							\
	using _enum = typename _XENUM5_STORE_NAME(DECL)::Enum;					_XENUM5_NWLN \


// ==============================================================================================
/**
 * Declare the static enum-value objects.
 */
#define _XENUM5_DECLC_ENUM_OBJS(CTXT)								\
	_XENUM5_DOC(@name Enum values)								\
	_XENUM5_DOC(@{)										\
	_XENUM5_CALL_VALS(_XENUM5_DECLC_ENUM_OBJ, CTXT)						\
	_XENUM5_DOC(@})										\

/**
 * Callback worker for _XENUM5_DECLC_ENUM_OBJS().
 */
#define _XENUM5_DECLC_ENUM_OBJ(CTXT, IDENT, ...)						\
	static constexpr const _XENUM5_DECL_GET_VALUENAME(_XENUM5_CTXT_GET_DECL(CTXT))		\
		IDENT = _enum::IDENT;								_XENUM5_NWLN


// ==============================================================================================
/**
 * Declare ctors, comparison operators, other stuff.
 */
#define _XENUM5_DECLC_FUNCS(CTXT, DECL)								\
	_XENUM5_DECLC_FUNCS_I1(									\
		CTXT,										\
		_XENUM5_STORE_NAME(DECL),							\
		_XENUM5_CNTNR_NAME(DECL),							\
		_XENUM5_DECL_GET_VALUENAME(DECL)						\
	)

/**
 * Worker for _XENUM5_DECLC_FUNCS().
 */
#define _XENUM5_DECLC_FUNCS_I1(CTXT, STORENAME, CREALNAME, VALUENAME)				\
	_XENUM5_DOC(Ctor. Do not use, except when iterating the enum-values.			_XENUM5_NWLN \
		All members of this class are static, so there is no				_XENUM5_NWLN \
		need to instantiate an object; just address the members				_XENUM5_NWLN \
		directly as CREALNAME::SomeValue.						_XENUM5_NWLN \
		However, range-based loops require an object, so use:				_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		@code										_XENUM5_NWLN \
		for (VALUENAME enumValue : CREALNAME()) { ... }					_XENUM5_NWLN \
		@endcode)									\
	constexpr CREALNAME (void) noexcept {}							_XENUM5_NWLN \
	/* Wrapper for store class lookup functions. */						\
	_XENUM5_DOC(Get enum value with given index.						_XENUM5_NWLN \
		@param index Enum-value index to retrieve.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if index >= number of enum values.)			\
	static VALUENAME _fromIndex(_index_t index)						\
		{ return STORENAME::fromIndex(index); }						_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given index, without throwing on error.			_XENUM5_NWLN \
		@param index Enum-value index to retrieve.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given index was found, else false.)		\
	static bool _fromIndex(_index_t index, VALUENAME& value) noexcept			\
		{ return STORENAME::fromIndex(index, value); }					_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name).				_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if no such identifier exists.)			\
	static VALUENAME _fromIdentifier(const char* identifier)				\
		{ return STORENAME::fromIdentifier(identifier); }				_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name), without throwing on error.	_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given identifier was found, else false.)	\
	static bool _fromIdentifier(const char* identifier, VALUENAME& value) noexcept		\
		{ return STORENAME::fromIdentifier(identifier, value); }			_XENUM5_NWLN \
	/* Iteration support. */								\
	_XENUM5_DOC(Iterator type for this container; for iterating the enum values.)		\
	typedef ::_XENUM5_NS::XenumCntnrIterator<CREALNAME> iterator;				_XENUM5_NWLN \
	_XENUM5_DOC(Get iterator to beginning (before the first enum-value).)			\
	static iterator begin(void) noexcept { return iterator(0); }				_XENUM5_NWLN \
	_XENUM5_DOC(Get iterator to end (past the last enum-value).)				\
	static iterator end(void) noexcept { return iterator(_size); }				_XENUM5_NWLN


#endif // _XENUM5_IMPL_DECLARE_CNTNR_HPP
