/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM3_IMPL_DECLARE_CNTNR_PROPS_HPP
#define _XENUM3_IMPL_DECLARE_CNTNR_PROPS_HPP


// ==============================================================================================
/**
 * Main entry function for declaring custom properties on the enum values.
 * Main loop is a REPEAT since that is the only kind of loop that provides a zero-based index
 * counter.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROPS(CTXT)							\
	BOOST_PP_REPEAT(									\
		BOOST_PP_SEQ_SIZE(_XENUM3_DECL_GET_PROPDEFS(_XENUM3_CTXT_GET_DECL(CTXT))),	\
		_XENUM3_DECLARE_CNTNR_PROPS_I1,							\
		CTXT										\
		)

/**
 * Callback for _XENUM3_DECLARE_CNTNR_PROPS() loop.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROPS_I1(Z, N, CTXT)						\
	_XENUM3_DECLARE_CNTNR_PROPS_I2								\
	(											\
		_XENUM3_CTXT_SET_PROPINDEX(CTXT, N),						\
		_XENUM3_DECL_GET_PROPDEFN(_XENUM3_CTXT_GET_DECL(CTXT), N),			\
		Z										\
	)

/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROPS_I1().
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROPS_I2(CTXT, PROPDEF, Z)					\
	_XENUM3_DECLARE_CNTNR_PROP(								\
		_XENUM3_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		_XENUM3_CTXT_GET_DECL(CTXT),							\
		PROPDEF,									\
		Z										\
	)

/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROPS_I2().
 * Declares a single custom property.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP(CTXT, DECL, PROPDEF, Z)					\
	_XENUM3_DECLARE_CNTNR_PROP_DATA(CTXT, DECL, PROPDEF, _XENUM3_PROPDEF_GET_NAME(PROPDEF), Z)	\
	_XENUM3_DECLARE_CNTNR_PROP_FUNCS(CTXT, DECL, PROPDEF, _XENUM3_PROPDEF_GET_NAME(PROPDEF), Z)	\
	_XENUM3_DECLARE_CNTNR_PROP_DEBUG(CTXT, DECL, PROPDEF, _XENUM3_PROPDEF_GET_NAME(PROPDEF), Z)	\

/*
_DECLARE_CNTNR_PROP: ctxt=CTXT decl=DECL propdef=PROPDEF NWLN \
*/


// ======================================= DATA =================================================
/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP().
 * Declares the data related to a single custom property.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_DATA(CTXT, DECL, PROPDEF, PROPNAME, Z)			\
public:												NWLN \
IND1	typedef _XENUM3_PROPDEF_GET_REAL_TYPE(PROPDEF) BOOST_PP_CAT(PROPNAME, _t);		NWLN \
protected:											NWLN \
IND1	static constexpr const size_t BOOST_PP_CAT(PROPNAME, _valuecount_) = 0			\
		_XENUM3_CALL_VALS(								\
			BOOST_PP_CAT(								\
				_XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_,			\
				_XENUM3_PROPDEF_GET_TYPCAT(PROPDEF)				\
			),									\
			CTXT									\
		);										NWLN \
/* This should be protected, but it's size must be compared to struct ${propname}_ValueNames_t	\
 * which is declared outside this class. */							\
public:												NWLN \
IND1	static const BOOST_PP_CAT(PROPNAME, _t)							\
		BOOST_PP_CAT(PROPNAME, _values_)						\
		[BOOST_PP_CAT(PROPNAME, _valuecount_)];						NWLN \
	/* Index-nodes only if depth != 0 */							\
	BOOST_PP_CAT(_XENUM3_DECLARE_CNTNR_PROP_NODES_, BOOST_PP_BOOL(_XENUM3_PROPDEF_GET_DEPTH(PROPDEF))) \
		(CTXT, DECL, PROPDEF, PROPNAME)


// ============================== COUNT VALUES ==============================
/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_DATA(). Called as XENUM_VALS_* callback.
 * Counts the values of a single custom property, for a single enum value.
 * VARARGS: All custom property data for the enum value.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN(CTXT, IDENT, ...)				\
	_XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN_DO					\
	(											\
		CTXT,										\
		_XENUM3_PROPDEF_GET_DEPTH(_XENUM3_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM3_GET_VARARG(_XENUM3_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__)		\
	)
/*
_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN: ctxt=CTXT ident=IDENT argc=BOOST_PP_VARIADIC_SIZE(__VA_ARGS__) argv=BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__) NWLN \
*/

/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN().
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN_DO(CTXT, DEPTH, DATA)			\
	BOOST_PP_CAT(_XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN_DO_, BOOST_PP_BOOL(DEPTH))	\
	(CTXT, DEPTH, DATA)

/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN_DO(), for DEPTH==0.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN_DO_0(CTXT, DEPTH, DATA)			\
	_XENUM3_ADD_ONE()

/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN_DO(), for DEPTH!=0.
 * Calc state is just a single number; count of values in the entire data tree.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN_DO_1(CTXT, DEPTH, DATA)			\
	+_XENUM3_TUPLETREE_ITERATE_DEPTH_CALC(							\
		DATA,										\
		/* Stop at the leafnodes; no reason to count individual values */		\
		/* when we have the leafnode size. */						\
		BOOST_PP_DEC(DEPTH),								\
		(_XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN_ADD_LEAF, _XENUM3_TUPLETREE_FILTER_LEAF),	\
		CTXT,										\
		0										\
	)											\

/**
 * Callback for _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN_DO_1() iteration. Called for
 * each node.
 * @return New state, with counter incremented with number of values in leaf node.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_PLAIN_ADD_LEAF(ITERPOS, NODE, CTXT, STATE)	\
	BOOST_PP_ADD(STATE, _XENUM3_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS))			\


/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_DATA(). Called as XENUM_VALS_* callback.
 * Counts the number of chars in all the string values of a single custom property, for a
 * single enum value.
 * VARARGS: All custom property data for the enum value.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING(CTXT, IDENT, ...)			\
	_XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING_DO					\
	(											\
		CTXT,										\
		_XENUM3_PROPDEF_GET_DEPTH(_XENUM3_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM3_GET_VARARG(_XENUM3_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__)		\
	)
/*
NWLN _DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING: ident=IDENT ctxt=CTXT argc=BOOST_PP_VARIADIC_SIZE(__VA_ARGS__) argv=BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__) NWLN \
*/

/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING().
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING_DO(CTXT, DEPTH, DATA)			\
	_XENUM3_TUPLETREE_ITERATE_DEPTH_GEN(							\
		DATA,										\
		DEPTH,										\
		(_XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING_ADD_ONE,			\
		 _XENUM3_TUPLETREE_FILTER_LEAF),						\
		CTXT										\
	)											\


#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING_ADD_ONE(ITERPOS, NODE, CTXT)		\
	+sizeof(NODE)


// ============================== COUNT NODES ==============================
/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_DATA(). Does nothing since depth==0.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_NODES_0(CTXT, DECL, PROPDEF, PROPNAME)
/*
_DECLARE_CNTNR_PROP_NODES_0: ctxt=CTXT NWLN
*/

/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_DATA(). Declares variables related to index nodes (depth>0).
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_NODES_1(CTXT, DECL, PROPDEF, PROPNAME)			\
protected:											NWLN \
IND1	static constexpr const size_t BOOST_PP_CAT(PROPNAME, _nodecount_) = 0			\
		_XENUM3_CALL_VALS(_XENUM3_DECLARE_CNTNR_PROP_COUNT_NODES, CTXT);		NWLN \
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
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_NODES_1(). Called as XENUM_VALS_* callback.
 * Counts the indexnodes of a single custom property, for a single enum value.
 * VARARGS: All custom property data for the enum value.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_NODES(CTXT, IDENT, ...)				\
	+_XENUM3_TUPLETREE_ITERATE_DEPTH_CALC(							\
		_XENUM3_GET_VARARG(_XENUM3_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		/* Only count nodes, not leaf values. */					\
		BOOST_PP_DEC(_XENUM3_PROPDEF_GET_DEPTH(_XENUM3_CTXT_GET_PROPDEF(CTXT))),	\
		(_XENUM3_DECLARE_CNTNR_PROP_NODECOUNT_ADD),					\
		CTXT,										\
		0										\
	)											\

/**
 * Callback for _XENUM3_DECLARE_CNTNR_PROP_COUNT_NODES() iteration. Called for each node.
 * Add +1 for each indexnode.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_NODECOUNT_ADD(ITERPOS, NODE, CTXT, STATE)			\
	BOOST_PP_INC(STATE)


// ======================================= FUNCTIONS ============================================
/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP().
 * Declares the functions related to a single custom property.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNCS(CTXT, DECL, PROPDEF, PROPNAME, Z)			\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		_XENUM3_PROPDEF_GET_DEPTH(PROPDEF),						\
		_XENUM3_DECLARE_CNTNR_PROP_FUNCS_I1,						\
		PROPNAME									\
	)											\
	_XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_VALUE(						\
		PROPNAME,									\
		_XENUM3_PROPDEF_GET_DEPTH(PROPDEF),						\
		Z)

/**
 * Callback worker for _XENUM3_DECLARE_CNTNR_PROP_FUNCS() iteration.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNCS_I1(Z, N, PROPNAME)					\
	_XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_NODE(PROPNAME, N, Z)				\
	_XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_SIZE(PROPNAME, N, Z)


// ==================================== FUNC helpers ============================================
/**
 * Helper to generate a list with a number of indexN function parameters (0..LEVELS).
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARMS(PROPNAME, LEVELS, Z)			\
	BOOST_PP_REPEAT_ ## Z(									\
		BOOST_PP_INC(LEVELS),								\
		_XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARM_N,				\
		PROPNAME									\
	)											\

/**
 * Callback worker for _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARMS() iteration over levels.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARM_N(Z, N, PROPNAME)			\
	BOOST_PP_CAT(_XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARM_, BOOST_PP_BOOL(N))	\
		(PROPNAME, N)

/**
 * Helper for _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARM_N().
 * Generate the first index parameter.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARM_0(PROPNAME, LEVEL)			\
	Enum index0

/**
 * Helper for _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARM_N().
 * Generate the n'th index parameter (for n>0).
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARM_1(PROPNAME, LEVEL)			\
	, BOOST_PP_CAT(PROPNAME, _index_t) BOOST_PP_CAT(index, LEVEL)


/**
 * Helper to generate a list with a number of indexN arguments (0..COUNT-1).
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_ARGS(COUNT, Z)				\
	BOOST_PP_REPEAT_ ## Z(									\
		COUNT,										\
		_XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_ARG_N,				\
												\
	)

/**
 * Helper to generate a single indexN function argument.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_ARG_N(Z, N, X)				\
	BOOST_PP_COMMA_IF(BOOST_PP_BOOL(N)) BOOST_PP_CAT(index, N)


// =================================== FUNC: getNode() ==========================================
/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_FUNCS_I1().
 * Generates get${propname}Node() getters.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_NODE(PROPNAME, N, Z)				\
protected:											NWLN \
IND1	static BOOST_PP_IF(BOOST_PP_BOOL(N), , constexpr) const					\
	BOOST_PP_CAT(PROPNAME, _IndexNode_t&)							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARMS(PROPNAME, N, Z)		\
	) {											\
		return BOOST_PP_CAT(PROPNAME, _nodes_)[						\
			BOOST_PP_CAT(								\
				_XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_NODE_INDEXING_,		\
				BOOST_PP_BOOL(N)						\
			) (PROPNAME, N, Z)							\
		];										\
	}											\
	NWLN

/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_NODE() iteration, for level==0.
 * Adds node indexing for level 0; direct index.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_NODE_INDEXING_0(PROPNAME, N, Z)			\
	static_cast<BOOST_PP_CAT(PROPNAME, _index_t)>(index0)					\

/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_NODE() iteration, for level!=0.
 * Adds chained node indexing using calls.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_NODE_INDEXING_1(PROPNAME, N, Z)			\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_ARGS(N, Z)				\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, N))


// =================================== FUNC: getSize() ==========================================
/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_FUNCS_I1().
 * Generates get${propname}Size() getters.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_SIZE(PROPNAME, N, Z)				\
public:												NWLN \
IND1	static BOOST_PP_IF(BOOST_PP_BOOL(N), , constexpr) const					\
	BOOST_PP_CAT(PROPNAME, _index_t&)							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (					\
		_XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARMS(PROPNAME, N, Z)		\
	) {											\
		return BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (			\
			_XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_ARGS(BOOST_PP_INC(N), Z)	\
		)										\
		.size;										\
	}											\
	NWLN


// ================================ FUNC: get$PROPNAME() ========================================
/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_FUNCS().
 * Generates get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_VALUE(PROPNAME, DEPTH, Z)				\
public:												NWLN \
IND1	static BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , constexpr) const				\
	BOOST_PP_CAT(PROPNAME, _t&)								\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_PARMS(PROPNAME, DEPTH, Z)		\
	) {											\
		return BOOST_PP_CAT(PROPNAME, _values_)[					\
			BOOST_PP_CAT(								\
				_XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_VALUE_INDEXING_,		\
				BOOST_PP_BOOL(DEPTH)						\
			) (PROPNAME, DEPTH, Z)							\
		];										\
	}											\
	NWLN

/**
 * Generate value indexing expression for a property having depth==0.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_VALUE_INDEXING_0(PROPNAME, DEPTH, Z)		\
	static_cast<index_t>(index0)

/**
 * Generate value indexing expression for a property having depth!=0.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_CNTNR_PROP_FUNC_GET_VALUE_INDEXING_1(PROPNAME, DEPTH, Z) \
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM3_DECLARE_CNTNR_PROP_FUNCS_GEN_INDEX_ARGS(DEPTH, Z)			\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, DEPTH))						\



// ====================================== DEBUG STUFF ===========================================
/**
 * Debugging helper functions. Only enable when needed.
 */
#define _XENUM3_DECLARE_CNTNR_PROP_DEBUG(CTXT, DECL, PROPDEF, PROPNAME, Z)			\

/*
public:												NWLN \
IND1	static void dumpNodes(void) noexcept;							NWLN \
*/



#endif // _XENUM3_IMPL_DECLARE_CNTNR_PROPS_HPP
