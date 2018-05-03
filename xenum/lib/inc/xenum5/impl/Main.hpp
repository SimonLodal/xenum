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
#define _XENUM5_DO_DECLARE(CTXT)								\
	_XENUM5_DECLARE_STORE(CTXT, _XENUM5_CTXT_XDCL(CTXT))					\
	_XENUM5_DECLARE_VALUE(CTXT, _XENUM5_CTXT_XDCL(CTXT))					\
	_XENUM5_DECLARE_CNTNR(CTXT, _XENUM5_CTXT_XDCL(CTXT))					\

/**
 * Generate source file contents.
 */
#define _XENUM5_DO_DEFINE(CTXT)									\
	_XENUM5_DEFINE_STORE(CTXT, _XENUM5_CTXT_XDCL(CTXT))					\
	_XENUM5_DEFINE_CNTNR(CTXT, _XENUM5_CTXT_XDCL(CTXT))					\


#endif // _XENUM5_IMPL_MAIN_HPP
