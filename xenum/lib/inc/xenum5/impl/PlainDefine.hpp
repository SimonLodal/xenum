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
		(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)						\

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
	_XENUM5_PLAIN_GETVALUE_EXT_DEF(PNAME, DEPTH, PDEF, LSCOPE ::, DSCOPE, SNAME, Z)		\


/**
 * Define get${pname}() value getter.
 */
#define _XENUM5_PLAIN_GETVALUE_EXT_DEF(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, Z)		\
	const _XENUM5_PDEF_PARM_TYPE(PDEF)							\
	DSCOPE SNAME::BOOST_PP_CAT(get, PNAME) (						\
		_XENUM5_PROP_GEN_INDEX0_PARMS(DSCOPE SNAME::Enum,				\
			DSCOPE SNAME::BOOST_PP_CAT(PNAME, Index), DEPTH, Z)			\
	) BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return LSCOPE BOOST_PP_CAT(PNAME, Values)[					\
			BOOST_PP_CAT(_XENUM5_PLAIN_GETVALUE_EXT_DEF_, BOOST_PP_BOOL(DEPTH))	\
				(PNAME, DEPTH, LSCOPE, DSCOPE, SNAME, Z)			\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN

/**
 * Define get${pname}() indexing for depth==0.
 */
#define _XENUM5_PLAIN_GETVALUE_EXT_DEF_0(PNAME, DEPTH, LSCOPE, DSCOPE, SNAME, Z)		\
	DSCOPE SNAME::getIndex(index0)								\

/**
 * Define get${pname}() indexing for depth!=0.
 */
#define _XENUM5_PLAIN_GETVALUE_EXT_DEF_1(PNAME, DEPTH, LSCOPE, DSCOPE, SNAME, Z)		\
	LSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (					\
		_XENUM5_PROP_GEN_INDEX0_ARGS(DEPTH, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, DEPTH))						\


// =========================== Define _check() ===============================
/**
 * Define final checks on data structures, for implementation in header.
 */
#define _XENUM5_PLAIN_CHECK_HDR(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)				\
	BOOST_PP_CAT(_XENUM5_PLAIN_CHECK_HDR_, BOOST_PP_BOOL(_XENUM5_PDEF_DEPTH(PDEF)))		\
		(PNAME, DSCOPE, SNAME)

/**
 * For depth==0, there is no final checks to be made.
 */
#define _XENUM5_PLAIN_CHECK_HDR_0(PNAME, DSCOPE, SNAME)						\

/**
 * For depth!=0, do check sizes of generated data.
 */
#define _XENUM5_PLAIN_CHECK_HDR_1(PNAME, DSCOPE, SNAME)						\
	static_assert(										\
		sizeof(DSCOPE SNAME::BOOST_PP_CAT(PNAME, ValueNames)) ==			\
		sizeof(DSCOPE SNAME::BOOST_PP_CAT(PNAME, Values)),				\
		"Struct/array size mismatch (ValueNames / Values)."				\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(DSCOPE SNAME::BOOST_PP_CAT(PNAME, NodeNames)) ==				\
		sizeof(DSCOPE SNAME::BOOST_PP_CAT(PNAME, Nodes)),				\
		"Struct/array size mismatch (NodeNames / Nodes)."				\
	);											_XENUM5_NWLN \


/**
 * Define final checks on data structures, for implementation in source.
 */
#define _XENUM5_PLAIN_CHECK_SRC(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)				\
	BOOST_PP_CAT(_XENUM5_PLAIN_CHECK_SRC_, BOOST_PP_BOOL(_XENUM5_PDEF_DEPTH(PDEF)))		\
		(PNAME, LSCOPE, DSCOPE, SNAME)							\

/**
 * Worker for _XENUM5_PLAIN_SRC_CHECK(), for depth==0.
 */
#define _XENUM5_PLAIN_CHECK_SRC_0(PNAME, LSCOPE, DSCOPE, SNAME)					\
	static_assert(										\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Values)) ==					\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Value)) * DSCOPE SNAME::size,		\
		"Data size mismatch (Values / enum-size)."					\
	);											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_PLAIN_SRC_CHECK(), for depth!=0.
 */
#define _XENUM5_PLAIN_CHECK_SRC_1(PNAME, LSCOPE, DSCOPE, SNAME)					\
	static_assert(										\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, NodeNames)) ==				\
		LSCOPE::BOOST_PP_CAT(PNAME, NodesSize) *					\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Node)),					\
		"Struct size mismatch (NodeNames / NodesSize)."					\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Nodes)) ==					\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, NodeNames)),					\
		"Array/struct size mismatch (Nodes / NodeNames)."				\
	);											_XENUM5_NWLN \


// =============================== _dbginfo() ==================================
/**
 * Define debug info, for implementation in header.
 */
#define _XENUM5_PLAIN_DBGINFO_HDR(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
	std::cout<<"\t"<<BOOST_PP_STRINGIZE(PNAME)<<" (HDR):"<<std::endl			\
/* FIXME: ? */\
		<<"\t\t?"<<std::endl								\
		;										_XENUM5_NWLN \


/**
 * Define debug info, for implementation in source.
 */
#define _XENUM5_PLAIN_DBGINFO_SRC(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
	std::cout<<"\t"<<BOOST_PP_STRINGIZE(PNAME)<<" (SRC):"<<std::endl			\
/* FIXME: ? */\
		<<"\t\t?"<<std::endl								\
		;										_XENUM5_NWLN \


#endif // _XENUM5_IMPL_PLAIN_DEFINE_HPP
