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
 * Define the data of a single custom property, for "plain" data types, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DEFINE(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
	/* FIXME: Also define NodesSize - ? */							\
	constexpr const										\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Value)					\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Values)					\
		[];										_XENUM5_NWLN \
	BOOST_PP_CAT(_XENUM5_PLAIN_HDR_DEFINE_, BOOST_PP_BOOL(DEPTH))				\
		(PNAME, DSCOPE, SNAME)								\

/**
 * Define nothing since the custom property has depth==0.
 */
#define _XENUM5_PLAIN_HDR_DEFINE_0(PNAME, DSCOPE, SNAME)


/**
 * Define the data of a single multilevel custom property, when depth!=0.
 */
#define _XENUM5_PLAIN_HDR_DEFINE_1(PNAME, DSCOPE, SNAME)						\
	constexpr const										\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Node)					\
		DSCOPE SNAME :: BOOST_PP_CAT(PNAME, Nodes)					\
		[];										_XENUM5_NWLN \


// ======================================= MAIN (SRC) ===========================================
/**
 * Define all the data and functions of a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DEFINE(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
	_XENUM5_PLAIN_SRC_DEFL(PNAME, DEPTH, PDEF, LSCOPE, CTXT, Z)				\
	_XENUM5_PLAIN_SRC_DEFS(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\

/**
 * Define the local data and functions.
 */
#define _XENUM5_PLAIN_SRC_DEFL(PNAME, DEPTH, PDEF, LSCOPE, CTXT, Z)				\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace LSCOPE {								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			_XENUM5_PLAIN_SRC_DEFL_VALUES(PNAME, PDEF, CTXT, Z)			\
			BOOST_PP_CAT(_XENUM5_PLAIN_SRC_DEFL, BOOST_PP_BOOL(DEPTH))		\
				(PNAME, DEPTH, PDEF, CTXT, Z)					\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace LSCOPE)						\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


/**
 * Worker for _XENUM5_PLAIN_SRC_DEFL(), for depth==0.
 * Values are already defined as a single plain array of values, directly indexed
 * by enum value; no need for name struct or nodes table.
 */
#define _XENUM5_PLAIN_SRC_DEFL0(PNAME, DEPTH, PDEF, CTXT, Z)					\

/**
 * Worker for _XENUM5_PLAIN_SRC_DEFL(), for depth==1.
 */
#define _XENUM5_PLAIN_SRC_DEFL1(PNAME, DEPTH, PDEF, CTXT, Z)					\
	_XENUM5_PLAIN_SRC_DEFL1_NODES(PNAME, CTXT, Z)						\
	_XENUM5_PLAIN_SRC_DEFL1_FUNCS(DEPTH, _XENUM5_CTXT_XDCL(CTXT), CTXT, Z)			\


/**
 * Define the functions declared in the store class.
 */
#define _XENUM5_PLAIN_SRC_DEFS(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)		\
	_XENUM5_PLAIN_SRC_DEFS_FUNCS(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\


// ====================================== VALUES (SRC) ==========================================
/**
 * Define the values.
 */
#define _XENUM5_PLAIN_SRC_DEFL_VALUES(PNAME, PDEF, CTXT, Z)					\
	_XENUM5_PROP_DECLARE_VALUE_TYPE(PNAME, PDEF)						\
	_XENUM5_PLAIN_DEFINE_VALUES(, PNAME, CTXT)						\


// ======================================= NODES (SRC) ==========================================
/**
 * Define the index nodes, for depth!=0; declare a name struct and define an array of nodes
 * with same layout.
 */
#define _XENUM5_PLAIN_SRC_DEFL1_NODES(PNAME, CTXT, Z)						\
	_XENUM5_PLAIN_DEFINE_NODESSIZE(, PNAME, CTXT)						\
	_XENUM5_PROP_DECLARE_INDEX_TYPE(PNAME)							\
	_XENUM5_PROP_DECLARE_NODE_TYPE(PNAME)							\
	_XENUM5_PLAIN_DECLARE_NODENAMES(PNAME, CTXT)						\
	_XENUM5_PLAIN_DECLARE_VALUENAMES(PNAME, CTXT)						\
	_XENUM5_PLAIN_DEFINE_NODES(, PNAME, CTXT)							\


// ================================== LOCAL FUNCTIONS (SRC) =====================================
/**
 * Define the local-ns functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DEFL1_FUNCS(DEPTH, XDCL, CTXT, Z)					\
	using Enum = _XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_enum;			_XENUM5_NWLN \
	_XENUM5_PROP_DEFINE_GET_NODE(DEPTH, CTXT, Z)						\


// ================================== STORE FUNCTIONS (SRC) =====================================
/**
 * Define the store class functions related to a single custom property.
 */
#define _XENUM5_PLAIN_SRC_DEFS_FUNCS(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, CTXT, Z)	\
	_XENUM5_PROP_SRC_DEFINE_GET_SIZE(DEPTH, CTXT, Z)					\
	_XENUM5_PLAIN_SRC_DEFS_GET_VALUE(PNAME, DEPTH, PDEF, LSCOPE ::, DSCOPE, SNAME, Z)	\


// ========================= get${PNAME}() (SRC) =============================
/**
 * Define get${propname}() value getter. For source implementation.
 */
#define _XENUM5_PLAIN_SRC_DEFS_GET_VALUE(PNAME, DEPTH, PDEF, LSCOPE, DSCOPE, SNAME, Z)		\
	const _XENUM5_PDEF_PARM_TYPE(PDEF)							\
	DSCOPE SNAME::BOOST_PP_CAT(get, PNAME) (						\
		_XENUM5_PROP_GEN_INDEX0_PARMS(DSCOPE SNAME::Enum,				\
			DSCOPE SNAME::BOOST_PP_CAT(PNAME, Index), DEPTH, Z)			\
	) BOOST_PP_IF(BOOST_PP_BOOL(DEPTH), , noexcept)						_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return LSCOPE BOOST_PP_CAT(PNAME, Values)[					\
			BOOST_PP_CAT(_XENUM5_PLAIN_SRC_DEFS_GET_VALUE_, BOOST_PP_BOOL(DEPTH))	\
				(PNAME, DEPTH, LSCOPE, DSCOPE, SNAME, Z)			\
		];										_XENUM5_NWLN \
	}											_XENUM5_NWLN

/**
 * Define get${propname}() indexing for depth==0.
 */
#define _XENUM5_PLAIN_SRC_DEFS_GET_VALUE_0(PNAME, DEPTH, LSCOPE, DSCOPE, SNAME, Z)		\
	DSCOPE SNAME::getIndex(index0)								\

/**
 * Define get${propname}() indexing for depth!=0.
 */
#define _XENUM5_PLAIN_SRC_DEFS_GET_VALUE_1(PNAME, DEPTH, LSCOPE, DSCOPE, SNAME, Z)		\
	LSCOPE BOOST_PP_CAT(BOOST_PP_CAT(get, PNAME), Node) (					\
		_XENUM5_PROP_GEN_INDEX0_ARGS(DEPTH, Z)						\
	)											\
	.getNextIndex(BOOST_PP_CAT(index, DEPTH))						\


// =============================== _check() ==================================
/**
 * Worker for _XENUM5_PROP_CHECK_PLAIN().
 * Define final checks on data structures, for implementation in header.
 */
#define _XENUM5_PLAIN_HDR_CHECK(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)				\
	BOOST_PP_CAT(_XENUM5_PLAIN_HDR_CHECK_, BOOST_PP_BOOL(_XENUM5_PDEF_DEPTH(PDEF)))		\
		(PNAME, DSCOPE, SNAME)

/**
 * Worker for _XENUM5_PLAIN_CHECK().
 * For depth==0, there is no final checks to be made.
 */
#define _XENUM5_PLAIN_HDR_CHECK_0(PNAME, DSCOPE, SNAME)						\

/**
 * Worker for _XENUM5_PLAIN_CHECK().
 * For depth!=0, do check sizes of generated data.
 */
#define _XENUM5_PLAIN_HDR_CHECK_1(PNAME, DSCOPE, SNAME)						\
	static_assert(										\
		sizeof(DSCOPE SNAME::BOOST_PP_CAT(PNAME, ValueNames)) ==			\
		sizeof(DSCOPE SNAME::BOOST_PP_CAT(PNAME, Values)),				\
		"Struct/array size mismatch (ValueNames / Values)."				\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(DSCOPE SNAME::BOOST_PP_CAT(PNAME, NodeNames)) ==				\
		sizeof(DSCOPE SNAME::BOOST_PP_CAT(PNAME, Nodes)),				\
		"Struct/array size mismatch (NodeNames / Nodes)."				\
	);											_XENUM5_NWLN \


/**
 * Worker for _XENUM5_PROP_CHECK_PLAIN().
 * Define final checks on data structures, for implementation in source.
 */
#define _XENUM5_PLAIN_SRC_CHECK(PNAME, PDEF, LSCOPE, DSCOPE, SNAME, Z)				\
	BOOST_PP_CAT(_XENUM5_PLAIN_SRC_CHECK_, BOOST_PP_BOOL(_XENUM5_PDEF_DEPTH(PDEF)))		\
		(PNAME, LSCOPE, DSCOPE, SNAME)							\

/**
 * Worker for _XENUM5_PLAIN_SRC_CHECK(), for depth==0.
 */
#define _XENUM5_PLAIN_SRC_CHECK_0(PNAME, LSCOPE, DSCOPE, SNAME)					\
	static_assert(										\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Values)) ==					\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Value)) * DSCOPE SNAME::size,		\
		"Data size mismatch (Values / enum-size)."					\
	);											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_PLAIN_SRC_CHECK(), for depth!=0.
 */
#define _XENUM5_PLAIN_SRC_CHECK_1(PNAME, LSCOPE, DSCOPE, SNAME)					\
	static_assert(										\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, NodeNames)) ==				\
		LSCOPE::BOOST_PP_CAT(PNAME, NodesSize) *					\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Node)),					\
		"Struct size mismatch (NodeNames / NodesSize)."					\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, Nodes)) ==					\
		sizeof(LSCOPE::BOOST_PP_CAT(PNAME, NodeNames)),					\
		"Array/struct size mismatch (Nodes / NodeNames)."				\
	);											_XENUM5_NWLN \


#endif // _XENUM5_IMPL_PLAIN_DEFINE_HPP
