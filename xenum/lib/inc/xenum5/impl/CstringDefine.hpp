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
 * Define all the data and functions of a single custom property, implemented in header.
 */
// FIXME: Implement hdr. Using src impl for now.
#define _XENUM5_CSTRING_HDR_DEFINE(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, STORENAME, CTXT, Z)	\
	_XENUM5_CSTRING_SRC_DEFINE(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, STORENAME, CTXT, Z)	\


// ======================================= MAIN (SRC) ===========================================
/**
 * Define all the data and functions of a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DEFINE(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, STORENAME, CTXT, Z)	\
	_XENUM5_CSTRING_SRC_DEFL(PNAME, DEPTH, PDEF, LOCALSCOPE, CTXT, Z)			\
	_XENUM5_CSTRING_SRC_DEFS(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, STORENAME, CTXT, Z)	\

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
			_XENUM5_CSTRING_SRC_DEFL_FUNCS(DEPTH, _XENUM5_CTXT_GET_DECL(CTXT), CTXT, Z)	\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace LOCALSCOPE)						\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


/**
 * Define the functions declared in the store class.
 */
#define _XENUM5_CSTRING_SRC_DEFS(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, STORENAME, CTXT, Z)	\
	_XENUM5_CSTRING_SRC_DEFS_FUNCS(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, STORENAME, CTXT, Z)	\


// ====================================== VALUES (SRC) ==========================================
/**
 * Define the string values.
 */
#define _XENUM5_CSTRING_SRC_DEFL_VALUES(PNAME, PDEF, CTXT, Z)					\
	_XENUM5_PROP_DECL_VALUE_TYPE(PNAME, PDEF)						\
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


// ==================================== LOCAL FUNCTIONS ========================================
/**
 * Define the local-ns functions related to a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DEFL_FUNCS(DEPTH, DECL, CTXT, Z)					\
	using Enum = _XENUM5_DECL_GET_SCOPE(DECL)_XENUM5_CNTNR_NAME(DECL)::_enum;		_XENUM5_NWLN \
	/* INC() because Nodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_DEFINE_GET_NODE(BOOST_PP_INC(DEPTH), CTXT, Z)				\


// ==================================== STORE FUNCTIONS ========================================
/**
 * Define the store class functions related to a single custom property.
 */
#define _XENUM5_CSTRING_SRC_DEFS_FUNCS(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, STORENAME, CTXT, Z)	\
	/* INC() because Nodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_SRC_DEFINE_GET_SIZE(BOOST_PP_INC(DEPTH), CTXT, Z)				\
	_XENUM5_CSTRING_SRC_DEFS_GET_VALUE(PNAME, DEPTH, PDEF, LOCALSCOPE ::, SCOPE, STORENAME, Z)	\


// ============================ get${PNAME}() ================================
/**
 * Define get${propname}() value getter.
 */
#define _XENUM5_CSTRING_SRC_DEFS_GET_VALUE(PNAME, DEPTH, PDEF, LOCALSCOPE, SCOPE, STORENAME, Z)	\
	const _XENUM5_PDEF_GET_PARM_TYPE(PDEF)							\
	SCOPE STORENAME :: BOOST_PP_CAT(get, PNAME) (						\
		_XENUM5_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, DEPTH, Z)		\
	)											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return &(									\
			(const _XENUM5_PDEF_GET_PARM_TYPE(PDEF))				\
			& LOCALSCOPE BOOST_PP_CAT(PNAME, Values)				\
		)[										\
			LOCALSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (		\
				_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(DEPTH), Z)		\
			)									\
			.index									\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN


// =========================== _check() ==============================
/**
 * Worker for _XENUM5_PROP_CHECK_CSTRING().
 * Define final checks on data structures, for implementation in header.
 */
// FIXME: Implement hdr. Using src impl for now.
#define _XENUM5_CSTRING_HDR_CHECK(PNAME, PDEF, LOCALSCOPE, SCOPE, STORENAME, Z)			\
	_XENUM5_CSTRING_SRC_CHECK(PNAME, PDEF, LOCALSCOPE, SCOPE, STORENAME, Z)			\


/**
 * Worker for _XENUM5_PROP_CHECK_CSTRING().
 * Define final checks on data structures, for implementation in source.
 */
#define _XENUM5_CSTRING_SRC_CHECK(PNAME, PDEF, LOCALSCOPE, SCOPE, STORENAME, Z)			\
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

/*
_XENUM5_CSTRING_CHECK: PNAME _XENUM5_NWLN \
*/


#endif // _XENUM5_IMPL_CSTRING_DEFINE_HPP
