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


// ======================================= MAIN (HDR) ===========================================
/**
 * Define the data of a single custom property, for "cstring" data types, implemented in header.
 */
#define _XENUM5_CSTRING_HDR_DEFINE(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
	/* FIXME: Also define NodesSize - ? */							\
	constexpr const										\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Value)					\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Values)					\
		[];										_XENUM5_NWLN \
	constexpr const										\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Node)					\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Nodes)					\
		[];										_XENUM5_NWLN \


// ======================================= MAIN (SRC) ===========================================
/**
 * Define all the data and functions of a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DEFINE(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
	_XENUM5_CSTRING_SRC_DEFL(PNAME, DEPTH, PDEF, LSCOPE, CTXT, Z)				\
	_XENUM5_CSTRING_SRC_DEFS(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\

/**
 * Define the local data and functions.
 */
#define _XENUM5_CSTRING_SRC_DEFL(PNAME, DEPTH, PDEF, LSCOPE, CTXT, Z)				\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace LSCOPE {								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			_XENUM5_CSTRING_SRC_DEFL_VALUES(PNAME, PDEF, CTXT, Z)			\
			_XENUM5_CSTRING_SRC_DEFL_NODES(PNAME, CTXT, Z)				\
			_XENUM5_CSTRING_SRC_DEFL_FUNCS(DEPTH, _XENUM5_CTXT_XDCL(CTXT), CTXT, Z)	\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace LSCOPE)						\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


/**
 * Define the functions declared in the store class.
 */
#define _XENUM5_CSTRING_SRC_DEFS(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
	_XENUM5_CSTRING_SRC_DEFS_FUNCS(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\


// ====================================== VALUES (SRC) ==========================================
/**
 * Define the string values.
 */
#define _XENUM5_CSTRING_SRC_DEFL_VALUES(PNAME, PDEF, CTXT, Z)					\
	_XENUM5_PROP_DECLARE_VALUE_TYPE(PNAME, PDEF)						\
	_XENUM5_CSTRING_DECLARE_VALUENAMES(PNAME, CTXT)						\
	_XENUM5_CSTRING_DEFINE_VALUES(, PNAME, CTXT)						\


// ======================================= NODES (SRC) ==========================================
/**
 * Define the indexnodes. Note: Called even when depth==0; for cstrings (contrary to "plain")
 * we always need an indexnodes table since each string needs to be referenced by an indexnode.
 */
#define _XENUM5_CSTRING_SRC_DEFL_NODES(PNAME, CTXT, Z)						\
	_XENUM5_CSTRING_DEFINE_NODESSIZE(, PNAME, CTXT)						\
	_XENUM5_PROP_DECLARE_INDEX_TYPE(PNAME)							\
	_XENUM5_PROP_DECLARE_NODE_TYPE(PNAME)							\
	_XENUM5_CSTRING_DECLARE_NODENAMES(PNAME, CTXT)						\
	_XENUM5_CSTRING_DEFINE_NODES(, PNAME, CTXT)						\


// ================================== LOCAL FUNCTIONS (SRC) =====================================
/**
 * Define the local-ns functions related to a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DEFL_FUNCS(DEPTH, XDCL, CTXT, Z)					\
	_XENUM5_DOC(Alias the native enum into this scope.)					\
	using Enum = _XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_enum;			_XENUM5_NWLN \
	/* INC() because Nodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_DEFINE_GET_NODE(BOOST_PP_INC(DEPTH), CTXT, Z)				\


// ================================== STORE FUNCTIONS (SRC) =====================================
/**
 * Define the store class functions related to a single custom property.
 */
#define _XENUM5_CSTRING_SRC_DEFS_FUNCS(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	/* INC() because Nodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_SRC_DEFINE_GET_SIZE(BOOST_PP_INC(DEPTH), CTXT, Z)				\
	_XENUM5_CSTRING_SRC_DEFS_GET_VALUE(PNAME, DEPTH, PDEF, LSCOPE ::, DSCOPE, SNAME, Z)	\


// ========================= get${PNAME}() (SRC) =============================
/**
 * Define get${propname}() value getter.
 */
#define _XENUM5_CSTRING_SRC_DEFS_GET_VALUE(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, Z)	\
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


// =============================== _check() ==================================
// FIXME: Merge into one, just set LSCOPE empty.
/**
 * Define final checks on data structures, for implementation in header.
 */
#define _XENUM5_CSTRING_HDR_CHECK(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
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
#define _XENUM5_CSTRING_SRC_CHECK(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
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


// =============================== _dbginfo() ==================================
/**
 * Define debug info, for implementation in header.
 */
#define _XENUM5_CSTRING_HDR_DBGINFO(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
	std::cout<<BOOST_PP_STRINGIZE(PNAME)<<" (HDR):"<<std::endl				\
		<<"\tsizeof(BOOST_PP_CAT(PNAME, Values)) = "<<sizeof(BOOST_PP_CAT(PNAME, Values))<<std::endl	\
		<<"\tsizeof(BOOST_PP_CAT(PNAME, ValueNames)) = "<<sizeof(BOOST_PP_CAT(PNAME, ValueNames))<<std::endl	\
		;										_XENUM5_NWLN \


/**
 * Define debug info, for implementation in source.
 */
#define _XENUM5_CSTRING_SRC_DBGINFO(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)			\
	std::cout<<BOOST_PP_STRINGIZE(PNAME)<<" (SRC):"<<std::endl				\
		<<"\tsizeof(LSCOPE::BOOST_PP_CAT(PNAME, Values)) = "<<sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Values))<<std::endl	\
		<<"\tsizeof(LSCOPE::BOOST_PP_CAT(PNAME, ValueNames)) = "<<sizeof(LSCOPE::BOOST_PP_CAT(PNAME, ValueNames))<<std::endl	\
		;										_XENUM5_NWLN \


#endif // _XENUM5_IMPL_CSTRING_DEFINE_HPP
