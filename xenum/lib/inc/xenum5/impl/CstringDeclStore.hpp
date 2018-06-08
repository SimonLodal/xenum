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
// FIXME: ext/cxp
#define _XENUM5_CSTRING_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\
	BOOST_PP_CAT(BOOST_PP_CAT(_XENUM5_CSTRING_, _XENUM5_PDEF_PLACEMENT_STR(PDEF)), _DECLS)	\
		(PNAME, DEPTH, PDEF, CTXT, Z)							\


// ======================================= MAIN (HDR) ===========================================
/**
 * Declare the data and functions related to a single custom property, implemented in header.
 */
#define _XENUM5_CSTRING_HDR_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_CSTRING_HDR_DECLS_VALUES(PNAME, PDEF, CTXT, Z)					\
	_XENUM5_CSTRING_HDR_DECLS_NODES(PNAME, CTXT, Z)						\
	_XENUM5_CSTRING_HDR_DECLS_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\


// ======================================= MAIN (SRC) ===========================================
/**
 * Declare the data related to a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DECLS(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_CSTRING_SRC_DECLS_FUNCS(PNAME, DEPTH, PDEF, Z)					\


// ====================================== VALUES (HDR) ==========================================
/**
 * Declare and define the value type and values.
 */
#define _XENUM5_CSTRING_HDR_DECLS_VALUES(PNAME, PDEF, CTXT, Z)					\
	_XENUM5_PROP_DECLARE_VALUE_TYPE(PNAME, PDEF)						\
	_XENUM5_CSTRING_DEFINE_VALUES(static, PNAME, CTXT)					\


// ======================================= NODES (HDR) ==========================================
/**
 * Define the indexnodes. Note: Called even when depth==0; for cstrings (contrary to "plain")
 * we always need an indexnodes table since each string needs to be referenced by an indexnode.
 */
#define _XENUM5_CSTRING_HDR_DECLS_NODES(PNAME, CTXT, Z)						\
	_XENUM5_CSTRING_DEFINE_NODESSIZE(static, PNAME, CTXT)					\
	_XENUM5_PROP_DECLARE_INDEX_TYPE(PNAME)							\
	_XENUM5_PROP_DECLARE_NODE_TYPE(PNAME)							\
	_XENUM5_CSTRING_DECLARE_NODENAMES(PNAME, CTXT)						\
	_XENUM5_CSTRING_DECLARE_VALUENAMES(PNAME, CTXT)						\
	_XENUM5_CSTRING_DEFINE_NODES(static, PNAME, CTXT)					\


// ===================================== FUNCTIONS (HDR) ========================================
/**
 * Declare the functions related to a single custom property, implemented in header.
 */
#define _XENUM5_CSTRING_HDR_DECLS_FUNCS(PNAME, DEPTH, PDEF, CTXT, Z)				\
	_XENUM5_PROP_DEFINE_GET_NODE(								\
		/* INC() because Nodes also has indexnodes for the leaf string values */	\
		BOOST_PP_INC(DEPTH),								\
		_XENUM5_CTXT_SET_DECLPFX(CTXT, static),						\
		Z										\
	)											\
	_XENUM5_PROP_HDR_DECLS_GET_SIZE(BOOST_PP_INC(DEPTH), PDEF, Z)				\
	_XENUM5_CSTRING_HDR_DECLS_GET_VALUE(PNAME, DEPTH, PDEF, Z)				\


// ========================= get${PNAME}() (HDR) =============================
/**
 * Generate get${propname}() value getter.
 */
#define _XENUM5_CSTRING_HDR_DECLS_GET_VALUE(PNAME, DEPTH, PDEF, Z)				\
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


// ===================================== FUNCTIONS (SRC) ========================================
/**
 * Declare the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_CSTRING_SRC_DECLS_FUNCS(PNAME, DEPTH, PDEF, Z)					\
	/* INC() because IndexNodes also has indexnodes for the leaf string values */		\
	_XENUM5_PROP_SRC_DECLS_INDEX_TYPE(PNAME, BOOST_PP_INC(DEPTH))				\
	_XENUM5_PROP_SRC_DECLS_GET_SIZE(BOOST_PP_INC(DEPTH), PDEF, Z)				\
	_XENUM5_PROP_SRC_DECLS_GET_VALUE(PNAME, DEPTH, PDEF, Z)					\


#endif // _XENUM5_IMPL_CSTRING_DECL_STORE_HPP
