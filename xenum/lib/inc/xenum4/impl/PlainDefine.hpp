/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of definitions for "plain" data type category.
 *
 * TODO:
 * - HDR and SRC implementations should use more common code.
 */
#ifndef _XENUM4_IMPL_PLAIN_DEFINE_HPP
#define _XENUM4_IMPL_PLAIN_DEFINE_HPP


// ======================================== MAIN ================================================
/**
 * Worker for _XENUM4_PROP_DEFINE_PLAIN().
 * Defines all the data and functions of a single custom property, implemented in source.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFINE(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	BOOST_PP_CAT(_XENUM4_PLAIN_SRC_DEFINE_, BOOST_PP_BOOL(_XENUM4_PROPDEF_GET_DEPTH(PROPDEF)))	\
		(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)					\

/**
 * Worker for _XENUM4_PLAIN_SRC_DEFINE(), for depth==0.
 * For this case, only generate a single plain array of values, directly indexed by enum
 * value; no need for name struct or nodes table.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFINE_0(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM4_PLAIN_SRC_DEFL0(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM4_PLAIN_SRC_DEFS0(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\

/**
 * Generate declarations and definitions that go into local namespace (parts that are
 * not declared in header). For depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL0(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	namespace { namespace _XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME) {				NWLN \
		_XENUM4_PLAIN_SRC_DEFL0_VALUES(PROPNAME, PROPDEF, CTXT, Z)			\
	}}											NWLN \

/**
 * Generate definitions of store class members. For depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFS0(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM4_PLAIN_SRC_DEFS0_FUNCS(								\
		PROPNAME,									\
		PROPDEF,									\
		SCOPE,										\
		_XENUM4_STORE_NAME(DECL),							\
		DECL,										\
		CTXT,										\
		Z										\
	)


/**
 * Worker for _XENUM4_PLAIN_SRC_DEFINE(), for depth!=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFINE_1(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM4_PLAIN_SRC_DEFL1(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM4_PLAIN_SRC_DEFS1(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\

/**
 * Generate declarations and definitions that go into local namespace (parts that are
 * not declared in header). For depth!=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL1(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	namespace { namespace _XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME) {				NWLN \
		_XENUM4_PLAIN_SRC_DEFL1_VALUES(PROPNAME, PROPDEF, CTXT, Z)			\
		_XENUM4_PLAIN_SRC_DEFL1_NODES(PROPNAME, PROPDEF, CTXT, Z)			\
		_XENUM4_PLAIN_SRC_DEFL1_FUNCS(_XENUM4_PROPDEF_GET_DEPTH(PROPDEF), CTXT, Z)	\
	}}											NWLN \


/**
 * Worker for _XENUM4_PLAIN_SRC_DEFINE().
 * Defines the store class functions related to a single custom property, implemented in source.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFS1(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM4_PLAIN_SRC_DEFS1_FUNCS(								\
		PROPNAME,									\
		_XENUM4_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		SCOPE,										\
		_XENUM4_STORE_NAME(DECL),							\
		CTXT,										\
		Z										\
	)


// ===================================== VALUES, COMMON =========================================
/**
 * Callback worker for values iteration.
 * Defines a single data value of a custom property.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_VALUE(ITERPOS, NODE, CTXT)						\
IND2	_XENUM4_PROP_GET_VALUE(NODE, CTXT),							NWLN


// ================================= VALUES (SRC, DEPTH==0) =====================================
/**
 * Define the values, for depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL0_VALUES(PROPNAME, PROPDEF, CTXT, Z)				\
IND1	typedef _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF) BOOST_PP_CAT(PROPNAME, Value);		NWLN \
	_XENUM4_PLAIN_SRC_DEFL0_VALUES_DATA(PROPNAME, CTXT)					\

/**
 * Worker for _XENUM4_PLAIN_SRC_DEFL0_VALUES().
 * Defines the ${propname}Values array.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL0_VALUES_DATA(PROPNAME, CTXT)					\
IND1	constexpr const BOOST_PP_CAT(PROPNAME, Value) BOOST_PP_CAT(PROPNAME, Values)[] = {	NWLN \
		_XENUM4_PROP_ITER_VALUES(_XENUM4_PLAIN_VALUE, CTXT)				\
IND1	};											NWLN


// ================================= VALUES (SRC, DEPTH!=0) =====================================
/**
 * Define the values, for depth!=0; declare a struct and define values as this struct.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL1_VALUES(PROPNAME, PROPDEF, CTXT, Z)				\
IND1	typedef _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF) BOOST_PP_CAT(PROPNAME, Value);		NWLN \
	_XENUM4_PLAIN_SRC_DEFL1_VALUES_STRUCT(PROPNAME, PROPDEF, CTXT)				\
	_XENUM4_PLAIN_SRC_DEFL1_VALUES_DATA(PROPNAME, CTXT)					\

/**
 * Worker for _XENUM4_PLAIN_SRC_DEFL1_VALUES().
 * Declares the ${propname}Values_t struct.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL1_VALUES_STRUCT(PROPNAME, PROPDEF, CTXT)				\
IND1	typedef struct {									NWLN \
		_XENUM4_PROP_ITER_VALUES(_XENUM4_PLAIN_SRC_DEFL1_VALUE_NAME, CTXT)		\
IND1	} BOOST_PP_CAT(PROPNAME, Values_t);							NWLN \

/**
 * Worker for _XENUM4_PLAIN_SRC_DEFL1_VALUES_STRUCT(); loop function for each data node.
 * Declares a single value field.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL1_VALUE_NAME(ITERPOS, NODE, CTXT)					\
IND2	BOOST_PP_CAT(_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)), Value) 		\
	_XENUM4_PROP_GEN_NODE_NAME(CTXT, _XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS));	NWLN \

/**
 * Worker for _XENUM4_PLAIN_SRC_DEFL1_VALUES().
 * Defines the ${propname}Values struct.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL1_VALUES_DATA(PROPNAME, CTXT)					\
IND1	constexpr const BOOST_PP_CAT(PROPNAME, Value) BOOST_PP_CAT(PROPNAME, Values)[] = {	NWLN \
		_XENUM4_PROP_ITER_VALUES(_XENUM4_PLAIN_VALUE, CTXT)				\
IND1	};											NWLN


// ====================================== NODES, COMMON =========================================
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


// ================================== NODES (SRC, DEPTH!=0) =====================================
/**
 * Define the index nodes, for depth!=0; declare a name struct and define nodes as this struct.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL1_NODES(PROPNAME, PROPDEF, CTXT, Z)				\
IND1	constexpr const size_t BOOST_PP_CAT(PROPNAME, IndexSize) = 0				\
		_XENUM4_CALL_VALS(_XENUM4_PLAIN_COUNT_NODES, CTXT);				NWLN \
IND1	typedef typename ::_XENUM4_NS::SelectInt< ::_XENUM4_NS::cmax(				\
			sizeof(BOOST_PP_CAT(PROPNAME, Values)),					\
			BOOST_PP_CAT(PROPNAME, IndexSize)					\
		) >::type BOOST_PP_CAT(PROPNAME, Index);					NWLN \
IND1	typedef ::_XENUM4_NS::IndexNode<BOOST_PP_CAT(PROPNAME, Index)>				\
		BOOST_PP_CAT(PROPNAME, Node);							NWLN \
	_XENUM4_PLAIN_SRC_NODES_STRUCT(PROPNAME, CTXT)						\
	_XENUM4_PLAIN_SRC_NODES_DATA(PROPNAME, CTXT)						\


// =========================== NODE NAMES (SRC) ==============================
/**
 * Declares the ${propname}Nodes_t struct.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_NODES_STRUCT(PROPNAME, CTXT)						\
IND1	typedef struct {									NWLN \
		_XENUM4_PLAIN_ITER_NODES(_XENUM4_PLAIN_SRC_NODES_FIELD, CTXT)			\
IND1	} BOOST_PP_CAT(PROPNAME, Nodes_t);							NWLN \

/**
 * Define a single field of the Nodes_t struct.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_NODES_FIELD(ITERPOS, NODE, CTXT)					\
IND2	BOOST_PP_CAT(_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)), Node)		\
	_XENUM4_PROP_GEN_NODE_NAME(								\
		CTXT,										\
		_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)				\
	);											NWLN \


// ======================== NODES DATA TABLE (SRC) ===========================
/**
 * Defines the ${propname}Nodes struct.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_NODES_DATA(PROPNAME, CTXT)						\
IND1	constexpr const BOOST_PP_CAT(PROPNAME, Node) BOOST_PP_CAT(PROPNAME, Nodes)[] =		\
	{											NWLN \
		_XENUM4_PLAIN_ITER_NODES(_XENUM4_PLAIN_SRC_NODE_DATA, CTXT)			\
IND1	};											NWLN \

/**
 * Worker for _XENUM4_PLAIN_SRC_NODES_DATA().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_NODE_DATA(ITERPOS, NODE, CTXT)					\
IND2	{											\
		/* Size */									\
		_XENUM4_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS),				\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM4_PLAIN_SRC_NODE_DATA_INDEX_,					\
			BOOST_PP_BOOL(_XENUM4_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS))	\
		) (ITERPOS, CTXT)								\
	},											NWLN \

/**
 * Define IndexNode.index to 0 since node has no children.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_NODE_DATA_INDEX_0(ITERPOS, CTXT)					\
	0

/**
 * Define IndexNode.index as an offset expression into a names struct.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_NODE_DATA_INDEX_1(ITERPOS, CTXT)					\
	_XENUM4_PLAIN_SRC_NODE_DATA_INDEX_1_DO(							\
		_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),				\
		BOOST_PP_IF(									\
			_XENUM4_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS),				\
			Nodes_t,								\
			Values_t								\
		),										\
		BOOST_PP_IF(									\
			_XENUM4_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS),				\
			Node,									\
			Value									\
		),										\
		CTXT										\
	)

/**
 * Worker for _XENUM4_PLAIN_SRC_NODE_DATA_INDEX_1().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_NODE_DATA_INDEX_1_DO(PROPNAME, INDEXPATH, NAMESTRUCT, MEMBERTYPE, CTXT)	\
	(offsetof(										\
		BOOST_PP_CAT(PROPNAME, NAMESTRUCT),						\
		_XENUM4_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0))		\
	) / sizeof(BOOST_PP_CAT(PROPNAME, MEMBERTYPE)))


// ======================================= DATA (HDR) ===========================================
/**
 * Worker for _XENUM4_PROP_DEFINE_PLAIN().
 * Defines all the data and functions of a single custom property, for "plain" data types,
 * implemented in header.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DEFINE(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)			\
	/* FIXME: Also define the ValuesSize and IndexSize integers - ? */			\
	constexpr const										\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Value)					\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Values)				\
		/* Explicit size not needed */							\
		/*[SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, ValuesSize)] = */			\
		[] =										\
		{										NWLN \
			_XENUM4_PLAIN_HDR_VALUES_DATA(CTXT)					\
		};										NWLN \
	BOOST_PP_CAT(										\
		_XENUM4_PLAIN_HDR_DATA_MULTILEVEL_,						\
		BOOST_PP_BOOL(_XENUM4_PROPDEF_GET_DEPTH(PROPDEF))				\
	) (CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)

/* DEBUG
_PLAIN_DEFINE_DATA: ctxt=CTXT scope=SCOPE storename=STORENAME valuename=VALUENAME inttype=INTTYPE propdef=PROPDEF NWLN \
*/


/**
 * Defines nothing since the custom property has depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DATA_MULTILEVEL_0(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)


/**
 * Worker for _XENUM4_PLAIN_DEFINE_DATA().
 * Defines the data of a single multilevel custom property (only when depth!=0).
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DATA_MULTILEVEL_1(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)	\
	_XENUM4_PLAIN_HDR_DEFINE_LOCAL(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\
	_XENUM4_PLAIN_HDR_NODES_DATA(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\

/**
 * Worker for _XENUM4_PLAIN_DEFINE_DATA_MULTILEVEL_1().
 * Declares the source-local name structs for the custom property.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DEFINE_LOCAL(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\
	/* The symbols should never become visible outside this source unit. */			\
	namespace {										\
	/* Also wrap in named namespace to prevent name clashes. */				\
	namespace _XENUM4_IMPL_LOCAL_NS(_XENUM4_CTXT_GET_DECL(CTXT), PROPNAME) {		NWLN \
	_XENUM4_PLAIN_HDR_VALUES_NAMES(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME)		\
	_XENUM4_PLAIN_HDR_NODES_NAMES(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\
	}}											NWLN \

// ========================== VALUES DATA TABLE ==============================
/**
 * Worker for _XENUM4_PLAIN_DEFINE_DATA().
 * Defines the ${propname}Values data table.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_VALUES_DATA(CTXT)							\
	_XENUM4_PROP_ITER_VALUES(_XENUM4_PLAIN_HDR_VALUE_DATA, CTXT)

/**
 * Callback worker for values iteration.
 * Defines a single data value of a custom property.
 * @hideinitializer
 */
// FIXME: What kind of error does it produce when there is no value and no default?
#define _XENUM4_PLAIN_HDR_VALUE_DATA(ITERPOS, NODE, CTXT)					\
IND1	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(NODE),							\
		_XENUM4_PROPDEF_GET_DEFAULTVALUE(_XENUM4_CTXT_GET_PROPDEF(CTXT)),		\
		NODE										\
	)											\
, NWLN


// ========================== VALUE NAMES (HDR) ==============================
/**
 * Worker for _XENUM4_PLAIN_DATA_MULTILEVEL_1().
 * Declares the ${propname}ValueNames struct that contains a name for each index in the
 * ${propname}Values table.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_VALUES_NAMES(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME)		\
IND1	typedef struct {									NWLN \
		_XENUM4_PROP_ITER_VALUES(_XENUM4_PLAIN_HDR_VALUE_NAME, CTXT)			\
IND1	} BOOST_PP_CAT(PROPNAME, ValueNames);							NWLN \

/**
 * Worker for _XENUM4_PLAIN_VALUES_NAMES(); loop function for each data node.
 * Declares a single value name.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_VALUE_NAME(ITERPOS, NODE, CTXT)					\
IND2	_XENUM4_DECL_GET_SCOPE(_XENUM4_CTXT_GET_DECL(CTXT))					\
	_XENUM4_STORE_NAME(_XENUM4_CTXT_GET_DECL(CTXT))						\
	:: BOOST_PP_CAT(_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)), Value)	\
	_XENUM4_PROP_GEN_NODE_NAME(CTXT, _XENUM4_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS))	\
	; NWLN


// =========================== NODE NAMES (HDR) ==============================
/**
 * Worker for _XENUM4_PLAIN_DATA_MULTILEVEL_1().
 * Declares the ${propname}NodeNames struct that contains a name for each index in the
 * ${propname}IndexNodes table.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_NODES_NAMES(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\
IND1	typedef struct {									NWLN \
		_XENUM4_PLAIN_ITER_NODES(_XENUM4_PLAIN_HDR_NODE_NAME, CTXT)			\
IND1	} BOOST_PP_CAT(PROPNAME, NodeNames);							NWLN \

/**
 * Worker for _XENUM4_PLAIN_NODES_NAMES().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_NODE_NAME(ITERPOS, NODE, CTXT)					\
IND2	_XENUM4_DECL_GET_SCOPE(_XENUM4_CTXT_GET_DECL(CTXT))					\
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


// ======================== NODES DATA TABLE (HDR) ===========================
/**
 * Worker for _XENUM4_PLAIN_DATA_MULTILEVEL_1().
 * Defines the ${propname}IndexNodes node-data table.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_NODES_DATA(CTXT, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\
	constexpr const										\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, IndexNode)				\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, IndexNodes)				\
		/* Explicit size not needed */							\
		/*[SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, IndexSize)] = */			\
		[] =										\
	{											NWLN \
		_XENUM4_PLAIN_ITER_NODES(_XENUM4_PLAIN_HDR_NODE_DATA, CTXT)			\
	};											NWLN \

/**
 * Worker for _XENUM4_PLAIN_NODES_DATA().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_NODE_DATA(ITERPOS, NODE, CTXT)					\
IND1	{											\
		/* Size */									\
		_XENUM4_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS),				\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM4_PLAIN_HDR_NODE_DATA_INDEX_,					\
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
#define _XENUM4_PLAIN_HDR_NODE_DATA_INDEX_0(ITERPOS, CTXT)					\
	0

/**
 * Worker for _XENUM4_PLAIN_NODE_DATA().
 * Define IndexNode.index as an offset expression into a names struct.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_NODE_DATA_INDEX_1(ITERPOS, CTXT)					\
	_XENUM4_PLAIN_HDR_NODE_DATA_INDEX_1_DO(							\
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
#define _XENUM4_PLAIN_HDR_NODE_DATA_INDEX_1_DO(CTXT, PROPNAME, INDEXPATH, NAMESTRUCT, MEMBERTYPE)	\
	(offsetof(										\
		_XENUM4_IMPL_LOCAL_NS(_XENUM4_CTXT_GET_DECL(CTXT), PROPNAME)::BOOST_PP_CAT(PROPNAME, NAMESTRUCT),	\
		_XENUM4_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0))		\
	) / sizeof(BOOST_PP_CAT(PROPNAME, MEMBERTYPE)))



// ==================================== LOCAL FUNCTIONS ========================================
/**
 * Define the local-ns functions related to a single custom property, implemented in source.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL1_FUNCS(DEPTH, CTXT, Z)						\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM4_PLAIN_SRC_DEFL1_GET_NODE,						\
		CTXT										\
	)											\

// =========================== getNode() (SRC) ===============================
/**
 * Define get${propname}Node() getter for given level.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL1_GET_NODE(Z, N, CTXT)						\
	_XENUM4_PLAIN_SRC_DEFL1_GET_NODE_I1(							\
		_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		_XENUM4_CTXT_GET_DECL(CTXT),							\
		Z										\
	)											\

/**
 * Worker for _XENUM4_PLAIN_SRC_DEFL1_GET_NODE().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFL1_GET_NODE_I1(PROPNAME, LEVEL, DECL, Z)				\
IND1	BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const					\
	BOOST_PP_CAT(PROPNAME, Node&)								\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM4_PROP_GEN_INDEX0_PARMS(							\
			_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_CNTNR_NAME(DECL)::_Enum,		\
			BOOST_PP_CAT(PROPNAME, Index),						\
			LEVEL,									\
			Z									\
		)										\
	)											NWLN \
IND1	{											NWLN \
IND2		return BOOST_PP_CAT(PROPNAME, Nodes)[						\
			_XENUM4_PROP_GEN_NODE_INDEXING(						\
				PROPNAME,							\
				BOOST_PP_CAT(PROPNAME, Index),					\
				LEVEL,								\
				Z								\
			)									\
		];										NWLN \
IND1	}											NWLN


// ==================================== STORE FUNCTIONS ========================================
/**
 * Define the store class functions related to a single custom property.
 * For source implementation, depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFS0_FUNCS(PROPNAME, PROPDEF, SCOPE, STORENAME, CTXT, DECL, Z)	\
	_XENUM4_PLAIN_SRC_DEFS0_GET_VALUE(							\
		PROPNAME,									\
		_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME) ::,					\
		SCOPE,										\
		STORENAME,									\
		PROPDEF,									\
		Z										\
	)

/**
 * Define the store class functions related to a single custom property.
 * For source implementation, depth!=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFS1_FUNCS(PROPNAME, DEPTH, PROPDEF, SCOPE, STORENAME, CTXT, Z)	\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM4_PLAIN_SRC_DEFS1_GET_SIZE,						\
		CTXT										\
	)											\
	_XENUM4_PLAIN_SRC_DEFS1_GET_VALUE(							\
		PROPNAME,									\
		DEPTH,										\
		_XENUM4_IMPL_LOCAL_NS(_XENUM4_CTXT_GET_DECL(CTXT), PROPNAME) ::,		\
		SCOPE,										\
		STORENAME,									\
		PROPDEF,									\
		Z										\
	)


// =========================== getSize() (SRC) ===============================
/**
 * Define get${propname}Size() getter for given level. For source implementation.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFS1_GET_SIZE(Z, N, CTXT)						\
	_XENUM4_PLAIN_SRC_DEFS1_GET_SIZE_I1(							\
		N,										\
		_XENUM4_CTXT_GET_PROPDEF(CTXT),							\
		_XENUM4_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Worker for _XENUM4_PLAIN_SRC_DEFS1_GET_SIZE().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFS1_GET_SIZE_I1(LEVEL, PROPDEF, DECL, Z)				\
	_XENUM4_PLAIN_SRC_DEFS1_GET_SIZE_I2(							\
		_XENUM4_PROPDEF_GET_NAME(PROPDEF),						\
		LEVEL,										\
		_XENUM4_DECL_GET_SCOPE(DECL),							\
		_XENUM4_STORE_NAME(DECL),							\
		DECL,										\
		Z										\
	)

/**
 * Worker for _XENUM4_PLAIN_SRC_DEFS1_GET_SIZE_I1().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFS1_GET_SIZE_I2(PROPNAME, LEVEL, SCOPE, STORENAME, DECL, Z)		\
	const size_t										\
	SCOPE STORENAME :: BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
		_XENUM4_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, LEVEL, Z)		\
	)											NWLN \
	{											NWLN \
IND1		return _XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME) ::					\
		BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (				\
			_XENUM4_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(LEVEL), Z)			\
		)										\
		.size;										NWLN \
	}											NWLN \


// =================== get${PROPNAME}() (SRC, DEPTH==0) ======================
/**
 * Defines get${propname}() value getter. For source implementation, depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFS0_GET_VALUE(PROPNAME, LOCALSCOPE, SCOPE, STORENAME, PROPDEF, Z)	\
	const _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF)&						\
	SCOPE STORENAME :: BOOST_PP_CAT(get, PROPNAME) (SCOPE STORENAME::Enum index0)		NWLN \
	{											NWLN \
IND1		return LOCALSCOPE BOOST_PP_CAT(PROPNAME, Values)[SCOPE STORENAME::getIndex(index0)];	NWLN \
	}											NWLN


// =================== get${PROPNAME}() (SRC, DEPTH!=0) ======================
/**
 * Defines get${propname}() value getter. For source implementation, depth!=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DEFS1_GET_VALUE(PROPNAME, DEPTH, LOCALSCOPE, SCOPE, STORENAME, PROPDEF, Z)	\
	const _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF)&						\
	SCOPE STORENAME :: BOOST_PP_CAT(get, PROPNAME) (					\
		_XENUM4_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, DEPTH, Z)		\
	) {											NWLN \
IND1		return LOCALSCOPE BOOST_PP_CAT(PROPNAME, Values)[				\
			LOCALSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (		\
				_XENUM4_PROP_GEN_INDEX0_ARGS(DEPTH, Z)				\
			)									\
			.getNextIndex(BOOST_PP_CAT(index, DEPTH))				\
		];										NWLN \
	}											NWLN


// =========================== _check() ==============================
/**
 * Worker for _XENUM4_PROP_CHECK_PLAIN().
 * Defines final checks on data structures, for implementation in header.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_CHECK(CXT, DECL, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\
	BOOST_PP_CAT(_XENUM4_PLAIN_HDR_CHECK_, BOOST_PP_BOOL(_XENUM4_PROPDEF_GET_DEPTH(PROPDEF)))	\
		(CTXT, DECL, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)

/**
 * Worker for _XENUM4_PLAIN_CHECK().
 * For depth==0, there is no final checks to be made.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_CHECK_0(CTXT, DECL, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\


/**
 * Worker for _XENUM4_PLAIN_CHECK().
 * For depth!=0, do check sizes of generated data.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_CHECK_1(CTXT, DECL, PROPDEF, SCOPE, STORENAME, PROPNAME, Z)		\
IND1	static_assert(										\
		sizeof(_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, ValueNames)) == 	\
		sizeof(SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Values)),			\
		"Struct/array size mismatch (ValueNames / Values)."				\
	);											NWLN \
IND1	static_assert(										\
		sizeof(_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, NodeNames)) ==	\
		sizeof(SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, IndexNodes)),			\
		"Struct/array size mismatch (NodeNames / IndexNodes)."				\
	);											NWLN \

/*
_XENUM4_PLAIN_CHECK: PROPNAME NWLN \
*/

/**
 * Worker for _XENUM4_PROP_CHECK_PLAIN().
 * Defines final checks on data structures, for implementation in source.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_CHECK(PROPNAME, PROPDEF, SCOPE, STORENAME, DECL, CTXT, Z)		\
	BOOST_PP_CAT(_XENUM4_PLAIN_SRC_CHECK_, BOOST_PP_BOOL(_XENUM4_PROPDEF_GET_DEPTH(PROPDEF)))	\
		(PROPNAME, PROPDEF, _XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME), SCOPE, STORENAME, DECL, CTXT, Z)	\

/**
 * Worker for _XENUM4_PLAIN_SRC_CHECK(), for depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_CHECK_0(PROPNAME, PROPDEF, LOCALSCOPE, SCOPE, STORENAME, DECL, CTXT, Z)	\
IND1	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Values)) ==				\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Value)) * SCOPE STORENAME::size,	\
		"Data size mismatch (Values / enum-size)."					\
	);											NWLN \


/**
 * Worker for _XENUM4_PLAIN_SRC_CHECK(), for depth!=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_CHECK_1(PROPNAME, PROPDEF, LOCALSCOPE, SCOPE, STORENAME, DECL, CTXT, Z)		\
IND1	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Nodes_t)) ==				\
		LOCALSCOPE::BOOST_PP_CAT(PROPNAME, IndexSize) *					\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Node)),				\
		"Struct size mismatch (Nodes_t / IndexSize)."					\
	);											NWLN \
IND1	static_assert(										\
		sizeof(_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, Nodes)) ==	\
		sizeof(_XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME)::BOOST_PP_CAT(PROPNAME, Nodes_t)),	\
		"Array/struct size mismatch (Nodes / Nodes_t)."					\
	);											NWLN \


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
