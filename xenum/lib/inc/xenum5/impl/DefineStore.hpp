/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Definition of the internal store class.
 */
#ifndef _XENUM5_IMPL_DEFINE_STORE_HPP
#define _XENUM5_IMPL_DEFINE_STORE_HPP


// ==============================================================================================
/**
 * Implementation parts that are not declared in the store class are declared and defined inside
 * a namespace with this name, to minimize risk of name clash with user code.
 * @return Name of implementation namespace.
 */
#define _XENUM5_IMPL_LOCAL_NS(DECL, PROPNAME)							\
	BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(_xenum_impl_ns_, _XENUM5_DECL_GET_SUFFIX(DECL)), _), PROPNAME)


// ==============================================================================================
/**
 * Main entry function.
 */
#define _XENUM5_DEFINE_STORE(CTXT, DECL)							\
	_XENUM5_DEFS_SIZE(CTXT, DECL)								\
	_XENUM5_DEFL_IDENT(CTXT, DECL)								\
	_XENUM5_DEFS_FUNCS(CTXT, DECL)								\
	_XENUM5_PROPS_DEFINE(CTXT, DECL)							\
	_XENUM5_DEFS_CHECK(CTXT, DECL)								\


// ==============================================================================================
/**
 * Define the .size var.
 */
// FIXME: Is it really necessary to define this at all?
#define _XENUM5_DEFS_SIZE(CTXT, DECL)								\
	constexpr const size_t _XENUM5_DECL_GET_SCOPE(DECL) _XENUM5_STORE_NAME(DECL) ::size;	_XENUM5_NWLN


// ==============================================================================================
/**
 * Define data and funcs for identifiers.
 */
#define _XENUM5_DEFL_IDENT(CTXT, DECL)								\
	/* The symbols should never become visible outside this source unit. */			\
	namespace {										\
	/* Also wrap in named namespace to prevent name clashes. */				\
	namespace _XENUM5_IMPL_LOCAL_NS(DECL, ) {						_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_IDENT_DEFL_VALUES(CTXT)							\
		_XENUM5_IDENT_DEFL_OFFSETS(CTXT)						\
		_XENUM5_IDENT_DEFL_FUNCS(CTXT, DECL)						\
		_XENUM5_INDENT_DEC								\
	}}											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_DEFL_IDENT().
 * Defines the identifier string values.
 */
#define _XENUM5_IDENT_DEFL_VALUES(CTXT)								\
	_XENUM5_IDENT_DEFL_VALUES_STRUCT(CTXT)							\
	_XENUM5_IDENT_DEFL_VALUES_DATA(CTXT)							\

/**
 * Worker for _XENUM5_IDENT_DEFL_VALUES().
 * Declares the IdentValues struct.
 */
#define _XENUM5_IDENT_DEFL_VALUES_STRUCT(CTXT)							\
	typedef struct {									_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DEFL_VALUE_NAME, CTXT)				\
		_XENUM5_INDENT_DEC								\
	} IdentValues;										_XENUM5_NWLN

/**
 * Worker for _XENUM5_IDENT_DEFL_VALUES_STRUCT(); loop function for each enum value.
 * Declares a single identifier field.
 */
#define _XENUM5_IDENT_DEFL_VALUE_NAME(CTXT, IDENT, ...)						\
	char IDENT[sizeof(#IDENT)];								_XENUM5_NWLN

/**
 * Worker for _XENUM5_IDENT_DEFINE_VALUES().
 * Defines the IdentValues struct.
 */
#define _XENUM5_IDENT_DEFL_VALUES_DATA(CTXT)							\
	constexpr const IdentValues identValues = {						_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DEFL_VALUE, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Callback worker for enum-values iteration.
 * Defines a single identifier value.
 */
#define _XENUM5_IDENT_DEFL_VALUE(CTXT, IDENT, ...)						\
	#IDENT,											_XENUM5_NWLN


/**
 * Worker for _XENUM5_DEFL_IDENT().
 * Defines the identifier string values.
 */
#define _XENUM5_IDENT_DEFL_OFFSETS(CTXT)							\
	/* Integer type big enough to hold offsets into the string pool. */			\
	typedef ::_XENUM5_NS::SelectInt<sizeof(IdentValues)>::type IdentIndex;			_XENUM5_NWLN \
	/* Table of offsets into the identifier stringpool. */					\
	constexpr const IdentIndex identOffsets[] = {						_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DEFL_OFFSET, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Callback worker for _XENUM5_IDENT_DEFL_OFFSETS().
 */
#define _XENUM5_IDENT_DEFL_OFFSET(CTXT, IDENT, ...)						\
	(IdentIndex)offsetof(IdentValues, IDENT),						_XENUM5_NWLN

/**
 * Worker for _XENUM5_DEFL_IDENT().
 * Defines getter function.
 */
#define _XENUM5_IDENT_DEFL_FUNCS(CTXT, DECL)							\
	constexpr const IdentIndex getIdentOffset						\
	(_XENUM5_DECL_GET_SCOPE(DECL)_XENUM5_CNTNR_NAME(DECL)::_enum value) noexcept		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return identOffsets[static_cast							\
			<_XENUM5_DECL_GET_SCOPE(DECL)_XENUM5_CNTNR_NAME(DECL)::_index_t>	\
			(value)];								_XENUM5_NWLN \
	}											_XENUM5_NWLN


// ==============================================================================================
/**
 * Define accessor and lookup functions.
 */
#define _XENUM5_DEFS_FUNCS(CTXT, DECL)								\
	_XENUM5_DEFS_FUNCS_I1(									\
		CTXT,										\
		DECL,										\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_STORE_NAME(DECL),							\
		_XENUM5_DECL_GET_VALUENAME(DECL)						\
	)

/**
 * Worker for _XENUM5_DEFS_FUNCS().
 */
#define _XENUM5_DEFS_FUNCS_I1(CTXT, DECL, SCOPE, STORENAME, VALUENAME)				\
	const char* SCOPE STORENAME::getIdentifier(SCOPE STORENAME::Enum value) noexcept	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return &((const char*)&_XENUM5_IMPL_LOCAL_NS(DECL, )::identValues)		\
			[_XENUM5_IMPL_LOCAL_NS(DECL, )::getIdentOffset(value)];			_XENUM5_NWLN \
	}											_XENUM5_NWLN \
	SCOPE STORENAME::Enum SCOPE STORENAME::fromIndex(SCOPE STORENAME::Index index)		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		if (index < size)								_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			return static_cast<SCOPE STORENAME::Enum>(index);			_XENUM5_NWLN \
		throw std::out_of_range("Index >= size.");					_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
	bool SCOPE STORENAME::fromIndex(SCOPE STORENAME::Index index,				\
				::_XENUM5_NS::XenumValue<STORENAME>& value) noexcept		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		if (index < size) {								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			value = static_cast<SCOPE STORENAME::Enum>(index);			_XENUM5_NWLN \
			return true;								_XENUM5_NWLN \
			_XENUM5_INDENT_DEC							\
		}										_XENUM5_NWLN \
		return false;									_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
	SCOPE STORENAME::Enum SCOPE STORENAME::fromIdentifier(const char* identifier)		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		/* FIXME: Linear search, terrible performance. */				\
		for (Index index=0; index<size; index++) {				_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			SCOPE VALUENAME value(static_cast<SCOPE STORENAME::Enum>(index));	_XENUM5_NWLN \
			if (strcmp(value.getIdentifier(), identifier) == 0)			_XENUM5_NWLN \
				_XENUM5_INDENT_ADD						\
				return value();							_XENUM5_NWLN \
			_XENUM5_INDENT_DEC							\
		}										_XENUM5_NWLN \
		throw std::out_of_range("No such identifier.");					_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
	bool SCOPE STORENAME::fromIdentifier(const char* identifier,				\
				::_XENUM5_NS::XenumValue<STORENAME>& value) noexcept		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		/* FIXME: Linear search, terrible performance. */				\
		for (Index index=0; index<size; index++) {					_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			if (strcmp(SCOPE VALUENAME(static_cast<SCOPE STORENAME::Enum>(index))	\
					.getIdentifier(), identifier) != 0)			_XENUM5_NWLN \
				_XENUM5_INDENT_ADD						\
				continue;							_XENUM5_NWLN \
			value = static_cast<SCOPE STORENAME::Enum>(index);			_XENUM5_NWLN \
			return true;								_XENUM5_NWLN \
			_XENUM5_INDENT_DEC							\
		}										_XENUM5_NWLN \
		return false;									_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


// ==============================================================================================
/**
 * Define static_assert() checks on generated data structures.
 */
#define _XENUM5_DEFS_CHECK(CTXT, DECL)								\
	_XENUM5_DEFS_CHECK_I1(									\
		CTXT,										\
		DECL,										\
		_XENUM5_DECL_GET_SCOPE(DECL),							\
		_XENUM5_STORE_NAME(DECL),							\
		_XENUM5_DECL_GET_VALUENAME(DECL)						\
	)

/**
 * Worker for _XENUM5_DEFS_CHECK().
 */
#define _XENUM5_DEFS_CHECK_I1(CTXT, DECL, SCOPE, STORENAME, VALUENAME)				\
	void SCOPE STORENAME::_check(void)							\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		static_assert(									\
			sizeof(_XENUM5_IMPL_LOCAL_NS(DECL, )::identOffsets) ==			\
			SCOPE STORENAME ::size *						\
			sizeof(_XENUM5_IMPL_LOCAL_NS(DECL, )::IdentIndex),			\
			"BUG: Struct size mismatch (identOffsets / size)."			\
		);										_XENUM5_NWLN \
		BOOST_PP_REPEAT									\
		(										\
			BOOST_PP_SEQ_SIZE(_XENUM5_DECL_GET_PROPDEFS(DECL)),			\
			_XENUM5_PROP_CHECK,							\
			CTXT									\
		)										\
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


#endif // _XENUM5_IMPL_DEFINE_STORE_HPP
