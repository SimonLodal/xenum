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
	BOOST_PP_CAT(_XenumStore_, _XENUM4_DECL_GET_CNTNRNAME(DECL))


// ==============================================================================================
/**
 * Main entry function.
 * @hideinitializer
 */
#define _XENUM4_DECLARE_STORE(CTXT, DECL)							\
	BOOST_PP_EXPR_IF(									\
		_XENUM4_DECL_HAS_PROPS(DECL),							\
		class _XENUM4_DECL_GET_VALUENAME(DECL);						NWLN \
	)											\
	class _XENUM4_CNTNR_NAME(DECL);								NWLN \
	class _XENUM4_STORE_NAME(DECL) {							NWLN \
IND1	friend class ::_XENUM4_NS::XenumValue<_XENUM4_STORE_NAME(DECL)>;			NWLN \
	BOOST_PP_EXPR_IF(									\
		_XENUM4_DECL_HAS_PROPS(DECL),							\
IND1		friend class _XENUM4_DECL_GET_VALUENAME(DECL);					NWLN \
	)											\
IND1	friend class _XENUM4_CNTNR_NAME(DECL);							NWLN \
private: /* Everything in this class should be private, only accessed by friends. */		NWLN \
		_XENUM4_DECLS_ENUM(CTXT, DECL)							\
		_XENUM4_DECLS_FUNCS(CTXT, DECL)							\
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
	) Index;										NWLN \
IND1	enum class Enum : Index {								NWLN \
		_XENUM4_CALL_VALS(_XENUM4_DECLS_ENUM_MEMBER, CTXT)				\
IND1	};											NWLN \
	/* @return Index of an enum value. */							\
IND1	static constexpr Index getIndex(Enum value) noexcept					\
		{ return static_cast<Index>(value); }						NWLN \

/**
 * Callback worker for _XENUM4_DECLARE_CNTNR_ENUM().
 * @hideinitializer
 */
#define _XENUM4_DECLS_ENUM_MEMBER(CTXT, VALUEIDENT, ...)					\
IND2		VALUEIDENT,									NWLN


// ==============================================================================================
/**
 * Declare accessor and lookup functions.
 * @hideinitializer
 */
#define _XENUM4_DECLS_FUNCS(CTXT, DECL)								\
	/* @return Identifier of an enum value. */						\
IND1	static const char* getIdentifier(Enum value) noexcept;					NWLN \
	/* Get enum value with given index. */							\
	/* @param index Enum-value index to retrieve. */					\
	/* @return Requested enum value. */							\
	/* @throws std::out_of_range if index >= number of enum values. */			\
IND1	static Enum fromIndex(Index index);							NWLN \
	/* Get enum value with given index, without throwing on error. */			\
	/* @param index Enum-value index to retrieve. */					\
	/* @param value Return value; is set to the requested */				\
	/*	enum value, if it exists, else it is not touched. */				\
	/* @return True if enum-value with given index was found, */				\
	/*	else false. */									\
IND1	static bool fromIndex(Index index,							\
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
