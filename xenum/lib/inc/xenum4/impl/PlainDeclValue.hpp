/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Declarations in value class context, for "plain" data type category.
 */
#ifndef _XENUM4_IMPL_PLAIN_DECL_VALUE_HPP
#define _XENUM4_IMPL_PLAIN_DECL_VALUE_HPP



// ========================================== TYPES =============================================
/**
 * Worker for _XENUM4_PROP_DECLV_PLAIN().
 * Declares the types related to a single custom property, implemented in header.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLV_TYPES(PROPNAME, DEPTH)						\
_XENUM4_INDENT_SUB										\
public:												_XENUM4_NWLN \
	_XENUM4_DOC(Native type of custom property PROPNAME values.)				\
	using BOOST_PP_CAT(PROPNAME, Value) =							\
		typename Store::BOOST_PP_CAT(PROPNAME, Value);					_XENUM4_NWLN \
	BOOST_PP_CAT(_XENUM4_PLAIN_HDR_DECLV_INDEX_T_, BOOST_PP_BOOL(DEPTH)) (PROPNAME)		\

/**
 * Worker for _XENUM4_PLAIN_DECLV_TYPES().
 * Declares nothing since the property has depth=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLV_INDEX_T_0(PROPNAME)						\

/**
 * Worker for _XENUM4_PLAIN_DECLV_TYPES().
 * Declares the ${propname}Index type since the property has depth!=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLV_INDEX_T_1(PROPNAME)						\
	_XENUM4_DOC(Integer type big enough to count and index both PROPNAME values and indexnodes.)	\
	using BOOST_PP_CAT(PROPNAME, Index) =							\
		typename Store::BOOST_PP_CAT(PROPNAME, Index);					_XENUM4_NWLN \


// ===================================== FUNCTIONS (HDR) ========================================
/**
 * Worker for _XENUM4_PROP_DECLV_PLAIN().
 * Declares the functions related to a single custom property, implemented in header.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLV_FUNCS(PROPNAME, DEPTH, CTXT, Z)					\
	_XENUM4_PLAIN_HDR_DECLV_GET_SIZE(DEPTH, CTXT, Z)					\
	_XENUM4_PLAIN_HDR_DECLV_GET_VALUE(PROPNAME, DEPTH, CTXT, Z)				\


// ================================== FUNC (HDR): getSize() =====================================
/**
 * Worker for _XENUM4_PROP_DECLV_PLAIN().
 * Declares the get${propname}Size() getter for each level.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLV_GET_SIZE(DEPTH, CTXT, Z)					\
	BOOST_PP_CAT(										\
		_XENUM4_PLAIN_HDR_DECLV_GET_SIZE_,						\
		BOOST_PP_BOOL(DEPTH)								\
	) (DEPTH, CTXT, Z)

/**
 * Worker for _XENUM4_PLAIN_DECLV_GET_SIZE().
 * Declares nothing since depth==0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLV_GET_SIZE_0(DEPTH, CTXT, Z)					\

/**
 * Worker for _XENUM4_PLAIN_HDR_DECLV_GET_SIZE().
 * Declares getters since depth!=0.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLV_GET_SIZE_1(DEPTH, CTXT, Z)					\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM4_PLAIN_HDR_DECLV_GET_SIZE_N,						\
		CTXT										\
	)

/**
 * Worker for _XENUM4_PLAIN_HDR_DECLV_GET_SIZE_1().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLV_GET_SIZE_N(Z, N, CTXT)						\
	_XENUM4_PLAIN_HDR_DECLV_GET_SIZE_N_I1							\
	(											\
		CTXT,										\
		_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		Z										\
	)

/**
 * Worker for _XENUM4_PLAIN_HDR_DECLV_FUNC_GET_SIZE_N().
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLV_GET_SIZE_N_I1(CTXT, PROPNAME, LEVEL, Z)				\
	_XENUM4_DOC(@copydoc Store::BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size)		\
		(_XENUM4_PROP_GEN_INDEX0_PARMS(Enum, BOOST_PP_CAT(PROPNAME, Index), LEVEL, Z)))	\
	BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr)						\
	const BOOST_PP_CAT(PROPNAME, Index)							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (					\
		_XENUM4_PROP_GEN_INDEX1_PARMS(BOOST_PP_CAT(PROPNAME, Index), LEVEL, Z)		\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)					\
	{											\
		return Store::BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
			value									\
			_XENUM4_PROP_GEN_INDEX1_ARGS(LEVEL, Z)					\
		);										\
	}											_XENUM4_NWLN \


// =============================== FUNC (HDR): get$PROPNAME() ===================================
/**
 * Worker for _XENUM4_PROP_DECLV_PLAIN().
 * Declares the get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_HDR_DECLV_GET_VALUE(PROPNAME, DEPTH, CTXT, Z)				\
	_XENUM4_DOC(@copydoc Store::BOOST_PP_CAT(get, PROPNAME)					\
		(_XENUM4_PROP_GEN_INDEX0_PARMS(Enum, BOOST_PP_CAT(PROPNAME, Index), DEPTH, Z)))	\
	BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , constexpr)						\
	const BOOST_PP_CAT(PROPNAME, Value&)							\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM4_PROP_GEN_INDEX1_PARMS(BOOST_PP_CAT(PROPNAME, Index), DEPTH, Z)		\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)					\
	{											\
		return Store::BOOST_PP_CAT(get, PROPNAME) (					\
			value									\
			_XENUM4_PROP_GEN_INDEX1_ARGS(DEPTH, Z)					\
		);										\
	}											_XENUM4_NWLN \


// ===================================== FUNCTIONS (SRC) ========================================
/**
 * Worker for _XENUM4_PROP_DECLV_PLAIN().
 * Declares the functions related to a single custom property, implemented in source.
 * @hideinitializer
 */
#define _XENUM4_PLAIN_SRC_DECLV_FUNCS(PROPNAME, DEPTH, CTXT, Z)					\
_XENUM4_INDENT_SUB										\
public:												_XENUM4_NWLN \
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM4_PROP_SRC_DECLV_GET_SIZE,						\
		PROPNAME									\
	)											\
	_XENUM4_PROP_SRC_DECLV_GET_VALUE(							\
		PROPNAME,									\
		_XENUM4_PROPDEF_GET_PARM_TYPE(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		DEPTH,										\
		Z										\
	)


#endif // _XENUM4_IMPL_PLAIN_DECL_VALUE_HPP
