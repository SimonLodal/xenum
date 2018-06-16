/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM5_IMPL_MAIN_HPP
#define _XENUM5_IMPL_MAIN_HPP


/**
 * Generate header file contents.
 */
#define _XENUM5_MAIN_DECLARE(SUFFIX)								\
	_XENUM5_MAIN_DECLARE_I1(SUFFIX, _XENUM5_XDCL_CHECK(SUFFIX))				\

/**
 * Worker for _XENUM5_MAIN_DECLARE().
 */
#define _XENUM5_MAIN_DECLARE_I1(SUFFIX, ERRMSGS)							\
	BOOST_PP_CAT(_XENUM5_MAIN_DECLARE_, BOOST_PP_IS_EMPTY(ERRMSGS)) (SUFFIX, ERRMSGS)	\

/**
 * Validation failed. Generate error message, and no other header contents.
 */
#define _XENUM5_MAIN_DECLARE_0(SUFFIX, ERRMSGS)							\
	static_assert(false,									_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		BOOST_PP_STRINGIZE(XENUM5 declaration errors (SUFFIX) (BOOST_PP_SEQ_SIZE(ERRMSGS)):)	_XENUM5_NWLN \
		BOOST_PP_REPEAT(BOOST_PP_SEQ_SIZE(ERRMSGS), _XENUM5_MAIN_ERROR ,ERRMSGS)	\
		_XENUM5_INDENT_SUB								\
	);											\

/**
 * Callback worker to print a single error message.
 */
#define _XENUM5_MAIN_ERROR(Z, N, ERRMSGS)							\
	" " BOOST_PP_STRINGIZE([N] BOOST_PP_SEQ_ELEM(N, ERRMSGS))				_XENUM5_NWLN \

/**
 * Validation succeeded. Initialize declaration and generate header contents.
 */
#define _XENUM5_MAIN_DECLARE_1(SUFFIX, ERRMSGS)							\
	_XENUM5_MAIN_DECLARE_2(_XENUM5_CTXT_INIT(SUFFIX))					\

/**
 * Generate header file contents.
 */
#define _XENUM5_MAIN_DECLARE_2(CTXT)								\
	_XENUM5_DECLARE_STORE(CTXT, _XENUM5_CTXT_XDCL(CTXT))					\
	_XENUM5_DECLARE_VALUE(CTXT, _XENUM5_CTXT_XDCL(CTXT))					\
	_XENUM5_DECLARE_CNTNR(CTXT, _XENUM5_CTXT_XDCL(CTXT))					\


/**
 * Generate source file contents.
 * Note: No need for validation, already done in DECLARE().
 */
#define _XENUM5_MAIN_DEFINE(SUFFIX)								\
	_XENUM5_MAIN_DEFINE_I1(_XENUM5_CTXT_INIT(SUFFIX))					\

/// Worker for _XENUM5_MAIN_DEFINE().
#define _XENUM5_MAIN_DEFINE_I1(CTXT)								\
	_XENUM5_DEFINE_STORE(CTXT, _XENUM5_CTXT_XDCL(CTXT))					\
	_XENUM5_DEFINE_CNTNR(CTXT, _XENUM5_CTXT_XDCL(CTXT))					\


#endif // _XENUM5_IMPL_MAIN_HPP
