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


// ======================================= MAIN (HDR) ===========================================
/**
 * Declare the data and functions related to a single custom property, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DECLV(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_PROP_HDR_DECLV_TYPES(PNAME, DEPTH)						\
	_XENUM5_PLAIN_HDR_DECLV_FUNCS(PNAME, DEPTH, CTXT, Z)					\


// ======================================= MAIN (SRC) ===========================================
/**
 * Declare the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DECLV(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_PLAIN_SRC_DECLV_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\


// ===================================== FUNCTIONS (HDR) ========================================
/**
 * Worker for _XENUM5_PROP_DECLV_PLAIN().
 * Declare the functions related to a single custom property, implemented in header.
 */
// FIXME: Use common _XENUM5_PROP_HDR_DECLV_GET_SIZE() and _XENUM5_PROP_HDR_DECLV_GET_VALUE().
#define _XENUM5_PLAIN_HDR_DECLV_FUNCS(PNAME, DEPTH, CTXT, Z)					\
	_XENUM5_PLAIN_HDR_DECLV_GET_SIZE(DEPTH, CTXT, Z)					\
	_XENUM5_PLAIN_HDR_DECLV_GET_VALUE(PNAME, DEPTH, CTXT, Z)				\


// ================================== FUNC (HDR): getSize() =====================================
/**
 * Worker for _XENUM5_PROP_DECLV_PLAIN().
 * Declare the get${propname}Size() getter for each level.
 */
#define _XENUM5_PLAIN_HDR_DECLV_GET_SIZE(DEPTH, CTXT, Z)					\
	BOOST_PP_CAT(										\
		_XENUM5_PLAIN_HDR_DECLV_GET_SIZE_,						\
		BOOST_PP_BOOL(DEPTH)								\
	) (DEPTH, CTXT, Z)

/**
 * Worker for _XENUM5_PLAIN_DECLV_GET_SIZE().
 * Declare nothing since depth==0.
 */
#define _XENUM5_PLAIN_HDR_DECLV_GET_SIZE_0(DEPTH, CTXT, Z)					\

/**
 * Worker for _XENUM5_PLAIN_HDR_DECLV_GET_SIZE().
 * Declare getters since depth!=0.
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
		_XENUM5_PDEF_GET_NAME(_XENUM5_CTXT_GET_PDEF(CTXT)),				\
		_XENUM5_PDEF_GET_DEPTH(_XENUM5_CTXT_GET_PDEF(CTXT)),				\
		N,										\
		Z										\
	)

/**
 * Worker for _XENUM5_PLAIN_HDR_DECLV_GET_SIZE_N().
 */
#define _XENUM5_PLAIN_HDR_DECLV_GET_SIZE_N_I1(PNAME, DEPTH, LEVEL, Z)				\
	_XENUM5_DOC(										\
	BOOST_PP_IF(BOOST_PP_EQUAL(DEPTH, LEVEL),						\
		Get size of custom property PNAME value (number of data elements).,		\
		Get number of BOOST_PP_IF(BOOST_PP_EQUAL(DEPTH, BOOST_PP_INC(LEVEL)),		\
			values in,								\
			childnodes of								\
		) BOOST_PP_IF(BOOST_PP_BOOL(LEVEL),						\
			a level LEVEL node in the data hierarchy of,				\
												\
		) custom property PNAME.							\
	))											\
	BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr)						\
	const BOOST_PP_CAT(PNAME, Index)&							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Size) (						\
		_XENUM5_PROP_GEN_INDEX1_PARMS(BOOST_PP_CAT(PNAME, Index), LEVEL, Z)		\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)					\
	{											\
		return Store::BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Size) (			\
			value									\
			_XENUM5_PROP_GEN_INDEX1_ARGS(LEVEL, Z)					\
		);										\
	}											_XENUM5_NWLN \


// ================================ FUNC (HDR): get${PNAME}() ===================================
/**
 * Worker for _XENUM5_PROP_DECLV_PLAIN().
 * Declare the get${propname}() value getter.
 */
#define _XENUM5_PLAIN_HDR_DECLV_GET_VALUE(PNAME, DEPTH, CTXT, Z)				\
	_XENUM5_DOC(Get custom property PNAME value.)						\
	BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , constexpr)						\
	const BOOST_PP_CAT(PNAME, Value&)							\
	BOOST_PP_CAT(get, PNAME) (								\
		_XENUM5_PROP_GEN_INDEX1_PARMS(BOOST_PP_CAT(PNAME, Index), DEPTH, Z)		\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)					\
	{											\
		return Store::BOOST_PP_CAT(get, PNAME) (					\
			value									\
			_XENUM5_PROP_GEN_INDEX1_ARGS(DEPTH, Z)					\
		);										\
	}											_XENUM5_NWLN \


// ===================================== FUNCTIONS (SRC) ========================================
/**
 * Worker for _XENUM5_PROP_DECLV_PLAIN().
 * Declare the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DECLV_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_SRC_DECLV_GET_SIZE(DEPTH, PDEF, Z)						\
	_XENUM5_PROP_SRC_DECLV_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\


#endif // _XENUM5_IMPL_PLAIN_DECL_VALUE_HPP
