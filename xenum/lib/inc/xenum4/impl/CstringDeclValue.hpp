/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in value class context, for "cstring" data type category.
 */
#ifndef _XENUM4_IMPL_CSTRING_DECL_VALUE_HPP
#define _XENUM4_IMPL_CSTRING_DECL_VALUE_HPP



// ======================================= FUNCTIONS ============================================
/**
 * Worker for _XENUM4_PROP_DECLV_CSTRING().
 * Declares the functions related to a single custom property, in container class.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DECLV_FUNCS(PROPNAME, DEPTH, CTXT, Z)					\
public:												NWLN \
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because _Nodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM4_CSTRING_DECLV_GET_SIZE,							\
		CTXT										\
	)											\
	_XENUM4_CSTRING_DECLV_GET_VALUE(							\
		PROPNAME,									\
		DEPTH,										\
		_XENUM4_CTXT_GET_PROPDEF(CTXT),							\
		_XENUM4_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Callback worker for _XENUM4_CSTRING_DECLV_FUNCS() iteration over levels.
 * Declares get${propname}Size() for this level.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DECLV_GET_SIZE(Z, N, CTXT)						\
	_XENUM4_CSTRING_DECLV_GET_SIZE_I1							\
	(											\
		_XENUM4_PROPDEF_GET_NAME(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		CTXT,										\
		_XENUM4_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Worker for _XENUM4_CSTRING_DECLV_GET_SIZE_N().
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DECLV_GET_SIZE_I1(PROPNAME, LEVEL, CTXT, DECL, Z)			\
IND1	const size_t BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (				\
		_XENUM4_PROP_GEN_INDEX1_PARMS(size_t, LEVEL, Z)					\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)					\
	{											\
		return										\
		_XENUM4_DECL_GET_SCOPE(DECL)							\
		_XENUM4_DECL_GET_CNTNRNAME(DECL)						\
		:: BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (				\
			value									\
			_XENUM4_PROP_GEN_INDEX1_ARGS(LEVEL, Z)					\
		);										\
	}											NWLN

/**
 * Worker for _XENUM4_CSTRING_DECLV_FUNCS().
 * Declares get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DECLV_GET_VALUE(PROPNAME, DEPTH, PROPDEF, DECL, Z)			\
IND1	const _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF)*						\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM4_PROP_GEN_INDEX1_PARMS(size_t, DEPTH, Z)					\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)					\
	{											\
		return										\
		_XENUM4_DECL_GET_SCOPE(DECL)							\
		_XENUM4_DECL_GET_CNTNRNAME(DECL)						\
		:: BOOST_PP_CAT(get, PROPNAME) (						\
			value									\
			_XENUM4_PROP_GEN_INDEX1_ARGS(DEPTH, Z)					\
		);										\
	}											NWLN


#endif // _XENUM4_IMPL_CSTRING_DECL_VALUE_HPP
