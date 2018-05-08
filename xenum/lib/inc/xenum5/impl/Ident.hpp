/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Implementation of enum-value identifier strings.
 */
#ifndef _XENUM5_IMPL_IDENT_HPP
#define _XENUM5_IMPL_IDENT_HPP


// ======================================= STORE (HDR) ==========================================
/**
 * Entry point for declaring identifiers in store class context, header implementation.
 */
// FIXME: !!
#define _XENUM5_IDENT_HDR_DECLS(XDCL, CTXT)							\
	_XENUM5_CMNT(XENUM5_IDENT_HDR_DECLS begin)

/**
 * Entry point for declaring identifiers in store class context, source implementation.
 */
#define _XENUM5_IDENT_SRC_DECLS(XDCL, CTXT)							\
	_XENUM5_CMNT(XENUM5_IDENT_SRC_DECLS begin)						\
	_XENUM5_IDENT_SRC_DECLS_FUNCS(XDCL, CTXT)						\


// ==============================================================================================
/**
 * Declare accessor and lookup functions.
 */
#define _XENUM5_IDENT_SRC_DECLS_FUNCS(XDCL, CTXT)						\
	_XENUM5_DOC(@return Identifier (name) of an enum value.)				\
	static const char* getIdentifier(Enum value) noexcept;					_XENUM5_NWLN \
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
		::_XENUM5_NS::XenumValue<_XENUM5_STORE_NAME(XDCL)>& value) noexcept;		_XENUM5_NWLN \

			






// ====================================== DEFINE (HDR) ==========================================
/**
 * Define the data and functions for identifiers, implemented in header.
 */
// FIXME: !!
#define _XENUM5_IDENT_HDR_DEFINE(XDCL, CTXT)							\
_XENUM5_CMNT(XENUM5_IDENT_HDR_DEFINE)								\



// ====================================== DEFINE (SRC) ==========================================
/**
 * Define the data and functions for identifiers, implemented in source.
 */
// FIXME: !!
#define _XENUM5_IDENT_SRC_DEFINE(XDCL, CTXT)							\
_XENUM5_CMNT(XENUM5_IDENT_SRC_DEFINE)								\
	_XENUM5_IDENT_SRC_DEFL(_XENUM5_IMPL_LOCAL_NS(XDCL, ), XDCL, CTXT)			\
	_XENUM5_DEFS_FUNCS(CTXT, XDCL)								\


/**
 * Define the local data and functions.
 */
#define _XENUM5_IDENT_SRC_DEFL(LSCOPE, XDCL, CTXT)						\
	_XENUM5_DOC(The symbols should never become visible outside this source unit.)		\
	namespace {										_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_DOC(Also wrap in named namespace to prevent name clashes.)		\
		namespace LSCOPE {								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
			_XENUM5_IDENT_DEFL_VALUES(CTXT)						\
			_XENUM5_IDENT_DEFL_OFFSETS(CTXT)					\
			_XENUM5_IDENT_DEFL_FUNCS(CTXT, XDCL)					\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace LSCOPE)						\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


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


#endif // _XENUM5_IMPL_IDENT_HPP
