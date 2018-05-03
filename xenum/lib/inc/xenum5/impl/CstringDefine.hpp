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
#define _XENUM5_CSTRING_HDR_DEFINE(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, SNAME, CTXT, Z)	\
	/* FIXME: Also define NodesSize - ? */							\
	constexpr const										\
		SCOPE SNAME :: BOOST_PP_CAT(PNAME, Value)					\
		SCOPE SNAME :: BOOST_PP_CAT(PNAME, Values)					\
		[];										_XENUM5_NWLN \
	constexpr const										\
		SCOPE SNAME :: BOOST_PP_CAT(PNAME, Node)					\
		SCOPE SNAME :: BOOST_PP_CAT(PNAME, Nodes)					\
		[];										_XENUM5_NWLN \


// ======================================= MAIN (SRC) ===========================================
/**
 * Define all the data and functions of a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DEFINE(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, SNAME, CTXT, Z)	\
	_XENUM5_CSTRING_SRC_DEFL(PNAME, DEPTH, PDEF, LOCALSCOPE, CTXT, Z)			\
	_XENUM5_CSTRING_SRC_DEFS(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, SNAME, CTXT, Z)		\

/**
 * Define the local data and functions.
 */
#define _XENUM5_CSTRING_SRC_DEFL(PNAME, DEPTH, PDEF, LOCALSCOPE, CTXT, Z)			\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace LOCALSCOPE {								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			_XENUM5_CSTRING_SRC_DEFL_VALUES(PNAME, PDEF, CTXT, Z)			\
			_XENUM5_CSTRING_SRC_DEFL_NODES(PNAME, CTXT, Z)				\
			_XENUM5_CSTRING_SRC_DEFL_FUNCS(DEPTH, _XENUM5_CTXT_XDCL(CTXT), CTXT, Z)	\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace LOCALSCOPE)						\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


/**
 * Define the functions declared in the store class.
 */
#define _XENUM5_CSTRING_SRC_DEFS(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, SNAME, CTXT, Z)		\
	_XENUM5_CSTRING_SRC_DEFS_FUNCS(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, SNAME, CTXT, Z)	\


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
	using Enum = _XENUM5_XDCL_SCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_enum;			_XENUM5_NWLN \
	/* INC() because Nodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_DEFINE_GET_NODE(BOOST_PP_INC(DEPTH), CTXT, Z)				\


// ================================== STORE FUNCTIONS (SRC) =====================================
/**
 * Define the store class functions related to a single custom property.
 */
#define _XENUM5_CSTRING_SRC_DEFS_FUNCS(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, SNAME, CTXT, Z)	\
	/* INC() because Nodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_SRC_DEFINE_GET_SIZE(BOOST_PP_INC(DEPTH), CTXT, Z)				\
	_XENUM5_CSTRING_SRC_DEFS_GET_VALUE(PNAME, DEPTH, PDEF, LOCALSCOPE ::, SCOPE, SNAME, Z)	\


// ========================= get${PNAME}() (SRC) =============================
/**
 * Define get${propname}() value getter.
 */
#define _XENUM5_CSTRING_SRC_DEFS_GET_VALUE(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, SNAME, Z)	\
	const _XENUM5_PDEF_PARM_TYPE(PDEF)							\
	SCOPE SNAME :: BOOST_PP_CAT(get, PNAME) (						\
		_XENUM5_PROP_GEN_INDEX0_PARMS(SCOPE SNAME::Enum,				\
			SCOPE SNAME::BOOST_PP_CAT(PNAME, Index), DEPTH, Z)			\
	) BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return & LOCALSCOPE BOOST_PP_CAT(PNAME, Values)[				\
			LOCALSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (		\
				_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(DEPTH), Z)		\
			)									\
			.index									\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN


// =============================== _check() ==================================
/**
 * Define final checks on data structures, for implementation in header.
 */
#define _XENUM5_CSTRING_HDR_CHECK(PNAME, PDEF, LOCALSCOPE, SCOPE, SNAME, Z)			\
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
#define _XENUM5_CSTRING_SRC_CHECK(PNAME, PDEF, LOCALSCOPE, SCOPE, SNAME, Z)			\
	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PNAME, NodeNames)) ==				\
		LOCALSCOPE::BOOST_PP_CAT(PNAME, NodesSize) *					\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PNAME, Node)),					\
		"BUG: Struct size mismatch (NodeNames / NodesSize)."				\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PNAME, Nodes)) ==				\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PNAME, NodeNames)),				\
		"BUG: Struct/array size mismatch (Nodes / NodeNames)."				\
	);											_XENUM5_NWLN \


#endif // _XENUM5_IMPL_CSTRING_DEFINE_HPP
