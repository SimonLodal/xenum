/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in store class context, for "cstring" data type category.
 */
#ifndef _XENUM5_IMPL_CSTRING_DECL_STORE_HPP
#define _XENUM5_IMPL_CSTRING_DECL_STORE_HPP


// ======================================= FUNCTIONS ============================================
/**
 * Worker for _XENUM5_PROP_DECLS_CSTRING().
 * Declares the functions related to a single custom property, in store class.
 */
#define _XENUM5_CSTRING_DECLS_FUNCS(PROPNAME, DEPTH, PROPDEF, CTXT, Z)				\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		/* INC() because IndexNodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM5_PROP_SRC_DECLS_GET_SIZE,						\
		PROPDEF										\
	)											\
	_XENUM5_PROP_SRC_DECLS_GET_VALUE(							\
		PROPNAME,									\
		_XENUM5_PROPDEF_GET_PARM_TYPE(PROPDEF),						\
		DEPTH,										\
		Z										\
	)


#endif // _XENUM5_IMPL_CSTRING_DECL_STORE_HPP
