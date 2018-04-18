/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM4_IMPL_MAIN_HPP
#define _XENUM4_IMPL_MAIN_HPP


/**
 * Generate header file contents.
 * @hideinitializer
 */
#define _XENUM4_DO_DECLARE(CTXT)								\
	_XENUM4_DECLARE_STORE(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))				\
	_XENUM4_DECLARE_VALUE(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))				\
	_XENUM4_DECLARE_CNTNR(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))				\

/**
 * Generate source file contents.
 * @hideinitializer
 */
#define _XENUM4_DO_DEFINE(CTXT)									\
	_XENUM4_DEFINE_STORE(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))					\
	_XENUM4_DEFINE_CNTNR(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))					\


#endif // _XENUM4_IMPL_MAIN_HPP
