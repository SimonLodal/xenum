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
 * Validate a custom property definition from XENUM5_{suffix}'s D() declaration.
 * This is done first, so the actual initialization does not have to check for errors
 * while initializing.
 */
#define _XENUM5_PDEF_CHECK(LOC, PDEF)								\
	BOOST_PP_CAT(_XENUM5_PDEF_CHECK_PDEF_, BOOST_PP_IS_EMPTY(PDEF))				\
		(LOC, PDEF)									\

/// Propdef empty; error.
#define _XENUM5_PDEF_CHECK_PDEF_1(LOC, PDEF)							\
	(LOC: Custom property definition is empty.)						\

/// Pdef is non-empty; check if tuple.
#define _XENUM5_PDEF_CHECK_PDEF_0(LOC, PDEF)							\
	BOOST_PP_CAT(_XENUM5_PDEF_CHECK_PDEF_0_, BOOST_PP_IS_BEGIN_PARENS(PDEF))		\
		(LOC, PDEF)									\

/// Pdef not a tuple; error.
#define _XENUM5_PDEF_CHECK_PDEF_0_0(LOC, PDEF)							\
	(LOC: Each custom property definition must be a parenthesized list (found: PDEF).)	\

/// Pdef is a tuple, ok, check parameters.
#define _XENUM5_PDEF_CHECK_PDEF_0_1(LOC, PDEF)							\
	_XENUM5_PDEF_CHECK_PARMS(LOC, BOOST_PP_TUPLE_ENUM(PDEF))				\

/**
 * Check all parameters of the property definition.
 */
#define _XENUM5_PDEF_CHECK_PARMS(LOC, ...)							\
	BOOST_PP_CAT(										\
		_XENUM5_PDEF_CHECK_PARMCNT_,							\
		BOOST_PP_LESS(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 6)				\
	) (LOC, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))						\
	_XENUM5_PDEF_CHECK_PNAME(LOC, __VA_ARGS__)						\

/// Parameter count error.
#define _XENUM5_PDEF_CHECK_PARMCNT_0(LOC, PCNT)							\
	(LOC: Excess property declaration parameters (PCNT).)					\

/// Parameter count ok.
#define _XENUM5_PDEF_CHECK_PARMCNT_1(LOC, PCNT)							\

/**
 * Check property name.
 */
#define _XENUM5_PDEF_CHECK_PNAME(LOC, PNAME, ...)						\
	BOOST_PP_CAT(_XENUM5_PDEF_CHECK_PNAME_, BOOST_PP_IS_EMPTY(PNAME)) (LOC, PNAME)		\
	_XENUM5_PDEF_CHECK_PTYPE(LOC(PNAME), __VA_ARGS__)					\

/// Property name error.
#define _XENUM5_PDEF_CHECK_PNAME_1(LOC, PNAME)							\
	(LOC: Missing custom property name.)							\

/// Property name ok.
#define _XENUM5_PDEF_CHECK_PNAME_0(LOC, PNAME)							\

/**
 * Check property type.
 */
#define _XENUM5_PDEF_CHECK_PTYPE(LOC, PTYPE, ...)						\
	BOOST_PP_CAT(_XENUM5_PDEF_CHECK_PTYPE_, BOOST_PP_IS_EMPTY(PTYPE)) (LOC, PTYPE)		\
	_XENUM5_PDEF_CHECK_DEFVAL(LOC, __VA_ARGS__)						\

/// Property type error.
#define _XENUM5_PDEF_CHECK_PTYPE_1(LOC, PTYPE)							\
	(LOC: Missing custom property type.)							\

/// Property type ok.
#define _XENUM5_PDEF_CHECK_PTYPE_0(LOC, PTYPE)							\

/**
 * Default value: Nothing to check since it is optional, and can be anything.
 */
#define _XENUM5_PDEF_CHECK_DEFVAL(LOC, DEFVAL, ...)						\
	_XENUM5_PDEF_CHECK_DEPTH(LOC, __VA_ARGS__)						\

/**
 * Depth: Nothing to check since it is optional, and can be anything (can't check integers).
 */
#define _XENUM5_PDEF_CHECK_DEPTH(LOC, DEPTH, ...)						\
	_XENUM5_PDEF_CHECK_FEATURES(LOC, __VA_ARGS__)						\

/**
 * Check features tuple.
 */
#define _XENUM5_PDEF_CHECK_FEATURES(LOC, FEATURES, ...)						\
	BOOST_PP_CAT(_XENUM5_PDEF_CHECK_FTUPLE_, BOOST_PP_IS_EMPTY(FEATURES))			\
		(LOC, FEATURES)									\
	/* Call next parameter check from here if ever added */

/// Features empty; ok.
#define _XENUM5_PDEF_CHECK_FTUPLE_1(LOC, FEATURES)						\

/// Features non-empty; check if tuple.
#define _XENUM5_PDEF_CHECK_FTUPLE_0(LOC, FEATURES)						\
	BOOST_PP_CAT(_XENUM5_PDEF_CHECK_FTUPLE_0_, BOOST_PP_IS_BEGIN_PARENS(FEATURES))		\
		(LOC, FEATURES)									\

/// Features is not a tuple; error.
#define _XENUM5_PDEF_CHECK_FTUPLE_0_0(LOC, FEATURES)						\
	(LOC: Feature options must be a parenthesized list (found: FEATURES).)			\

/// Features is a tuple, check contents.
#define _XENUM5_PDEF_CHECK_FTUPLE_0_1(LOC, FEATURES)						\
	BOOST_PP_CAT(										\
		_XENUM5_PDEF_CHECK_FPARMCNT_,							\
		BOOST_PP_LESS(BOOST_PP_TUPLE_SIZE(FEATURES), 2)					\
	) (LOC, BOOST_PP_TUPLE_SIZE(FEATURES))							\
	_XENUM5_PDEF_CHECK_FEATOPTS(LOC, BOOST_PP_TUPLE_ENUM(FEATURES))				\

/// Parameter count error.
#define _XENUM5_PDEF_CHECK_FPARMCNT_0(LOC, PCNT)						\
	(LOC: Excess property declaration parameters (PCNT).)					\

/// Parameter count ok.
#define _XENUM5_PDEF_CHECK_FPARMCNT_1(LOC, PCNT)						\

/**
 * Check feature options.
 */
#define _XENUM5_PDEF_CHECK_FEATOPTS(LOC, ...)							\
	_XENUM5_PDEF_CHECK_PLACEMENT(LOC, __VA_ARGS__)						\

/**
 * 'placement' feature option: Can not really be checked; must be empty, 0 or 1.
 */
#define _XENUM5_PDEF_CHECK_PLACEMENT(LOC, PLACEMENT, ...)					\
	_XENUM5_CHECK_BOOL_OR_EMPTY(PLACEMENT, LOC)						\
	/* Call next feature option check from here if ever added */


/**
 * Initialize a custom property definition; fill in defaults where applicable.
 * Assumes that _XENUM5_PDEF_CHECK() has run, and succeeded.
 * @param LOC Config location description, for debugging.
 * @param ... Remaining (optional) parameters of the custom property definition.
 * @return Initialized custom property declaration, as a sequence, where all fields are present.
 */
#define _XENUM5_PDEF_INIT(LOC, ...)								\
	_XENUM5_PDEF_INIT_I1(LOC, __VA_ARGS__)							\

/// Worker for _XENUM5_PDEF_INIT().
#define _XENUM5_PDEF_INIT_I1(LOC, PNAME, PTYPE, ...)						\
	(PNAME)											\
	_XENUM5_PDEF_INIT_TYPES(LOC, PTYPE)							\
	_XENUM5_PDEF_INIT_DEFAULTVALUE(LOC, __VA_ARGS__)					\

/// Helper definition for _XENUM5_PDEF_TYPCAT().
#define _XENUM5_PDEF_CATEGORY_cstring	
/// Helper definition for _XENUM5_PDEF_TYPCAT().
#define _XENUM5_PDEF_CATEGORY_IS_cstring	1

/**
 * Define the type fields.
 */
#define _XENUM5_PDEF_INIT_TYPES(LOC, PTYPE)							\
	(BOOST_PP_IF(										\
		/* For plain types this symbol is not defined, and is therefore just itself, */	\
		/* which is non-empty; special types must be defined and resolve to empty. */	\
		BOOST_PP_IS_EMPTY(BOOST_PP_CAT(_XENUM5_PDEF_CATEGORY_, PTYPE)),			\
		BOOST_PP_IF(									\
			BOOST_PP_EQUAL(1, BOOST_PP_CAT(_XENUM5_PDEF_CATEGORY_IS_, PTYPE)),	\
			(PTYPE)(char)(char*)(CSTRING),						\
			/ * Hopefully this is printed somewhere so the compiler sees it. * /	\
			static_assert(false, BOOST_PP_STRINGIZE(BUG (LOC): Unhandled special type [PROPTYPE].))	\
		),										\
		(PTYPE)(PTYPE)(PTYPE&)(PLAIN)							\
	))											\

/**
 * Helper for _XENUM5_PDEF_INIT().
 */
#define _XENUM5_PDEF_INIT_DEFAULTVALUE(LOC, DEFAULTVALUE, ...)					\
	(DEFAULTVALUE)										\
	_XENUM5_PDEF_INIT_DEPTH(LOC, __VA_ARGS__)						\

/**
 * Helper for _XENUM5_PDEF_INIT().
 */
#define _XENUM5_PDEF_INIT_DEPTH(LOC, DEPTH, ...)						\
	(BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(DEPTH),							\
		0,										\
		DEPTH										\
	))											\
	_XENUM5_PDEF_INIT_FEATURES(LOC, __VA_ARGS__)						\

/**
 * Helper for _XENUM5_PDEF_INIT().
 */
#define _XENUM5_PDEF_INIT_FEATURES(LOC, FEATURES)						\
	(BOOST_PP_CAT(										\
		_XENUM5_PDEF_INIT_FEATURES_,							\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(FEATURES))					\
	) (LOC, BOOST_PP_TUPLE_ENUM(FEATURES)))							\

/**
 * Helper for _XENUM5_PDEF_INIT_FEATURES(), when features tuple is not defined.
 */
#define _XENUM5_PDEF_INIT_FEATURES_0(LOC, ...)							\
	(0)

/**
 * Helper for _XENUM5_PDEF_INIT_FEATURES(), when features tuple is defined.
 * A level of indirection is needed to separate the tuple data into parameters.
 */
#define _XENUM5_PDEF_INIT_FEATURES_1(LOC, ...)							\
	_XENUM5_PDEF_INIT_FEATURES_I1(LOC, __VA_ARGS__)						\

/**
 * Helper for _XENUM5_PDEF_INIT_FEATURES(), when features tuple is defined.
 */
#define _XENUM5_PDEF_INIT_FEATURES_I1(LOC, PLACEMENT, ...)					\
	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(PLACEMENT),							\
		(0),										\
		(PLACEMENT)									\
	)											\


#endif // _XENUM5_IMPL_PROPDEF_HPP
