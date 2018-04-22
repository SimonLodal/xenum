/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Macros to handle the xenum declaration "object".
 */
#ifndef _XENUM5_IMPL_DECL_HPP
#define _XENUM5_IMPL_DECL_HPP


/**
 * @return SUFFIX that the xenum is declared with.
 */
#define _XENUM5_DECL_GET_SUFFIX(DECL)		BOOST_PP_SEQ_ELEM(0, DECL)

/**
 * @return SCOPE field of the xenum declaration.
 */
#define _XENUM5_DECL_GET_SCOPE(DECL)		BOOST_PP_SEQ_ELEM(1, DECL)

/**
 * @return CNTNRNAME field of the xenum declaration.
 */
#define _XENUM5_DECL_GET_CNTNRNAME(DECL)	BOOST_PP_SEQ_ELEM(2, DECL)

/**
 * @return VALUENAME field of the xenum declaration.
 */
#define _XENUM5_DECL_GET_VALUENAME(DECL)	BOOST_PP_SEQ_ELEM(3, DECL)

/**
 * @return INTTYPE field of the xenum declaration.
 */
#define _XENUM5_DECL_GET_INTTYPE(DECL)		BOOST_PP_SEQ_ELEM(4, DECL)

/**
 * @return FEATURES "object" of the xenum declaration.
 */
#define _XENUM5_DECL_GET_FEATURES(DECL)		BOOST_PP_SEQ_ELEM(5, DECL)

/**
 * @return 0|1 if the xenum declaration contains any custom properties.
 */
#define _XENUM5_DECL_HAS_PROPS(DECL)		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM5_DECL_GET_PROPDEFS(DECL)))

/**
 * @return PROPDEFS field of the xenum declaration.
 */
#define _XENUM5_DECL_GET_PROPDEFS(DECL)		BOOST_PP_SEQ_ELEM(6, DECL)

/**
 * Convenience getter.
 * @return A single PROPDEF.
 */
#define _XENUM5_DECL_GET_PROPDEFN(DECL, PROPINDEX)	BOOST_PP_SEQ_ELEM(PROPINDEX, _XENUM5_DECL_GET_PROPDEFS(DECL))


/**
 * Initialize the XENUM_DECL_* macro; generate error if required fields are missing/empty,
 * and fill in defaults where applicable.
 * @param SUFFIX The suffix that identifies the xenum.
 * @return Initialized xenum declaration, as a sequence, where all fields are present.
 */
#define _XENUM5_DECL_INIT(SUFFIX)								\
	(SUFFIX)										\
	_XENUM5_DECL_INIT_DO(SUFFIX, BOOST_PP_TUPLE_ENUM(BOOST_PP_CAT(XENUM_DECL_, SUFFIX)))

/**
 * Helper for _XENUM5_DECL_INIT().
 */
#define _XENUM5_DECL_INIT_DO(DBGLOC, ...)							\
	_XENUM5_DECL_INIT_SCOPE(DBGLOC, __VA_ARGS__)
/*
_DECL_INIT_DO: dbgloc=DBGLOC argc=BOOST_PP_VARIADIC_SIZE(__VA_ARGS__) args=__VA_ARGS__ _XENUM5_NWLN \
*/

/**
 * Helper for _XENUM5_DECL_INIT().
 */
#define _XENUM5_DECL_INIT_SCOPE(DBGLOC, SCOPE, ...)						\
	(SCOPE)											\
	_XENUM5_DECL_INIT_CNTNRNAME(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_DECL_INIT().
 */
#define _XENUM5_DECL_INIT_CNTNRNAME(DBGLOC, CNTNRNAME, ...)					\
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(CNTNRNAME),							\
		_XENUM5_ERROR(DBGLOC, Missing enum-container class name.),			\
		CNTNRNAME									\
	))											\
	_XENUM5_DECL_INIT_VALUENAME(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_DECL_INIT().
 */
#define _XENUM5_DECL_INIT_VALUENAME(DBGLOC, VALUENAME, ...)					\
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(VALUENAME),							\
		_XENUM5_ERROR(DBGLOC, Missing enum-value class name.),				\
		VALUENAME									\
	))											\
	_XENUM5_DECL_INIT_INTTYPE(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_DECL_INIT().
 */
#define _XENUM5_DECL_INIT_INTTYPE(DBGLOC, INTTYPE, ...)						\
	(INTTYPE)										\
	_XENUM5_DECL_INIT_FEATURES(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_DECL_INIT().
 */
#define _XENUM5_DECL_INIT_FEATURES(DBGLOC, FEATURES, ...)					\
	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(FEATURES),							\
		(),										\
/* FIXME: Process features object */ \
		FEATURES									\
	)											\
	_XENUM5_DECL_INIT_PROPDEFS(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_DECL_INIT().
 */
#define _XENUM5_DECL_INIT_PROPDEFS(DBGLOC, PROPDEFS)						\
	( BOOST_PP_CAT(										\
		_XENUM5_DECL_INIT_PROPDEFS_,							\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(PROPDEFS))					\
	) (DBGLOC, PROPDEFS) )

/**
 * Helper for _XENUM5_DECL_INIT().
 */
#define _XENUM5_DECL_INIT_PROPDEFS_0(DBGLOC, PROPDEFS)						\

/**
 * Helper for _XENUM5_DECL_INIT().
 */
#define _XENUM5_DECL_INIT_PROPDEFS_1(DBGLOC, PROPDEFS)						\
	BOOST_PP_REPEAT(									\
		BOOST_PP_TUPLE_SIZE(PROPDEFS),							\
		_XENUM5_DECL_INIT_PROPDEFN,							\
		(DBGLOC, PROPDEFS)								\
 	)

/**
 * Helper for _XENUM5_DECL_INIT().
 */
#define _XENUM5_DECL_INIT_PROPDEFN(Z, N, DATA)							\
	(_XENUM5_PROPDEF_INIT(									\
		BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM(2, 0, DATA), _prop[N]),			\
		BOOST_PP_TUPLE_ENUM(BOOST_PP_TUPLE_ELEM(N, BOOST_PP_TUPLE_ELEM(2, 1, DATA)))	\
	))


#endif // _XENUM5_IMPL_DECL_HPP