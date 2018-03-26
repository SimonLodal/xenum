/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM4_IMPL_DECLARE_CNTNR_HPP
#define _XENUM4_IMPL_DECLARE_CNTNR_HPP


// ==============================================================================================
/**
 * Begin declaration of the enum-container class.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_BEGIN(CTXT)							\
	_XENUM4_DECLARE_CNTNR_BEGIN_DO(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))

/**
 * Callback worker for _XENUM4_DECLARE_CNTNR_BEGIN().
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_BEGIN_DO(CTXT, DECL)						\
	/* Enum-container class. */								\
	class _XENUM4_DECL_GET_CNTNRNAME(DECL) {						NWLN \
	public:											NWLN \
		/* The enum-value class. Not used here, but useful for XenumSet and others. */	\
IND1		typedef ::_XENUM4_NS::XenumValue<_XENUM4_DECL_GET_CNTNRNAME(DECL)> value_t;	NWLN \
		/* Number of values in this enum class. */					\
IND1		static constexpr const size_t size = 0 _XENUM4_CALL_VALS(_XENUM4_ADD_ONE, CTXT);	NWLN \
		/* Integer type used for enum values. */					\
IND1		typedef BOOST_PP_IF(								\
			BOOST_PP_IS_EMPTY(_XENUM4_DECL_GET_INTTYPE(DECL)),			\
			::_XENUM4_NS::SelectInt<size>::type,					\
			_XENUM4_DECL_GET_INTTYPE(DECL)						\
		) index_t;									NWLN \


// ==============================================================================================
/**
 * Declare the native C++ enum.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_ENUM_NATIVE(CTXT)							\
	public:											NWLN \
IND1		enum class Enum : index_t {							NWLN \
			_XENUM4_CALL_VALS(_XENUM4_DECLARE_CNTNR_ENUM_NATIVE_MEMBER, CTXT)	\
IND1		};										NWLN

/**
 * Callback worker for _XENUM4_DECLARE_CNTNR_ENUM().
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_ENUM_NATIVE_MEMBER(CTXT, VALUEIDENT, ...)				\
IND2		VALUEIDENT,									NWLN


// ==============================================================================================
/**
 * Declare the static enum-value copies.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_ENUM_COPY(CTXT)							\
	_XENUM4_CALL_VALS(_XENUM4_DECLARE_CNTNR_ENUM_COPY_MEMBER, CTXT)
/**
 * Callback worker for _XENUM4_DECLARE_CNTNR_ENUM_COPY().
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_ENUM_COPY_MEMBER(CTXT, VALUEIDENT, ...)				\
IND1		static constexpr const Enum VALUEIDENT = Enum::VALUEIDENT;			NWLN


// ==============================================================================================
/**
 * Define identifier stringpool type, and declare the pool.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_IDENTPOOL(CTXT)							\
	protected:										NWLN \
		/* Identifier stringpool type. */						\
IND1		typedef struct {								NWLN \
			_XENUM4_CALL_VALS(_XENUM4_DECLARE_CNTNR_IDENTPOOL_MEMBER, CTXT)		\
IND1		} IdentifierPool;								NWLN \
		/* Identifier stringpool data. */						\
IND1		static const IdentifierPool identifierPool;					NWLN \
		/* Integer type big enough to hold offsets into the string pool. */		\
IND1		typedef ::_XENUM4_NS::SelectInt<sizeof(IdentifierPool)>::type IdentifierOffset;	NWLN \
		/* Table of offsets into the identifier stringpool. */				\
IND1		static const IdentifierOffset identifierOffsets[size];				NWLN \
		/* @return Offset into identifier stringpool for this enum-value. */		\
IND1		static constexpr const IdentifierOffset* getIdentifierOffset(Enum value) noexcept { return &identifierOffsets[static_cast<index_t>(value)]; } NWLN

/**
 * Callback worker for _XENUM4_DECLARE_CNTNR_IDENTPOOL().
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_IDENTPOOL_MEMBER(CTXT, VALUEIDENT, ...)				\
IND2	char VALUEIDENT[sizeof(#VALUEIDENT)];							NWLN


// ==============================================================================================
/**
 * Declare ctors, comparison operators, other stuff.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_FUNCS(CTXT)							\
	_XENUM4_DECLARE_CNTNR_FUNCS_DO(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))

/**
 * Callback worker for _XENUM4_DECLARE_CNTNR_FUNCS().
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_FUNCS_DO(CTXT, DECL)						\
	public:											NWLN \
		/* @return Index of an enum value. */						\
IND1		static constexpr index_t getIndex(Enum value) noexcept				\
			{ return static_cast<index_t>(value); }					NWLN \
		/* @return Identifier of an enum value. */					\
IND1		static constexpr const char* getIdentifier(Enum value) noexcept			\
			{ return &((const char*)&identifierPool)[*getIdentifierOffset(value)]; } NWLN \
	public:											NWLN \
		/* Ctor. Do not use, except when iterating the enum-values. */			\
		/* All members of this class are static, so there is no */			\
		/* need to instantiate an object; just address the members */			\
		/* directly as $EnumCntnr::Some_Value. */					\
		/* However, range-based loops require an object, so use: */			\
		/* for (EnumValue enumValue : EnumCntnr()) { ... } */				\
IND1		constexpr _XENUM4_DECL_GET_CNTNRNAME(DECL)(void) noexcept {}			NWLN \
		/* Get enum value with given index. */						\
		/* @param index Enum-value index to retrieve. */				\
		/* @return Requested enum value. */						\
		/* @throws std::out_of_range if index >= number of enum values. */		\
IND1		static Enum fromIndex(index_t index);						NWLN \
		/* Get enum value with given index, without throwing on error. */		\
		/* @param index Enum-value index to retrieve. */				\
		/* @param value Return value; is set to the requested */			\
		/*	enum value, if it exists, else it is not touched. */			\
		/* @return True if enum-value with given index was found, */			\
		/*	else false. */								\
IND1		static bool fromIndex(index_t index, Enum& value) noexcept;			NWLN \
		/* Get enum value with given identifier. */					\
		/* @param ident Identifier to look up. */					\
		/* @return Requested enum value. */						\
		/* @throws std::out_of_range if no such identifier exists. */			\
IND1		static Enum fromIdentifier(const char* identifier);				NWLN \
		/* Get enum value with given identifier. */					\
		/* Does not throw when not found. */						\
		/* @param ident Identifier to look up. */					\
		/* @param value Return value; is set to the requested enum */			\
		/*	value if it exists, else it is not touched. */				\
		/* @return True if enum-value with given identifier was found, else false. */	\
IND1		static bool fromIdentifier(const char* identifier, Enum& value) noexcept;	NWLN \
	/* Iteration support. */								\
	public:											NWLN \
		/* Iterator type for this container. */						\
IND1		typedef ::_XENUM4_NS::XenumCntnrIterator<_XENUM4_DECL_GET_CNTNRNAME(DECL)> iterator; NWLN \
		/* Get iterator to beginning (before the first enum-value). */			\
IND1		static iterator begin(void) noexcept { return iterator(0); }			NWLN \
		/* Get iterator to end (past the last enum-value). */				\
IND1		static iterator end(void) noexcept { return iterator(size); }			NWLN


// ==============================================================================================
/**
 * End declaration of enum-container class.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_CNTNR_END								NWLN \
	};											NWLN


#endif // _XENUM4_IMPL_DECLARE_CNTNR_HPP
