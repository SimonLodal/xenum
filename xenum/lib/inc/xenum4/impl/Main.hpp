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
	/* Run all the header functions in order. */						\
	_XENUM4_DECLARE_CNTNR_BEGIN(CTXT)							\
	_XENUM4_DECLARE_CNTNR_ENUM_NATIVE(CTXT)							\
	_XENUM4_DECLARE_CNTNR_ENUM_COPY(CTXT)							\
	_XENUM4_DECLARE_CNTNR_IDENTPOOL(CTXT)							\
	_XENUM4_DECLARE_CNTNR_FUNCS(CTXT)							\
	_XENUM4_PROPS_DECLC(CTXT)								\
	_XENUM4_DECLARE_CNTNR_END								\
	_XENUM4_DECLARE_VALUE(CTXT)								\

/**
 * Generate source file contents.
 * @hideinitializer
 */
#define _XENUM4_DO_DEFINE(CTXT)									\
	/* Run all the source functions in order. */						\
	_XENUM4_DEFINE_CNTNR_ENUMSIZE(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))			\
	_XENUM4_DEFINE_CNTNR_ENUM_COPY(CTXT)							\
	_XENUM4_DEFINE_CNTNR_FUNCS(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))				\
	_XENUM4_DEFINE_CNTNR_IDENTPOOL(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))			\
	_XENUM4_PROPS_DEFINE(CTXT)								\


#endif // _XENUM4_IMPL_MAIN_HPP
