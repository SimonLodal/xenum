/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * The public container class.
 */
#ifndef _XENUM5_IMPL_CNTNR_HPP
#define _XENUM5_IMPL_CNTNR_HPP


// ==============================================================================================
/**
 * @return Name of the container class.
 */
#define _XENUM5_CNTNR_NAME(XDCL)								\
	_XENUM5_XDCL_CNAME(XDCL)

//	BOOST_PP_CAT(_Xenum5Cntnr_, _XENUM5_XDCL_CNAME(XDCL))


// ======================================= MAIN: DECLC ==========================================
/**
 * Main entry function for declaring the container class.
 */
#define _XENUM5_DECLARE_CNTNR(CTXT, XDCL)							\
	_XENUM5_DOC(Container class for xenum _XENUM5_XDCL_CNAME(XDCL).				_XENUM5_NWLN \
		Contains all the enum values as value objects, lookup functions, and iteration.)\
	class _XENUM5_CNTNR_NAME(XDCL) {							_XENUM5_NWLN \
	public:											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_INDENT_SUB _XENUM5_CMNT(Main)						\
		_XENUM5_DECLC_VALUE_T(CTXT, XDCL)						\
		_XENUM5_DECLC_ENUM(CTXT, XDCL)							\
		_XENUM5_DECLC_ENUM_OBJS(CTXT)							\
		_XENUM5_DECLC_FUNCS(CTXT, XDCL)							\
		_XENUM5_IDENT_DECLC(XDCL, CTXT)							\
		_XENUM5_PROPS_DECLC(CTXT)							\
		_XENUM5_INDENT_SUB _XENUM5_CMNT(Iteration)					\
		_XENUM5_DECLC_ITERATION(XDCL)							\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN


// ==========================================================================
/**
 * Declare the value class type.
 * Not used here, but useful for XenumSet and others.
 */
#define _XENUM5_DECLC_VALUE_T(CTXT, XDCL)							\
	_XENUM5_DOC(The enum-value class.)							\
	using _value_t = _XENUM5_XDCL_VNAME(XDCL);						_XENUM5_NWLN


// ==========================================================================
/**
 * Copy native enum declaration from store class.
 */
#define _XENUM5_DECLC_ENUM(CTXT, XDCL)								\
	_XENUM5_DOC(Number of enum values in this enum class.)					\
	static constexpr const size_t _size = _XENUM5_STORE_NAME(XDCL)::size;			_XENUM5_NWLN \
	_XENUM5_DOC(Integer type used for enum values.)						\
	using _index_t = typename _XENUM5_STORE_NAME(XDCL)::Index;				_XENUM5_NWLN \
	_XENUM5_DOC(The native enum class.)							\
	using _enum = typename _XENUM5_STORE_NAME(XDCL)::Enum;					_XENUM5_NWLN \


// ==========================================================================
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
	static constexpr const _XENUM5_XDCL_VNAME(_XENUM5_CTXT_XDCL(CTXT))			\
		IDENT = _enum::IDENT;								_XENUM5_NWLN


// ==========================================================================
/**
 * Declare ctors and common functions.
 */
#define _XENUM5_DECLC_FUNCS(CTXT, XDCL)								\
	_XENUM5_DECLC_FUNCS_I1(									\
		CTXT,										\
		_XENUM5_STORE_NAME(XDCL),							\
		_XENUM5_CNTNR_NAME(XDCL),							\
		_XENUM5_XDCL_VNAME(XDCL)							\
	)

/**
 * Worker for _XENUM5_DECLC_FUNCS().
 */
#define _XENUM5_DECLC_FUNCS_I1(CTXT, SNAME, CNAME, VNAME)					\
	_XENUM5_DOC(Ctor. Do not use, except when iterating the enum-values.			_XENUM5_NWLN \
		All members of this class are static, so there is no				_XENUM5_NWLN \
		need to instantiate an object; just address the members				_XENUM5_NWLN \
		directly as CNAME::SomeValue.							_XENUM5_NWLN \
		However, range-based loops require an object, so use:				_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		@code										_XENUM5_NWLN \
		for (VNAME enumValue : CNAME()) { ... }						_XENUM5_NWLN \
		@endcode)									\
	constexpr CNAME (void) noexcept								_XENUM5_NWLN \
	{}											_XENUM5_NWLN \
	/* Wrapper for store class lookup functions. */						\
	_XENUM5_DOC(Get enum value with given index.						_XENUM5_NWLN \
		@param index Enum-value index to retrieve.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if index >= number of enum values.)			\
	static constexpr VNAME _fromIndex(_index_t index)					_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return SNAME::fromIndex(index);							_XENUM5_NWLN \
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given index, without throwing on error.			_XENUM5_NWLN \
		@param index Enum-value index to retrieve.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given index was found, else false.)		\
	static constexpr bool _fromIndex(_index_t index, VNAME& value) noexcept			_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return SNAME::fromIndex(index, value);						_XENUM5_NWLN \
	}											_XENUM5_NWLN \


// ==========================================================================
/**
 * Declare iterator class and functions.
 */
#define _XENUM5_DECLC_ITERATION(XDCL)								\
 	_XENUM5_DOC(Iterator type for this container; for iterating the enum values.)		\
	using iterator = ::_XENUM5_NS::XenumCntnrIterator<_XENUM5_CNTNR_NAME(XDCL)>;		_XENUM5_NWLN \
 	_XENUM5_DOC(Get iterator to beginning (before the first enum-value).)			\
 	static iterator begin(void) noexcept							_XENUM5_NWLN \
 	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return iterator(0);								_XENUM5_NWLN \
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Get iterator to end (past the last enum-value).)				\
	static iterator end(void) noexcept							_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return iterator(_size);								_XENUM5_NWLN \
	}											_XENUM5_NWLN \


// ======================================= MAIN: DEFC ===========================================
/**
 * Main entry function for defining the container class.
 */
#define _XENUM5_DEFINE_CNTNR(CTXT, XDCL)							\
	_XENUM5_NWLN _XENUM5_CMNT(Cntnr:Main)							\
	_XENUM5_DEFC_SIZE(CTXT, XDCL)								\
	_XENUM5_DEFC_ENUM_COPY(CTXT)								\


// ==========================================================================
/**
 * Define the $cntnr::size static var.
 */
// FIXME: Is it really necessary to define this at all?
#define _XENUM5_DEFC_SIZE(CTXT, XDCL)								\
	constexpr const size_t _XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_size;		_XENUM5_NWLN


// ==========================================================================
/**
 * Define the static enum-value copies.
 */
#define _XENUM5_DEFC_ENUM_COPY(CTXT)								\
	_XENUM5_CALL_VALS(_XENUM5_DEFC_ENUM_COPY_MEMBER, CTXT)

/**
 * Callback worker for _XENUM5_DEFC_ENUM_COPY().
 */
#define _XENUM5_DEFC_ENUM_COPY_MEMBER(CTXT, IDENT, ...)						\
	_XENUM5_DEFC_ENUM_COPY_MEMBER_PREFIX(CTXT, _XENUM5_CTXT_XDCL(CTXT))IDENT;		_XENUM5_NWLN

/**
 * Worker for _XENUM5_DEFC_ENUM_COPY_MEMBER().
 */
#define _XENUM5_DEFC_ENUM_COPY_MEMBER_PREFIX(CTXT, XDCL)					\
	constexpr const										\
	_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_XDCL_VNAME(XDCL)					\
	_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::


#endif // _XENUM5_IMPL_CNTNR_HPP
