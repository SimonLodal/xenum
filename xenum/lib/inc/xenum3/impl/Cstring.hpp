/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of the "cstring" data type for custom properties.
 */
#ifndef _XENUM3_IMPL_CSTRING_HPP
#define _XENUM3_IMPL_CSTRING_HPP


// ====================================== DECLARATION ==========================================
/**
 * Entry point for declaring a custom property of cstring type, in container class context.
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLC_CSTRING(CTXT, DECL, PROPDEF, Z)					\
// FIXME: !!

/**
 * Entry point for declaring a custom property of cstring type, in value class context.
 * @hideinitializer
 */
#define _XENUM3_PROP_DECLV_CSTRING(CTXT, PROPDEF, Z)						\
// FIXME: !!





// ======================================= DEFINITION ==========================================
// FIXME: !!
#define _XENUM3_PROP_DEFINE_CSTRING(CTXT, DECL, PROPDEF, PROPNAME, SCOPE, CNTNRNAME, Z)		\






// =================================== FIXME: OLD =======================================
/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_DATA(). Called as XENUM_VALS_* callback.
 * Counts the number of chars in all the string values of a single custom property, for a
 * single enum value.
 * VARARGS: All custom property data for the enum value.
 * @hideinitializer
 */
/* FIXME: Move to other file.
#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING(CTXT, IDENT, ...)			\
	_XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING_DO					\
	(											\
		CTXT,										\
		_XENUM3_PROPDEF_GET_DEPTH(_XENUM3_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM3_GET_VARARG(_XENUM3_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__)		\
	)
*/
/*
NWLN _DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING: ident=IDENT ctxt=CTXT argc=BOOST_PP_VARIADIC_SIZE(__VA_ARGS__) argv=BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__) NWLN \
*/

/**
 * Worker for _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING().
 * @hideinitializer
 */
/* FIXME: Move to other file.
#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING_DO(CTXT, DEPTH, DATA)			\
	_XENUM3_TUPLETREE_ITERATE_DEPTH_GEN(							\
		DATA,										\
		DEPTH,										\
		(_XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING_ADD_ONE,			\
		 _XENUM3_TUPLETREE_FILTER_LEAF),						\
		CTXT										\
	)											\


#define _XENUM3_DECLARE_CNTNR_PROP_COUNT_VALUES_CSTRING_ADD_ONE(ITERPOS, NODE, CTXT)		\
	+sizeof(NODE)
*/



#endif // _XENUM3_IMPL_CSTRING_HPP
