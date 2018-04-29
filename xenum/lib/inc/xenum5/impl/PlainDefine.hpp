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


// ======================================= MAIN (HDR) ===========================================
/**
 * Worker for _XENUM5_PROP_DEFINE_PLAIN().
 * Define the data of a single custom property, for "plain" data types, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DEFINE(PROPNAME, PROPDEF, SCOPE, STORENAME, Z)			\
	/* FIXME: Also define NodesSize - ? */							\
	constexpr const										\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Value)				\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Values)				\
		[];										_XENUM5_NWLN \
	BOOST_PP_CAT(										\
		_XENUM5_PLAIN_HDR_DEFINE_,							\
		BOOST_PP_BOOL(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF))				\
	) (PROPNAME, SCOPE, STORENAME)

/**
 * Define nothing since the custom property has depth==0.
 */
#define _XENUM5_PLAIN_HDR_DEFINE_0(PROPNAME, SCOPE, STORENAME)


/**
 * Worker for _XENUM5_PLAIN_HDR_DEFINE().
 * Define the data of a single multilevel custom property, when depth!=0.
 */
#define _XENUM5_PLAIN_HDR_DEFINE_1(PROPNAME, SCOPE, STORENAME)					\
	constexpr const										\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Node)					\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Nodes)				\
		[];										_XENUM5_NWLN \


// ======================================= MAIN (SRC) ===========================================
/**
 * Worker for _XENUM5_PROP_DEFINE_PLAIN().
 * Define all the data and functions of a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DEFINE(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_PLAIN_SRC_DEFL(PROPNAME, PROPDEF, DECL, CTXT, Z)				\
	_XENUM5_PLAIN_SRC_DEFS(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)				\

/**
 * Define the local data and functions.
 */
#define _XENUM5_PLAIN_SRC_DEFL(PROPNAME, PROPDEF, DECL, CTXT, Z)				\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME) {				_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			_XENUM5_PLAIN_SRC_DEFL_VALUES(PROPNAME, PROPDEF, CTXT, Z)		\
			BOOST_PP_CAT(_XENUM5_PLAIN_SRC_DEFL, BOOST_PP_BOOL(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF))) \
				(PROPNAME, PROPDEF, DECL, CTXT, Z)				\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME))			\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


/**
 * Worker for _XENUM5_PLAIN_SRC_DEFL(), for depth==0.
 * Values are already defined as a single plain array of values, directly indexed
 * by enum value; no need for name struct or nodes table.
 */
#define _XENUM5_PLAIN_SRC_DEFL0(PROPNAME, PROPDEF, DECL, CTXT, Z)				\

/**
 * Worker for _XENUM5_PLAIN_SRC_DEFL(), for depth==1.
 */
#define _XENUM5_PLAIN_SRC_DEFL1(PROPNAME, PROPDEF, DECL, CTXT, Z)				\
	_XENUM5_PLAIN_SRC_DEFL1_NODES(PROPNAME, CTXT, Z)					\
	_XENUM5_PLAIN_SRC_DEFL1_FUNCS(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF), DECL, CTXT, Z)	\


/**
 * Define the functions declared in the store class.
 */
#define _XENUM5_PLAIN_SRC_DEFS(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)				\
	_XENUM5_PLAIN_SRC_DEFS_FUNCS(								\
		PROPNAME,									\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		SCOPE,										\
		_XENUM5_STORE_NAME(DECL),							\
		DECL,										\
		CTXT,										\
		Z										\
	)


// ====================================== VALUES (SRC) ==========================================
/**
 * Define the values.
 */
#define _XENUM5_PLAIN_SRC_DEFL_VALUES(PROPNAME, PROPDEF, CTXT, Z)				\
	_XENUM5_PROP_DECL_VALUE_TYPE(PROPNAME, PROPDEF)						\
	_XENUM5_PLAIN_DEFINE_VALUES(, PROPNAME, CTXT)						\


// ======================================= NODES (SRC) ==========================================
/**
 * Define the index nodes, for depth!=0; declare a name struct and define an array of nodes
 * with same layout.
 */
#define _XENUM5_PLAIN_SRC_DEFL1_NODES(PROPNAME, CTXT, Z)					\
	_XENUM5_PLAIN_DEFINE_NODESSIZE(, PROPNAME, CTXT)					\
	_XENUM5_PROP_DECLARE_INDEX_TYPE(PROPNAME)						\
	_XENUM5_PROP_DECLARE_NODE_TYPE(PROPNAME)						\
	_XENUM5_PLAIN_DECLARE_NODENAMES(PROPNAME, CTXT)						\
	_XENUM5_PLAIN_DECLARE_VALUENAMES(PROPNAME, CTXT)					\
	_XENUM5_PLAIN_DEFINE_NODES(, PROPNAME, CTXT)						\


// ==================================== LOCAL FUNCTIONS ========================================
/**
 * Define the local-ns functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DEFL1_FUNCS(DEPTH, DECL, CTXT, Z)					\
	using Enum = _XENUM5_DECL_GET_SCOPE(DECL)_XENUM5_CNTNR_NAME(DECL)::_enum;		_XENUM5_NWLN \
	_XENUM5_PROP_DEFINE_GET_NODE(DEPTH, CTXT, Z)						\


// ==================================== STORE FUNCTIONS ========================================
/**
 * Define the store class functions related to a single custom property.
 */
#define _XENUM5_PLAIN_SRC_DEFS_FUNCS(PROPNAME, DEPTH, PROPDEF, SCOPE, STORENAME, DECL, CTXT, Z)	\
	_XENUM5_PROP_SRC_DEFINE_GET_SIZE(DEPTH, CTXT, Z)					\
	_XENUM5_PLAIN_SRC_DEFS_GET_VALUE(							\
		PROPNAME, DEPTH, PROPDEF, _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME) ::,		\
		SCOPE, STORENAME, Z)								\


// =========================== get${PROPNAME}() ==============================
/**
 * Define get${propname}() value getter. For source implementation.
 */
#define _XENUM5_PLAIN_SRC_DEFS_GET_VALUE(PROPNAME, DEPTH, PROPDEF, LOCALSCOPE, SCOPE, STORENAME, Z)	\
	const _XENUM5_PROPDEF_GET_PARM_TYPE(PROPDEF)						\
	SCOPE STORENAME :: BOOST_PP_CAT(get, PROPNAME) (					\
		_XENUM5_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, DEPTH, Z)		\
	)											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return LOCALSCOPE BOOST_PP_CAT(PROPNAME, Values)[				\
			BOOST_PP_CAT(_XENUM5_PLAIN_SRC_DEFS_GET_VALUE_, BOOST_PP_BOOL(DEPTH))	\
				(PROPNAME, DEPTH, LOCALSCOPE, SCOPE, STORENAME, Z)	\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN

/**
 * Define get${propname}() indexing for depth==0.
 */
#define _XENUM5_PLAIN_SRC_DEFS_GET_VALUE_0(PROPNAME, DEPTH, LOCALSCOPE, SCOPE, STORENAME, Z)	\
	SCOPE STORENAME::getIndex(index0)							\

/**
 * Define get${propname}() indexing for depth!=0.
 */
#define _XENUM5_PLAIN_SRC_DEFS_GET_VALUE_1(PROPNAME, DEPTH, LOCALSCOPE, SCOPE, STORENAME, Z)	\
	LOCALSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (				\
		_XENUM5_PROP_GEN_INDEX0_ARGS(DEPTH, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, DEPTH))						\


// =========================== _check() ==============================
/**
 * Worker for _XENUM5_PROP_CHECK_PLAIN().
 * Define final checks on data structures, for implementation in header.
 */
#define _XENUM5_PLAIN_HDR_CHECK(PROPNAME, PROPDEF, LOCALSCOPE, SCOPE, STORENAME, Z)		\
	BOOST_PP_CAT(_XENUM5_PLAIN_HDR_CHECK_, BOOST_PP_BOOL(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF)))	\
		(PROPNAME, SCOPE, STORENAME)

/**
 * Worker for _XENUM5_PLAIN_CHECK().
 * For depth==0, there is no final checks to be made.
 */
#define _XENUM5_PLAIN_HDR_CHECK_0(PROPNAME, SCOPE, STORENAME)					\

/**
 * Worker for _XENUM5_PLAIN_CHECK().
 * For depth!=0, do check sizes of generated data.
 */
#define _XENUM5_PLAIN_HDR_CHECK_1(PROPNAME, SCOPE, STORENAME)					\
	static_assert(										\
		sizeof(SCOPE STORENAME::BOOST_PP_CAT(PROPNAME, ValueNames)) ==			\
		sizeof(SCOPE STORENAME::BOOST_PP_CAT(PROPNAME, Values)),			\
		"Struct/array size mismatch (ValueNames / Values)."				\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(SCOPE STORENAME::BOOST_PP_CAT(PROPNAME, NodeNames)) ==			\
		sizeof(SCOPE STORENAME::BOOST_PP_CAT(PROPNAME, Nodes)),				\
		"Struct/array size mismatch (NodeNames / Nodes)."				\
	);											_XENUM5_NWLN \


/**
 * Worker for _XENUM5_PROP_CHECK_PLAIN().
 * Define final checks on data structures, for implementation in source.
 */
#define _XENUM5_PLAIN_SRC_CHECK(PROPNAME, PROPDEF, LOCALSCOPE, SCOPE, STORENAME, Z)		\
	BOOST_PP_CAT(_XENUM5_PLAIN_SRC_CHECK_, BOOST_PP_BOOL(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF)))	\
		(PROPNAME, LOCALSCOPE, SCOPE, STORENAME)					\

/**
 * Worker for _XENUM5_PLAIN_SRC_CHECK(), for depth==0.
 */
#define _XENUM5_PLAIN_SRC_CHECK_0(PROPNAME, LOCALSCOPE, SCOPE, STORENAME)			\
	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Values)) ==				\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Value)) * SCOPE STORENAME::size,	\
		"Data size mismatch (Values / enum-size)."					\
	);											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_PLAIN_SRC_CHECK(), for depth!=0.
 */
#define _XENUM5_PLAIN_SRC_CHECK_1(PROPNAME, LOCALSCOPE, SCOPE, STORENAME)			\
	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, NodeNames)) ==			\
		LOCALSCOPE::BOOST_PP_CAT(PROPNAME, NodesSize) *					\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Node)),				\
		"Struct size mismatch (NodeNames / NodesSize)."					\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Nodes)) ==				\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, NodeNames)),				\
		"Array/struct size mismatch (Nodes / NodeNames)."				\
	);											_XENUM5_NWLN \


#endif // _XENUM5_IMPL_PLAIN_DEFINE_HPP
