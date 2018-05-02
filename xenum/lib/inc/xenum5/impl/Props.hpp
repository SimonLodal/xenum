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
		BOOST_PP_SEQ_SIZE(_XENUM5_DECL_GET_PDEFS(_XENUM5_CTXT_GET_DECL(CTXT))),		\
		_XENUM5_PROP_DECLS,								\
		CTXT										\
		)

/**
 * Callback for _XENUM5_PROPS_DECLS() loop.
 */
#define _XENUM5_PROP_DECLS(Z, N, CTXT)								\
	_XENUM5_PROP_DECLS_I1									\
	(											\
		_XENUM5_DECL_GET_PDEFN(_XENUM5_CTXT_GET_DECL(CTXT), N),				\
		_XENUM5_CTXT_SET_PINDEX(CTXT, N),						\
		Z										\
	)

/**
 * Worker for _XENUM5_PROP_DECLS().
 */
#define _XENUM5_PROP_DECLS_I1(PDEF, CTXT, Z)							\
	_XENUM5_INDENT_SUB _XENUM5_CMNT(_XENUM5_PDEF_GET_NAME(PDEF))				\
	BOOST_PP_CAT(_XENUM5_PROP_DECLS_, _XENUM5_PDEF_GET_TYPCAT(PDEF))			\
	(											\
		PDEF,										\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		_XENUM5_CTXT_SET_PDEF(CTXT, PDEF),						\
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
		BOOST_PP_SEQ_SIZE(_XENUM5_DECL_GET_PDEFS(_XENUM5_CTXT_GET_DECL(CTXT))),		\
		_XENUM5_PROP_DECLV,								\
		CTXT										\
	)											\

/**
 * Callback for _XENUM5_PROPS_DECLV() loop.
 */
#define _XENUM5_PROP_DECLV(Z, N, CTXT)								\
	_XENUM5_PROP_DECLV_I1									\
	(											\
		_XENUM5_DECL_GET_PDEFN(_XENUM5_CTXT_GET_DECL(CTXT), N),				\
		_XENUM5_CTXT_SET_PINDEX(CTXT, N),						\
		Z										\
	)

/**
 * Worker for _XENUM5_PROP_DECLV().
 */
#define _XENUM5_PROP_DECLV_I1(PDEF, CTXT, Z)							\
	_XENUM5_INDENT_SUB _XENUM5_CMNT(_XENUM5_PDEF_GET_NAME(PDEF))				\
	BOOST_PP_CAT(_XENUM5_PROP_DECLV_, _XENUM5_PDEF_GET_TYPCAT(PDEF))			\
	(											\
		PDEF,										\
		_XENUM5_CTXT_SET_PDEF(CTXT, PDEF),						\
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
		BOOST_PP_SEQ_SIZE(_XENUM5_DECL_GET_PDEFS(DECL)),				\
		_XENUM5_PROP_DEFINE,								\
		CTXT										\
	)											\

/**
 * Callback for _XENUM5_PROPS_DEFINE() loop.
 */
#define _XENUM5_PROP_DEFINE(Z, N, CTXT)								\
	_XENUM5_PROP_DEFINE_I1									\
	(											\
		_XENUM5_DECL_GET_PDEFN(_XENUM5_CTXT_GET_DECL(CTXT), N),				\
		_XENUM5_CTXT_SET_PINDEX(CTXT, N),						\
		Z										\
	)

/**
 * Worker for _XENUM5_PROP_DEFINE().
 */
#define _XENUM5_PROP_DEFINE_I1(PDEF, CTXT, Z)							\
	_XENUM5_NWLN _XENUM5_INDENT_SUB _XENUM5_CMNT(Store:_XENUM5_PDEF_GET_NAME(PDEF))		\
	BOOST_PP_CAT(_XENUM5_PROP_DEFINE_, _XENUM5_PDEF_GET_TYPCAT(PDEF))			\
	(											\
		PDEF,										\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		_XENUM5_CTXT_SET_PDEF(CTXT, PDEF),						\
		Z										\
	)


/**
 * Callback for _XENUM5_DEFS_CHECK() loop.
 * Generate static_assert() checks for the N'th property.
 */
#define _XENUM5_PROP_CHECK(Z, N, CTXT)								\
	_XENUM5_PROP_CHECK_I1									\
	(											\
		_XENUM5_DECL_GET_PDEFN(_XENUM5_CTXT_GET_DECL(CTXT), N),				\
		_XENUM5_CTXT_SET_PINDEX(CTXT, N),						\
		Z										\
	)

/**
 * Worker for _XENUM5_PROP_CHECK().
 */
#define _XENUM5_PROP_CHECK_I1(PDEF, CTXT, Z)							\
	_XENUM5_CMNT(_XENUM5_PDEF_GET_NAME(PDEF))						\
	BOOST_PP_CAT(_XENUM5_PROP_CHECK_, _XENUM5_PDEF_GET_TYPCAT(PDEF))			\
	(											\
		_XENUM5_PDEF_GET_NAME(PDEF),							\
		PDEF,										\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		_XENUM5_CTXT_SET_PDEF(CTXT, PDEF),						\
		Z										\
	)


// ====================================== COMMON PARTS ==========================================
/**
 * Declare the data type for a custom property.
 */
#define _XENUM5_PROP_DECL_VALUE_TYPE(PNAME, PDEF)						\
	_XENUM5_DOC(Native type of custom property PNAME values.)				\
	typedef _XENUM5_PDEF_GET_REAL_TYPE(PDEF) BOOST_PP_CAT(PNAME, Value);			_XENUM5_NWLN \


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
 * @param CTXT Context object. Assumes the following fields are set: PINDEX, PDEF, IDENT.
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
		_XENUM5_GET_VARARG(_XENUM5_CTXT_GET_PINDEX(CTXT), __VA_ARGS__),			\
		_XENUM5_PDEF_GET_DEPTH(_XENUM5_CTXT_GET_PDEF(CTXT)),				\
		_XENUM5_CTXT_SET_IDENT(CTXT, IDENT)						\
	)

/**
 * Worker for _XENUM5_PROP_ITER_VALUES_NODE().
 * Execute tupletree iteration.
 */
#define _XENUM5_PROP_ITER_VALUES_NODE_I1(DATA, DEPTH, CTXT)					\
	_XENUM5_TT_ITERATE_DEPTH_GEN(								\
		DATA,										\
		DEPTH,										\
		(_XENUM5_CTXT_GET_CALLBACK(CTXT), _XENUM5_TT_FILTER_LEAF),			\
		CTXT										\
	)


// ========================= APPLY DEFAULT VALUE =============================
/**
 * @param NODE A leaf-node (value).
 * @param PDEF Property definition object.
 * @return NODE if non-empty, else DEFAULT_VALUE from the PDEF.
 */
// FIXME: Report error if value and defaultvalue are both empty.
#define _XENUM5_PROP_GET_VALUE(NODE, PDEF)							\
	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(NODE),							\
		_XENUM5_PDEF_GET_DEFAULTVALUE(PDEF),						\
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
#define _XENUM5_PROP_GEN_NODE_INDEXING(PNAME, INDEX_T, LEVELS, Z)				\
	BOOST_PP_CAT(										\
		_XENUM5_PROP_GEN_NODE_INDEXING_,						\
		BOOST_PP_BOOL(LEVELS)								\
	) (PNAME, INDEX_T, LEVELS, Z)								\


/**
 * Worker for _XENUM5_PROP_GEN_NODE_INDEXING() iteration, for level==0.
 * Add node indexing for level 0; direct index.
 */
#define _XENUM5_PROP_GEN_NODE_INDEXING_0(PNAME, INDEX_T, LEVELS, Z)				\
	static_cast<INDEX_T>(index0)								\

/**
 * Worker for _XENUM5_PROP_GEN_NODE_INDEXING() iteration, for level!=0.
 * Add chained node indexing using calls.
 */
#define _XENUM5_PROP_GEN_NODE_INDEXING_1(PNAME, INDEX_T, LEVELS, Z)				\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (						\
		_XENUM5_PROP_GEN_INDEX0_ARGS(LEVELS, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, LEVELS))


// ============================== Index type =================================
/**
 * Define the ${PNAME}Index type.
 */
#define _XENUM5_PROP_DECLARE_INDEX_TYPE(PNAME)							\
	_XENUM5_DOC(Integer type big enough to count and index both PNAME values and indexnodes.)	\
	typedef typename ::_XENUM5_NS::SelectInt< ::_XENUM5_NS::cmax(				\
			sizeof(BOOST_PP_CAT(PNAME, Values)) / sizeof(BOOST_PP_CAT(PNAME, Value)), \
			BOOST_PP_CAT(PNAME, NodesSize)						\
		) >::type BOOST_PP_CAT(PNAME, Index);						_XENUM5_NWLN \


// ============================== Node type ==================================
/**
 * Define the ${PNAME}IndexNode type.
 */
#define _XENUM5_PROP_DECLARE_NODE_TYPE(PNAME)							\
	_XENUM5_DOC(IndexNode type for PNAME, to map the PNAME value hierarchy.)		\
	typedef ::_XENUM5_NS::IndexNode<BOOST_PP_CAT(PNAME, Index)>				\
		BOOST_PP_CAT(PNAME, Node);							_XENUM5_NWLN \


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
	BOOST_PP_CAT(_XENUM5_PDEF_GET_NAME(_XENUM5_CTXT_GET_PDEF(CTXT)), Node)			\
	_XENUM5_PROP_GEN_NODE_NAME(								\
		CTXT,										\
		_XENUM5_TT_ITERPOS_GET_INDEXPATH(ITERPOS)					\
	);											_XENUM5_NWLN


// =================================== Value::TYPES (HDR) =======================================
/**
 * Declare the Value class types related to a single custom property, implemented in header.
 */
#define _XENUM5_PROP_HDR_DECLV_TYPES(PNAME, DEPTH)						\
	_XENUM5_DOC(Native type of custom property PNAME values.)				\
	using BOOST_PP_CAT(PNAME, Value) = typename Store::BOOST_PP_CAT(PNAME, Value);		_XENUM5_NWLN \
	BOOST_PP_CAT(_XENUM5_PROP_HDR_DECLV_INDEX_T_, BOOST_PP_BOOL(DEPTH)) (PNAME)		\

/**
 * Do not declare an Index type since the property has depth=0.
 */
#define _XENUM5_PROP_HDR_DECLV_INDEX_T_0(PNAME)							\

/**
 * Declare the ${propname}Index type since the property has depth!=0.
 */
#define _XENUM5_PROP_HDR_DECLV_INDEX_T_1(PNAME)							\
	_XENUM5_DOC(Integer type big enough to count and index both PNAME values and indexnodes.)	\
	using BOOST_PP_CAT(PNAME, Index) = typename Store::BOOST_PP_CAT(PNAME, Index);		_XENUM5_NWLN \


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
		_XENUM5_PDEF_GET_NAME(_XENUM5_CTXT_GET_PDEF(CTXT)),				\
		N,										\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		Z										\
	)											\

/**
 * Worker for _XENUM5_PROP_DEFINE_GET_NODE_N().
 */
#define _XENUM5_PROP_DEFINE_GET_NODE_N_I1(DECLPFX, PNAME, LEVEL, DECL, Z)			\
	_XENUM5_DOC(Retrieve a level LEVEL node of the PNAME data hierarchy.)			\
	DECLPFX constexpr const BOOST_PP_CAT(PNAME, Node&)					\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (						\
		_XENUM5_PROP_GEN_INDEX0_PARMS(							\
			Enum,									\
			BOOST_PP_CAT(PNAME, Index),						\
			LEVEL,									\
			Z									\
		)										\
	) BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return BOOST_PP_CAT(PNAME, Nodes)[						\
			_XENUM5_PROP_GEN_NODE_INDEXING(						\
				PNAME,								\
				BOOST_PP_CAT(PNAME, Index),					\
				LEVEL,								\
				Z								\
			)									\
		];										_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN


// ====================== INL Store::getSize() (HDR) =========================
/**
 * Declare and inline-define Store::get${propname}Size() for all levels.
 * For properties implemented in header.
 */
#define _XENUM5_PROP_HDR_DECLS_GET_SIZE(DEPTH, PDEF, Z)					\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PROP_HDR_DECLS_GET_SIZE_N,						\
		PDEF										\
	)											\

/**
 * Define get${PNAME}Size() getter for this level.
 */
#define _XENUM5_PROP_HDR_DECLS_GET_SIZE_N(Z, N, PDEF)						\
	_XENUM5_PROP_HDR_DECLS_GET_SIZE_N_I1(							\
		_XENUM5_PDEF_GET_NAME(PDEF),							\
		N,										\
		_XENUM5_PDEF_GET_DEPTH(PDEF),							\
		Z										\
	)											\

/**
 * Worker for _XENUM5_PROP_HDR_DECLS_GET_SIZE_N().
 */
#define _XENUM5_PROP_HDR_DECLS_GET_SIZE_N_I1(PNAME, LEVEL, DEPTH, Z)				\
	_XENUM5_DOC(Get number of								\
		BOOST_PP_IF(									\
			BOOST_PP_EQUAL(DEPTH, BOOST_PP_INC(LEVEL)),				\
			values in,								\
			childnodes of								\
		) a level LEVEL node in the PNAME data hierarchy.)				\
	static constexpr const BOOST_PP_CAT(PNAME, Index)&					\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Size) (						\
		_XENUM5_PROP_GEN_INDEX0_PARMS(							\
			Enum,									\
			BOOST_PP_CAT(PNAME, Index),						\
			LEVEL,									\
			Z									\
		)										\
	) BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (				\
			_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(LEVEL), Z)			\
		)										\
		.size;										_XENUM5_NWLN \
	}											_XENUM5_NWLN \


// ===================== DECL Store::getSize() (SRC) =========================
/**
 * Declare Store::get${propname}Size() for all levels.
 * For properties implemented in source.
 */
#define _XENUM5_PROP_SRC_DECLS_GET_SIZE(DEPTH, PDEF, Z)						\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PROP_SRC_DECLS_GET_SIZE_N,						\
		PDEF										\
	)											\

/**
 * Declare Store::get${propname}Size() for this level.
 */
#define _XENUM5_PROP_SRC_DECLS_GET_SIZE_N(Z, LEVEL, PDEF)					\
	static size_t										\
	BOOST_PP_CAT(BOOST_PP_CAT(get, _XENUM5_PDEF_GET_NAME(PDEF)), Size) (			\
		_XENUM5_PROP_GEN_INDEX0_PARMS(Enum, size_t, LEVEL, Z)				\
	) BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept);					_XENUM5_NWLN \


// ====================== DEF Store::getSize() (SRC) =========================
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
		_XENUM5_PDEF_GET_NAME(_XENUM5_CTXT_GET_PDEF(CTXT)),				\
		N,										\
		_XENUM5_DECL_GET_SCOPE(_XENUM5_CTXT_GET_DECL(CTXT)),				\
		_XENUM5_STORE_NAME(_XENUM5_CTXT_GET_DECL(CTXT)),				\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Worker for _XENUM5_PROP_DEFS_GET_SIZE_N().
 */
#define _XENUM5_PROP_SRC_DEFS_GET_SIZE_N_I1(PNAME, LEVEL, SCOPE, STORENAME, DECL, Z)		\
	size_t											\
	SCOPE STORENAME :: BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Size) (			\
		_XENUM5_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, LEVEL, Z)		\
	) BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return										\
		_XENUM5_IMPL_LOCAL_NS(DECL, PNAME) ::						\
		BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (					\
			_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(LEVEL), Z)			\
		)										\
		.size;										_XENUM5_NWLN \
	}											_XENUM5_NWLN


// =================== DECL Store::get${PNAME}() (SRC) =======================
/**
 * Declare Store::get${propname}() value getter.
 * For properties implemented in source.
 */
#define _XENUM5_PROP_SRC_DECLS_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\
	static const _XENUM5_PDEF_GET_PARM_TYPE(PDEF) BOOST_PP_CAT(get, PNAME) (		\
		_XENUM5_PROP_GEN_INDEX0_PARMS(Enum, size_t, DEPTH, Z)				\
	) BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept);					_XENUM5_NWLN \


// ====================== DEF Value::getSize() (HDR) =========================
/**
 * Declare and inline-define Value::get${propname}Size() for all levels.
 * For properties implemented in header.
 */
// FIXME: Merge with _XENUM5_PROP_SRC_DECLV_GET_SIZE().
#define _XENUM5_PROP_HDR_DECLV_GET_SIZE(DEPTH, PDEF, Z)						\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PROP_HDR_DECLV_GET_SIZE_N,						\
		PDEF										\
	)											\


/**
 * Declare Value::get${propname}Size() for this level.
 */
#define _XENUM5_PROP_HDR_DECLV_GET_SIZE_N(Z, LEVEL, PDEF)					\
	_XENUM5_PROP_HDR_DECLV_GET_SIZE_I1(							\
		_XENUM5_PDEF_GET_NAME(PDEF),							\
		_XENUM5_PDEF_GET_DEPTH(PDEF),							\
		LEVEL,										\
		Z										\
	)											\

/**
 * Worker for _XENUM5_PROP_HDR_DECLV_GET_SIZE_N().
 */
#define _XENUM5_PROP_HDR_DECLV_GET_SIZE_I1(PNAME, DEPTH, LEVEL, Z)				\
	_XENUM5_DOC(										\
	BOOST_PP_IF(BOOST_PP_EQUAL(DEPTH, LEVEL),						\
		Get size of custom property PNAME value (number of data elements).,		\
		Get number of BOOST_PP_IF(BOOST_PP_EQUAL(DEPTH, BOOST_PP_INC(LEVEL)),		\
			values in,								\
			childnodes of								\
		) BOOST_PP_IF(BOOST_PP_BOOL(LEVEL),						\
			a level LEVEL node in the data hierarchy of,				\
												\
		) custom property PNAME.							\
	))											\
	constexpr const BOOST_PP_CAT(PNAME, Index)&						\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Size) (						\
		_XENUM5_PROP_GEN_INDEX1_PARMS(BOOST_PP_CAT(PNAME, Index), LEVEL, Z)		\
	) const BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)					_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return Store::BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Size) (			\
			value									\
			_XENUM5_PROP_GEN_INDEX1_ARGS(LEVEL, Z)					\
		);										_XENUM5_NWLN \
	}											_XENUM5_NWLN \


// ====================== DEF Value::getSize() (SRC) =========================
/**
 * Declare and inline-define Value::get${propname}Size() for all levels.
 * For properties implemented in source.
 */
// FIXME: Merge with _XENUM5_PROP_HDR_DECLV_GET_SIZE().
#define _XENUM5_PROP_SRC_DECLV_GET_SIZE(DEPTH, PDEF, Z)						\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PROP_SRC_DECLV_GET_SIZE_N,						\
		PDEF										\
	)											\


/**
 * Declare Value::get${propname}Size() for this level.
 */
#define _XENUM5_PROP_SRC_DECLV_GET_SIZE_N(Z, LEVEL, PDEF)					\
	_XENUM5_PROP_SRC_DECLV_GET_SIZE_I1(							\
		_XENUM5_PDEF_GET_NAME(PDEF),							\
		_XENUM5_PDEF_GET_DEPTH(PDEF),							\
		LEVEL,										\
		Z										\
	)											\

/**
 * Worker for _XENUM5_PROP_SRC_DECLV_GET_SIZE_N().
 */
#define _XENUM5_PROP_SRC_DECLV_GET_SIZE_I1(PNAME, DEPTH, LEVEL, Z)				\
	_XENUM5_DOC(										\
	BOOST_PP_IF(BOOST_PP_EQUAL(DEPTH, LEVEL),						\
		Get size of custom property PNAME value (number of data elements).,		\
		Get number of BOOST_PP_IF(BOOST_PP_EQUAL(DEPTH, BOOST_PP_INC(LEVEL)),		\
			values in,								\
			childnodes of								\
		) BOOST_PP_IF(BOOST_PP_BOOL(LEVEL),						\
			a level LEVEL node in the data hierarchy of,				\
												\
		) custom property PNAME.							\
	))											\
	size_t BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Size) (					\
		_XENUM5_PROP_GEN_INDEX1_PARMS(size_t, LEVEL, Z)					\
	)											\
	const BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , noexcept)					_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return Store::BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Size) (			\
			value									\
			_XENUM5_PROP_GEN_INDEX1_ARGS(LEVEL, Z)					\
		);										_XENUM5_NWLN \
	}											_XENUM5_NWLN


// ==================== DEF Value::get${PNAME}() (HDR) =======================
/**
 * Declare Value::get${propname}() value getter.
 * For properties implemented in header.
 */
// FIXME: Merge with _XENUM5_PROP_SRC_DECLV_GET_VALUE().
#define _XENUM5_PROP_HDR_DECLV_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\
	_XENUM5_DOC(Get custom property PNAME value.)						\
	constexpr const _XENUM5_PDEF_GET_PARM_TYPE(PDEF)					\
	BOOST_PP_CAT(get, PNAME) (								\
		_XENUM5_PROP_GEN_INDEX1_PARMS(BOOST_PP_CAT(PNAME, Index), DEPTH, Z)		\
	) const BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)					_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return Store::BOOST_PP_CAT(get, PNAME) (					\
			value									\
			_XENUM5_PROP_GEN_INDEX1_ARGS(DEPTH, Z)					\
		);										_XENUM5_NWLN \
	}											_XENUM5_NWLN \


// ==================== DEF Value::get${PNAME}() (SRC) =======================
/**
 * Declare Value::get${propname}() value getter.
 * For properties implemented in source.
 */
// FIXME: Merge with _XENUM5_PROP_HDR_DECLV_GET_VALUE().
#define _XENUM5_PROP_SRC_DECLV_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\
	_XENUM5_DOC(Get custom property PNAME value.)						\
	const _XENUM5_PDEF_GET_PARM_TYPE(PDEF) BOOST_PP_CAT(get, PNAME) (			\
		_XENUM5_PROP_GEN_INDEX1_PARMS(size_t, DEPTH, Z)					\
	) const BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)					_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return Store::BOOST_PP_CAT(get, PNAME) (					\
			value									\
			_XENUM5_PROP_GEN_INDEX1_ARGS(DEPTH, Z)					\
		);										_XENUM5_NWLN \
	}											_XENUM5_NWLN


#endif // _XENUM5_IMPL_PROPS_HPP
