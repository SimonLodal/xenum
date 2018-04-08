/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of definitions for "plain" data type category.
 */
#ifndef _XENUM4_IMPL_PLAIN_DEFINE_HPP
#define _XENUM4_IMPL_PLAIN_DEFINE_HPP


// ======================================== DATA ================================================
/**
 * Worker for _XENUM4_PROP_DEFINE_PLAIN().
 * Defines all the data and functions of a single custom property, for "plain" data types.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DEFINE(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)			\
	/* FIXME: Also define the ValuesSize and IndexSize integers - ? */			\
	constexpr const										\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Value)					\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Values)				\
		/* Explicit size not needed */							\
		/*[SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, ValuesSize)] = */			\
		[] =										\
		{										NWLN \
			_XENUM4_PLAIN_VALUES_DATA(CTXT)						\
		};										NWLN \
	BOOST_PP_CAT(										\
		_XENUM4_PLAIN_DATA_MULTILEVEL_,							\
		BOOST_PP_BOOL(_XENUM4_PROPDEF_GET_DEPTH(PROPDEF))				\
	) (CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)

/* DEBUG
_PLAIN_DEFINE_DATA: ctxt=CTXT scope=SCOPE storename=STORENAME valuename=VALUENAME inttype=INTTYPE propdef=PROPDEF NWLN \
*/


/**
 * Defines nothing since the custom property has depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DATA_MULTILEVEL_0(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)


/**
 * Worker for _XENUM4_PLAIN_DEFINE_DATA().
 * Defines the data of a single multilevel custom property (only when depth!=0).
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DATA_MULTILEVEL_1(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\
	_XENUM4_PLAIN_VALUES_NAMES(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME)			\
	_XENUM4_PLAIN_NODES_NAMES(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)			\
	_XENUM4_PLAIN_NODES_DATA(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)			\


// ========================== VALUES DATA TABLE ==============================
/**
 * Worker for _XENUM4_PLAIN_DEFINE_DATA().
 * Defines the ${propname}Values data table.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_VALUES_DATA(CTXT)								\
	_XENUM4_PROP_ITER_VALUES(_XENUM4_PLAIN_VALUE_DATA, CTXT)

/**
 * Callback worker for values iteration.
 * Defines a single data value of a custom property.
 * @hideinitializer
 */
// FIXME: What kind of error does it produce when there is no value and no default?
#define _XENUM4_PLAIN_VALUE_DATA(ITERPOS, NODE, CTXT)						\
IND1	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(NODE),							\
		_XENUM4_PROPDEF_GET_DEFAULTVALUE(_XENUM4_CTXT_GET_PROPDEF(CTXT)),		\
		NODE										\
	)											\
, NWLN


// ============================= VALUE NAMES =================================
/**
 * Worker for _XENUM4_PLAIN_DATA_MULTILEVEL_1().
 * Declares the ${propname}ValueNames struct that contains a name for each index in the
 * ${propname}Values table.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_VALUES_NAMES(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME)			\
	typedef struct										\
	{ NWLN											\
		_XENUM4_PROP_ITER_VALUES(_XENUM4_PLAIN_VALUE_NAME, CTXT)			\
	} BOOST_PP_CAT(PROPNAME, ValueNames);							\
	NWLN											\
	/* Data and names should match, but it can not hurt to check it again */		\
	static_assert(										\
		sizeof(BOOST_PP_CAT(PROPNAME, ValueNames)) == 					\
		sizeof(SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Values)),			\
		"Struct/array size mismatch (ValueNames/Values)."				\
	);											\
	NWLN

/**
 * Worker for _XENUM4_PLAIN_VALUES_NAMES(); loop function for each data node.
 * Declares a single value name.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_VALUE_NAME(ITERPOS, NODE, CTXT)						\
IND1	_XENUM4_DECL_GET_SCOPE(_XENUM4_CTXT_GET_DECL(CTXT))					\
	_XENUM4_STORE_NAME(_XENUM4_CTXT_GET_DECL(CTXT))						\
	:: BOOST_PP_CAT(_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)), Value)	\
	_XENUM4_PROP_GEN_NODE_NAME(CTXT, _XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS))	\
	; NWLN


// ==================== COMMON LOOP FOR NODE ITERATION =======================
/**
 * Iterate data structure using ITERATE_FLAT_GEN(); execute callback for each branch-node.
 * Used by both nodenames- and nodedata-generation iterations, to ensure that they have
 * identical layout; that the placement of node data in the IndexNodes table match the names
 * in the NodeNames struct.
 * Note: The root nodes (enum-values) must appear first in the tables so they can be directly
 * indexed by an enum-value.
 * Note: All node iteration sets depth-=1 because we are not iterating leaf values, only nodes.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_ITER_NODES(CALLBACK, CTXT)						\
	/* First, execute callback only for the enum values (root nodes), so they are */	\
	/* executed in one block. */								\
	_XENUM4_CALL_VALS(									\
		_XENUM4_PLAIN_ITER_NODES_ROOT,							\
		_XENUM4_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)											\
	/* Secondly, iterate all non-root nodes. */						\
	_XENUM4_CALL_VALS(									\
		_XENUM4_PLAIN_ITER_NODES_NONROOT,						\
		_XENUM4_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)

/**
 * Callback worker for _XENUM4_PLAIN_ITER_NODES(); loop function for each root node
 * (enum-value). Execute the callback only for the root node (no further iteration).
 * @hideinitializer
 */
#define _XENUM4_PLAIN_ITER_NODES_ROOT(CTXT, IDENT, ...)						\
	_XENUM4_PLAIN_ITER_NODES_ROOT_I1							\
	(											\
		_XENUM4_GET_VARARG(_XENUM4_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		BOOST_PP_DEC(_XENUM4_PROPDEF_GET_DEPTH(_XENUM4_CTXT_GET_PROPDEF(CTXT))),	\
		_XENUM4_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM4_PLAIN_ITER_NODES_ROOT().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_ITER_NODES_ROOT_I1(DATA, DEPTH, CTXT)					\
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
 * Callback worker for _XENUM4_PLAIN_ITER_NODES(); loop function for each node.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_ITER_NODES_NONROOT(CTXT, IDENT, ...)					\
	_XENUM4_PLAIN_ITER_NODES_NONROOT_I1							\
	(											\
		_XENUM4_GET_VARARG(_XENUM4_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM4_PROPDEF_GET_DEPTH(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM4_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM4_PLAIN_ITER_NODES_NONROOT().
 * Execute tupletree iteration.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_ITER_NODES_NONROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM4_TUPLETREE_ITERATE_FLAT_GEN(							\
		DATA,										\
		/* We do not want to iterate leaf values */					\
		BOOST_PP_DEC(DEPTH),								\
		(_XENUM4_CTXT_GET_CALLBACK(CTXT), _XENUM4_PLAIN_ITER_NODES_NONROOT_FLT),	\
		CTXT										\
	)

/**
 * Filter function for non-root nodes iteration.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_ITER_NODES_NONROOT_FLT(ITERPOS, NODE, CTXT)				\
	BOOST_PP_AND(										\
		BOOST_PP_NOT(_XENUM4_TUPLETREE_ITERPOS_GET_NEXTCHILD(ITERPOS)),			\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)))	\
	)


// ============================== NODE NAMES =================================
/**
 * Worker for _XENUM4_PLAIN_DATA_MULTILEVEL_1().
 * Declares the ${propname}NodeNames struct that contains a name for each index in the
 * ${propname}IndexNodes table.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_NODES_NAMES(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)			\
	typedef struct										\
	{ NWLN											\
		_XENUM4_PLAIN_ITER_NODES(_XENUM4_PLAIN_NODE_NAME, CTXT)				\
	} BOOST_PP_CAT(PROPNAME, NodeNames);							\
	NWLN

/**
 * Worker for _XENUM4_PLAIN_NODES_NAMES().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_NODE_NAME(ITERPOS, NODE, CTXT)						\
IND1	_XENUM4_DECL_GET_SCOPE(_XENUM4_CTXT_GET_DECL(CTXT))					\
	_XENUM4_STORE_NAME(_XENUM4_CTXT_GET_DECL(CTXT))						\
	:: BOOST_PP_CAT(_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)), IndexNode)	\
	_XENUM4_PROP_GEN_NODE_NAME(								\
		CTXT,										\
		_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)				\
	)											\
	; NWLN
/*
_PLAIN_NODE_NAME: iterpos={_XENUM4_TUPLETREE_ITERPOS_DUMP(ITERPOS)} node=[NODE] ctxt=[CTXT] NWLN \
*/


// =========================== NODES DATA TABLE ==============================
/**
 * Worker for _XENUM4_PLAIN_DATA_MULTILEVEL_1().
 * Defines the ${propname}IndexNodes node-data table.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_NODES_DATA(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)			\
	constexpr const										\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, IndexNode)				\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, IndexNodes)				\
		/* Explicit size not needed */							\
		/*[SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, IndexSize)] = */			\
		[] =										\
	{ NWLN											\
		_XENUM4_PLAIN_ITER_NODES(_XENUM4_PLAIN_NODE_DATA, CTXT)				\
	};											\
	NWLN											\
	static_assert(										\
		sizeof(BOOST_PP_CAT(PROPNAME, NodeNames)) == 					\
		sizeof(SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, IndexNodes)),			\
		"Struct/array size mismatch (IndexNodes/NodeNames)."				\
	);											\
	NWLN


/**
 * Worker for _XENUM4_PLAIN_NODES_DATA().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_NODE_DATA(ITERPOS, NODE, CTXT)						\
IND1	{											\
		/* Size */									\
		_XENUM4_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS),				\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM4_PLAIN_NODE_DATA_INDEX_,						\
			BOOST_PP_BOOL(_XENUM4_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS))	\
		) (ITERPOS, CTXT)								\
	},											\
	NWLN
/*
_XENUM4_PLAIN_NODE_DATA: iterpos={_XENUM4_TUPLETREE_ITERPOS_DUMP(ITERPOS)} ctxt=[CTXT] node=[NODE] NWLN \
*/

/**
 * Worker for _XENUM4_PLAIN_NODE_DATA().
 * Define IndexNode.index to 0 since node has no children.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_NODE_DATA_INDEX_0(ITERPOS, CTXT)						\
	0

/**
 * Worker for _XENUM4_PLAIN_NODE_DATA().
 * Define IndexNode.index as an offset expression into a names struct.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_NODE_DATA_INDEX_1(ITERPOS, CTXT)						\
	_XENUM4_PLAIN_NODE_DATA_INDEX_1_DO(							\
		CTXT,										\
		_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),				\
		BOOST_PP_IF(									\
			_XENUM4_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS),				\
			NodeNames,								\
			ValueNames								\
		),										\
		BOOST_PP_IF(									\
			_XENUM4_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS),				\
			IndexNode,								\
			Value									\
		)										\
	)

/**
 * Worker for _XENUM4_PLAIN_NODE_VALUE_INDEX_1().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_NODE_DATA_INDEX_1_DO(CTXT, PROPNAME, INDEXPATH, NAMESTRUCT, MEMBERTYPE)	\
	(offsetof(										\
		BOOST_PP_CAT(PROPNAME, NAMESTRUCT),						\
		_XENUM4_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0))		\
	) / sizeof(BOOST_PP_CAT(PROPNAME, MEMBERTYPE)))


// ====================================== DEBUG STUFF ===========================================
/**
 * Define some members for debugging.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DEFINE_DEBUG(CTXT, PROPDEF, Z)						\
	_XENUM4_PLAIN_DEFINE_FUNC_DUMP_NODES(CTXT, PROPDEF, _XENUM4_PROPDEF_GET_NAME(PROPDEF))	\

/**
 * Worker for _XENUM4_PLAIN_DEFINE_DEBUG().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DEFINE_FUNC_DUMP_NODES(CTXT, PROPDEF, PROPNAME)				\

/*
	void _XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_STORE_NAME(DECL)				\
	:: dumpNodes(void) noexcept								NWLN \
	{											NWLN \
IND1		std::cout									NWLN \
IND2			<<BOOST_PP_STRINGIZE(PROPNAME)<<"IndexNodes"				NWLN \
IND2			<<" ("<<BOOST_PP_CAT(PROPNAME, IndexSize)<<"/"<<sizeof(BOOST_PP_CAT(PROPNAME, IndexNodes))<<")"	NWLN \
IND2			<<" sizeof(IndexNode)="<<sizeof(BOOST_PP_CAT(PROPNAME, IndexNode))	NWLN \
IND2			<<":"									NWLN \
IND2			<<std::endl;								NWLN \
IND2		for (BOOST_PP_CAT(PROPNAME, Index) idx=0; idx<BOOST_PP_CAT(PROPNAME, IndexSize); idx++) { NWLN \
IND3			std::cout								NWLN \
IND4				<<"\t"								NWLN \
IND4				<<" ["<<(int)idx<<"]"						NWLN \
IND4				<<" {"								NWLN \
IND4				<<(int)BOOST_PP_CAT(PROPNAME, IndexNodes)[idx].size		NWLN \
IND4				<<","								NWLN \
IND4				<<(int)BOOST_PP_CAT(PROPNAME, IndexNodes)[idx].index		NWLN \
IND4				<<"}"								NWLN \
IND4				<<std::endl;							NWLN \
IND2		}										NWLN \
	}											NWLN \
*/


#endif // _XENUM4_IMPL_PLAIN_DEFINE_HPP
