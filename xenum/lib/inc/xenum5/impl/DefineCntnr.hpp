/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM5_IMPL_DEFINE_CNTNR_HPP
#define _XENUM5_IMPL_DEFINE_CNTNR_HPP


// ==============================================================================================
/**
 * Main entry function.
 */
#define _XENUM5_DEFINE_CNTNR(CTXT, XDCL)							\
	_XENUM5_NWLN _XENUM5_CMNT(Cntnr:Main)							\
	_XENUM5_DEFC_SIZE(CTXT, XDCL)								\
	_XENUM5_DEFC_ENUM_COPY(CTXT)								\


// ==============================================================================================
/**
 * Define the $cntnr::size static var.
 */
// FIXME: Is it really necessary to define this at all?
#define _XENUM5_DEFC_SIZE(CTXT, XDCL)								\
	constexpr const size_t _XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_size;		_XENUM5_NWLN


// ==============================================================================================
/**
 * Define the static enum-value copies.
 */
#define _XENUM5_DEFC_ENUM_COPY(CTXT)								\
	_XENUM5_CALL_VALS(_XENUM5_DEFC_ENUM_COPY_MEMBER, CTXT)

/**
 * Callback worker for _XENUM5_DEFC_ENUM_COPY().
 */
#define _XENUM5_DEFC_ENUM_COPY_MEMBER(CTXT, IDENT, ...)						\
	_XENUM5_DEFC_ENUM_COPY_MEMBER_PREFIX(CTXT, _XENUM5_CTXT_XDCL(CTXT))IDENT;		_XENUM5_NWLN

/**
 * Worker for _XENUM5_DEFC_ENUM_COPY_MEMBER().
 */
#define _XENUM5_DEFC_ENUM_COPY_MEMBER_PREFIX(CTXT, XDCL)					\
	constexpr const										\
	_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_XDCL_VNAME(XDCL)					\
	_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::


#endif // _XENUM5_IMPL_DEFINE_CNTNR_HPP
