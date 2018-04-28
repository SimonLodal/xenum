/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Toplevel entry functions for generating custom properties,
 * and utilities for their implementations.
 */
#ifndef _XENUM5_IMPL_PROPS_HPP
#define _XENUM5_IMPL_PROPS_HPP



// =============================== DECLARATION IN STORE CLASS ===================================
/**
 * Main entry point for declaring custom properties on the enum values.
 * Caller context: Store class declaration (header).
 */
#define _XENUM5_PROPS_DECLS(CTXT)								\
	BOOST_PP_REPEAT(									\
		BOOST_PP_SEQ_SIZE(_XENUM5_DECL_GET_PROPDEFS(_XENUM5_CTXT_GET_DECL(CTXT))),	\
		_XENUM5_PROP_DECLS,								\
		CTXT										\
		)

/**
 * Callback for _XENUM5_PROPS_DECLS() loop.
 */
#define _XENUM5_PROP_DECLS(Z, N, CTXT)								\
	_XENUM5_PROP_DECLS_I1									\
	(											\
		_XENUM5_DECL_GET_PROPDEFN(_XENUM5_CTXT_GET_DECL(CTXT), N),			\
		_XENUM5_CTXT_SET_PROPINDEX(CTXT, N),						\
		Z										\
	)

/**
 * Worker for _XENUM5_PROP_DECLS().
 */
#define _XENUM5_PROP_DECLS_I1(PROPDEF, CTXT, Z)							\
	_XENUM5_INDENT_SUB _XENUM5_CMNT(_XENUM5_PROPDEF_GET_NAME(PROPDEF))			\
	BOOST_PP_CAT(_XENUM5_PROP_DECLS_, _XENUM5_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		PROPDEF,									\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		_XENUM5_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		Z										\
	)


// =============================== DECLARATION IN VALUE CLASS ===================================
/**
 * Main entry point for declaring custom properties on the enum values.
 * Caller context: Value class declaration (header).
 */
#define _XENUM5_PROPS_DECLV(CTXT)								\
	BOOST_PP_REPEAT										\
	(											\
		BOOST_PP_SEQ_SIZE(_XENUM5_DECL_GET_PROPDEFS(_XENUM5_CTXT_GET_DECL(CTXT))),	\
		_XENUM5_PROP_DECLV,								\
		CTXT										\
	)											\

/**
 * Callback for _XENUM5_PROPS_DECLV() loop.
 */
#define _XENUM5_PROP_DECLV(Z, N, CTXT)								\
	_XENUM5_PROP_DECLV_I1									\
	(											\
		_XENUM5_DECL_GET_PROPDEFN(_XENUM5_CTXT_GET_DECL(CTXT), N),			\
		_XENUM5_CTXT_SET_PROPINDEX(CTXT, N),						\
		Z										\
	)

/**
 * Worker for _XENUM5_PROP_DECLV().
 */
#define _XENUM5_PROP_DECLV_I1(PROPDEF, CTXT, Z)							\
	_XENUM5_INDENT_SUB _XENUM5_CMNT(_XENUM5_PROPDEF_GET_NAME(PROPDEF))			\
	BOOST_PP_CAT(_XENUM5_PROP_DECLV_, _XENUM5_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		PROPDEF,									\
		_XENUM5_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		Z										\
	)


// ======================================= DEFINITION ===========================================
/**
 * Main entry function for defining the data for custom properties.
 * Caller context: Source file.
 */
#define _XENUM5_PROPS_DEFINE(CTXT, DECL)							\
	BOOST_PP_REPEAT										\
	(											\
		BOOST_PP_SEQ_SIZE(_XENUM5_DECL_GET_PROPDEFS(DECL)),				\
		_XENUM5_PROP_DEFINE,								\
		CTXT										\
	)											\

/**
 * Callback for _XENUM5_PROPS_DEFINE() loop.
 */
#define _XENUM5_PROP_DEFINE(Z, N, CTXT)								\
	_XENUM5_PROP_DEFINE_I1									\
	(											\
		_XENUM5_DECL_GET_PROPDEFN(_XENUM5_CTXT_GET_DECL(CTXT), N),			\
		_XENUM5_CTXT_SET_PROPINDEX(CTXT, N),						\
		Z										\
	)

/**
 * Worker for _XENUM5_PROP_DEFINE().
 */
#define _XENUM5_PROP_DEFINE_I1(PROPDEF, CTXT, Z)						\
	BOOST_PP_CAT(_XENUM5_PROP_DEFINE_, _XENUM5_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		PROPDEF,									\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		_XENUM5_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		Z										\
	)


/**
 * Callback for _XENUM5_DEFS_CHECK() loop.
 * Generate static_assert() checks for the N'th property.
 */
#define _XENUM5_PROP_CHECK(Z, N, CTXT)								\
	_XENUM5_PROP_CHECK_I1									\
	(											\
		_XENUM5_DECL_GET_PROPDEFN(_XENUM5_CTXT_GET_DECL(CTXT), N),			\
		_XENUM5_CTXT_SET_PROPINDEX(CTXT, N),						\
		Z										\
	)

/**
 * Worker for _XENUM5_PROP_CHECK().
 */
#define _XENUM5_PROP_CHECK_I1(PROPDEF, CTXT, Z)							\
	BOOST_PP_CAT(_XENUM5_PROP_CHECK_, _XENUM5_PROPDEF_GET_TYPCAT(PROPDEF))			\
	(											\
		PROPDEF,									\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		_XENUM5_CTXT_SET_PROPDEF(CTXT, PROPDEF),					\
		Z										\
	)


// ====================================== COMMON PARTS ==========================================
/**
 * Declare the data type for a custom property.
 */
#define _XENUM5_PROP_DECL_VALUE_TYPE(PROPNAME, PROPDEF)						\
	_XENUM5_DOC(Native type of custom property PROPNAME values.)				\
	typedef _XENUM5_PROPDEF_GET_REAL_TYPE(PROPDEF) BOOST_PP_CAT(PROPNAME, Value);		_XENUM5_NWLN \


// ============================ INDEXNODE NAME ===============================
/**
 * Utility to generate a node name.
 * @param CTXT Context object. Assumes the following fields are set: IDENT.
 * @param INDEXPATH Index-path object provided by TUPLETREE iteration.
 */
#define _XENUM5_PROP_GEN_NODE_NAME(CTXT, INDEXPATH)						\
	BOOST_PP_CAT(										\
		_XENUM5_PROP_GEN_NODE_NAME_,							\
		BOOST_PP_BOOL(BOOST_PP_SEQ_SIZE(INDEXPATH))					\
	) (CTXT, INDEXPATH)

/**
 * Worker for _XENUM5_PROP_GEN_NODE_NAME(), when indexpath is empty.
 * Avoid using FOLD_LEFT() since it fails on empty seq.
 */
#define _XENUM5_PROP_GEN_NODE_NAME_0(CTXT, INDEXPATH)						\
	_XENUM5_CTXT_GET_IDENT(CTXT)

/**
 * Worker for _XENUM5_PROP_GEN_NODE_NAME(), when indexpath is non-empty.
 */
#define _XENUM5_PROP_GEN_NODE_NAME_1(CTXT, INDEXPATH)						\
	BOOST_PP_SEQ_FOLD_LEFT(									\
		_XENUM5_PROP_GEN_NODE_NAME_APPEND_INDEX,					\
		_XENUM5_CTXT_GET_IDENT(CTXT),							\
		INDEXPATH									\
	)

/**
 * Append a single index to the node name.
 */
#define _XENUM5_PROP_GEN_NODE_NAME_APPEND_INDEX(S, RESULT, INDEX)				\
	BOOST_PP_CAT(RESULT, BOOST_PP_CAT(_, INDEX))


// ============================ ITERATE VALUES ===============================
/**
 * Iterate data structure, execute callback for each leaf value.
 * @param CALLBACK Callback to execute for each value.
 * @param CTXT Context object. Assumes the following fields are set: PROPINDEX, PROPDEF, IDENT.
 */
#define _XENUM5_PROP_ITER_VALUES(CALLBACK, CTXT)						\
	_XENUM5_CALL_VALS(									\
		_XENUM5_PROP_ITER_VALUES_NODE,							\
		_XENUM5_CTXT_SET_CALLBACK(CTXT, CALLBACK)					\
	)

/**
 * Callback worker for _XENUM5_PROP_ITER_VALUES(); loop function for each node.
 */
#define _XENUM5_PROP_ITER_VALUES_NODE(CTXT, IDENT, ...)						\
	_XENUM5_PROP_ITER_VALUES_NODE_I1							\
	(											\
		_XENUM5_GET_VARARG(_XENUM5_CTXT_GET_PROPINDEX(CTXT), __VA_ARGS__),		\
		_XENUM5_PROPDEF_GET_DEPTH(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_PROP_ITER_VALUES_NODE().
 * Execute tupletree iteration.
 */
#define _XENUM5_PROP_ITER_VALUES_NODE_I1(DATA, DEPTH, CTXT)					\
	_XENUM5_TUPLETREE_ITERATE_DEPTH_GEN(							\
		DATA,										\
		DEPTH,										\
		(_XENUM5_CTXT_GET_CALLBACK(CTXT), _XENUM5_TUPLETREE_FILTER_LEAF),		\
		CTXT										\
	)


// ========================= APPLY DEFAULT VALUE =============================
/**
 * @param NODE A leaf-node (value).
 * @param PROPDEF Property definition object.
 * @return NODE if non-empty, else DEFAULT_VALUE from the PROPDEF.
 */
// FIXME: Report error if value and defaultvalue are both empty.
#define _XENUM5_PROP_GET_VALUE(NODE, PROPDEF)							\
	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(NODE),							\
		_XENUM5_PROPDEF_GET_DEFAULTVALUE(PROPDEF),					\
		NODE										\
	)


// =========================== INDEX PARAMETERS ==============================
/**
 * Helper for function generators: Generate a list with a number of indexN function
 * parameters (0..LEVELS, inclusive), where the first is of type ENUM_T, and the
 * remaining of type INDEX_T.
 */
#define _XENUM5_PROP_GEN_INDEX0_PARMS(ENUM_T, INDEX_T, LEVELS, Z)				\
	BOOST_PP_REPEAT_ ## Z(									\
		BOOST_PP_INC(LEVELS),								\
		_XENUM5_PROP_GEN_INDEX0_PARM_N,							\
		(ENUM_T, INDEX_T)								\
	)											\

/**
 * Callback worker for _XENUM5_PROP_GEN_INDEX0_PARMS() iteration over levels.
 */
#define _XENUM5_PROP_GEN_INDEX0_PARM_N(Z, N, TYPES)						\
	BOOST_PP_COMMA_IF(N)									\
	BOOST_PP_TUPLE_ELEM(2, BOOST_PP_BOOL(N), TYPES)						\
	BOOST_PP_CAT(index, N)


/**
 * Helper to generate a list with a number of indexN function parameters (1..LEVELS) of
 * type INDEX_T, or just void for LEVELS=0.
 */
#define _XENUM5_PROP_GEN_INDEX1_PARMS(INDEX_T, LEVELS, Z)					\
	BOOST_PP_CAT(										\
		_XENUM5_PROP_GEN_INDEX1_PARMS_,							\
		BOOST_PP_BOOL(LEVELS)								\
	) (INDEX_T, LEVELS, Z)

/**
 * Worker for _XENUM5_PROP_GEN_INDEX1_PARMS().
 * Declare no index parameters since level==0.
 */
#define _XENUM5_PROP_GEN_INDEX1_PARMS_0(INDEX_T, LEVELS, Z)					\
	void

/**
 * Worker for _XENUM5_PROP_GEN_INDEX1_PARMS().
 * Generate a function parameter list with a number of indexN parameters (1..LEVELS).
 */
#define _XENUM5_PROP_GEN_INDEX1_PARMS_1(INDEX_T, LEVELS, Z)					\
	BOOST_PP_REPEAT_ ## Z(									\
		LEVELS,										\
		_XENUM5_PROP_GEN_INDEX1_PARM_N,							\
		INDEX_T										\
	)											\

/**
 * Callback worker for _XENUM5_PROP_GEN_INDEX1_PARMS_1() iteration over levels.
 * Generate a single index parameter.
 */
#define _XENUM5_PROP_GEN_INDEX1_PARM_N(Z, N, INDEX_T)						\
	BOOST_PP_COMMA_IF(BOOST_PP_BOOL(N)) INDEX_T BOOST_PP_CAT(index, BOOST_PP_INC(N))


// =========================== INDEX ARGUMENTS ===============================
/**
 * Helper for function generators: Generate a list with a number of indexN
 * arguments (0..COUNT-1).
 */
#define _XENUM5_PROP_GEN_INDEX0_ARGS(COUNT, Z)							\
	BOOST_PP_REPEAT_ ## Z(									\
		COUNT,										\
		_XENUM5_PROP_GEN_INDEX0_ARG_N,							\
												\
	)

/**
 * Helper for _XENUM5_PROP_GEN_INDEX0_ARGS() to generate a single indexN function argument.
 */
#define _XENUM5_PROP_GEN_INDEX0_ARG_N(Z, N, EMPTY)						\
	BOOST_PP_COMMA_IF(BOOST_PP_BOOL(N)) BOOST_PP_CAT(index, N)


/**
 * Helper to generate a list with a number of indexN arguments (1..COUNT).
 */
#define _XENUM5_PROP_GEN_INDEX1_ARGS(COUNT, Z)							\
	BOOST_PP_REPEAT_ ## Z(									\
		COUNT,										\
		_XENUM5_PROP_GEN_INDEX1_ARG_N,							\
												\
	)

/**
 * Helper for _XENUM5_PROP_GEN_INDEX1_ARGS() to generate a single indexN function argument.
 */
#define _XENUM5_PROP_GEN_INDEX1_ARG_N(Z, N, CTXT)						\
	, BOOST_PP_CAT(index, BOOST_PP_INC(N))


// ========================== NODE-INDEX LOOKUP ==============================
/**
 * Helper for function generators: Generate an expression for resolving an index list.
 */
#define _XENUM5_PROP_GEN_NODE_INDEXING(PROPNAME, INDEX_T, LEVELS, Z)				\
	BOOST_PP_CAT(										\
		_XENUM5_PROP_GEN_NODE_INDEXING_,						\
		BOOST_PP_BOOL(LEVELS)								\
	) (PROPNAME, INDEX_T, LEVELS, Z)							\


/**
 * Worker for _XENUM5_PROP_GEN_NODE_INDEXING() iteration, for level==0.
 * Add node indexing for level 0; direct index.
 */
#define _XENUM5_PROP_GEN_NODE_INDEXING_0(PROPNAME, INDEX_T, LEVELS, Z)				\
	static_cast<INDEX_T>(index0)								\

/**
 * Worker for _XENUM5_PROP_GEN_NODE_INDEXING() iteration, for level!=0.
 * Add chained node indexing using calls.
 */
#define _XENUM5_PROP_GEN_NODE_INDEXING_1(PROPNAME, INDEX_T, LEVELS, Z)				\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM5_PROP_GEN_INDEX0_ARGS(LEVELS, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, LEVELS))


// ============================== Index type =================================
/**
 * Define the ${PROPNAME}Index type.
 */
#define _XENUM5_PROP_DECLARE_INDEX_TYPE(PROPNAME)						\
	_XENUM5_DOC(Integer type big enough to count and index both PROPNAME values and indexnodes.)	\
	typedef typename ::_XENUM5_NS::SelectInt< ::_XENUM5_NS::cmax(				\
			sizeof(BOOST_PP_CAT(PROPNAME, Values)) / sizeof(BOOST_PP_CAT(PROPNAME, Value)), \
			BOOST_PP_CAT(PROPNAME, NodesSize)					\
		) >::type BOOST_PP_CAT(PROPNAME, Index);					_XENUM5_NWLN \


// ============================== Node type ==================================
/**
 * Define the ${PROPNAME}IndexNode type.
 */
#define _XENUM5_PROP_DECLARE_NODE_TYPE(PROPNAME)						\
	_XENUM5_DOC(IndexNode type for PROPNAME, to map the PROPNAME value hierarchy.)		\
	typedef ::_XENUM5_NS::IndexNode<BOOST_PP_CAT(PROPNAME, Index)>				\
		BOOST_PP_CAT(PROPNAME, Node);							_XENUM5_NWLN \


// ============================ Node counting ================================
/**
 * Callback for iteration functions. Called for each node.
 * Add +1 for each indexnode.
 */
#define _XENUM5_PROP_COUNT_NODES_ADD(ITERPOS, NODE, CTXT, STATE)				\
	BOOST_PP_INC(STATE)


// ============================== Node naming ================================
/**
 * Callback for iteration functions. Called for each node.
 * Declare a single field of the NodeNames struct.
 */
#define _XENUM5_PROP_DECLARE_NODENAME(ITERPOS, NODE, CTXT)					\
	BOOST_PP_CAT(_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)), Node)		\
	_XENUM5_PROP_GEN_NODE_NAME(								\
		CTXT,										\
		_XENUM5_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)				\
	);											_XENUM5_NWLN


// ===================== DEF {Store,anon}::getNode() =========================
/**
 * Define get${propname}Node() getters for all levels.
 */
#define _XENUM5_PROP_DEFINE_GET_NODE(DEPTH, CTXT, Z)						\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PROP_DEFINE_GET_NODE_N,							\
		CTXT										\
	)											\

/**
 * Define get${propname}Node() getter for given level.
 */
#define _XENUM5_PROP_DEFINE_GET_NODE_N(Z, N, CTXT)						\
	_XENUM5_PROP_DEFINE_GET_NODE_N_I1(							\
		_XENUM5_CTXT_GET_DECLPFX(CTXT),							\
		_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		Z										\
	)											\

/**
 * Worker for _XENUM5_PROP_DEFINE_GET_NODE_N().
 */
#define _XENUM5_PROP_DEFINE_GET_NODE_N_I1(DECLPFX, PROPNAME, LEVEL, DECL, Z)			\
	_XENUM5_DOC(Retrieve a level LEVEL node of the PROPNAME data hierarchy.)		\
	DECLPFX BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const				\
	BOOST_PP_CAT(PROPNAME, Node&)								\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM5_PROP_GEN_INDEX0_PARMS(							\
			Enum,									\
			BOOST_PP_CAT(PROPNAME, Index),						\
			LEVEL,									\
			Z									\
		)										\
	)											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return BOOST_PP_CAT(PROPNAME, Nodes)[						\
			_XENUM5_PROP_GEN_NODE_INDEXING(						\
				PROPNAME,							\
				BOOST_PP_CAT(PROPNAME, Index),					\
				LEVEL,								\
				Z								\
			)									\
		];										_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN


// ======================== DECL Store::getSize() ============================
/**
 * Declare Store::get${propname}Size() for all levels.
 * For properties implemented in source.
 */
#define _XENUM5_PROP_SRC_DECLS_GET_SIZE(DEPTH, PROPDEF, Z)					\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PROP_SRC_DECLS_GET_SIZE_N,						\
		PROPDEF										\
	)											\

/**
 * Declare Store::get${propname}Size() for this level.
 */
#define _XENUM5_PROP_SRC_DECLS_GET_SIZE_N(Z, LEVEL, PROPDEF)					\
	static size_t BOOST_PP_CAT(BOOST_PP_CAT(get, _XENUM5_PROPDEF_GET_NAME(PROPDEF)), Size) (\
		_XENUM5_PROP_GEN_INDEX0_PARMS(Enum, size_t, LEVEL, Z)				\
	);											_XENUM5_NWLN


// ========================= DEF Store::getSize() ============================
/**
 * Define Store::get${propname}Size() getters for all levels. For source implementation.
 */
#define _XENUM5_PROP_SRC_DEFINE_GET_SIZE(DEPTH, CTXT, Z)					\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PROP_SRC_DEFS_GET_SIZE_N,						\
		CTXT										\
	)											\

/**
 * Define get${propname}Size() getter for this level.
 */
#define _XENUM5_PROP_SRC_DEFS_GET_SIZE_N(Z, N, CTXT)						\
	_XENUM5_PROP_SRC_DEFS_GET_SIZE_N_I1(							\
		_XENUM5_PROPDEF_GET_NAME(_XENUM5_CTXT_GET_PROPDEF(CTXT)),			\
		N,										\
		_XENUM5_DECL_GET_SCOPE(_XENUM5_CTXT_GET_DECL(CTXT)),				\
		_XENUM5_STORE_NAME(_XENUM5_CTXT_GET_DECL(CTXT)),				\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Worker for _XENUM5_PROP_DEFS_GET_SIZE().
 */
#define _XENUM5_PROP_SRC_DEFS_GET_SIZE_N_I1(PROPNAME, LEVEL, SCOPE, STORENAME, DECL, Z)		\
	size_t											\
	SCOPE STORENAME :: BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
		_XENUM5_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, LEVEL, Z)		\
	)											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return										\
		_XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME) ::					\
		BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (				\
			_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(LEVEL), Z)			\
		)										\
		.size;										_XENUM5_NWLN \
	}											_XENUM5_NWLN


// ====================== DECL Store::get$PROPNAME() =========================
/**
 * Declare Store::get${propname}() value getter.
 * For properties implemented in source.
 */
#define _XENUM5_PROP_SRC_DECLS_GET_VALUE(PROPNAME, DEPTH, PROPDEF, Z)				\
	static const _XENUM5_PROPDEF_GET_PARM_TYPE(PROPDEF) BOOST_PP_CAT(get, PROPNAME) (	\
		_XENUM5_PROP_GEN_INDEX0_PARMS(Enum, size_t, DEPTH, Z)				\
	);											_XENUM5_NWLN


// ========================= DEF Value::getSize() ============================
/**
 * Declare Store::get${propname}Size() for all levels.
 * For properties implemented in source.
 */
#define _XENUM5_PROP_SRC_DECLV_GET_SIZE(DEPTH, PROPDEF, Z)					\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PROP_SRC_DECLV_GET_SIZE_N,						\
		PROPDEF										\
	)											\


/**
 * Declare Value::get${propname}Size() for this level.
 */
#define _XENUM5_PROP_SRC_DECLV_GET_SIZE_N(Z, LEVEL, PROPDEF)					\
	_XENUM5_PROP_SRC_DECLV_GET_SIZE_I1(							\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		LEVEL,										\
		Z										\
	)											\

/**
 * Worker for _XENUM5_PROP_SRC_DECLV_GET_SIZE().
 */
#define _XENUM5_PROP_SRC_DECLV_GET_SIZE_I1(PROPNAME, DEPTH, LEVEL, Z)				\
	_XENUM5_DOC(										\
	BOOST_PP_IF(BOOST_PP_EQUAL(DEPTH, LEVEL),						\
		Get size of custom property PROPNAME value (number of data elements).,		\
		Get number of BOOST_PP_IF(BOOST_PP_EQUAL(DEPTH, BOOST_PP_INC(LEVEL)),		\
			values in,								\
			childnodes of								\
		) BOOST_PP_IF(BOOST_PP_BOOL(LEVEL),						\
			a level LEVEL node in the data hierarchy of,				\
												\
		) custom property PROPNAME.							\
	))											\
	size_t BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (				\
		_XENUM5_PROP_GEN_INDEX1_PARMS(size_t, LEVEL, Z)					\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)					\
	{											\
		return Store::BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
			value									\
			_XENUM5_PROP_GEN_INDEX1_ARGS(LEVEL, Z)					\
		);										\
	}											_XENUM5_NWLN


// ====================== DEF Value::get$PROPNAME() ==========================
/**
 * Declare Value::get${propname}() value getter.
 * For properties implemented in source.
 */
#define _XENUM5_PROP_SRC_DECLV_GET_VALUE(PROPNAME, DEPTH, PROPDEF, Z)				\
	_XENUM5_DOC(Get custom property PROPNAME value.)					\
	const _XENUM5_PROPDEF_GET_PARM_TYPE(PROPDEF) BOOST_PP_CAT(get, PROPNAME) (		\
		_XENUM5_PROP_GEN_INDEX1_PARMS(size_t, DEPTH, Z)					\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)					\
	{											\
		return Store::BOOST_PP_CAT(get, PROPNAME) (					\
			value									\
			_XENUM5_PROP_GEN_INDEX1_ARGS(DEPTH, Z)					\
		);										\
	}											_XENUM5_NWLN


#endif // _XENUM5_IMPL_PROPS_HPP
