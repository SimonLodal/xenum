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


// ==============================================================================================
/**
 * @return Name of the store class.
 * @hideinitializer
 */
#define _XENUM4_STORE_NAME(DECL)								\
	BOOST_PP_CAT(_Xenum_, _XENUM4_DECL_GET_CNTNRNAME(DECL))


// ==============================================================================================
/**
 * Main entry function.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_STORE(CTXT, DECL)							\
	class _XENUM4_DECL_GET_CNTNRNAME(DECL);							NWLN \
	class _XENUM4_STORE_NAME(DECL) {							NWLN \
	friend class _XENUM4_DECL_GET_CNTNRNAME(DECL);						NWLN \
	private:										NWLN \
		_XENUM4_DECLS_ENUM(CTXT, DECL)							\
		_XENUM4_DECLS_IDENTPOOL(CTXT)							\
		_XENUM4_DECLS_VALUE_ACCESSORS(CTXT, DECL)					\
		_XENUM4_DECLS_LOOKUP_FUNCS(CTXT, DECL)						\
	};											NWLN


/* FIXME: Move from Cntnr:
	public:											NWLN \
		/ * The enum-value class. Not used here, but useful for XenumSet and others. * /	\
IND1		typedef ::_XENUM4_NS::XenumValue<_XENUM4_DECL_GET_CNTNRNAME(DECL)> value_t;	NWLN \

*/


// ==============================================================================================
/**
 * Declare the native C++ enum and associated stuff.
 * @hideinitializer
 */
#define _XENUM4_DECLS_ENUM(CTXT, DECL)								\
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


// ==============================================================================================
/**
 * Declare identifier stringpool.
 * @hideinitializer
 */
// FIXME: Make it look more like custom-prop cstring.
#define _XENUM4_DECLS_IDENTPOOL(CTXT)								\
	/* Identifier stringpool type. */							\
IND1	typedef struct {									NWLN \
		_XENUM4_CALL_VALS(_XENUM4_DECLS_IDENTPOOL_MEMBER, CTXT)				\
IND1	} _IdentPool;										NWLN \
	/* Identifier stringpool data. */							\
IND1	static const _IdentPool _identPool;							NWLN \
	/* Integer type big enough to hold offsets into the string pool. */			\
IND1	typedef ::_XENUM4_NS::SelectInt<sizeof(_IdentPool)>::type _IdentOffset;			NWLN \
	/* Table of offsets into the identifier stringpool. */					\
IND1	static const _IdentOffset _identOffsets[_size];						NWLN \
	/* @return Offset into identifier stringpool for this enum-value. */			\
IND1	static constexpr const _IdentOffset* _getIdentOffset(_Enum value) noexcept		\
		{ return &_identOffsets[static_cast<_index_t>(value)]; }			NWLN

/**
 * Callback worker for _XENUM4_DECLS_IDENTPOOL().
 * @hideinitializer
 */
#define _XENUM4_DECLS_IDENTPOOL_MEMBER(CTXT, IDENT, ...)					\
IND2	char IDENT[sizeof(#IDENT)];								NWLN


// ==============================================================================================
/**
 * Declare functions to access value properties.
 * @hideinitializer
 */
#define _XENUM4_DECLS_VALUE_ACCESSORS(CTXT, DECL)						\
	/* @return Index of an enum value. */							\
IND1	static constexpr _index_t _getIndex(_Enum value) noexcept				\
		{ return static_cast<_index_t>(value); }					NWLN \
	/* @return Identifier of an enum value. */						\
IND1	static constexpr const char* _getIdentifier(_Enum value) noexcept			\
		{ return &((const char*)&_identPool)[*_getIdentOffset(value)]; }		NWLN \


// ==============================================================================================
/**
 * Declare functions to look up values.
 * @hideinitializer
 */
#define _XENUM4_DECLS_LOOKUP_FUNCS(CTXT, DECL)							\
	/* Get enum value with given index. */							\
	/* @param index Enum-value index to retrieve. */					\
	/* @return Requested enum value. */							\
	/* @throws std::out_of_range if index >= number of enum values. */			\
IND1	static _Enum _fromIndex(_index_t index);						NWLN \
	/* Get enum value with given index, without throwing on error. */			\
	/* @param index Enum-value index to retrieve. */					\
	/* @param value Return value; is set to the requested */				\
	/*	enum value, if it exists, else it is not touched. */				\
	/* @return True if enum-value with given index was found, */				\
	/*	else false. */									\
IND1	static bool _fromIndex(_index_t index, _Enum& value) noexcept;				NWLN \
	/* Get enum value with given identifier. */						\
	/* @param ident Identifier to look up. */						\
	/* @return Requested enum value. */							\
	/* @throws std::out_of_range if no such identifier exists. */				\
IND1	static _Enum _fromIdent(const char* identifier);					NWLN \
	/* Get enum value with given identifier. */						\
	/* Does not throw when not found. */							\
	/* @param ident Identifier to look up. */						\
	/* @param value Return value; is set to the requested enum */				\
	/*	value if it exists, else it is not touched. */					\
	/* @return True if enum-value with given identifier was found, else false. */		\
IND1	static bool _fromIdent(const char* identifier, _Enum& value) noexcept;			NWLN \



#endif // _XENUM4_IMPL_DECLARE_STORE_HPP
