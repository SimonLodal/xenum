/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Macros to handle the xenum declaration "object".
 */
#ifndef _XENUM5_IMPL_XDCL_HPP
#define _XENUM5_IMPL_XDCL_HPP


/**
 * @return SUFFIX that the xenum is declared with.
 */
#define _XENUM5_XDCL_SUFFIX(XDCL)		BOOST_PP_SEQ_ELEM(0, XDCL)

/**
 * @return SCOPE field of the xenum declaration.
 */
#define _XENUM5_XDCL_SCOPE(XDCL)		BOOST_PP_SEQ_ELEM(1, XDCL)

/**
 * @return Container class name field (CNAME) of the xenum declaration.
 */
#define _XENUM5_XDCL_CNAME(XDCL)		BOOST_PP_SEQ_ELEM(2, XDCL)

/**
 * @return Value class name field (VNAME) of the xenum declaration.
 */
#define _XENUM5_XDCL_VNAME(XDCL)		BOOST_PP_SEQ_ELEM(3, XDCL)

/**
 * @return INTTYPE field of the xenum declaration.
 */
#define _XENUM5_XDCL_INTTYPE(XDCL)		BOOST_PP_SEQ_ELEM(4, XDCL)

/**
 * @return FEATURES "object" of the xenum declaration.
 */
#define _XENUM5_XDCL_FEATURES(XDCL)		BOOST_PP_SEQ_ELEM(5, XDCL)

/**
 * @return 0|1 if the xenum declaration contains any custom properties.
 */
#define _XENUM5_XDCL_HAS_PROPS(XDCL)		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM5_XDCL_PDEFS(XDCL)))

/**
 * @return PROPDEFS field of the xenum declaration.
 */
#define _XENUM5_XDCL_PDEFS(XDCL)		BOOST_PP_SEQ_ELEM(6, XDCL)

/**
 * Convenience getter.
 * @return A single PROPDEF.
 */
#define _XENUM5_XDCL_PDEFN(XDCL, PINDEX)	BOOST_PP_SEQ_ELEM(PINDEX, _XENUM5_XDCL_PDEFS(XDCL))


/**
 * Initialize the XENUM5_$suffix declaration macro; generate error if required fields are
 * missing/empty, and fill in defaults where applicable.
 * @param SUFFIX The suffix that identifies the xenum.
 * @return Initialized xenum declaration, as a sequence, where all fields are present.
 */
#define _XENUM5_XDCL_INIT(SUFFIX)								\
	(SUFFIX)										\
	_XENUM5_CALL_DECL(_XENUM5_XDCL_INIT_DO, SUFFIX)

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_DO(DBGLOC, ...)							\
	_XENUM5_XDCL_INIT_SCOPE(DBGLOC, __VA_ARGS__)
/*
_XDCL_INIT_DO: dbgloc=DBGLOC argc=BOOST_PP_VARIADIC_SIZE(__VA_ARGS__) args=__VA_ARGS__ _XENUM5_NWLN \
*/

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_SCOPE(DBGLOC, SCOPE, ...)						\
	(SCOPE)											\
	_XENUM5_XDCL_INIT_CNAME(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_CNAME(DBGLOC, CNAME, ...)						\
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(CNAME),							\
		_XENUM5_ERROR(DBGLOC, Missing enum-container class name.),			\
		CNAME										\
	))											\
	_XENUM5_XDCL_INIT_VNAME(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_VNAME(DBGLOC, VNAME, ...)						\
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(VNAME),							\
		_XENUM5_ERROR(DBGLOC, Missing enum-value class name.),				\
		VNAME										\
	))											\
	_XENUM5_XDCL_INIT_INTTYPE(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_INTTYPE(DBGLOC, INTTYPE, ...)						\
	(INTTYPE)										\
	_XENUM5_XDCL_INIT_FEATURES(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_FEATURES(DBGLOC, FEATURES, ...)					\
	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(FEATURES),							\
		(),										\
/* FIXME: Process features object */ \
		FEATURES									\
	)											\
	_XENUM5_XDCL_INIT_PDEFS(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_PDEFS(DBGLOC, PDEFS)							\
	( BOOST_PP_CAT(										\
		_XENUM5_XDCL_INIT_PDEFS_,							\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(PDEFS))						\
	) (DBGLOC, PDEFS) )

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_PDEFS_0(DBGLOC, PDEFS)						\

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_PDEFS_1(DBGLOC, PDEFS)						\
	BOOST_PP_REPEAT(									\
		BOOST_PP_TUPLE_SIZE(PDEFS),							\
		_XENUM5_XDCL_INIT_PDEFN,							\
		(DBGLOC, PDEFS)									\
 	)

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_PDEFN(Z, N, DATA)							\
	(_XENUM5_PDEF_INIT(									\
		BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM(2, 0, DATA), _prop[N]),			\
		BOOST_PP_TUPLE_ENUM(BOOST_PP_TUPLE_ELEM(N, BOOST_PP_TUPLE_ELEM(2, 1, DATA)))	\
	))


#endif // _XENUM5_IMPL_XDCL_HPP