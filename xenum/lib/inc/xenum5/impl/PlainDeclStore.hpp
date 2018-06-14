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
	BOOST_PP_CAT(_XENUM5_PLAIN_GETTERS_DECLS_, _XENUM5_PDEF_IMPL_GET(PDEF))			\
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
	_XENUM5_PROP_VALUETYPE_DECL(PNAME, PDEF)						\
	_XENUM5_PLAIN_VALUES_DEF(static, PNAME, CTXT)						\
	BOOST_PP_CAT(_XENUM5_PLAIN_DATA_DECLS_HDR_, BOOST_PP_BOOL(DEPTH))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


/**
 * Worker for _XENUM5_PLAIN_DATA_DECLS_HDR(), for depth==0.
 * Values are already defined as a single plain array of values, directly indexed
 * by enum value; no need for name struct or nodes table.
 */
#define _XENUM5_PLAIN_DATA_DECLS_HDR_0(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * Worker for _XENUM5_PLAIN_DATA_DECLS_HDR(), for depth!=0.
 * Declares variables related to index nodes (depth>0).
 */
#define _XENUM5_PLAIN_DATA_DECLS_HDR_1(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PLAIN_NODESSIZE_DEF(static, PNAME, CTXT)					\
	_XENUM5_PROP_INDEXTYPE_SELECT_DECL(PNAME)						\
	_XENUM5_PROP_NODETYPE_DECL(PNAME)							\
	_XENUM5_PLAIN_NODENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_PLAIN_VALUENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_PLAIN_NODES_DEF(static, PNAME, CTXT)						\
	_XENUM5_PROP_GETNODE_DEF(								\
		DEPTH,										\
		_XENUM5_CTXT_SET_DECLPFX(CTXT, static),						\
		Z										\
	)											\


// ========================== DECLS prop getters =============================
/**
 * Omit getters, turned off.
 */
/* FIXME: Implement later
#define _XENUM5_PLAIN_GETTERS_DECLS_off(PNAME, DEPTH, PDEF, CTXT, Z)				\
*/

/**
 * Declare getters, defined in source file.
 */
#define _XENUM5_PLAIN_GETTERS_DECLS_ext(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_INDEXTYPE_FIXED_DECL(PNAME, DEPTH)						\
	_XENUM5_PROP_GETSIZE_EXT_DECL(DEPTH, PDEF, Z)						\
	_XENUM5_PROP_GETVALUE_EXT_DECL(PNAME, DEPTH, PDEF, Z)					\

/**
 * Define getters as inline constexpr.
 */
#define _XENUM5_PLAIN_GETTERS_DECLS_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_GETSIZE_CXP_DEFS(DEPTH, PDEF, Z)						\
	_XENUM5_PLAIN_GETVALUE_CXP_DEFS(PNAME, DEPTH, PDEF, Z)					\


/**
 * Generate get${pname}() value getter.
 */
// FIXME: Merge with function to define the source implementation.
#define _XENUM5_PLAIN_GETVALUE_CXP_DEFS(PNAME, DEPTH, PDEF, Z)					\
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
