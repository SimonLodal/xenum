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
#define _XENUM5_PLAIN_HDR_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_PLAIN_HDR_DECLS_VALUES(PNAME, PDEF, CTXT, Z)					\
	BOOST_PP_CAT(_XENUM5_PLAIN_HDR_DECLS, BOOST_PP_BOOL(DEPTH))				\
		(PNAME, PDEF, CTXT, Z)								\
	_XENUM5_PLAIN_HDR_DECLS_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * Worker for _XENUM5_PLAIN_HDR_DECLS(), for depth==0.
 * Values are already defined as a single plain array of values, directly indexed
 * by enum value; no need for name struct or nodes table.
 */
#define _XENUM5_PLAIN_HDR_DECLS0(PNAME, PDEF, CTXT, Z)						\

/**
 * Worker for _XENUM5_PLAIN_HDR_DECLS(), for depth!=0.
 */
#define _XENUM5_PLAIN_HDR_DECLS1(PNAME, PDEF, CTXT, Z)						\
	_XENUM5_PLAIN_HDR_DECLS1_NODES(PNAME, PDEF, CTXT, Z)					\


// ======================================= MAIN (SRC) ===========================================
/**
 * Declare the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_PLAIN_SRC_DECLS_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\


// ====================================== VALUES (HDR) ==========================================
/**
 * Declare and define the value type and values.
 */
#define _XENUM5_PLAIN_HDR_DECLS_VALUES(PNAME, PDEF, CTXT, Z)					\
	_XENUM5_PROP_DECL_VALUE_TYPE(PNAME, PDEF)						\
	_XENUM5_PLAIN_DEFINE_VALUES(static, PNAME, CTXT)					\


// ======================================= NODES (HDR) ==========================================
/**
 * Worker for _XENUM5_PLAIN_HDR_DECLS_DATA(). Declares variables related to index nodes (depth>0).
 */
#define _XENUM5_PLAIN_HDR_DECLS1_NODES(PNAME, PDEF, CTXT, Z)					\
	_XENUM5_PLAIN_DEFINE_NODESSIZE(static, PNAME, CTXT)					\
	_XENUM5_PROP_DECLARE_INDEX_TYPE(PNAME)							\
	_XENUM5_PROP_DECLARE_NODE_TYPE(PNAME)							\
	_XENUM5_PLAIN_DECLARE_NODENAMES(PNAME, CTXT)						\
	_XENUM5_PLAIN_DECLARE_VALUENAMES(PNAME, CTXT)						\
	_XENUM5_PLAIN_DEFINE_NODES(static, PNAME, CTXT)						\


// ===================================== FUNCTIONS (HDR) ========================================
/**
 * Declare the functions related to a single custom property, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DECLS_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_DEFINE_GET_NODE(								\
		DEPTH,										\
		_XENUM5_CTXT_SET_DECLPFX(CTXT, static),						\
		Z										\
	)											\
	_XENUM5_PROP_HDR_DECLS_GET_SIZE(DEPTH, PDEF, Z)						\
	_XENUM5_PLAIN_HDR_DECLS_GET_VALUE(PNAME, DEPTH, PDEF, Z)				\


// ========================= get${PNAME}() (HDR) =============================
/**
 * Generate get${propname}() value getter.
 */
#define _XENUM5_PLAIN_HDR_DECLS_GET_VALUE(PNAME, DEPTH, PDEF, Z)				\
	_XENUM5_DOC(Get value of the custom property PNAME.)					\
	static constexpr const _XENUM5_PDEF_GET_PARM_TYPE(PDEF)					\
	BOOST_PP_CAT(get, PNAME) (								\
		_XENUM5_PROP_GEN_INDEX0_PARMS(Enum, BOOST_PP_CAT(PNAME, Index), DEPTH, Z)	\
	) BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return BOOST_PP_CAT(PNAME, Values)[						\
			BOOST_PP_CAT(								\
				_XENUM5_PLAIN_GEN_VALUE_INDEXING_,				\
				BOOST_PP_BOOL(DEPTH)						\
			) (PNAME, DEPTH, Z)							\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN \

/**
 * Generate value indexing expression for a property having depth==0.
 */
#define _XENUM5_PLAIN_GEN_VALUE_INDEXING_0(PNAME, DEPTH, Z)					\
	getIndex(index0)

/**
 * Generate value indexing expression for a property having depth!=0.
 */
#define _XENUM5_PLAIN_GEN_VALUE_INDEXING_1(PNAME, DEPTH, Z)					\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (						\
		_XENUM5_PROP_GEN_INDEX0_ARGS(DEPTH, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, DEPTH))						\


// ===================================== FUNCTIONS (SRC) ========================================
/**
 * Worker for _XENUM5_PROP_DECLS_PLAIN().
 * Declare the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DECLS_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_SRC_DECLS_GET_SIZE(DEPTH, PDEF, Z)						\
	_XENUM5_PROP_SRC_DECLS_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\


#endif // _XENUM5_IMPL_PLAIN_DECL_STORE_HPP
