/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of definitions for "cstring" data type category.
 */
#ifndef _XENUM5_IMPL_CSTRING_DEFINE_HPP
#define _XENUM5_IMPL_CSTRING_DEFINE_HPP


// ========================================== MAIN ==============================================
/**
 * Entry point for all custom-prop related definitions in source file.
 */
#define _XENUM5_CSTRING_DEFINE(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:PNAME:data: _XENUM5_PDEF_PROP_DATA(PDEF))			\
	BOOST_PP_CAT(_XENUM5_CSTRING_DATA_DEF_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
		(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)				\
_XENUM5_INDENT_SUB _XENUM5_CMNT(Store:PNAME:get: _XENUM5_PDEF_IMPL_GET(PDEF))			\
	BOOST_PP_CAT(_XENUM5_CSTRING_GETTERS_DEF_, _XENUM5_PDEF_IMPL_GET(PDEF))			\
		(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)				\

/**
 * Entry point for definition of final checks on data structures.
 */
#define _XENUM5_CSTRING_CHECK(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)				\
	BOOST_PP_CAT(_XENUM5_CSTRING_CHECK_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
		(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)						\

/**
 * Entry point for definition of debug info printing.
 */
#define _XENUM5_CSTRING_DBGINFO(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)				\
	BOOST_PP_CAT(_XENUM5_CSTRING_DBGINFO_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
		(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)						\


// ============================= Define data =================================
/**
 * Define the data, without content since that is in the header.
 */
#define _XENUM5_CSTRING_DATA_DEF_HDR(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	/* FIXME: Also define NodesSize - ? */							\
	constexpr const										\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Value)					\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Values)					\
		[];										_XENUM5_NWLN \
	constexpr const										\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Node)					\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Nodes)					\
		[];										_XENUM5_NWLN \

/**
 * Define all the data, in local ns.
 */
#define _XENUM5_CSTRING_DATA_DEF_SRC(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace LSCOPE {								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			/* Values */								\
			_XENUM5_PROP_VALUETYPE_DECL(PNAME, PDEF)				\
			_XENUM5_CSTRING_VALUES_DEF(, PNAME, CTXT)				\
			/* Nodes. For cstrings (contrary to "plain") we always need an */	\
			/* indexnodes table since each string needs to be referenced by */	\
			/* an indexnode. */							\
			_XENUM5_CSTRING_NODESSIZE_DEF(, PNAME, CTXT)				\
			_XENUM5_PROP_INDEXTYPE_SELECT_DECL(PNAME)				\
			_XENUM5_PROP_NODETYPE_DECL(PNAME)					\
			_XENUM5_CSTRING_NODENAMES_DECL(PNAME, CTXT)				\
			_XENUM5_CSTRING_VALUENAMES_DECL(PNAME, CTXT)				\
			_XENUM5_CSTRING_NODES_DEF(, PNAME, CTXT)				\
			/* Funcs */								\
			_XENUM5_DOC(Alias the native enum into this scope.)			\
			using Enum = _XENUM5_XDCL_DSCOPE(_XENUM5_CTXT_XDCL(CTXT))_XENUM5_CNTNR_NAME(_XENUM5_CTXT_XDCL(CTXT))::_enum;	_XENUM5_NWLN \
			/* INC() because Nodes also has indexnodes for the leaf stringvalues */	\
			_XENUM5_PROP_GETNODE_DEF(BOOST_PP_INC(DEPTH), CTXT, Z)			\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace LSCOPE)						\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


// ============================ Define getters ===============================
/**
 * Omit getters, they are defined inline constexpr in header.
 */
#define _XENUM5_CSTRING_GETTERS_DEF_cxp(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\

/**
 * Define getters, declared in header file.
 */
#define _XENUM5_CSTRING_GETTERS_DEF_ext(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	/* INC() because Nodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_GETSIZE_DEFS(BOOST_PP_INC(DEPTH), CTXT, Z)					\
	_XENUM5_CSTRING_GETVALUE_EXT_DEF(PNAME, DEPTH, PDEF, LSCOPE ::, DSCOPE, SNAME, Z)	\

/**
 * Define get${pname}() value getter.
 */
// FIXME: Rename. Merge with constexpr generator.
#define _XENUM5_CSTRING_GETVALUE_EXT_DEF(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, Z)	\
	const _XENUM5_PDEF_PARM_TYPE(PDEF)							\
	DSCOPE SNAME :: BOOST_PP_CAT(get, PNAME) (						\
		_XENUM5_PROP_GEN_INDEX0_PARMS(DSCOPE SNAME::Enum,				\
			DSCOPE SNAME::BOOST_PP_CAT(PNAME, Index), DEPTH, Z)			\
	) BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return & LSCOPE BOOST_PP_CAT(PNAME, Values)[					\
			LSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (			\
				_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(DEPTH), Z)		\
			)									\
			.index									\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN


// =========================== Define _check() ===============================
// FIXME: Merge into one, just set LSCOPE empty.
/**
 * Define final checks on data structures, for implementation in header.
 */
#define _XENUM5_CSTRING_CHECK_HDR(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
	static_assert(										\
		/* +1: Compiler adds an extra null terminator in Values array */		\
		sizeof(BOOST_PP_CAT(PNAME, Values)) ==						\
		sizeof(BOOST_PP_CAT(PNAME, ValueNames)) + 1,					\
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
 * Define final checks on data structures, for implementation in source.
 */
#define _XENUM5_CSTRING_CHECK_SRC(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
	static_assert(										\
		/* +1: Compiler adds an extra null terminator in Values array */		\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Values)) ==					\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, ValueNames)) + 1,				\
		"BUG: Struct/array size mismatch (ValueNames / Values)."			\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, NodeNames)) ==				\
		LSCOPE::BOOST_PP_CAT(PNAME, NodesSize) *					\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Node)),					\
		"BUG: Struct size mismatch (NodeNames / NodesSize)."				\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Nodes)) ==					\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, NodeNames)),					\
		"BUG: Struct/array size mismatch (Nodes / NodeNames)."				\
	);											_XENUM5_NWLN \


// =========================== DEFS _dbginfo() ===============================
/**
 * Define debug info for prop data structures, defined in header.
 */
#define _XENUM5_CSTRING_DBGINFO_HDR(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
	std::cout<<"\t"<<BOOST_PP_STRINGIZE(PNAME)<<" (HDR):"<<std::endl			\
		<<"\t\tsizeof("<<BOOST_PP_STRINGIZE(BOOST_PP_CAT(PNAME, Values))<<") = "	\
			<<sizeof(BOOST_PP_CAT(PNAME, Values))<<std::endl			\
		<<"\t\tsizeof("<<BOOST_PP_STRINGIZE(BOOST_PP_CAT(PNAME, ValueNames))<<") = "	\
			<<sizeof(BOOST_PP_CAT(PNAME, ValueNames))<<std::endl			\
		;										_XENUM5_NWLN \


/**
 * Define debug info for prop data structures, defined in source.
 */
#define _XENUM5_CSTRING_DBGINFO_SRC(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
	std::cout<<"\t"<<BOOST_PP_STRINGIZE(PNAME)<<" (SRC):"<<std::endl			\
		<<"\t\tsizeof("<<BOOST_PP_STRINGIZE(LSCOPE::BOOST_PP_CAT(PNAME, Values))<<") = "	\
			<<sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Values))<<std::endl		\
		<<"\t\tsizeof("<<BOOST_PP_STRINGIZE(LSCOPE::BOOST_PP_CAT(PNAME, ValueNames))<<") = "	\
			<<sizeof(LSCOPE::BOOST_PP_CAT(PNAME, ValueNames))<<std::endl		\
		;										_XENUM5_NWLN \


#endif // _XENUM5_IMPL_CSTRING_DEFINE_HPP
