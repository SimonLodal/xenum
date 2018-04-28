/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of definitions for "plain" data type category.
 */
#ifndef _XENUM5_IMPL_PLAIN_DEFINE_HPP
#define _XENUM5_IMPL_PLAIN_DEFINE_HPP


// ======================================= MAIN (HDR) ===========================================
/**
 * Worker for _XENUM5_PROP_DEFINE_PLAIN().
 * Define the data of a single custom property, for "plain" data types, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DEFINE(PROPNAME, PROPDEF, SCOPE, STORENAME, Z)			\
	/* FIXME: Also define IndexSize - ? */							\
	constexpr const										\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Value)				\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Values)				\
		[];										_XENUM5_NWLN \
	BOOST_PP_CAT(										\
		_XENUM5_PLAIN_HDR_DEFINE_,							\
		BOOST_PP_BOOL(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF))				\
	) (PROPNAME, SCOPE, STORENAME)

/**
 * Define nothing since the custom property has depth==0.
 */
#define _XENUM5_PLAIN_HDR_DEFINE_0(PROPNAME, SCOPE, STORENAME)


/**
 * Worker for _XENUM5_PLAIN_HDR_DEFINE().
 * Define the data of a single multilevel custom property, when depth!=0.
 */
#define _XENUM5_PLAIN_HDR_DEFINE_1(PROPNAME, SCOPE, STORENAME)					\
	constexpr const										\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Node)					\
		SCOPE STORENAME :: BOOST_PP_CAT(PROPNAME, Nodes)				\
		[];										_XENUM5_NWLN \


// ======================================= MAIN (SRC) ===========================================
/**
 * Worker for _XENUM5_PROP_DEFINE_PLAIN().
 * Define all the data and functions of a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DEFINE(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	BOOST_PP_CAT(_XENUM5_PLAIN_SRC_DEFINE_, BOOST_PP_BOOL(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF)))	\
		(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)					\

/**
 * Worker for _XENUM5_PLAIN_SRC_DEFINE(), for depth==0.
 * For this case, only generate a single plain array of values, directly indexed by enum
 * value; no need for name struct or nodes table.
 */
#define _XENUM5_PLAIN_SRC_DEFINE_0(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_PLAIN_SRC_DEFL0(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_PLAIN_SRC_DEFS0(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\

/**
 * Generate declarations and definitions that go into local namespace (parts that are
 * not declared in header). For depth==0.
 */
#define _XENUM5_PLAIN_SRC_DEFL0(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	namespace { namespace _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME) {				_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PLAIN_SRC_DEFL0_VALUES(PROPNAME, PROPDEF, CTXT, Z)			\
		_XENUM5_INDENT_DEC								\
	}}											_XENUM5_NWLN \

/**
 * Generate definitions of store class members. For depth==0.
 */
#define _XENUM5_PLAIN_SRC_DEFS0(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_PLAIN_SRC_DEFS0_FUNCS(								\
		PROPNAME,									\
		PROPDEF,									\
		SCOPE,										\
		_XENUM5_STORE_NAME(DECL),							\
		DECL,										\
		CTXT,										\
		Z										\
	)


/**
 * Worker for _XENUM5_PLAIN_SRC_DEFINE(), for depth!=0.
 */
#define _XENUM5_PLAIN_SRC_DEFINE_1(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_PLAIN_SRC_DEFL1(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_PLAIN_SRC_DEFS1(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\

/**
 * Generate declarations and definitions that go into local namespace (parts that are
 * not declared in header). For depth!=0.
 */
#define _XENUM5_PLAIN_SRC_DEFL1(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	namespace { namespace _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME) {				_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_PLAIN_SRC_DEFL1_VALUES(PROPNAME, PROPDEF, CTXT, Z)			\
		_XENUM5_PLAIN_SRC_DEFL1_NODES(PROPNAME, PROPDEF, CTXT, Z)			\
		_XENUM5_PLAIN_SRC_DEFL1_FUNCS(							\
			_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),					\
			_XENUM5_CTXT_GET_DECL(CTXT),						\
			CTXT,									\
			Z									\
		)										\
		_XENUM5_INDENT_DEC								\
	}}											_XENUM5_NWLN \


/**
 * Worker for _XENUM5_PLAIN_SRC_DEFINE().
 * Define the store class functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DEFS1(PROPNAME, PROPDEF, SCOPE, DECL, CTXT, Z)			\
	_XENUM5_PLAIN_SRC_DEFS1_FUNCS(								\
		PROPNAME,									\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		PROPDEF,									\
		SCOPE,										\
		_XENUM5_STORE_NAME(DECL),							\
		CTXT,										\
		Z										\
	)


// ================================= VALUES (SRC, DEPTH==0) =====================================
/**
 * Define the values, for depth==0.
 */
#define _XENUM5_PLAIN_SRC_DEFL0_VALUES(PROPNAME, PROPDEF, CTXT, Z)				\
	_XENUM5_PROP_DECL_VALUE_TYPE(PROPNAME, PROPDEF)						\
	_XENUM5_PLAIN_DEFINE_VALUES(, PROPNAME, CTXT)						\


// ================================= VALUES (SRC, DEPTH!=0) =====================================
/**
 * Define the values, for depth!=0; declare a struct and define values as this struct.
 */
#define _XENUM5_PLAIN_SRC_DEFL1_VALUES(PROPNAME, PROPDEF, CTXT, Z)				\
	_XENUM5_PROP_DECL_VALUE_TYPE(PROPNAME, PROPDEF)						\
	_XENUM5_PLAIN_DEFINE_VALUES(, PROPNAME, CTXT)						\


// ================================== NODES (SRC, DEPTH!=0) =====================================
/**
 * Define the index nodes, for depth!=0; declare a name struct and define nodes as this struct.
 */
#define _XENUM5_PLAIN_SRC_DEFL1_NODES(PROPNAME, PROPDEF, CTXT, Z)				\
	_XENUM5_PLAIN_DEFINE_INDEXSIZE(, PROPNAME, CTXT)					\
	_XENUM5_PLAIN_DECLARE_INDEX_TYPE(PROPNAME)						\
	_XENUM5_PLAIN_DECLARE_NODE_TYPE(PROPNAME)						\
	_XENUM5_PLAIN_DEFINE_NODENAMES(PROPNAME, CTXT)						\
	_XENUM5_PLAIN_DEFINE_VALUENAMES(PROPNAME, CTXT)						\
	_XENUM5_PLAIN_DEFINE_NODES(, PROPNAME, CTXT)						\


// ==================================== LOCAL FUNCTIONS ========================================
/**
 * Define the local-ns functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DEFL1_FUNCS(DEPTH, DECL, CTXT, Z)					\
	using Enum = _XENUM5_DECL_GET_SCOPE(DECL)_XENUM5_CNTNR_NAME(DECL)::_enum;		_XENUM5_NWLN \
	_XENUM5_PLAIN_DEFINE_GET_NODE(DEPTH, CTXT, Z)						\


// ==================================== STORE FUNCTIONS ========================================
/**
 * Define the store class functions related to a single custom property.
 * For source implementation, depth==0.
 */
#define _XENUM5_PLAIN_SRC_DEFS0_FUNCS(PROPNAME, PROPDEF, SCOPE, STORENAME, CTXT, DECL, Z)	\
	_XENUM5_PLAIN_SRC_DEFS0_GET_VALUE(							\
		PROPNAME,									\
		_XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME) ::,					\
		SCOPE,										\
		STORENAME,									\
		PROPDEF,									\
		Z										\
	)

/**
 * Define the store class functions related to a single custom property.
 * For source implementation, depth!=0.
 */
#define _XENUM5_PLAIN_SRC_DEFS1_FUNCS(PROPNAME, DEPTH, PROPDEF, SCOPE, STORENAME, CTXT, Z)	\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PLAIN_SRC_DEFS1_GET_SIZE,						\
		CTXT										\
	)											\
	_XENUM5_PLAIN_SRC_DEFS1_GET_VALUE(							\
		PROPNAME,									\
		DEPTH,										\
		_XENUM5_IMPL_LOCAL_NS(_XENUM5_CTXT_GET_DECL(CTXT), PROPNAME) ::,		\
		SCOPE,										\
		STORENAME,									\
		PROPDEF,									\
		Z										\
	)


// =========================== getSize() (SRC) ===============================
/**
 * Define get${propname}Size() getter for given level. For source implementation.
 */
#define _XENUM5_PLAIN_SRC_DEFS1_GET_SIZE(Z, N, CTXT)						\
	_XENUM5_PLAIN_SRC_DEFS1_GET_SIZE_I1(							\
		N,										\
		_XENUM5_CTXT_GET_PROPDEF(CTXT),							\
		_XENUM5_CTXT_GET_DECL(CTXT),							\
		Z										\
	)

/**
 * Worker for _XENUM5_PLAIN_SRC_DEFS1_GET_SIZE().
 */
#define _XENUM5_PLAIN_SRC_DEFS1_GET_SIZE_I1(LEVEL, PROPDEF, DECL, Z)				\
	_XENUM5_PLAIN_SRC_DEFS1_GET_SIZE_I2(							\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		LEVEL,										\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_STORE_NAME(DECL),							\
		DECL,										\
		Z										\
	)

/**
 * Worker for _XENUM5_PLAIN_SRC_DEFS1_GET_SIZE_I1().
 */
#define _XENUM5_PLAIN_SRC_DEFS1_GET_SIZE_I2(PROPNAME, LEVEL, SCOPE, STORENAME, DECL, Z)		\
	size_t											\
	SCOPE STORENAME :: BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Size) (			\
		_XENUM5_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, LEVEL, Z)		\
	)											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME) ::					\
		BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (				\
			_XENUM5_PROP_GEN_INDEX0_ARGS(BOOST_PP_INC(LEVEL), Z)			\
		)										\
		.size;										_XENUM5_NWLN \
	}											_XENUM5_NWLN \


// =================== get${PROPNAME}() (SRC, DEPTH==0) ======================
/**
 * Define get${propname}() value getter. For source implementation, depth==0.
 */
#define _XENUM5_PLAIN_SRC_DEFS0_GET_VALUE(PROPNAME, LOCALSCOPE, SCOPE, STORENAME, PROPDEF, Z)	\
	const _XENUM5_PROPDEF_GET_PARM_TYPE(PROPDEF)						\
	SCOPE STORENAME :: BOOST_PP_CAT(get, PROPNAME) (SCOPE STORENAME::Enum index0)		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return LOCALSCOPE BOOST_PP_CAT(PROPNAME, Values)[SCOPE STORENAME::getIndex(index0)];	_XENUM5_NWLN \
	}											_XENUM5_NWLN


// =================== get${PROPNAME}() (SRC, DEPTH!=0) ======================
/**
 * Define get${propname}() value getter. For source implementation, depth!=0.
 */
#define _XENUM5_PLAIN_SRC_DEFS1_GET_VALUE(PROPNAME, DEPTH, LOCALSCOPE, SCOPE, STORENAME, PROPDEF, Z)	\
	const _XENUM5_PROPDEF_GET_PARM_TYPE(PROPDEF)						\
	SCOPE STORENAME :: BOOST_PP_CAT(get, PROPNAME) (					\
		_XENUM5_PROP_GEN_INDEX0_PARMS(SCOPE STORENAME::Enum, size_t, DEPTH, Z)		\
	)											_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return LOCALSCOPE BOOST_PP_CAT(PROPNAME, Values)[				\
			LOCALSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (		\
				_XENUM5_PROP_GEN_INDEX0_ARGS(DEPTH, Z)				\
			)									\
			.getNextIndex(BOOST_PP_CAT(index, DEPTH))				\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN


// =========================== _check() ==============================
/**
 * Worker for _XENUM5_PROP_CHECK_PLAIN().
 * Define final checks on data structures, for implementation in header.
 */
#define _XENUM5_PLAIN_HDR_CHECK(PROPNAME, PROPDEF, SCOPE, STORENAME, Z)				\
	BOOST_PP_CAT(_XENUM5_PLAIN_HDR_CHECK_, BOOST_PP_BOOL(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF)))	\
		(PROPNAME, SCOPE, STORENAME)

/**
 * Worker for _XENUM5_PLAIN_CHECK().
 * For depth==0, there is no final checks to be made.
 */
#define _XENUM5_PLAIN_HDR_CHECK_0(PROPNAME, SCOPE, STORENAME)					\


/**
 * Worker for _XENUM5_PLAIN_CHECK().
 * For depth!=0, do check sizes of generated data.
 */
#define _XENUM5_PLAIN_HDR_CHECK_1(PROPNAME, SCOPE, STORENAME)					\
	static_assert(										\
		sizeof(SCOPE STORENAME::BOOST_PP_CAT(PROPNAME, ValueNames)) ==			\
		sizeof(SCOPE STORENAME::BOOST_PP_CAT(PROPNAME, Values)),			\
		"Struct/array size mismatch (ValueNames / Values)."				\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(SCOPE STORENAME::BOOST_PP_CAT(PROPNAME, NodeNames)) ==			\
		sizeof(SCOPE STORENAME::BOOST_PP_CAT(PROPNAME, Nodes)),				\
		"Struct/array size mismatch (NodeNames / Nodes)."				\
	);											_XENUM5_NWLN \

/*
_XENUM5_PLAIN_CHECK: PROPNAME _XENUM5_NWLN \
*/

/**
 * Worker for _XENUM5_PROP_CHECK_PLAIN().
 * Define final checks on data structures, for implementation in source.
 */
#define _XENUM5_PLAIN_SRC_CHECK(PROPNAME, PROPDEF, SCOPE, STORENAME, DECL, Z)			\
	BOOST_PP_CAT(_XENUM5_PLAIN_SRC_CHECK_, BOOST_PP_BOOL(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF)))	\
		(PROPNAME, _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME), SCOPE, STORENAME)		\

/**
 * Worker for _XENUM5_PLAIN_SRC_CHECK(), for depth==0.
 */
#define _XENUM5_PLAIN_SRC_CHECK_0(PROPNAME, LOCALSCOPE, SCOPE, STORENAME)			\
	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Values)) ==				\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Value)) * SCOPE STORENAME::size,	\
		"Data size mismatch (Values / enum-size)."					\
	);											_XENUM5_NWLN \


/**
 * Worker for _XENUM5_PLAIN_SRC_CHECK(), for depth!=0.
 */
#define _XENUM5_PLAIN_SRC_CHECK_1(PROPNAME, LOCALSCOPE, SCOPE, STORENAME)			\
	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, NodeNames)) ==			\
		LOCALSCOPE::BOOST_PP_CAT(PROPNAME, IndexSize) *					\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Node)),				\
		"Struct size mismatch (NodeNames / IndexSize)."					\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, Nodes)) ==				\
		sizeof(LOCALSCOPE::BOOST_PP_CAT(PROPNAME, NodeNames)),				\
		"Array/struct size mismatch (Nodes / NodeNames)."				\
	);											_XENUM5_NWLN \


#endif // _XENUM5_IMPL_PLAIN_DEFINE_HPP
