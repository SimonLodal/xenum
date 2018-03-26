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
#define _XENUM4_CSTRING_DEFINE(CTXT, PROPDEF, SCOPE, CNTNRNAME, PROPNAME, Z)			\
	/* The symbols should never become visible outside this source unit. */			\
	namespace {										\
	/* Also wrap in named namespace to prevent name clashes. */				\
	namespace BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(_xenum_internal__, CNTNRNAME), __), PROPNAME) {	NWLN \
		_XENUM4_CSTRING_DEFINE_VALUES(CTXT, PROPDEF, PROPNAME, Z)			\
		_XENUM4_CSTRING_DEFINE_NODES(CTXT, PROPDEF, PROPNAME, Z)			\
		_XENUM4_CSTRING_DEFL_FUNCS(PROPDEF, CTXT, Z)					\
	}}											NWLN \
	_XENUM4_CSTRING_DEFS_FUNCS(								\
		PROPNAME,									\
		_XENUM4_PROPDEF_GET_DEPTH(PROPDEF),						\
		SCOPE,										\
		_XENUM4_STORE_NAME(_XENUM4_CTXT_GET_DECL(CTXT)),				\
		CNTNRNAME,									\
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
	_XENUM4_CSTRING_VALUES_STRUCT(CTXT, PROPDEF, PROPNAME)						\
	_XENUM4_CSTRING_VALUES_DATA(CTXT, PROPNAME)						\

/**
 * Worker for _XENUM4_CSTRING_DEFINE_VALUES().
 * Declares the ${propname}_Values_t struct.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_VALUES_STRUCT(CTXT, PROPDEF, PROPNAME)					\
IND1	typedef _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF) BOOST_PP_CAT(PROPNAME, _t);		NWLN \
IND1	typedef struct {									NWLN \
		_XENUM4_PROP_ITER_VALUES(_XENUM4_CSTRING_VALUE_NAME, CTXT)			\
IND1	} BOOST_PP_CAT(PROPNAME, _Values_t);							\
	NWLN

/**
 * Worker for _XENUM4_CSTRING_VALUES_STRUCT(); loop function for each data node.
 * Declares a single value field.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_VALUE_NAME(ITERPOS, NODE, CTXT)						\
IND2	BOOST_PP_CAT(_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)), _t) 		\
	_XENUM4_PROP_GEN_NODE_NAME(CTXT, _XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS))	\
	[sizeof(_XENUM4_PROP_GET_VALUE(NODE, CTXT))]; NWLN

/**
 * Worker for _XENUM4_CSTRING_DEFINE_VALUES().
 * Defines the ${propname}_Values struct.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_VALUES_DATA(CTXT, PROPNAME)						\
IND1	constexpr BOOST_PP_CAT(PROPNAME, _Values_t) BOOST_PP_CAT(PROPNAME, _Values) = {		NWLN \
		_XENUM4_PROP_ITER_VALUES(_XENUM4_CSTRING_DEFINE_VALUE, CTXT)			\
IND1	};											NWLN

/**
 * Callback worker for values iteration.
 * Defines a single data value of a custom property.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFINE_VALUE(ITERPOS, NODE, CTXT)					\
IND2	_XENUM4_PROP_GET_VALUE(NODE, CTXT),							NWLN


// ========================================= NODES =============================================
/**
 * Worker for _XENUM4_CSTRING_DEFINE().
 * Defines the indexnodes. Note: Called even when depth==0; for cstrings (contrary to "plain")
 * we always need an indexnodes table since each string needs to be referenced by an indexnode.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFINE_NODES(CTXT, PROPDEF, PROPNAME, Z)				\
IND1	constexpr size_t BOOST_PP_CAT(PROPNAME, _ValuesSize) = 					\
		sizeof(BOOST_PP_CAT(PROPNAME, _Values_t));					NWLN \
IND1	constexpr size_t BOOST_PP_CAT(PROPNAME, _NodesSize) = 0					\
		_XENUM4_CALL_VALS(_XENUM4_CSTRING_COUNT_NODES, CTXT);				NWLN \
IND1	typedef typename ::_XENUM4_NS::SelectInt< ::_XENUM4_NS::cmax(				\
			BOOST_PP_CAT(PROPNAME, _ValuesSize),					\
			BOOST_PP_CAT(PROPNAME, _NodesSize)					\
		) >::type BOOST_PP_CAT(PROPNAME, _Index_t);					NWLN \
IND1	typedef ::_XENUM4_NS::IndexNode<BOOST_PP_CAT(PROPNAME, _Index_t)>			\
		BOOST_PP_CAT(PROPNAME, _IndexNode_t);						NWLN \
	_XENUM4_CSTRING_NODES_NAMES(CTXT, PROPDEF, PROPNAME, Z)					\
	_XENUM4_CSTRING_NODES_DATA(CTXT, PROPDEF, PROPNAME, Z)					\


/*
IND1	constexpr const BOOST_PP_CAT(PROPNAME, _IndexNode_t)					\
		BOOST_PP_CAT(PROPNAME, _Nodes) [BOOST_PP_CAT(PROPNAME, _NodesSize)] = {		NWLN \
		_XENUM4_CSTRING_ITER_NODES(_XENUM4_CSTRING_NODE_DATA, CTXT)			\
IND1	};											NWLN
*/


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
 * identical layout; that the placement of node data in the _Nodes table match the names
 * in the _NodeNames_t struct.
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
 * Declares the ${propname}_NodeNames_t struct that contains a name for each index in the
 * ${propname}_nodes_ table.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODES_NAMES(CTXT, PROPDEF, PROPNAME, Z)					\
IND1	typedef struct {									NWLN \
		_XENUM4_CSTRING_ITER_NODES(_XENUM4_CSTRING_NODE_NAME, CTXT)			\
IND1	} BOOST_PP_CAT(PROPNAME, _NodeNames_t);							NWLN \

/**
 * Worker for _XENUM4_CSTRING_NODES_NAMES().
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_NAME(ITERPOS, NODE, CTXT)						\
IND2	BOOST_PP_CAT(_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)), _IndexNode_t)	\
	_XENUM4_PROP_GEN_NODE_NAME(								\
		CTXT,										\
		_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)				\
	)											\
	; NWLN
/*
_CSTRING_NODE_NAME: iterpos={_XENUM4_TUPLETREE_ITERPOS_DUMP(ITERPOS)} node=[NODE] ctxt=[CTXT] NWLN \
*/


// =========================== NODES DATA TABLE ==============================
/**
 * Worker for _XENUM4_CSTRING_DEFINE_NODES().
 * Defines the ${propname}_Nodes node-data table.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODES_DATA(CTXT, PROPDEF, PROPNAME, Z)					\
IND1	constexpr BOOST_PP_CAT(PROPNAME, _IndexNode_t) BOOST_PP_CAT(PROPNAME, _Nodes) [] =	\
	{											NWLN \
		_XENUM4_CSTRING_ITER_NODES(_XENUM4_CSTRING_NODE_DATA, CTXT)			\
IND1	};											NWLN \
	/* Name struct and data table must be identical, and it can not hurt to check */	\
IND1	static_assert(										\
		sizeof(BOOST_PP_CAT(PROPNAME, _NodeNames_t)) == 				\
		sizeof(BOOST_PP_CAT(PROPNAME, _Nodes)),						\
		"Struct/array size mismatch (_NodeNames_t / _Nodes)."				\
	);											\
	NWLN


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
IND2	{											\
		/* Size */									\
		sizeof(_XENUM4_PROP_GET_VALUE(NODE, CTXT)),					\
		/* Index */									\
		_XENUM4_CSTRING_NODE_DATA_0_INDEX(						\
			_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),			\
			_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),		\
			CTXT									\
		)										\
	},											\
	NWLN
/*
_CSTRING_NODE_DATA_0: iterpos={_XENUM4_TUPLETREE_ITERPOS_DUMP(ITERPOS)} node=[NODE] NWLN \
*/

/**
 * Worker for _XENUM4_CSTRING_NODE_DATA_0().
 * Define IndexNode.index as an offset expression into a Values_t struct.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_DATA_0_INDEX(INDEXPATH, PROPNAME, CTXT)				\
	((intptr_t)&((BOOST_PP_CAT(PROPNAME, _Values_t)*)0)->					\
	_XENUM4_PROP_GEN_NODE_NAME(CTXT, INDEXPATH))


/**
 * Worker for _XENUM4_CSTRING_NODE_DATA().
 * Define a node for level>0.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_DATA_1(ITERPOS, NODE, CTXT)					\
IND2	{											\
		/* Size */									\
		_XENUM4_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS),				\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM4_CSTRING_NODE_DATA_1_INDEX_,					\
			BOOST_PP_BOOL(_XENUM4_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS))	\
		) (ITERPOS, CTXT)								\
	},											\
	NWLN
/*
_CSTRING_NODE_DATA_1: iterpos={_XENUM4_TUPLETREE_ITERPOS_DUMP(ITERPOS)} node=[NODE] NWLN \
*/

/**
 * Worker for _XENUM4_CSTRING_NODE_DATA_1().
 * Define IndexNode.index to 0 since node has no children.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_NODE_DATA_1_INDEX_0(ITERPOS, CTXT)						\
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
	(((intptr_t)&((BOOST_PP_CAT(PROPNAME, _NodeNames_t)*)0)->				\
	_XENUM4_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0)))			\
	/ sizeof(BOOST_PP_CAT(PROPNAME, _IndexNode_t)))


// ==================================== LOCAL FUNCTIONS ========================================
/**
 * Worker for _XENUM4_CSTRING_DEFINE().
 * Defines the local functions (in anon namespace, not part of any class) related to a
 * single custom property.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFL_FUNCS(PROPDEF, CTXT, Z)						\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because _Nodes also has indexnodes for the leaf string values */	\
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
		_XENUM4_DECL_GET_SCOPE(_XENUM4_CTXT_GET_DECL(CTXT)),				\
		_XENUM4_DECL_GET_CNTNRNAME(_XENUM4_CTXT_GET_DECL(CTXT)),			\
		Z										\
	)

/**
 * Worker for _XENUM4_CSTRING_DEFL_GET_NODE().
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFL_GET_NODE_I1(PROPNAME, LEVEL, SCOPE, CNTNRNAME, Z)			\
IND1	BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const					\
	BOOST_PP_CAT(PROPNAME, _IndexNode_t&)							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM4_PROP_GEN_INDEX0_PARMS(							\
			SCOPE CNTNRNAME :: Enum,						\
			BOOST_PP_CAT(PROPNAME, _Index_t),					\
			LEVEL,									\
			Z									\
		)										\
	)											NWLN \
IND1	{											NWLN \
IND2		return BOOST_PP_CAT(PROPNAME, _Nodes)[						\
			_XENUM4_PROP_GEN_NODE_INDEXING(						\
				PROPNAME,							\
				BOOST_PP_CAT(PROPNAME, _Index_t),				\
				LEVEL,								\
				Z								\
			)									\
		];										NWLN \
IND1	}											NWLN


// ==================================== STORE FUNCTIONS ========================================
/**
 * Worker for _XENUM4_CSTRING_DEFINE().
 * Defines the store class functions related to a single custom property.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFS_FUNCS(PROPNAME, DEPTH, SCOPE, STORENAME, CNTNRNAME, CTXT, PROPDEF, Z)	\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because _Nodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM4_CSTRING_DEFS_GET_SIZE,							\
		CTXT										\
	)											\
	_XENUM4_CSTRING_DEFS_GET_VALUE(								\
		PROPNAME,									\
		DEPTH,										\
		BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(_xenum_internal__, CNTNRNAME), __), PROPNAME) ::,	\
		SCOPE,										\
		STORENAME,									\
		CNTNRNAME,									\
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
		_XENUM4_DECL_GET_CNTNRNAME(_XENUM4_CTXT_GET_DECL(CTXT)),			\
		Z										\
	)

/**
 * Worker for _XENUM4_CSTRING_DEFS_GET_SIZE().
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFS_GET_SIZE_I1(PROPNAME, LEVEL, SCOPE, STORENAME, CNTNRNAME, Z)	\
	const size_t										\
	SCOPE STORENAME :: BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
		_XENUM4_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::_Enum, size_t, LEVEL, Z)		\
	) {											NWLN \
IND1		return										\
		BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(_xenum_internal__, CNTNRNAME), __), PROPNAME) ::	\
		BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (				\
			_XENUM4_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(LEVEL), Z)			\
		)										\
		.size;										NWLN \
	}											NWLN


// =========================== get${PROPNAME}() ==============================
/**
 * Worker for _XENUM4_CSTRING_DEFS_FUNCS().
 * Defines get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DEFS_GET_VALUE(PROPNAME, DEPTH, LOCALSCOPE, SCOPE, STORENAME, CNTNRNAME, PROPDEF, Z)	\
	const _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF)*						\
	SCOPE STORENAME :: BOOST_PP_CAT(get, PROPNAME) (					\
		_XENUM4_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::_Enum, size_t, DEPTH, Z)		\
	) {											NWLN \
IND1		return &(									\
			(const _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF)*)				\
			& LOCALSCOPE BOOST_PP_CAT(PROPNAME, _Values)				\
		)[										\
			LOCALSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (		\
				_XENUM4_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(DEPTH), Z)		\
			)									\
			.index									\
		];										NWLN \
	}											NWLN


#endif // _XENUM4_IMPL_CSTRING_DEFINE_HPP
