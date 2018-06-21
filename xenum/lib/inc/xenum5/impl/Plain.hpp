/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of the "plain" data type category for custom properties.
 */
#ifndef _XENUM5_IMPL_PLAIN_HPP
#define _XENUM5_IMPL_PLAIN_HPP


// ======================================= MAIN: DECLS ==========================================
/**
 * Entry point for all custom-prop related declarations in store class (header).
 */
#define _XENUM5_PLAIN_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\
_XENUM5_INDENT_SUB _XENUM5_CMNT(PNAME:common: _XENUM5_PDEF_PLACE_COMMON(PDEF))			\
	BOOST_PP_CAT(_XENUM5_PLAIN_COMMON_DECLS_, _XENUM5_PDEF_PLACE_COMMON(PDEF))		\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(PNAME:get: _XENUM5_PDEF_IMPL_GET(PDEF))				\
	BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_DECLS_, _XENUM5_PDEF_IMPL_GET(PDEF))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(PNAME:from: _XENUM5_PDEF_IMPL_FROM(PDEF))			\
	BOOST_PP_CAT(_XENUM5_PLAIN_FROMVALUE_DECLS_, _XENUM5_PDEF_IMPL_FROM(PDEF))		\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


// ============================= DECLS common ================================
/**
 * No common stuff to declare since nobody uses it.
 */
#define _XENUM5_PLAIN_COMMON_DECLS_OFF(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * No common stuff to declare since it is all defined in source file.
 */
#define _XENUM5_PLAIN_COMMON_DECLS_SRC(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * Define data inline since some inline methods use it.
 */
#define _XENUM5_PLAIN_COMMON_DECLS_HDR(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_VALUETYPE_DECL(PNAME, PDEF)						\
	_XENUM5_PLAIN_VALUES_DEF(static, PNAME, CTXT)						\


// ========================== DECLS prop getters =============================
/**
 * Omit getters, turned off.
 */
#define _XENUM5_PLAIN_GETTERS_DECLS_off(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * Declare getters, defined in source file.
 */
#define _XENUM5_PLAIN_GETTERS_DECLS_ext(PNAME, DEPTH, PDEF, CTXT, Z)				\
	/* Only define index type if depth>0. */						\
	_XENUM5_PROP_INDEXTYPE_FIXED_DECL(PNAME, BOOST_PP_BOOL(DEPTH))				\
	_XENUM5_PROP_GETSIZE_EXT_DECL(DEPTH, PDEF, Z)						\
	_XENUM5_PROP_GETVALUE_EXT_DECL(PNAME, DEPTH, PDEF, Z)					\

/**
 * Define getters as inline constexpr.
 */
#define _XENUM5_PLAIN_GETTERS_DECLS_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
	/* Getter-only data */									\
	_XENUM5_PLAIN_NODESSIZE_DEF(static, PNAME, CTXT)					\
	_XENUM5_PROP_INDEXTYPE_SELECT_DECL(PNAME)						\
	_XENUM5_PROP_NODETYPE_DECL(PNAME)							\
	_XENUM5_PLAIN_NODENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_PLAIN_VALUENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_PLAIN_NODES_DEF(static, PNAME, CTXT)						\
	_XENUM5_PROP_GETNODE_DEF(								\
		DEPTH,										\
		_XENUM5_CTXT_SET_DECLPFX(CTXT, static),						\
		Z										\
	)											\
	_XENUM5_PROP_GETSIZE_DEFS(DEPTH, CTXT, Z)						\
	_XENUM5_PLAIN_GETVALUE_DEFS(static constexpr, PNAME, DEPTH, PDEF, , , Z)		\


// ========================== DECLS prop lookup ==============================
/**
 * Omit from${pname}(), turned off.
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLS_off(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * Declare from${pname}(), defined in source file.
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLS_ext(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_FROMVALUE_EXT_DECL(PNAME, PDEF)						\

/**
 * Define from${pname}() as inline, non-constexpr.
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLS_inl(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_FROMVALUE_STD_DEFS(							\
		static,										\
		PNAME, DEPTH, PDEF, , , Z							\
	)											\

/**
 * Define cxpFrom${pname}() as inline constexpr (also include plain inline variant).
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLS_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PLAIN_FROMVALUE_DECLS_inl(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_FROMVALUE_CXP_DEFS(PNAME, PDEF)						\


// ======================================= MAIN: DECLV ==========================================
/**
 * Entry point for all custom-prop related declarations in value class (header).
 */
#define _XENUM5_PLAIN_DECLV(PNAME, DEPTH, PDEF, CTXT, Z)					\
	BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_DECLV_, _XENUM5_PDEF_IMPL_GET(PDEF))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


// ========================== DECLV prop getters =============================
#ifdef _XENUM5_UNIT_TEST
/**
 * Omit getters, turned off, but replace with a throwing variants just so unit test
 * can detect that they are "not present".
 */
#define _XENUM5_PLAIN_GETTERS_DECLV_off(PNAME, DEPTH, PDEF, CTXT, Z)				\
	const _XENUM5_PDEF_PARM_TYPE(PDEF)							\
	BOOST_PP_CAT(get, PNAME) (								\
		_XENUM5_PROP_GEN_INDEX1_PARMS(size_t, DEPTH, Z)					\
	) const											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		throw std::logic_error("get" BOOST_PP_STRINGIZE(PNAME) "() is configured 'off'.");	_XENUM5_NWLN \
	}											_XENUM5_NWLN \

#else
/**
 * Omit getters, turned off.
 */
#define _XENUM5_PLAIN_GETTERS_DECLV_off(PNAME, DEPTH, PDEF, CTXT, Z)				
#endif

/**
 * Define getters calling store implementation that is defined in source file.
 */
#define _XENUM5_PLAIN_GETTERS_DECLV_ext(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_TYPES_DECLV(PNAME, DEPTH)							\
	_XENUM5_PROP_GETSIZE_DEFV(								\
		BOOST_PP_CAT(PNAME, Index),							\
		DEPTH, CTXT, Z									\
	)											\
	_XENUM5_PROP_GETVALUE_DEFV(, PNAME, DEPTH, PDEF, Z)					\

/**
 * Define getters calling store implementation that is constexpr.
 */
#define _XENUM5_PLAIN_GETTERS_DECLV_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_TYPES_DECLV(PNAME, DEPTH)							\
	_XENUM5_PROP_GETSIZE_DEFV(								\
		constexpr const BOOST_PP_CAT(PNAME, Index)&,					\
		DEPTH, CTXT, Z									\
	)											\
	_XENUM5_PROP_GETVALUE_DEFV(constexpr, PNAME, DEPTH, PDEF, Z)				\


// ======================================= MAIN: DECLC ==========================================
/**
 * Entry point for all custom-prop related declarations in container class (header).
 */
#define _XENUM5_PLAIN_DECLC(PNAME, DEPTH, PDEF, CTXT, Z)					\
	BOOST_PP_CAT(_XENUM5_PLAIN_FROMVALUE_DECLC_, _XENUM5_PDEF_IMPL_FROM(PDEF))		\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


// ========================== DECLC prop lookup ==============================
#ifdef _XENUM5_UNIT_TEST
/**
 * Omit _from${pname}(), turned off, but replace with a throwing variant just so unit test
 * can detect that it is "not present".
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLC_off(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_FROMVALUE_OFF_DEFC(PNAME, PDEF, _XENUM5_XDCL_VNAME(_XENUM5_CTXT_XDCL(CTXT)))

#else
/**
 * Omit _from${pname}(), turned off.
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLC_off(PNAME, DEPTH, PDEF, CTXT, Z)				
#endif

/**
 * Declare _from${pname}(), defined in source file.
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLC_ext(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_FROMVALUE_STD_DEFC(							\
		PNAME,										\
		PDEF,										\
		_XENUM5_STORE_NAME(_XENUM5_CTXT_XDCL(CTXT)),					\
		_XENUM5_XDCL_VNAME(_XENUM5_CTXT_XDCL(CTXT))					\
	)											\

/**
 * Define _from${pname}() as inline, non-constexpr.
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLC_inl(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_FROMVALUE_STD_DEFC(							\
		PNAME,										\
		PDEF,										\
		_XENUM5_STORE_NAME(_XENUM5_CTXT_XDCL(CTXT)),					\
		_XENUM5_XDCL_VNAME(_XENUM5_CTXT_XDCL(CTXT))					\
	)											\

/**
 * Define _from${pname}() as inline, non-constexpr (also include plain inline variant).
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLC_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PLAIN_FROMVALUE_DECLC_inl(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_FROMVALUE_CXP_DEFC(							\
		PNAME,										\
		PDEF,										\
		_XENUM5_STORE_NAME(_XENUM5_CTXT_XDCL(CTXT)),					\
		_XENUM5_XDCL_VNAME(_XENUM5_CTXT_XDCL(CTXT))					\
	)											\


// ====================================== MAIN: DEFINE ==========================================
/**
 * Entry point for all custom-prop related definitions in source file.
 */
#define _XENUM5_PLAIN_DEFINE(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
	_XENUM5_PLAIN_DEFL(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)			\
	_XENUM5_PLAIN_DEFS(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)			\

/**
 * Entry point for definition of final checks on data structures.
 */
#define _XENUM5_PLAIN_CHECK(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)				\
	using namespace LSCOPE;									_XENUM5_NWLN \
	BOOST_PP_CAT(										\
		_XENUM5_PLAIN_COMMON_CHECK_,							\
		BOOST_PP_EQUAL(_XENUM5_PDEF_PLACE_INT_COMMON(PDEF), 0)				\
	) (PNAME, _XENUM5_PDEF_DEPTH(PDEF))							\
	BOOST_PP_CAT(										\
		_XENUM5_PLAIN_GETTERS_CHECK_,							\
		BOOST_PP_EQUAL(_XENUM5_PDEF_PLACE_INT_GET(PDEF), 0)				\
	) (PNAME, _XENUM5_PDEF_DEPTH(PDEF))							\
	BOOST_PP_CAT(										\
		_XENUM5_PLAIN_FROMVALUE_CHECK_,							\
		BOOST_PP_EQUAL(_XENUM5_PDEF_PLACE_INT_FROM(PDEF), 0)				\
	) (PNAME, _XENUM5_PDEF_DEPTH(PDEF))							\

/**
 * Entry point for definition of debug info printing.
 */
#define _XENUM5_PLAIN_DBGINFO(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)				\
	using namespace LSCOPE;									_XENUM5_NWLN \
	std::cout<<"\t"<<BOOST_PP_STRINGIZE(PNAME)<<":"<<std::endl;				_XENUM5_NWLN \
	BOOST_PP_CAT(										\
		_XENUM5_PLAIN_COMMON_DBGINFO_,							\
		BOOST_PP_EQUAL(_XENUM5_PDEF_PLACE_INT_COMMON(PDEF), 0)				\
	) (PNAME, PDEF)										\
	BOOST_PP_CAT(										\
		_XENUM5_PLAIN_GETTERS_DBGINFO_,							\
		BOOST_PP_EQUAL(_XENUM5_PDEF_PLACE_INT_GET(PDEF), 0)				\
	) (PNAME, PDEF)										\
	BOOST_PP_CAT(										\
		_XENUM5_PLAIN_FROMVALUE_DBGINFO_,						\
		BOOST_PP_EQUAL(_XENUM5_PDEF_PLACE_INT_FROM(PDEF), 0)				\
	) (PNAME, PDEF)										\


// ========================== Define in local ns =============================
/**
 * Entry function for definitions made in local ns.
 */
#define _XENUM5_PLAIN_DEFL(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)			\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace LSCOPE {								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Local:PNAME:common: _XENUM5_PDEF_PLACE_COMMON(PDEF))		\
			BOOST_PP_CAT(_XENUM5_PLAIN_COMMON_DEFL_, _XENUM5_PDEF_PLACE_COMMON(PDEF))	\
				(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Local:PNAME:get: _XENUM5_PDEF_PLACE_GET(PDEF))			\
			BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_DEFL_, _XENUM5_PDEF_PLACE_GET(PDEF))	\
				(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
/* FIXME: FROMVALUE_DEFL_* */ \
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace LSCOPE)						\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


// ========================== DEFL common stuff ==============================
/**
 * No common stuff to define at all.
 */
#define _XENUM5_PLAIN_COMMON_DEFL_OFF(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Common stuff defined in header is defined in store class; nothing to add in local ns.
 * Except for convenience we define the value type, to be used by get/from if they are
 * defined in src (local-ns).
 */
#define _XENUM5_PLAIN_COMMON_DEFL_HDR(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	_XENUM5_PROP_VALUETYPE_DECL(PNAME, PDEF)						\

/**
 * Common stuff omitted from store class is defined here in local ns.
 */
#define _XENUM5_PLAIN_COMMON_DEFL_SRC(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	/* Values */										\
	_XENUM5_PROP_VALUETYPE_DECL(PNAME, PDEF)						\
	_XENUM5_PLAIN_VALUES_DEF(, PNAME, CTXT)							\


// ============================= DEFL getters ================================
/**
 * No getter stuff to define at all.
 */
#define _XENUM5_PLAIN_GETTERS_DEFL_OFF(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Getter stuff defined in header is defined in store class; nothing to add in local ns.
 */
#define _XENUM5_PLAIN_GETTERS_DEFL_HDR(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Getter stuff omitted from store class is defined here in local ns.
 */
#define _XENUM5_PLAIN_GETTERS_DEFL_SRC(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	/* Nodes, if depth!=0 */								\
	BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_DEFL_SRC_, BOOST_PP_BOOL(DEPTH))			\
		(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)				\

/**
 * For depth==0: Values are already defined as a single plain array of values,
 * directly indexed by enum value; no need for name struct or nodes table.
 */
#define _XENUM5_PLAIN_GETTERS_DEFL_SRC_0(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * For depth!=0: Define nodes; declare a name struct and define an array of nodes
 * with same layout.
 */
#define _XENUM5_PLAIN_GETTERS_DEFL_SRC_1(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	/* Nodes */										\
	_XENUM5_PLAIN_NODESSIZE_DEF(, PNAME, CTXT)						\
	_XENUM5_PROP_INDEXTYPE_DEFL(PNAME, PDEF)						\
	_XENUM5_PROP_NODETYPE_DECL(PNAME)							\
	_XENUM5_PLAIN_NODENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_PLAIN_VALUENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_PLAIN_NODES_DEF(, PNAME, CTXT)							\
	/* Funcs */										\
	_XENUM5_DOC(Alias the native enum into this scope.)					\
	using Enum = _XENUM5_XDCL_DSCOPE(_XENUM5_CTXT_XDCL(CTXT))_XENUM5_CNTNR_NAME(_XENUM5_CTXT_XDCL(CTXT))::_enum;	_XENUM5_NWLN \
	_XENUM5_PROP_GETNODE_DEF(DEPTH, CTXT, Z)						\


// ========================= Define store members ============================
/**
 * Entry function for definitions of store members.
 */
#define _XENUM5_PLAIN_DEFS(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)			\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:PNAME:common: _XENUM5_PDEF_PLACE_COMMON(PDEF))		\
	BOOST_PP_CAT(_XENUM5_PLAIN_COMMON_DEFS_, _XENUM5_PDEF_PLACE_COMMON(PDEF))		\
		(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)				\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:PNAME:get: _XENUM5_PDEF_PLACE_GET(PDEF))			\
	BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_DEFS_, _XENUM5_PDEF_PLACE_GET(PDEF))			\
		(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)				\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:PNAME:from: _XENUM5_PDEF_PLACE_FROM(PDEF))		\
	BOOST_PP_CAT(_XENUM5_PLAIN_FROMVALUE_DEFS_, _XENUM5_PDEF_PLACE_FROM(PDEF))		\
		(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)				\


// ========================== DEFS common stuff ==============================
/**
 * No common stuff to define at all.
 */
#define _XENUM5_PLAIN_COMMON_DEFS_OFF(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Common stuff is defined inline in store class, but must also exist here in source file,
 * without content.
 */
#define _XENUM5_PLAIN_COMMON_DEFS_HDR(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	constexpr const										\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Value)					\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Values)					\
		[];										_XENUM5_NWLN \

/**
 * Common stuff omitted from store class is defined in local ns above.
 */
#define _XENUM5_PLAIN_COMMON_DEFS_SRC(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\


// ============================= DEFS getters ================================
/**
 * No getters stuff to define at all.
 */
#define _XENUM5_PLAIN_GETTERS_DEFS_OFF(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Define store members declared inline in header (only the data).
 */
#define _XENUM5_PLAIN_GETTERS_DEFS_HDR(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_DEFS_HDR_, BOOST_PP_BOOL(DEPTH))			\
		(PNAME, DSCOPE, SNAME)								\

/**
 * Define nothing since the custom property has depth==0.
 */
#define _XENUM5_PLAIN_GETTERS_DEFS_HDR_0(PNAME, DSCOPE, SNAME)					\

/**
 * Define the getter data, for depth!=0.
 */
#define _XENUM5_PLAIN_GETTERS_DEFS_HDR_1(PNAME, DSCOPE, SNAME)					\
	constexpr const										\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Node)					\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Nodes)					\
		[];										_XENUM5_NWLN \
	/* FIXME: Also define NodesSize - ? */							\

/**
 * Define store members declared inline in header.
 */
#define _XENUM5_PLAIN_GETTERS_DEFS_SRC(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	_XENUM5_PROP_GETSIZE_DEFS(DEPTH, CTXT, Z)						\
	_XENUM5_PLAIN_GETVALUE_DEFS(								\
		,										\
		PNAME,										\
		DEPTH,										\
		PDEF,										\
		LSCOPE,										\
		DSCOPE SNAME::,									\
		Z										\
	)											\


// ============================= DEFS lookup =================================
/**
 * No lookup stuff to define at all.
 */
#define _XENUM5_PLAIN_FROMVALUE_DEFS_OFF(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Define store members declared inline in header (only the data).
 */
#define _XENUM5_PLAIN_FROMVALUE_DEFS_HDR(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
/* FIXME: Lookup data */

/**
 * Define store members declared inline in header.
 */
#define _XENUM5_PLAIN_FROMVALUE_DEFS_SRC(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	_XENUM5_PROP_FROMVALUE_STD_DEFS(							\
		,										\
		PNAME,										\
		DEPTH,										\
		PDEF,										\
		LSCOPE::,									\
		DSCOPE SNAME::,									\
		Z										\
	)											\


// ======================= Define _check() contents ==========================
/**
 * Final checks on common data structures.
 */
#define _XENUM5_PLAIN_COMMON_CHECK_0(PNAME, DEPTH)						\
	BOOST_PP_CAT(_XENUM5_PLAIN_COMMON_CHECK_0_, BOOST_PP_BOOL(DEPTH)) (PNAME)		\

/**
 * Final checks on common data structures, for depth==0.
 */
#define _XENUM5_PLAIN_COMMON_CHECK_0_0(PNAME)							\
	static_assert(										\
		sizeof(BOOST_PP_CAT(PNAME, Values)) ==						\
		sizeof(BOOST_PP_CAT(PNAME, Value)) * size,					\
		"BUG: Data size mismatch (Values / enum-size)."					\
	);											_XENUM5_NWLN \

/**
 * Final checks on common data structures, for depth!=0.
 */
#define _XENUM5_PLAIN_COMMON_CHECK_0_1(PNAME)							\

/**
 * Final checks on common data structures: None since they do not exist.
 */
#define _XENUM5_PLAIN_COMMON_CHECK_1(PNAME, DEPTH)						\


/**
 * Final checks on getter data structures.
 */
#define _XENUM5_PLAIN_GETTERS_CHECK_0(PNAME, DEPTH)						\
	BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_CHECK_0_, BOOST_PP_BOOL(DEPTH)) (PNAME)		\

/**
 * No further getter checks to define for depth==0.
 */
#define _XENUM5_PLAIN_GETTERS_CHECK_0_0(PNAME)							\

/**
 * Define checks for depth!=0.
 */
#define _XENUM5_PLAIN_GETTERS_CHECK_0_1(PNAME)							\
	static_assert(										\
		sizeof(BOOST_PP_CAT(PNAME, Values)) ==						\
		sizeof(BOOST_PP_CAT(PNAME, ValueNames)),					\
		"BUG: Struct/array size mismatch (ValueNames / Values)."			\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(BOOST_PP_CAT(PNAME, NodeNames)) ==					\
		BOOST_PP_CAT(PNAME, NodesSize) * sizeof(BOOST_PP_CAT(PNAME, Node)),		\
		"BUG: Struct size mismatch (NodeNames / NodesSize)."				\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(BOOST_PP_CAT(PNAME, Nodes)) ==						\
		sizeof(BOOST_PP_CAT(PNAME, NodeNames)),						\
		"BUG: Struct/array size mismatch (Nodes / NodeNames)."				\
	);											_XENUM5_NWLN \

/**
 * Final checks on getter data structures: None since they do not exist.
 */
#define _XENUM5_PLAIN_GETTERS_CHECK_1(PNAME, DEPTH)						\


/**
 * Final checks on fromValue() data structures.
 */
// FIXME!
#define _XENUM5_PLAIN_FROMVALUE_CHECK_0(PNAME, DEPTH)						\

/**
 * Final checks on fromValue() data structures: None since they do not exist.
 */
#define _XENUM5_PLAIN_FROMVALUE_CHECK_1(PNAME, DEPTH)						\


// ====================== Define _dbginfo() contents =========================
/**
 * Define debug info for common data structures.
 */
#define _XENUM5_PLAIN_COMMON_DBGINFO_0(PNAME, PDEF)						\
	std::cout										\
		<<"\t\t"<<BOOST_PP_STRINGIZE(_XENUM5_PDEF_PLACE_COMMON(PDEF))<<": "		\
		<<"sizeof("<<BOOST_PP_STRINGIZE(BOOST_PP_CAT(PNAME, Values))<<") = "		\
		<<sizeof(BOOST_PP_CAT(PNAME, Values))<<std::endl;				_XENUM5_NWLN \

/**
 * Define debug info for common data structures: None since they are OFF.
 */
#define _XENUM5_PLAIN_COMMON_DBGINFO_1(PNAME, PDEF)						\

/**
 * Define debug info for getter data structures.
 */
#define _XENUM5_PLAIN_GETTERS_DBGINFO_0(PNAME, PDEF)						\


/**
 * Define debug info for getter data structures, for depth==0.
 */
#define _XENUM5_PLAIN_GETTERS_DBGINFO_0_0(PNAME, PDEF)						\
	BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_DBGINFO_0_, BOOST_PP_BOOL(_XENUM5_PDEF_DEPTH(PDEF)))	\
		(PNAME, PDEF)									\

/**
 * Define debug info for getter data structures, for depth!=0.
 */
#define _XENUM5_PLAIN_GETTERS_DBGINFO_0_1(PNAME, PDEF)						\
	std::cout										\
		<<"\t\t"<<BOOST_PP_STRINGIZE(_XENUM5_PDEF_PLACE_GET(PDEF))<<": "		\
		<<"\t\tsizeof("<<BOOST_PP_STRINGIZE(BOOST_PP_CAT(PNAME, ValueNames))<<") = "	\
		<<sizeof(BOOST_PP_CAT(PNAME, ValueNames))<<std::endl;				_XENUM5_NWLN \

/**
 * Define debug info for getter data structures: None since they are OFF.
 */
#define _XENUM5_PLAIN_GETTERS_DBGINFO_1(PNAME, PDEF)						\

/**
 * Define debug info for fromValue() data structures.
 */
#define _XENUM5_PLAIN_FROMVALUE_DBGINFO_0(PNAME, PDEF)						\
/* FIXME: ! */

/**
 * Define debug info for fromValue data structures: None since they are OFF.
 */
#define _XENUM5_PLAIN_FROMVALUE_DBGINFO_1(PNAME, PDEF)						\



// ====================================== COMMON PARTS ==========================================

// ========================= Node iteration loop =============================
/**
 * Iterate data structure using ITERATE_FLAT_GEN(); execute callback for each branch-node.
 * Used by both nodenames- and nodedata-generation iterations, to ensure that they have
 * identical layout; that the placement of node data in the IndexNodes table match the names
 * in the NodeNames struct.
 * Note: The root nodes (enum-values) must appear first in the tables so they can be directly
 * indexed by an enum-value.
 * Note: All node iteration sets depth-=1 because we are not iterating leaf values, only nodes.
 */
#define _XENUM5_PLAIN_ITER_NODES(CALLBACK, CTXT)						\
	/* First, execute callback only for the enum values (root nodes), so they are */	\
	/* executed in one block. */								\
	_XENUM5_CALL_VALS(									\
		_XENUM5_PLAIN_ITER_NODES_ROOT,							\
		_XENUM5_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)											\
	/* Secondly, iterate all non-root nodes. */						\
	_XENUM5_CALL_VALS(									\
		_XENUM5_PLAIN_ITER_NODES_NONROOT,						\
		_XENUM5_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)

/**
 * Callback worker for _XENUM5_PLAIN_ITER_NODES(); loop function for each root node
 * (enum-value). Execute the callback only for the root node (no further iteration).
 */
#define _XENUM5_PLAIN_ITER_NODES_ROOT(CTXT, IDENT, ...)						\
	_XENUM5_PLAIN_ITER_NODES_ROOT_I1							\
	(											\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_PINDEX(CTXT), __VA_ARGS__),			\
		BOOST_PP_DEC(_XENUM5_PDEF_DEPTH(_XENUM5_CTXT_PDEF(CTXT))),			\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_PLAIN_ITER_NODES_ROOT().
 */
#define _XENUM5_PLAIN_ITER_NODES_ROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM5_CTXT_CALLBACK(CTXT) (								\
		_XENUM5_TT_ITERPOS_INIT(							\
			DEPTH,									\
			,									\
			0,									\
			_XENUM5_GET_TUPLE_SIZE_IF_TUPLE(DATA)					\
		),										\
		_XENUM5_TUPLE_TO_SEQ_COND(DATA, BOOST_PP_BOOL(DEPTH)),				\
		CTXT										\
	)

/**
 * Callback worker for _XENUM5_PLAIN_ITER_NODES(); loop function for each node.
 */
#define _XENUM5_PLAIN_ITER_NODES_NONROOT(CTXT, IDENT, ...)					\
	_XENUM5_PLAIN_ITER_NODES_NONROOT_I1							\
	(											\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_PINDEX(CTXT), __VA_ARGS__),			\
		_XENUM5_PDEF_DEPTH(_XENUM5_CTXT_PDEF(CTXT)),					\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_PLAIN_ITER_NODES_NONROOT().
 * Execute tupletree iteration.
 */
#define _XENUM5_PLAIN_ITER_NODES_NONROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM5_TT_ITERATE_FLAT_GEN(								\
		DATA,										\
		/* We do not want to iterate leaf values */					\
		BOOST_PP_DEC(DEPTH),								\
		(_XENUM5_CTXT_CALLBACK(CTXT), _XENUM5_PLAIN_ITER_NODES_NONROOT_FLT),		\
		CTXT										\
	)

/**
 * Filter function for non-root nodes iteration.
 */
#define _XENUM5_PLAIN_ITER_NODES_NONROOT_FLT(ITERPOS, NODE, CTXT)				\
	BOOST_PP_AND(										\
		BOOST_PP_NOT(_XENUM5_TT_ITERPOS_NEXTCHILD(ITERPOS)),				\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM5_TT_ITERPOS_INDEXPATH(ITERPOS)))		\
	)


// ================================ Values ===================================
/**
 * Define the values array.
 */
#define _XENUM5_PLAIN_VALUES_DEF(DECLPFX, PNAME, CTXT)						\
	_XENUM5_DOC(Array of all PNAME values.)							\
	DECLPFX constexpr const BOOST_PP_CAT(PNAME, Value) BOOST_PP_CAT(PNAME, Values)[] =	\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_PLAIN_VALUE_DEF, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Loop worker for _XENUM5_PLAIN_VALUES_DEF().
 */
#define _XENUM5_PLAIN_VALUE_DEF(ITERPOS, NODE, CTXT)						\
	_XENUM5_PROP_VALUE(NODE, _XENUM5_CTXT_PDEF(CTXT)),					_XENUM5_NWLN


// ============================== NodesSize ==================================
/**
 * Define the NodesSize count.
 */
#define _XENUM5_PLAIN_NODESSIZE_DEF(DECLPFX, PNAME, CTXT)					\
	_XENUM5_DOC(Total number of indexnodes for indexing PNAME values.)			\
	DECLPFX constexpr const size_t BOOST_PP_CAT(PNAME, NodesSize) = 0			\
		_XENUM5_CALL_VALS(_XENUM5_PLAIN_COUNT_NODES, CTXT);				_XENUM5_NWLN \

/**
 * Callback worker for _XENUM5_PLAIN_NODESSIZE_DEF().
 */
#define _XENUM5_PLAIN_COUNT_NODES(CTXT, IDENT, ...)						\
	+_XENUM5_TT_ITERATE_DEPTH_CALC(								\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_PINDEX(CTXT), __VA_ARGS__),			\
		/* Only count nodes, not leaf values. */					\
		BOOST_PP_DEC(_XENUM5_PDEF_DEPTH(_XENUM5_CTXT_PDEF(CTXT))),			\
		(_XENUM5_PROP_COUNT_NODES_ADD),							\
		CTXT,										\
		0										\
	)											\


// ============================== NodeNames ==================================
/**
 * Declare the ${pname}NodeNames struct.
 */
#define _XENUM5_PLAIN_NODENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_DOC(Used for calculating offsets into BOOST_PP_CAT(PNAME, Nodes) array,		\
		has same layout.)								\
	using BOOST_PP_CAT(PNAME, NodeNames) = struct {						_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PLAIN_ITER_NODES(_XENUM5_PROP_NODENAME_DECL, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \


// ============================== ValueNames =================================
/**
 * Declare the ${pname}ValueNames struct.
 */
#define _XENUM5_PLAIN_VALUENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_DOC(Used for calculating offsets into BOOST_PP_CAT(PNAME, Values) array,	\
		has same layout.)								\
	using BOOST_PP_CAT(PNAME, ValueNames) = struct {					_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_PLAIN_VALUENAME_DECL, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Declare a single field of the ValueNames struct.
 */
#define _XENUM5_PLAIN_VALUENAME_DECL(ITERPOS, NODE, CTXT)					\
	BOOST_PP_CAT(_XENUM5_PDEF_NAME(_XENUM5_CTXT_PDEF(CTXT)), Value)				\
	_XENUM5_PROP_GEN_NODE_NAME(CTXT, _XENUM5_TT_ITERPOS_INDEXPATH(ITERPOS));		_XENUM5_NWLN \


// ================================ Nodes ====================================
/**
 * Define the ${pname}Nodes array.
 */
#define _XENUM5_PLAIN_NODES_DEF(DECLPFX, PNAME, CTXT)					\
	_XENUM5_DOC(Mapping of all nodes and values in the PNAME data hierarchy.)		\
	DECLPFX constexpr const BOOST_PP_CAT(PNAME, Node) BOOST_PP_CAT(PNAME, Nodes)[] =	\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PLAIN_ITER_NODES(_XENUM5_PLAIN_NODE_DEF, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_PLAIN_NODES_DEF().
 */
#define _XENUM5_PLAIN_NODE_DEF(ITERPOS, NODE, CTXT)						\
	{											\
		/* Size */									\
		_XENUM5_TT_ITERPOS_CHILDCOUNT(ITERPOS),						\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM5_PLAIN_NODE_DEF_INDEX_,						\
			BOOST_PP_BOOL(_XENUM5_TT_ITERPOS_CHILDCOUNT(ITERPOS))			\
		) (ITERPOS, CTXT)								\
	},											_XENUM5_NWLN \

/**
 * Define Node.index to 0 since node has no children.
 */
#define _XENUM5_PLAIN_NODE_DEF_INDEX_0(ITERPOS, CTXT)						\
	0

/**
 * Define Node.index as an offset expression into a names struct.
 */
#define _XENUM5_PLAIN_NODE_DEF_INDEX_1(ITERPOS, CTXT)						\
	_XENUM5_PLAIN_NODE_DEF_INDEX_1_I1(							\
		_XENUM5_PDEF_NAME(_XENUM5_CTXT_PDEF(CTXT)),					\
		_XENUM5_TT_ITERPOS_INDEXPATH(ITERPOS),						\
		BOOST_PP_IF(									\
			_XENUM5_TT_ITERPOS_LEVEL(ITERPOS),					\
			NodeNames,								\
			ValueNames								\
		),										\
		BOOST_PP_IF(									\
			_XENUM5_TT_ITERPOS_LEVEL(ITERPOS),					\
			Node,									\
			Value									\
		),										\
		CTXT										\
	)

/**
 * Worker for _XENUM5_PLAIN_NODE_DEF_INDEX_1().
 */
#define _XENUM5_PLAIN_NODE_DEF_INDEX_1_I1(PNAME, INDEXPATH, NAMESTRUCT, MEMBERTYPE, CTXT)	\
	(offsetof(										\
		BOOST_PP_CAT(PNAME, NAMESTRUCT),						\
		_XENUM5_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0))		\
	) / sizeof(BOOST_PP_CAT(PNAME, MEMBERTYPE)))


// ========================= Define get${PNAME}() ============================
/**
 * Define Store::get${pname}(), inline/constexpr or ext as declared in header.
 */
#define _XENUM5_PLAIN_GETVALUE_DEFS(DECLPFX, PNAME, DEPTH, PDEF, LSCOPE, SSCOPED, Z)		\
	_XENUM5_DOC(Get value of the custom property PNAME.)					\
	DECLPFX const _XENUM5_PDEF_PARM_TYPE(PDEF)						\
	SSCOPED BOOST_PP_CAT(get, PNAME) (							\
		_XENUM5_PROP_GEN_INDEX0_PARMS(							\
			SSCOPED Enum,								\
			SSCOPED BOOST_PP_CAT(PNAME, Index),					\
			DEPTH,									\
			Z									\
		)										\
	) BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		BOOST_PP_IF(BOOST_PP_IS_EMPTY(LSCOPE),						\
			,									\
			using namespace LSCOPE; _XENUM5_NWLN					\
		)										\
		return BOOST_PP_CAT(PNAME, Values)[						\
			BOOST_PP_CAT(								\
				_XENUM5_PLAIN_GEN_VALUE_INDEXING_,				\
				BOOST_PP_BOOL(DEPTH)						\
			) (PNAME, DEPTH, Z)							\
		];										_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


/**
 * Generate value indexing expression for a property having depth==0.
 */
#define _XENUM5_PLAIN_GEN_VALUE_INDEXING_0(PNAME, DEPTH, Z)					\
	getIndex(index0)

/**
 * Generate value indexing expression for a property having depth!=0.
 */
#define _XENUM5_PLAIN_GEN_VALUE_INDEXING_1(PNAME, DEPTH, Z)					\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (						\
		_XENUM5_PROP_GEN_INDEX0_ARGS(DEPTH, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, DEPTH))						\


#endif // _XENUM5_IMPL_PLAIN_HPP
