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
#define _XENUM5_XDCL_DSCOPE(XDCL)		BOOST_PP_SEQ_ELEM(1, XDCL)

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
 * Validate the whole XENUM5_{suffix}'s D() declaration. This is done first, so the actual
 * initialization does not have to check for errors while initializing.
 */
#define _XENUM5_XDCL_CHECK(SUFFIX)								\
	_XENUM5_CALL_DECL(_XENUM5_XDCL_CHECK_DO, SUFFIX)					\

/**
 * Check number of parameters.
 */
#define _XENUM5_XDCL_CHECK_DO(SUFFIX, ...)							\
	BOOST_PP_CAT(										\
		_XENUM5_XDCL_CHECK_PARMCNT_,							\
		BOOST_PP_LESS(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 7)				\
	) (, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))						\
	_XENUM5_XDCL_CHECK_DSCOPE(, __VA_ARGS__)

/// Parameter count error.
#define _XENUM5_XDCL_CHECK_PARMCNT_0(LOC, PCNT)							\
	(LOC: Excess declaration parameters (PCNT).)						\

/// Parameter count ok.
#define _XENUM5_XDCL_CHECK_PARMCNT_1(LOC, PCNT)							\

/**
 * DSCOPE field: Nothing to check, it is optional and can be anything.
 */
#define _XENUM5_XDCL_CHECK_DSCOPE(LOC, DSCOPE, ...)						\
	_XENUM5_XDCL_CHECK_CNAME(LOC, __VA_ARGS__)						\

/**
 * Check container name.
 */
#define _XENUM5_XDCL_CHECK_CNAME(LOC, CNAME, ...)						\
	BOOST_PP_CAT(_XENUM5_XDCL_CHECK_CNAME_, BOOST_PP_IS_EMPTY(CNAME)) (LOC, CNAME)		\
	_XENUM5_XDCL_CHECK_VNAME(LOC, __VA_ARGS__)						\

/// Container-class name error.
#define _XENUM5_XDCL_CHECK_CNAME_1(LOC, CNAME)							\
	(LOC: Missing enum-container class name.)						\

/// Container-class name ok.
#define _XENUM5_XDCL_CHECK_CNAME_0(LOC, CNAME)							\

/**
 * Check value name.
 */
#define _XENUM5_XDCL_CHECK_VNAME(LOC, VNAME, ...)						\
	BOOST_PP_CAT(_XENUM5_XDCL_CHECK_VNAME_, BOOST_PP_IS_EMPTY(VNAME)) (LOC, VNAME)		\
	_XENUM5_XDCL_CHECK_INTTYPE(LOC, __VA_ARGS__)						\

/// Value-class name error.
#define _XENUM5_XDCL_CHECK_VNAME_1(LOC, VNAME)							\
	(LOC: Missing enum-value class name.)							\

/// Value-class name ok.
#define _XENUM5_XDCL_CHECK_VNAME_0(LOC, VNAME)							\

/**
 * Int-type: Nothing to check, it is optional and can be anything.
 */
#define _XENUM5_XDCL_CHECK_INTTYPE(LOC, INTTYPE, ...)						\
	_XENUM5_XDCL_CHECK_FEATURES(LOC, __VA_ARGS__)						\

/**
 * Check feature options.
 */
#define _XENUM5_XDCL_CHECK_FEATURES(LOC, FEATURES, ...)						\
	BOOST_PP_CAT(_XENUM5_XDCL_CHECK_FEATURES_, BOOST_PP_IS_EMPTY(FEATURES)) (LOC, FEATURES)	\
	_XENUM5_XDCL_CHECK_PDEFS(LOC, __VA_ARGS__)						\

/// Features empty; ok.
#define _XENUM5_XDCL_CHECK_FEATURES_1(LOC, FEATURES)						\

/// Features non-empty; check if tuple.
#define _XENUM5_XDCL_CHECK_FEATURES_0(LOC, FEATURES)						\
	BOOST_PP_CAT(_XENUM5_XDCL_CHECK_FEATURES_0_, BOOST_PP_IS_BEGIN_PARENS(FEATURES))	\
		(LOC, FEATURES)									\

/// Features is not a tuple; error.
#define _XENUM5_XDCL_CHECK_FEATURES_0_0(LOC, FEATURES)						\
	(LOC: Feature options must be a parenthesized list (found: FEATURES).)			\

/// Features non-empty; error since no features options are defined yet.
#define _XENUM5_XDCL_CHECK_FEATURES_0_1(LOC, FEATURES)						\
	(LOC: No feature options implemented yet.)						\

/**
 * Check custom property declarations.
 */
#define _XENUM5_XDCL_CHECK_PDEFS(LOC, PDEFS, ...)						\
	BOOST_PP_CAT(_XENUM5_XDCL_CHECK_PDEFS_, BOOST_PP_IS_EMPTY(PDEFS)) (LOC, PDEFS)		\
	/* Call next parameter check from here if ever added */

/// Propdefs empty; ok.
#define _XENUM5_XDCL_CHECK_PDEFS_1(LOC, PDEFS)							\

/// Pdefs non-empty; check if tuple.
#define _XENUM5_XDCL_CHECK_PDEFS_0(LOC, PDEFS)							\
	BOOST_PP_CAT(_XENUM5_XDCL_CHECK_PDEFS_0_, BOOST_PP_IS_BEGIN_PARENS(PDEFS))		\
		(LOC, PDEFS)									\

/// Pdefs not a tuple; error.
#define _XENUM5_XDCL_CHECK_PDEFS_0_0(LOC, PDEFS)						\
	(LOC: List of custom property definitions must be parenthesized.)			\

/// Pdefs is a tuple, ok, check each.
#define _XENUM5_XDCL_CHECK_PDEFS_0_1(LOC, PDEFS)						\
	BOOST_PP_REPEAT(									\
		BOOST_PP_TUPLE_SIZE(PDEFS),							\
		_XENUM5_XDCL_CHECK_PDEFN,							\
		(LOC, PDEFS)									\
 	)

/// Check a single propdef.
#define _XENUM5_XDCL_CHECK_PDEFN(Z, N, PARMS)							\
	_XENUM5_PDEF_CHECK(									\
		BOOST_PP_TUPLE_ELEM(0, PARMS) prop[N],						\
		BOOST_PP_TUPLE_ELEM(N, BOOST_PP_TUPLE_ELEM(1, PARMS))				\
	)


/**
 * Initialize the XENUM5_$suffix declaration macro; fill in defaults where applicable.
 * Assumes that _XENUM5_XDCL_CHECK() has run, and succeeded.
 * @param SUFFIX The suffix that identifies the xenum.
 * @return Initialized xenum declaration, as a sequence, where all fields are present.
 */
#define _XENUM5_XDCL_INIT(SUFFIX)								\
	(SUFFIX)										\
	_XENUM5_CALL_DECL(_XENUM5_XDCL_INIT_DO, SUFFIX)						\

/**
 * Init the first required fields.
 */
#define _XENUM5_XDCL_INIT_DO(LOC, DSCOPE, CNAME, VNAME, ...)					\
	(DSCOPE)										\
	(CNAME)											\
	(VNAME)											\
	_XENUM5_XDCL_INIT_INTTYPE(LOC, __VA_ARGS__)						\

/**
 * Init int-type field.
 */
#define _XENUM5_XDCL_INIT_INTTYPE(LOC, INTTYPE, ...)						\
	(INTTYPE)										\
	_XENUM5_XDCL_INIT_FEATURES(LOC, __VA_ARGS__)

/**
 * Init features.
 */
#define _XENUM5_XDCL_INIT_FEATURES(LOC, FEATURES, ...)						\
	BOOST_PP_IF(										\
		BOOST_PP_IS_EMPTY(FEATURES),							\
		(),										\
/* FIXME: Process features object */ \
		FEATURES									\
	)											\
	_XENUM5_XDCL_INIT_PDEFS(LOC, __VA_ARGS__)						\

/**
 * Init custom property definitions.
 */
#define _XENUM5_XDCL_INIT_PDEFS(LOC, PDEFS)							\
	( BOOST_PP_CAT(										\
		_XENUM5_XDCL_INIT_PDEFS_,							\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(PDEFS))						\
	) (LOC, PDEFS) )									\

/// No custom properties.
#define _XENUM5_XDCL_INIT_PDEFS_0(LOC, PDEFS)							\

/// Custom properties exist.
#define _XENUM5_XDCL_INIT_PDEFS_1(LOC, PDEFS)							\
	BOOST_PP_REPEAT(									\
		BOOST_PP_TUPLE_SIZE(PDEFS),							\
		_XENUM5_XDCL_INIT_PDEFN,							\
		(LOC, PDEFS)									\
 	)

/**
 * Helper for _XENUM5_XDCL_INIT().
 */
#define _XENUM5_XDCL_INIT_PDEFN(Z, N, DATA)							\
	(_XENUM5_PDEF_INIT(									\
		BOOST_PP_TUPLE_ELEM(2, 0, DATA) prop[N],					\
		BOOST_PP_TUPLE_ENUM(BOOST_PP_TUPLE_ELEM(N, BOOST_PP_TUPLE_ELEM(2, 1, DATA)))	\
	))


#endif // _XENUM5_IMPL_XDCL_HPP
