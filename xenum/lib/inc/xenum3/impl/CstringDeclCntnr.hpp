/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in container class context, for "cstring" data type category.
 */
#ifndef _XENUM3_IMPL_CSTRING_DECL_CNTNR_HPP
#define _XENUM3_IMPL_CSTRING_DECL_CNTNR_HPP


// ======================================= FUNCTIONS ============================================
/**
 * Worker for _XENUM3_PROP_DECLC_CSTRING().
 * Declares the functions related to a single custom property, in container class.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLC_FUNCS(PROPNAME, DEPTH, CTXT, Z)					\
public:												NWLN \
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because _Nodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM3_CSTRING_DECLC_GET_SIZE,							\
		PROPNAME									\
	)											\
	_XENUM3_CSTRING_DECLC_GET_VALUE(							\
		PROPNAME,									\
		DEPTH,										\
		_XENUM3_CTXT_GET_PROPDEF(CTXT),							\
		Z										\
	)

/**
 * Callback worker for _XENUM3_CSTRING_DECLC_FUNCS() iteration over levels.
 * Declares get${propname}Size() for this level.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLC_GET_SIZE(Z, LEVEL, PROPNAME)					\
IND1	static const size_t BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
		_XENUM3_PROP_GEN_INDEX_PARMS(Enum, size_t, LEVEL, Z)				\
	);											NWLN

/**
 * Worker for _XENUM3_CSTRING_DECLC_FUNCS_LV().
 * Declares get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DECLC_GET_VALUE(PROPNAME, DEPTH, PROPDEF, Z)				\
IND1	static const _XENUM3_PROPDEF_GET_REAL_TYPE(PROPDEF)*					\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM3_PROP_GEN_INDEX_PARMS(Enum, size_t, DEPTH, Z)				\
	);											NWLN



#endif // _XENUM3_IMPL_CSTRING_DECL_CNTNR_HPP
