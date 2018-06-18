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
_XENUM5_INDENT_SUB _XENUM5_CMNT(PNAME:data: _XENUM5_PDEF_PROP_DATA(PDEF))			\
	BOOST_PP_CAT(_XENUM5_PLAIN_DATA_DECLS_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(PNAME:get: _XENUM5_PDEF_IMPL_GET(PDEF))				\
	BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_DECLS_, _XENUM5_PDEF_IMPL_GET(PDEF))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(PNAME:from: _XENUM5_PDEF_IMPL_FROM(PDEF))			\
	BOOST_PP_CAT(_XENUM5_PLAIN_FROMVALUE_DECLS_, _XENUM5_PDEF_IMPL_FROM(PDEF))		\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


// =========================== DECLS prop data ===============================
/**
 * No data to declare since nobody uses it.
 */
#define _XENUM5_PLAIN_DATA_DECLS_OFF(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * No data to declare since it is all defined in source file.
 */
#define _XENUM5_PLAIN_DATA_DECLS_SRC(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * Define data inline since some inline methods use it.
 */
#define _XENUM5_PLAIN_DATA_DECLS_HDR(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_VALUETYPE_DECL(PNAME, PDEF)						\
	_XENUM5_PLAIN_VALUES_DEF(static, PNAME, CTXT)						\
	BOOST_PP_CAT(_XENUM5_PLAIN_DATA_DECLS_HDR_, BOOST_PP_BOOL(DEPTH))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


/**
 * Worker for _XENUM5_PLAIN_DATA_DECLS_HDR(), for depth==0.
 * Values are already defined as a single plain array of values, directly indexed
 * by enum value; no need for name struct or nodes table.
 */
#define _XENUM5_PLAIN_DATA_DECLS_HDR_0(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * Worker for _XENUM5_PLAIN_DATA_DECLS_HDR(), for depth!=0.
 * Declares variables related to index nodes (depth>0).
 */
#define _XENUM5_PLAIN_DATA_DECLS_HDR_1(PNAME, DEPTH, PDEF, CTXT, Z)				\
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


// ========================== DECLS prop getters =============================
/**
 * Omit getters, turned off.
 */
#define _XENUM5_PLAIN_GETTERS_DECLS_off(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * Declare getters, defined in source file.
 */
#define _XENUM5_PLAIN_GETTERS_DECLS_ext(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_INDEXTYPE_FIXED_DECL(PNAME, DEPTH)						\
	_XENUM5_PROP_GETSIZE_EXT_DECL(DEPTH, PDEF, Z)						\
	_XENUM5_PROP_GETVALUE_EXT_DECL(PNAME, DEPTH, PDEF, Z)					\

/**
 * Define getters as inline constexpr.
 */
#define _XENUM5_PLAIN_GETTERS_DECLS_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
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
/* FIXME */											\
static_assert(false, "Custom-prop fromValue() (plain:decls:ext) not implemented yet.");	_XENUM5_NWLN \

/**
 * Define from${pname}() as inline, non-constexpr.
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLS_inl(PNAME, DEPTH, PDEF, CTXT, Z)				\
/* FIXME */											\
static_assert(false, "Custom-prop fromValue() (plain:decls:inl) not implemented yet.");	_XENUM5_NWLN \

/**
 * Define cxpFrom${pname}() as inline constexpr (also include plain inline variant).
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLS_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
/* FIXME */											\
static_assert(false, "Custom-prop fromValue() (plain:decls:cxp) not implemented yet.");	_XENUM5_NWLN \


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
/* FIXME */											\
static_assert(false, "Custom-prop fromValue() (plain:declc:ext) not implemented yet.");		_XENUM5_NWLN \

/**
 * Define _from${pname}() as inline, non-constexpr.
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLC_inl(PNAME, DEPTH, PDEF, CTXT, Z)				\
/* FIXME */											\
static_assert(false, "Custom-prop fromValue() (plain:declc:inl) not implemented yet.");		_XENUM5_NWLN \

/**
 * Define _from${pname}() as inline, non-constexpr.
 */
#define _XENUM5_PLAIN_FROMVALUE_DECLC_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
/* FIXME */											\
static_assert(false, "Custom-prop fromValue() (plain:declc:cxp) not implemented yet.");		_XENUM5_NWLN \



// ====================================== MAIN: DEFINE ==========================================
/**
 * Entry point for all custom-prop related definitions in source file.
 */
#define _XENUM5_PLAIN_DEFINE(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:PNAME:data: _XENUM5_PDEF_PROP_DATA(PDEF))			\
	BOOST_PP_CAT(_XENUM5_PLAIN_DATA_DEF_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
		(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)				\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:PNAME:get: _XENUM5_PDEF_IMPL_GET(PDEF))			\
	BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_DEF_, _XENUM5_PDEF_IMPL_GET(PDEF))			\
		(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)				\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:PNAME:from: _XENUM5_PDEF_IMPL_FROM(PDEF))			\
	BOOST_PP_CAT(_XENUM5_PLAIN_FROMVALUE_DEF_, _XENUM5_PDEF_IMPL_FROM(PDEF))		\
		(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)				\

/**
 * Entry point for definition of final checks on data structures.
 */
#define _XENUM5_PLAIN_CHECK(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)				\
	BOOST_PP_CAT(_XENUM5_PLAIN_CHECK_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
	(											\
		PNAME,										\
		_XENUM5_PDEF_DEPTH(PDEF),							\
		LSCOPE,										\
		DSCOPE SNAME									\
	)											\

/**
 * Entry point for definition of debug info printing.
 */
#define _XENUM5_PLAIN_DBGINFO(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)				\
	BOOST_PP_CAT(_XENUM5_PLAIN_DBGINFO_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
		(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)						\


// ============================= Define data =================================
/**
 * No data to define since nobody uses it.
 */
#define _XENUM5_PLAIN_DATA_DEF_OFF(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\

/**
 * Define the data, without content since that is in the header.
 */
#define _XENUM5_PLAIN_DATA_DEF_HDR(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
	/* FIXME: Also define NodesSize - ? */							\
	constexpr const										\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Value)					\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Values)					\
		[];										_XENUM5_NWLN \
	BOOST_PP_CAT(_XENUM5_PLAIN_DATA_DEF_HDR_, BOOST_PP_BOOL(DEPTH))				\
		(PNAME, DSCOPE, SNAME)								\

/**
 * Define nothing since the custom property has depth==0.
 */
#define _XENUM5_PLAIN_DATA_DEF_HDR_0(PNAME, DSCOPE, SNAME)					\


/**
 * Define the data of a single multilevel custom property, when depth!=0.
 */
#define _XENUM5_PLAIN_DATA_DEF_HDR_1(PNAME, DSCOPE, SNAME)					\
	constexpr const										\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Node)					\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Nodes)					\
		[];										_XENUM5_NWLN \

/**
 * Define all the data, in local ns.
 */
#define _XENUM5_PLAIN_DATA_DEF_SRC(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace LSCOPE {								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			/* Values */								\
			_XENUM5_PROP_VALUETYPE_DECL(PNAME, PDEF)				\
			_XENUM5_PLAIN_VALUES_DEF(, PNAME, CTXT)					\
			/* Nodes, if depth!=0 */						\
			BOOST_PP_CAT(_XENUM5_PLAIN_DATA_DEF_SRC_, BOOST_PP_BOOL(DEPTH))		\
				(PNAME, DEPTH, PDEF, CTXT, Z)					\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace LSCOPE)						\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


/**
 * For depth==0: Values are already defined as a single plain array of values,
 * directly indexed by enum value; no need for name struct or nodes table.
 */
#define _XENUM5_PLAIN_DATA_DEF_SRC_0(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * For depth!=0: Define nodes; declare a name struct and define an array of nodes
 * with same layout.
 */
#define _XENUM5_PLAIN_DATA_DEF_SRC_1(PNAME, DEPTH, PDEF, CTXT, Z)				\
	/* Nodes */										\
	_XENUM5_PLAIN_NODESSIZE_DEF(, PNAME, CTXT)						\
	_XENUM5_PROP_INDEXTYPE_SELECT_DECL(PNAME)						\
	_XENUM5_PROP_NODETYPE_DECL(PNAME)							\
	_XENUM5_PLAIN_NODENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_PLAIN_VALUENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_PLAIN_NODES_DEF(, PNAME, CTXT)							\
	/* Funcs */										\
	_XENUM5_DOC(Alias the native enum into this scope.)					\
	using Enum = _XENUM5_XDCL_DSCOPE(_XENUM5_CTXT_XDCL(CTXT))_XENUM5_CNTNR_NAME(_XENUM5_CTXT_XDCL(CTXT))::_enum;	_XENUM5_NWLN \
	_XENUM5_PROP_GETNODE_DEF(DEPTH, CTXT, Z)						\


// ============================ Define getters ===============================
/**
 * Omit getters, they are configured off.
 */
#define _XENUM5_PLAIN_GETTERS_DEF_off(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Define getters, declared in header file.
 */
#define _XENUM5_PLAIN_GETTERS_DEF_ext(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	_XENUM5_PROP_GETSIZE_DEFS(DEPTH, CTXT, Z)						\
	_XENUM5_PLAIN_GETVALUE_DEFS(, PNAME, DEPTH, PDEF, LSCOPE::, DSCOPE SNAME::, Z)		\

/**
 * Omit getters, they are defined inline constexpr in header.
 */
#define _XENUM5_PLAIN_GETTERS_DEF_cxp(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\


// ============================ Define lookup ================================
/**
 * Omit from${pname}(), turned off.
 */
#define _XENUM5_PLAIN_FROMVALUE_DEF_off(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Define from${pname}(), declared in header file.
 */
#define _XENUM5_PLAIN_FROMVALUE_DEF_ext(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
/* FIXME */											\
static_assert(false, "Custom-prop fromValue() (plain:def:ext) not implemented yet.");		_XENUM5_NWLN \

/**
 * Omit from${pname}(), defined inline in header.
 */
#define _XENUM5_PLAIN_FROMVALUE_DEF_inl(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Omit from${pname}(), defined inline constexpr in header.
 */
#define _XENUM5_PLAIN_FROMVALUE_DEF_cxp(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\


// ======================= Define _check() contents ==========================
/**
 * Final checks on data structures: None since they do not exist.
 */
#define _XENUM5_PLAIN_CHECK_OFF(PNAME, DEPTH, LSCOPE, SSCOPE)					\

/**
 * Define final checks on data structures, for implementation in header.
 */
#define _XENUM5_PLAIN_CHECK_HDR(PNAME, DEPTH, LSCOPE, SSCOPE)					\
	_XENUM5_PLAIN_CHECK_I1(PNAME, DEPTH, , )						\

/**
 * Define final checks on data structures, for implementation in source.
 */
#define _XENUM5_PLAIN_CHECK_SRC(PNAME, DEPTH, LSCOPE, SSCOPE)					\
	_XENUM5_PLAIN_CHECK_I1(PNAME, DEPTH, LSCOPE::, SSCOPE::)				\

/**
 * Define final checks on data structures, both for hdr/src.
 */
#define _XENUM5_PLAIN_CHECK_I1(PNAME, DEPTH, LSCOPED, SSCOPED)					\
	BOOST_PP_CAT(_XENUM5_PLAIN_CHECK_, BOOST_PP_BOOL(DEPTH)) (PNAME, LSCOPED, SSCOPED)	\

/**
 * Define checks for depth==0.
 */
#define _XENUM5_PLAIN_CHECK_0(PNAME, LSCOPED, SSCOPED)						\
	static_assert(										\
		sizeof(LSCOPED BOOST_PP_CAT(PNAME, Values)) ==					\
		sizeof(LSCOPED BOOST_PP_CAT(PNAME, Value)) * SSCOPED size,			\
		"BUG: Data size mismatch (Values / enum-size)."					\
	);											_XENUM5_NWLN \

/**
 * Define checks for depth!=0.
 */
#define _XENUM5_PLAIN_CHECK_1(PNAME, LSCOPED, SSCOPED)						\
	static_assert(										\
		sizeof(LSCOPED BOOST_PP_CAT(PNAME, Values)) ==					\
		sizeof(LSCOPED BOOST_PP_CAT(PNAME, ValueNames)),				\
		"BUG: Struct/array size mismatch (ValueNames / Values)."			\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LSCOPED BOOST_PP_CAT(PNAME, NodeNames)) ==				\
		LSCOPED BOOST_PP_CAT(PNAME, NodesSize) *					\
		sizeof(LSCOPED BOOST_PP_CAT(PNAME, Node)),					\
		"BUG: Struct size mismatch (NodeNames / NodesSize)."				\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LSCOPED BOOST_PP_CAT(PNAME, Nodes)) ==					\
		sizeof(LSCOPED BOOST_PP_CAT(PNAME, NodeNames)),					\
		"BUG: Struct/array size mismatch (Nodes / NodeNames)."				\
	);											_XENUM5_NWLN \


// ====================== Define _dbginfo() contents =========================
/**
 * Define debug info for prop data structures, defined in header.
 */
#define _XENUM5_PLAIN_DBGINFO_HDR(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
	_XENUM5_PLAIN_DBGINFO_I1(PNAME, _XENUM5_PDEF_DEPTH(PDEF), , SNAME)			\

/**
 * Define debug info for prop data structures, defined in source.
 */
#define _XENUM5_PLAIN_DBGINFO_SRC(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
	_XENUM5_PLAIN_DBGINFO_I1(PNAME, _XENUM5_PDEF_DEPTH(PDEF), LSCOPE::, LSCOPE)		\

/**
 * Define debug info for prop data structures, for both hdr/src.
 */
#define _XENUM5_PLAIN_DBGINFO_I1(PNAME, DEPTH, LSCOPED, INFSCOPE)				\
	std::cout<<"\t"<<BOOST_PP_STRINGIZE(PNAME)<<":"<<std::endl				\
		<<"\t\tsizeof("<<BOOST_PP_STRINGIZE(INFSCOPE::BOOST_PP_CAT(PNAME, Values))<<") = "	\
			<<sizeof(LSCOPED BOOST_PP_CAT(PNAME, Values))<<std::endl		\
	BOOST_PP_CAT(_XENUM5_PLAIN_DBGINFO_I1_, BOOST_PP_BOOL(DEPTH))(PNAME, LSCOPED, INFSCOPE)	\
		;										_XENUM5_NWLN \

/**
 * Depth==0: No other data structures, so no more debug info to define.
 */
#define _XENUM5_PLAIN_DBGINFO_I1_0(PNAME, LSCOPED, INFSCOPE)					\

/**
 * Depth!=0: Define debug info for additional data structures.
 */
#define _XENUM5_PLAIN_DBGINFO_I1_1(PNAME, LSCOPED, INFSCOPE)					\
		<<"\t\tsizeof("<<BOOST_PP_STRINGIZE(INFSCOPE::BOOST_PP_CAT(PNAME, ValueNames))<<") = "	\
			<<sizeof(LSCOPED BOOST_PP_CAT(PNAME, ValueNames))<<std::endl		\



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
#define _XENUM5_PLAIN_GETVALUE_DEFS(DECLPFX, PNAME, DEPTH, PDEF, LSCOPED, SSCOPED, Z)		\
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
		_XENUM5_INDENT_ADD								\
		return LSCOPED BOOST_PP_CAT(PNAME, Values)[					\
			BOOST_PP_CAT(								\
				_XENUM5_PLAIN_GEN_VALUE_INDEXING_,				\
				BOOST_PP_BOOL(DEPTH)						\
			) (LSCOPED, PNAME, DEPTH, Z)						\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN \


/**
 * Generate value indexing expression for a property having depth==0.
 */
#define _XENUM5_PLAIN_GEN_VALUE_INDEXING_0(LSCOPED, PNAME, DEPTH, Z)				\
	getIndex(index0)

/**
 * Generate value indexing expression for a property having depth!=0.
 */
#define _XENUM5_PLAIN_GEN_VALUE_INDEXING_1(LSCOPED, PNAME, DEPTH, Z)				\
	LSCOPED BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (					\
		_XENUM5_PROP_GEN_INDEX0_ARGS(DEPTH, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, DEPTH))						\


#endif // _XENUM5_IMPL_PLAIN_HPP
