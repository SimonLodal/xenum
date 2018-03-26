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
#define _XENUM4_DECLARE_VALUE(CTXT)								\
	_XENUM4_DECLARE_VALUE_DO(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))

/**
 * Worker for _XENUM4_DECLARE_VALUE().
 * @hideinitializer
 */
#define _XENUM4_DECLARE_VALUE_DO(CTXT, DECL)							\
	BOOST_PP_CAT(										\
		_XENUM4_DECLARE_VALUE_,								\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM4_DECL_GET_PROPDEFS(DECL)))		\
	) (CTXT, DECL)
/*
_DECLARE_VALUE_DO: ctxt=CTXT decl=DECL has-props=BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM4_DECL_GET_PROPDEFS(DECL))) NWLN \
*/

// ==============================================================================================
/**
 * Declare the enum-value class as a simple typedef of the template class.
 * For enums that do not have custom properties.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_VALUE_0(CTXT, DECL)							\
	typedef ::_XENUM4_NS::XenumValue<_XENUM4_DECL_GET_CNTNRNAME(DECL)>			\
		_XENUM4_DECL_GET_VALUENAME(DECL);


// ==============================================================================================
/**
 * Declare the enum-value class as a subclass of the template class.
 * For enums that have custom properties.
 * Adds getters for the custom properties.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_VALUE_1(CTXT, DECL)							\
class _XENUM4_DECL_GET_VALUENAME(DECL)								\
	: public ::_XENUM4_NS::XenumValue<_XENUM4_DECL_GET_CNTNRNAME(DECL)> {			NWLN \
	_XENUM4_DECLARE_VALUE_SUBCLASS_CTORS(_XENUM4_DECL_GET_VALUENAME(DECL))			\
public:												NWLN \
	_XENUM4_PROPS_DECLV(CTXT)								\
};												\
NWLN

/**
 * Worker for _XENUM4_DECLARE_VALUE_1().
 * Creates ctors; we need to copy all the ctors of the base class.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_VALUE_SUBCLASS_CTORS(VALUENAME)						\
public:												NWLN \
IND1	constexpr VALUENAME(void) noexcept {}							NWLN \
IND1	constexpr VALUENAME(Enum value) noexcept : XenumValue(value) {}				NWLN \
IND1	constexpr VALUENAME(const VALUENAME& other) noexcept : XenumValue(other) {}		NWLN \




#endif // _XENUM4_IMPL_DECLARE_VALUE_HPP
