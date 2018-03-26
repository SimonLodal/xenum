/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of the "cstring" data type category for custom properties.
 */
#ifndef _XENUM3_IMPL_CSTRING_HPP
#define _XENUM3_IMPL_CSTRING_HPP


// ============================= DECLARATION IN CONTAINER CLASS ================================
/**
 * Entry point for declaring a custom property of cstring type, in container class context.
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLC_CSTRING(CTXT, DECL, PROPDEF, Z)					\
	_XENUM3_CSTRING_DECLC_FUNCS(								\
		_XENUM3_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM3_PROPDEF_GET_DEPTH(PROPDEF),						\
		CTXT,										\
		Z										\
	)


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Entry point for declaring a custom property of cstring type, in value class context.
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLV_CSTRING(CTXT, PROPDEF, Z)						\
	_XENUM3_CSTRING_DECLV_FUNCS(								\
		_XENUM3_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM3_PROPDEF_GET_DEPTH(PROPDEF),						\
		CTXT,										\
		Z										\
	)


// ======================================= DEFINITION ==========================================
/**
 * Entry point for defining the data of a custom properties of cstring type, in source file
 * context.
 * @hideinitializer
 */
//#define _XENUM3_PROP_DEFINE_CSTRING(CTXT, DECL, PROPDEF, PROPNAME, SCOPE, CNTNRNAME, Z)
#define _XENUM3_PROP_DEFINE_CSTRING(CTXT, DECL, PROPDEF, Z)					\
	_XENUM3_CSTRING_DEFINE									\
	(											\
		CTXT,										\
		PROPDEF,									\
		_XENUM3_DECL_GET_SCOPE(DECL),							\
		_XENUM3_DECL_GET_CNTNRNAME(DECL),						\
		_XENUM3_PROPDEF_GET_NAME(PROPDEF),						\
		Z										\
	)											\

// FIXME: Funcs?




#endif // _XENUM3_IMPL_CSTRING_HPP
