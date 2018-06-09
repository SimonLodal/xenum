/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of declarations in store class context, for "cstring" data type category.
 */
#ifndef _XENUM5_IMPL_CSTRING_DECL_STORE_HPP
#define _XENUM5_IMPL_CSTRING_DECL_STORE_HPP


// ========================================== MAIN ==============================================
/**
 * Entry point for all custom-prop related declarations in store class (header).
 */
#define _XENUM5_CSTRING_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\
_XENUM5_INDENT_SUB _XENUM5_CMNT(PNAME:data: _XENUM5_PDEF_PROP_DATA(PDEF))			\
	BOOST_PP_CAT(_XENUM5_CSTRING_DATA_DECLS_, _XENUM5_PDEF_PROP_DATA(PDEF))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\
_XENUM5_INDENT_SUB _XENUM5_CMNT(PNAME:get: _XENUM5_PDEF_IMPL_GET(PDEF))				\
	BOOST_PP_CAT(_XENUM5_CSTRING_GET_DECLS_, _XENUM5_PDEF_IMPL_GET(PDEF))			\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


// =========================== DECLS prop data ===============================
/**
 * No data to declare since nobody uses it.
 */
/* FIXME: Implement later
#define _XENUM5_CSTRING_DATA_DECLS_OFF(PNAME, DEPTH, PDEF, CTXT, Z)				\
*/

/**
 * No data to declare since it is all defined in source file.
 */
#define _XENUM5_CSTRING_DATA_DECLS_SRC(PNAME, DEPTH, PDEF, CTXT, Z)				\

/**
 * Define data inline since some inline methods use it.
 */
#define _XENUM5_CSTRING_DATA_DECLS_HDR(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_DECLARE_VALUE_TYPE(PNAME, PDEF)						\
	_XENUM5_CSTRING_DEFINE_VALUES(static, PNAME, CTXT)					\
	_XENUM5_CSTRING_DEFINE_NODESSIZE(static, PNAME, CTXT)					\
	_XENUM5_PROP_DECLARE_INDEX_TYPE(PNAME)							\
	_XENUM5_PROP_DECLARE_NODE_TYPE(PNAME)							\
	_XENUM5_CSTRING_DECLARE_NODENAMES(PNAME, CTXT)						\
	_XENUM5_CSTRING_DECLARE_VALUENAMES(PNAME, CTXT)						\
	_XENUM5_CSTRING_DEFINE_NODES(static, PNAME, CTXT)					\


// ========================== DECLS prop getters =============================
/**
 * Omit getters, turned off.
 */
/* FIXME: Implement later
#define _XENUM5_CSTRING_GET_DECLS_off(PNAME, DEPTH, PDEF, CTXT, Z)				\
*/

/**
 * Declare getters, defined in source file.
 */
#define _XENUM5_CSTRING_GET_DECLS_ext(PNAME, DEPTH, PDEF, CTXT, Z)				\
	/* INC() because IndexNodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_SRC_DECLS_INDEX_TYPE(PNAME, BOOST_PP_INC(DEPTH))				\
	_XENUM5_PROP_SRC_DECLS_GET_SIZE(BOOST_PP_INC(DEPTH), PDEF, Z)				\
	_XENUM5_PROP_SRC_DECLS_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\

/**
 * Define getters as inline constexpr.
 */
#define _XENUM5_CSTRING_GET_DECLS_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_DEFINE_GET_NODE(								\
		/* INC() because Nodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM5_CTXT_SET_DECLPFX(CTXT, static),						\
		Z										\
	)											\
	_XENUM5_PROP_HDR_DECLS_GET_SIZE(BOOST_PP_INC(DEPTH), PDEF, Z)				\
	_XENUM5_CSTRING_GET_DEFS_cxp(PNAME, DEPTH, PDEF, Z)					\

/**
 * Generate get${propname}() value getter.
 */
// FIXME: Merge with function to define the source implementation.
#define _XENUM5_CSTRING_GET_DEFS_cxp(PNAME, DEPTH, PDEF, Z)					\
	_XENUM5_DOC(Get value of the custom property PNAME.)					\
	static constexpr const _XENUM5_PDEF_PARM_TYPE(PDEF)					\
	BOOST_PP_CAT(get, PNAME) (								\
		_XENUM5_PROP_GEN_INDEX0_PARMS(Enum, BOOST_PP_CAT(PNAME, Index), DEPTH, Z)	\
	) BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return & BOOST_PP_CAT(PNAME, Values)[						\
			BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (				\
				_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(DEPTH), Z)		\
			)									\
			.index									\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN


#endif // _XENUM5_IMPL_CSTRING_DECL_STORE_HPP
