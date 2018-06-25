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
_XENUM5_INDENT_SUB _XENUM5_CMNT(Ident:common: _XENUM5_XDCL_PLACE_COMMON(XDCL))			\
	BOOST_PP_CAT(_XENUM5_IDENT_COMMON_DECLS_, _XENUM5_XDCL_PLACE_COMMON(XDCL)) (XDCL, CTXT)	\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Ident:get: _XENUM5_XDCL_IMPL_GET(XDCL))				\
	BOOST_PP_CAT(_XENUM5_IDENT_GETVALUE_DECLS_, _XENUM5_XDCL_IMPL_GET(XDCL)) ()		\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Ident:from: _XENUM5_XDCL_IMPL_FROM(XDCL))			\
	BOOST_PP_CAT(_XENUM5_IDENT_FROMVALUE_DECLS_, _XENUM5_XDCL_IMPL_FROM(XDCL)) (XDCL, CTXT)	\


// ============================= DECLS common ================================
/**
 * No common stuff to declare since nobody uses it.
 */
#define _XENUM5_IDENT_COMMON_DECLS_OFF(XDCL, CTXT)						\

/**
 * No common stuff to declare since it is all defined in source file.
 */
#define _XENUM5_IDENT_COMMON_DECLS_SRC(XDCL, CTXT)						\

/**
 * Define common data inline since some inline methods use it.
 */
#define _XENUM5_IDENT_COMMON_DECLS_HDR(XDCL, CTXT)						\
	_XENUM5_IDENT_VALUES_DEF(static, CTXT)							\
	_XENUM5_IDENT_VALUENAMES_DECL(CTXT)							\
	_XENUM5_IDENT_OFFSETS_DEF(static, CTXT)							\
	_XENUM5_IDENT_GETOFFSET_DEF(static)							\


// ============================ DECLS ident get() ============================
/**
 * Omit getIdentifier(), turned off.
 */
#define _XENUM5_IDENT_GETVALUE_DECLS_off()							\

/**
 * Declare getIdentifier(), defined in source file.
 */
#define _XENUM5_IDENT_GETVALUE_DECLS_ext()							\
	_XENUM5_DOC(@return Identifier (name) of an enum value.)				\
	static const char* getIdentifier(Enum value) noexcept;					_XENUM5_NWLN \

/**
 * Define getIdentifier() as inline constexpr.
 */
#define _XENUM5_IDENT_GETVALUE_DECLS_cxp()							\
	_XENUM5_IDENT_GETIDENT_DEF(static constexpr, , )					\


// ========================== DECLS ident from() =============================
/**
 * Omit fromIdentifier(), turned off.
 */
#define _XENUM5_IDENT_FROMVALUE_DECLS_off(XDCL, CTXT)						\

/**
 * Declare fromIdentifier(), defined in source file.
 */
#define _XENUM5_IDENT_FROMVALUE_DECLS_ext(XDCL, CTXT)						\
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
#define _XENUM5_IDENT_FROMVALUE_DECLS_inl(XDCL, CTXT)						\
	_XENUM5_IDENT_FROMVALUE_STD_DEF(							\
		static,										\
		,										\
												\
	)											\

/**
 * Define cxpFromIdentifier() as inline constexpr (also include plain inline variant).
 */
#define _XENUM5_IDENT_FROMVALUE_DECLS_cxp(XDCL, CTXT)						\
	_XENUM5_IDENT_FROMVALUE_DECLS_inl(XDCL, CTXT)						\
	_XENUM5_IDENT_FROMVALUE_CXP_DEF()							\


// ======================================= MAIN: CNTNR ==========================================
/**
 * Entry point for all identifier related declarations in container class (header).
 */
#define _XENUM5_IDENT_DECLC(XDCL, CTXT)								\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Ident:from: _XENUM5_XDCL_IMPL_FROM(XDCL))			\
	BOOST_PP_CAT(_XENUM5_IDENT_FROMVALUE_DECLC_, _XENUM5_XDCL_IMPL_FROM(XDCL)) (XDCL, CTXT)	\


// ========================== DECLC ident from() =============================
#ifdef _XENUM5_UNIT_TEST
/**
 * Omit _fromIdentifier(), turned off, but replace with a throwing variant just so unit test
 * can detect that it is "not present".
 */
#define _XENUM5_IDENT_FROMVALUE_DECLC_off(XDCL, CTXT)						\
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
#define _XENUM5_IDENT_FROMVALUE_DECLC_off(XDCL, CTXT)	
#endif

/**
 * Declare _fromIdentifier(), defined in source file.
 */
#define _XENUM5_IDENT_FROMVALUE_DECLC_ext(XDCL, CTXT)						\
	_XENUM5_IDENT_FROMVALUE_STD_DECLC_I1(_XENUM5_STORE_NAME(XDCL), _XENUM5_XDCL_VNAME(XDCL))\

/**
 * Define _fromIdentifier() as inline, non-constexpr.
 */
#define _XENUM5_IDENT_FROMVALUE_DECLC_inl(XDCL, CTXT)						\
	_XENUM5_IDENT_FROMVALUE_STD_DECLC_I1(_XENUM5_STORE_NAME(XDCL), _XENUM5_XDCL_VNAME(XDCL))\

/**
 * Define _fromIdentifier() as inline constexpr.
 */
#define _XENUM5_IDENT_FROMVALUE_DECLC_cxp(XDCL, CTXT)						\
	_XENUM5_IDENT_FROMVALUE_STD_DECLC_I1(_XENUM5_STORE_NAME(XDCL), _XENUM5_XDCL_VNAME(XDCL))\
	_XENUM5_IDENT_FROMVALUE_CXP_DECLC_I1(_XENUM5_STORE_NAME(XDCL), _XENUM5_XDCL_VNAME(XDCL))\


/**
 * Common fromIdentifier() generator for container class.
 */
#define _XENUM5_IDENT_FROMVALUE_STD_DECLC_I1(SNAME, VNAME)					\
	_XENUM5_DOC(Get enum value with given identifier (name).				_XENUM5_NWLN \
		Warning: Terrible performance, because linear search.				_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if no such identifier exists.)			\
	static VNAME _fromIdentifier(const char* identifier)					_XENUM5_NWLN \
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
	static bool _fromIdentifier(const char* identifier, VNAME& value) noexcept		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return SNAME::fromIdentifier(identifier, value);				_XENUM5_NWLN \
	}											_XENUM5_NWLN \


/**
 * Constexpr cxpFromIdentifier() generator for container class.
 */
#define _XENUM5_IDENT_FROMVALUE_CXP_DECLC_I1(SNAME, VNAME)					\
	_XENUM5_DOC(Get enum value with given identifier (name).				_XENUM5_NWLN \
		Warning: Terrible performance, because linear search, and because		_XENUM5_NWLN \
		constexpr requirements result in very suboptimal runtime code.			_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if no such identifier exists.)			\
	static constexpr VNAME _cxpFromIdentifier(const char* identifier)			_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return SNAME::cxpFromIdentifier(identifier);					_XENUM5_NWLN \
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name), without throwing on error.	_XENUM5_NWLN \
		Warning: Terrible performance, because linear search, and because		_XENUM5_NWLN \
		constexpr requirements result in very suboptimal runtime code.			_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given identifier was found, else false.)	\
	static constexpr bool _cxpFromIdentifier(const char* identifier, VNAME& value) noexcept	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return SNAME::cxpFromIdentifier(identifier, value);				_XENUM5_NWLN \
	}											_XENUM5_NWLN \



// ====================================== MAIN: DEFINE ==========================================
/**
 * Entry point for all identifier related definitions (in source file).
 */
#define _XENUM5_IDENT_DEFINE(XDCL, CTXT)							\
	_XENUM5_IDENT_DEFL(XDCL, CTXT)								\
	_XENUM5_IDENT_DEFS(XDCL, CTXT)								\

/**
 * Entry point for defining final checks for identifier data.
 */
#define _XENUM5_IDENT_CHECK(XDCL)								\
	_XENUM5_CMNT(Ident)									\
	using namespace _XENUM5_IMPL_LOCAL_NS(XDCL, );						_XENUM5_NWLN \
	BOOST_PP_CAT(										\
		_XENUM5_IDENT_COMMON_CHECK_,							\
		BOOST_PP_EQUAL(_XENUM5_XDCL_PLACE_INT_COMMON(XDCL), 0)				\
	) (XDCL)										\
/* Nothing to do, all data is in common.							\
	BOOST_PP_CAT(										\
		_XENUM5_IDENT_GETTERS_CHECK_,							\
		BOOST_PP_EQUAL(_XENUM5_XDCL_PLACE_INT_GET(XDCL), 0)				\
	) (XDCL)										\
	BOOST_PP_CAT(										\
		_XENUM5_IDENT_FROMVALUE_CHECK_,							\
		BOOST_PP_EQUAL(_XENUM5_XDCL_PLACE_INT_FROM(XDCL), 0)				\
	) (XDCL)										\
*/

/**
 * Entry point for debug dumping of identifier data.
 */
#define _XENUM5_IDENT_DBGINFO(XDCL)								\
	_XENUM5_CMNT(Ident)									\
	using namespace _XENUM5_IMPL_LOCAL_NS(XDCL, );						_XENUM5_NWLN \
	BOOST_PP_CAT(										\
		_XENUM5_IDENT_COMMON_DBGINFO_,							\
		BOOST_PP_EQUAL(_XENUM5_XDCL_PLACE_INT_COMMON(XDCL), 0)				\
	) (XDCL)										\
/* Nothing to do, all data is in common.							\
	BOOST_PP_CAT(										\
		_XENUM5_IDENT_GETTERS_DBGINFO_,							\
		BOOST_PP_EQUAL(_XENUM5_XDCL_PLACE_INT_GET(XDCL), 0)				\
	) (XDCL)										\
	BOOST_PP_CAT(										\
		_XENUM5_IDENT_FROMVALUE_DBGINFO_,						\
		BOOST_PP_EQUAL(_XENUM5_XDCL_PLACE_INT_FROM(XDCL), 0)				\
	) (XDCL)										\
*/


// ========================== Define in local ns =============================
/**
 * Entry function for definitions made in local ns.
 */
#define _XENUM5_IDENT_DEFL(XDCL, CTXT)								\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace _XENUM5_IMPL_LOCAL_NS(XDCL,) {					_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Local:Ident:common: _XENUM5_XDCL_PLACE_COMMON(XDCL))		\
			BOOST_PP_CAT(_XENUM5_IDENT_COMMON_DEFL_, _XENUM5_XDCL_PLACE_COMMON(XDCL))	\
				(XDCL, CTXT)							\
/* Nothing to do, everything needed is in common.						\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Local:Ident:get: _XENUM5_XDCL_PLACE_GET(XDCL))			\
			BOOST_PP_CAT(_XENUM5_IDENT_GETTERS_DEFL_, _XENUM5_XDCL_PLACE_GET(XDCL))	\
				(XDCL, CTXT)							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Local:Ident:from: _XENUM5_XDCL_PLACE_FROM(XDCL))		\
			BOOST_PP_CAT(_XENUM5_IDENT_FROMVALUE_DEFL_, _XENUM5_XDCL_PLACE_FROM(XDCL))	\
				(XDCL, CTXT)							\
*/\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace _XENUM5_IMPL_LOCAL_NS(XDCL,))				\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


// ========================== DEFL common stuff ==============================
/**
 * No common stuff to define at all.
 */
#define _XENUM5_IDENT_COMMON_DEFL_OFF(XDCL, CTXT)						\

/**
 * Common stuff defined in header is defined in store class; nothing to add in local ns.
 */
#define _XENUM5_IDENT_COMMON_DEFL_HDR(XDCL, CTXT)						\

/**
 * Common stuff omitted from store class is defined here in local ns.
 */
#define _XENUM5_IDENT_COMMON_DEFL_SRC(XDCL, CTXT)						\
	_XENUM5_IDENT_VALUES_DEF(, CTXT)							\
	_XENUM5_IDENT_VALUENAMES_DECL(CTXT)							\
	_XENUM5_IDENT_OFFSETS_DEF(, CTXT)							\
	_XENUM5_DOC(Alias the native enum into this scope.)					\
	using Enum = _XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_enum;			_XENUM5_NWLN \
	_XENUM5_DOC(Alias the Index type into this scope.)					\
	using Index = _XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_index_t;		_XENUM5_NWLN \
	_XENUM5_IDENT_GETOFFSET_DEF()								\


// ========================= Define store members ============================
/**
 * Entry function for definitions of store members.
 */
#define _XENUM5_IDENT_DEFS(XDCL, CTXT)								\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:Ident:common: _XENUM5_XDCL_PLACE_COMMON(XDCL))		\
	BOOST_PP_CAT(_XENUM5_IDENT_COMMON_DEFS_, _XENUM5_XDCL_PLACE_COMMON(XDCL))		\
		(XDCL, CTXT)									\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:Ident:get: _XENUM5_XDCL_PLACE_GET(XDCL))			\
	BOOST_PP_CAT(_XENUM5_IDENT_GETTERS_DEFS_, _XENUM5_XDCL_PLACE_GET(XDCL))			\
		(XDCL, CTXT)									\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:Ident:from: _XENUM5_XDCL_PLACE_FROM(XDCL))		\
	BOOST_PP_CAT(_XENUM5_IDENT_FROMVALUE_DEFS_, _XENUM5_XDCL_PLACE_FROM(XDCL))		\
		(XDCL, CTXT)									\


// ========================== DEFS common stuff ==============================
/**
 * No common stuff to define at all.
 */
#define _XENUM5_IDENT_COMMON_DEFS_OFF(XDCL, CTXT)						\

/**
 * Common stuff is defined inline in store class, but must also exist here in source file,
 * without content.
 */
#define _XENUM5_IDENT_COMMON_DEFS_HDR(XDCL, CTXT)						\
	_XENUM5_IDENT_COMMON_DEFS_HDR_I1(_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_STORE_NAME(XDCL))	\

/**
 * Helper for  _XENUM5_IDENT_COMMON_DEFS_HDR().
 */
#define _XENUM5_IDENT_COMMON_DEFS_HDR_I1(SSCOPE)						\
	constexpr const SSCOPE::IdentValue SSCOPE::identValues[];				_XENUM5_NWLN \
	constexpr const SSCOPE::IdentIndex SSCOPE::identOffsets[];				_XENUM5_NWLN \

/**
 * Common stuff omitted from store class is defined in local ns above.
 */
#define _XENUM5_IDENT_COMMON_DEFS_SRC(XDCL, CTXT)						\


// ============================= DEFS getters ================================
/**
 * No getters stuff to define at all.
 */
#define _XENUM5_IDENT_GETTERS_DEFS_OFF(XDCL, CTXT)						\

/**
 * Define store members declared inline in header (only the data): None, all is in common.
 */
#define _XENUM5_IDENT_GETTERS_DEFS_HDR(XDCL, CTXT)						\

/**
 * Define store members declared inline in header.
 */
#define _XENUM5_IDENT_GETTERS_DEFS_SRC(XDCL, CTXT)						\
	_XENUM5_IDENT_GETIDENT_DEF(								\
		,										\
		_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_STORE_NAME(XDCL)::,				\
		_XENUM5_IDENT_DATA_SCOPE(XDCL)							\
	)											\


/**
 * Helper to get the correct data scope.
 */
// FIXME: Get rid of this, just import the local ns inside getIdentifier().
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
#define _XENUM5_IDENT_FROMVALUE_DEFS_OFF(XDCL, CTXT)						\

/**
 * Omit fromIdentifier(), defined inline/constexpr in header.
 */
#define _XENUM5_IDENT_FROMVALUE_DEFS_HDR(XDCL, CTXT)						\

/**
 * Define fromIdentifier(), declared ext in header file.
 */
#define _XENUM5_IDENT_FROMVALUE_DEFS_SRC(XDCL, CTXT)						\
	_XENUM5_IDENT_FROMVALUE_STD_DEF(							\
		,										\
		_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_STORE_NAME(XDCL)::,				\
		_XENUM5_IDENT_DATA_SCOPE(XDCL)							\
	)											\


// ======================= Define _check() contents ==========================
/**
 * Final checks on common data structures.
 */
#define _XENUM5_IDENT_COMMON_CHECK_0(XDCL)							\
	static_assert(										\
		/* +1: Compiler adds an extra null terminator in Values array */		\
		sizeof(identValues) == sizeof(IdentValueNames) + 1,				\
		"BUG: Struct/array size mismatch (IdentValueNames / identValues)."		\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(identOffsets) == size * sizeof(IdentIndex),				\
		"BUG: Struct size mismatch (identOffsets / ::size)."				\
	);											_XENUM5_NWLN \

/**
 * Final checks on common data structures: None since they do not exist.
 */
#define _XENUM5_IDENT_COMMON_CHECK_1(XDCL)							\


// ====================== Define _dbginfo() contents =========================
/**
 * Define debug info for common data structures.
 */
#define _XENUM5_IDENT_COMMON_DBGINFO_0(XDCL)							\
	std::cout<<"\tIdent:"<<std::endl;							_XENUM5_NWLN \
	std::cout										\
		<<"\t\t"<<BOOST_PP_STRINGIZE(_XENUM5_XDCL_PLACE_COMMON(XDCL))<<": "		\
		<<"sizeof(identValues) = "<<sizeof(identValues)<<std::endl;			_XENUM5_NWLN \
	std::cout										\
		<<"\t\t"<<BOOST_PP_STRINGIZE(_XENUM5_XDCL_PLACE_COMMON(XDCL))<<": "		\
		<<"sizeof(IdentValueNames) = "<<sizeof(IdentValueNames)<<std::endl;		_XENUM5_NWLN \

/**
 * Define debug info for common data structures: None since they are OFF.
 */
#define _XENUM5_IDENT_COMMON_DBGINFO_1(XDCL)							\


// ====================================== COMMON PARTS ==========================================

// ================================ Values ===================================
/**
 * Define the identValues array.
 */
#define _XENUM5_IDENT_VALUES_DEF(DECLPFX, CTXT)							\
	_XENUM5_DOC(Native type for identifier strings.)					\
	using IdentValue = char;								_XENUM5_NWLN \
	_XENUM5_DOC(Array of all identifier strings.)						\
	DECLPFX constexpr const IdentValue identValues[] =					\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_VALUE_DEF, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Loop worker for _XENUM5_IDENT_VALUES_DEF().
 * Define a single identifier value.
 */
#define _XENUM5_IDENT_VALUE_DEF(CTXT, IDENT, ...)						\
	#IDENT "\0"										_XENUM5_NWLN


// ============================== ValueNames =================================
/**
 * Define the IdentValueNames struct.
 */
#define _XENUM5_IDENT_VALUENAMES_DECL(CTXT)							\
	_XENUM5_DOC(Layout of identValues array.)						\
	using IdentValueNames = struct {							_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_VALUENAME_DECL, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Declare a single field of the ValueNames struct.
 */
#define _XENUM5_IDENT_VALUENAME_DECL(CTXT, IDENT, ...)						\
	IdentValue IDENT[sizeof(#IDENT)];							_XENUM5_NWLN


// =============================== Offsets ===================================
/**
 * Define the identOffsets array.
 */
#define _XENUM5_IDENT_OFFSETS_DEF(DECLPFX, CTXT)						\
	_XENUM5_DOC(Integer type big enough to hold offsets into the string pool.)		\
	using IdentIndex = ::_XENUM5_NS::SelectInt<sizeof(identValues)>::type;			_XENUM5_NWLN \
	_XENUM5_DOC(Table of offsets into the identifier stringpool.)				\
	DECLPFX constexpr const IdentIndex identOffsets[] = {					_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_OFFSET_DEF, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Define the offset of a single identifier string.
 */
#define _XENUM5_IDENT_OFFSET_DEF(CTXT, IDENT, ...)						\
	offsetof(IdentValueNames, IDENT),							_XENUM5_NWLN


// ============================= getOffset() =================================
/**
 * Define offset getter function.
 */
#define _XENUM5_IDENT_GETOFFSET_DEF(DECLPFX)							\
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
#define _XENUM5_IDENT_GETIDENT_DEF(DECLPFX, SSCOPED, DATA_SCOPE)				\
	_XENUM5_DOC(@return Identifier (name) of an enum value.)				\
	DECLPFX const char* SSCOPED getIdentifier(SSCOPED Enum value) noexcept			_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return &DATA_SCOPE identValues[DATA_SCOPE getIdentOffset(value)];		_XENUM5_NWLN \
	}											_XENUM5_NWLN \


// =========================== fromIdentifier() ==============================
/**
 * Define fromIdentifier() method, non-constexpr. Both for inline and source definition.
 */
#define _XENUM5_IDENT_FROMVALUE_STD_DEF(DECLPFX, STORE_SCOPE, DATA_SCOPE)			\
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
 * Define cxpFromIdentifier() method; constexpr variant of fromIdentifier().
 */
#define _XENUM5_IDENT_FROMVALUE_CXP_DEF()							\
	_XENUM5_DOC(Recursive worker for throwing cxpFromIdentifier().)				\
	static constexpr Enum cxpFromIdentifierT(const char* identifier, Index index)		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return (index < size)								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			?(::_XENUM5_NS::cxpStrEqual(identifier,					\
					&identValues[getIdentOffset(static_cast<Enum>(index))])	_XENUM5_NWLN \
				_XENUM5_INDENT_INC						\
				? static_cast<Enum>(index)					_XENUM5_NWLN \
				: cxpFromIdentifierT(identifier, index+1)			_XENUM5_NWLN \
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
	static constexpr Enum cxpFromIdentifier(const char* identifier)				_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
 		return cxpFromIdentifierT(identifier, 0);						_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
 	_XENUM5_DOC(Recursive worker for non-throwing cxpFromIdentifier().)			\
	static constexpr bool cxpFromIdentifierN(const char* identifier, Value& value, Index index)	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return (index < size)								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			?(::_XENUM5_NS::cxpStrEqual(identifier,					\
					&identValues[getIdentOffset(static_cast<Enum>(index))])	_XENUM5_NWLN \
				_XENUM5_INDENT_INC						\
 				? (value = static_cast<Enum>(index)), true			_XENUM5_NWLN \
 				: cxpFromIdentifierN(identifier, value, index+1)			_XENUM5_NWLN \
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
	static constexpr bool cxpFromIdentifier(const char* identifier, Value& value) noexcept	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
 		return cxpFromIdentifierN(identifier, value, 0);					_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


#endif // _XENUM5_IMPL_IDENT_HPP
