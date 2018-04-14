/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Toplevel entry functions for generating custom properties,
 * and utilities for their implementations.
 */
#ifndef _XENUM4_IMPL_PROPS_HPP
#define _XENUM4_IMPL_PROPS_HPP



// =============================== DECLARATION IN STORE CLASS ==================================
/**
 * Main entry point for declaring custom properties on the enum values.
 * Caller context: Store class declaration (header).
 * @hideinitializer
 */
#define _XENUM4_PROPS_DECLS(CTXT)								\
	BOOST_PP_REPEAT(									\
		BOOST_PP_SEQ_SIZE(_XENUM4_DECL_GET_PROPDEFS(_XENUM4_CTXT_GET_DECL(CTXT))),	\
		_XENUM4_PROP_DECLS,								\
		CTXT										\
		)

/**
 * Callback for _XENUM4_PROPS_DECLS() loop.
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLS(Z, N, CTXT)								\
	_XENUM4_PROP_DECLS_I1									\
	(											\
		_XENUM4_CTXT_SET_PROPINDEX(CTXT, N),						\
		_XENUM4_DECL_GET_PROPDEFN(_XENUM4_CTXT_GET_DECL(CTXT), N),			\
		Z										\
	)

/**
 * Worker for _XENUM4_PROP_DECLS().
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLS_I1(CTXT, PROPDEF, Z)							\
	BOOST_PP_CAT(_XENUM4_PROP_DECLS_, _XENUM4_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		_XENUM4_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		_XENUM4_CTXT_GET_DECL(CTXT),							\
		PROPDEF,									\
		Z										\
	)


// =============================== DECLARATION IN VALUE CLASS ==================================
/**
 * Main entry point for declaring custom properties on the enum values.
 * Caller context: Value class declaration (header).
 * @hideinitializer
 */
#define _XENUM4_PROPS_DECLV(CTXT)								\
	BOOST_PP_REPEAT										\
	(											\
		BOOST_PP_SEQ_SIZE(_XENUM4_DECL_GET_PROPDEFS(_XENUM4_CTXT_GET_DECL(CTXT))),	\
		_XENUM4_PROP_DECLV,								\
		CTXT										\
	)											\

/**
 * Callback for _XENUM4_PROPS_DECLV() loop.
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLV(Z, N, CTXT)								\
	_XENUM4_PROP_DECLV_I1									\
	(											\
		_XENUM4_CTXT_SET_PROPINDEX(CTXT, N),						\
		_XENUM4_DECL_GET_PROPDEFN(_XENUM4_CTXT_GET_DECL(CTXT), N),			\
		Z										\
	)

/**
 * Worker for _XENUM4_PROP_DECLV().
 * @hideinitializer
 */
#define _XENUM4_PROP_DECLV_I1(CTXT, PROPDEF, Z)							\
	BOOST_PP_CAT(_XENUM4_PROP_DECLV_, _XENUM4_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		_XENUM4_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		PROPDEF,									\
		Z										\
	)


// ======================================= DEFINITION ==========================================
/**
 * Main entry function for defining the data for custom properties.
 * Caller context: Source file.
 * @hideinitializer
 */
#define _XENUM4_PROPS_DEFINE(CTXT, DECL)							\
	BOOST_PP_REPEAT										\
	(											\
		BOOST_PP_SEQ_SIZE(_XENUM4_DECL_GET_PROPDEFS(DECL)),				\
		_XENUM4_PROP_DEFINE,								\
		CTXT										\
	)											\

/**
 * Callback for _XENUM4_PROPS_DEFINE() loop.
 * @hideinitializer
 */
#define _XENUM4_PROP_DEFINE(Z, N, CTXT)								\
	_XENUM4_PROP_DEFINE_I1									\
	(											\
		_XENUM4_CTXT_SET_PROPINDEX(CTXT, N),						\
		_XENUM4_DECL_GET_PROPDEFN(_XENUM4_CTXT_GET_DECL(CTXT), N),			\
		Z										\
	)

/**
 * Worker for _XENUM4_PROP_DEFINE().
 * @hideinitializer
 */
#define _XENUM4_PROP_DEFINE_I1(CTXT, PROPDEF, Z)						\
	BOOST_PP_CAT(_XENUM4_PROP_DEFINE_, _XENUM4_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		_XENUM4_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		_XENUM4_CTXT_GET_DECL(CTXT),							\
		PROPDEF,									\
		Z										\
	)


/**
 * Callback for _XENUM4_DEFS_CHECK() loop.
 * Generate static_assert() checks for the N'th property.
 * @hideinitializer
 */
#define _XENUM4_PROP_CHECK(Z, N, CTXT)								\
	_XENUM4_PROP_CHECK_I1									\
	(											\
		_XENUM4_CTXT_SET_PROPINDEX(CTXT, N),						\
		_XENUM4_DECL_GET_PROPDEFN(_XENUM4_CTXT_GET_DECL(CTXT), N),			\
		Z										\
	)

/**
 * Worker for _XENUM4_PROP_CHECK().
 * @hideinitializer
 */
#define _XENUM4_PROP_CHECK_I1(CTXT, PROPDEF, Z)							\
	BOOST_PP_CAT(_XENUM4_PROP_CHECK_, _XENUM4_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		_XENUM4_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		_XENUM4_CTXT_GET_DECL(CTXT),							\
		PROPDEF,									\
		Z										\
	)


// ====================================== COMMON UTILS =========================================

// ============================ INDEXNODE NAME ===============================
/**
 * Utility to generate a node name.
 * @param CTXT Context object. Assumes the following fields are set: IDENT.
 * @param INDEXPATH Index-path object provided by TUPLETREE iteration.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_NODE_NAME(CTXT, INDEXPATH)						\
	BOOST_PP_CAT(										\
		_XENUM4_PROP_GEN_NODE_NAME_,							\
		BOOST_PP_BOOL(BOOST_PP_SEQ_SIZE(INDEXPATH))					\
	) (CTXT, INDEXPATH)

/**
 * Worker for _XENUM4_PROP_GEN_NODE_NAME(), when indexpath is empty.
 * Avoid using FOLD_LEFT() since it fails on empty seq.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_NODE_NAME_0(CTXT, INDEXPATH)						\
	_XENUM4_CTXT_GET_IDENT(CTXT)

/**
 * Worker for _XENUM4_PROP_GEN_NODE_NAME(), when indexpath is non-empty.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_NODE_NAME_1(CTXT, INDEXPATH)						\
	BOOST_PP_SEQ_FOLD_LEFT(									\
		_XENUM4_PROP_GEN_NODE_NAME_APPEND_INDEX,					\
		_XENUM4_CTXT_GET_IDENT(CTXT),							\
		INDEXPATH									\
	)

/**
 * Append a single index to the node name.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_NODE_NAME_APPEND_INDEX(S, RESULT, INDEX)				\
	BOOST_PP_CAT(RESULT, BOOST_PP_CAT(_, INDEX))


// ============================ ITERATE VALUES ===============================
/**
 * Iterate data structure, execute callback for each leaf value.
 * @param CALLBACK Callback to execute for each value.
 * @param CTXT Context object. Assumes the following fields are set: PROPINDEX, PROPDEF, IDENT.
 * @hideinitializer
 */
#define _XENUM4_PROP_ITER_VALUES(CALLBACK, CTXT)						\
	_XENUM4_CALL_VALS(									\
		_XENUM4_PROP_ITER_VALUES_NODE,							\
		_XENUM4_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)

/**
 * Callback worker for _XENUM4_PROP_ITER_VALUES(); loop function for each node.
 * @hideinitializer
 */
#define _XENUM4_PROP_ITER_VALUES_NODE(CTXT, IDENT, ...)						\
	_XENUM4_PROP_ITER_VALUES_NODE_I1							\
	(											\
		_XENUM4_GET_VARARG(_XENUM4_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM4_PROPDEF_GET_DEPTH(_XENUM4_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM4_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM4_PROP_ITER_VALUES_NODE().
 * Execute tupletree iteration.
 * @hideinitializer
 */
#define _XENUM4_PROP_ITER_VALUES_NODE_I1(DATA, DEPTH, CTXT)					\
	_XENUM4_TUPLETREE_ITERATE_DEPTH_GEN(							\
		DATA,										\
		DEPTH,										\
		(_XENUM4_CTXT_GET_CALLBACK(CTXT), _XENUM4_TUPLETREE_FILTER_LEAF),		\
		CTXT										\
	)


// ========================= APPLY DEFAULT VALUE =============================
/**
 * @param NODE A leaf-node (value).
 * @param CTXT Context object. Must have PROPDEF set.
 * @return NODE if non-empty, else DEFAULT_VALUE from the PROPDEF.
 * @hideinitializer
 */
// FIXME: Report error if value and defaultvalue are both empty.
#define _XENUM4_PROP_GET_VALUE(NODE, CTXT)							\
	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(NODE),							\
		_XENUM4_PROPDEF_GET_DEFAULTVALUE(_XENUM4_CTXT_GET_PROPDEF(CTXT)),		\
		NODE										\
	)


// =========================== INDEX PARAMETERS ==============================
/**
 * Helper for function generators: Generate a list with a number of indexN function
 * parameters (0..LEVELS, inclusive), where the first is of type ENUM_T, and the
 * remaining of type INDEX_T.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_INDEX0_PARMS(ENUM_T, INDEX_T, LEVELS, Z)				\
	BOOST_PP_REPEAT_ ## Z(									\
		BOOST_PP_INC(LEVELS),								\
		_XENUM4_PROP_GEN_INDEX0_PARM_N,							\
		(ENUM_T, INDEX_T)								\
	)											\

/**
 * Callback worker for _XENUM4_PROP_GEN_INDEX0_PARMS() iteration over levels.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_INDEX0_PARM_N(Z, N, TYPES)						\
	BOOST_PP_COMMA_IF(N)									\
	BOOST_PP_TUPLE_ELEM(2, BOOST_PP_BOOL(N), TYPES)						\
	BOOST_PP_CAT(index, N)


/**
 * Helper to generate a list with a number of indexN function parameters (1..LEVELS) of
 * type INDEX_T, or just void for LEVELS=0.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_INDEX1_PARMS(INDEX_T, LEVELS, Z)					\
	BOOST_PP_CAT(										\
		_XENUM4_PROP_GEN_INDEX1_PARMS_,							\
		BOOST_PP_BOOL(LEVELS)								\
	) (INDEX_T, LEVELS, Z)

/**
 * Worker for _XENUM4_PROP_GEN_INDEX1_PARMS().
 * Declares no index parameters since level==0.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_INDEX1_PARMS_0(INDEX_T, LEVELS, Z)					\
	void

/**
 * Worker for _XENUM4_PROP_GEN_INDEX1_PARMS().
 * Generate a function parameter list with a number of indexN parameters (1..LEVELS).
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_INDEX1_PARMS_1(INDEX_T, LEVELS, Z)					\
	BOOST_PP_REPEAT_ ## Z(									\
		LEVELS,										\
		_XENUM4_PROP_GEN_INDEX1_PARM_N,							\
		INDEX_T										\
	)											\

/**
 * Callback worker for _XENUM4_PROP_GEN_INDEX1_PARMS_1() iteration over levels.
 * Generates a single index parameter.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_INDEX1_PARM_N(Z, N, INDEX_T)						\
	BOOST_PP_COMMA_IF(BOOST_PP_BOOL(N)) INDEX_T BOOST_PP_CAT(index, BOOST_PP_INC(N))


// =========================== INDEX ARGUMENTS ===============================
/**
 * Helper for function generators: Generate a list with a number of indexN
 * arguments (0..COUNT-1).
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_INDEX0_ARGS(COUNT, Z)							\
	BOOST_PP_REPEAT_ ## Z(									\
		COUNT,										\
		_XENUM4_PROP_GEN_INDEX0_ARG_N,							\
												\
	)

/**
 * Helper for _XENUM4_PROP_GEN_INDEX0_ARGS() to generate a single indexN function argument.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_INDEX0_ARG_N(Z, N, EMPTY)						\
	BOOST_PP_COMMA_IF(BOOST_PP_BOOL(N)) BOOST_PP_CAT(index, N)


/**
 * Helper to generate a list with a number of indexN arguments (1..COUNT).
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_INDEX1_ARGS(COUNT, Z)							\
	BOOST_PP_REPEAT_ ## Z(									\
		COUNT,										\
		_XENUM4_PROP_GEN_INDEX1_ARG_N,							\
												\
	)

/**
 * Helper for _XENUM4_PROP_GEN_INDEX1_ARGS() to generate a single indexN function argument.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_INDEX1_ARG_N(Z, N, CTXT)						\
	, BOOST_PP_CAT(index, BOOST_PP_INC(N))


// ========================== NODE-INDEX LOOKUP ==============================
/**
 * Helper for function generators: Generate an expression for resolving an index list.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_NODE_INDEXING(PROPNAME, INDEX_T, LEVELS, Z)				\
	BOOST_PP_CAT(										\
		_XENUM4_PROP_GEN_NODE_INDEXING_,						\
		BOOST_PP_BOOL(LEVELS)								\
	) (PROPNAME, INDEX_T, LEVELS, Z)							\


/**
 * Worker for _XENUM4_PROP_GEN_NODE_INDEXING() iteration, for level==0.
 * Adds node indexing for level 0; direct index.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_NODE_INDEXING_0(PROPNAME, INDEX_T, LEVELS, Z)				\
	static_cast<INDEX_T>(index0)								\

/**
 * Worker for _XENUM4_PROP_GEN_NODE_INDEXING() iteration, for level!=0.
 * Adds chained node indexing using calls.
 * @hideinitializer
 */
#define _XENUM4_PROP_GEN_NODE_INDEXING_1(PROPNAME, INDEX_T, LEVELS, Z)				\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM4_PROP_GEN_INDEX0_ARGS(LEVELS, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, LEVELS))


#endif // _XENUM4_IMPL_PROPS_HPP
