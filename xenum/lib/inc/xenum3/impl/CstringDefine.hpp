/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of definitions for "cstring" data type category.
 */
#ifndef _XENUM3_IMPL_CSTRING_DEFINE_HPP
#define _XENUM3_IMPL_CSTRING_DEFINE_HPP


// ======================================== DATA ================================================
/**
 * Worker for _XENUM3_PROP_DEFINE_CSTRING().
 * Defines all the data of a single custom property, for "cstring" data types.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DEFINE_DATA(CTXT, PROPDEF, SCOPE, CNTNRNAME, PROPNAME, Z)		\
	namespace BOOST_PP_CAT(_xenum_internal_, CNTNRNAME) {					NWLN \
IND1		namespace BOOST_PP_CAT(PROPNAME, _values) {					NWLN \
			_XENUM3_CSTRING_DEFINE_VALUES(CTXT)					\
IND1		}										NWLN \
		BOOST_PP_CAT(									\
			_XENUM3_CSTRING_DATA_MULTILEVEL_,					\
			BOOST_PP_BOOL(_XENUM3_PROPDEF_GET_DEPTH(PROPDEF))			\
		) (CTXT, PROPDEF, SCOPE, CNTNRNAME, PROPNAME, Z)				\
	}											NWLN \



/**
 * Defines nothing since the custom property has depth==0.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DATA_MULTILEVEL_0(CTXT, PROPDEF, SCOPE, CNTNRNAME, PROPNAME, Z)


/**
 * Worker for _XENUM3_CSTRING_DEFINE_DATA().
 * Defines the data of a single multilevel custom property (only when depth!=0).
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DATA_MULTILEVEL_1(CTXT, PROPDEF, SCOPE, CNTNRNAME, PROPNAME, Z)		\

/* FIXME: !
	_XENUM3_CSTRING_DEFINE_NODES(CTXT, PROPDEF, SCOPE, CNTNRNAME, PROPNAME, Z)		\
*/


// ============================== VALUES =================================
/**
 * Worker for _XENUM3_CSTRING_DEFINE_DATA().
 * Defines the ${propname}_values data.
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DEFINE_VALUES(CTXT)							\
	_XENUM3_PROP_ITER_VALUES(_XENUM3_CSTRING_DEFINE_VALUE, CTXT)

/**
 * Callback worker for values iteration.
 * Defines a single data value of a custom property.
 * @hideinitializer
 */
// FIXME: Report error if value and defaultvalue are both empty.
#define _XENUM3_CSTRING_DEFINE_VALUE(ITERPOS, NODE, CTXT)					\
	_XENUM3_CSTRING_DEFINE_VALUE_I1(							\
		ITERPOS,									\
		BOOST_PP_IF(									\
			BOOST_PP_IS_EMPTY(NODE),						\
			_XENUM3_PROPDEF_GET_DEFAULTVALUE(_XENUM3_CTXT_GET_PROPDEF(CTXT)),	\
			NODE									\
		),										\
		CTXT										\
	)

/**
 * Worker for _XENUM3_CSTRING_DEFINE_VALUE().
 * @hideinitializer
 */
#define _XENUM3_CSTRING_DEFINE_VALUE_I1(ITERPOS, VALUE, CTXT)					\
IND2	static constexpr const _XENUM3_PROPDEF_GET_REAL_TYPE(_XENUM3_CTXT_GET_PROPDEF(CTXT))	\
	_XENUM3_PROP_GEN_NODE_NAME(CTXT, _XENUM3_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS))	\
	[] = VALUE;										NWLN


// ============================== NODES =================================

































#endif // _XENUM3_IMPL_CSTRING_DEFINE_HPP
