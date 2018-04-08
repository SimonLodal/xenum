/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in store class context, for "cstring" data type category.
 */
#ifndef _XENUM4_IMPL_CSTRING_DECL_STORE_HPP
#define _XENUM4_IMPL_CSTRING_DECL_STORE_HPP


// ======================================= FUNCTIONS ============================================
/**
 * Worker for _XENUM4_PROP_DECLS_CSTRING().
 * Declares the functions related to a single custom property, in store class.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DECLS_FUNCS(PROPNAME, DEPTH, CTXT, Z)					\
private:											NWLN \
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because IndexNodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM4_CSTRING_DECLS_GET_SIZE,							\
		PROPNAME									\
	)											\
	_XENUM4_CSTRING_DECLS_GET_VALUE(							\
		PROPNAME,									\
		DEPTH,										\
		_XENUM4_CTXT_GET_PROPDEF(CTXT),							\
		Z										\
	)

/**
 * Callback worker for _XENUM4_CSTRING_DECLS_FUNCS() iteration over levels.
 * Declares get${propname}Size() for this level.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DECLS_GET_SIZE(Z, LEVEL, PROPNAME)					\
IND1	static const size_t BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
		_XENUM4_PROP_GEN_INDEX0_PARMS(Enum, size_t, LEVEL, Z)				\
	);											NWLN

/**
 * Worker for _XENUM4_CSTRING_DECLS_FUNCS().
 * Declares get${propname}() value getter.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DECLS_GET_VALUE(PROPNAME, DEPTH, PROPDEF, Z)				\
IND1	static const _XENUM4_PROPDEF_GET_REAL_TYPE(PROPDEF)*					\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM4_PROP_GEN_INDEX0_PARMS(Enum, size_t, DEPTH, Z)				\
	);											NWLN



#endif // _XENUM4_IMPL_CSTRING_DECL_STORE_HPP
