/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Declarations in value class context, for "plain" data type category.
 */
#ifndef _XENUM5_IMPL_PLAIN_DECL_VALUE_HPP
#define _XENUM5_IMPL_PLAIN_DECL_VALUE_HPP


// ========================================== MAIN ==============================================
/**
 * Entry point for all custom-prop related declarations in value class (header).
 */
#define _XENUM5_PLAIN_DECLV(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_PROP_TYPES_DECLV(PNAME, DEPTH)							\
	BOOST_PP_CAT(_XENUM5_PLAIN_DECLV_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


// ======================================= MAIN (HDR) ===========================================
/**
 * Declare the data and functions related to a single custom property, implemented in header.
 */
#define _XENUM5_PLAIN_DECLV_HDR(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_PROP_GETSIZE_CXP_DEFV(DEPTH, PDEF, Z)						\
	_XENUM5_PROP_GETVALUE_CXP_DEFV(PNAME, DEPTH, PDEF, Z)					\


// ======================================= MAIN (SRC) ===========================================
/**
 * Declare the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_DECLV_SRC(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_PROP_GETSIZE_EXT_DEFV(DEPTH, PDEF, Z)						\
	_XENUM5_PROP_GETVALUE_EXT_DEFV(PNAME, DEPTH, PDEF, Z)					\


#endif // _XENUM5_IMPL_PLAIN_DECL_VALUE_HPP
