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
#define _XENUM5_CSTRING_HDR_DEFINE(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_CSTRING_SRC_DEFINE(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\



// ======================================= MAIN (SRC) ===========================================
/**
 * Define all the data and functions of a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DEFINE(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_CSTRING_SRC_DEFL(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_CSTRING_SRC_DEFS(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\

/**
 * Define the local data and functions.
 */
#define _XENUM5_CSTRING_SRC_DEFL(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME) {				_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			_XENUM5_CSTRING_SRC_DEFL_VALUES(PROPNAME, PROPDEF, CTXT, Z)		\
			_XENUM5_CSTRING_SRC_DEFL_NODES(PROPNAME, PROPDEF, CTXT, Z)		\
			_XENUM5_CSTRING_SRC_DEFL_FUNCS(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF), DECL, CTXT, Z)	\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME))			\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


/**
 * Define the functions declared in the store class.
 */
#define _XENUM5_CSTRING_SRC_DEFS(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_CSTRING_SRC_DEFS_FUNCS(								\
		PROPNAME,									\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		SCOPE,										\
		_XENUM5_STORE_NAME(_XENUM5_CTXT_GET_DECL(CTXT)),				\
		CTXT,										\
		Z										\
	)


// ====================================== VALUES (SRC) ==========================================
/**
 * Define the string values.
 */
#define _XENUM5_CSTRING_SRC_DEFL_VALUES(PROPNAME, PROPDEF, CTXT, Z)				\
	_XENUM5_PROP_DECL_VALUE_TYPE(PROPNAME, PROPDEF)						\
	_XENUM5_CSTRING_DECLARE_VALUENAMES(PROPNAME, CTXT)					\
	_XENUM5_CSTRING_DEFINE_VALUES(, PROPNAME, CTXT)						\


// ======================================= NODES (SRC) ==========================================
/**
 * Define the indexnodes. Note: Called even when depth==0; for cstrings (contrary to "plain")
 * we always need an indexnodes table since each string needs to be referenced by an indexnode.
 */
#define _XENUM5_CSTRING_SRC_DEFL_NODES(PROPNAME, PROPDEF, CTXT, Z)				\
	_XENUM5_CSTRING_DEFINE_NODESSIZE(, PROPNAME, CTXT)					\
	_XENUM5_PROP_DECLARE_INDEX_TYPE(PROPNAME)						\
	_XENUM5_PROP_DECLARE_NODE_TYPE(PROPNAME)						\
	_XENUM5_CSTRING_DECLARE_NODENAMES(PROPNAME, CTXT)					\
	_XENUM5_CSTRING_DEFINE_NODES(, PROPNAME, CTXT)						\


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
#define _XENUM5_CSTRING_SRC_DEFS_FUNCS(PROPNAME, DEPTH, PROPDEF, SCOPE, STORENAME, CTXT, Z)	\
	/* INC() because Nodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_SRC_DEFINE_GET_SIZE(BOOST_PP_INC(DEPTH), CTXT, Z)				\
	_XENUM5_CSTRING_SRC_DEFS_GET_VALUE(							\
		PROPNAME, DEPTH, PROPDEF,							\
		_XENUM5_IMPL_LOCAL_NS(_XENUM5_CTXT_GET_DECL(CTXT), PROPNAME) ::,		\
		SCOPE, STORENAME, Z)								\


// =========================== get${PROPNAME}() ==============================
/**
 * Define get${propname}() value getter.
 */
#define _XENUM5_CSTRING_SRC_DEFS_GET_VALUE(PROPNAME, DEPTH, PROPDEF, LOCALSCOPE, SCOPE, STORENAME, Z)	\
	const _XENUM5_PROPDEF_GET_PARM_TYPE(PROPDEF)						\
	SCOPE STORENAME :: BOOST_PP_CAT(get, PROPNAME) (					\
		_XENUM5_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, DEPTH, Z)		\
	)											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return &(									\
			(const _XENUM5_PROPDEF_GET_PARM_TYPE(PROPDEF))				\
			& LOCALSCOPE BOOST_PP_CAT(PROPNAME, Values)				\
		)[										\
			LOCALSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (		\
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
#define _XENUM5_CSTRING_HDR_CHECK(PROPNAME, PROPDEF, LOCALSCOPE, SCOPE, STORENAME, Z)		\
	_XENUM5_CSTRING_SRC_CHECK(PROPNAME, PROPDEF, LOCALSCOPE, SCOPE, STORENAME, Z)		\


/**
 * Worker for _XENUM5_PROP_CHECK_CSTRING().
 * Define final checks on data structures, for implementation in source.
 */
#define _XENUM5_CSTRING_SRC_CHECK(PROPNAME, PROPDEF, LOCALSCOPE, SCOPE, STORENAME, Z)		\
	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, NodeNames)) ==			\
		LOCALSCOPE::BOOST_PP_CAT(PROPNAME, NodesSize) *					\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Node)),				\
		"BUG: Struct size mismatch (NodeNames / NodesSize)."				\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Nodes)) ==				\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, NodeNames)),				\
		"BUG: Struct/array size mismatch (Nodes / NodeNames)."				\
	);											_XENUM5_NWLN \

/*
_XENUM5_CSTRING_CHECK: PROPNAME _XENUM5_NWLN \
*/


#endif // _XENUM5_IMPL_CSTRING_DEFINE_HPP
