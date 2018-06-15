/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Common parts for implementation of the "cstring" data type category for custom properties.
 */
#ifndef _XENUM5_IMPL_CSTRING_HPP
#define _XENUM5_IMPL_CSTRING_HPP


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
		_XENUM5_GET_VARARG(_XENUM5_CTXT_PINDEX(CTXT), __VA_ARGS__),			\
		_XENUM5_PDEF_DEPTH(_XENUM5_CTXT_PDEF(CTXT)),					\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_CSTRING_ITER_NODES_ROOT().
 */
#define _XENUM5_CSTRING_ITER_NODES_ROOT_I1(DATA, DEPTH, CTXT)					\
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
 * Callback worker for _XENUM5_CSTRING_ITER_NODES(); loop function for each node.
 */
#define _XENUM5_CSTRING_ITER_NODES_NONROOT(CTXT, IDENT, ...)					\
	_XENUM5_CSTRING_ITER_NODES_NONROOT_I1							\
	(											\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_PINDEX(CTXT), __VA_ARGS__),			\
		_XENUM5_PDEF_DEPTH(_XENUM5_CTXT_PDEF(CTXT)),					\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_CSTRING_ITER_NODES_NONROOT().
 * Execute tupletree iteration.
 */
#define _XENUM5_CSTRING_ITER_NODES_NONROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM5_TT_ITERATE_FLAT_GEN(								\
		DATA,										\
		DEPTH,										\
		(_XENUM5_CTXT_CALLBACK(CTXT), _XENUM5_CSTRING_ITER_NODES_NONROOT_FLT),		\
		CTXT										\
	)

/**
 * Filter function for non-root nodes iteration.
 */
#define _XENUM5_CSTRING_ITER_NODES_NONROOT_FLT(ITERPOS, NODE, CTXT)				\
	BOOST_PP_AND(										\
		BOOST_PP_NOT(_XENUM5_TT_ITERPOS_NEXTCHILD(ITERPOS)),				\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM5_TT_ITERPOS_INDEXPATH(ITERPOS)))		\
	)


// ================================ Values ===================================
/**
 * Define the values array.
 */
#define _XENUM5_CSTRING_VALUES_DEF(DECLPFX, PNAME, CTXT)					\
	_XENUM5_DOC(All PNAME values.)								\
	DECLPFX constexpr const BOOST_PP_CAT(PNAME, Value) BOOST_PP_CAT(PNAME, Values)[] =	\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_CSTRING_VALUE_DEF, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Loop worker for _XENUM5_CSTRING_VALUES_DEF().
 */
#define _XENUM5_CSTRING_VALUE_DEF(ITERPOS, NODE, CTXT)						\
	_XENUM5_PROP_VALUE(NODE, _XENUM5_CTXT_PDEF(CTXT)) "\0"					_XENUM5_NWLN


// ============================== NodesSize ==================================
/**
 * Define the NodesSize count.
 */
#define _XENUM5_CSTRING_NODESSIZE_DEF(DECLPFX, PNAME, CTXT)					\
	_XENUM5_DOC(Total number of indexnodes for indexing PNAME values.)			\
	DECLPFX constexpr const size_t BOOST_PP_CAT(PNAME, NodesSize) = 0			\
		_XENUM5_CALL_VALS(_XENUM5_CSTRING_COUNT_NODES, CTXT);				_XENUM5_NWLN \

/**
 * Callback worker for _XENUM5_CSTRING_NODESSIZE_DEF().
 */
#define _XENUM5_CSTRING_COUNT_NODES(CTXT, IDENT, ...)						\
	+_XENUM5_TT_ITERATE_DEPTH_CALC(								\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_PINDEX(CTXT), __VA_ARGS__),			\
		/* Count all nodes, including leaf values, since each string value needs */	\
		/* to be referenced by an indexnode. */						\
		_XENUM5_PDEF_DEPTH(_XENUM5_CTXT_PDEF(CTXT)),					\
		(_XENUM5_PROP_COUNT_NODES_ADD),							\
		CTXT,										\
		0										\
	)											\


// ============================== NodeNames ==================================
/**
 * Declare the ${pname}NodeNames struct.
 */
#define _XENUM5_CSTRING_NODENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_DOC(Used for calculating offsets into BOOST_PP_CAT(PNAME, Nodes) array,		\
		has same layout.)								\
	using BOOST_PP_CAT(PNAME, NodeNames) = struct {						_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CSTRING_ITER_NODES(_XENUM5_PROP_NODENAME_DECL, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \


// ============================== ValueNames =================================
/**
 * Declare the ${pname}ValueNames struct.
 */
#define _XENUM5_CSTRING_VALUENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_DOC(Layout of all PNAME values.)						\
	using BOOST_PP_CAT(PNAME, ValueNames) = struct {					_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_CSTRING_VALUENAME_DECL, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Declare a single field of the ValueNames struct.
 */
#define _XENUM5_CSTRING_VALUENAME_DECL(ITERPOS, NODE, CTXT)					\
	BOOST_PP_CAT(_XENUM5_PDEF_NAME(_XENUM5_CTXT_PDEF(CTXT)), Value) 			\
	_XENUM5_PROP_GEN_NODE_NAME(CTXT, _XENUM5_TT_ITERPOS_INDEXPATH(ITERPOS))			\
	[sizeof(_XENUM5_PROP_VALUE(NODE, _XENUM5_CTXT_PDEF(CTXT)))];				_XENUM5_NWLN \


// ================================ Nodes ====================================
/**
 * Define the ${pname}Nodes array.
 */
#define _XENUM5_CSTRING_NODES_DEF(DECLPFX, PNAME, CTXT)						\
	_XENUM5_DOC(Mapping of all nodes and values in the PNAME data hierarchy.)		\
	DECLPFX constexpr const BOOST_PP_CAT(PNAME, Node) BOOST_PP_CAT(PNAME, Nodes)[] =	\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CSTRING_ITER_NODES(_XENUM5_CSTRING_NODE_DEF, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_CSTRING_NODES_DEF().
 */
#define _XENUM5_CSTRING_NODE_DEF(ITERPOS, NODE, CTXT)						\
	BOOST_PP_CAT(										\
		_XENUM5_CSTRING_NODE_DEF_,							\
		BOOST_PP_BOOL(_XENUM5_TT_ITERPOS_LEVEL(ITERPOS))				\
	) (ITERPOS, NODE, CTXT)									\


/**
 * Worker for _XENUM5_CSTRING_NODE_DEF().
 * Define a node for level==0.
 */
#define _XENUM5_CSTRING_NODE_DEF_0(ITERPOS, NODE, CTXT)						\
	{											\
		/* Size */									\
		sizeof(_XENUM5_PROP_VALUE(NODE, _XENUM5_CTXT_PDEF(CTXT))),			\
		/* Index */									\
		_XENUM5_CSTRING_NODE_DEF_0_INDEX(						\
			_XENUM5_TT_ITERPOS_INDEXPATH(ITERPOS),					\
			_XENUM5_PDEF_NAME(_XENUM5_CTXT_PDEF(CTXT)),				\
			CTXT									\
		)										\
	},											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_CSTRING_NODE_DEF_0().
 * Define Node.index as an offset expression into a ValueNames struct.
 */
#define _XENUM5_CSTRING_NODE_DEF_0_INDEX(INDEXPATH, PNAME, CTXT)				\
	(offsetof(										\
		BOOST_PP_CAT(PNAME, ValueNames),						\
		_XENUM5_PROP_GEN_NODE_NAME(CTXT, INDEXPATH)					\
	) / sizeof(BOOST_PP_CAT(PNAME, Value)))							\


/**
 * Worker for _XENUM5_CSTRING_NODE_DEF().
 * Define a node for level>0.
 */
#define _XENUM5_CSTRING_NODE_DEF_1(ITERPOS, NODE, CTXT)						\
	{											\
		/* Size */									\
		_XENUM5_TT_ITERPOS_CHILDCOUNT(ITERPOS),						\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM5_CSTRING_NODE_DEF_1_INDEX_,					\
			BOOST_PP_BOOL(_XENUM5_TT_ITERPOS_CHILDCOUNT(ITERPOS))			\
		) (ITERPOS, CTXT)								\
	},											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_CSTRING_NODE_DEF_1().
 * Define Node.index to 0 since node has no children.
 */
#define _XENUM5_CSTRING_NODE_DEF_1_INDEX_0(ITERPOS, CTXT)					\
	0

/**
 * Worker for _XENUM5_CSTRING_NODE_DEF_1().
 * Define Node.index as an offset expression into a Node table.
 */
#define _XENUM5_CSTRING_NODE_DEF_1_INDEX_1(ITERPOS, CTXT)					\
	_XENUM5_CSTRING_NODE_DEF_1_INDEX_1_DO(							\
		_XENUM5_TT_ITERPOS_INDEXPATH(ITERPOS),						\
		_XENUM5_PDEF_NAME(_XENUM5_CTXT_PDEF(CTXT)),					\
		CTXT										\
	)

/**
 * Worker for _XENUM5_CSTRING_NODE_DEF_1_INDEX_1().
 */
#define _XENUM5_CSTRING_NODE_DEF_1_INDEX_1_DO(INDEXPATH, PNAME, CTXT)			\
	(offsetof(										\
		BOOST_PP_CAT(PNAME, NodeNames),							\
		_XENUM5_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0))		\
	) / sizeof(BOOST_PP_CAT(PNAME, Node)))


// ========================= Define get${PNAME}() ============================
/**
 * Define Store::get${pname}() value getter, inline/constexpr or ext.
 */
#define _XENUM5_CSTRING_GETVALUE_DEFS(DECLPFX, PNAME, DEPTH, PDEF, LSCOPED, SSCOPED, Z)		\
	_XENUM5_DOC(Get value of the custom property PNAME.)					\
	DECLPFX const _XENUM5_PDEF_PARM_TYPE(PDEF)						\
	SSCOPED BOOST_PP_CAT(get, PNAME) (							\
		_XENUM5_PROP_GEN_INDEX0_PARMS(							\
			SSCOPED Enum,								\
			SSCOPED BOOST_PP_CAT(PNAME, Index),					\
			DEPTH,									\
			Z									\
		)										\
	) BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return & LSCOPED BOOST_PP_CAT(PNAME, Values)[					\
			LSCOPED BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (			\
				_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(DEPTH), Z)		\
			)									\
			.index									\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN


#endif // _XENUM5_IMPL_CSTRING_HPP
