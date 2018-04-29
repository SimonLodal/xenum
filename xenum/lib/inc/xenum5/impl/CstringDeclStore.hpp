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


// ======================================= MAIN (HDR) ===========================================
/**
 * Declare the data and functions related to a single custom property, implemented in header.
 */
// FIXME: Implement hdr. Using src impl for now.
#define _XENUM5_CSTRING_HDR_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_CSTRING_SRC_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\


// ======================================= MAIN (SRC) ===========================================
/**
 * Declare the data related to a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_CSTRING_SRC_DECLS_FUNCS(PNAME, DEPTH, PDEF, Z)					\


// ===================================== FUNCTIONS (SRC) ========================================
/**
 * Declare the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DECLS_FUNCS(PNAME, DEPTH, PDEF, Z)					\
	/* INC() because IndexNodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_SRC_DECLS_GET_SIZE(BOOST_PP_INC(DEPTH), PDEF, Z)				\
	_XENUM5_PROP_SRC_DECLS_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\


#endif // _XENUM5_IMPL_CSTRING_DECL_STORE_HPP
