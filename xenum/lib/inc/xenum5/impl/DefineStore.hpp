/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Definition of the internal store class.
 */
#ifndef _XENUM5_IMPL_DEFINE_STORE_HPP
#define _XENUM5_IMPL_DEFINE_STORE_HPP


// ==============================================================================================
/**
 * Implementation parts that are not declared in the store class are declared and defined inside
 * a namespace with this name, to minimize risk of name clash with user code.
 * @return Name of implementation namespace.
 */
#define _XENUM5_IMPL_LOCAL_NS(XDCL, PNAME)							\
	BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(_xenum5_local_, _XENUM5_XDCL_SUFFIX(XDCL)), _), PNAME)


// ==============================================================================================
/**
 * Main entry function.
 */
#define _XENUM5_DEFINE_STORE(CTXT, XDCL)							\
	_XENUM5_CMNT(Store:Main)								\
	_XENUM5_DEFS_SIZE(CTXT, XDCL)								\
	BOOST_PP_CAT(										\
		BOOST_PP_CAT(_XENUM5_IDENT_, _XENUM5_XDCL_PLACEMENT_STR(XDCL)),			\
		_DEFINE										\
	) (XDCL, CTXT)										\
	_XENUM5_PROPS_DEFINE(CTXT, XDCL)							\
	_XENUM5_DEFS_CHECK(CTXT, XDCL)								\


// ==============================================================================================
/**
 * Define the .size var.
 */
// FIXME: Is it really necessary to define this at all?
#define _XENUM5_DEFS_SIZE(CTXT, XDCL)								\
	constexpr const size_t _XENUM5_XDCL_DSCOPE(XDCL) _XENUM5_STORE_NAME(XDCL) ::size;	_XENUM5_NWLN


// ==============================================================================================
/**
 * Define static_assert() checks on generated data structures.
 */
#define _XENUM5_DEFS_CHECK(CTXT, XDCL)								\
	_XENUM5_DEFS_CHECK_I1(									\
		CTXT,										\
		XDCL,										\
		_XENUM5_XDCL_DSCOPE(XDCL),							\
		_XENUM5_STORE_NAME(XDCL),							\
		_XENUM5_XDCL_VNAME(XDCL)							\
	)

/**
 * Worker for _XENUM5_DEFS_CHECK().
 */
#define _XENUM5_DEFS_CHECK_I1(CTXT, XDCL, DSCOPE, SNAME, VNAME)					\
	_XENUM5_NWLN _XENUM5_CMNT(Store:Check)							\
	void DSCOPE SNAME::_check(void)								\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CMNT(Main)								\
		static_assert(									\
			sizeof(_XENUM5_IMPL_LOCAL_NS(XDCL, )::identOffsets) ==			\
			DSCOPE SNAME ::size *							\
			sizeof(_XENUM5_IMPL_LOCAL_NS(XDCL, )::IdentIndex),			\
			"BUG: Struct size mismatch (identOffsets / size)."			\
		);										_XENUM5_NWLN \
		BOOST_PP_REPEAT									\
		(										\
			BOOST_PP_SEQ_SIZE(_XENUM5_XDCL_PDEFS(XDCL)),				\
			_XENUM5_PROP_CHECK,							\
			CTXT									\
		)										\
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


#endif // _XENUM5_IMPL_DEFINE_STORE_HPP
