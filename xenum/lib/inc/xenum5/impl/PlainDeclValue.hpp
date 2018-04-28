/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Declarations in value class context, for "plain" data type category.
 */
#ifndef _XENUM5_IMPL_PLAIN_DECL_VALUE_HPP
#define _XENUM5_IMPL_PLAIN_DECL_VALUE_HPP



// ========================================== TYPES =============================================
/**
 * Worker for _XENUM5_PROP_DECLV_PLAIN().
 * Declares the types related to a single custom property, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DECLV_TYPES(PROPNAME, DEPTH)						\
	_XENUM5_DOC(Native type of custom property PROPNAME values.)				\
	using BOOST_PP_CAT(PROPNAME, Value) =							\
		typename Store::BOOST_PP_CAT(PROPNAME, Value);					_XENUM5_NWLN \
	BOOST_PP_CAT(_XENUM5_PLAIN_HDR_DECLV_INDEX_T_, BOOST_PP_BOOL(DEPTH)) (PROPNAME)		\

/**
 * Worker for _XENUM5_PLAIN_DECLV_TYPES().
 * Declares nothing since the property has depth=0.
 */
#define _XENUM5_PLAIN_HDR_DECLV_INDEX_T_0(PROPNAME)						\

/**
 * Worker for _XENUM5_PLAIN_DECLV_TYPES().
 * Declares the ${propname}Index type since the property has depth!=0.
 */
#define _XENUM5_PLAIN_HDR_DECLV_INDEX_T_1(PROPNAME)						\
	_XENUM5_DOC(Integer type big enough to count and index both PROPNAME values and indexnodes.)	\
	using BOOST_PP_CAT(PROPNAME, Index) =							\
		typename Store::BOOST_PP_CAT(PROPNAME, Index);					_XENUM5_NWLN \


// ===================================== FUNCTIONS (HDR) ========================================
/**
 * Worker for _XENUM5_PROP_DECLV_PLAIN().
 * Declares the functions related to a single custom property, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DECLV_FUNCS(PROPNAME, DEPTH, CTXT, Z)					\
	_XENUM5_PLAIN_HDR_DECLV_GET_SIZE(DEPTH, CTXT, Z)					\
	_XENUM5_PLAIN_HDR_DECLV_GET_VALUE(PROPNAME, DEPTH, CTXT, Z)				\


// ================================== FUNC (HDR): getSize() =====================================
/**
 * Worker for _XENUM5_PROP_DECLV_PLAIN().
 * Declares the get${propname}Size() getter for each level.
 */
#define _XENUM5_PLAIN_HDR_DECLV_GET_SIZE(DEPTH, CTXT, Z)					\
	BOOST_PP_CAT(										\
		_XENUM5_PLAIN_HDR_DECLV_GET_SIZE_,						\
		BOOST_PP_BOOL(DEPTH)								\
	) (DEPTH, CTXT, Z)

/**
 * Worker for _XENUM5_PLAIN_DECLV_GET_SIZE().
 * Declares nothing since depth==0.
 */
#define _XENUM5_PLAIN_HDR_DECLV_GET_SIZE_0(DEPTH, CTXT, Z)					\

/**
 * Worker for _XENUM5_PLAIN_HDR_DECLV_GET_SIZE().
 * Declares getters since depth!=0.
 */
#define _XENUM5_PLAIN_HDR_DECLV_GET_SIZE_1(DEPTH, CTXT, Z)					\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PLAIN_HDR_DECLV_GET_SIZE_N,						\
		CTXT										\
	)

/**
 * Worker for _XENUM5_PLAIN_HDR_DECLV_GET_SIZE_1().
 */
#define _XENUM5_PLAIN_HDR_DECLV_GET_SIZE_N(Z, N, CTXT)						\
	_XENUM5_PLAIN_HDR_DECLV_GET_SIZE_N_I1							\
	(											\
		_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM5_PROPDEF_GET_DEPTH(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		Z										\
	)

/**
 * Worker for _XENUM5_PLAIN_HDR_DECLV_FUNC_GET_SIZE_N().
 */
#define _XENUM5_PLAIN_HDR_DECLV_GET_SIZE_N_I1(PROPNAME, DEPTH, LEVEL, Z)			\
	_XENUM5_DOC(										\
	BOOST_PP_IF(BOOST_PP_EQUAL(DEPTH, LEVEL),						\
		Get size of custom property PROPNAME value (number of data elements).,		\
		Get number of BOOST_PP_IF(BOOST_PP_EQUAL(DEPTH, BOOST_PP_INC(LEVEL)),		\
			values in,								\
			childnodes of								\
		) BOOST_PP_IF(BOOST_PP_BOOL(LEVEL),						\
			a level LEVEL node in the data hierarchy of,				\
												\
		) custom property PROPNAME.							\
	))											\
	BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr)						\
	const BOOST_PP_CAT(PROPNAME, Index)&							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (					\
		_XENUM5_PROP_GEN_INDEX1_PARMS(BOOST_PP_CAT(PROPNAME, Index), LEVEL, Z)		\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)					\
	{											\
		return Store::BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
			value									\
			_XENUM5_PROP_GEN_INDEX1_ARGS(LEVEL, Z)					\
		);										\
	}											_XENUM5_NWLN \


// =============================== FUNC (HDR): get$PROPNAME() ===================================
/**
 * Worker for _XENUM5_PROP_DECLV_PLAIN().
 * Declares the get${propname}() value getter.
 */
#define _XENUM5_PLAIN_HDR_DECLV_GET_VALUE(PROPNAME, DEPTH, CTXT, Z)				\
	_XENUM5_DOC(Get custom property PROPNAME value.)					\
	BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , constexpr)						\
	const BOOST_PP_CAT(PROPNAME, Value&)							\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM5_PROP_GEN_INDEX1_PARMS(BOOST_PP_CAT(PROPNAME, Index), DEPTH, Z)		\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)					\
	{											\
		return Store::BOOST_PP_CAT(get, PROPNAME) (					\
			value									\
			_XENUM5_PROP_GEN_INDEX1_ARGS(DEPTH, Z)					\
		);										\
	}											_XENUM5_NWLN \


// ===================================== FUNCTIONS (SRC) ========================================
/**
 * Worker for _XENUM5_PROP_DECLV_PLAIN().
 * Declares the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DECLV_FUNCS(PROPNAME, DEPTH, PROPDEF, CTXT, Z)			\
	_XENUM5_PROP_SRC_DECLV_GET_SIZE(DEPTH, PROPDEF, Z)					\
	_XENUM5_PROP_SRC_DECLV_GET_VALUE(PROPNAME, DEPTH, PROPDEF, Z)				\


#endif // _XENUM5_IMPL_PLAIN_DECL_VALUE_HPP
