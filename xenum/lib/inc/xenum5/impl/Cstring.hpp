/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of the "cstring" data type category for custom properties.
 */
#ifndef _XENUM5_IMPL_CSTRING_HPP
#define _XENUM5_IMPL_CSTRING_HPP


// ============================= DECLARATION IN CONTAINER CLASS ================================
/**
 * Entry point for declaring a custom property of cstring type, in store class context.
 */
#define _XENUM5_PROP_DECLS_CSTRING(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_CSTRING_DECLS_FUNCS(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		CTXT,										\
		Z										\
	)


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Entry point for declaring a custom property of cstring type, in value class context.
 */
#define _XENUM5_PROP_DECLV_CSTRING(CTXT, PROPDEF, Z)						\
	_XENUM5_CSTRING_DECLV_FUNCS(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		CTXT,										\
		Z										\
	)


// ======================================= DEFINITION ==========================================
/**
 * Entry point for defining the data of a custom properties of cstring type, in source file
 * context.
 */
#define _XENUM5_PROP_DEFINE_CSTRING(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_CSTRING_DEFINE									\
	(											\
		CTXT,										\
		DECL,										\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		Z										\
	)											\

/**
 * Entry point for defining final checks for a custom property of cstring type, in source file
 * context.
 */
#define _XENUM5_PROP_CHECK_CSTRING(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_CSTRING_CHECK									\
	(											\
		CTXT,										\
		DECL,										\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_STORE_NAME(DECL),							\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		Z										\
	)											\


#endif // _XENUM5_IMPL_CSTRING_HPP
