/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of the "plain" data type category for custom properties.
 */
#ifndef _XENUM5_IMPL_PLAIN_HPP
#define _XENUM5_IMPL_PLAIN_HPP



// =============================== DECLARATION IN STORE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in store class context.
 */
#define _XENUM5_PROP_DECLS_PLAIN(PDEF, XDCL, CTXT, Z)						\
	BOOST_PP_CAT(BOOST_PP_CAT(_XENUM5_PLAIN_, _XENUM5_PDEF_PLACEMENT_STR(PDEF)), _DECLS)	\
	(											\
		_XENUM5_PDEF_NAME(PDEF),							\
		_XENUM5_PDEF_DEPTH(PDEF),							\
		PDEF,										\
		CTXT,										\
		Z										\
	)


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in value class context.
 */
#define _XENUM5_PROP_DECLV_PLAIN(PDEF, CTXT, Z)							\
	BOOST_PP_CAT(BOOST_PP_CAT(_XENUM5_PLAIN_, _XENUM5_PDEF_PLACEMENT_STR(PDEF)), _DECLV)	\
	(											\
		_XENUM5_PDEF_NAME(PDEF),							\
		_XENUM5_PDEF_DEPTH(PDEF),							\
		PDEF,										\
		CTXT,										\
		Z										\
	)


// ======================================= DEFINITION ==========================================
/**
 * Entry point for defining a custom property of plain type, in source file context.
 */
#define _XENUM5_PROP_DEFINE_PLAIN(PDEF, XDCL, CTXT, Z)						\
	BOOST_PP_CAT(BOOST_PP_CAT(_XENUM5_PLAIN_, _XENUM5_PDEF_PLACEMENT_STR(PDEF)), _DEFINE)	\
	(											\
		_XENUM5_PDEF_NAME(PDEF),							\
		_XENUM5_PDEF_DEPTH(PDEF),							\
		PDEF,										\
		_XENUM5_IMPL_LOCAL_NS(XDCL, _XENUM5_PDEF_NAME(PDEF)),				\
		_XENUM5_XDCL_DSCOPE(XDCL),							\
		_XENUM5_STORE_NAME(XDCL),							\
		CTXT,										\
		Z										\
	)


/**
 * Entry point for defining final checks for a custom property of plain type, in source file
 * context.
 */
#define _XENUM5_PROP_CHECK_PLAIN(PNAME, PDEF, XDCL, CTXT, Z)					\
	BOOST_PP_CAT(BOOST_PP_CAT(_XENUM5_PLAIN_, _XENUM5_PDEF_PLACEMENT_STR(PDEF)), _CHECK)	\
	(											\
		PNAME,										\
		PDEF,										\
		_XENUM5_IMPL_LOCAL_NS(XDCL, PNAME),						\
		_XENUM5_XDCL_DSCOPE(XDCL),							\
		_XENUM5_STORE_NAME(XDCL),							\
		Z										\
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
 * Note: All node iteration sets depth-=1 because we are not iterating leaf values, only nodes.
 */
#define _XENUM5_PLAIN_ITER_NODES(CALLBACK, CTXT)						\
	/* First, execute callback only for the enum values (root nodes), so they are */	\
	/* executed in one block. */								\
	_XENUM5_CALL_VALS(									\
		_XENUM5_PLAIN_ITER_NODES_ROOT,							\
		_XENUM5_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)											\
	/* Secondly, iterate all non-root nodes. */						\
	_XENUM5_CALL_VALS(									\
		_XENUM5_PLAIN_ITER_NODES_NONROOT,						\
		_XENUM5_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)

/**
 * Callback worker for _XENUM5_PLAIN_ITER_NODES(); loop function for each root node
 * (enum-value). Execute the callback only for the root node (no further iteration).
 */
#define _XENUM5_PLAIN_ITER_NODES_ROOT(CTXT, IDENT, ...)						\
	_XENUM5_PLAIN_ITER_NODES_ROOT_I1							\
	(											\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_PINDEX(CTXT), __VA_ARGS__),			\
		BOOST_PP_DEC(_XENUM5_PDEF_DEPTH(_XENUM5_CTXT_PDEF(CTXT))),			\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_PLAIN_ITER_NODES_ROOT().
 */
#define _XENUM5_PLAIN_ITER_NODES_ROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM5_CTXT_CALLBACK(CTXT) (								\
		_XENUM5_TT_ITERPOS_INIT(							\
			DEPTH,									\
			,									\
			0,									\
			_XENUM5_GET_TUPLE_SIZE_IF_TUPLE(DATA)					\
		),										\
		_XENUM5_TUPLE_TO_SEQ_COND(DATA, BOOST_PP_BOOL(DEPTH)),				\
		CTXT										\
	)

/**
 * Callback worker for _XENUM5_PLAIN_ITER_NODES(); loop function for each node.
 */
#define _XENUM5_PLAIN_ITER_NODES_NONROOT(CTXT, IDENT, ...)					\
	_XENUM5_PLAIN_ITER_NODES_NONROOT_I1							\
	(											\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_PINDEX(CTXT), __VA_ARGS__),			\
		_XENUM5_PDEF_DEPTH(_XENUM5_CTXT_PDEF(CTXT)),					\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_PLAIN_ITER_NODES_NONROOT().
 * Execute tupletree iteration.
 */
#define _XENUM5_PLAIN_ITER_NODES_NONROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM5_TT_ITERATE_FLAT_GEN(								\
		DATA,										\
		/* We do not want to iterate leaf values */					\
		BOOST_PP_DEC(DEPTH),								\
		(_XENUM5_CTXT_CALLBACK(CTXT), _XENUM5_PLAIN_ITER_NODES_NONROOT_FLT),		\
		CTXT										\
	)

/**
 * Filter function for non-root nodes iteration.
 */
#define _XENUM5_PLAIN_ITER_NODES_NONROOT_FLT(ITERPOS, NODE, CTXT)				\
	BOOST_PP_AND(										\
		BOOST_PP_NOT(_XENUM5_TT_ITERPOS_NEXTCHILD(ITERPOS)),				\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM5_TT_ITERPOS_INDEXPATH(ITERPOS)))		\
	)


// ================================ Values ===================================
/**
 * Define the values array.
 */
#define _XENUM5_PLAIN_DEFINE_VALUES(DECLPFX, PNAME, CTXT)					\
	_XENUM5_DOC(Array of all PNAME values.)							\
	DECLPFX constexpr const BOOST_PP_CAT(PNAME, Value) BOOST_PP_CAT(PNAME, Values)[] =	\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_PLAIN_DEFINE_VALUE, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Loop worker for _XENUM5_PLAIN_DEFINE_VALUES().
 */
#define _XENUM5_PLAIN_DEFINE_VALUE(ITERPOS, NODE, CTXT)						\
	_XENUM5_PROP_VALUE(NODE, _XENUM5_CTXT_PDEF(CTXT)),					_XENUM5_NWLN


// ============================== NodesSize ==================================
/**
 * Define the NodesSize count.
 */
#define _XENUM5_PLAIN_DEFINE_NODESSIZE(DECLPFX, PNAME, CTXT)					\
	_XENUM5_DOC(Total number of indexnodes for indexing PNAME values.)			\
	DECLPFX constexpr const size_t BOOST_PP_CAT(PNAME, NodesSize) = 0			\
		_XENUM5_CALL_VALS(_XENUM5_PLAIN_COUNT_NODES, CTXT);				_XENUM5_NWLN \

/**
 * Callback worker for _XENUM5_PLAIN_DEFINE_NODESSIZE().
 */
#define _XENUM5_PLAIN_COUNT_NODES(CTXT, IDENT, ...)						\
	+_XENUM5_TT_ITERATE_DEPTH_CALC(								\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_PINDEX(CTXT), __VA_ARGS__),			\
		/* Only count nodes, not leaf values. */					\
		BOOST_PP_DEC(_XENUM5_PDEF_DEPTH(_XENUM5_CTXT_PDEF(CTXT))),			\
		(_XENUM5_PROP_COUNT_NODES_ADD),							\
		CTXT,										\
		0										\
	)											\


// ============================== NodeNames ==================================
/**
 * Declare the ${propname}NodeNames struct.
 */
#define _XENUM5_PLAIN_DECLARE_NODENAMES(PNAME, CTXT)						\
	_XENUM5_DOC(Used for calculating offsets into BOOST_PP_CAT(PNAME, Nodes) array,		\
		has same layout.)								\
	using BOOST_PP_CAT(PNAME, NodeNames) = struct {						_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PLAIN_ITER_NODES(_XENUM5_PROP_DECLARE_NODENAME, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \


// ============================== ValueNames =================================
/**
 * Declare the ${propname}ValueNames struct.
 */
#define _XENUM5_PLAIN_DECLARE_VALUENAMES(PNAME, CTXT)						\
	_XENUM5_DOC(Used for calculating offsets into BOOST_PP_CAT(PNAME, Values) array,	\
		has same layout.)								\
	using BOOST_PP_CAT(PNAME, ValueNames) = struct {					_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_PLAIN_DECLARE_VALUENAME, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Declare a single field of the ValueNames struct.
 */
#define _XENUM5_PLAIN_DECLARE_VALUENAME(ITERPOS, NODE, CTXT)					\
	BOOST_PP_CAT(_XENUM5_PDEF_NAME(_XENUM5_CTXT_PDEF(CTXT)), Value)				\
	_XENUM5_PROP_GEN_NODE_NAME(CTXT, _XENUM5_TT_ITERPOS_INDEXPATH(ITERPOS));		_XENUM5_NWLN \


// ================================ Nodes ====================================
/**
 * Define the ${propname}Nodes array.
 */
#define _XENUM5_PLAIN_DEFINE_NODES(DECLPFX, PNAME, CTXT)					\
	_XENUM5_DOC(Mapping of all nodes and values in the PNAME data hierarchy.)		\
	DECLPFX constexpr const BOOST_PP_CAT(PNAME, Node) BOOST_PP_CAT(PNAME, Nodes)[] =	\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PLAIN_ITER_NODES(_XENUM5_PLAIN_DEFINE_NODE, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_PLAIN_DEFINE_NODES().
 */
#define _XENUM5_PLAIN_DEFINE_NODE(ITERPOS, NODE, CTXT)						\
	{											\
		/* Size */									\
		_XENUM5_TT_ITERPOS_CHILDCOUNT(ITERPOS),						\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM5_PLAIN_DEFINE_NODE_INDEX_,					\
			BOOST_PP_BOOL(_XENUM5_TT_ITERPOS_CHILDCOUNT(ITERPOS))			\
		) (ITERPOS, CTXT)								\
	},											_XENUM5_NWLN \

/**
 * Define Node.index to 0 since node has no children.
 */
#define _XENUM5_PLAIN_DEFINE_NODE_INDEX_0(ITERPOS, CTXT)					\
	0

/**
 * Define Node.index as an offset expression into a names struct.
 */
#define _XENUM5_PLAIN_DEFINE_NODE_INDEX_1(ITERPOS, CTXT)					\
	_XENUM5_PLAIN_DEFINE_NODE_INDEX_1_I1(							\
		_XENUM5_PDEF_NAME(_XENUM5_CTXT_PDEF(CTXT)),					\
		_XENUM5_TT_ITERPOS_INDEXPATH(ITERPOS),						\
		BOOST_PP_IF(									\
			_XENUM5_TT_ITERPOS_LEVEL(ITERPOS),					\
			NodeNames,								\
			ValueNames								\
		),										\
		BOOST_PP_IF(									\
			_XENUM5_TT_ITERPOS_LEVEL(ITERPOS),					\
			Node,									\
			Value									\
		),										\
		CTXT										\
	)

/**
 * Worker for _XENUM5_PLAIN_SRC_NODE_DATA_INDEX_1().
 */
#define _XENUM5_PLAIN_DEFINE_NODE_INDEX_1_I1(PNAME, INDEXPATH, NAMESTRUCT, MEMBERTYPE, CTXT)	\
	(offsetof(										\
		BOOST_PP_CAT(PNAME, NAMESTRUCT),						\
		_XENUM5_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0))		\
	) / sizeof(BOOST_PP_CAT(PNAME, MEMBERTYPE)))


#endif // _XENUM5_IMPL_PLAIN_HPP
