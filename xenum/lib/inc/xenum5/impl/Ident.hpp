/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of enum-value identifier strings.
 */
#ifndef _XENUM5_IMPL_IDENT_HPP
#define _XENUM5_IMPL_IDENT_HPP


// ======================================= MAIN: STORE ==========================================
 /**
 * Entry point for all identifier related declarations in store class (header).
 */
#define _XENUM5_IDENT_DECLS(XDCL, CTXT)								\
	_XENUM5_INDENT_SUB _XENUM5_CMNT(Ident)							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Ident:data: _XENUM5_XDCL_IDENT_DATA(XDCL))			\
	BOOST_PP_CAT(_XENUM5_IDENT_DATA_DECLS_, _XENUM5_XDCL_IDENT_DATA(XDCL)) (XDCL, CTXT)	\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Ident:get: _XENUM5_XDCL_IDENT_GET(XDCL))			\
	BOOST_PP_CAT(_XENUM5_IDENT_GET_DECLS_, _XENUM5_XDCL_IDENT_GET(XDCL)) ()			\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Ident:from: _XENUM5_XDCL_IDENT_FROM(XDCL))			\
	BOOST_PP_CAT(_XENUM5_IDENT_FROM_DECLS_, _XENUM5_XDCL_IDENT_FROM(XDCL)) (XDCL, CTXT)	\


// =========================== DECLS ident data ==============================
/**
 * No data to declare since nobody uses it.
 */
#define _XENUM5_IDENT_DATA_DECLS_OFF(XDCL, CTXT)						\

/**
 * No data to declare since it is all defined in source file.
 */
#define _XENUM5_IDENT_DATA_DECLS_SRC(XDCL, CTXT)						\

/**
 * Define data inline since some inline methods use it.
 */
#define _XENUM5_IDENT_DATA_DECLS_HDR(XDCL, CTXT)						\
	_XENUM5_IDENT_DEFINE_VALUES(static, CTXT)						\
	_XENUM5_IDENT_DECLARE_VALUENAMES(CTXT)							\
	_XENUM5_IDENT_DEFINE_OFFSETS(static, CTXT)						\
	_XENUM5_IDENT_DEFINE_GET_OFFSET(static)							\


// ============================ DECLS ident get() ============================
/**
 * Omit getIdentifier(), turned off.
 */
#define _XENUM5_IDENT_GET_DECLS_off()								\

/**
 * Declare getIdentifier(), defined in source file.
 */
#define _XENUM5_IDENT_GET_DECLS_ext()								\
	_XENUM5_DOC(@return Identifier (name) of an enum value.)				\
	static const char* getIdentifier(Enum value) noexcept;					_XENUM5_NWLN \

/**
 * Define getIdentifier() as inline constexpr.
 */
#define _XENUM5_IDENT_GET_DECLS_cxp()								\
	_XENUM5_IDENT_DEFINE_GET_IDENT(static constexpr, , )					\


// =========================== DECLS ident from() ============================
/**
 * Omit fromIdentifier(), turned off.
 */
#define _XENUM5_IDENT_FROM_DECLS_off(XDCL, CTXT)						\

/**
 * Declare fromIdentifier(), defined in source file.
 */
#define _XENUM5_IDENT_FROM_DECLS_ext(XDCL, CTXT)						\
	_XENUM5_DOC(Get enum value with given identifier (name).				_XENUM5_NWLN \
		Warning: Terrible performance, because linear search.				_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if no such identifier exists.)			\
	static Enum fromIdentifier(const char* identifier);					_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name), without throwing on error.	_XENUM5_NWLN \
		Warning: Terrible performance, because linear search.				_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given identifier was found, else false.)	\
	static bool fromIdentifier(const char* identifier, Value& value) noexcept;		_XENUM5_NWLN \

/**
 * Define fromIdentifier() as inline, non-constexpr.
 */
#define _XENUM5_IDENT_FROM_DECLS_inl(XDCL, CTXT)						\
	_XENUM5_IDENT_DEFINE_FROM_IDENT_STD(							\
		static,										\
		,										\
												\
	)											\

/**
 * Define fromIdentifier() as inline constexpr.
 */
#define _XENUM5_IDENT_FROM_DECLS_cxp(XDCL, CTXT)						\
	_XENUM5_IDENT_DEFINE_FROM_IDENT_CXP()							\


// ======================================= MAIN: CNTNR ==========================================
 /**
 * Entry point for all identifier related declarations in container class (header).
 */
#define _XENUM5_IDENT_DECLC(XDCL, CTXT)								\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Ident:from: _XENUM5_XDCL_IDENT_FROM(XDCL))			\
	BOOST_PP_CAT(_XENUM5_IDENT_FROM_DECLC_, _XENUM5_XDCL_IDENT_FROM(XDCL)) (XDCL, CTXT)	\


// =========================== DECLC ident from() ============================
#ifdef _XENUM5_UNIT_TEST
/**
 * Omit _fromIdentifier(), turned off (but replace with a throwing variant just so unit test
 * can detect that it is "not present").
 */
#define _XENUM5_IDENT_FROM_DECLC_off(XDCL, CTXT)						\
	static _XENUM5_XDCL_VNAME(XDCL) _fromIdentifier(const char* identifier)			_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		throw std::logic_error("fromIdentifier() is configured 'off'.");		_XENUM5_NWLN \
	}											_XENUM5_NWLN \
	static bool _fromIdentifier(const char* identifier, _XENUM5_XDCL_VNAME(XDCL)& value)	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		throw std::logic_error("fromIdentifier() is configured 'off'.");		_XENUM5_NWLN \
	}											_XENUM5_NWLN \

#else
/**
 * Omit _fromIdentifier(), turned off.
 */
#define _XENUM5_IDENT_FROM_DECLC_off(XDCL, CTXT)	
#endif

/**
 * Define _fromIdentifier() as inline, non-constexpr.
 */
#define _XENUM5_IDENT_FROM_DECLC_ext(XDCL, CTXT)						\
	_XENUM5_IDENT_FROM_DECLC_I1(								\
		static,										\
		_XENUM5_STORE_NAME(XDCL),							\
		_XENUM5_XDCL_VNAME(XDCL)							\
	)											\

/**
 * Define _fromIdentifier() as inline, non-constexpr.
 */
#define _XENUM5_IDENT_FROM_DECLC_inl(XDCL, CTXT)						\
	_XENUM5_IDENT_FROM_DECLC_I1(								\
		static,										\
		_XENUM5_STORE_NAME(XDCL),							\
		_XENUM5_XDCL_VNAME(XDCL)							\
	)											\

/**
 * Define _fromIdentifier() as inline constexpr.
 */
#define _XENUM5_IDENT_FROM_DECLC_cxp(XDCL, CTXT)						\
	_XENUM5_IDENT_FROM_DECLC_I1(								\
		static constexpr,								\
		_XENUM5_STORE_NAME(XDCL),							\
		_XENUM5_XDCL_VNAME(XDCL)							\
	)											\


/**
 * Common fromIdentifier() generator for container class.
 */
#define _XENUM5_IDENT_FROM_DECLC_I1(DECLPFX, SNAME, VNAME)					\
	_XENUM5_DOC(Get enum value with given identifier (name).				_XENUM5_NWLN \
		Warning: Terrible performance, because linear search.				_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if no such identifier exists.)			\
	DECLPFX VNAME _fromIdentifier(const char* identifier)					_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return SNAME::fromIdentifier(identifier);					_XENUM5_NWLN \
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name), without throwing on error.	_XENUM5_NWLN \
		Warning: Terrible performance, because linear search.				_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given identifier was found, else false.)	\
	DECLPFX bool _fromIdentifier(const char* identifier, VNAME& value) noexcept		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return SNAME::fromIdentifier(identifier, value);				_XENUM5_NWLN \
	}											_XENUM5_NWLN \



// ====================================== MAIN: DEFINE ==========================================
/**
 * Entry point for all identifier related definitions (in source file).
 */
#define _XENUM5_IDENT_DEFINE(XDCL, CTXT)							\
	_XENUM5_NWLN _XENUM5_CMNT(Store:Ident)							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:Ident:data: _XENUM5_XDCL_IDENT_DATA(XDCL))		\
	BOOST_PP_CAT(_XENUM5_IDENT_DATA_DEFINE_, _XENUM5_XDCL_IDENT_DATA(XDCL)) (XDCL, CTXT)	\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:Ident:get: _XENUM5_XDCL_IDENT_GET(XDCL))			\
	BOOST_PP_CAT(_XENUM5_IDENT_GET_DEFINE_, _XENUM5_XDCL_IDENT_GET(XDCL)) (XDCL)		\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:Ident:from: _XENUM5_XDCL_IDENT_FROM(XDCL))		\
	BOOST_PP_CAT(_XENUM5_IDENT_FROM_DEFINE_, _XENUM5_XDCL_IDENT_FROM(XDCL)) (XDCL, CTXT)	\


/**
 * Entry point for defining final checks for identifier data.
 */
#define _XENUM5_IDENT_CHECK(XDCL)								\
	_XENUM5_CMNT(Ident)									\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:Ident:check: _XENUM5_XDCL_IDENT_DATA(XDCL))		\
	BOOST_PP_CAT(_XENUM5_IDENT_CHECK_, _XENUM5_XDCL_IDENT_DATA(XDCL)) (XDCL)		\


/**
 * Entry point for debug dumping of identifier data.
 */
#define _XENUM5_IDENT_DBGINFO(XDCL)								\
	_XENUM5_CMNT(Ident)									\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:Ident:dbginfo: _XENUM5_XDCL_IDENT_DATA(XDCL))		\
	BOOST_PP_CAT(_XENUM5_IDENT_DBGINFO_, _XENUM5_XDCL_IDENT_DATA(XDCL)) (XDCL)		\


// =========================== DEFS ident data ===============================
/**
 * No data to define since nobody uses it.
 */
#define _XENUM5_IDENT_DATA_DEFINE_OFF(XDCL, CTXT)						\

/**
 * Define all the data.
 */
#define _XENUM5_IDENT_DATA_DEFINE_SRC(XDCL, CTXT)						\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace _XENUM5_IMPL_LOCAL_NS(XDCL,) {					_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			_XENUM5_IDENT_DEFINE_VALUES(, CTXT)					\
			_XENUM5_IDENT_DECLARE_VALUENAMES(CTXT)					\
			_XENUM5_IDENT_DEFINE_OFFSETS(, CTXT)					\
			_XENUM5_DOC(Alias the native enum into this scope.)			\
			using Enum = _XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_enum;	_XENUM5_NWLN \
			_XENUM5_DOC(Alias the Index type into this scope.)			\
			using Index = _XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_index_t;	_XENUM5_NWLN \
			_XENUM5_IDENT_DEFINE_GET_OFFSET()					\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace _XENUM5_IMPL_LOCAL_NS(XDCL,))				\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\

/**
 * Define the data, without content since that is in the header.
 */
#define _XENUM5_IDENT_DATA_DEFINE_HDR(XDCL, CTXT)						\
	_XENUM5_IDENT_DATA_DEFINE_HDR_I1(_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_STORE_NAME(XDCL))	\

/// Worker for _XENUM5_IDENT_DATA_DEFINE_HDR().
#define _XENUM5_IDENT_DATA_DEFINE_HDR_I1(SCOPE_SNAME)						\
	constexpr const SCOPE_SNAME::IdentValue SCOPE_SNAME::identValues[];			_XENUM5_NWLN \
	constexpr const SCOPE_SNAME::IdentIndex SCOPE_SNAME::identOffsets[];			_XENUM5_NWLN \


// =========================== DEFS ident get() ==============================
/**
 * Omit getIdentifier(), turned off.
 */
#define _XENUM5_IDENT_GET_DEFINE_off(XDCL)							\


/**
 * Define getIdentifier(), declared in header file.
 */
#define _XENUM5_IDENT_GET_DEFINE_ext(XDCL)							\
	_XENUM5_IDENT_DEFINE_GET_IDENT(								\
		,										\
		_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_STORE_NAME(XDCL)::,				\
		_XENUM5_IDENT_DATA_SCOPE(XDCL)							\
	)											\

/**
 * Omit getIdentifier(), defined inline constexpr in header.
 */
#define _XENUM5_IDENT_GET_DEFINE_cxp(XDCL)							\


/**
 * Helper to get the correct data scope.
 */
#define _XENUM5_IDENT_DATA_SCOPE(XDCL)								\
	BOOST_PP_CAT(_XENUM5_IDENT_DATA_SCOPE_, _XENUM5_XDCL_IDENT_DATA(XDCL)) (XDCL)		\

/**
 * This should not happen. No data, no data scope.
 */
#define _XENUM5_IDENT_DATA_SCOPE_OFF(XDCL)							\
	Data is nowhere!

/**
 * Data is in the source-local ns.
 */
#define _XENUM5_IDENT_DATA_SCOPE_SRC(XDCL)							\
	_XENUM5_IMPL_LOCAL_NS(XDCL, )::

/**
 * Data is inlined in the class. And since this is used inside methods that are already class
 * members, there is no need to prepend a scope.
 */
#define _XENUM5_IDENT_DATA_SCOPE_HDR(XDCL)							\


// ========================== DEFS ident from() ==============================
/**
 * Omit fromIdentifier(), turned off.
 */
#define _XENUM5_IDENT_FROM_DEFINE_off(XDCL, CTXT)						\

/**
 * Define fromIdentifier(), declared in header file.
 */
#define _XENUM5_IDENT_FROM_DEFINE_ext(XDCL, CTXT)						\
	_XENUM5_IDENT_DEFINE_FROM_IDENT_STD(							\
		,										\
		_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_STORE_NAME(XDCL)::,				\
		_XENUM5_IDENT_DATA_SCOPE(XDCL)							\
	)											\

/**
 * Omit fromIdentifier(), defined inline in header.
 */
#define _XENUM5_IDENT_FROM_DEFINE_inl(XDCL, CTXT)							\

/**
 * Omit fromIdentifier(), defined inline constexpr in header.
 */
#define _XENUM5_IDENT_FROM_DEFINE_cxp(XDCL, CTXT)						\


// ============================ DEFS _check() ================================
/**
 * Final checks on ident data structures: None since they do not exist.
 */
#define _XENUM5_IDENT_CHECK_OFF(XDCL)								\

/**
 * Define final checks on ident data structures, defined in source.
 */
#define _XENUM5_IDENT_CHECK_SRC(XDCL)								\
	_XENUM5_IDENT_CHECK_I1(									\
		_XENUM5_IMPL_LOCAL_NS(XDCL, )::,						\
		_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_STORE_NAME(XDCL)::				\
	)											\

/**
 * Define final checks on ident data structures, defined in header.
 */
#define _XENUM5_IDENT_CHECK_HDR(XDCL)								\
	_XENUM5_IDENT_CHECK_I1(,)								\


/**
 * Common worker to define the ident data structures checks.
 */
#define _XENUM5_IDENT_CHECK_I1(LSCOPE, SSCOPE)							\
	static_assert(										\
		/* +1: Compiler adds an extra null terminator in Values array */		\
		sizeof(LSCOPE identValues) == sizeof(LSCOPE IdentValueNames) + 1,		\
		"BUG: Struct/array size mismatch (IdentValueNames / identValues)."		\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LSCOPE identOffsets) == SSCOPE size * sizeof(LSCOPE IdentIndex),		\
		"BUG: Struct size mismatch (identOffsets / ::size)."				\
	);											_XENUM5_NWLN \


// =========================== DEFS _dbginfo() ===============================
/**
 * Debug info: None since there is no data.
 */
#define _XENUM5_IDENT_DBGINFO_OFF(XDCL)								\

/**
 * Debug info for ident data structures, defined in source.
 */
#define _XENUM5_IDENT_DBGINFO_SRC(XDCL)								\
	_XENUM5_IDENT_DBGINFO_I1(								\
		_XENUM5_IMPL_LOCAL_NS(XDCL, )::,						\
		XDCL										\
	)											\

/**
 * Debug info for ident data structures, defined in source.
 */
#define _XENUM5_IDENT_DBGINFO_HDR(XDCL)								\
	_XENUM5_IDENT_DBGINFO_I1(, XDCL)							\


/**
 * Common worker to define debug info for ident data structures.
 */
#define _XENUM5_IDENT_DBGINFO_I1(DATA_SCOPE, XDCL)						\
	std::cout										\
		<<"\tident:"<<std::endl								\
		<<"\t\tsizeof(identValues) = "<<sizeof(DATA_SCOPE identValues)<<std::endl	\
		<<"\t\tsizeof(IdentValueNames) = "<<sizeof(DATA_SCOPE IdentValueNames )<<std::endl	\
		;										\


// ====================================== COMMON PARTS ==========================================

// ================================ Values ===================================
/**
 * Define the identValues array.
 */
#define _XENUM5_IDENT_DEFINE_VALUES(DECLPFX, CTXT)						\
	_XENUM5_DOC(Native type for identifier strings.)					\
	using IdentValue = char;								_XENUM5_NWLN \
	_XENUM5_DOC(Array of all identifier strings.)						\
	DECLPFX constexpr const IdentValue identValues[] =					\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DEFINE_VALUE, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Loop worker for _XENUM5_IDENT_DEFINE_VALUES().
 * Define a single identifier value.
 */
#define _XENUM5_IDENT_DEFINE_VALUE(CTXT, IDENT, ...)						\
	#IDENT "\0"										_XENUM5_NWLN


// ============================== ValueNames =================================
/**
 * Define the IdentValueNames struct.
 */
#define _XENUM5_IDENT_DECLARE_VALUENAMES(CTXT)							\
	_XENUM5_DOC(Layout of identValues array.)						\
	using IdentValueNames = struct {							_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DECLARE_VALUENAME, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Declare a single field of the ValueNames struct.
 */
#define _XENUM5_IDENT_DECLARE_VALUENAME(CTXT, IDENT, ...)					\
	IdentValue IDENT[sizeof(#IDENT)];							_XENUM5_NWLN


// =============================== Offsets ===================================
/**
 * Define the identOffsets array.
 */
#define _XENUM5_IDENT_DEFINE_OFFSETS(DECLPFX, CTXT)						\
	_XENUM5_DOC(Integer type big enough to hold offsets into the string pool.)		\
	using IdentIndex = ::_XENUM5_NS::SelectInt<sizeof(identValues)>::type;			_XENUM5_NWLN \
	_XENUM5_DOC(Table of offsets into the identifier stringpool.)				\
	DECLPFX constexpr const IdentIndex identOffsets[] = {					_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DEFINE_OFFSET, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Define the offset of a single identifier string.
 */
#define _XENUM5_IDENT_DEFINE_OFFSET(CTXT, IDENT, ...)						\
	offsetof(IdentValueNames, IDENT),							_XENUM5_NWLN


// ============================= getOffset() =================================
/**
 * Define offset getter function.
 */
#define _XENUM5_IDENT_DEFINE_GET_OFFSET(DECLPFX)						\
	_XENUM5_DOC(Get offset in string table for a given enum value.)				\
	DECLPFX constexpr const IdentIndex getIdentOffset(Enum value) noexcept			_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return identOffsets[static_cast<Index>(value)];					_XENUM5_NWLN \
	}											_XENUM5_NWLN \


// =========================== getIdentifier() ===============================
/**
 * Define getIdentifier(), either inline in header, or as definition in source file.
 */
#define _XENUM5_IDENT_DEFINE_GET_IDENT(DECLPFX, STORE_SCOPE, DATA_SCOPE)			\
	_XENUM5_DOC(@return Identifier (name) of an enum value.)				\
	DECLPFX const char* STORE_SCOPE getIdentifier(STORE_SCOPE Enum value) noexcept		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return &DATA_SCOPE identValues[DATA_SCOPE getIdentOffset(value)];		_XENUM5_NWLN \
	}											_XENUM5_NWLN \


// =========================== fromIdentifier() ==============================
/**
 * Define fromIdentifier() methods, non-constexpr. Both for inline and source definition.
 */
#define _XENUM5_IDENT_DEFINE_FROM_IDENT_STD(DECLPFX, STORE_SCOPE, DATA_SCOPE)			\
	_XENUM5_DOC(Get enum value with given identifier (name).				_XENUM5_NWLN \
		Warning: Terrible performance, because linear search.				_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if no such identifier exists.)			\
	DECLPFX STORE_SCOPE Enum STORE_SCOPE fromIdentifier(const char* identifier)		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		for (Index index=0; index<size; index++) {					_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			if (strcmp(&DATA_SCOPE identValues[DATA_SCOPE getIdentOffset(static_cast<Enum>(index))],	\
				   identifier) == 0)						_XENUM5_NWLN \
				_XENUM5_INDENT_ADD						\
				return static_cast<Enum>(index);				_XENUM5_NWLN \
			_XENUM5_INDENT_DEC							\
		}										_XENUM5_NWLN \
		throw std::out_of_range("No such identifier.");					_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name), without throwing on error.	_XENUM5_NWLN \
		Warning: Terrible performance, because linear search.				_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given identifier was found, else false.)	\
	DECLPFX bool STORE_SCOPE fromIdentifier(const char* identifier, Value& value) noexcept	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		for (Index index=0; index<size; index++) {					_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			if (strcmp(&DATA_SCOPE identValues[DATA_SCOPE getIdentOffset(static_cast<Enum>(index))],	\
				   identifier) != 0)						_XENUM5_NWLN \
				_XENUM5_INDENT_ADD						\
				continue;							_XENUM5_NWLN \
			value = static_cast<Enum>(index);					_XENUM5_NWLN \
			return true;								_XENUM5_NWLN \
			_XENUM5_INDENT_DEC							\
		}										_XENUM5_NWLN \
		return false;									_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


/**
 * Define fromIdentifier() methods, constexpr.
 */
#define _XENUM5_IDENT_DEFINE_FROM_IDENT_CXP()							\
	_XENUM5_DOC(Recursive worker for throwing fromIdentifier().)				\
	static constexpr Enum fromIdentifierT(const char* identifier, Index index)		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return (index < size)								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			?(::_XENUM5_NS::cxpStrEqual(identifier,					\
					&identValues[getIdentOffset(static_cast<Enum>(index))])	_XENUM5_NWLN \
				_XENUM5_INDENT_INC						\
				? static_cast<Enum>(index)					_XENUM5_NWLN \
				: fromIdentifierT(identifier, index+1)				_XENUM5_NWLN \
				_XENUM5_INDENT_DEC						\
			)									_XENUM5_NWLN \
			: throw std::out_of_range("No such identifier.");			_XENUM5_NWLN \
			_XENUM5_INDENT_DEC							\
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name).				_XENUM5_NWLN \
		Warning: Terrible performance, because linear search, and because		_XENUM5_NWLN \
		constexpr requirements result in very suboptimal runtime code.			_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if no such identifier exists.)			\
	static constexpr Enum fromIdentifier(const char* identifier)				_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
 		return fromIdentifierT(identifier, 0);						_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
 	_XENUM5_DOC(Recursive worker for non-throwing fromIdentifier().)			\
	static constexpr bool fromIdentifierN(const char* identifier, Value& value, Index index)	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return (index < size)								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			?(::_XENUM5_NS::cxpStrEqual(identifier,					\
					&identValues[getIdentOffset(static_cast<Enum>(index))])	_XENUM5_NWLN \
				_XENUM5_INDENT_INC						\
 				? (value = static_cast<Enum>(index)), true			_XENUM5_NWLN \
 				: fromIdentifierN(identifier, value, index+1)			_XENUM5_NWLN \
				_XENUM5_INDENT_DEC						\
			)									_XENUM5_NWLN \
			: false;								_XENUM5_NWLN \
			_XENUM5_INDENT_DEC							\
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name), without throwing on error.	_XENUM5_NWLN \
		Warning: Terrible performance, because linear search, and because		_XENUM5_NWLN \
		constexpr requirements result in very suboptimal runtime code.			_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given identifier was found, else false.)	\
	static constexpr bool fromIdentifier(const char* identifier, Value& value) noexcept	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
 		return fromIdentifierN(identifier, value, 0);					_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


#endif // _XENUM5_IMPL_IDENT_HPP
