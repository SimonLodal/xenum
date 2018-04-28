/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of the "cstring" data type category for custom properties.
 */
#ifndef _XENUM5_IMPL_CSTRING_HPP
#define _XENUM5_IMPL_CSTRING_HPP


// ============================= DECLARATION IN CONTAINER CLASS ================================
/**
 * Entry point for declaring a custom property of cstring type, in store class context.
 */
// FIXME: hdr/src impl
#define _XENUM5_PROP_DECLS_CSTRING(PROPDEF, DECL, CTXT, Z)					\
	_XENUM5_CSTRING_DECLS_FUNCS(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		CTXT,										\
		Z										\
	)


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Entry point for declaring a custom property of cstring type, in value class context.
 */
// FIXME: hdr/src impl
#define _XENUM5_PROP_DECLV_CSTRING(PROPDEF, CTXT, Z)						\
	_XENUM5_CSTRING_DECLV_FUNCS(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		CTXT,										\
		Z										\
	)


// ======================================= DEFINITION ==========================================
/**
 * Entry point for defining the data of a custom properties of cstring type, in source file
 * context.
 */
#define _XENUM5_PROP_DEFINE_CSTRING(PROPDEF, DECL, CTXT, Z)					\
	BOOST_PP_CAT(BOOST_PP_CAT(_XENUM5_CSTRING_, _XENUM5_PROPDEF_GET_PLACEMENT_STR(PROPDEF)), _DEFINE)	\
	(											\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		DECL,										\
		CTXT,										\
		Z										\
	)											\

/**
 * Entry point for defining final checks for a custom property of cstring type, in source file
 * context.
 */
#define _XENUM5_PROP_CHECK_CSTRING(PROPDEF, DECL, CTXT, Z)					\
	BOOST_PP_CAT(BOOST_PP_CAT(_XENUM5_CSTRING_, _XENUM5_PROPDEF_GET_PLACEMENT_STR(PROPDEF)), _CHECK)	\
	(											\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		PROPDEF,									\
		DECL										\
	)											\


// ====================================== COMMON PARTS ==========================================

// ========================= Node iteration loop =============================
/**
 * Iterate data structure using ITERATE_FLAT_GEN(); execute callback for each branch-node.
 * Used by both nodenames- and nodedata-generation iterations, to ensure that they have
 * identical layout; that the placement of node data in the IndexNodes table match the names
 * in the NodeNames struct.
 * Note: The root nodes (enum-values) must appear first in the tables so they can be directly
 * indexed by an enum-value.
 * Note: Contrary to _PLAIN_ITER_NODES, this loop iterates all nodes, including the leafs
 * (values), else we could share these functions.
 */
#define _XENUM5_CSTRING_ITER_NODES(CALLBACK, CTXT)						\
	/* First, execute callback only for the enum values (root nodes), so they are */	\
	/* executed in one block. */								\
	_XENUM5_CALL_VALS(									\
		_XENUM5_CSTRING_ITER_NODES_ROOT,							\
		_XENUM5_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)											\
	/* Secondly, iterate all non-root nodes. */						\
	_XENUM5_CALL_VALS(									\
		_XENUM5_CSTRING_ITER_NODES_NONROOT,						\
		_XENUM5_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)

/**
 * Callback worker for _XENUM5_CSTRING_ITER_NODES(); loop function for each root node
 * (enum-value). Execute the callback only for the root node (no further iteration).
 */
#define _XENUM5_CSTRING_ITER_NODES_ROOT(CTXT, IDENT, ...)						\
	_XENUM5_CSTRING_ITER_NODES_ROOT_I1							\
	(											\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM5_PROPDEF_GET_DEPTH(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_CSTRING_ITER_NODES_ROOT().
 */
#define _XENUM5_CSTRING_ITER_NODES_ROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM5_CTXT_GET_CALLBACK(CTXT) (							\
		_XENUM5_TUPLETREE_ITERPOS_INIT(							\
			DEPTH,									\
			,									\
			0,									\
			_XENUM5_GET_TUPLE_SIZE_IF_TUPLE(DATA)					\
		),										\
		_XENUM5_TUPLE_TO_SEQ_COND(DATA, BOOST_PP_BOOL(DEPTH)),				\
		CTXT										\
	)

/**
 * Callback worker for _XENUM5_CSTRING_ITER_NODES(); loop function for each node.
 */
#define _XENUM5_CSTRING_ITER_NODES_NONROOT(CTXT, IDENT, ...)					\
	_XENUM5_CSTRING_ITER_NODES_NONROOT_I1							\
	(											\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM5_PROPDEF_GET_DEPTH(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_CSTRING_ITER_NODES_NONROOT().
 * Execute tupletree iteration.
 */
#define _XENUM5_CSTRING_ITER_NODES_NONROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM5_TUPLETREE_ITERATE_FLAT_GEN(							\
		DATA,										\
		DEPTH,										\
		(_XENUM5_CTXT_GET_CALLBACK(CTXT), _XENUM5_CSTRING_ITER_NODES_NONROOT_FLT),	\
		CTXT										\
	)

/**
 * Filter function for non-root nodes iteration.
 */
#define _XENUM5_CSTRING_ITER_NODES_NONROOT_FLT(ITERPOS, NODE, CTXT)				\
	BOOST_PP_AND(										\
		BOOST_PP_NOT(_XENUM5_TUPLETREE_ITERPOS_GET_NEXTCHILD(ITERPOS)),			\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)))	\
	)


// ============================== ValueNames =================================
/**
 * Declare the ${propname}ValueNames struct.
 */
#define _XENUM5_CSTRING_DECLARE_VALUENAMES(PROPNAME, CTXT)					\
	_XENUM5_DOC(Layout of all PROPNAME values.)						\
	typedef struct {									_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_CSTRING_DECLARE_VALUENAME, CTXT)		\
		_XENUM5_INDENT_DEC								\
	} BOOST_PP_CAT(PROPNAME, ValueNames);							_XENUM5_NWLN \

/**
 * Declare a single field of the ValueNames struct.
 */
#define _XENUM5_CSTRING_DECLARE_VALUENAME(ITERPOS, NODE, CTXT)					\
	BOOST_PP_CAT(_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)), Value) 		\
	_XENUM5_PROP_GEN_NODE_NAME(CTXT, _XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS))	\
	[sizeof(_XENUM5_PROP_GET_VALUE(NODE, _XENUM5_CTXT_GET_PROPDEF(CTXT)))];			_XENUM5_NWLN \


// ================================ Values ===================================
/**
 * Define the values array.
 */
#define _XENUM5_CSTRING_DEFINE_VALUES(DECLPFX, PROPNAME, CTXT)					\
	_XENUM5_DOC(All PROPNAME values.)							\
	DECLPFX constexpr const BOOST_PP_CAT(PROPNAME, ValueNames) BOOST_PP_CAT(PROPNAME, Values) =\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_CSTRING_DEFINE_VALUE, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Loop worker for _XENUM5_CSTRING_DEFINE_VALUES().
 */
#define _XENUM5_CSTRING_DEFINE_VALUE(ITERPOS, NODE, CTXT)						\
	_XENUM5_PROP_GET_VALUE(NODE, _XENUM5_CTXT_GET_PROPDEF(CTXT)),				_XENUM5_NWLN


// ============================== NodesSize ==================================
/**
 * Define the NodesSize count.
 */
#define _XENUM5_CSTRING_DEFINE_NODESSIZE(DECLPFX, PROPNAME, CTXT)				\
	_XENUM5_DOC(Total number of indexnodes for indexing PROPNAME values.)			\
	DECLPFX constexpr const size_t BOOST_PP_CAT(PROPNAME, NodesSize) = 0			\
		_XENUM5_CALL_VALS(_XENUM5_CSTRING_COUNT_NODES, CTXT);				_XENUM5_NWLN \

/**
 * Callback worker for _XENUM5_CSTRING_DEFINE_NODESSIZE().
 */
#define _XENUM5_CSTRING_COUNT_NODES(CTXT, IDENT, ...)						\
	+_XENUM5_TUPLETREE_ITERATE_DEPTH_CALC(							\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		/* Count all nodes, including leaf values, since each string value needs */	\
		/* to be referenced by an indexnode. */						\
		_XENUM5_PROPDEF_GET_DEPTH(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		(_XENUM5_PROP_COUNT_NODES_ADD),							\
		CTXT,										\
		0										\
	)											\


// ============================== NodeNames ==================================
/**
 * Declare the ${propname}NodeNames struct.
 */
#define _XENUM5_CSTRING_DECLARE_NODENAMES(PROPNAME, CTXT)					\
	_XENUM5_DOC(Used for calculating offsets into BOOST_PP_CAT(PROPNAME, Nodes) array,	\
		has same layout.)								\
	typedef struct {									_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CSTRING_ITER_NODES(_XENUM5_PROP_DECLARE_NODENAME, CTXT)			\
		_XENUM5_INDENT_DEC								\
	} BOOST_PP_CAT(PROPNAME, NodeNames);							_XENUM5_NWLN \


// ================================ Nodes ====================================
/**
 * Define the ${propname}Nodes array.
 */
#define _XENUM5_CSTRING_DEFINE_NODES(DECLPFX, PROPNAME, CTXT)					\
	_XENUM5_DOC(Mapping of all nodes and values in the PROPNAME data hierarchy.)		\
	DECLPFX constexpr const BOOST_PP_CAT(PROPNAME, Node) BOOST_PP_CAT(PROPNAME, Nodes)[] =	\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CSTRING_ITER_NODES(_XENUM5_CSTRING_DEFINE_NODE, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_CSTRING_NODES_DATA().
 */
#define _XENUM5_CSTRING_DEFINE_NODE(ITERPOS, NODE, CTXT)					\
	BOOST_PP_CAT(										\
		_XENUM5_CSTRING_DEFINE_NODE_,							\
		BOOST_PP_BOOL(_XENUM5_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS))			\
	) (ITERPOS, NODE, CTXT)									\


/**
 * Worker for _XENUM5_CSTRING_DEFINE_NODE().
 * Define a node for level==0.
 */
#define _XENUM5_CSTRING_DEFINE_NODE_0(ITERPOS, NODE, CTXT)					\
	{											\
		/* Size */									\
		sizeof(_XENUM5_PROP_GET_VALUE(NODE, _XENUM5_CTXT_GET_PROPDEF(CTXT))),		\
		/* Index */									\
		_XENUM5_CSTRING_DEFINE_NODE_0_INDEX(						\
			_XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),			\
			_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),		\
			CTXT									\
		)										\
	},											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_CSTRING_DEFINE_NODE_0().
 * Define Node.index as an offset expression into a ValueNames struct.
 */
#define _XENUM5_CSTRING_DEFINE_NODE_0_INDEX(INDEXPATH, PROPNAME, CTXT)				\
	(offsetof(										\
		BOOST_PP_CAT(PROPNAME, ValueNames),						\
		_XENUM5_PROP_GEN_NODE_NAME(CTXT, INDEXPATH)					\
	) / sizeof(BOOST_PP_CAT(PROPNAME, Value)))						\


/**
 * Worker for _XENUM5_CSTRING_DEFINE_NODE().
 * Define a node for level>0.
 */
#define _XENUM5_CSTRING_DEFINE_NODE_1(ITERPOS, NODE, CTXT)					\
	{											\
		/* Size */									\
		_XENUM5_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS),				\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM5_CSTRING_DEFINE_NODE_1_INDEX_,					\
			BOOST_PP_BOOL(_XENUM5_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS))	\
		) (ITERPOS, CTXT)								\
	},											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_CSTRING_DEFINE_NODE_1().
 * Define Node.index to 0 since node has no children.
 */
#define _XENUM5_CSTRING_DEFINE_NODE_1_INDEX_0(ITERPOS, CTXT)					\
	0

/**
 * Worker for _XENUM5_CSTRING_NODE_DATA_1().
 * Define Node.index as an offset expression into a Node table.
 */
#define _XENUM5_CSTRING_DEFINE_NODE_1_INDEX_1(ITERPOS, CTXT)					\
	_XENUM5_CSTRING_DEFINE_NODE_1_INDEX_1_DO(						\
		_XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),				\
		_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		CTXT										\
	)

/**
 * Worker for _XENUM5_CSTRING_NODE_VALUE_INDEX_1().
 */
#define _XENUM5_CSTRING_DEFINE_NODE_1_INDEX_1_DO(INDEXPATH, PROPNAME, CTXT)			\
	(offsetof(										\
		BOOST_PP_CAT(PROPNAME, NodeNames),						\
		_XENUM5_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0))		\
	) / sizeof(BOOST_PP_CAT(PROPNAME, Node)))


#endif // _XENUM5_IMPL_CSTRING_HPP
