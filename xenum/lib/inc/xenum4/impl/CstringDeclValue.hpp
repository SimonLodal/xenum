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
 * Declares the functions related to a single custom property, in value class.
 * @hideinitializer
 */
#define _XENUM4_CSTRING_DECLV_FUNCS(PROPNAME, DEPTH, CTXT, Z)					\
public:												_XENUM4_NWLN \
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because IndexNodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM4_PROP_SRC_DECLV_GET_SIZE,						\
		PROPNAME									\
	)											\
	_XENUM4_PROP_SRC_DECLV_GET_VALUE(							\
		PROPNAME,									\
		_XENUM4_PROPDEF_GET_PARM_TYPE(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		DEPTH,										\
		Z										\
	)


#endif // _XENUM4_IMPL_CSTRING_DECL_VALUE_HPP
