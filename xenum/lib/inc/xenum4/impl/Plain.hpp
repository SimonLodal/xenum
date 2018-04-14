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

/// Define where the data of the custom property is defined; HDR or SRC.
#define _XENUM4_PLAIN_IMPL	HDR
//#define _XENUM4_PLAIN_IMPL	SRC


// =============================== DECLARATION IN STORE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in store class context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLS_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	BOOST_PP_CAT(_XENUM4_PROP_DECLS_PLAIN_, _XENUM4_PLAIN_IMPL) (CTXT, DECL, PROPDEF, Z)

/**
 * Declaratation for a custom property of plain type, implemented in header, in store class
 * context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLS_PLAIN_HDR(CTXT, DECL, PROPDEF, Z)					\
	_XENUM4_PLAIN_HDR_DECLS_DATA(CTXT, DECL, PROPDEF, _XENUM4_PROPDEF_GET_NAME(PROPDEF), Z)	\
	_XENUM4_PLAIN_HDR_DECLS_FUNCS(CTXT, PROPDEF, _XENUM4_PROPDEF_GET_NAME(PROPDEF), Z)	\
	_XENUM4_PLAIN_DECLS_DEBUG(CTXT, DECL, PROPDEF, _XENUM4_PROPDEF_GET_NAME(PROPDEF), Z)	\

/**
 * Declaratation for a custom property of plain type, implemented in source, in store class
 * context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLS_PLAIN_SRC(CTXT, DECL, PROPDEF, Z)					\
// FIXME: Do!


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in value class context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLV_PLAIN(CTXT, PROPDEF, Z)						\
	BOOST_PP_CAT(_XENUM4_PROP_DECLV_PLAIN_, _XENUM4_PLAIN_IMPL) (CTXT, PROPDEF, Z)


/**
 * Declaratation for a custom property of plain type, implemented in header, in value class
 * context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLV_PLAIN_HDR(CTXT, PROPDEF, Z)						\
	_XENUM4_PLAIN_HDR_DECLV_TYPES(								\
		_XENUM4_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM4_PROPDEF_GET_DEPTH(PROPDEF)						\
	)											\
	_XENUM4_PLAIN_HDR_DECLV_FUNCS(								\
		_XENUM4_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM4_PROPDEF_GET_DEPTH(PROPDEF),						\
		CTXT,										\
		Z										\
	)

/**
 * Declaratation for a custom property of plain type, implemented in source, in value class
 * context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLV_PLAIN_SRC(CTXT, PROPDEF, Z)						\
// FIXME: Do!


// ======================================= DEFINITION ==========================================
/**
 * Entry point for defining a custom property of plain type, in source file context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DEFINE_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	BOOST_PP_CAT(_XENUM4_PROP_DEFINE_PLAIN_, _XENUM4_PLAIN_IMPL) (CTXT, DECL, PROPDEF, Z)

/**
 * Definitions for a custom property of plain type, implemented in header, in source file context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DEFINE_PLAIN_HDR(CTXT, DECL, PROPDEF, Z)					\
	_XENUM4_PLAIN_HDR_DEFINE								\
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
 * Definitions for a custom property of plain type, implemented in source, in source file
 * context.
 * @hideinitializer
 */
#define _XENUM4_PROP_DEFINE_PLAIN_SRC(CTXT, DECL, PROPDEF, Z)					\
// FIXME: Do!


/**
 * Entry point for defining final checks for a custom property of plain type, in source file
 * context.
 * @hideinitializer
 */
#define _XENUM4_PROP_CHECK_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	BOOST_PP_CAT(_XENUM4_PROP_CHECK_PLAIN_, _XENUM4_PLAIN_IMPL) (CTXT, DECL, PROPDEF, Z)

/**
 * Define final checks for a custom property of plain type, implemented in header, in source
 * file context.
 * @hideinitializer
 */
#define _XENUM4_PROP_CHECK_PLAIN_HDR(CTXT, DECL, PROPDEF, Z)					\
	_XENUM4_PLAIN_HDR_CHECK									\
	(											\
		CTXT,										\
		DECL,										\
		PROPDEF,									\
		_XENUM4_DECL_GET_SCOPE(DECL),							\
		_XENUM4_STORE_NAME(DECL),							\
		_XENUM4_PROPDEF_GET_NAME(PROPDEF),						\
		Z										\
	)											\

/**
 * Define final checks for a custom property of plain type, implemented in source, in source
 * file context.
 * @hideinitializer
 */
#define _XENUM4_PROP_CHECK_PLAIN_SRC(CTXT, DECL, PROPDEF, Z)					\
// FIXME: Do!


#endif // _XENUM4_IMPL_PLAIN_HPP
