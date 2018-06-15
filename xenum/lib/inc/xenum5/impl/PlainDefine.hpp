/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of definitions for "plain" data type category.
 */
#ifndef _XENUM5_IMPL_PLAIN_DEFINE_HPP
#define _XENUM5_IMPL_PLAIN_DEFINE_HPP


// ========================================== MAIN ==============================================
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
 * Omit getters, they are defined inline constexpr in header.
 */
#define _XENUM5_PLAIN_GETTERS_DEF_cxp(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Define getters, declared in header file.
 */
#define _XENUM5_PLAIN_GETTERS_DEF_ext(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	_XENUM5_PROP_GETSIZE_DEFS(DEPTH, CTXT, Z)						\
	_XENUM5_PLAIN_GETVALUE_DEFS(, PNAME, DEPTH, PDEF, LSCOPE::, DSCOPE SNAME::, Z)		\


// ======================= Define _check() contents ==========================
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



#endif // _XENUM5_IMPL_PLAIN_DEFINE_HPP
