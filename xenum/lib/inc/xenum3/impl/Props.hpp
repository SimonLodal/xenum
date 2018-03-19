/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Toplevel entry functions for generating custom properties,
 * and utilities for their implementations.
 */
#ifndef _XENUM3_IMPL_PROPS_HPP
#define _XENUM3_IMPL_PROPS_HPP


// ============================= DECLARATION IN CONTAINER CLASS ================================
/**
 * Main entry point for declaring custom properties on the enum values.
 * Caller context: Container class declaration (header).
 * @hideinitializer
 */
#define _XENUM3_PROPS_DECLC(CTXT)								\
	BOOST_PP_REPEAT(									\
		BOOST_PP_SEQ_SIZE(_XENUM3_DECL_GET_PROPDEFS(_XENUM3_CTXT_GET_DECL(CTXT))),	\
		_XENUM3_PROP_DECLC,								\
		CTXT										\
		)

/**
 * Callback for _XENUM3_PROPS_DECLC() loop.
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLC(Z, N, CTXT)								\
	_XENUM3_PROP_DECLC_I1									\
	(											\
		_XENUM3_CTXT_SET_PROPINDEX(CTXT, N),						\
		_XENUM3_DECL_GET_PROPDEFN(_XENUM3_CTXT_GET_DECL(CTXT), N),			\
		Z										\
	)

/**
 * Worker for _XENUM3_PROP_DECLC().
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLC_I1(CTXT, PROPDEF, Z)							\
	BOOST_PP_CAT(_XENUM3_PROP_DECLC_, _XENUM3_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		_XENUM3_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		_XENUM3_CTXT_GET_DECL(CTXT),							\
		PROPDEF,									\
		Z										\
	)


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Main entry point for declaring custom properties on the enum values.
 * Caller context: Value class declaration (header).
 * @hideinitializer
 */
#define _XENUM3_PROPS_DECLV(CTXT)								\
	BOOST_PP_REPEAT										\
	(											\
		BOOST_PP_SEQ_SIZE(_XENUM3_DECL_GET_PROPDEFS(_XENUM3_CTXT_GET_DECL(CTXT))),	\
		_XENUM3_PROP_DECLV,								\
		CTXT										\
	)											\

/**
 * Callback for _XENUM3_PROPS_DECLV() loop.
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLV(Z, N, CTXT)								\
	_XENUM3_PROP_DECLV_I1									\
	(											\
		_XENUM3_CTXT_SET_PROPINDEX(CTXT, N),						\
		_XENUM3_DECL_GET_PROPDEFN(_XENUM3_CTXT_GET_DECL(CTXT), N),			\
		Z										\
	)

/**
 * Worker for _XENUM3_PROP_DECLV().
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLV_I1(CTXT, PROPDEF, Z)							\
	BOOST_PP_CAT(_XENUM3_PROP_DECLV_, _XENUM3_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		_XENUM3_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		PROPDEF,									\
		Z										\
	)


// ======================================= DEFINITION ==========================================
/**
 * Main entry function for defining the data for custom properties.
 * Caller context: Source file.
 * @hideinitializer
 */
#define _XENUM3_PROPS_DEFINE(CTXT)								\
	BOOST_PP_REPEAT										\
	(											\
		BOOST_PP_SEQ_SIZE(_XENUM3_DECL_GET_PROPDEFS(_XENUM3_CTXT_GET_DECL(CTXT))),	\
		_XENUM3_PROP_DEFINE,								\
		CTXT										\
	)

/**
 * Callback for _XENUM3_PROPS_DEFINE() loop.
 * @hideinitializer
 */
#define _XENUM3_PROP_DEFINE(Z, N, CTXT)								\
	_XENUM3_PROP_DEFINE_I1									\
	(											\
		_XENUM3_CTXT_SET_PROPINDEX(CTXT, N),						\
		_XENUM3_DECL_GET_PROPDEFN(_XENUM3_CTXT_GET_DECL(CTXT), N),			\
		Z										\
	)

/**
 * Worker for _XENUM3_PROP_DEFINE().
 * @hideinitializer
 */
#define _XENUM3_PROP_DEFINE_I1(CTXT, PROPDEF, Z)						\
	_XENUM3_PROP_DEFINE_I2(									\
		_XENUM3_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		_XENUM3_CTXT_GET_DECL(CTXT),							\
		PROPDEF,									\
		Z										\
	)

/**
 * Worker for _XENUM3_PROP_DEFINE_I2().
 * @hideinitializer
 */
#define _XENUM3_PROP_DEFINE_I2(CTXT, DECL, PROPDEF, Z)						\
	BOOST_PP_CAT(_XENUM3_PROP_DEFINE_, _XENUM3_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		CTXT,										\
		DECL,										\
		PROPDEF,									\
		_XENUM3_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM3_DECL_GET_SCOPE(DECL),							\
		_XENUM3_DECL_GET_CNTNRNAME(DECL),						\
		Z										\
	)											\
/* Nothing to define										\
	_XENUM3_DEFINE_CNTNR_PROP_FUNCS(CTXT, DECL, PROPDEF)					\
*/												\
	_XENUM3_DEFINE_CNTNR_PROP_DEBUG(CTXT, DECL, PROPDEF)					\




#endif // _XENUM3_IMPL_PROPS_HPP
