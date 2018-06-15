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
	BOOST_PP_CAT(_XENUM5_CSTRING_GETTERS_DECLS_, _XENUM5_PDEF_IMPL_GET(PDEF))		\
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
	_XENUM5_PROP_VALUETYPE_DECL(PNAME, PDEF)						\
	_XENUM5_CSTRING_VALUES_DEF(static, PNAME, CTXT)						\
	_XENUM5_CSTRING_NODESSIZE_DEF(static, PNAME, CTXT)					\
	_XENUM5_PROP_INDEXTYPE_SELECT_DECL(PNAME)						\
	_XENUM5_PROP_NODETYPE_DECL(PNAME)							\
	_XENUM5_CSTRING_NODENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_CSTRING_VALUENAMES_DECL(PNAME, CTXT)						\
	_XENUM5_CSTRING_NODES_DEF(static, PNAME, CTXT)						\
	_XENUM5_PROP_GETNODE_DEF(								\
		/* INC() because Nodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM5_CTXT_SET_DECLPFX(CTXT, static),						\
		Z										\
	)											\


// ========================== DECLS prop getters =============================
/**
 * Omit getters, turned off.
 */
/* FIXME: Implement later
#define _XENUM5_CSTRING_GETTERS_DECLS_off(PNAME, DEPTH, PDEF, CTXT, Z)				\
*/

/**
 * Declare getters, defined in source file.
 */
#define _XENUM5_CSTRING_GETTERS_DECLS_ext(PNAME, DEPTH, PDEF, CTXT, Z)				\
	/* INC() because IndexNodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_INDEXTYPE_FIXED_DECL(PNAME, BOOST_PP_INC(DEPTH))				\
	_XENUM5_PROP_GETSIZE_EXT_DECL(BOOST_PP_INC(DEPTH), PDEF, Z)				\
	_XENUM5_PROP_GETVALUE_EXT_DECL(PNAME, DEPTH, PDEF, Z)					\

/**
 * Define getters as inline constexpr.
 */
#define _XENUM5_CSTRING_GETTERS_DECLS_cxp(PNAME, DEPTH, PDEF, CTXT, Z)				\
	/* INC() because IndexNodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_GETSIZE_DEFS(BOOST_PP_INC(DEPTH), CTXT, Z)					\
	_XENUM5_CSTRING_GETVALUE_DEFS(static constexpr, PNAME, DEPTH, PDEF, , , Z)		\


#endif // _XENUM5_IMPL_CSTRING_DECL_STORE_HPP
