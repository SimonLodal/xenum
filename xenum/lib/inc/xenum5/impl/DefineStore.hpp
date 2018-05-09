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
	_XENUM5_DEFS_SIZE(XDCL)									\
	BOOST_PP_CAT(										\
		BOOST_PP_CAT(_XENUM5_IDENT_, _XENUM5_XDCL_PLACEMENT_STR(XDCL)),			\
		_DEFINE										\
	) (XDCL, CTXT)										\
	_XENUM5_PROPS_DEFINE(CTXT, XDCL)							\
	_XENUM5_DEFS_CHECK(									\
		_XENUM5_XDCL_DSCOPE(XDCL),							\
		_XENUM5_STORE_NAME(XDCL),							\
		XDCL,										\
		CTXT										\
	)											\
	BOOST_PP_CAT(_XENUM5_DEFS_DBGINFO_, _XENUM5_DEBUG_STORE) (				\
		_XENUM5_IMPL_LOCAL_NS(XDCL, )::,						\
		_XENUM5_XDCL_DSCOPE(XDCL),							\
		_XENUM5_STORE_NAME(XDCL),							\
		XDCL,										\
		CTXT										\
	)											\


// ==============================================================================================
/**
 * Define the .size var.
 */
// FIXME: Is it really necessary to define this at all?
#define _XENUM5_DEFS_SIZE(XDCL)									\
	constexpr const size_t _XENUM5_XDCL_DSCOPE(XDCL) _XENUM5_STORE_NAME(XDCL) ::size;	_XENUM5_NWLN


// ==============================================================================================
/**
 * Define static_assert() checks on generated data structures.
 */
#define _XENUM5_DEFS_CHECK(DSCOPE, SNAME, XDCL, CTXT)						\
	_XENUM5_NWLN _XENUM5_CMNT(Store:Check)							\
	void DSCOPE SNAME::_check(void)								\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		BOOST_PP_CAT(									\
			BOOST_PP_CAT(_XENUM5_IDENT_, _XENUM5_XDCL_PLACEMENT_STR(XDCL)),		\
			_CHECK									\
		) (										\
			_XENUM5_IMPL_LOCAL_NS(XDCL, )::,					\
			DSCOPE,									\
			SNAME									\
		)										\
		BOOST_PP_REPEAT									\
		(										\
			BOOST_PP_SEQ_SIZE(_XENUM5_XDCL_PDEFS(XDCL)),				\
			_XENUM5_PROP_CHECK,							\
			CTXT									\
		)										\
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


// ==============================================================================================
/**
 * Do not define a debugging info function.
 */
#define _XENUM5_DEFS_DBGINFO_0(LSCOPE, DSCOPE, SNAME, XDCL, CTXT)				\

/**
 * Define a debugging info function.
 */
#define _XENUM5_DEFS_DBGINFO_1(LSCOPE, DSCOPE, SNAME, XDCL, CTXT)				\
	_XENUM5_NWLN _XENUM5_CMNT(Store:Debug)							\
	void DSCOPE SNAME::_dbginfo(void)							\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		std::cout									\
			<<BOOST_PP_STRINGIZE(_XENUM5_STORE_NAME(XDCL))<<"::_dbginfo:"<<std::endl	\
			<<"\tsizeof(identValues) = "<<sizeof(LSCOPE identValues)<<std::endl	\
			<<"\tsizeof(IdentValueNames) = "<<sizeof(LSCOPE IdentValueNames)<<std::endl	\
			;									\
		BOOST_PP_REPEAT									\
		(										\
			BOOST_PP_SEQ_SIZE(_XENUM5_XDCL_PDEFS(XDCL)),				\
			_XENUM5_PROP_DBGINFO,							\
			CTXT									\
		)										\
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


#endif // _XENUM5_IMPL_DEFINE_STORE_HPP
