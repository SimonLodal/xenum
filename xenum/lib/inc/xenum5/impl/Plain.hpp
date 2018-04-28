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
#define _XENUM5_PROP_DECLS_PLAIN(PROPDEF, DECL, CTXT, Z)					\
	BOOST_PP_CAT(_XENUM5_PROP_DECLS_PLAIN_, _XENUM5_PROPDEF_GET_PLACEMENT_STR(PROPDEF))	\
		(PROPDEF, DECL, CTXT, Z)

/*
_XENUM5_CMNT(PROP_DECLS_PLAIN: propdef=PROPDEF) \
_XENUM5_CMNT(PROP_DECLS_PLAIN: features=_XENUM5_PROPDEF_GET_FEATURES(PROPDEF)) \
_XENUM5_CMNT(PROP_DECLS_PLAIN: placement=_XENUM5_PROPDEF_FEAT_PLACEMENT(PROPDEF)) \
*/

/**
 * Declaratation for a custom property of plain type, implemented in header, in store class
 * context.
 */
#define _XENUM5_PROP_DECLS_PLAIN_HDR(PROPDEF, DECL, CTXT, Z)					\
	_XENUM5_PLAIN_HDR_DECLS(_XENUM5_PROPDEF_GET_NAME(PROPDEF), PROPDEF, DECL, CTXT, Z)	\

/**
 * Declaratation for a custom property of plain type, implemented in source, in store class
 * context.
 */
#define _XENUM5_PROP_DECLS_PLAIN_SRC(PROPDEF, DECL, CTXT, Z)					\
	_XENUM5_PLAIN_SRC_DECLS_FUNCS(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		CTXT,										\
		Z										\
	)


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in value class context.
 */
#define _XENUM5_PROP_DECLV_PLAIN(PROPDEF, CTXT, Z)						\
	BOOST_PP_CAT(_XENUM5_PROP_DECLV_PLAIN_, _XENUM5_PROPDEF_GET_PLACEMENT_STR(PROPDEF))	\
		(PROPDEF, CTXT, Z)


/**
 * Declaratation for a custom property of plain type, implemented in header, in value class
 * context.
 */
#define _XENUM5_PROP_DECLV_PLAIN_HDR(PROPDEF, CTXT, Z)						\
	_XENUM5_PLAIN_HDR_DECLV_TYPES(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF)						\
	)											\
	_XENUM5_PLAIN_HDR_DECLV_FUNCS(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		CTXT,										\
		Z										\
	)

/**
 * Declaratation for a custom property of plain type, implemented in source, in value class
 * context.
 */
#define _XENUM5_PROP_DECLV_PLAIN_SRC(PROPDEF, CTXT, Z)						\
	_XENUM5_PLAIN_SRC_DECLV_FUNCS(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		CTXT,										\
		Z										\
	)


// ======================================= DEFINITION ==========================================
/**
 * Entry point for defining a custom property of plain type, in source file context.
 */
#define _XENUM5_PROP_DEFINE_PLAIN(PROPDEF, DECL, CTXT, Z)					\
	BOOST_PP_CAT(_XENUM5_PROP_DEFINE_PLAIN_, _XENUM5_PROPDEF_GET_PLACEMENT_STR(PROPDEF))	\
		(CTXT, DECL, PROPDEF, Z)

/**
 * Definitions for a custom property of plain type, implemented in header, in source file context.
 */
#define _XENUM5_PROP_DEFINE_PLAIN_HDR(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_PLAIN_HDR_DEFINE								\
	(											\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_STORE_NAME(DECL),							\
		Z										\
	)											\

/**
 * Definitions for a custom property of plain type, implemented in source, in source file
 * context.
 */
#define _XENUM5_PROP_DEFINE_PLAIN_SRC(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_PLAIN_SRC_DEFINE								\
	(											\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		DECL,										\
		CTXT,										\
		Z										\
	)											\


/**
 * Entry point for defining final checks for a custom property of plain type, in source file
 * context.
 */
#define _XENUM5_PROP_CHECK_PLAIN(PROPDEF, DECL, CTXT, Z)					\
	BOOST_PP_CAT(_XENUM5_PROP_CHECK_PLAIN_, _XENUM5_PROPDEF_GET_PLACEMENT_STR(PROPDEF))	\
		(PROPDEF, DECL, CTXT, Z)

/**
 * Define final checks for a custom property of plain type, implemented in header, in source
 * file context.
 */
#define _XENUM5_PROP_CHECK_PLAIN_HDR(PROPDEF, DECL, CTXT, Z)					\
	_XENUM5_PLAIN_HDR_CHECK									\
	(											\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_STORE_NAME(DECL),							\
		Z										\
	)											\

/**
 * Define final checks for a custom property of plain type, implemented in source, in source
 * file context.
 */
#define _XENUM5_PROP_CHECK_PLAIN_SRC(PROPDEF, DECL, CTXT, Z)					\
	_XENUM5_PLAIN_SRC_CHECK									\
	(											\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_STORE_NAME(DECL),							\
		DECL,										\
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
		_XENUM5_GET_VARARG(_XENUM5_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		BOOST_PP_DEC(_XENUM5_PROPDEF_GET_DEPTH(_XENUM5_CTXT_GET_PROPDEF(CTXT))),	\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_PLAIN_ITER_NODES_ROOT().
 */
#define _XENUM5_PLAIN_ITER_NODES_ROOT_I1(DATA, DEPTH, CTXT)					\
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
 * Callback worker for _XENUM5_PLAIN_ITER_NODES(); loop function for each node.
 */
#define _XENUM5_PLAIN_ITER_NODES_NONROOT(CTXT, IDENT, ...)					\
	_XENUM5_PLAIN_ITER_NODES_NONROOT_I1							\
	(											\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM5_PROPDEF_GET_DEPTH(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_PLAIN_ITER_NODES_NONROOT().
 * Execute tupletree iteration.
 */
#define _XENUM5_PLAIN_ITER_NODES_NONROOT_I1(DATA, DEPTH, CTXT)					\
	_XENUM5_TUPLETREE_ITERATE_FLAT_GEN(							\
		DATA,										\
		/* We do not want to iterate leaf values */					\
		BOOST_PP_DEC(DEPTH),								\
		(_XENUM5_CTXT_GET_CALLBACK(CTXT), _XENUM5_PLAIN_ITER_NODES_NONROOT_FLT),	\
		CTXT										\
	)

/**
 * Filter function for non-root nodes iteration.
 */
#define _XENUM5_PLAIN_ITER_NODES_NONROOT_FLT(ITERPOS, NODE, CTXT)				\
	BOOST_PP_AND(										\
		BOOST_PP_NOT(_XENUM5_TUPLETREE_ITERPOS_GET_NEXTCHILD(ITERPOS)),			\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)))	\
	)


// ================================ Values ===================================
/**
 * Define the values array.
 */
#define _XENUM5_PLAIN_DEFINE_VALUES(DECLPFX, PROPNAME, CTXT)					\
	_XENUM5_DOC(Array of all PROPNAME values.)						\
	DECLPFX constexpr const BOOST_PP_CAT(PROPNAME, Value) BOOST_PP_CAT(PROPNAME, Values)[] =\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_PLAIN_DEFINE_VALUE, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Loop worker for _XENUM5_PLAIN_DEFINE_VALUES().
 */
#define _XENUM5_PLAIN_DEFINE_VALUE(ITERPOS, NODE, CTXT)						\
	_XENUM5_PROP_GET_VALUE(NODE, _XENUM5_CTXT_GET_PROPDEF(CTXT)),				_XENUM5_NWLN


// ============================== IndexSize ==================================
/**
 * Define the IndexSize count.
 */
#define _XENUM5_PLAIN_DEFINE_INDEXSIZE(DECLPFX, PROPNAME, CTXT)					\
	_XENUM5_DOC(Total number of indexnodes for indexing PROPNAME values.)			\
	DECLPFX constexpr const size_t BOOST_PP_CAT(PROPNAME, IndexSize) = 0			\
		_XENUM5_CALL_VALS(_XENUM5_PLAIN_COUNT_NODES, CTXT);				_XENUM5_NWLN \

/**
 * Callback worker for _XENUM5_PLAIN_DEFINE_INDEXSIZE().
 */
#define _XENUM5_PLAIN_COUNT_NODES(CTXT, IDENT, ...)						\
	+_XENUM5_TUPLETREE_ITERATE_DEPTH_CALC(							\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		/* Only count nodes, not leaf values. */					\
		BOOST_PP_DEC(_XENUM5_PROPDEF_GET_DEPTH(_XENUM5_CTXT_GET_PROPDEF(CTXT))),	\
		(_XENUM5_PLAIN_COUNT_NODES_ADD),						\
		CTXT,										\
		0										\
	)											\

/**
 * Callback for _XENUM5_PLAIN_COUNT_NODES() iteration. Called for each node.
 * Add +1 for each indexnode.
 */
#define _XENUM5_PLAIN_COUNT_NODES_ADD(ITERPOS, NODE, CTXT, STATE)				\
	BOOST_PP_INC(STATE)


// ============================== Index type =================================
/**
 * Define the ${PROPNAME}Index type.
 */
#define _XENUM5_PLAIN_DECLARE_INDEX_TYPE(PROPNAME)						\
	_XENUM5_DOC(Integer type big enough to count and index both PROPNAME values and indexnodes.)	\
	typedef typename ::_XENUM5_NS::SelectInt< ::_XENUM5_NS::cmax(				\
			sizeof(BOOST_PP_CAT(PROPNAME, Values)) / sizeof(BOOST_PP_CAT(PROPNAME, Value)), \
			BOOST_PP_CAT(PROPNAME, IndexSize)					\
		) >::type BOOST_PP_CAT(PROPNAME, Index);					_XENUM5_NWLN \


// ============================== Node type ==================================
/**
 * Define the ${PROPNAME}IndexNode type.
 */
#define _XENUM5_PLAIN_DECLARE_NODE_TYPE(PROPNAME)						\
	_XENUM5_DOC(IndexNode type for PROPNAME, to map the PROPNAME value hierarchy.)		\
	typedef ::_XENUM5_NS::IndexNode<BOOST_PP_CAT(PROPNAME, Index)>				\
		BOOST_PP_CAT(PROPNAME, Node);							_XENUM5_NWLN \


// ============================== NodeNames ==================================
/**
 * Define the ${propname}NodeNames struct.
 */
#define _XENUM5_PLAIN_DEFINE_NODENAMES(PROPNAME, CTXT)						\
	_XENUM5_DOC(Used for calculating offsets into BOOST_PP_CAT(PROPNAME, Nodes) array,	\
		has same layout.)								\
	typedef struct {									_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PLAIN_ITER_NODES(_XENUM5_PLAIN_DEFINE_NODENAME, CTXT)			\
		_XENUM5_INDENT_DEC								\
	} BOOST_PP_CAT(PROPNAME, NodeNames);							_XENUM5_NWLN \

/**
 * Define a single field of the NodeNames struct.
 */
#define _XENUM5_PLAIN_DEFINE_NODENAME(ITERPOS, NODE, CTXT)					\
	BOOST_PP_CAT(_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)), Node)		\
	_XENUM5_PROP_GEN_NODE_NAME(								\
		CTXT,										\
		_XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)				\
	);											_XENUM5_NWLN \


// ============================== ValueNames =================================
/**
 * Define the ${propname}ValueNames struct.
 */
#define _XENUM5_PLAIN_DEFINE_VALUENAMES(PROPNAME, CTXT)						\
	_XENUM5_DOC(Used for calculating offsets into BOOST_PP_CAT(PROPNAME, Values) array,	\
		has same layout.)								\
	typedef struct {									_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_PLAIN_DEFINE_VALUENAME, CTXT)			\
		_XENUM5_INDENT_DEC								\
	} BOOST_PP_CAT(PROPNAME, ValueNames);							_XENUM5_NWLN \

/**
 * Define a single field of the ValueNames struct.
 */
#define _XENUM5_PLAIN_DEFINE_VALUENAME(ITERPOS, NODE, CTXT)					\
	BOOST_PP_CAT(_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)), Value)		\
	_XENUM5_PROP_GEN_NODE_NAME(CTXT, _XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS));	_XENUM5_NWLN \


// ================================ Nodes ====================================
/**
 * Define the ${propname}Nodes struct.
 */
#define _XENUM5_PLAIN_DEFINE_NODES(DECLPFX, PROPNAME, CTXT)					\
	_XENUM5_DOC(Mapping of all nodes and values in the PROPNAME data hierarchy.)		\
	DECLPFX constexpr const BOOST_PP_CAT(PROPNAME, Node) BOOST_PP_CAT(PROPNAME, Nodes)[] =	\
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
		_XENUM5_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS),				\
		/* Index */									\
		BOOST_PP_CAT(									\
			_XENUM5_PLAIN_DEFINE_NODE_INDEX_,					\
			BOOST_PP_BOOL(_XENUM5_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS))	\
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
		_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),				\
		BOOST_PP_IF(									\
			_XENUM5_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS),				\
			NodeNames,								\
			ValueNames								\
		),										\
		BOOST_PP_IF(									\
			_XENUM5_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS),				\
			Node,									\
			Value									\
		),										\
		CTXT										\
	)

/**
 * Worker for _XENUM5_PLAIN_SRC_NODE_DATA_INDEX_1().
 */
#define _XENUM5_PLAIN_DEFINE_NODE_INDEX_1_I1(PROPNAME, INDEXPATH, NAMESTRUCT, MEMBERTYPE, CTXT)	\
	(offsetof(										\
		BOOST_PP_CAT(PROPNAME, NAMESTRUCT),						\
		_XENUM5_PROP_GEN_NODE_NAME(CTXT, BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, 0))		\
	) / sizeof(BOOST_PP_CAT(PROPNAME, MEMBERTYPE)))


// ============================== getNode() ==================================
/**
 * Define get${propname}Node() getters for all levels.
 */
#define _XENUM5_PLAIN_DEFINE_GET_NODE(DEPTH, CTXT, Z)						\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PLAIN_DEFINE_GET_NODE_N,						\
		CTXT										\
	)											\

/**
 * Define get${propname}Node() getter for given level.
 */
#define _XENUM5_PLAIN_DEFINE_GET_NODE_N(Z, N, CTXT)						\
	_XENUM5_PLAIN_DEFINE_GET_NODE_N_I1(							\
		_XENUM5_CTXT_GET_DECLPFX(CTXT),							\
		_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		Z										\
	)											\

/**
 * Worker for _XENUM5_PLAIN_DEFINE_GET_NODE_N().
 */
#define _XENUM5_PLAIN_DEFINE_GET_NODE_N_I1(DECLPFX, PROPNAME, LEVEL, DECL, Z)			\
	_XENUM5_DOC(Retrieve a level LEVEL node of the PROPNAME data hierarchy.)		\
	DECLPFX BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const				\
	BOOST_PP_CAT(PROPNAME, Node&)								\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM5_PROP_GEN_INDEX0_PARMS(							\
			Enum,									\
			BOOST_PP_CAT(PROPNAME, Index),						\
			LEVEL,									\
			Z									\
		)										\
	)											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return BOOST_PP_CAT(PROPNAME, Nodes)[						\
			_XENUM5_PROP_GEN_NODE_INDEXING(						\
				PROPNAME,							\
				BOOST_PP_CAT(PROPNAME, Index),					\
				LEVEL,								\
				Z								\
			)									\
		];										_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN


#endif // _XENUM5_IMPL_PLAIN_HPP
