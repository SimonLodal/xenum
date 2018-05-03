/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Macros to handle custom property definitions.
 */
#ifndef _XENUM5_IMPL_PROPDEF_HPP
#define _XENUM5_IMPL_PROPDEF_HPP


/**
 * Get the name of a custom property.
 */
#define _XENUM5_PDEF_NAME(PDEF)			BOOST_PP_SEQ_ELEM(0, PDEF)

/**
 * Get the data type of a custom property.
 */
#define _XENUM5_PDEF_TYPE(PDEF)			BOOST_PP_SEQ_ELEM(0, BOOST_PP_SEQ_ELEM(1, PDEF))

/**
 * Get the actual data type used for storing data for this custom property.
 */
#define _XENUM5_PDEF_REAL_TYPE(PDEF)		BOOST_PP_SEQ_ELEM(1, BOOST_PP_SEQ_ELEM(1, PDEF))

/**
 * Get the data type used as parameter type in functions handling data for this property.
 */
#define _XENUM5_PDEF_PARM_TYPE(PDEF)		BOOST_PP_SEQ_ELEM(2, BOOST_PP_SEQ_ELEM(1, PDEF))

/**
 * Get the type category; for branching handling of different types.
 */
#define _XENUM5_PDEF_TYPCAT(PDEF)		BOOST_PP_SEQ_ELEM(3, BOOST_PP_SEQ_ELEM(1, PDEF))

/**
 * Get the default value of a custom property.
 */
#define _XENUM5_PDEF_DEFAULTVALUE(PDEF)		BOOST_PP_SEQ_ELEM(2, PDEF)

/**
 * Get the depth of a custom property.
 */
#define _XENUM5_PDEF_DEPTH(PDEF)		BOOST_PP_SEQ_ELEM(3, PDEF)

/**
 * Get the "PLACEMENT" feature; 0=place implementation in source file, 1=in header file.
 */
#define _XENUM5_PDEF_PLACEMENT(PDEF)		BOOST_PP_SEQ_ELEM(0, BOOST_PP_SEQ_ELEM(4, PDEF))

/**
 * Get the "PLACEMENT" feature as suffix string; HDR or SRC.
 */
#define _XENUM5_PDEF_PLACEMENT_STR(PDEF)	BOOST_PP_IF(					\
							_XENUM5_PDEF_PLACEMENT(PDEF),		\
							HDR,					\
							SRC)

//#define _XENUM5_PDEF_FEATURES(PDEF)		BOOST_PP_SEQ_ELEM(4, PDEF)


/**
 * Initialize a custom property definition; generate error if required fields are missing/empty,
 * and fill in defaults where applicable.
 * @param DBGLOC Config location description, for debugging and error reporting.
 * @param ... The custom property definition, expanded as individual parameters.
 * @return Initialized custom property declaration, as a sequence, where all fields are present.
 */
#define _XENUM5_PDEF_INIT(DBGLOC, ...)								\
	_XENUM5_PDEF_INIT_NAME(DBGLOC, __VA_ARGS__)						\

/*
_PDEF_INIT: dbgloc=DBGLOC argc=BOOST_PP_VARIADIC_SIZE(__VA_ARGS__) args=__VA_ARGS__ _XENUM5_NWLN \
*/

/**
 * Helper for _XENUM5_PDEF_INIT().
 */
#define _XENUM5_PDEF_INIT_NAME(DBGLOC, PNAME, ...)						\
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(PNAME),							\
		_XENUM5_ERROR(LOC, Missing custom property name.),				\
		PNAME										\
	))											\
	_XENUM5_PDEF_INIT_TYPE(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_PDEF_INIT().
 */
#define _XENUM5_PDEF_INIT_TYPE(DBGLOC, PROPTYPE, ...)						\
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(PROPTYPE),							\
		_XENUM5_ERROR(LOC, Missing custom property type.),				\
		(PROPTYPE) _XENUM5_PDEF_ADD_TYPES(DBGLOC, PROPTYPE)				\
	))											\
	_XENUM5_PDEF_INIT_DEFAULTVALUE(DBGLOC, __VA_ARGS__)


/// Helper definition for _XENUM5_PDEF_TYPCAT().
#define _XENUM5_PDEF_CATEGORY_cstring	
/// Helper definition for _XENUM5_PDEF_TYPCAT().
#define _XENUM5_PDEF_CATEGORY_IS_cstring	1

/**
 * Helper for _XENUM5_PDEF_INIT_TYPE().
 */
#define _XENUM5_PDEF_ADD_TYPES(DBGLOC, PROPTYPE)						\
	BOOST_PP_IF(										\
		/* For plain types this symbol is not defined, and is therefore just itself, */	\
		/* which is true; special types otoh will be defined and resolve to 0. */	\
		BOOST_PP_IS_EMPTY(BOOST_PP_CAT(_XENUM5_PDEF_CATEGORY_, PROPTYPE)),		\
		BOOST_PP_IF(									\
			BOOST_PP_EQUAL(1, BOOST_PP_CAT(_XENUM5_PDEF_CATEGORY_IS_, PROPTYPE)),	\
			(char)(char*)(CSTRING),							\
			_XENUM5_ERROR(DBGLOC, Unhandled special type [PROPTYPE].)		\
		),										\
		(PROPTYPE)(PROPTYPE&)(PLAIN)							\
	)											\

/**
 * Helper for _XENUM5_PDEF_INIT().
 */
#define _XENUM5_PDEF_INIT_DEFAULTVALUE(DBGLOC, DEFAULTVALUE, ...)				\
	(DEFAULTVALUE)										\
	_XENUM5_PDEF_INIT_DEPTH(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_PDEF_INIT().
 */
#define _XENUM5_PDEF_INIT_DEPTH(DBGLOC, DEPTH, ...)						\
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(DEPTH),							\
		0,										\
		DEPTH										\
	))											\
	_XENUM5_PDEF_INIT_FEATURES(DBGLOC, __VA_ARGS__)

/**
 * Helper for _XENUM5_PDEF_INIT().
 */
#define _XENUM5_PDEF_INIT_FEATURES(DBGLOC, FEATURES)						\
	(BOOST_PP_CAT(										\
		_XENUM5_PDEF_INIT_FEATURES_,							\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(FEATURES))					\
	) (DBGLOC, BOOST_PP_TUPLE_ENUM(FEATURES)))

/**
 * Helper for _XENUM5_PDEF_INIT_FEATURES(), when features tuple is not defined.
 */
#define _XENUM5_PDEF_INIT_FEATURES_0(DBGLOC, PLACEMENT)						\
	(0)

/**
 * Helper for _XENUM5_PDEF_INIT_FEATURES(), when features tuple is defined.
 */
#define _XENUM5_PDEF_INIT_FEATURES_1(DBGLOC, PLACEMENT, ...)					\
	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(PLACEMENT),							\
		(0),										\
		(BOOST_PP_BOOL(PLACEMENT))							\
	)											\


#endif // _XENUM5_IMPL_PROPDEF_HPP
