/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in value class context, for "cstring" data type category.
 */
#ifndef _XENUM5_IMPL_CSTRING_DECL_VALUE_HPP
#define _XENUM5_IMPL_CSTRING_DECL_VALUE_HPP



// ========================================== MAIN ==============================================
/**
 * Entry point for all custom-prop related declarations in value class (header).
 */
#define _XENUM5_CSTRING_DECLV(PNAME, DEPTH, PDEF, CTXT, Z)					\
	/* INC() to ensure that the index type always gets defined */				\
	_XENUM5_PROP_TYPES_DECLV(PNAME, BOOST_PP_INC(DEPTH))					\
	BOOST_PP_CAT(_XENUM5_CSTRING_DECLV_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


// ======================================= MAIN (HDR) ===========================================
/**
 * Declare the functions related to a single custom property, implemented in header.
 */
#define _XENUM5_CSTRING_DECLV_HDR(PNAME, DEPTH, PDEF, CTXT, Z)					\
	/* INC() because IndexNodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_GETSIZE_CXP_DEFV(BOOST_PP_INC(DEPTH), PDEF, Z)				\
	_XENUM5_PROP_GETVALUE_CXP_DEFV(PNAME, DEPTH, PDEF, Z)					\


// ======================================= MAIN (SRC) ===========================================
/**
 * Declare the data related to a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_DECLV_SRC(PNAME, DEPTH, PDEF, CTXT, Z)					\
	/* INC() because IndexNodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_GETSIZE_EXT_DEFV(BOOST_PP_INC(DEPTH), PDEF, Z)				\
	_XENUM5_PROP_GETVALUE_EXT_DEFV(PNAME, DEPTH, PDEF, Z)					\


#endif // _XENUM5_IMPL_CSTRING_DECL_VALUE_HPP
