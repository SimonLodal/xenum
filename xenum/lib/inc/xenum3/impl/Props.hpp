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
	BOOST_PP_CAT(_XENUM3_PROP_DEFINE_, _XENUM3_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		_XENUM3_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		_XENUM3_CTXT_GET_DECL(CTXT),							\
		PROPDEF,									\
		Z										\
	)



// ====================================== COMMON UTILS =========================================

// ============================== INDEXNODE NAME ==============================
/**
 * Utility to generate a node name.
 * @param CTXT Context object. Assumes the following fields are set: IDENT.
 * @param INDEXPATH Index-path object provided by TUPLETREE iteration.
 * @hideinitializer
 */
#define _XENUM3_PROP_GEN_NODE_NAME(CTXT, INDEXPATH)						\
	BOOST_PP_CAT(										\
		_XENUM3_PROP_GEN_NODE_NAME_,							\
		BOOST_PP_BOOL(BOOST_PP_SEQ_SIZE(INDEXPATH))					\
	) (CTXT, INDEXPATH)

/**
 * Worker for _XENUM3_PROP_GEN_NODE_NAME(), when indexpath is empty.
 * Avoid using FOLD_LEFT() since it fails on empty seq.
 * @hideinitializer
 */
#define _XENUM3_PROP_GEN_NODE_NAME_0(CTXT, INDEXPATH)						\
	_XENUM3_CTXT_GET_IDENT(CTXT)

/**
 * Worker for _XENUM3_PROP_GEN_NODE_NAME(), when indexpath is non-empty.
 * @hideinitializer
 */
#define _XENUM3_PROP_GEN_NODE_NAME_1(CTXT, INDEXPATH)						\
	BOOST_PP_SEQ_FOLD_LEFT(									\
		_XENUM3_PROP_GEN_NODE_NAME_APPEND_INDEX,					\
		_XENUM3_CTXT_GET_IDENT(CTXT),							\
		INDEXPATH									\
	)

/**
 * Append a single index to the node name.
 * @hideinitializer
 */
#define _XENUM3_PROP_GEN_NODE_NAME_APPEND_INDEX(S, RESULT, INDEX)				\
	BOOST_PP_CAT(RESULT, BOOST_PP_CAT(_, INDEX))


// ======================= ITERATE VALUES =======================
/**
 * Iterate data structure, execute callback for each leaf value.
 * @param CALLBACK Callback to execute for each value.
 * @param CTXT Context object. Assumes the following fields are set: PROPINDEX, PROPDEF, IDENT.
 * @hideinitializer
 */
#define _XENUM3_PROP_ITER_VALUES(CALLBACK, CTXT)						\
	_XENUM3_CALL_VALS(									\
		_XENUM3_PROP_ITER_VALUES_NODE,							\
		_XENUM3_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)

/**
 * Callback worker for _XENUM3_PLAIN_ITER_VALUES(); loop function for each node.
 * @hideinitializer
 */
#define _XENUM3_PROP_ITER_VALUES_NODE(CTXT, IDENT, ...)					\
	_XENUM3_PROP_ITER_VALUES_NODE_I1							\
	(											\
		_XENUM3_GET_VARARG(_XENUM3_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM3_PROPDEF_GET_DEPTH(_XENUM3_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM3_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM3_PLAIN_ITER_VALUES_NODE().
 * Execute tupletree iteration.
 * @hideinitializer
 */
#define _XENUM3_PROP_ITER_VALUES_NODE_I1(DATA, DEPTH, CTXT)					\
	_XENUM3_TUPLETREE_ITERATE_DEPTH_GEN(							\
		DATA,										\
		DEPTH,										\
		(_XENUM3_CTXT_GET_CALLBACK(CTXT), _XENUM3_TUPLETREE_FILTER_LEAF),		\
		CTXT										\
	)


// ======================= APPLY DEFAULT VALUE =======================
/**
 * @param NODE A leaf-node (value).
 * @param CTXT Context object. Must have PROPDEF set.
 * @return NODE if non-empty, else DEFAULT_VALUE from the PROPDEF.
 * @hideinitializer
 */
// FIXME: Report error if value and defaultvalue are both empty.
#define _XENUM3_PROP_GET_VALUE(NODE, CTXT)							\
	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(NODE),							\
		_XENUM3_PROPDEF_GET_DEFAULTVALUE(_XENUM3_CTXT_GET_PROPDEF(CTXT)),		\
		NODE										\
	)


#endif // _XENUM3_IMPL_PROPS_HPP
