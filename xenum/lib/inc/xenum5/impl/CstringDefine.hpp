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


/**
 * Worker for _XENUM5_PROP_DEFINE_CSTRING().
 * Define all the data and functions of a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_DEFINE(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)				\
	/* The symbols should never become visible outside this source unit. */			\
	namespace {										\
	/* Also wrap in named namespace to prevent name clashes. */				\
	namespace _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME) {					_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CSTRING_DEFINE_VALUES(PROPNAME, PROPDEF, CTXT, Z)			\
		_XENUM5_CSTRING_DEFINE_NODES(PROPNAME, PROPDEF, CTXT, Z)			\
		_XENUM5_CSTRING_DEFL_FUNCS(PROPDEF, CTXT, Z)					\
		_XENUM5_INDENT_DEC								\
	}}											_XENUM5_NWLN \
	_XENUM5_CSTRING_DEFS_FUNCS(								\
		PROPNAME,									\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		SCOPE,										\
		_XENUM5_STORE_NAME(_XENUM5_CTXT_GET_DECL(CTXT)),				\
		PROPDEF,									\
		CTXT,										\
		Z										\
	)


// ========================================= VALUES ============================================
/**
 * Worker for _XENUM5_CSTRING_DEFINE().
 * Define the string values.
 */
#define _XENUM5_CSTRING_DEFINE_VALUES(PROPNAME, PROPDEF, CTXT, Z)				\
	_XENUM5_CSTRING_VALUES_STRUCT(PROPNAME, PROPDEF, CTXT)					\
	_XENUM5_CSTRING_VALUES_DATA(PROPNAME, CTXT)						\

/**
 * Worker for _XENUM5_CSTRING_DEFINE_VALUES().
 * Declare the ${propname}Values_t struct.
 */
#define _XENUM5_CSTRING_VALUES_STRUCT(PROPNAME, PROPDEF, CTXT)					\
	_XENUM5_PROP_DECL_VALUE_TYPE(PROPNAME, PROPDEF)						\
	typedef struct {									_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_CSTRING_VALUE_NAME, CTXT)			\
		_XENUM5_INDENT_DEC								\
	} BOOST_PP_CAT(PROPNAME, Values_t);							_XENUM5_NWLN \

/**
 * Worker for _XENUM5_CSTRING_VALUES_STRUCT(); loop function for each data node.
 * Declare a single value field.
 */
#define _XENUM5_CSTRING_VALUE_NAME(ITERPOS, NODE, CTXT)						\
	BOOST_PP_CAT(_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)), Value) 		\
	_XENUM5_PROP_GEN_NODE_NAME(CTXT, _XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS))	\
	[sizeof(_XENUM5_PROP_GET_VALUE(NODE, _XENUM5_CTXT_GET_PROPDEF(CTXT)))];			_XENUM5_NWLN \

/**
 * Worker for _XENUM5_CSTRING_DEFINE_VALUES().
 * Define the ${propname}Values struct.
 */
#define _XENUM5_CSTRING_VALUES_DATA(PROPNAME, CTXT)						\
	constexpr BOOST_PP_CAT(PROPNAME, Values_t) BOOST_PP_CAT(PROPNAME, Values) = {		_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_CSTRING_DEFINE_VALUE, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Callback worker for values iteration.
 * Define a single data value of a custom property.
 */
#define _XENUM5_CSTRING_DEFINE_VALUE(ITERPOS, NODE, CTXT)					\
	_XENUM5_PROP_GET_VALUE(NODE, _XENUM5_CTXT_GET_PROPDEF(CTXT)),				_XENUM5_NWLN


// ========================================= NODES =============================================
/**
 * Worker for _XENUM5_CSTRING_DEFINE().
 * Define the indexnodes. Note: Called even when depth==0; for cstrings (contrary to "plain")
 * we always need an indexnodes table since each string needs to be referenced by an indexnode.
 */
#define _XENUM5_CSTRING_DEFINE_NODES(PROPNAME, PROPDEF, CTXT, Z)				\
	constexpr size_t BOOST_PP_CAT(PROPNAME, ValuesSize) = 					\
		sizeof(BOOST_PP_CAT(PROPNAME, Values_t));					_XENUM5_NWLN \
	constexpr size_t BOOST_PP_CAT(PROPNAME, IndexSize) = 0					\
		_XENUM5_CALL_VALS(_XENUM5_CSTRING_COUNT_NODES, CTXT);				_XENUM5_NWLN \
	typedef typename ::_XENUM5_NS::SelectInt< ::_XENUM5_NS::cmax(				\
			BOOST_PP_CAT(PROPNAME, ValuesSize),					\
			BOOST_PP_CAT(PROPNAME, IndexSize)					\
		) >::type BOOST_PP_CAT(PROPNAME, Index);					_XENUM5_NWLN \
	typedef ::_XENUM5_NS::IndexNode<BOOST_PP_CAT(PROPNAME, Index)>				\
		BOOST_PP_CAT(PROPNAME, IndexNode);						_XENUM5_NWLN \
	_XENUM5_CSTRING_NODES_NAMES(PROPNAME, PROPDEF, CTXT, Z)					\
	_XENUM5_CSTRING_NODES_DATA(PROPNAME, PROPDEF, CTXT, Z)					\


// ============================= COUNT NODES =================================
/**
 * Worker for _XENUM5_CSTRING_DEFINE_NODES(). Called as XENUM_VALS_* callback.
 * Count the indexnodes of a single custom property, for a single enum value.
 * Counts all nodes, including leaf values, since each string value needs to be referenced
 * by an indexnode.
 */
#define _XENUM5_CSTRING_COUNT_NODES(CTXT, IDENT, ...)						\
	+_XENUM5_TUPLETREE_ITERATE_DEPTH_CALC(							\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM5_PROPDEF_GET_DEPTH(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		(_XENUM5_CSTRING_COUNT_NODES_ADD),						\
		CTXT,										\
		0										\
	)											\

/**
 * Callback for _XENUM5_CSTRING_COUNT_NODES() iteration. Called for each node.
 * Add +1 for each indexnode.
 */
#define _XENUM5_CSTRING_COUNT_NODES_ADD(ITERPOS, NODE, CTXT, STATE)				\
	BOOST_PP_INC(STATE)


// ============================== NODE NAMES =================================
/**
 * Worker for _XENUM5_CSTRING_DEFINE_NODES().
 * Declare the ${propname}NodeNames struct that contains a name for each index in the
 * ${propname}IndexNodes table.
 */
#define _XENUM5_CSTRING_NODES_NAMES(PROPNAME, PROPDEF, CTXT, Z)					\
	typedef struct {									_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CSTRING_ITER_NODES(_XENUM5_CSTRING_NODE_NAME, CTXT)			\
		_XENUM5_INDENT_DEC								\
	} BOOST_PP_CAT(PROPNAME, NodeNames);							_XENUM5_NWLN \

/**
 * Worker for _XENUM5_CSTRING_NODES_NAMES().
 */
#define _XENUM5_CSTRING_NODE_NAME(ITERPOS, NODE, CTXT)						\
	BOOST_PP_CAT(_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)), IndexNode)	\
	_XENUM5_PROP_GEN_NODE_NAME(								\
		CTXT,										\
		_XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)				\
	);											_XENUM5_NWLN
/*
_CSTRING_NODE_NAME: iterpos={_XENUM5_TUPLETREE_ITERPOS_DUMP(ITERPOS)} node=[NODE] ctxt=[CTXT] _XENUM5_NWLN \
*/


// =========================== NODES DATA TABLE ==============================
/**
 * Worker for _XENUM5_CSTRING_DEFINE_NODES().
 * Define the ${propname}IndexNodes node-data table.
 */
#define _XENUM5_CSTRING_NODES_DATA(PROPNAME, PROPDEF, CTXT, Z)					\
	constexpr BOOST_PP_CAT(PROPNAME, IndexNode) BOOST_PP_CAT(PROPNAME, IndexNodes) [] = {	_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CSTRING_ITER_NODES(_XENUM5_CSTRING_NODE_DATA, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_CSTRING_NODES_DATA().
 */
#define _XENUM5_CSTRING_NODE_DATA(ITERPOS, NODE, CTXT)						\
	BOOST_PP_CAT(										\
		_XENUM5_CSTRING_NODE_DATA_,							\
		BOOST_PP_BOOL(_XENUM5_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS))			\
	) (ITERPOS, NODE, CTXT)									\


/**
 * Worker for _XENUM5_CSTRING_NODE_DATA().
 * Define a node for level==0.
 */
#define _XENUM5_CSTRING_NODE_DATA_0(ITERPOS, NODE, CTXT)					\
	{											\
		/* Size */									\
		sizeof(_XENUM5_PROP_GET_VALUE(NODE, _XENUM5_CTXT_GET_PROPDEF(CTXT))),		\
		/* Index */									\
		_XENUM5_CSTRING_NODE_DATA_0_INDEX(						\
			_XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),			\
			_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),		\
			CTXT									\
		)										\
	},											_XENUM5_NWLN \

/*
_CSTRING_NODE_DATA_0: iterpos={_XENUM5_TUPLETREE_ITERPOS_DUMP(ITERPOS)} node=[NODE] _XENUM5_NWLN \
*/

/**
 * Worker for _XENUM5_CSTRING_NODE_DATA_0().
 * Define IndexNode.index as an offset expression into a Values_t struct.
 */
#define _XENUM5_CSTRING_NODE_DATA_0_INDEX(INDEXPATH, PROPNAME, CTXT)				\
	(offsetof(BOOST_PP_CAT(PROPNAME, Values_t), _XENUM5_PROP_GEN_NODE_NAME(CTXT, INDEXPATH)))


/**
 * Worker for _XENUM5_CSTRING_NODE_DATA().
 * Define a node for level>0.
 */
#define _XENUM5_CSTRING_NODE_DATA_1(ITERPOS, NODE, CTXT)					\
	{											\
		/* Size */									\
		_XENUM5_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS),				\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM5_CSTRING_NODE_DATA_1_INDEX_,					\
			BOOST_PP_BOOL(_XENUM5_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS))	\
		) (ITERPOS, CTXT)								\
	},											_XENUM5_NWLN \

/*
_CSTRING_NODE_DATA_1: iterpos={_XENUM5_TUPLETREE_ITERPOS_DUMP(ITERPOS)} node=[NODE] _XENUM5_NWLN \
*/

/**
 * Worker for _XENUM5_CSTRING_NODE_DATA_1().
 * Define IndexNode.index to 0 since node has no children.
 */
#define _XENUM5_CSTRING_NODE_DATA_1_INDEX_0(ITERPOS, CTXT)					\
	0

/**
 * Worker for _XENUM5_CSTRING_NODE_DATA_1().
 * Define IndexNode.index as an offset expression into an IndexNode table.
 */
#define _XENUM5_CSTRING_NODE_DATA_1_INDEX_1(ITERPOS, CTXT)					\
	_XENUM5_CSTRING_NODE_DATA_1_INDEX_1_DO(							\
		_XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),				\
		_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		CTXT										\
	)

/**
 * Worker for _XENUM5_CSTRING_NODE_VALUE_INDEX_1().
 */
#define _XENUM5_CSTRING_NODE_DATA_1_INDEX_1_DO(INDEXPATH, PROPNAME, CTXT)			\
	(offsetof(										\
		BOOST_PP_CAT(PROPNAME, NodeNames),						\
		_XENUM5_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0))		\
	) / sizeof(BOOST_PP_CAT(PROPNAME, IndexNode)))


// ==================================== LOCAL FUNCTIONS ========================================
/**
 * Worker for _XENUM5_CSTRING_DEFINE().
 * Define the local functions (in local anon namespace, not part of any class) related to a
 * single custom property.
 */
#define _XENUM5_CSTRING_DEFL_FUNCS(PROPDEF, CTXT, Z)						\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because IndexNodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF)),				\
		_XENUM5_CSTRING_DEFL_GET_NODE,							\
		CTXT										\
	)											\


// ============================== getNode() ==================================
/**
 * Worker for _XENUM5_CSTRING_DEFINE_FUNCS_LV().
 * Define get${propname}Node() getters.
 */
#define _XENUM5_CSTRING_DEFL_GET_NODE(Z, N, CTXT)						\
	_XENUM5_CSTRING_DEFL_GET_NODE_I1(							\
		_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Worker for _XENUM5_CSTRING_DEFL_GET_NODE().
 */
#define _XENUM5_CSTRING_DEFL_GET_NODE_I1(PROPNAME, LEVEL, DECL, Z)				\
	BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const					\
	BOOST_PP_CAT(PROPNAME, IndexNode&)							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM5_PROP_GEN_INDEX0_PARMS(							\
			_XENUM5_DECL_GET_SCOPE(DECL)_XENUM5_CNTNR_NAME(DECL)::_enum,		\
			BOOST_PP_CAT(PROPNAME, Index),						\
			LEVEL,									\
			Z									\
		)										\
	)											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return BOOST_PP_CAT(PROPNAME, IndexNodes)[					\
			_XENUM5_PROP_GEN_NODE_INDEXING(						\
				PROPNAME,							\
				BOOST_PP_CAT(PROPNAME, Index),					\
				LEVEL,								\
				Z								\
			)									\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN


// ==================================== STORE FUNCTIONS ========================================
/**
 * Worker for _XENUM5_CSTRING_DEFINE().
 * Define the store class functions related to a single custom property.
 */
#define _XENUM5_CSTRING_DEFS_FUNCS(PROPNAME, DEPTH, SCOPE, STORENAME, PROPDEF, CTXT, Z)		\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because IndexNodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM5_CSTRING_DEFS_GET_SIZE,							\
		CTXT										\
	)											\
	_XENUM5_CSTRING_DEFS_GET_VALUE(								\
		PROPNAME,									\
		DEPTH,										\
		_XENUM5_IMPL_LOCAL_NS(_XENUM5_CTXT_GET_DECL(CTXT), PROPNAME) ::,		\
		SCOPE,										\
		STORENAME,									\
		PROPDEF,									\
		Z										\
	)


// ============================== getSize() ==================================
/**
 * Callback worker for _XENUM5_CSTRING_DEFS_FUNCS().
 * Define get${propname}Size() getters.
 */
#define _XENUM5_CSTRING_DEFS_GET_SIZE(Z, N, CTXT)						\
	_XENUM5_CSTRING_DEFS_GET_SIZE_I1(							\
		_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		_XENUM5_DECL_GET_SCOPE(_XENUM5_CTXT_GET_DECL(CTXT)),				\
		_XENUM5_STORE_NAME(_XENUM5_CTXT_GET_DECL(CTXT)),				\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Worker for _XENUM5_CSTRING_DEFS_GET_SIZE().
 */
#define _XENUM5_CSTRING_DEFS_GET_SIZE_I1(PROPNAME, LEVEL, SCOPE, STORENAME, DECL, Z)		\
	size_t											\
	SCOPE STORENAME :: BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
		_XENUM5_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, LEVEL, Z)		\
	)											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return										\
		_XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME) ::					\
		BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (				\
			_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(LEVEL), Z)			\
		)										\
		.size;										_XENUM5_NWLN \
	}											_XENUM5_NWLN


// =========================== get${PROPNAME}() ==============================
/**
 * Worker for _XENUM5_CSTRING_DEFS_FUNCS().
 * Define get${propname}() value getter.
 */
#define _XENUM5_CSTRING_DEFS_GET_VALUE(PROPNAME, DEPTH, LOCALSCOPE, SCOPE, STORENAME, PROPDEF, Z)	\
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
 * Define final checks on data structures.
 */
#define _XENUM5_CSTRING_CHECK(PROPNAME, PROPDEF, DECL)						\
	static_assert(										\
		sizeof(_XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, NodeNames)) ==	\
		sizeof(_XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, IndexNode)) *	\
		_XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, IndexSize),	\
		"BUG: Struct size mismatch (NodeNames / IndexSize)."				\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(_XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, NodeNames)) ==	\
		sizeof(_XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, IndexNodes)),	\
		"BUG: Struct/array size mismatch (NodeNames / IndexNodes)."			\
	);											_XENUM5_NWLN \

/*
_XENUM5_CSTRING_CHECK: PROPNAME _XENUM5_NWLN \
*/


#endif // _XENUM5_IMPL_CSTRING_DEFINE_HPP
