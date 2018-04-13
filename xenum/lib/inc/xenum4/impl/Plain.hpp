/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of the "plain" data type category for custom properties.
 */
#ifndef _XENUM4_IMPL_PLAIN_HPP
#define _XENUM4_IMPL_PLAIN_HPP


// =============================== DECLARATION IN STORE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in store class context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLS_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	_XENUM4_PLAIN_DECLS_DATA(CTXT, DECL, PROPDEF, _XENUM4_PROPDEF_GET_NAME(PROPDEF), Z)	\
	_XENUM4_PLAIN_DECLS_FUNCS(CTXT, PROPDEF, _XENUM4_PROPDEF_GET_NAME(PROPDEF), Z)		\
	_XENUM4_PLAIN_DECLS_DEBUG(CTXT, DECL, PROPDEF, _XENUM4_PROPDEF_GET_NAME(PROPDEF), Z)	\


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in value class context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLV_PLAIN(CTXT, PROPDEF, Z)						\
	_XENUM4_PLAIN_DECLV_TYPES(								\
		_XENUM4_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM4_PROPDEF_GET_DEPTH(PROPDEF)						\
	)											\
	_XENUM4_PLAIN_DECLV_FUNCS(								\
		_XENUM4_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM4_PROPDEF_GET_DEPTH(PROPDEF),						\
		CTXT,										\
		Z										\
	)


// ======================================= DEFINITION ==========================================
/**
 * Entry point for defining a custom property of plain type, in source file context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DEFINE_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	_XENUM4_PLAIN_DEFINE									\
	(											\
		CTXT,										\
		PROPDEF,									\
		_XENUM4_DECL_GET_SCOPE(DECL),							\
		_XENUM4_STORE_NAME(DECL),							\
		_XENUM4_PROPDEF_GET_NAME(PROPDEF),						\
		Z										\
	)											\
	_XENUM4_PLAIN_DEFINE_DEBUG(CTXT, PROPDEF, Z)						\

/**
 * Entry point for defining final checks for a custom property of plain type, in source file
 * context.
 * @hideinitializer
 */
#define _XENUM4_PROP_CHECK_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	_XENUM4_PLAIN_CHECK									\
	(											\
		CTXT,										\
		DECL,										\
		PROPDEF,									\
		_XENUM4_DECL_GET_SCOPE(DECL),							\
		_XENUM4_STORE_NAME(DECL),							\
		_XENUM4_PROPDEF_GET_NAME(PROPDEF),						\
		Z										\
	)											\


#endif // _XENUM4_IMPL_PLAIN_HPP
