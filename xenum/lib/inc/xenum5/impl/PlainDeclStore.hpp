/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in store class context, for "plain" data type category.
 */
#ifndef _XENUM5_IMPL_PLAIN_DECL_STORE_HPP
#define _XENUM5_IMPL_PLAIN_DECL_STORE_HPP


// ======================================= MAIN (HDR) ===========================================
/**
 * Declare the data and functions related to a single custom property, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DECLS(PROPNAME, DEPTH, PROPDEF, CTXT, Z)				\
	_XENUM5_PLAIN_HDR_DECLS_VALUES(PROPNAME, PROPDEF, CTXT, Z)				\
	BOOST_PP_CAT(_XENUM5_PLAIN_HDR_DECLS, BOOST_PP_BOOL(DEPTH))				\
		(PROPNAME, PROPDEF, CTXT, Z)							\
	_XENUM5_PLAIN_HDR_DECLS_FUNCS(PROPNAME, DEPTH, PROPDEF, CTXT, Z)			\

/**
 * Worker for _XENUM5_PLAIN_HDR_DECLS(), for depth==0.
 * Values are already defined as a single plain array of values, directly indexed
 * by enum value; no need for name struct or nodes table.
 */
#define _XENUM5_PLAIN_HDR_DECLS0(PROPNAME, PROPDEF, CTXT, Z)					\

/**
 * Worker for _XENUM5_PLAIN_HDR_DECLS(), for depth!=0.
 */
#define _XENUM5_PLAIN_HDR_DECLS1(PROPNAME, PROPDEF, CTXT, Z)					\
	_XENUM5_PLAIN_HDR_DECLS1_NODES(PROPNAME, PROPDEF, CTXT, Z)				\


// ======================================= MAIN (SRC) ===========================================
/**
 * Declare the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DECLS(PROPNAME, DEPTH, PROPDEF, CTXT, Z)				\
	_XENUM5_PLAIN_SRC_DECLS_FUNCS(PROPNAME, DEPTH, PROPDEF, CTXT, Z)			\


// ====================================== VALUES (HDR) ==========================================
/**
 * Declare and define the value type and values.
 */
#define _XENUM5_PLAIN_HDR_DECLS_VALUES(PROPNAME, PROPDEF, CTXT, Z)				\
	_XENUM5_PROP_DECL_VALUE_TYPE(PROPNAME, PROPDEF)						\
	_XENUM5_PLAIN_DEFINE_VALUES(static, PROPNAME, CTXT)					\


// ======================================= NODES (HDR) ==========================================
/**
 * Worker for _XENUM5_PLAIN_HDR_DECLS_DATA(). Declares variables related to index nodes (depth>0).
 */
#define _XENUM5_PLAIN_HDR_DECLS1_NODES(PROPNAME, PROPDEF, CTXT, Z)				\
	_XENUM5_PLAIN_DEFINE_NODESSIZE(static, PROPNAME, CTXT)					\
	_XENUM5_PROP_DECLARE_INDEX_TYPE(PROPNAME)						\
	_XENUM5_PROP_DECLARE_NODE_TYPE(PROPNAME)						\
	_XENUM5_PLAIN_DECLARE_NODENAMES(PROPNAME, CTXT)						\
	_XENUM5_PLAIN_DECLARE_VALUENAMES(PROPNAME, CTXT)						\
	_XENUM5_PLAIN_DEFINE_NODES(static, PROPNAME, CTXT)					\


// ===================================== FUNCTIONS (HDR) ========================================
/**
 * Worker for _XENUM5_PROP_DECLS_PLAIN().
 * Declare the functions related to a single custom property, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DECLS_FUNCS(PROPNAME, DEPTH, PROPDEF, CTXT, Z)			\
	_XENUM5_PROP_DEFINE_GET_NODE(								\
		DEPTH,										\
		_XENUM5_CTXT_SET_DECLPFX(CTXT, static),						\
		Z										\
	)											\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PLAIN_HDR_DECLS_FUNCS_I1,						\
		PROPDEF										\
	)											\
	_XENUM5_PLAIN_HDR_DECLS_FUNC_GET_VALUE(PROPNAME, DEPTH, Z)				\

/**
 * Callback worker for _XENUM5_PLAIN_DECLS_FUNCS() iteration.
 */
#define _XENUM5_PLAIN_HDR_DECLS_FUNCS_I1(Z, N, PROPDEF)						\
	_XENUM5_PLAIN_HDR_DECLS_FUNC_GET_SIZE(							\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		N,										\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		Z										\
	)											\


// =========================== getSize() (HDR) ===============================
/**
 * Worker for _XENUM5_PLAIN_DECLS_FUNCS().
 * Generate get${propname}Size() getters.
 */
#define _XENUM5_PLAIN_HDR_DECLS_FUNC_GET_SIZE(PROPNAME, LEVEL, DEPTH, Z)			\
	_XENUM5_DOC(Get number of								\
		BOOST_PP_IF(									\
			BOOST_PP_EQUAL(DEPTH, BOOST_PP_INC(LEVEL)),				\
			values in,								\
			childnodes of								\
		) a level LEVEL node in the PROPNAME data hierarchy.)				\
	static BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr)					\
	const BOOST_PP_CAT(PROPNAME, Index)&							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (					\
		_XENUM5_PROP_GEN_INDEX0_PARMS(							\
			Enum,									\
			BOOST_PP_CAT(PROPNAME, Index),						\
			LEVEL,									\
			Z									\
		)										\
	) {											\
		return BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (			\
			_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(LEVEL), Z)			\
		)										\
		.size;										\
	}											_XENUM5_NWLN \


// ======================== get${PROPNAME}() (HDR) ===========================
/**
 * Generate get${propname}() value getter.
 */
#define _XENUM5_PLAIN_HDR_DECLS_FUNC_GET_VALUE(PROPNAME, DEPTH, Z)				\
	_XENUM5_DOC(Get value of the custom property PROPNAME.)					\
	static BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , constexpr) const				\
	BOOST_PP_CAT(PROPNAME, Value&)								\
	BOOST_PP_CAT(get, PROPNAME) (								\
		_XENUM5_PROP_GEN_INDEX0_PARMS(							\
			Enum,									\
			BOOST_PP_CAT(PROPNAME, Index),						\
			DEPTH,									\
			Z									\
		)										\
	) {											\
		return BOOST_PP_CAT(PROPNAME, Values)[						\
			BOOST_PP_CAT(								\
				_XENUM5_PLAIN_GEN_VALUE_INDEXING_,				\
				BOOST_PP_BOOL(DEPTH)						\
			) (PROPNAME, DEPTH, Z)							\
		];										\
	}											_XENUM5_NWLN \

/**
 * Generate value indexing expression for a property having depth==0.
 */
#define _XENUM5_PLAIN_GEN_VALUE_INDEXING_0(PROPNAME, DEPTH, Z)					\
	getIndex(index0)

/**
 * Generate value indexing expression for a property having depth!=0.
 */
#define _XENUM5_PLAIN_GEN_VALUE_INDEXING_1(PROPNAME, DEPTH, Z)					\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM5_PROP_GEN_INDEX0_ARGS(DEPTH, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, DEPTH))						\



// ===================================== FUNCTIONS (SRC) ========================================
/**
 * Worker for _XENUM5_PROP_DECLS_PLAIN().
 * Declare the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DECLS_FUNCS(PROPNAME, DEPTH, PROPDEF, CTXT, Z)			\
	_XENUM5_PROP_SRC_DECLS_GET_SIZE(DEPTH, PROPDEF, Z)					\
	_XENUM5_PROP_SRC_DECLS_GET_VALUE(PROPNAME, DEPTH, PROPDEF, Z)				\


#endif // _XENUM5_IMPL_PLAIN_DECL_STORE_HPP
