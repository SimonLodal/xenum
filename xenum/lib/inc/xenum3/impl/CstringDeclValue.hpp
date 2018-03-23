/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in value class context, for "cstring" data type category.
 */
#ifndef _XENUM3_IMPL_CSTRING_DECL_VALUE_HPP
#define _XENUM3_IMPL_CSTRING_DECL_VALUE_HPP



// =========================== INDEX PARAMETERS ==============================
// FIXME: Move these to Props.hpp; use for other prop types too.
/**
 * Helper to generate a list with a number of indexN function parameters (1..LEVELS),
 * or just void for level=0.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLV_GEN_INDEX_PARMS(INDEX_T, LEVELS, Z)				\
	BOOST_PP_CAT(										\
		_XENUM3_CSTRING_DECLV_GEN_INDEX_PARMS_,						\
		BOOST_PP_BOOL(LEVELS)								\
	) (INDEX_T, LEVELS, Z)

/**
 * Worker for _XENUM3_CSTRING_DECLV_GEN_INDEX_PARMS().
 * Declares no index parameters since level==0.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLV_GEN_INDEX_PARMS_0(INDEX_T, LEVELS, Z)				\
	void

/**
 * Worker for _XENUM3_CSTRING_DECLV_GEN_INDEX_PARMS().
 * Generate a function parameter list with a number of indexN parameters (1..LEVELS).
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLV_GEN_INDEX_PARMS_1(INDEX_T, LEVELS, Z)				\
	BOOST_PP_REPEAT_ ## Z(									\
		LEVELS,										\
		_XENUM3_CSTRING_DECLV_GEN_INDEX_PARM_N,						\
		INDEX_T										\
	)											\

/**
 * Callback worker for _XENUM3_CSTRING_DECLV_GEN_INDEX_PARMS_1() iteration over levels.
 * Generates a single index parameter.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLV_GEN_INDEX_PARM_N(Z, N, INDEX_T)					\
	BOOST_PP_COMMA_IF(BOOST_PP_BOOL(N)) INDEX_T BOOST_PP_CAT(index, BOOST_PP_INC(N))


// =========================== INDEX ARGUMENTS ===============================
// FIXME: Move these to Props.hpp; use for other prop types too.
/**
 * Helper to generate a list with a number of indexN arguments (1..COUNT).
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLV_GEN_INDEX_ARGS(COUNT, Z)						\
	BOOST_PP_REPEAT_ ## Z(									\
		COUNT,										\
		_XENUM3_CSTRING_DECLV_GEN_INDEX_ARG_N,						\
												\
	)

/**
 * Helper to generate a single indexN argument.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLV_GEN_INDEX_ARG_N(Z, N, CTXT)						\
	, BOOST_PP_CAT(index, BOOST_PP_INC(N))


// ======================================= FUNCTIONS ============================================
/**
 * Worker for _XENUM3_PROP_DECLV_CSTRING().
 * Declares the functions related to a single custom property, in container class.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLV_FUNCS(PROPNAME, DEPTH, CTXT, Z)					\
public:												NWLN \
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because _Nodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM3_CSTRING_DECLV_GET_SIZE,							\
		CTXT										\
	)											\
	_XENUM3_CSTRING_DECLV_GET_VALUE(							\
		PROPNAME,									\
		DEPTH,										\
		_XENUM3_CTXT_GET_PROPDEF(CTXT),							\
		_XENUM3_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Callback worker for _XENUM3_CSTRING_DECLV_FUNCS() iteration over levels.
 * Declares get${propname}Size() for this level.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLV_GET_SIZE(Z, N, CTXT)						\
	_XENUM3_CSTRING_DECLV_GET_SIZE_I1							\
	(											\
		_XENUM3_PROPDEF_GET_NAME(_XENUM3_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		CTXT,										\
		_XENUM3_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Worker for _XENUM3_CSTRING_DECLV_GET_SIZE_N().
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLV_GET_SIZE_I1(PROPNAME, LEVEL, CTXT, DECL, Z)			\
IND1	const size_t BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (				\
		_XENUM3_CSTRING_DECLV_GEN_INDEX_PARMS(size_t, LEVEL, Z)				\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)					\
	{											\
		return										\
		_XENUM3_DECL_GET_SCOPE(DECL)							\
		_XENUM3_DECL_GET_CNTNRNAME(DECL)						\
		:: BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (				\
			value									\
			_XENUM3_CSTRING_DECLV_GEN_INDEX_ARGS(LEVEL, Z)				\
		);										\
	}											NWLN

/**
 * Worker for _XENUM3_CSTRING_DECLV_FUNCS().
 * Declares get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLV_GET_VALUE(PROPNAME, DEPTH, PROPDEF, DECL, Z)			\
IND1	const _XENUM3_PROPDEF_GET_REAL_TYPE(PROPDEF)*						\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM3_CSTRING_DECLV_GEN_INDEX_PARMS(size_t, DEPTH, Z)				\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)					\
	{											\
		return										\
		_XENUM3_DECL_GET_SCOPE(DECL)							\
		_XENUM3_DECL_GET_CNTNRNAME(DECL)						\
		:: BOOST_PP_CAT(get, PROPNAME) (						\
			value									\
			_XENUM3_PLAIN_DECLV_GEN_INDEX_ARGS(CTXT, DEPTH, Z)			\
		);										\
	}											NWLN


#endif // _XENUM3_IMPL_CSTRING_DECL_VALUE_HPP
