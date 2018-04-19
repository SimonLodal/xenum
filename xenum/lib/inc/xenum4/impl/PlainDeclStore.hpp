/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in store class context, for "plain" data type category.
 */
#ifndef _XENUM4_IMPL_PLAIN_DECL_STORE_HPP
#define _XENUM4_IMPL_PLAIN_DECL_STORE_HPP


// ======================================= DATA =================================================
/**
 * Worker for _XENUM4_PROP_DECLS_PLAIN().
 * Declares the data related to a single custom property, implemented in header.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLS_DATA(CTXT, DECL, PROPDEF, PROPNAME, Z)				\
	/* Everything should be private, but this is used in struct ${propname}ValueNames	\
	* which is declared outside this class. */						\
	public:											_XENUM4_NWLN \
_XENUM4_IND1	typedef _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF) BOOST_PP_CAT(PROPNAME, Value);	_XENUM4_NWLN \
	private:										_XENUM4_NWLN \
_XENUM4_IND1	static constexpr const size_t BOOST_PP_CAT(PROPNAME, ValuesSize) = 0		\
			_XENUM4_CALL_VALS(_XENUM4_PLAIN_COUNT_VALUES, CTXT);			_XENUM4_NWLN \
_XENUM4_IND1	static const BOOST_PP_CAT(PROPNAME, Value)					\
			BOOST_PP_CAT(PROPNAME, Values)						\
			[BOOST_PP_CAT(PROPNAME, ValuesSize)];					_XENUM4_NWLN \
		/* Index-nodes only if depth != 0 */						\
		BOOST_PP_CAT(_XENUM4_PLAIN_HDR_DECLS_NODES_, BOOST_PP_BOOL(_XENUM4_PROPDEF_GET_DEPTH(PROPDEF))) \
			(CTXT, DECL, PROPDEF, PROPNAME)


// ============================== COUNT VALUES ==============================
/**
 * Worker for _XENUM4_PLAIN_DECLS_DATA(). Called as XENUM_VALS_* callback.
 * Counts the values of a single custom property of plain type, for a single enum value.
 * VARARGS: All custom property data for the enum value.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_COUNT_VALUES(CTXT, IDENT, ...)						\
	_XENUM4_PLAIN_COUNT_VALUES_I1								\
	(											\
		CTXT,										\
		_XENUM4_PROPDEF_GET_DEPTH(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM4_GET_VARARG(_XENUM4_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__)		\
	)

/**
 * Worker for _XENUM4_PLAIN_COUNT_VALUES().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_COUNT_VALUES_I1(CTXT, DEPTH, DATA)					\
	BOOST_PP_CAT(_XENUM4_PLAIN_COUNT_VALUES_, BOOST_PP_BOOL(DEPTH))				\
	(CTXT, DEPTH, DATA)

/**
 * Worker for _XENUM4_PLAIN_COUNT_VALUES(), for DEPTH==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_COUNT_VALUES_0(CTXT, DEPTH, DATA)						\
	_XENUM4_ADD_ONE()

/**
 * Worker for _XENUM4_PLAIN_COUNT_VALUES(), for DEPTH!=0.
 * Calc state is just a single number; count of values in the entire data tree.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_COUNT_VALUES_1(CTXT, DEPTH, DATA)						\
	+_XENUM4_TUPLETREE_ITERATE_DEPTH_CALC(							\
		DATA,										\
		/* Stop at the leafnodes; no reason to count individual values */		\
		/* when we have the leafnode size. */						\
		BOOST_PP_DEC(DEPTH),								\
		(_XENUM4_PLAIN_COUNT_VALUES_ADD, _XENUM4_TUPLETREE_FILTER_LEAF),		\
		CTXT,										\
		0										\
	)											\

/**
 * Callback for _XENUM4_PLAIN_COUNT_VALUES_1() iteration. Called for each leaf node.
 * @return New state, with counter incremented with number of values in leaf node.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_COUNT_VALUES_ADD(ITERPOS, NODE, CTXT, STATE)				\
	BOOST_PP_ADD(STATE, _XENUM4_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS))			\


// ============================== COUNT NODES ==============================
/**
 * Worker for _XENUM4_PLAIN_HDR_DECLS_DATA(). Does nothing since depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLS_NODES_0(CTXT, DECL, PROPDEF, PROPNAME)

/**
 * Worker for _XENUM4_PLAIN_HDR_DECLS_DATA(). Declares variables related to index nodes (depth>0).
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLS_NODES_1(CTXT, DECL, PROPDEF, PROPNAME)				\
_XENUM4_IND1	static constexpr const size_t BOOST_PP_CAT(PROPNAME, IndexSize) = 0		\
			_XENUM4_CALL_VALS(_XENUM4_PLAIN_COUNT_NODES, CTXT);			_XENUM4_NWLN \
_XENUM4_IND1	typedef typename ::_XENUM4_NS::SelectInt< ::_XENUM4_NS::cmax(			\
				BOOST_PP_CAT(PROPNAME, ValuesSize),				\
				BOOST_PP_CAT(PROPNAME, IndexSize)				\
			) >::type BOOST_PP_CAT(PROPNAME, Index);				_XENUM4_NWLN \
	/* Everything should be private, but this is used by struct ${propname}NodeNames	\
	 * which is declared outside this class. */						\
	public:											_XENUM4_NWLN \
_XENUM4_IND1	typedef ::_XENUM4_NS::IndexNode<BOOST_PP_CAT(PROPNAME, Index)>			\
			BOOST_PP_CAT(PROPNAME, IndexNode);					_XENUM4_NWLN \
	private:										_XENUM4_NWLN \
_XENUM4_IND1	static const BOOST_PP_CAT(PROPNAME, IndexNode)					\
			BOOST_PP_CAT(PROPNAME, IndexNodes) [BOOST_PP_CAT(PROPNAME, IndexSize)];	_XENUM4_NWLN \


// ===================================== FUNCTIONS (HDR) ========================================
/**
 * Worker for _XENUM4_PROP_DECLS_PLAIN().
 * Declares the functions related to a single custom property, implemented in header.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLS_FUNCS(CTXT, PROPDEF, PROPNAME, Z)				\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		_XENUM4_PROPDEF_GET_DEPTH(PROPDEF),						\
		_XENUM4_PLAIN_HDR_DECLS_FUNCS_I1,						\
		PROPNAME									\
	)											\
	_XENUM4_PLAIN_HDR_DECLS_FUNC_GET_VALUE(							\
		PROPNAME,									\
		_XENUM4_PROPDEF_GET_DEPTH(PROPDEF),						\
		Z)

/**
 * Callback worker for _XENUM4_PLAIN_DECLS_FUNCS() iteration.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLS_FUNCS_I1(Z, N, PROPNAME)					\
	_XENUM4_PLAIN_HDR_DECLS_FUNC_GET_NODE(PROPNAME, N, Z)					\
	_XENUM4_PLAIN_HDR_DECLS_FUNC_GET_SIZE(PROPNAME, N, Z)


// ================================== FUNC (HDR): getNode() =====================================
/**
 * Worker for _XENUM4_PLAIN_DECLS_FUNCS().
 * Generates get${propname}Node() getters.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLS_FUNC_GET_NODE(PROPNAME, LEVEL, Z)				\
_XENUM4_IND1	static BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const			\
		BOOST_PP_CAT(PROPNAME, IndexNode&)						\
		BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (				\
			_XENUM4_PROP_GEN_INDEX0_PARMS(						\
				Enum,								\
				BOOST_PP_CAT(PROPNAME, Index),					\
				LEVEL,								\
				Z								\
			)									\
		) {										\
			return BOOST_PP_CAT(PROPNAME, IndexNodes)[				\
				_XENUM4_PROP_GEN_NODE_INDEXING(					\
					PROPNAME,						\
					BOOST_PP_CAT(PROPNAME, Index),				\
					LEVEL,							\
					Z							\
				)								\
			];									\
		}										_XENUM4_NWLN \


// ================================== FUNC (HDR): getSize() =====================================
/**
 * Worker for _XENUM4_PLAIN_DECLS_FUNCS().
 * Generates get${propname}Size() getters.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLS_FUNC_GET_SIZE(PROPNAME, LEVEL, Z)				\
_XENUM4_IND1	static BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const			\
		BOOST_PP_CAT(PROPNAME, Index)							\
		BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (				\
			_XENUM4_PROP_GEN_INDEX0_PARMS(						\
				Enum,								\
				BOOST_PP_CAT(PROPNAME, Index),					\
				LEVEL,								\
				Z								\
			)									\
		) {										\
			return BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (		\
				_XENUM4_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(LEVEL), Z)		\
			)									\
			.size;									\
		}										_XENUM4_NWLN \


// =============================== FUNC (HDR): get$PROPNAME() ===================================
/**
 * Worker for _XENUM4_PLAIN_DECLS_FUNCS().
 * Generates get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLS_FUNC_GET_VALUE(PROPNAME, DEPTH, Z)				\
_XENUM4_IND1	static BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , constexpr) const			\
		BOOST_PP_CAT(PROPNAME, Value&)							\
		BOOST_PP_CAT(get, PROPNAME) (							\
			_XENUM4_PROP_GEN_INDEX0_PARMS(						\
				Enum,								\
				BOOST_PP_CAT(PROPNAME, Index),					\
				DEPTH,								\
				Z								\
			)									\
		) {										\
			return BOOST_PP_CAT(PROPNAME, Values)[					\
				BOOST_PP_CAT(							\
					_XENUM4_PLAIN_GEN_VALUE_INDEXING_,			\
					BOOST_PP_BOOL(DEPTH)					\
				) (PROPNAME, DEPTH, Z)						\
			];									\
		}										_XENUM4_NWLN \

/**
 * Generate value indexing expression for a property having depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_GEN_VALUE_INDEXING_0(PROPNAME, DEPTH, Z)					\
	getIndex(index0)

/**
 * Generate value indexing expression for a property having depth!=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_GEN_VALUE_INDEXING_1(PROPNAME, DEPTH, Z)					\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM4_PROP_GEN_INDEX0_ARGS(DEPTH, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, DEPTH))						\



// ===================================== FUNCTIONS (SRC) ========================================
/**
 * Worker for _XENUM4_PROP_DECLS_PLAIN().
 * Declares the functions related to a single custom property, implemented in source.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DECLS_FUNCS(PROPNAME, DEPTH, CTXT, Z)					\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM4_PROP_SRC_DECLS_GET_SIZE,						\
		PROPNAME									\
	)											\
	_XENUM4_PROP_SRC_DECLS_GET_VALUE(							\
		PROPNAME,									\
		_XENUM4_PROPDEF_GET_PARM_TYPE(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		DEPTH,										\
		Z										\
	)



// ====================================== DEBUG STUFF ===========================================
/**
 * Debugging helper functions. Only enable when needed.
 */
#define _XENUM4_PLAIN_DECLS_DEBUG(CTXT, DECL, PROPDEF, PROPNAME, Z)				\

/*
public:												_XENUM4_NWLN \
_XENUM4_IND1	static void dumpNodes(void) noexcept;						_XENUM4_NWLN \
*/



#endif // _XENUM4_IMPL_PLAIN_DECL_STORE_HPP
