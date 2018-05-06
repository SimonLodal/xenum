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
#define _XENUM5_IMPL_LOCAL_NS(XDCL, PNAME)							\
	BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(_xenum5_local_, _XENUM5_XDCL_SUFFIX(XDCL)), _), PNAME)


// ==============================================================================================
/**
 * Main entry function.
 */
#define _XENUM5_DEFINE_STORE(CTXT, XDCL)							\
	_XENUM5_CMNT(Store:Main)							\
	_XENUM5_DEFS_SIZE(CTXT, XDCL)								\
	_XENUM5_DEFL_IDENT(CTXT, XDCL)								\
	_XENUM5_DEFS_FUNCS(CTXT, XDCL)								\
	_XENUM5_PROPS_DEFINE(CTXT, XDCL)							\
	_XENUM5_DEFS_CHECK(CTXT, XDCL)								\


// ==============================================================================================
/**
 * Define the .size var.
 */
// FIXME: Is it really necessary to define this at all?
#define _XENUM5_DEFS_SIZE(CTXT, XDCL)								\
	constexpr const size_t _XENUM5_XDCL_DSCOPE(XDCL) _XENUM5_STORE_NAME(XDCL) ::size;	_XENUM5_NWLN


// ==============================================================================================
/**
 * Define data and funcs for identifiers.
 */
#define _XENUM5_DEFL_IDENT(CTXT, XDCL)								\
	/* The symbols should never become visible outside this source unit. */			\
	namespace {										\
	/* Also wrap in named namespace to prevent name clashes. */				\
	namespace _XENUM5_IMPL_LOCAL_NS(XDCL, ) {						_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_IDENT_DEFL_VALUES(CTXT)							\
		_XENUM5_IDENT_DEFL_OFFSETS(CTXT)						\
		_XENUM5_IDENT_DEFL_FUNCS(CTXT, XDCL)						\
		_XENUM5_INDENT_DEC								\
	}}											_XENUM5_NWLN \

/**
 * Worker for _XENUM5_DEFL_IDENT().
 * Define the identifier string values.
 */
#define _XENUM5_IDENT_DEFL_VALUES(CTXT)								\
	_XENUM5_IDENT_DEFL_VALUES_STRUCT(CTXT)							\
	_XENUM5_IDENT_DEFL_VALUES_DATA(CTXT)							\

/**
 * Worker for _XENUM5_IDENT_DEFL_VALUES().
 * Declare the IdentValues struct.
 */
#define _XENUM5_IDENT_DEFL_VALUES_STRUCT(CTXT)							\
	using IdentValues = struct {								_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DEFL_VALUE_NAME, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Worker for _XENUM5_IDENT_DEFL_VALUES_STRUCT(); loop function for each enum value.
 * Declare a single identifier field.
 */
#define _XENUM5_IDENT_DEFL_VALUE_NAME(CTXT, IDENT, ...)						\
	char IDENT[sizeof(#IDENT)];								_XENUM5_NWLN

/**
 * Worker for _XENUM5_IDENT_DEFINE_VALUES().
 * Define the IdentValues struct.
 */
#define _XENUM5_IDENT_DEFL_VALUES_DATA(CTXT)							\
	constexpr const IdentValues identValues = {						_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DEFL_VALUE, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Callback worker for enum-values iteration.
 * Define a single identifier value.
 */
#define _XENUM5_IDENT_DEFL_VALUE(CTXT, IDENT, ...)						\
	#IDENT,											_XENUM5_NWLN


/**
 * Worker for _XENUM5_DEFL_IDENT().
 * Define the identifier string values.
 */
#define _XENUM5_IDENT_DEFL_OFFSETS(CTXT)							\
	/* Integer type big enough to hold offsets into the string pool. */			\
	using IdentIndex = ::_XENUM5_NS::SelectInt<sizeof(IdentValues)>::type;			_XENUM5_NWLN \
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
 * Define getter function.
 */
#define _XENUM5_IDENT_DEFL_FUNCS(CTXT, XDCL)							\
	constexpr const IdentIndex getIdentOffset						\
	(_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_enum value) noexcept		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return identOffsets[static_cast							\
			<_XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_index_t>		\
			(value)];								_XENUM5_NWLN \
	}											_XENUM5_NWLN


// ==============================================================================================
/**
 * Define accessor and lookup functions.
 */
#define _XENUM5_DEFS_FUNCS(CTXT, XDCL)								\
	_XENUM5_DEFS_FUNCS_I1(									\
		CTXT,										\
		XDCL,										\
		_XENUM5_XDCL_DSCOPE(XDCL),							\
		_XENUM5_STORE_NAME(XDCL),							\
		_XENUM5_XDCL_VNAME(XDCL)							\
	)

/**
 * Worker for _XENUM5_DEFS_FUNCS().
 */
#define _XENUM5_DEFS_FUNCS_I1(CTXT, XDCL, DSCOPE, SNAME, VNAME)					\
	const char* DSCOPE SNAME::getIdentifier(DSCOPE SNAME::Enum value) noexcept		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return &((const char*)&_XENUM5_IMPL_LOCAL_NS(XDCL, )::identValues)		\
			[_XENUM5_IMPL_LOCAL_NS(XDCL, )::getIdentOffset(value)];			_XENUM5_NWLN \
	}											_XENUM5_NWLN \
	DSCOPE SNAME::Enum DSCOPE SNAME::fromIdentifier(const char* identifier)			_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		/* FIXME: Linear search, terrible performance. */				\
		for (Index index=0; index<size; index++) {					_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			DSCOPE VNAME value(static_cast<DSCOPE SNAME::Enum>(index));		_XENUM5_NWLN \
			if (strcmp(value.getIdentifier(), identifier) == 0)			_XENUM5_NWLN \
				_XENUM5_INDENT_ADD						\
				return value();							_XENUM5_NWLN \
			_XENUM5_INDENT_DEC							\
		}										_XENUM5_NWLN \
		throw std::out_of_range("No such identifier.");					_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
	bool DSCOPE SNAME::fromIdentifier(const char* identifier,				\
				::_XENUM5_NS::XenumValue<SNAME>& value) noexcept		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		/* FIXME: Linear search, terrible performance. */				\
		for (Index index=0; index<size; index++) {					_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			if (strcmp(DSCOPE VNAME(static_cast<DSCOPE SNAME::Enum>(index))		\
					.getIdentifier(), identifier) != 0)			_XENUM5_NWLN \
				_XENUM5_INDENT_ADD						\
				continue;							_XENUM5_NWLN \
			value = static_cast<DSCOPE SNAME::Enum>(index);				_XENUM5_NWLN \
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
#define _XENUM5_DEFS_CHECK(CTXT, XDCL)								\
	_XENUM5_DEFS_CHECK_I1(									\
		CTXT,										\
		XDCL,										\
		_XENUM5_XDCL_DSCOPE(XDCL),							\
		_XENUM5_STORE_NAME(XDCL),							\
		_XENUM5_XDCL_VNAME(XDCL)							\
	)

/**
 * Worker for _XENUM5_DEFS_CHECK().
 */
#define _XENUM5_DEFS_CHECK_I1(CTXT, XDCL, DSCOPE, SNAME, VNAME)					\
	_XENUM5_NWLN _XENUM5_CMNT(Store:Check)							\
	void DSCOPE SNAME::_check(void)								\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CMNT(Main)								\
		static_assert(									\
			sizeof(_XENUM5_IMPL_LOCAL_NS(XDCL, )::identOffsets) ==			\
			DSCOPE SNAME ::size *							\
			sizeof(_XENUM5_IMPL_LOCAL_NS(XDCL, )::IdentIndex),			\
			"BUG: Struct size mismatch (identOffsets / size)."			\
		);										_XENUM5_NWLN \
		BOOST_PP_REPEAT									\
		(										\
			BOOST_PP_SEQ_SIZE(_XENUM5_XDCL_PDEFS(XDCL)),				\
			_XENUM5_PROP_CHECK,							\
			CTXT									\
		)										\
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


#endif // _XENUM5_IMPL_DEFINE_STORE_HPP
