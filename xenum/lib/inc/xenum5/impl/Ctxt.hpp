/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Macros to handle the context "objects" passed around between many functions.
 * The context object contains the enum-specific SUFFIX. Besides that it is mainly a
 * container for random things that need to be passed through from loop initiators
 * to loop callbacks, and have to be stuffed inside a single parameter.
 */
#ifndef _XENUM5_IMPL_CTXT_HPP
#define _XENUM5_IMPL_CTXT_HPP


/**
 * Get enum suffix. Must always be defined.
 */
#define _XENUM5_CTXT_GET_SUFFIX(CTXT)			BOOST_PP_SEQ_ELEM(0, CTXT)

/**
 * Get enum declaration; a seq containing all the parameters of the XENUM_DECL_$suffix macro.
 */
#define _XENUM5_CTXT_GET_DECL(CTXT)			BOOST_PP_SEQ_ELEM(1, CTXT)

/**
 * Get the current property index, if any.
 */
#define _XENUM5_CTXT_GET_PROPINDEX(CTXT)		BOOST_PP_SEQ_ELEM(2, CTXT)

/**
 * Set the current property index.
 */
#define _XENUM5_CTXT_SET_PROPINDEX(CTXT, PROPINDEX)	BOOST_PP_SEQ_REPLACE(CTXT, 2, PROPINDEX)

/**
 * Get the current property definition field, if any.
 */
#define _XENUM5_CTXT_GET_PDEF(CTXT)			BOOST_PP_SEQ_ELEM(3, CTXT)

/**
 * Set the current property definition field.
 */
#define _XENUM5_CTXT_SET_PDEF(CTXT, PDEF)		BOOST_PP_SEQ_REPLACE(CTXT, 3, PDEF)

/**
 * Get current enum-value identifier, if any.
 */
#define _XENUM5_CTXT_GET_IDENT(CTXT)			BOOST_PP_SEQ_ELEM(4, CTXT)

/**
 * Set the current enum-value identifier.
 */
#define _XENUM5_CTXT_SET_IDENT(CTXT, IDENT)		BOOST_PP_SEQ_REPLACE(CTXT, 4, IDENT)

/**
 * Get current data tree iteration position, if any.
 */
#define _XENUM5_CTXT_GET_ITERPOS(CTXT)			BOOST_PP_SEQ_ELEM(5, CTXT)

/**
 * Set the current data tree iteration position.
 */
#define _XENUM5_CTXT_SET_ITERPOS(CTXT, ITERPOS)		BOOST_PP_SEQ_REPLACE(CTXT, 5, ITERPOS)

/**
 * Get current data tree node, if any.
 */
#define _XENUM5_CTXT_GET_NODE(CTXT)			BOOST_PP_SEQ_ELEM(6, CTXT)

/**
 * Set the current data tree node.
 */
#define _XENUM5_CTXT_SET_NODE(CTXT, NODE)		BOOST_PP_SEQ_REPLACE(CTXT, 6, NODE)

/**
 * Get current callback function, if any.
 */
#define _XENUM5_CTXT_GET_CALLBACK(CTXT)			BOOST_PP_SEQ_ELEM(7, CTXT)

/**
 * Set the current callback function.
 */
#define _XENUM5_CTXT_SET_CALLBACK(CTXT, CALLBACK)	BOOST_PP_SEQ_REPLACE(CTXT, 7, CALLBACK)

/**
 * Get current declaration prefix, if any.
 */
#define _XENUM5_CTXT_GET_DECLPFX(CTXT)			BOOST_PP_SEQ_ELEM(8, CTXT)

/**
 * Set the current declaration prefix.
 */
#define _XENUM5_CTXT_SET_DECLPFX(CTXT, DECLPFX)		BOOST_PP_SEQ_REPLACE(CTXT, 8, DECLPFX)


/**
 * Create a new context object.
 */
#define _XENUM5_CTXT_INIT(SUFFIX)								\
	(SUFFIX)										\
	(_XENUM5_DECL_INIT(SUFFIX))								\
	()											\
	()											\
	()											\
	()											\
	()											\
	()											\
	()											\


#endif // _XENUM5_IMPL_CTXT_HPP
