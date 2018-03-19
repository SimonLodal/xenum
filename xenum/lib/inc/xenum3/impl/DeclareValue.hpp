/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM3_IMPL_DECLARE_VALUE_HPP
#define _XENUM3_IMPL_DECLARE_VALUE_HPP


// ==============================================================================================
/**
 * Declare the enum-value class.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE(CTXT)								\
	_XENUM3_DECLARE_VALUE_DO(CTXT, _XENUM3_CTXT_GET_DECL(CTXT))

/**
 * Worker for _XENUM3_DECLARE_VALUE().
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_DO(CTXT, DECL)							\
	BOOST_PP_CAT(										\
		_XENUM3_DECLARE_VALUE_,								\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM3_DECL_GET_PROPDEFS(DECL)))		\
	) (CTXT, DECL)
/*
_DECLARE_VALUE_DO: ctxt=CTXT decl=DECL has-props=BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM3_DECL_GET_PROPDEFS(DECL))) NWLN \
*/

// ==============================================================================================
/**
 * Declare the enum-value class as a simple typedef of the template class.
 * For enums that do not have custom properties.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_0(CTXT, DECL)							\
	typedef ::_XENUM3_NS::XenumValue<_XENUM3_DECL_GET_CNTNRNAME(DECL)>			\
		_XENUM3_DECL_GET_VALUENAME(DECL);


// ==============================================================================================
/**
 * Declare the enum-value class as a subclass of the template class.
 * For enums that have custom properties.
 * Adds getters for the custom properties.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_1(CTXT, DECL)							\
class _XENUM3_DECL_GET_VALUENAME(DECL)								\
	: public ::_XENUM3_NS::XenumValue<_XENUM3_DECL_GET_CNTNRNAME(DECL)> {			NWLN \
	_XENUM3_DECLARE_VALUE_SUBCLASS_CTORS(_XENUM3_DECL_GET_VALUENAME(DECL))			\
public:												NWLN \
	BOOST_PP_REPEAT										\
	(											\
		BOOST_PP_SEQ_SIZE(_XENUM3_DECL_GET_PROPDEFS(DECL)),				\
		_XENUM3_DECLARE_VALUE_PROPIDX,							\
		CTXT										\
	)											\
};												\
NWLN

/* DEBUG
_DECLARE_VALUE_SUBCLASS : ctxt=CTXT argc=BOOST_PP_VARIADIC_SIZE(__VA_ARGS__) NWLN \
*/

/**
 * Worker for _XENUM3_DECLARE_VALUE_1().
 * Creates ctors; we need to copy all the ctors of the base class.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_SUBCLASS_CTORS(VALUENAME)						\
public:												NWLN \
IND1	constexpr VALUENAME(void) noexcept {}							NWLN \
IND1	constexpr VALUENAME(Enum value) noexcept : XenumValue(value) {}				NWLN \
IND1	constexpr VALUENAME(const VALUENAME& other) noexcept : XenumValue(other) {}		NWLN \


/**
 * Callback worker for _XENUM3_DECLARE_VALUE() iteration over propdefs indexes.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROPIDX(Z, N, CTXT)						\
	_XENUM3_DECLARE_VALUE_PROPIDX_I1							\
	(											\
		_XENUM3_CTXT_SET_PROPINDEX(CTXT, N),						\
		_XENUM3_DECL_GET_PROPDEFN(_XENUM3_CTXT_GET_DECL(CTXT), N),			\
		Z										\
	)

/**
 * Worker for _XENUM3_DECLARE_VALUE_PROPIDX().
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROPIDX_I1(CTXT, PROPDEF, Z)					\
	BOOST_PP_CAT(_XENUM3_DECLARE_VALUE_PROP_FUNCS_, _XENUM3_PROPDEF_GET_TYPCAT(PROPDEF)) (	\
		_XENUM3_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		PROPDEF,									\
		Z										\
	)

/**
 * Callback worker for _XENUM3_DECLARE_VALUE_1() iteration over propdefs.
 * Declare the getters for a single property.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNCS_PLAIN(CTXT, PROPDEF, Z)				\
	_XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE(CTXT, PROPDEF, Z)				\
	_XENUM3_DECLARE_VALUE_PROP_FUNC_GET_VALUE(CTXT, PROPDEF, Z)				\


// ==================================== FUNC helpers ============================================
/**
 * Helper to generate a list with a number of indexN function parameters (1..LEVELS).
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS(CTXT, LEVEL, Z)			\
	BOOST_PP_CAT(										\
		_XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS_,				\
		BOOST_PP_BOOL(LEVEL)								\
	) (CTXT, LEVEL, Z)

/**
 * Worker for _XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS().
 * Declares no index parameters since level==0.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS_0(CTXT, LEVEL, Z)			\

/*
NWLN _DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS_0: ctxt=CTXT propname=PROPNAME level=LEVEL NWLN \
*/

/**
 * Worker for _XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS().
 * Generate a function parameter list with a number of indexN parameters (1..LEVELS).
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS_1(CTXT, LEVEL, Z)			\
	BOOST_PP_REPEAT_ ## Z(									\
		LEVEL,										\
		_XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARM_N,				\
		CTXT										\
	)											\

/*
NWLN _DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS_1: ctxt=CTXT propname=PROPNAME level=LEVEL NWLN \
*/

/**
 * Callback worker for _XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS_1() iteration over levels.
 * Generates a single index parameter.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARM_N(Z, N, CTXT)				\
	BOOST_PP_COMMA_IF(BOOST_PP_BOOL(N))							\
	_XENUM3_DECL_GET_SCOPE(_XENUM3_CTXT_GET_DECL(CTXT))					\
	_XENUM3_DECL_GET_CNTNRNAME(_XENUM3_CTXT_GET_DECL(CTXT))					\
	:: BOOST_PP_CAT(_XENUM3_PROPDEF_GET_NAME(_XENUM3_CTXT_GET_PROPDEF(CTXT)), _index_t)	\
	BOOST_PP_CAT(index, BOOST_PP_INC(N))


/**
 * Helper to generate a list with a number of indexN arguments (1..COUNT).
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_ARGS(CTXT, COUNT, Z)				\
	BOOST_PP_REPEAT_ ## Z(									\
		COUNT,										\
		_XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_ARG_N,				\
		PROPNAME									\
	)

/**
 * Helper to generate a single indexN argument.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_ARG_N(Z, N, CTXT)				\
	, BOOST_PP_CAT(index, BOOST_PP_INC(N))


// =================================== FUNC: getSize() ==========================================
/**
 * Worker for _XENUM3_DECLARE_VALUE_PROP_FUNCS().
 * Declares the get${propname}Size() getter for each level.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE(CTXT, PROPDEF, Z)				\
	BOOST_PP_CAT(										\
		_XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE_,					\
		BOOST_PP_BOOL(_XENUM3_PROPDEF_GET_DEPTH(PROPDEF))				\
	) (CTXT, PROPDEF, Z)

/**
 * Worker for _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE().
 * Declares nothing since depth==0.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE_0(CTXT, PROPDEF, Z)				\

/*
_DECLARE_VALUE_PROP_FUNC_GET_SIZE_0: ctxt=CTXT propdef=PROPDEF NWLN
*/

/**
 * Worker for _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE().
 * Declares getters since depth!=0.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE_1(CTXT, PROPDEF, Z)				\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		_XENUM3_PROPDEF_GET_DEPTH(PROPDEF),						\
		_XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE_N,					\
		CTXT										\
	)
/*
_DECLARE_VALUE_PROP_FUNC_GET_SIZE_1: ctxt=CTXT propdef=PROPDEF NWLN \
*/

/**
 * Worker for _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE_1().
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE_N(Z, N, CTXT)					\
	_XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE_N_I1						\
	(											\
		CTXT,										\
		_XENUM3_PROPDEF_GET_NAME(_XENUM3_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		Z										\
	)

/**
 * Worker for _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE_N().
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE_N_I1(CTXT, PROPNAME, LEVEL, Z)			\
IND1	BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const					\
	_XENUM3_DECL_GET_SCOPE(_XENUM3_CTXT_GET_DECL(CTXT))					\
	_XENUM3_DECL_GET_CNTNRNAME(_XENUM3_CTXT_GET_DECL(CTXT))					\
	:: BOOST_PP_CAT(PROPNAME, _index_t&)							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (					\
		_XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS(CTXT, LEVEL, Z)		\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)					\
	{											\
		return										\
		_XENUM3_DECL_GET_SCOPE(_XENUM3_CTXT_GET_DECL(CTXT))				\
		_XENUM3_DECL_GET_CNTNRNAME(_XENUM3_CTXT_GET_DECL(CTXT))				\
		:: BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (				\
			value									\
			_XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_ARGS(CTXT, LEVEL, Z)		\
		);										\
	}											\
	NWLN

/*
_DECLARE_VALUE_PROP_FUNC_GET_SIZE_N_I1: ctxt=CTXT propname=PROPNAME level=LEVEL NWLN \
*/

// ================================ FUNC: get$PROPNAME() ========================================
/**
 * Worker for _XENUM3_DECLARE_VALUE_PROP_FUNCS().
 * Declares the get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_VALUE(CTXT, PROPDEF, Z)				\
	_XENUM3_DECLARE_VALUE_PROP_FUNC_GET_VALUE_DO(						\
		CTXT,										\
		_XENUM3_DECL_GET_SCOPE(_XENUM3_CTXT_GET_DECL(CTXT)),				\
		_XENUM3_DECL_GET_CNTNRNAME(_XENUM3_CTXT_GET_DECL(CTXT)),			\
		_XENUM3_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM3_PROPDEF_GET_DEPTH(PROPDEF),						\
		Z)										\

/**
 * Worker for _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_VALUE().
 * @hideinitializer
 */
#define _XENUM3_DECLARE_VALUE_PROP_FUNC_GET_VALUE_DO(CTXT, SCOPE, CNTNRNAME, PROPNAME, DEPTH, Z)	\
IND1	BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , constexpr) const					\
	SCOPE CNTNRNAME :: BOOST_PP_CAT(PROPNAME, _t&)						\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_PARMS(CTXT, DEPTH, Z)		\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)					\
	{											\
		return SCOPE CNTNRNAME :: BOOST_PP_CAT(get, PROPNAME) (				\
			value									\
			_XENUM3_DECLARE_VALUE_PROP_FUNCS_GEN_INDEX_ARGS(CTXT, DEPTH, Z)		\
		);										\
	}											\
	NWLN


#endif // _XENUM3_IMPL_DECLARE_VALUE_HPP
