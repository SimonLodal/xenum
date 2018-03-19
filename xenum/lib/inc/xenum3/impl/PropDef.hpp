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
#define _XENUM3_PROPDEF_GET_TYPE(PROPDEF)		BOOST_PP_SEQ_ELEM(0, BOOST_PP_SEQ_ELEM(1, PROPDEF))

/**
 * Get the actual data type to use.
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_GET_REAL_TYPE(PROPDEF)		BOOST_PP_SEQ_ELEM(1, BOOST_PP_SEQ_ELEM(1, PROPDEF))

/**
 * Get the type category; for branching handling of different types.
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_GET_TYPCAT(PROPDEF)		BOOST_PP_SEQ_ELEM(2, BOOST_PP_SEQ_ELEM(1, PROPDEF))

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
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(PROPNAME),							\
		_XENUM3_ERROR(LOC, Missing custom property name.),				\
		PROPNAME									\
	))											\
	_XENUM3_PROPDEF_INIT_TYPE(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM3_PROPDEF_INIT().
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_INIT_TYPE(DBGLOC, PROPTYPE, ...)					\
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(PROPTYPE),							\
		_XENUM3_ERROR(LOC, Missing custom property type.),				\
		(PROPTYPE) _XENUM3_PROPDEF_ADD_TYPES(DBGLOC, PROPTYPE)				\
	))											\
	_XENUM3_PROPDEF_INIT_DEFAULTVALUE(DBGLOC, __VA_ARGS__)


/// Helper definition for _XENUM3_PROPDEF_GET_TYPE_CATEGORY().
#define _XENUM3_PROPDEF_CATEGORY_cstring	
/// Helper definition for _XENUM3_PROPDEF_GET_TYPE_CATEGORY().
#define _XENUM3_PROPDEF_CATEGORY_IS_cstring	1

/**
 * Helper for _XENUM3_PROPDEF_INIT_TYPE().
 * @hideinitializer
 */
#define _XENUM3_PROPDEF_ADD_TYPES(DBGLOC, PROPTYPE)						\
	BOOST_PP_IF(										\
		/* For plain types this symbol is not defined, and is therefore just itself, */	\
		/* which is true; special types otoh will be defined and resolve to 0. */	\
		BOOST_PP_IS_EMPTY(BOOST_PP_CAT(_XENUM3_PROPDEF_CATEGORY_, PROPTYPE)),		\
		BOOST_PP_IF(									\
			BOOST_PP_EQUAL(1, BOOST_PP_CAT(_XENUM3_PROPDEF_CATEGORY_IS_, PROPTYPE)),\
			(char)(CSTRING),							\
			_XENUM3_ERROR(DBGLOC, Unhandled special type [PROPTYPE].)		\
		),										\
		(PROPTYPE)(PLAIN)								\
	)											\

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
