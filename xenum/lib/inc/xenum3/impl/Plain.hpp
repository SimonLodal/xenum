/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of the "plain" data type category for custom properties.
 */
#ifndef _XENUM3_IMPL_PLAIN_HPP
#define _XENUM3_IMPL_PLAIN_HPP



// ============================= DECLARATION IN CONTAINER CLASS ================================
/**
 * Entry point for declaring a custom property of plain type, in container class context.
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLC_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	_XENUM3_PLAIN_DECLC_DATA(CTXT, DECL, PROPDEF, _XENUM3_PROPDEF_GET_NAME(PROPDEF), Z)	\
	_XENUM3_PLAIN_DECLC_FUNCS(CTXT, PROPDEF, _XENUM3_PROPDEF_GET_NAME(PROPDEF), Z)		\
	_XENUM3_PLAIN_DECLC_DEBUG(CTXT, DECL, PROPDEF, _XENUM3_PROPDEF_GET_NAME(PROPDEF), Z)	\


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in value class context.
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLV_PLAIN(CTXT, PROPDEF, Z)						\
	_XENUM3_PLAIN_DECLV_FUNC_GET_SIZE(CTXT, PROPDEF, Z)					\
	_XENUM3_PLAIN_DECLV_FUNC_GET_VALUE(CTXT, PROPDEF, Z)					\


// ======================================= DEFINITION ==========================================
/**
 * Entry point for defining a custom property of plain type, in source file context.
 * @hideinitializer
 */
#define _XENUM3_PROP_DEFINE_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	_XENUM3_PLAIN_DEFINE									\
	(											\
		CTXT,										\
		PROPDEF,									\
		_XENUM3_DECL_GET_SCOPE(DECL),							\
		_XENUM3_DECL_GET_CNTNRNAME(DECL),						\
		_XENUM3_PROPDEF_GET_NAME(PROPDEF),						\
		Z										\
	)											\
	_XENUM3_PLAIN_DEFINE_DEBUG(CTXT, PROPDEF, Z)						\




#endif // _XENUM3_IMPL_PLAIN_HPP
