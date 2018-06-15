/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Inheriting an enum value class from XenumValue.
 */
#ifndef _XENUM5_IMPL_VALUE_HPP
#define _XENUM5_IMPL_VALUE_HPP


// ==============================================================================================
/**
 * @return Fully qualified expression of the base value class.
 */
#define _XENUM5_VEXPR(XDCL)									\
	::_XENUM5_NS::XenumValue<_XENUM5_STORE_NAME(XDCL), _XENUM5_XDCL_IDENT_INT_GET(XDCL)>	\


// ======================================= MAIN: DECLV ==========================================
/**
 * Declare the enum-value class.
 */
#define _XENUM5_DECLARE_VALUE(CTXT, XDCL)							\
	BOOST_PP_CAT(										\
		_XENUM5_DECLV_,									\
		_XENUM5_XDCL_HAS_PROPS(XDCL)							\
	) (CTXT, XDCL)
/*
DECLARE_VALUE: ctxt=CTXT xdcl=XDCL has-props=BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM5_XDCL_PDEFS(XDCL))) _XENUM5_NWLN \
*/

/**
 * Declare the enum-value class as a simple alias of the template class.
 * For enums that do not have custom properties.
 */
#define _XENUM5_DECLV_0(CTXT, XDCL)								\
	_XENUM5_DOC(Enum-value class type.							_XENUM5_NWLN \
		Thin wrapper around a native enum value.					_XENUM5_NWLN \
		Can never have an invalid value.)						\
	using _XENUM5_XDCL_VNAME(XDCL) = _XENUM5_VEXPR(XDCL);					_XENUM5_NWLN \


/**
 * Declare the enum-value class as a subclass of the template class.
 * For enums that have custom properties.
 * Adds getters for the custom properties.
 */
#define _XENUM5_DECLV_1(CTXT, XDCL)								\
_XENUM5_DOC(Enum-value class for xenum _XENUM5_XDCL_CNAME(XDCL).				_XENUM5_NWLN \
	Thin wrapper around a native enum value.						_XENUM5_NWLN \
	Can never have an invalid value.)							\
class _XENUM5_XDCL_VNAME(XDCL)									\
	: public _XENUM5_VEXPR(XDCL) {								_XENUM5_NWLN \
public:												_XENUM5_NWLN \
	_XENUM5_INDENT_INC									\
	_XENUM5_INDENT_SUB _XENUM5_CMNT(Main)							\
	_XENUM5_DECLV_SUBCLASS_CTORS(_XENUM5_XDCL_VNAME(XDCL))					\
	_XENUM5_PROPS_DECLV(CTXT)								\
	_XENUM5_INDENT_DEC									\
};												_XENUM5_NWLN \

/**
 * Worker for _XENUM5_DECLV_1().
 * Creates ctors; we need to copy all the ctors of the base class.
 */
#define _XENUM5_DECLV_SUBCLASS_CTORS(VNAME)							\
	_XENUM5_DOC(@copydoc _XENUM5_NS::XenumValue::XenumValue(void))				\
	constexpr VNAME(void) noexcept {}							_XENUM5_NWLN \
	_XENUM5_DOC(@copydoc _XENUM5_NS::XenumValue::XenumValue(Enum value))			\
	constexpr VNAME(Enum value) noexcept : XenumValue(value) {}				_XENUM5_NWLN \
	_XENUM5_DOC(@copydoc _XENUM5_NS::XenumValue::XenumValue(const XenumValue& other))	\
	constexpr VNAME(const VNAME& other) noexcept : XenumValue(other) {}			_XENUM5_NWLN \


#endif // _XENUM5_IMPL_VALUE_HPP
