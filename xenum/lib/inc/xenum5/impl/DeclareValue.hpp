/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM5_IMPL_DECLARE_VALUE_HPP
#define _XENUM5_IMPL_DECLARE_VALUE_HPP


// ==============================================================================================
/**
 * Declare the enum-value class.
 */
#define _XENUM5_DECLARE_VALUE(CTXT, DECL)							\
	BOOST_PP_CAT(										\
		_XENUM5_DECLARE_VALUE_,								\
		_XENUM5_DECL_HAS_PROPS(DECL)							\
	) (CTXT, DECL)
/*
_DECLARE_VALUE_DO: ctxt=CTXT decl=DECL has-props=BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM5_DECL_GET_PDEFS(DECL))) _XENUM5_NWLN \
*/

// ==============================================================================================
/**
 * Declare the enum-value class as a simple typedef of the template class.
 * For enums that do not have custom properties.
 */
#define _XENUM5_DECLARE_VALUE_0(CTXT, DECL)							\
	_XENUM5_DOC(Enum-value class type.							_XENUM5_NWLN \
		Thin wrapper around a native enum value.					_XENUM5_NWLN \
		Can never have an invalid value.)						\
	typedef ::_XENUM5_NS::XenumValue<_XENUM5_STORE_NAME(DECL)>				\
		_XENUM5_DECL_GET_VALUENAME(DECL);						_XENUM5_NWLN


// ==============================================================================================
/**
 * Declare the enum-value class as a subclass of the template class.
 * For enums that have custom properties.
 * Adds getters for the custom properties.
 */
#define _XENUM5_DECLARE_VALUE_1(CTXT, DECL)							\
_XENUM5_DOC(Enum-value class for xenum _XENUM5_DECL_GET_CNTNRNAME(DECL).			_XENUM5_NWLN \
	Thin wrapper around a native enum value.						_XENUM5_NWLN \
	Can never have an invalid value.)							\
class _XENUM5_DECL_GET_VALUENAME(DECL)								\
	: public ::_XENUM5_NS::XenumValue<_XENUM5_STORE_NAME(DECL)> {				_XENUM5_NWLN \
	_XENUM5_INDENT_INC									\
	_XENUM5_DECLARE_VALUE_SUBCLASS_CTORS(_XENUM5_DECL_GET_VALUENAME(DECL))			\
	_XENUM5_PROPS_DECLV(CTXT)								\
	_XENUM5_INDENT_DEC									\
};												_XENUM5_NWLN \

/**
 * Worker for _XENUM5_DECLARE_VALUE_1().
 * Creates ctors; we need to copy all the ctors of the base class.
 */
#define _XENUM5_DECLARE_VALUE_SUBCLASS_CTORS(VALUENAME)						\
_XENUM5_INDENT_SUB										\
public:												_XENUM5_NWLN \
	_XENUM5_DOC(@copydoc _XENUM5_NS::XenumValue::XenumValue(void))				\
	constexpr VALUENAME(void) noexcept {}							_XENUM5_NWLN \
	_XENUM5_DOC(@copydoc _XENUM5_NS::XenumValue::XenumValue(Enum value))			\
	constexpr VALUENAME(Enum value) noexcept : XenumValue(value) {}				_XENUM5_NWLN \
	_XENUM5_DOC(@copydoc _XENUM5_NS::XenumValue::XenumValue(const XenumValue& other))	\
	constexpr VALUENAME(const VALUENAME& other) noexcept : XenumValue(other) {}		_XENUM5_NWLN \


#endif // _XENUM5_IMPL_DECLARE_VALUE_HPP
