/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of definitions for "cstring" data type category.
 */
#ifndef _XENUM4_IMPL_CSTRING_DEFINE_HPP
#define _XENUM4_IMPL_CSTRING_DEFINE_HPP


/**
 * Worker for _XENUM4_PROP_DEFINE_CSTRING().
 * Defines all the data and functions of a single custom property, for "cstring" data types.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFINE(CTXT, DECL, PROPDEF, SCOPE, PROPNAME, Z)				\
	/* The symbols should never become visible outside this source unit. */			\
	namespace {										\
	/* Also wrap in named namespace to prevent name clashes. */				\
	namespace _XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME) {					_XENUM4_NWLN \
		_XENUM4_INDENT_INC								\
		_XENUM4_CSTRING_DEFINE_VALUES(CTXT, PROPDEF, PROPNAME, Z)			\
		_XENUM4_CSTRING_DEFINE_NODES(CTXT, PROPDEF, PROPNAME, Z)			\
		_XENUM4_CSTRING_DEFL_FUNCS(PROPDEF, CTXT, Z)					\
		_XENUM4_INDENT_DEC								\
	}}											_XENUM4_NWLN \
	_XENUM4_CSTRING_DEFS_FUNCS(								\
		PROPNAME,									\
		_XENUM4_PROPDEF_GET_DEPTH(PROPDEF),						\
		SCOPE,										\
		_XENUM4_STORE_NAME(_XENUM4_CTXT_GET_DECL(CTXT)),				\
		CTXT,										\
		PROPDEF,									\
		Z										\
	)


// ========================================= VALUES ============================================
/**
 * Worker for _XENUM4_CSTRING_DEFINE().
 * Defines the string values.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFINE_VALUES(CTXT, PROPDEF, PROPNAME, Z)				\
	_XENUM4_CSTRING_VALUES_STRUCT(CTXT, PROPDEF, PROPNAME)					\
	_XENUM4_CSTRING_VALUES_DATA(CTXT, PROPNAME)						\

/**
 * Worker for _XENUM4_CSTRING_DEFINE_VALUES().
 * Declares the ${propname}Values_t struct.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_VALUES_STRUCT(CTXT, PROPDEF, PROPNAME)					\
	typedef _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF) BOOST_PP_CAT(PROPNAME, Value);		_XENUM4_NWLN \
	typedef struct {									_XENUM4_NWLN \
		_XENUM4_INDENT_INC								\
		_XENUM4_PROP_ITER_VALUES(_XENUM4_CSTRING_VALUE_NAME, CTXT)			\
		_XENUM4_INDENT_DEC								\
	} BOOST_PP_CAT(PROPNAME, Values_t);							_XENUM4_NWLN \

/**
 * Worker for _XENUM4_CSTRING_VALUES_STRUCT(); loop function for each data node.
 * Declares a single value field.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_VALUE_NAME(ITERPOS, NODE, CTXT)						\
	BOOST_PP_CAT(_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)), Value) 		\
	_XENUM4_PROP_GEN_NODE_NAME(CTXT, _XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS))	\
	[sizeof(_XENUM4_PROP_GET_VALUE(NODE, CTXT))];						_XENUM4_NWLN \

/**
 * Worker for _XENUM4_CSTRING_DEFINE_VALUES().
 * Defines the ${propname}Values struct.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_VALUES_DATA(CTXT, PROPNAME)						\
	constexpr BOOST_PP_CAT(PROPNAME, Values_t) BOOST_PP_CAT(PROPNAME, Values) = {		_XENUM4_NWLN \
		_XENUM4_INDENT_INC								\
		_XENUM4_PROP_ITER_VALUES(_XENUM4_CSTRING_DEFINE_VALUE, CTXT)			\
		_XENUM4_INDENT_DEC								\
	};											_XENUM4_NWLN

/**
 * Callback worker for values iteration.
 * Defines a single data value of a custom property.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFINE_VALUE(ITERPOS, NODE, CTXT)					\
	_XENUM4_PROP_GET_VALUE(NODE, CTXT),							_XENUM4_NWLN


// ========================================= NODES =============================================
/**
 * Worker for _XENUM4_CSTRING_DEFINE().
 * Defines the indexnodes. Note: Called even when depth==0; for cstrings (contrary to "plain")
 * we always need an indexnodes table since each string needs to be referenced by an indexnode.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFINE_NODES(CTXT, PROPDEF, PROPNAME, Z)				\
	constexpr size_t BOOST_PP_CAT(PROPNAME, ValuesSize) = 					\
		sizeof(BOOST_PP_CAT(PROPNAME, Values_t));					_XENUM4_NWLN \
	constexpr size_t BOOST_PP_CAT(PROPNAME, IndexSize) = 0					\
		_XENUM4_CALL_VALS(_XENUM4_CSTRING_COUNT_NODES, CTXT);				_XENUM4_NWLN \
	typedef typename ::_XENUM4_NS::SelectInt< ::_XENUM4_NS::cmax(				\
			BOOST_PP_CAT(PROPNAME, ValuesSize),					\
			BOOST_PP_CAT(PROPNAME, IndexSize)					\
		) >::type BOOST_PP_CAT(PROPNAME, Index);					_XENUM4_NWLN \
	typedef ::_XENUM4_NS::IndexNode<BOOST_PP_CAT(PROPNAME, Index)>				\
		BOOST_PP_CAT(PROPNAME, IndexNode);						_XENUM4_NWLN \
	_XENUM4_CSTRING_NODES_NAMES(CTXT, PROPDEF, PROPNAME, Z)					\
	_XENUM4_CSTRING_NODES_DATA(CTXT, PROPDEF, PROPNAME, Z)					\


// ============================= COUNT NODES =================================
/**
 * Worker for _XENUM4_CSTRING_DEFINE_NODES(). Called as XENUM_VALS_* callback.
 * Counts the indexnodes of a single custom property, for a single enum value.
 * Counts all nodes, including leaf values, since each string value needs to be referenced
 * by an indexnode.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_COUNT_NODES(CTXT, IDENT, ...)						\
	+_XENUM4_TUPLETREE_ITERATE_DEPTH_CALC(							\
		_XENUM4_GET_VARARG(_XENUM4_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM4_PROPDEF_GET_DEPTH(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		(_XENUM4_CSTRING_COUNT_NODES_ADD),						\
		CTXT,										\
		0										\
	)											\

/**
 * Callback for _XENUM4_CSTRING_COUNT_NODES() iteration. Called for each node.
 * Add +1 for each indexnode.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_COUNT_NODES_ADD(ITERPOS, NODE, CTXT, STATE)				\
	BOOST_PP_INC(STATE)


// ==================== COMMON LOOP FOR NODE ITERATION =======================
/**
 * Iterate data structure using ITERATE_FLAT_GEN(); execute callback for each branch-node.
 * Used by both nodenames- and nodedata-generation iterations, to ensure that they have
 * identical layout; that the placement of node data in the IndexNodes table match the names
 * in the NodeNames struct.
 * Note: The root nodes (enum-values) must appear first in the tables so they can be directly
 * indexed by an enum-value.
 * Note: Contrary to _PLAIN_ITER_NODES, this loop iterates all nodes, including the leafs
 * (values), else we could share these functions.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_ITER_NODES(CALLBACK, CTXT)						\
	/* First, execute callback only for the enum values (root nodes), so they are */	\
	/* executed in one block. */								\
	_XENUM4_CALL_VALS(									\
		_XENUM4_CSTRING_ITER_NODES_ROOT,							\
		_XENUM4_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)											\
	/* Secondly, iterate all non-root nodes. */						\
	_XENUM4_CALL_VALS(									\
		_XENUM4_CSTRING_ITER_NODES_NONROOT,						\
		_XENUM4_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)

/**
 * Callback worker for _XENUM4_CSTRING_ITER_NODES(); loop function for each root node
 * (enum-value). Execute the callback only for the root node (no further iteration).
 * @hideinitializer
 */
#define _XENUM4_CSTRING_ITER_NODES_ROOT(CTXT, IDENT, ...)						\
	_XENUM4_CSTRING_ITER_NODES_ROOT_I1							\
	(											\
		_XENUM4_GET_VARARG(_XENUM4_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM4_PROPDEF_GET_DEPTH(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM4_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM4_CSTRING_ITER_NODES_ROOT().
 * @hideinitializer
 */
#define _XENUM4_CSTRING_ITER_NODES_ROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM4_CTXT_GET_CALLBACK(CTXT) (							\
		_XENUM4_TUPLETREE_ITERPOS_INIT(							\
			DEPTH,									\
			,									\
			0,									\
			_XENUM4_GET_TUPLE_SIZE_IF_TUPLE(DATA)					\
		),										\
		_XENUM4_TUPLE_TO_SEQ_COND(DATA, BOOST_PP_BOOL(DEPTH)),				\
		CTXT										\
	)

/**
 * Callback worker for _XENUM4_CSTRING_ITER_NODES(); loop function for each node.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_ITER_NODES_NONROOT(CTXT, IDENT, ...)					\
	_XENUM4_CSTRING_ITER_NODES_NONROOT_I1							\
	(											\
		_XENUM4_GET_VARARG(_XENUM4_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM4_PROPDEF_GET_DEPTH(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM4_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM4_CSTRING_ITER_NODES_NONROOT().
 * Execute tupletree iteration.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_ITER_NODES_NONROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM4_TUPLETREE_ITERATE_FLAT_GEN(							\
		DATA,										\
		DEPTH,										\
		(_XENUM4_CTXT_GET_CALLBACK(CTXT), _XENUM4_CSTRING_ITER_NODES_NONROOT_FLT),	\
		CTXT										\
	)

/**
 * Filter function for non-root nodes iteration.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_ITER_NODES_NONROOT_FLT(ITERPOS, NODE, CTXT)				\
	BOOST_PP_AND(										\
		BOOST_PP_NOT(_XENUM4_TUPLETREE_ITERPOS_GET_NEXTCHILD(ITERPOS)),			\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)))	\
	)


// ============================== NODE NAMES =================================
/**
 * Worker for _XENUM4_CSTRING_DEFINE_NODES().
 * Declares the ${propname}NodeNames struct that contains a name for each index in the
 * ${propname}IndexNodes table.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODES_NAMES(CTXT, PROPDEF, PROPNAME, Z)					\
	typedef struct {									_XENUM4_NWLN \
		_XENUM4_INDENT_INC								\
		_XENUM4_CSTRING_ITER_NODES(_XENUM4_CSTRING_NODE_NAME, CTXT)			\
		_XENUM4_INDENT_DEC								\
	} BOOST_PP_CAT(PROPNAME, NodeNames);							_XENUM4_NWLN \

/**
 * Worker for _XENUM4_CSTRING_NODES_NAMES().
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_NAME(ITERPOS, NODE, CTXT)						\
	BOOST_PP_CAT(_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)), IndexNode)	\
	_XENUM4_PROP_GEN_NODE_NAME(								\
		CTXT,										\
		_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)				\
	);											_XENUM4_NWLN
/*
_CSTRING_NODE_NAME: iterpos={_XENUM4_TUPLETREE_ITERPOS_DUMP(ITERPOS)} node=[NODE] ctxt=[CTXT] _XENUM4_NWLN \
*/


// =========================== NODES DATA TABLE ==============================
/**
 * Worker for _XENUM4_CSTRING_DEFINE_NODES().
 * Defines the ${propname}IndexNodes node-data table.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODES_DATA(CTXT, PROPDEF, PROPNAME, Z)					\
	constexpr BOOST_PP_CAT(PROPNAME, IndexNode) BOOST_PP_CAT(PROPNAME, IndexNodes) [] = {	_XENUM4_NWLN \
		_XENUM4_INDENT_INC								\
		_XENUM4_CSTRING_ITER_NODES(_XENUM4_CSTRING_NODE_DATA, CTXT)			\
		_XENUM4_INDENT_DEC								\
	};											_XENUM4_NWLN \

/**
 * Worker for _XENUM4_CSTRING_NODES_DATA().
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_DATA(ITERPOS, NODE, CTXT)						\
	BOOST_PP_CAT(										\
		_XENUM4_CSTRING_NODE_DATA_,							\
		BOOST_PP_BOOL(_XENUM4_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS))			\
	) (ITERPOS, NODE, CTXT)									\


/**
 * Worker for _XENUM4_CSTRING_NODE_DATA().
 * Define a node for level==0.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_DATA_0(ITERPOS, NODE, CTXT)					\
	{											\
		/* Size */									\
		sizeof(_XENUM4_PROP_GET_VALUE(NODE, CTXT)),					\
		/* Index */									\
		_XENUM4_CSTRING_NODE_DATA_0_INDEX(						\
			_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),			\
			_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),		\
			CTXT									\
		)										\
	},											_XENUM4_NWLN \

/*
_CSTRING_NODE_DATA_0: iterpos={_XENUM4_TUPLETREE_ITERPOS_DUMP(ITERPOS)} node=[NODE] _XENUM4_NWLN \
*/

/**
 * Worker for _XENUM4_CSTRING_NODE_DATA_0().
 * Define IndexNode.index as an offset expression into a Values_t struct.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_DATA_0_INDEX(INDEXPATH, PROPNAME, CTXT)				\
	(offsetof(BOOST_PP_CAT(PROPNAME, Values_t), _XENUM4_PROP_GEN_NODE_NAME(CTXT, INDEXPATH)))


/**
 * Worker for _XENUM4_CSTRING_NODE_DATA().
 * Define a node for level>0.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_DATA_1(ITERPOS, NODE, CTXT)					\
	{											\
		/* Size */									\
		_XENUM4_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS),				\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM4_CSTRING_NODE_DATA_1_INDEX_,					\
			BOOST_PP_BOOL(_XENUM4_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS))	\
		) (ITERPOS, CTXT)								\
	},											_XENUM4_NWLN \

/*
_CSTRING_NODE_DATA_1: iterpos={_XENUM4_TUPLETREE_ITERPOS_DUMP(ITERPOS)} node=[NODE] _XENUM4_NWLN \
*/

/**
 * Worker for _XENUM4_CSTRING_NODE_DATA_1().
 * Define IndexNode.index to 0 since node has no children.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_DATA_1_INDEX_0(ITERPOS, CTXT)					\
	0

/**
 * Worker for _XENUM4_CSTRING_NODE_DATA_1().
 * Define IndexNode.index as an offset expression into an IndexNode table.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_DATA_1_INDEX_1(ITERPOS, CTXT)					\
	_XENUM4_CSTRING_NODE_DATA_1_INDEX_1_DO(							\
		_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),				\
		_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		CTXT										\
	)

/**
 * Worker for _XENUM4_CSTRING_NODE_VALUE_INDEX_1().
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_DATA_1_INDEX_1_DO(INDEXPATH, PROPNAME, CTXT)			\
	(offsetof(										\
		BOOST_PP_CAT(PROPNAME, NodeNames),						\
		_XENUM4_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0))		\
	) / sizeof(BOOST_PP_CAT(PROPNAME, IndexNode)))


// ==================================== LOCAL FUNCTIONS ========================================
/**
 * Worker for _XENUM4_CSTRING_DEFINE().
 * Defines the local functions (in local anon namespace, not part of any class) related to a
 * single custom property.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFL_FUNCS(PROPDEF, CTXT, Z)						\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because IndexNodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(_XENUM4_PROPDEF_GET_DEPTH(PROPDEF)),				\
		_XENUM4_CSTRING_DEFL_GET_NODE,							\
		CTXT										\
	)											\


// ============================== getNode() ==================================
/**
 * Worker for _XENUM4_CSTRING_DEFINE_FUNCS_LV().
 * Defines get${propname}Node() getters.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFL_GET_NODE(Z, N, CTXT)						\
	_XENUM4_CSTRING_DEFL_GET_NODE_I1(							\
		_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		_XENUM4_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Worker for _XENUM4_CSTRING_DEFL_GET_NODE().
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFL_GET_NODE_I1(PROPNAME, LEVEL, DECL, Z)				\
	BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const					\
	BOOST_PP_CAT(PROPNAME, IndexNode&)							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM4_PROP_GEN_INDEX0_PARMS(							\
			_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_CNTNR_NAME(DECL)::_Enum,		\
			BOOST_PP_CAT(PROPNAME, Index),						\
			LEVEL,									\
			Z									\
		)										\
	)											_XENUM4_NWLN \
	{											_XENUM4_NWLN \
		_XENUM4_INDENT_ADD								\
		return BOOST_PP_CAT(PROPNAME, IndexNodes)[					\
			_XENUM4_PROP_GEN_NODE_INDEXING(						\
				PROPNAME,							\
				BOOST_PP_CAT(PROPNAME, Index),					\
				LEVEL,								\
				Z								\
			)									\
		];										_XENUM4_NWLN \
	}											_XENUM4_NWLN


// ==================================== STORE FUNCTIONS ========================================
/**
 * Worker for _XENUM4_CSTRING_DEFINE().
 * Defines the store class functions related to a single custom property.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFS_FUNCS(PROPNAME, DEPTH, SCOPE, STORENAME, CTXT, PROPDEF, Z)		\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because IndexNodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM4_CSTRING_DEFS_GET_SIZE,							\
		CTXT										\
	)											\
	_XENUM4_CSTRING_DEFS_GET_VALUE(								\
		PROPNAME,									\
		DEPTH,										\
		_XENUM4_IMPL_LOCAL_NS(_XENUM4_CTXT_GET_DECL(CTXT), PROPNAME) ::,		\
		SCOPE,										\
		STORENAME,									\
		PROPDEF,									\
		Z										\
	)


// ============================== getSize() ==================================
/**
 * Callback worker for _XENUM4_CSTRING_DEFS_FUNCS().
 * Defines get${propname}Size() getters.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFS_GET_SIZE(Z, N, CTXT)						\
	_XENUM4_CSTRING_DEFS_GET_SIZE_I1(							\
		_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		_XENUM4_DECL_GET_SCOPE(_XENUM4_CTXT_GET_DECL(CTXT)),				\
		_XENUM4_STORE_NAME(_XENUM4_CTXT_GET_DECL(CTXT)),				\
		_XENUM4_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Worker for _XENUM4_CSTRING_DEFS_GET_SIZE().
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFS_GET_SIZE_I1(PROPNAME, LEVEL, SCOPE, STORENAME, DECL, Z)		\
	const size_t										\
	SCOPE STORENAME :: BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
		_XENUM4_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, LEVEL, Z)		\
	)											_XENUM4_NWLN \
	{											_XENUM4_NWLN \
		_XENUM4_INDENT_ADD								\
		return										\
		_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME) ::					\
		BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (				\
			_XENUM4_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(LEVEL), Z)			\
		)										\
		.size;										_XENUM4_NWLN \
	}											_XENUM4_NWLN


// =========================== get${PROPNAME}() ==============================
/**
 * Worker for _XENUM4_CSTRING_DEFS_FUNCS().
 * Defines get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFS_GET_VALUE(PROPNAME, DEPTH, LOCALSCOPE, SCOPE, STORENAME, PROPDEF, Z)	\
	const _XENUM4_PROPDEF_GET_PARM_TYPE(PROPDEF)						\
	SCOPE STORENAME :: BOOST_PP_CAT(get, PROPNAME) (					\
		_XENUM4_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, DEPTH, Z)		\
	)											_XENUM4_NWLN \
	{											_XENUM4_NWLN \
		_XENUM4_INDENT_ADD								\
		return &(									\
			(const _XENUM4_PROPDEF_GET_PARM_TYPE(PROPDEF))				\
			& LOCALSCOPE BOOST_PP_CAT(PROPNAME, Values)				\
		)[										\
			LOCALSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (		\
				_XENUM4_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(DEPTH), Z)		\
			)									\
			.index									\
		];										_XENUM4_NWLN \
	}											_XENUM4_NWLN


// =========================== _check() ==============================
/**
 * Worker for _XENUM4_PROP_CHECK_CSTRING().
 * Defines final checks on data structures.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_CHECK(CXT, DECL, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\
	static_assert(										\
		sizeof(_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, NodeNames)) ==	\
		sizeof(_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, IndexNode)) *	\
		_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, IndexSize),	\
		"BUG: Struct size mismatch (NodeNames / IndexSize)."				\
	);											_XENUM4_NWLN \
	static_assert(										\
		sizeof(_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, NodeNames)) ==	\
		sizeof(_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, IndexNodes)),	\
		"BUG: Struct/array size mismatch (NodeNames / IndexNodes)."			\
	);											_XENUM4_NWLN \

/*
_XENUM4_CSTRING_CHECK: PROPNAME _XENUM4_NWLN \
*/


#endif // _XENUM4_IMPL_CSTRING_DEFINE_HPP
