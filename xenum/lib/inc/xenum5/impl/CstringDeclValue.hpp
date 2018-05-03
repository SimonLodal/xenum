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



// ======================================= MAIN (HDR) ===========================================
/**
 * Declare the functions related to a single custom property, implemented in header.
 */
#define _XENUM5_CSTRING_HDR_DECLV(PNAME, DEPTH, PDEF, CTXT, Z)					\
	/* INC() to ensure that the index type always gets defined */				\
	_XENUM5_PROP_DECLV_TYPES(PNAME, BOOST_PP_INC(DEPTH))					\
	_XENUM5_CSTRING_HDR_DECLV_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\


// ======================================= MAIN (SRC) ===========================================
/**
 * Declare the data related to a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DECLV(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_PROP_DECLV_TYPES(PNAME, BOOST_PP_INC(DEPTH))					\
	_XENUM5_CSTRING_SRC_DECLV_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\


// ===================================== FUNCTIONS (HDR) ========================================
/**
 * Worker for _XENUM5_PROP_DECLV_PLAIN().
 * Declare the functions related to a single custom property, implemented in header.
 */
#define _XENUM5_CSTRING_HDR_DECLV_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_HDR_DECLV_GET_SIZE(BOOST_PP_INC(DEPTH), PDEF, Z)				\
	_XENUM5_PROP_HDR_DECLV_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\


// ===================================== FUNCTIONS (SRC) ========================================
/**
 * Declare the functions related to a single custom property, in value class.
 */
#define _XENUM5_CSTRING_SRC_DECLV_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\
	/* INC() because IndexNodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_SRC_DECLV_GET_SIZE(BOOST_PP_INC(DEPTH), PDEF, Z)				\
	_XENUM5_PROP_SRC_DECLV_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\


#endif // _XENUM5_IMPL_CSTRING_DECL_VALUE_HPP
