/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in container class context, for "plain" data type category.
 */
#ifndef _XENUM3_IMPL_PLAIN_DECL_CNTNR_HPP
#define _XENUM3_IMPL_PLAIN_DECL_CNTNR_HPP


// ======================================= DATA =================================================
/**
 * Worker for _XENUM3_PROP_DECLC_PLAIN().
 * Declares the data related to a single custom property.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_DATA(CTXT, DECL, PROPDEF, PROPNAME, Z)				\
public:												NWLN \
IND1	typedef _XENUM3_PROPDEF_GET_REAL_TYPE(PROPDEF) BOOST_PP_CAT(PROPNAME, _t);		NWLN \
protected:											NWLN \
IND1	static constexpr const size_t BOOST_PP_CAT(PROPNAME, _valuecount_) = 0			\
		_XENUM3_CALL_VALS(_XENUM3_PLAIN_COUNT_VALUES, CTXT);				NWLN \
/* This should be protected, but it's size must be compared to struct ${propname}_ValueNames_t	\
 * which is declared outside this class. */							\
public:												NWLN \
IND1	static const BOOST_PP_CAT(PROPNAME, _t)							\
		BOOST_PP_CAT(PROPNAME, _values_)						\
		[BOOST_PP_CAT(PROPNAME, _valuecount_)];						NWLN \
	/* Index-nodes only if depth != 0 */							\
	BOOST_PP_CAT(_XENUM3_PLAIN_DECLC_NODES_, BOOST_PP_BOOL(_XENUM3_PROPDEF_GET_DEPTH(PROPDEF))) \
		(CTXT, DECL, PROPDEF, PROPNAME)


// ============================== COUNT VALUES ==============================
/**
 * Worker for _XENUM3_PLAIN_DECLC_DATA(). Called as XENUM_VALS_* callback.
 * Counts the values of a single custom property of plain type, for a single enum value.
 * VARARGS: All custom property data for the enum value.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_COUNT_VALUES(CTXT, IDENT, ...)						\
	_XENUM3_PLAIN_COUNT_VALUES_I1								\
	(											\
		CTXT,										\
		_XENUM3_PROPDEF_GET_DEPTH(_XENUM3_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM3_GET_VARARG(_XENUM3_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__)		\
	)

/**
 * Worker for _XENUM3_PLAIN_COUNT_VALUES().
 * @hideinitializer
 */
#define _XENUM3_PLAIN_COUNT_VALUES_I1(CTXT, DEPTH, DATA)					\
	BOOST_PP_CAT(_XENUM3_PLAIN_COUNT_VALUES_, BOOST_PP_BOOL(DEPTH))				\
	(CTXT, DEPTH, DATA)

/**
 * Worker for _XENUM3_PLAIN_COUNT_VALUES(), for DEPTH==0.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_COUNT_VALUES_0(CTXT, DEPTH, DATA)						\
	_XENUM3_ADD_ONE()

/**
 * Worker for _XENUM3_PLAIN_COUNT_VALUES(), for DEPTH!=0.
 * Calc state is just a single number; count of values in the entire data tree.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_COUNT_VALUES_1(CTXT, DEPTH, DATA)						\
	+_XENUM3_TUPLETREE_ITERATE_DEPTH_CALC(							\
		DATA,										\
		/* Stop at the leafnodes; no reason to count individual values */		\
		/* when we have the leafnode size. */						\
		BOOST_PP_DEC(DEPTH),								\
		(_XENUM3_PLAIN_COUNT_VALUES_ADD, _XENUM3_TUPLETREE_FILTER_LEAF),		\
		CTXT,										\
		0										\
	)											\

/**
 * Callback for _XENUM3_PLAIN_COUNT_VALUES_1() iteration. Called for each leaf node.
 * @return New state, with counter incremented with number of values in leaf node.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_COUNT_VALUES_ADD(ITERPOS, NODE, CTXT, STATE)				\
	BOOST_PP_ADD(STATE, _XENUM3_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS))			\


// ============================== COUNT NODES ==============================
/**
 * Worker for _XENUM3_PLAIN_DECLC_DATA(). Does nothing since depth==0.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_NODES_0(CTXT, DECL, PROPDEF, PROPNAME)

/**
 * Worker for _XENUM3_PLAIN_DECLC_DATA(). Declares variables related to index nodes (depth>0).
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_NODES_1(CTXT, DECL, PROPDEF, PROPNAME)				\
protected:											NWLN \
IND1	static constexpr const size_t BOOST_PP_CAT(PROPNAME, _nodecount_) = 0			\
		_XENUM3_CALL_VALS(_XENUM3_PLAIN_COUNT_NODES, CTXT);				NWLN \
public:												NWLN \
IND1	typedef typename ::_XENUM3_NS::SelectInt< ::_XENUM3_NS::cmax(				\
			BOOST_PP_CAT(PROPNAME, _valuecount_),					\
			BOOST_PP_CAT(PROPNAME, _nodecount_)					\
		) >::type BOOST_PP_CAT(PROPNAME, _index_t);					NWLN \
/* This should be protected, but it is used by struct ${propname}_NodeNames_t	\
 * which is declared outside this class. */							\
IND1	typedef ::_XENUM3_NS::IndexNode<BOOST_PP_CAT(PROPNAME, _index_t)>			\
		BOOST_PP_CAT(PROPNAME, _IndexNode_t);						NWLN \
/* This should be protected, but it's size must be compared to struct ${propname}_NodeNames_t	\
 * which is declared outside this class. */							\
IND1	static const BOOST_PP_CAT(PROPNAME, _IndexNode_t)					\
		BOOST_PP_CAT(PROPNAME, _nodes_) [BOOST_PP_CAT(PROPNAME, _nodecount_)];		NWLN \

/**
 * Worker for _XENUM3_PLAIN_DECLC_NODES_1(). Called as XENUM_VALS_* callback.
 * Counts the indexnodes of a single custom property, for a single enum value.
 * VARARGS: All custom property data for the enum value.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_COUNT_NODES(CTXT, IDENT, ...)						\
	+_XENUM3_TUPLETREE_ITERATE_DEPTH_CALC(							\
		_XENUM3_GET_VARARG(_XENUM3_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		/* Only count nodes, not leaf values. */					\
		BOOST_PP_DEC(_XENUM3_PROPDEF_GET_DEPTH(_XENUM3_CTXT_GET_PROPDEF(CTXT))),	\
		(_XENUM3_PLAIN_COUNT_NODES_ADD),						\
		CTXT,										\
		0										\
	)											\

/**
 * Callback for _XENUM3_PLAIN_COUNT_NODES() iteration. Called for each node.
 * Add +1 for each indexnode.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_COUNT_NODES_ADD(ITERPOS, NODE, CTXT, STATE)				\
	BOOST_PP_INC(STATE)


// ======================================= FUNCTIONS ============================================
/**
 * Worker for _XENUM3_PROP_DECLC_PLAIN().
 * Declares the functions related to a single custom property.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_FUNCS(CTXT, PROPDEF, PROPNAME, Z)					\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		_XENUM3_PROPDEF_GET_DEPTH(PROPDEF),						\
		_XENUM3_PLAIN_DECLC_FUNCS_I1,							\
		PROPNAME									\
	)											\
	_XENUM3_PLAIN_DECLC_FUNC_GET_VALUE(							\
		PROPNAME,									\
		_XENUM3_PROPDEF_GET_DEPTH(PROPDEF),						\
		Z)

/**
 * Callback worker for _XENUM3_PLAIN_DECLC_FUNCS() iteration.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_FUNCS_I1(Z, N, PROPNAME)						\
	_XENUM3_PLAIN_DECLC_FUNC_GET_NODE(PROPNAME, N, Z)					\
	_XENUM3_PLAIN_DECLC_FUNC_GET_SIZE(PROPNAME, N, Z)


// ==================================== FUNC helpers ============================================
/**
 * Helper to generate a list with a number of indexN function parameters (0..LEVELS).
 * @hideinitializer
 */
// FIXME: Use _XENUM3_PROP_GEN_INDEX0_PARMS() instead.
#define _XENUM3_PLAIN_DECLC_GEN_INDEX_PARMS(PROPNAME, LEVELS, Z)				\
	BOOST_PP_REPEAT_ ## Z(									\
		BOOST_PP_INC(LEVELS),								\
		_XENUM3_PLAIN_DECLC_GEN_INDEX_PARM_N,						\
		PROPNAME									\
	)											\

/**
 * Callback worker for _XENUM3_PLAIN_DECLC_GEN_INDEX_PARMS() iteration over levels.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_GEN_INDEX_PARM_N(Z, N, PROPNAME)					\
	BOOST_PP_CAT(_XENUM3_PLAIN_DECLC_GEN_INDEX_PARM_, BOOST_PP_BOOL(N))			\
		(PROPNAME, N)

/**
 * Helper for _XENUM3_PLAIN_DECLC_GEN_INDEX_PARM_N().
 * Generate the first index parameter.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_GEN_INDEX_PARM_0(PROPNAME, LEVEL)					\
	Enum index0

/**
 * Helper for _XENUM3_PLAIN_DECLC_GEN_INDEX_PARM_N().
 * Generate the n'th index parameter (for n>0).
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_GEN_INDEX_PARM_1(PROPNAME, LEVEL)					\
	, BOOST_PP_CAT(PROPNAME, _index_t) BOOST_PP_CAT(index, LEVEL)


/**
 * Helper to generate a list with a number of indexN arguments (0..COUNT-1).
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_GEN_INDEX_ARGS(COUNT, Z)						\
	BOOST_PP_REPEAT_ ## Z(									\
		COUNT,										\
		_XENUM3_PLAIN_DECLC_GEN_INDEX_ARG_N,						\
												\
	)

/**
 * Helper to generate a single indexN function argument.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_GEN_INDEX_ARG_N(Z, N, X)						\
	BOOST_PP_COMMA_IF(BOOST_PP_BOOL(N)) BOOST_PP_CAT(index, N)


// =================================== FUNC: getNode() ==========================================
/**
 * Worker for _XENUM3_PLAIN_DECLC_FUNCS().
 * Generates get${propname}Node() getters.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_FUNC_GET_NODE(PROPNAME, N, Z)					\
protected:											NWLN \
IND1	static BOOST_PP_IF(BOOST_PP_BOOL(N), , constexpr) const					\
	BOOST_PP_CAT(PROPNAME, _IndexNode_t&)							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM3_PLAIN_DECLC_GEN_INDEX_PARMS(PROPNAME, N, Z)				\
	) {											\
		return BOOST_PP_CAT(PROPNAME, _nodes_)[						\
/* FIXME: Use _XENUM3_PROP_GEN_NODE_INDEXING() instead */ \
			BOOST_PP_CAT(								\
				_XENUM3_PLAIN_GEN_NODE_INDEXING_,				\
				BOOST_PP_BOOL(N)						\
			) (PROPNAME, N, Z)							\
		];										\
	}											\
	NWLN

/**
 * Worker for _XENUM3_PLAIN_DECLC_FUNC_GET_NODE() iteration, for level==0.
 * Adds node indexing for level 0; direct index.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_GEN_NODE_INDEXING_0(PROPNAME, N, Z)					\
	static_cast<BOOST_PP_CAT(PROPNAME, _index_t)>(index0)					\

/**
 * Worker for _XENUM3_PLAIN_DECLC_FUNC_GET_NODE() iteration, for level!=0.
 * Adds chained node indexing using calls.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_GEN_NODE_INDEXING_1(PROPNAME, N, Z)					\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM3_PLAIN_DECLC_GEN_INDEX_ARGS(N, Z)					\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, N))


// =================================== FUNC: getSize() ==========================================
/**
 * Worker for _XENUM3_PLAIN_DECLC_FUNCS().
 * Generates get${propname}Size() getters.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_FUNC_GET_SIZE(PROPNAME, N, Z)					\
public:												NWLN \
IND1	static BOOST_PP_IF(BOOST_PP_BOOL(N), , constexpr) const					\
	BOOST_PP_CAT(PROPNAME, _index_t&)							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (					\
		_XENUM3_PLAIN_DECLC_GEN_INDEX_PARMS(PROPNAME, N, Z)				\
	) {											\
		return BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (			\
			_XENUM3_PLAIN_DECLC_GEN_INDEX_ARGS(BOOST_PP_INC(N), Z)			\
		)										\
		.size;										\
	}											\
	NWLN


// ================================ FUNC: get$PROPNAME() ========================================
/**
 * Worker for _XENUM3_PLAIN_DECLC_FUNCS().
 * Generates get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_DECLC_FUNC_GET_VALUE(PROPNAME, DEPTH, Z)					\
public:												NWLN \
IND1	static BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , constexpr) const				\
	BOOST_PP_CAT(PROPNAME, _t&)								\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM3_PLAIN_DECLC_GEN_INDEX_PARMS(PROPNAME, DEPTH, Z)				\
	) {											\
		return BOOST_PP_CAT(PROPNAME, _values_)[					\
			BOOST_PP_CAT(								\
				_XENUM3_PLAIN_GEN_VALUE_INDEXING_,				\
				BOOST_PP_BOOL(DEPTH)						\
			) (PROPNAME, DEPTH, Z)							\
		];										\
	}											\
	NWLN

/**
 * Generate value indexing expression for a property having depth==0.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_GEN_VALUE_INDEXING_0(PROPNAME, DEPTH, Z)					\
	static_cast<index_t>(index0)

/**
 * Generate value indexing expression for a property having depth!=0.
 * @hideinitializer
 */
#define _XENUM3_PLAIN_GEN_VALUE_INDEXING_1(PROPNAME, DEPTH, Z)					\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM3_PLAIN_DECLC_GEN_INDEX_ARGS(DEPTH, Z)					\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, DEPTH))						\



// ====================================== DEBUG STUFF ===========================================
/**
 * Debugging helper functions. Only enable when needed.
 */
#define _XENUM3_PLAIN_DECLC_DEBUG(CTXT, DECL, PROPDEF, PROPNAME, Z)				\

/*
public:												NWLN \
IND1	static void dumpNodes(void) noexcept;							NWLN \
*/



#endif // _XENUM3_IMPL_PLAIN_DECL_CNTNR_HPP
