/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM4_IMPL_DECLARE_VALUE_HPP
#define _XENUM4_IMPL_DECLARE_VALUE_HPP


// ==============================================================================================
/**
 * Declare the enum-value class.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_VALUE(CTXT, DECL)							\
	BOOST_PP_CAT(										\
		_XENUM4_DECLARE_VALUE_,								\
		_XENUM4_DECL_HAS_PROPS(DECL)							\
	) (CTXT, DECL)
/*
_DECLARE_VALUE_DO: ctxt=CTXT decl=DECL has-props=BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM4_DECL_GET_PROPDEFS(DECL))) _XENUM4_NWLN \
*/

// ==============================================================================================
/**
 * Declare the enum-value class as a simple typedef of the template class.
 * For enums that do not have custom properties.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_VALUE_0(CTXT, DECL)							\
	_XENUM4_DOC(Enum-value class type.							_XENUM4_NWLN \
		Thin wrapper around a native enum value.					_XENUM4_NWLN \
		Can never have an invalid value.)						\
	typedef ::_XENUM4_NS::XenumValue<_XENUM4_STORE_NAME(DECL)>				\
		_XENUM4_DECL_GET_VALUENAME(DECL);						_XENUM4_NWLN


// ==============================================================================================
/**
 * Declare the enum-value class as a subclass of the template class.
 * For enums that have custom properties.
 * Adds getters for the custom properties.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_VALUE_1(CTXT, DECL)							\
_XENUM4_DOC(Enum-value class.									_XENUM4_NWLN \
	Thin wrapper around a native enum value.						_XENUM4_NWLN \
	Can never have an invalid value.)							\
class _XENUM4_DECL_GET_VALUENAME(DECL)								\
	: public ::_XENUM4_NS::XenumValue<_XENUM4_STORE_NAME(DECL)> {				_XENUM4_NWLN \
	_XENUM4_INDENT_INC									\
	_XENUM4_DECLARE_VALUE_SUBCLASS_CTORS(_XENUM4_DECL_GET_VALUENAME(DECL))			\
	_XENUM4_PROPS_DECLV(CTXT)								\
	_XENUM4_INDENT_DEC									\
};												_XENUM4_NWLN \

/**
 * Worker for _XENUM4_DECLARE_VALUE_1().
 * Creates ctors; we need to copy all the ctors of the base class.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_VALUE_SUBCLASS_CTORS(VALUENAME)						\
_XENUM4_INDENT_SUB										\
public:												_XENUM4_NWLN \
	_XENUM4_DOC(@copydoc _XENUM4_NS::XenumValue::XenumValue(void) noexcept)			\
	constexpr VALUENAME(void) noexcept {}							_XENUM4_NWLN \
	_XENUM4_DOC(@copydoc _XENUM4_NS::XenumValue::XenumValue(Enum value) noexcept)		\
	constexpr VALUENAME(Enum value) noexcept : XenumValue(value) {}				_XENUM4_NWLN \
	_XENUM4_DOC(@copydoc _XENUM4_NS::XenumValue::XenumValue(const XenumValue& other) noexcept)	\
	constexpr VALUENAME(const VALUENAME& other) noexcept : XenumValue(other) {}		_XENUM4_NWLN \


#endif // _XENUM4_IMPL_DECLARE_VALUE_HPP
