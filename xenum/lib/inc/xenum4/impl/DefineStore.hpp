/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Definition of the internal store class.
 */
#ifndef _XENUM4_IMPL_DEFINE_STORE_HPP
#define _XENUM4_IMPL_DEFINE_STORE_HPP


// ==============================================================================================
/**
 * Implementation parts that are not declared in the store class are declared and defined inside
 * a namespace with this name, to minimize risk of name clash with user code.
 * @return Name of implementation namespace.
 * @hideinitializer
 */
#define _XENUM4_IMPL_LOCAL_NS(DECL, PROPNAME)							\
	BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(_XenumImplNs_, _XENUM4_DECL_GET_SUFFIX(DECL)), _), PROPNAME)


// ==============================================================================================
/**
 * Main entry function.
 * @hideinitializer
 */
#define _XENUM4_DEFINE_STORE(CTXT, DECL)							\
	_XENUM4_DEFS_SIZE(CTXT, DECL)								\
	_XENUM4_DEFL_IDENT(CTXT, DECL)								\
	_XENUM4_DEFS_FUNCS(CTXT, DECL)								\
	_XENUM4_PROPS_DEFINE(CTXT, DECL)							\
	_XENUM4_DEFS_CHECK(CTXT, DECL)								\


// ==============================================================================================
/**
 * Define the .size var.
 * @hideinitializer
 */
// FIXME: Is it really necessary to define this at all?
#define _XENUM4_DEFS_SIZE(CTXT, DECL)								\
	constexpr const size_t _XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_STORE_NAME(DECL) ::size;	NWLN


// ==============================================================================================
/**
 * Define data and funcs for identifiers.
 * @hideinitializer
 */
#define _XENUM4_DEFL_IDENT(CTXT, DECL)								\
	/* The symbols should never become visible outside this source unit. */			\
	namespace {										\
	/* Also wrap in named namespace to prevent name clashes. */				\
	namespace _XENUM4_IMPL_LOCAL_NS(DECL, ) {						NWLN \
		_XENUM4_IDENT_DEFL_VALUES(CTXT)							\
		_XENUM4_IDENT_DEFL_OFFSETS(CTXT)						\
		_XENUM4_IDENT_DEFL_FUNCS(CTXT, DECL)						\
	}}											NWLN \

/**
 * Worker for _XENUM4_DEFL_IDENT().
 * Defines the identifier string values.
 * @hideinitializer
 */
#define _XENUM4_IDENT_DEFL_VALUES(CTXT)								\
	_XENUM4_IDENT_DEFL_VALUES_STRUCT(CTXT)							\
	_XENUM4_IDENT_DEFL_VALUES_DATA(CTXT)							\

/**
 * Worker for _XENUM4_IDENT_DEFL_VALUES().
 * Declares the IdentValues struct.
 * @hideinitializer
 */
#define _XENUM4_IDENT_DEFL_VALUES_STRUCT(CTXT)							\
IND1	typedef struct {									NWLN \
		_XENUM4_CALL_VALS(_XENUM4_IDENT_DEFL_VALUE_NAME, CTXT)				\
IND1	} IdentValues;										NWLN

/**
 * Worker for _XENUM4_IDENT_DEFL_VALUES_STRUCT(); loop function for each enum value.
 * Declares a single identifier field.
 * @hideinitializer
 */
#define _XENUM4_IDENT_DEFL_VALUE_NAME(CTXT, IDENT, ...)						\
IND2	char IDENT[sizeof(#IDENT)];								NWLN

/**
 * Worker for _XENUM4_IDENT_DEFINE_VALUES().
 * Defines the IdentValues struct.
 * @hideinitializer
 */
#define _XENUM4_IDENT_DEFL_VALUES_DATA(CTXT)							\
IND1	constexpr const IdentValues identValues = {						NWLN \
		_XENUM4_CALL_VALS(_XENUM4_IDENT_DEFL_VALUE, CTXT)				NWLN \
IND1	};											NWLN

/**
 * Callback worker for enum-values iteration.
 * Defines a single identifier value.
 * @hideinitializer
 */
#define _XENUM4_IDENT_DEFL_VALUE(CTXT, IDENT, ...)						\
IND2	#IDENT,											NWLN


/**
 * Worker for _XENUM4_DEFL_IDENT().
 * Defines the identifier string values.
 * @hideinitializer
 */
#define _XENUM4_IDENT_DEFL_OFFSETS(CTXT)							\
	/* Integer type big enough to hold offsets into the string pool. */			\
IND1	typedef ::_XENUM4_NS::SelectInt<sizeof(IdentValues)>::type IdentIndex;			NWLN \
	/* Table of offsets into the identifier stringpool. */					\
IND1	constexpr const IdentIndex identOffsets[] = {						NWLN \
		_XENUM4_CALL_VALS(_XENUM4_IDENT_DEFL_OFFSET, CTXT)				NWLN \
IND1	};											NWLN

/**
 * Callback worker for _XENUM4_IDENT_DEFL_OFFSETS().
 * @hideinitializer
 */
#define _XENUM4_IDENT_DEFL_OFFSET(CTXT, IDENT, ...)						\
IND2	(IdentIndex)offsetof(IdentValues, IDENT),						NWLN

/**
 * Worker for _XENUM4_DEFL_IDENT().
 * Defines getter function.
 * @hideinitializer
 */
#define _XENUM4_IDENT_DEFL_FUNCS(CTXT, DECL)							\
IND1	constexpr const IdentIndex getIdentOffset						\
	(_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_CNTNR_NAME(DECL)::_Enum value) noexcept		NWLN \
IND1	{											NWLN \
IND2		return identOffsets[static_cast							\
		<_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_CNTNR_NAME(DECL)::_Index>		\
		(value)];									NWLN \
IND1	}											NWLN


// ==============================================================================================
/**
 * Define accessor and lookup functions.
 * @hideinitializer
 */
#define _XENUM4_DEFS_FUNCS(CTXT, DECL)								\
	_XENUM4_DEFS_FUNCS_I1(									\
		CTXT,										\
		DECL,										\
		_XENUM4_DECL_GET_SCOPE(DECL),							\
		_XENUM4_STORE_NAME(DECL),							\
		_XENUM4_DECL_GET_VALUENAME(DECL)						\
	)

/**
 * Worker for _XENUM4_DEFS_FUNCS().
 * @hideinitializer
 */
#define _XENUM4_DEFS_FUNCS_I1(CTXT, DECL, SCOPE, STORENAME, VALUENAME)				\
	const char* SCOPE STORENAME::getIdentifier(SCOPE STORENAME::Enum value) noexcept	NWLN \
	{											NWLN \
IND1		return &((const char*)&_XENUM4_IMPL_LOCAL_NS(DECL, )::identValues)		\
			[_XENUM4_IMPL_LOCAL_NS(DECL, )::getIdentOffset(value)];			NWLN \
	}											NWLN \
	SCOPE STORENAME::Enum SCOPE STORENAME::fromIndex(SCOPE STORENAME::Index index)		NWLN \
	{											NWLN \
IND1		if (index < size)								NWLN \
IND2			return static_cast<SCOPE STORENAME::Enum>(index);			NWLN \
IND1		throw std::out_of_range("Index >= size.");					NWLN \
	}											NWLN \
	bool SCOPE STORENAME::fromIndex(SCOPE STORENAME::Index index,				\
					 ::_XENUM4_NS::XenumValue<STORENAME>& value) noexcept	NWLN \
	{											NWLN \
IND1		if (index < size) {								NWLN \
IND2			value = static_cast<SCOPE STORENAME::Enum>(index);			NWLN \
IND2			return true;								NWLN \
IND1		}										NWLN \
IND1		return false;									NWLN \
	}											NWLN \
	SCOPE STORENAME::Enum SCOPE STORENAME::fromIdent(const char* identifier)		NWLN \
	{											NWLN \
		/* FIXME: Linear search, terrible performance. */				NWLN \
IND1		for (Index index=0; index<size; index++) {					NWLN \
IND2			SCOPE VALUENAME value(static_cast<SCOPE STORENAME::Enum>(index));	NWLN \
IND2			if (strcmp(value.getIdentifier(), identifier) == 0)			NWLN \
IND3				return value();							NWLN \
IND1		}										NWLN \
IND1		throw std::out_of_range("No such identifier.");					NWLN \
	}											NWLN \
	bool SCOPE STORENAME::fromIdent(const char* identifier,					\
					 ::_XENUM4_NS::XenumValue<STORENAME>& value) noexcept	NWLN \
	{											NWLN \
		/* FIXME: Linear search, terrible performance. */				NWLN \
IND1		for (Index index=0; index<size; index++) {					NWLN \
IND2			if (strcmp(SCOPE VALUENAME(static_cast<SCOPE STORENAME::Enum>(index))	\
				   .getIdentifier(), identifier) != 0)				NWLN \
IND3				continue;							NWLN \
IND2			value = static_cast<SCOPE STORENAME::Enum>(index);			NWLN \
IND2			return true;								NWLN \
IND1		}										NWLN \
IND1		return false;									NWLN \
	}											NWLN \


// ==============================================================================================
/**
 * Define static_assert() checks on generated data structures.
 * @hideinitializer
 */
#define _XENUM4_DEFS_CHECK(CTXT, DECL)								\
	_XENUM4_DEFS_CHECK_I1(									\
		CTXT,										\
		DECL,										\
		_XENUM4_DECL_GET_SCOPE(DECL),							\
		_XENUM4_STORE_NAME(DECL),							\
		_XENUM4_DECL_GET_VALUENAME(DECL)						\
	)

/**
 * Worker for _XENUM4_DEFS_CHECK().
 * @hideinitializer
 */
#define _XENUM4_DEFS_CHECK_I1(CTXT, DECL, SCOPE, STORENAME, VALUENAME)				\
	void SCOPE STORENAME::_check(void)							\
	{											NWLN \
IND1		static_assert(									\
			sizeof(_XENUM4_IMPL_LOCAL_NS(DECL, )::identOffsets) ==			\
			SCOPE STORENAME ::size *						\
			sizeof(_XENUM4_IMPL_LOCAL_NS(DECL, )::IdentIndex),			\
			"BUG: Struct size mismatch (identOffsets / size)."			\
		);										NWLN \
		BOOST_PP_REPEAT									\
		(										\
			BOOST_PP_SEQ_SIZE(_XENUM4_DECL_GET_PROPDEFS(DECL)),			\
			_XENUM4_PROP_CHECK,							\
			CTXT									\
		)										\
	}											NWLN \



#endif // _XENUM4_IMPL_DEFINE_STORE_HPP
