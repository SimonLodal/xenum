/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Macros to handle custom property definitions.
 */
#ifndef _XENUM3_IMPL_PROPDEF_HPP
#define _XENUM3_IMPL_PROPDEF_HPP


/**
 * Get the name of a custom property.
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_GET_NAME(PROPDEF)		BOOST_PP_SEQ_ELEM(0, PROPDEF)

/**
 * Get the data type of a custom property.
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_GET_TYPE(PROPDEF)		BOOST_PP_SEQ_ELEM(1, PROPDEF)

/**
 * Get the default value of a custom property.
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_GET_DEFAULTVALUE(PROPDEF)	BOOST_PP_SEQ_ELEM(2, PROPDEF)

/**
 * Get the depth of a custom property.
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_GET_DEPTH(PROPDEF)		BOOST_PP_SEQ_ELEM(3, PROPDEF)


/**
 * Initialize a custom property definition; generate error if required fields are missing/empty,
 * and fill in defaults where applicable.
 * @param DBGLOC Config location description, for debugging and error reporting.
 * @param ... The custom property definition, expanded as individual parameters.
 * @return Initialized custom property declaration, as a sequence, where all fields are present.
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_INIT(DBGLOC, ...)							\
	_XENUM3_PROPDEF_INIT_NAME(DBGLOC, __VA_ARGS__)						\

/*
_PROPDEF_INIT: dbgloc=DBGLOC argc=BOOST_PP_VARIADIC_SIZE(__VA_ARGS__) args=__VA_ARGS__ NWLN \
*/

/**
 * Helper for _XENUM3_PROPDEF_INIT().
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_INIT_NAME(DBGLOC, PROPNAME, ...)					\
	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(PROPNAME),							\
		Xenum3 error (DBGLOC): Missing custom property name.,				\
		(PROPNAME)									\
	)											\
	_XENUM3_PROPDEF_INIT_TYPE(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM3_PROPDEF_INIT().
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_INIT_TYPE(DBGLOC, PROPTYPE, ...)					\
/* FIXME: Define general type suffix */ \
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(PROPTYPE),							\
		Xenum3 error (DBGLOC): Missing custom property type.,				\
		PROPTYPE									\
	))											\
	_XENUM3_PROPDEF_INIT_DEFAULTVALUE(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM3_PROPDEF_INIT().
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_INIT_DEFAULTVALUE(DBGLOC, DEFAULTVALUE, ...)				\
	(DEFAULTVALUE)										\
	_XENUM3_PROPDEF_INIT_DEPTH(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM3_PROPDEF_INIT().
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_INIT_DEPTH(DBGLOC, DEPTH)						\
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(DEPTH),							\
		0,										\
		DEPTH										\
	))


#endif // _XENUM3_IMPL_PROPDEF_HPP
