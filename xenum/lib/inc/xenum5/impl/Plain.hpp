/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of the "plain" data type category for custom properties.
 */
#ifndef _XENUM5_IMPL_PLAIN_HPP
#define _XENUM5_IMPL_PLAIN_HPP



// =============================== DECLARATION IN STORE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in store class context.
 */
#define _XENUM5_PROP_DECLS_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	BOOST_PP_CAT(_XENUM5_PROP_DECLS_PLAIN_, _XENUM5_PROPDEF_GET_PLACEMENT_STR(PROPDEF))	\
		(CTXT, DECL, PROPDEF, Z)

/*
_XENUM5_CMNT(PROP_DECLS_PLAIN: propdef=PROPDEF) \
_XENUM5_CMNT(PROP_DECLS_PLAIN: features=_XENUM5_PROPDEF_GET_FEATURES(PROPDEF)) \
_XENUM5_CMNT(PROP_DECLS_PLAIN: placement=_XENUM5_PROPDEF_FEAT_PLACEMENT(PROPDEF)) \
*/

/**
 * Declaratation for a custom property of plain type, implemented in header, in store class
 * context.
 */
#define _XENUM5_PROP_DECLS_PLAIN_HDR(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_PLAIN_HDR_DECLS_DATA(CTXT, DECL, PROPDEF, _XENUM5_PROPDEF_GET_NAME(PROPDEF), Z)	\
	_XENUM5_PLAIN_HDR_DECLS_FUNCS(CTXT, PROPDEF, _XENUM5_PROPDEF_GET_NAME(PROPDEF), Z)	\
	_XENUM5_PLAIN_DECLS_DEBUG(CTXT, DECL, PROPDEF, _XENUM5_PROPDEF_GET_NAME(PROPDEF), Z)	\

/**
 * Declaratation for a custom property of plain type, implemented in source, in store class
 * context.
 */
#define _XENUM5_PROP_DECLS_PLAIN_SRC(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_PLAIN_SRC_DECLS_FUNCS(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		CTXT,										\
		Z										\
	)


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Entry point for declaring a custom property of plain type, in value class context.
 */
#define _XENUM5_PROP_DECLV_PLAIN(CTXT, PROPDEF, Z)						\
	BOOST_PP_CAT(_XENUM5_PROP_DECLV_PLAIN_, _XENUM5_PROPDEF_GET_PLACEMENT_STR(PROPDEF))	\
		(CTXT, PROPDEF, Z)


/**
 * Declaratation for a custom property of plain type, implemented in header, in value class
 * context.
 */
#define _XENUM5_PROP_DECLV_PLAIN_HDR(CTXT, PROPDEF, Z)						\
	_XENUM5_PLAIN_HDR_DECLV_TYPES(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF)						\
	)											\
	_XENUM5_PLAIN_HDR_DECLV_FUNCS(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		CTXT,										\
		Z										\
	)

/**
 * Declaratation for a custom property of plain type, implemented in source, in value class
 * context.
 */
#define _XENUM5_PROP_DECLV_PLAIN_SRC(CTXT, PROPDEF, Z)						\
	_XENUM5_PLAIN_SRC_DECLV_FUNCS(								\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		CTXT,										\
		Z										\
	)


// ======================================= DEFINITION ==========================================
/**
 * Entry point for defining a custom property of plain type, in source file context.
 */
#define _XENUM5_PROP_DEFINE_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	BOOST_PP_CAT(_XENUM5_PROP_DEFINE_PLAIN_, _XENUM5_PROPDEF_GET_PLACEMENT_STR(PROPDEF))	\
		(CTXT, DECL, PROPDEF, Z)

/**
 * Definitions for a custom property of plain type, implemented in header, in source file context.
 */
#define _XENUM5_PROP_DEFINE_PLAIN_HDR(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_PLAIN_HDR_DEFINE								\
	(											\
		CTXT,										\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_STORE_NAME(DECL),							\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		Z										\
	)											\
	_XENUM5_PLAIN_DEFINE_DEBUG(CTXT, PROPDEF, Z)						\

/**
 * Definitions for a custom property of plain type, implemented in source, in source file
 * context.
 */
#define _XENUM5_PROP_DEFINE_PLAIN_SRC(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_PLAIN_SRC_DEFINE								\
	(											\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		DECL,										\
		CTXT,										\
		Z										\
	)											\
	_XENUM5_PLAIN_DEFINE_DEBUG(CTXT, PROPDEF, Z)						\


/**
 * Entry point for defining final checks for a custom property of plain type, in source file
 * context.
 */
#define _XENUM5_PROP_CHECK_PLAIN(CTXT, DECL, PROPDEF, Z)					\
	BOOST_PP_CAT(_XENUM5_PROP_CHECK_PLAIN_, _XENUM5_PROPDEF_GET_PLACEMENT_STR(PROPDEF))	\
		(CTXT, DECL, PROPDEF, Z)

/**
 * Define final checks for a custom property of plain type, implemented in header, in source
 * file context.
 */
#define _XENUM5_PROP_CHECK_PLAIN_HDR(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_PLAIN_HDR_CHECK									\
	(											\
		CTXT,										\
		DECL,										\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_STORE_NAME(DECL),							\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		Z										\
	)											\

/**
 * Define final checks for a custom property of plain type, implemented in source, in source
 * file context.
 */
#define _XENUM5_PROP_CHECK_PLAIN_SRC(CTXT, DECL, PROPDEF, Z)					\
	_XENUM5_PLAIN_SRC_CHECK									\
	(											\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		PROPDEF,									\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_STORE_NAME(DECL),							\
		DECL,										\
		CTXT,										\
		Z										\
	)											\


// ====================================== COMMON UTILS ==========================================

/**
 * Helper to define the values array.
 */
#define _XENUM5_PLAIN_DEFINE_VALUES(CTXT)							\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PROP_ITER_VALUES(_XENUM5_PLAIN_DEFINE_VALUE, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Loop worker for _XENUM5_PLAIN_DEFINE_VALUES().
 */
#define _XENUM5_PLAIN_DEFINE_VALUE(ITERPOS, NODE, CTXT)						\
	_XENUM5_PROP_GET_VALUE(NODE, _XENUM5_CTXT_GET_PROPDEF(CTXT)),				_XENUM5_NWLN


// ============================= COUNT NODES =================================
/**
 * Call as XENUM_VALS_* callback.
 * Counts the indexnodes of a single custom property, for a single enum value.
 * VARARGS: All custom property data for the enum value.
 */
#define _XENUM5_PLAIN_COUNT_NODES(CTXT, IDENT, ...)						\
	+_XENUM5_TUPLETREE_ITERATE_DEPTH_CALC(							\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		/* Only count nodes, not leaf values. */					\
		BOOST_PP_DEC(_XENUM5_PROPDEF_GET_DEPTH(_XENUM5_CTXT_GET_PROPDEF(CTXT))),	\
		(_XENUM5_PLAIN_COUNT_NODES_ADD),						\
		CTXT,										\
		0										\
	)											\

/**
 * Callback for _XENUM5_PLAIN_COUNT_NODES() iteration. Called for each node.
 * Add +1 for each indexnode.
 */
#define _XENUM5_PLAIN_COUNT_NODES_ADD(ITERPOS, NODE, CTXT, STATE)				\
	BOOST_PP_INC(STATE)


#endif // _XENUM5_IMPL_PLAIN_HPP
