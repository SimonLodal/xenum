/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in value class context, for "plain" data type category.
 */
#ifndef _XENUM4_IMPL_PLAIN_DECL_VALUE_HPP
#define _XENUM4_IMPL_PLAIN_DECL_VALUE_HPP



// ========================================== TYPES =============================================
/**
 * Worker for _XENUM4_PROP_DECLV_PLAIN().
 * Declares the types related to a single custom property, in value class.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_TYPES(PROPNAME, DEPTH)						\
public:												NWLN \
IND1	using BOOST_PP_CAT(PROPNAME, _t) = typename store_t::BOOST_PP_CAT(PROPNAME, _t);	NWLN \
	BOOST_PP_CAT(_XENUM4_PLAIN_DECLV_INDEX_T_, BOOST_PP_BOOL(DEPTH)) (PROPNAME)		\

/**
 * Worker for _XENUM4_PLAIN_DECLV_TYPES().
 * Declares nothing since the property has depth=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_INDEX_T_0(PROPNAME)							\

/**
 * Worker for _XENUM4_PLAIN_DECLV_TYPES().
 * Declares the ${propname}_index_t since the property has depth!=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_INDEX_T_1(PROPNAME)							\
IND1	using BOOST_PP_CAT(PROPNAME, _index_t) = typename store_t::BOOST_PP_CAT(PROPNAME, _index_t);	NWLN \


// ======================================== FUNCTIONS ===========================================
/**
 * Worker for _XENUM4_PROP_DECLV_PLAIN().
 * Declares the functions related to a single custom property, in value class.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_FUNCS(PROPNAME, DEPTH, CTXT, Z)					\
	_XENUM4_PLAIN_DECLV_GET_SIZE(DEPTH, CTXT, Z)						\
	_XENUM4_PLAIN_DECLV_GET_VALUE(PROPNAME, DEPTH, CTXT, Z)					\


// ==================================== FUNC helpers ============================================
// FIXME: Use common Props.hpp functions instead.
/**
 * Helper to generate a list with a number of indexN function parameters (1..LEVELS).
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GEN_INDEX_PARMS(CTXT, LEVEL, Z)					\
	BOOST_PP_CAT(										\
		_XENUM4_PLAIN_DECLV_GEN_INDEX_PARMS_,						\
		BOOST_PP_BOOL(LEVEL)								\
	) (CTXT, LEVEL, Z)

/**
 * Worker for _XENUM4_PLAIN_DECLV_GEN_INDEX_PARMS().
 * Declares no index parameters since level==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GEN_INDEX_PARMS_0(CTXT, LEVEL, Z)					\

/**
 * Worker for _XENUM4_PLAIN_DECLV_GEN_INDEX_PARMS().
 * Generate a function parameter list with a number of indexN parameters (1..LEVELS).
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GEN_INDEX_PARMS_1(CTXT, LEVEL, Z)					\
	BOOST_PP_REPEAT_ ## Z(									\
		LEVEL,										\
		_XENUM4_PLAIN_DECLV_GEN_INDEX_PARM_N,						\
		CTXT										\
	)											\

/**
 * Callback worker for _XENUM4_PLAIN_DECLV_GEN_INDEX_PARMS_1() iteration over levels.
 * Generates a single index parameter.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GEN_INDEX_PARM_N(Z, N, CTXT)					\
	BOOST_PP_COMMA_IF(BOOST_PP_BOOL(N))							\
	BOOST_PP_CAT(_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)), _index_t)	\
	BOOST_PP_CAT(index, BOOST_PP_INC(N))


/**
 * Helper to generate a list with a number of indexN arguments (1..COUNT).
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GEN_INDEX_ARGS(CTXT, COUNT, Z)					\
	BOOST_PP_REPEAT_ ## Z(									\
		COUNT,										\
		_XENUM4_PLAIN_DECLV_GEN_INDEX_ARG_N,						\
		PROPNAME									\
	)

/**
 * Helper to generate a single indexN argument.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GEN_INDEX_ARG_N(Z, N, CTXT)						\
	, BOOST_PP_CAT(index, BOOST_PP_INC(N))


// =================================== FUNC: getSize() ==========================================
/**
 * Worker for _XENUM4_PROP_DECLV_PLAIN().
 * Declares the get${propname}Size() getter for each level.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GET_SIZE(DEPTH, CTXT, Z)						\
	BOOST_PP_CAT(										\
		_XENUM4_PLAIN_DECLV_GET_SIZE_,							\
		BOOST_PP_BOOL(DEPTH)								\
	) (DEPTH, CTXT, Z)

/**
 * Worker for _XENUM4_PLAIN_DECLV_GET_SIZE().
 * Declares nothing since depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GET_SIZE_0(DEPTH, CTXT, Z)						\

/**
 * Worker for _XENUM4_PLAIN_DECLV_GET_SIZE().
 * Declares getters since depth!=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GET_SIZE_1(DEPTH, CTXT, Z)						\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM4_PLAIN_DECLV_GET_SIZE_N,							\
		CTXT										\
	)

/**
 * Worker for _XENUM4_PLAIN_DECLV_GET_SIZE_1().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GET_SIZE_N(Z, N, CTXT)						\
	_XENUM4_PLAIN_DECLV_GET_SIZE_N_I1							\
	(											\
		CTXT,										\
		_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		Z										\
	)

/**
 * Worker for _XENUM4_PLAIN_DECLV_FUNC_GET_SIZE_N().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GET_SIZE_N_I1(CTXT, PROPNAME, LEVEL, Z)				\
IND1	BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const BOOST_PP_CAT(PROPNAME, _index_t)	\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (					\
		_XENUM4_PLAIN_DECLV_GEN_INDEX_PARMS(CTXT, LEVEL, Z)				\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)					\
	{											\
		return store_t::BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (		\
			value									\
			_XENUM4_PLAIN_DECLV_GEN_INDEX_ARGS(CTXT, LEVEL, Z)			\
		);										\
	}											\
	NWLN


// ================================ FUNC: get$PROPNAME() ========================================
/**
 * Worker for _XENUM4_PROP_DECLV_PLAIN().
 * Declares the get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_DECLV_GET_VALUE(PROPNAME, DEPTH, CTXT, Z)					\
IND1	BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , constexpr) const BOOST_PP_CAT(PROPNAME, _t&)	\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM4_PLAIN_DECLV_GEN_INDEX_PARMS(CTXT, DEPTH, Z)				\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)					\
	{											\
		return store_t::BOOST_PP_CAT(get, PROPNAME) (					\
			value									\
			_XENUM4_PLAIN_DECLV_GEN_INDEX_ARGS(CTXT, DEPTH, Z)			\
		);										\
	}											\
	NWLN


#endif // _XENUM4_IMPL_PLAIN_DECL_VALUE_HPP
