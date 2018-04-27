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


// ======================================= DATA (HDR) ===========================================
/**
 * Worker for _XENUM5_PROP_DECLS_PLAIN().
 * Declares the data related to a single custom property, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DECLS_DATA(CTXT, DECL, PROPDEF, PROPNAME, Z)				\
	_XENUM5_INDENT_SUB									\
	public:											_XENUM5_NWLN \
	_XENUM5_DOC(Native type of custom property PROPNAME values.				_XENUM5_NWLN \
		Should be private, but is used in struct BOOST_PP_CAT(PROPNAME, ValueNames)	\
		which is declared outside this class.)						\
	_XENUM5_PROP_DECL_VALUE_TYPE(PROPNAME, PROPDEF)						\
	_XENUM5_INDENT_SUB									\
	private:										_XENUM5_NWLN \
	_XENUM5_PLAIN_HDR_DECLS_VALUES(PROPNAME, PROPDEF, DECL, CTXT, Z)			\
	/* Index-nodes only if depth != 0 */							\
	BOOST_PP_CAT(_XENUM5_PLAIN_HDR_DECLS_NODES_, BOOST_PP_BOOL(_XENUM5_PROPDEF_GET_DEPTH(PROPDEF))) \
		(CTXT, DECL, PROPDEF, PROPNAME)


/**
 * Declare and define the values.
 */
#define _XENUM5_PLAIN_HDR_DECLS_VALUES(PROPNAME, PROPDEF, DECL, CTXT, Z)			\
	_XENUM5_DOC(Array of all PROPNAME values.)						\
	static constexpr const BOOST_PP_CAT(PROPNAME, Value)					\
	BOOST_PP_CAT(PROPNAME, Values)[] = _XENUM5_PLAIN_DEFINE_VALUES(CTXT)			\


// ============================= COUNT NODES =================================
/**
 * Worker for _XENUM5_PLAIN_HDR_DECLS_DATA(). Does nothing since depth==0.
 */
#define _XENUM5_PLAIN_HDR_DECLS_NODES_0(CTXT, DECL, PROPDEF, PROPNAME)

/**
 * Worker for _XENUM5_PLAIN_HDR_DECLS_DATA(). Declares variables related to index nodes (depth>0).
 */
#define _XENUM5_PLAIN_HDR_DECLS_NODES_1(CTXT, DECL, PROPDEF, PROPNAME)				\
	_XENUM5_DOC(Total number of indexnodes for indexing PROPNAME values.)			\
	static constexpr const size_t BOOST_PP_CAT(PROPNAME, IndexSize) = 0			\
		_XENUM5_CALL_VALS(_XENUM5_PLAIN_COUNT_NODES, CTXT);				_XENUM5_NWLN \
	_XENUM5_DOC(Integer type big enough to count and index both PROPNAME values and indexnodes.)	\
	typedef typename ::_XENUM5_NS::SelectInt< ::_XENUM5_NS::cmax(				\
			sizeof(BOOST_PP_CAT(PROPNAME, Values)) / sizeof(BOOST_PP_CAT(PROPNAME, Value)), \
			BOOST_PP_CAT(PROPNAME, IndexSize)					\
		) >::type BOOST_PP_CAT(PROPNAME, Index);					_XENUM5_NWLN \
	_XENUM5_INDENT_SUB									\
	public:											_XENUM5_NWLN \
	_XENUM5_DOC(Indexnode type for PROPNAME, to map the PROPNAME value hierarchy.		_XENUM5_NWLN \
		Should be private, but is used in struct BOOST_PP_CAT(PROPNAME, NodeNames)	\
		which is declared outside this class.)						\
	typedef ::_XENUM5_NS::IndexNode<BOOST_PP_CAT(PROPNAME, Index)>				\
		BOOST_PP_CAT(PROPNAME, IndexNode);						_XENUM5_NWLN \
	_XENUM5_INDENT_SUB									\
	private:										_XENUM5_NWLN \
	_XENUM5_DOC(Mapping of all nodes and values in the PROPNAME data hierarchy.)		\
	static const BOOST_PP_CAT(PROPNAME, IndexNode)						\
		BOOST_PP_CAT(PROPNAME, IndexNodes) [BOOST_PP_CAT(PROPNAME, IndexSize)];		_XENUM5_NWLN \


// ===================================== FUNCTIONS (HDR) ========================================
/**
 * Worker for _XENUM5_PROP_DECLS_PLAIN().
 * Declares the functions related to a single custom property, implemented in header.
 */
#define _XENUM5_PLAIN_HDR_DECLS_FUNCS(CTXT, PROPDEF, PROPNAME, Z)				\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		_XENUM5_PLAIN_HDR_DECLS_FUNCS_I1,						\
		PROPDEF										\
	)											\
	_XENUM5_PLAIN_HDR_DECLS_FUNC_GET_VALUE(							\
		PROPNAME,									\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		Z)

/**
 * Callback worker for _XENUM5_PLAIN_DECLS_FUNCS() iteration.
 */
#define _XENUM5_PLAIN_HDR_DECLS_FUNCS_I1(Z, N, PROPDEF)						\
	_XENUM5_PLAIN_HDR_DECLS_FUNC_GET_NODE(							\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		N,										\
		Z										\
	)											\
	_XENUM5_PLAIN_HDR_DECLS_FUNC_GET_SIZE(							\
		_XENUM5_PROPDEF_GET_NAME(PROPDEF),						\
		N,										\
		_XENUM5_PROPDEF_GET_DEPTH(PROPDEF),						\
		Z										\
	)											\


// ================================== FUNC (HDR): getNode() =====================================
/**
 * Worker for _XENUM5_PLAIN_DECLS_FUNCS().
 * Generates get${propname}Node() getters.
 */
#define _XENUM5_PLAIN_HDR_DECLS_FUNC_GET_NODE(PROPNAME, LEVEL, Z)				\
	_XENUM5_DOC(Retrieve a level LEVEL node of the PROPNAME data hierarchy.)		\
	static BOOST_PP_IF(BOOST_PP_BOOL(LEVEL), , constexpr) const				\
	BOOST_PP_CAT(PROPNAME, IndexNode&)							\
	BOOST_PP_CAT(BOOST_PP_CAT(get, PROPNAME), Node) (					\
		_XENUM5_PROP_GEN_INDEX0_PARMS(							\
			Enum,									\
			BOOST_PP_CAT(PROPNAME, Index),						\
			LEVEL,									\
			Z									\
		)										\
	) {											\
		return BOOST_PP_CAT(PROPNAME, IndexNodes)[					\
			_XENUM5_PROP_GEN_NODE_INDEXING(						\
				PROPNAME,							\
				BOOST_PP_CAT(PROPNAME, Index),					\
				LEVEL,								\
				Z								\
			)									\
		];										\
	}											_XENUM5_NWLN \


// ================================== FUNC (HDR): getSize() =====================================
/**
 * Worker for _XENUM5_PLAIN_DECLS_FUNCS().
 * Generates get${propname}Size() getters.
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


// =============================== FUNC (HDR): get$PROPNAME() ===================================
/**
 * Worker for _XENUM5_PLAIN_DECLS_FUNCS().
 * Generates get${propname}() value getter.
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
 * Declares the functions related to a single custom property, implemented in source.
 */
#define _XENUM5_PLAIN_SRC_DECLS_FUNCS(PROPNAME, DEPTH, PROPDEF, CTXT, Z)			\
	BOOST_PP_REPEAT_ ## Z									\
	(											\
		DEPTH,										\
		_XENUM5_PROP_SRC_DECLS_GET_SIZE,						\
		PROPDEF										\
	)											\
	_XENUM5_PROP_SRC_DECLS_GET_VALUE(							\
		PROPNAME,									\
		_XENUM5_PROPDEF_GET_PARM_TYPE(PROPDEF),						\
		DEPTH,										\
		Z										\
	)


#endif // _XENUM5_IMPL_PLAIN_DECL_STORE_HPP
