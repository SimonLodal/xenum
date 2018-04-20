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
		class _XENUM4_DECL_GET_VALUENAME(DECL);						_XENUM4_NWLN \
	)											\
	class _XENUM4_CNTNR_NAME(DECL);								_XENUM4_NWLN \
	_XENUM4_DOC(Internal/private class for data storage.					_XENUM4_NWLN \
		Only accessed by friends (value and container classes).)			\
	class _XENUM4_STORE_NAME(DECL) {							_XENUM4_NWLN \
	private:										_XENUM4_NWLN \
		_XENUM4_INDENT_INC								\
		friend class ::_XENUM4_NS::XenumValue<_XENUM4_STORE_NAME(DECL)>;		_XENUM4_NWLN \
		BOOST_PP_EXPR_IF(								\
			_XENUM4_DECL_HAS_PROPS(DECL),						\
			friend class _XENUM4_DECL_GET_VALUENAME(DECL);				_XENUM4_NWLN \
		)										\
		friend class _XENUM4_CNTNR_NAME(DECL);						_XENUM4_NWLN \
		_XENUM4_DECLS_ENUM(CTXT, DECL)							\
		_XENUM4_DECLS_FUNCS(CTXT, DECL)							\
		_XENUM4_PROPS_DECLS(CTXT)							\
		_XENUM4_DECLS_CHECK()								\
		_XENUM4_INDENT_DEC								\
	};											_XENUM4_NWLN


// ==============================================================================================
/**
 * Declare the native C++ enum and associated stuff.
 * @hideinitializer
 */
#define _XENUM4_DECLS_ENUM(CTXT, DECL)								\
	_XENUM4_DOC(Number of values in this enum class.)					\
	static constexpr const size_t size = 0 _XENUM4_CALL_VALS(_XENUM4_ADD_ONE, CTXT);	_XENUM4_NWLN \
	_XENUM4_DOC(Integer type used for enum values.)						\
	typedef BOOST_PP_IF(									\
		BOOST_PP_IS_EMPTY(_XENUM4_DECL_GET_INTTYPE(DECL)),				\
		::_XENUM4_NS::SelectInt<size>::type,						\
		_XENUM4_DECL_GET_INTTYPE(DECL)							\
	) Index;										_XENUM4_NWLN \
	_XENUM4_DOC(The native enum class.)							\
	enum class Enum : Index {								_XENUM4_NWLN \
		_XENUM4_CALL_VALS(_XENUM4_DECLS_ENUM_MEMBER, CTXT)				\
	};											_XENUM4_NWLN \
	_XENUM4_DOC(@return The index of an enum value (zero-based, consecutive).)		\
	static constexpr Index getIndex(Enum value) noexcept					\
		{ return static_cast<Index>(value); }						_XENUM4_NWLN \

/**
 * Callback worker for _XENUM4_DECLARE_CNTNR_ENUM().
 * @hideinitializer
 */
#define _XENUM4_DECLS_ENUM_MEMBER(CTXT, VALUEIDENT, ...)					\
	_XENUM4_INDENT_ADD VALUEIDENT,								_XENUM4_NWLN


// ==============================================================================================
/**
 * Declare accessor and lookup functions.
 * @hideinitializer
 */
#define _XENUM4_DECLS_FUNCS(CTXT, DECL)								\
	_XENUM4_DOC(@return Identifier (name) of an enum value.)				\
	static const char* getIdentifier(Enum value) noexcept;					_XENUM4_NWLN \
	_XENUM4_DOC(Get enum value with given index.						_XENUM4_NWLN \
		@param index Enum-value index to retrieve.					_XENUM4_NWLN \
		@return Requested enum value.							_XENUM4_NWLN \
		@throws std::out_of_range if index >= number of enum values.)			\
	static Enum fromIndex(Index index);							_XENUM4_NWLN \
	_XENUM4_DOC(Get enum value with given index, without throwing on error.			_XENUM4_NWLN \
		@param index Enum-value index to retrieve.					_XENUM4_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM4_NWLN \
			_XENUM4_INDENT_ADD							\
			if it exists, else it is not touched.					\
		@return True if enum-value with given index was found, else false.)		\
	static bool fromIndex(Index index,							\
		::_XENUM4_NS::XenumValue<_XENUM4_STORE_NAME(DECL)>& value) noexcept;		_XENUM4_NWLN \
	_XENUM4_DOC(Get enum value with given identifier (name).				_XENUM4_NWLN \
		@param ident Identifier to look up.						_XENUM4_NWLN \
		@return Requested enum value.							_XENUM4_NWLN \
		@throws std::out_of_range if no such identifier exists.)			\
	static Enum fromIdent(const char* identifier);						_XENUM4_NWLN \
	_XENUM4_DOC(Get enum value with given identifier (name), without throwing on error.	_XENUM4_NWLN \
		@param ident Identifier to look up.						_XENUM4_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM4_NWLN \
			_XENUM4_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM4_NWLN \
		@return True if enum-value with given identifier was found, else false.)	\
	static bool fromIdent(const char* identifier,						\
		::_XENUM4_NS::XenumValue<_XENUM4_STORE_NAME(DECL)>& value) noexcept;		_XENUM4_NWLN \

			
// ==============================================================================================
/**
 * Declare function for static_assert() checks on generated data structures.
 * The function is never supposed to be called. It should only contain static_assert()'s, which
 * are evaluated only by the compiler. The static_assert's can technically be placed anywhere,
 * but they need access to the store class' private members, so needs to be part of it.
 * @hideinitializer
 */
#define _XENUM4_DECLS_CHECK()									\
	static void _check(void);								_XENUM4_NWLN \


#endif // _XENUM4_IMPL_DECLARE_STORE_HPP
