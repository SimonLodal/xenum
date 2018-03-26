/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Declaration of the internal store class.
 */
#ifndef _XENUM4_IMPL_DECLARE_STORE_HPP
#define _XENUM4_IMPL_DECLARE_STORE_HPP


/**
 * @return Name of the store class.
 * @hideinitializer
 */
#define _XENUM4_STORE_NAME(CTXT)								\
	BOOST_PP_CAT(_Xenum_, _XENUM4_DECL_GET_CNTNRNAME(_XENUM4_CTXT_GET_DECL(CTXT)))


// ==============================================================================================
/**
 * Main entry function.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_STORE(CTXT)								\
	class _XENUM4_STORE_NAME(CTXT) {							NWLN \
		_XENUM4_DECLS_ENUM(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))				\
	};											NWLN


/* FIXME: Move from Cntnr:
	public:											NWLN \
		/ * The enum-value class. Not used here, but useful for XenumSet and others. * /	\
IND1		typedef ::_XENUM4_NS::XenumValue<_XENUM4_DECL_GET_CNTNRNAME(DECL)> value_t;	NWLN \

*/


// ==============================================================================================
/**
 * Declare the native C++ enum.
 * @hideinitializer
 */
#define _XENUM4_DECLS_ENUM(CTXT, DECL)								\
public:												NWLN \
	/* Number of values in this enum class. */						\
IND1	static constexpr const size_t _size = 0 _XENUM4_CALL_VALS(_XENUM4_ADD_ONE, CTXT);	NWLN \
	/* Integer type used for enum values. */						\
IND1	typedef BOOST_PP_IF(									\
		BOOST_PP_IS_EMPTY(_XENUM4_DECL_GET_INTTYPE(DECL)),				\
		::_XENUM4_NS::SelectInt<_size>::type,						\
		_XENUM4_DECL_GET_INTTYPE(DECL)							\
	) _index_t;										NWLN \
IND1	enum class _Enum : _index_t {								NWLN \
		_XENUM4_CALL_VALS(_XENUM4_DECLS_ENUM_MEMBER, CTXT)				\
IND1	};											NWLN

/**
 * Callback worker for _XENUM4_DECLARE_CNTNR_ENUM().
 * @hideinitializer
 */
#define _XENUM4_DECLS_ENUM_MEMBER(CTXT, VALUEIDENT, ...)					\
IND2		VALUEIDENT,									NWLN










#endif // _XENUM4_IMPL_DECLARE_STORE_HPP
