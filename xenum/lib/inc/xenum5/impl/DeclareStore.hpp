/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Declaration of the internal store class.
 */
#ifndef _XENUM5_IMPL_DECLARE_STORE_HPP
#define _XENUM5_IMPL_DECLARE_STORE_HPP


// ==============================================================================================
/**
 * @return Name of the store class.
 */
#define _XENUM5_STORE_NAME(DECL)								\
	BOOST_PP_CAT(_xenum5_store_, _XENUM5_DECL_CNTNRNAME(DECL))


// ==============================================================================================
/**
 * Main entry function.
 */
#define _XENUM5_DECLARE_STORE(CTXT, DECL)							\
	BOOST_PP_EXPR_IF(									\
		_XENUM5_DECL_HAS_PROPS(DECL),							\
		class _XENUM5_DECL_VALUENAME(DECL);						_XENUM5_NWLN \
	)											\
	class _XENUM5_CNTNR_NAME(DECL);								_XENUM5_NWLN \
	_XENUM5_DOC(Internal/private class for xenum _XENUM5_DECL_CNTNRNAME(DECL).		_XENUM5_NWLN \
		Contains data and accessors for the enum.					_XENUM5_NWLN \
		Only accessed by friends (value and container classes).)			\
	class _XENUM5_STORE_NAME(DECL) {							_XENUM5_NWLN \
	private:										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_INDENT_SUB _XENUM5_CMNT(Main)						\
		friend class ::_XENUM5_NS::XenumValue<_XENUM5_STORE_NAME(DECL)>;		_XENUM5_NWLN \
		BOOST_PP_EXPR_IF(								\
			_XENUM5_DECL_HAS_PROPS(DECL),						\
			friend class _XENUM5_DECL_VALUENAME(DECL);				_XENUM5_NWLN \
		)										\
		friend class _XENUM5_CNTNR_NAME(DECL);						_XENUM5_NWLN \
		_XENUM5_DECLS_ENUM(CTXT, DECL)							\
		_XENUM5_DECLS_FUNCS(CTXT, DECL)							\
		_XENUM5_PROPS_DECLS(CTXT)							\
		_XENUM5_DECLS_CHECK()								\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN


// ==============================================================================================
/**
 * Declare the native C++ enum and associated stuff.
 */
#define _XENUM5_DECLS_ENUM(CTXT, DECL)								\
	_XENUM5_DOC(Number of enum values in this enum class.)					\
	static constexpr const size_t size = 0 _XENUM5_CALL_VALS(_XENUM5_ADD_ONE, CTXT);	_XENUM5_NWLN \
	_XENUM5_DOC(Integer type used for enum values.)						\
	using Index = BOOST_PP_IF(									\
		BOOST_PP_IS_EMPTY(_XENUM5_DECL_INTTYPE(DECL)),					\
		::_XENUM5_NS::SelectInt<size>::type,						\
		_XENUM5_DECL_INTTYPE(DECL)							\
	);											_XENUM5_NWLN \
	_XENUM5_DOC(The native enum class.)							\
	enum class Enum : Index {								_XENUM5_NWLN \
		_XENUM5_CALL_VALS(_XENUM5_DECLS_ENUM_MEMBER, CTXT)				\
	};											_XENUM5_NWLN \
	_XENUM5_DOC(@return The index of an enum value (zero-based, consecutive).)		\
	static constexpr Index getIndex(Enum value) noexcept					\
		{ return static_cast<Index>(value); }						_XENUM5_NWLN \

/**
 * Callback worker for _XENUM5_DECLARE_CNTNR_ENUM().
 */
#define _XENUM5_DECLS_ENUM_MEMBER(CTXT, VALUEIDENT, ...)					\
	_XENUM5_INDENT_ADD VALUEIDENT,								_XENUM5_NWLN


// ==============================================================================================
/**
 * Declare accessor and lookup functions.
 */
#define _XENUM5_DECLS_FUNCS(CTXT, DECL)								\
	_XENUM5_DOC(@return Identifier (name) of an enum value.)				\
	static const char* getIdentifier(Enum value) noexcept;					_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given index.						_XENUM5_NWLN \
		@param index Enum-value index to retrieve.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if index >= number of enum values.)			\
	static Enum fromIndex(Index index);							_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given index, without throwing on error.			_XENUM5_NWLN \
		@param index Enum-value index to retrieve.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given index was found, else false.)		\
	static bool fromIndex(Index index,							\
		::_XENUM5_NS::XenumValue<_XENUM5_STORE_NAME(DECL)>& value) noexcept;		_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name).				_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if no such identifier exists.)			\
	static Enum fromIdentifier(const char* identifier);					_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name), without throwing on error.	_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given identifier was found, else false.)	\
	static bool fromIdentifier(const char* identifier,					\
		::_XENUM5_NS::XenumValue<_XENUM5_STORE_NAME(DECL)>& value) noexcept;		_XENUM5_NWLN \

			
// ==============================================================================================
/**
 * Declare function for static_assert() checks on generated data structures.
 */
#define _XENUM5_DECLS_CHECK()									\
	_XENUM5_INDENT_SUB _XENUM5_CMNT(Check)							\
	_XENUM5_DOC(										\
		This function is never supposed to be called. It only contains			_XENUM5_NWLN \
		static_assert()s (for validating the generated data structures), which		_XENUM5_NWLN \
		are evaluated by the compiler. The static_asserts can technically be		_XENUM5_NWLN \
		placed anywhere, but they need access to private members of the store		_XENUM5_NWLN \
		class, so need to be part of it.)						\
	static void _check(void);								_XENUM5_NWLN \


#endif // _XENUM5_IMPL_DECLARE_STORE_HPP
