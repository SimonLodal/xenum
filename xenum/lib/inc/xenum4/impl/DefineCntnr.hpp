/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM4_IMPL_DEFINE_CNTNR_HPP
#define _XENUM4_IMPL_DEFINE_CNTNR_HPP


// ==============================================================================================
/**
 * Main entry function.
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR(CTXT, DECL)							\
	_XENUM4_DEFC_SIZE(CTXT, DECL)								\
	_XENUM4_DEFC_ENUM_COPY(CTXT)								\


// ==============================================================================================
/**
 * Define the $cntnr::size static var.
 * @hideinitializer
 */
// FIXME: Is it really necessary to define this at all?
#define _XENUM4_DEFC_SIZE(CTXT, DECL)								\
	constexpr const size_t _XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_CNTNR_NAME(DECL)::_size;	_XENUM4_NWLN


// ==============================================================================================
/**
 * Define the static enum-value copies.
 * @hideinitializer
 */
#define _XENUM4_DEFC_ENUM_COPY(CTXT)								\
	_XENUM4_CALL_VALS(_XENUM4_DEFC_ENUM_COPY_MEMBER, CTXT)

/**
 * Callback worker for _XENUM4_DEFC_ENUM_COPY().
 * @hideinitializer
 */
#define _XENUM4_DEFC_ENUM_COPY_MEMBER(CTXT, IDENT, ...)						\
	_XENUM4_DEFC_ENUM_COPY_MEMBER_PREFIX(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))IDENT;		_XENUM4_NWLN

/**
 * Worker for _XENUM4_DEFC_ENUM_COPY_MEMBER().
 * @hideinitializer
 */
#define _XENUM4_DEFC_ENUM_COPY_MEMBER_PREFIX(CTXT, DECL)					\
	constexpr const										\
	_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_DECL_GET_VALUENAME(DECL)				\
	_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_CNTNR_NAME(DECL)::


#endif // _XENUM4_IMPL_DEFINE_CNTNR_HPP
