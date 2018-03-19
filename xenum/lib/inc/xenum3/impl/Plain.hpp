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
	_XENUM3_DECLARE_CNTNR_PROP_DATA(CTXT, DECL, PROPDEF, _XENUM3_PROPDEF_GET_NAME(PROPDEF), Z)	\
	_XENUM3_DECLARE_CNTNR_PROP_FUNCS(CTXT, DECL, PROPDEF, _XENUM3_PROPDEF_GET_NAME(PROPDEF), Z)	\
	_XENUM3_DECLARE_CNTNR_PROP_DEBUG(CTXT, DECL, PROPDEF, _XENUM3_PROPDEF_GET_NAME(PROPDEF), Z)	\


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in value class context.
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLV_PLAIN(CTXT, PROPDEF, Z)						\
	_XENUM3_DECLARE_VALUE_PROP_FUNC_GET_SIZE(CTXT, PROPDEF, Z)				\
	_XENUM3_DECLARE_VALUE_PROP_FUNC_GET_VALUE(CTXT, PROPDEF, Z)				\


#endif // _XENUM3_IMPL_PLAIN_HPP
