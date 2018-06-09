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


// ======================================= MAIN: STORE ==========================================
/**
 * Entry point for all custom-prop related declarations in store class (header).
 */
#define _XENUM5_PLAIN_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\
_XENUM5_INDENT_SUB _XENUM5_CMNT(PNAME:data: _XENUM5_PDEF_PROP_DATA(PDEF))			\
	BOOST_PP_CAT(_XENUM5_PLAIN_DATA_DECLS_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(PNAME:get: _XENUM5_PDEF_IMPL_GET(PDEF))				\
	BOOST_PP_CAT(_XENUM5_PLAIN_GET_DECLS_, _XENUM5_PDEF_IMPL_GET(PDEF))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


// =========================== DECLS prop data ===============================
/**
 * No data to declare since nobody uses it.
 */
/* FIXME: Implement later
#define _XENUM5_PLAIN_DATA_DECLS_OFF(PNAME, DEPTH, PDEF, CTXT, Z)				\
*/

/**
 * No data to declare since it is all defined in source file.
 */
#define _XENUM5_PLAIN_DATA_DECLS_SRC(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * Define data inline since some inline methods use it.
 */
#define _XENUM5_PLAIN_DATA_DECLS_HDR(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_DECLARE_VALUE_TYPE(PNAME, PDEF)						\
	_XENUM5_PLAIN_DEFINE_VALUES(static, PNAME, CTXT)					\
	BOOST_PP_CAT(_XENUM5_PLAIN_DATA_DECLS_HDR_, BOOST_PP_BOOL(DEPTH))			\
		(PNAME, PDEF, CTXT, Z)								\


/**
 * Worker for _XENUM5_PLAIN_DATA_DECLS_HDR(), for depth==0.
 * Values are already defined as a single plain array of values, directly indexed
 * by enum value; no need for name struct or nodes table.
 */
#define _XENUM5_PLAIN_DATA_DECLS_HDR_0(PNAME, PDEF, CTXT, Z)					\

/**
 * Worker for _XENUM5_PLAIN_DATA_DECLS_HDR(), for depth!=0.
 * Declares variables related to index nodes (depth>0).
 */
#define _XENUM5_PLAIN_DATA_DECLS_HDR_1(PNAME, PDEF, CTXT, Z)					\
	_XENUM5_PLAIN_DEFINE_NODESSIZE(static, PNAME, CTXT)					\
	_XENUM5_PROP_DECLARE_INDEX_TYPE(PNAME)							\
	_XENUM5_PROP_DECLARE_NODE_TYPE(PNAME)							\
	_XENUM5_PLAIN_DECLARE_NODENAMES(PNAME, CTXT)						\
	_XENUM5_PLAIN_DECLARE_VALUENAMES(PNAME, CTXT)						\
	_XENUM5_PLAIN_DEFINE_NODES(static, PNAME, CTXT)						\


// ========================== DECLS prop getters =============================
/**
 * Omit getters, turned off.
 */
/* FIXME: Implement later
#define _XENUM5_PLAIN_GET_DECLS_off(PNAME, DEPTH, PDEF, CTXT, Z)				\
*/

/**
 * Declare getters, defined in source file.
 */
#define _XENUM5_PLAIN_GET_DECLS_ext(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_SRC_DECLS_INDEX_TYPE(PNAME, DEPTH)						\
	_XENUM5_PROP_SRC_DECLS_GET_SIZE(DEPTH, PDEF, Z)						\
	_XENUM5_PROP_SRC_DECLS_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\

/**
 * Define getters as inline constexpr.
 */
#define _XENUM5_PLAIN_GET_DECLS_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_DEFINE_GET_NODE(								\
		DEPTH,										\
		_XENUM5_CTXT_SET_DECLPFX(CTXT, static),						\
		Z										\
	)											\
	_XENUM5_PROP_HDR_DECLS_GET_SIZE(DEPTH, PDEF, Z)						\
	_XENUM5_PLAIN_GET_DEFS_cxp(PNAME, DEPTH, PDEF, Z)					\


/**
 * Generate get${propname}() value getter.
 */
// FIXME: Merge with function to define the source implementation.
#define _XENUM5_PLAIN_GET_DEFS_cxp(PNAME, DEPTH, PDEF, Z)				\
	_XENUM5_DOC(Get value of the custom property PNAME.)					\
	static constexpr const _XENUM5_PDEF_PARM_TYPE(PDEF)					\
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


#endif // _XENUM5_IMPL_PLAIN_DECL_STORE_HPP
