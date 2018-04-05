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
/* FIXME: Make everything private. */								\
public:												NWLN \
		_XENUM4_DECLS_ENUM(CTXT, DECL)							\
		_XENUM4_DECLS_IDENTPOOL(CTXT)							\
		_XENUM4_DECLS_VALUE_ACCESSORS(CTXT, DECL)					\
		_XENUM4_DECLS_LOOKUP_FUNCS(CTXT, DECL)						\
		_XENUM4_PROPS_DECLS(CTXT)							\
	};											NWLN


// ==============================================================================================
/**
 * Declare the native C++ enum and associated stuff.
 * @hideinitializer
 */
#define _XENUM4_DECLS_ENUM(CTXT, DECL)								\
	/* Number of values in this enum class. */						\
IND1	static constexpr const size_t size = 0 _XENUM4_CALL_VALS(_XENUM4_ADD_ONE, CTXT);	NWLN \
	/* Integer type used for enum values. */						\
IND1	typedef BOOST_PP_IF(									\
		BOOST_PP_IS_EMPTY(_XENUM4_DECL_GET_INTTYPE(DECL)),				\
		::_XENUM4_NS::SelectInt<size>::type,						\
		_XENUM4_DECL_GET_INTTYPE(DECL)							\
	) index_t;										NWLN \
IND1	enum class Enum : index_t {								NWLN \
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
IND1	} IdentPool;										NWLN \
	/* Identifier stringpool data. */							\
IND1	static const IdentPool identPool;							NWLN \
	/* Integer type big enough to hold offsets into the string pool. */			\
IND1	typedef ::_XENUM4_NS::SelectInt<sizeof(IdentPool)>::type IdentOffset;			NWLN \
	/* Table of offsets into the identifier stringpool. */					\
IND1	static const IdentOffset identOffsets[size];						NWLN \
	/* @return Offset into identifier stringpool for this enum-value. */			\
IND1	static constexpr const IdentOffset* getIdentOffset(Enum value) noexcept			\
		{ return &identOffsets[static_cast<index_t>(value)]; }				NWLN

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
IND1	static constexpr index_t getIndex(Enum value) noexcept					\
		{ return static_cast<index_t>(value); }						NWLN \
	/* @return Identifier of an enum value. */						\
IND1	static constexpr const char* getIdentifier(Enum value) noexcept				\
		{ return &((const char*)&identPool)[*getIdentOffset(value)]; }			NWLN \


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
IND1	static Enum fromIndex(index_t index);							NWLN \
	/* Get enum value with given index, without throwing on error. */			\
	/* @param index Enum-value index to retrieve. */					\
	/* @param value Return value; is set to the requested */				\
	/*	enum value, if it exists, else it is not touched. */				\
	/* @return True if enum-value with given index was found, */				\
	/*	else false. */									\
IND1	static bool fromIndex(index_t index,							\
			::_XENUM4_NS::XenumValue<_XENUM4_STORE_NAME(DECL)>& value) noexcept;	NWLN \
	/* Get enum value with given identifier. */						\
	/* @param ident Identifier to look up. */						\
	/* @return Requested enum value. */							\
	/* @throws std::out_of_range if no such identifier exists. */				\
IND1	static Enum fromIdent(const char* identifier);						NWLN \
	/* Get enum value with given identifier. */						\
	/* Does not throw when not found. */							\
	/* @param ident Identifier to look up. */						\
	/* @param value Return value; is set to the requested enum */				\
	/*	value if it exists, else it is not touched. */					\
	/* @return True if enum-value with given identifier was found, else false. */		\
IND1	static bool fromIdent(const char* identifier,						\
			::_XENUM4_NS::XenumValue<_XENUM4_STORE_NAME(DECL)>& value) noexcept;	NWLN \



#endif // _XENUM4_IMPL_DECLARE_STORE_HPP
