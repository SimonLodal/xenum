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
#define _XENUM5_IDENT_HDR_DECLS(XDCL, CTXT)							\
	_XENUM5_IDENT_DEFINE_VALUES(static, CTXT)						\
	_XENUM5_IDENT_DECLARE_VALUENAMES(CTXT)							\
	_XENUM5_IDENT_DEFINE_OFFSETS(static, CTXT)						\
	_XENUM5_IDENT_DEFINE_GET_OFFSET(static)							\
	_XENUM5_IDENT_HDR_DECLS_FUNCS(XDCL, CTXT)						\


// ======================================= STORE (SRC) ==========================================
/**
 * Entry point for declaring identifiers in store class context, source implementation.
 */
#define _XENUM5_IDENT_SRC_DECLS(XDCL, CTXT)							\
	_XENUM5_IDENT_SRC_DECLS_FUNCS(XDCL, CTXT)						\

/**
 * Declare the identifier methods, for implementation in source.
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
 * Define the data for identifiers, implemented in header.
 */
#define _XENUM5_IDENT_HDR_DEFINE(XDCL, CTXT)							\
	_XENUM5_IDENT_HDR_DEFINE_I1(								\
		_XENUM5_XDCL_DSCOPE(XDCL),							\
		_XENUM5_STORE_NAME(XDCL)							\
	)											\

/**
 * Worker for _XENUM5_IDENT_HDR_DEFINE().
 */
#define _XENUM5_IDENT_HDR_DEFINE_I1(DSCOPE, SNAME)						\
	constexpr const DSCOPE SNAME::IdentValue DSCOPE SNAME::identValues[];			_XENUM5_NWLN \
	constexpr const DSCOPE SNAME::IdentIndex DSCOPE SNAME::identOffsets[];			_XENUM5_NWLN \


// ====================================== DEFINE (SRC) ==========================================
/**
 * Define the data and functions for identifiers, implemented in source.
 */
#define _XENUM5_IDENT_SRC_DEFINE(XDCL, CTXT)							\
	_XENUM5_IDENT_SRC_DEFL(_XENUM5_IMPL_LOCAL_NS(XDCL, ), XDCL, CTXT)			\
	_XENUM5_IDENT_SRC_DEFS_FUNCS(XDCL, CTXT)						\


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
			_XENUM5_IDENT_DEFINE_VALUES(, CTXT)					\
			_XENUM5_IDENT_DECLARE_VALUENAMES(CTXT)					\
			_XENUM5_IDENT_DEFINE_OFFSETS(, CTXT)					\
			_XENUM5_IDENT_SRC_DEFL_FUNCS(XDCL, CTXT)				\
			_XENUM5_INDENT_DEC							\
		} _XENUM5_CMNT(namespace LSCOPE)						\
		_XENUM5_INDENT_DEC								\
	} _XENUM5_CMNT(Anon namespace)								\


/**
 * Define the local-ns functions related to a single custom property, implemented in source.
 */
#define _XENUM5_IDENT_SRC_DEFL_FUNCS(XDCL, CTXT)						\
	_XENUM5_DOC(Alias the native enum into this scope.)					\
	using Enum = _XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_enum;			_XENUM5_NWLN \
	_XENUM5_DOC(Alias the Index type into this scope.)					\
	using Index = _XENUM5_XDCL_DSCOPE(XDCL)_XENUM5_CNTNR_NAME(XDCL)::_index_t;		_XENUM5_NWLN \
	_XENUM5_IDENT_DEFINE_GET_OFFSET()							\


// ======================================= CHECK (HDR) ==========================================
/**
 * Define final checks on data structures, for implementation in header.
 */
// FIXME: !!
#define _XENUM5_IDENT_HDR_CHECK(LSCOPE, DSCOPE, SNAME)						\


// ======================================= CHECK (SRC) ==========================================
/**
 * Define final checks on data structures, for implementation in header.
 */
#define _XENUM5_IDENT_SRC_CHECK(LSCOPE, DSCOPE, SNAME)						\
	_XENUM5_CMNT(Ident)									\
	static_assert(										\
		/* +1: Compiler adds an extra null terminator in Values array */		\
		sizeof(LSCOPE identValues) == sizeof(LSCOPE IdentValueNames) + 1,		\
		"BUG: Struct/array size mismatch (IdentValueNames / identValues)."		\
	);											_XENUM5_NWLN \
	static_assert(										\
		sizeof(LSCOPE identOffsets) == DSCOPE SNAME::size * sizeof(LSCOPE IdentIndex),	\
		"BUG: Struct size mismatch (identOffsets / ::size)."				\
	);											_XENUM5_NWLN \


// ====================================== COMMON PARTS ==========================================

// ================================ Values ===================================
/**
 * Define the identValues array.
 */
#define _XENUM5_IDENT_DEFINE_VALUES(DECLPFX, CTXT)						\
	_XENUM5_DOC(Native type for identifier strings.)					\
	using IdentValue = char;								_XENUM5_NWLN \
	_XENUM5_DOC(Array of all identifier strings.)						\
	DECLPFX constexpr const IdentValue identValues[] =					\
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DEFINE_VALUE, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Loop worker for _XENUM5_IDENT_DEFINE_VALUES().
 * Define a single identifier value.
 */
#define _XENUM5_IDENT_DEFINE_VALUE(CTXT, IDENT, ...)						\
	#IDENT "\0"										_XENUM5_NWLN


// ============================== ValueNames =================================
/**
 * Define the IdentValueNames struct.
 */
#define _XENUM5_IDENT_DECLARE_VALUENAMES(CTXT)							\
	_XENUM5_DOC(Layout of identValues array.)						\
	using IdentValueNames = struct {							_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DECLARE_VALUENAME, CTXT)			\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN \

/**
 * Declare a single field of the ValueNames struct.
 */
#define _XENUM5_IDENT_DECLARE_VALUENAME(CTXT, IDENT, ...)					\
	IdentValue IDENT[sizeof(#IDENT)];							_XENUM5_NWLN


// =============================== Offsets ===================================
/**
 * Define the identOffsets array.
 */
#define _XENUM5_IDENT_DEFINE_OFFSETS(DECLPFX, CTXT)						\
	_XENUM5_DOC(Integer type big enough to hold offsets into the string pool.)		\
	using IdentIndex = ::_XENUM5_NS::SelectInt<sizeof(identValues)>::type;			_XENUM5_NWLN \
	_XENUM5_DOC(Table of offsets into the identifier stringpool.)				\
	DECLPFX constexpr const IdentIndex identOffsets[] = {					_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		_XENUM5_CALL_VALS(_XENUM5_IDENT_DEFINE_OFFSET, CTXT)				\
		_XENUM5_INDENT_DEC								\
	};											_XENUM5_NWLN

/**
 * Define the offset of a single identifier string.
 */
#define _XENUM5_IDENT_DEFINE_OFFSET(CTXT, IDENT, ...)						\
	offsetof(IdentValueNames, IDENT),							_XENUM5_NWLN


// ============================= getOffset() =================================
/**
 * Define offset getter function.
 */
#define _XENUM5_IDENT_DEFINE_GET_OFFSET(DECLPFX)						\
	_XENUM5_DOC(Get offset in string table for a given enum value.)				\
	DECLPFX constexpr const IdentIndex getIdentOffset(Enum value) noexcept			_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return identOffsets[static_cast<Index>(value)];					_XENUM5_NWLN \
	}											_XENUM5_NWLN \


// =========================== fromIdentifier() ==============================
/**
 * Define identifier functions (SRC).
 */
#define _XENUM5_IDENT_SRC_DEFS_FUNCS(XDCL, CTXT)						\
	_XENUM5_IDENT_SRC_DEFS_FUNCS_I1(							\
		_XENUM5_IMPL_LOCAL_NS(XDCL, ),							\
		_XENUM5_XDCL_DSCOPE(XDCL),							\
		_XENUM5_STORE_NAME(XDCL),							\
		_XENUM5_XDCL_VNAME(XDCL),							\
		XDCL,										\
		CTXT										\
	)

/**
 * Declare and define inline identifier functions (HDR).
 */
#define _XENUM5_IDENT_HDR_DECLS_FUNCS(XDCL, CTXT)						\
	_XENUM5_IDENT_HDR_DECLS_FUNCS_I1(							\
		static constexpr,								\
		,										\
		,										\
		,										\
		::_XENUM5_NS::XenumValue<_XENUM5_STORE_NAME(XDCL)>,				\
		XDCL,										\
		CTXT										\
	)

/**
 * Define identifier functions.
 */
#define _XENUM5_IDENT_HDR_DECLS_FUNCS_I1(DECLPFX, LSCOPE, DSCOPE, SNAME, VNAME, XDCL, CTXT)	\
	_XENUM5_DOC(@return Identifier (name) of an enum value.)				\
	DECLPFX const char* DSCOPE SNAME getIdentifier(DSCOPE SNAME Enum value) noexcept	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return &LSCOPE identValues[LSCOPE getIdentOffset(value)];			_XENUM5_NWLN \
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Recursive worker for throwing fromIdentifier().)				\
	DECLPFX DSCOPE SNAME Enum DSCOPE SNAME fromIdentifierT(const char* identifier, Index index)	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return (index < size)								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
/* FIXME: For non-inline \
			?( (strcmp(identifier, &identValues[getIdentOffset(static_cast<Enum>(index))]) == 0)	_XENUM5_NWLN \
*/\
			?(::_XENUM5_NS::ce_strEqual(identifier, &identValues[getIdentOffset(static_cast<Enum>(index))])	_XENUM5_NWLN \
				_XENUM5_INDENT_INC						\
				? static_cast<Enum>(index)					_XENUM5_NWLN \
				: fromIdentifierT(identifier, index++)				_XENUM5_NWLN \
				_XENUM5_INDENT_DEC						\
			)									_XENUM5_NWLN \
			: throw std::out_of_range("No such identifier.");			_XENUM5_NWLN \
			_XENUM5_INDENT_DEC							\
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name).				_XENUM5_NWLN \
		Warning: Linear search, terrible performance.					_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@return Requested enum value.							_XENUM5_NWLN \
		@throws std::out_of_range if no such identifier exists.)			\
	DECLPFX DSCOPE SNAME Enum DSCOPE SNAME fromIdentifier(const char* identifier)		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return fromIdentifierT(identifier, 0);						_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Recursive worker for non-throwing fromIdentifier().)			\
	DECLPFX bool DSCOPE SNAME fromIdentifierN(const char* identifier, VNAME& value, Index index)	_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return (index < size)								_XENUM5_NWLN \
			_XENUM5_INDENT_INC							\
/* FIXME: For non-inline \
			?( (strcmp(identifier, &identValues[getIdentOffset(static_cast<Enum>(index))]) == 0)	_XENUM5_NWLN \
*/\
			?(::_XENUM5_NS::ce_strEqual(identifier, &identValues[getIdentOffset(static_cast<Enum>(index))])	_XENUM5_NWLN \
				_XENUM5_INDENT_INC						\
				? (value = static_cast<Enum>(index)), true			_XENUM5_NWLN \
				: fromIdentifierN(identifier, value, index++)			_XENUM5_NWLN \
				_XENUM5_INDENT_DEC						\
			)									_XENUM5_NWLN \
			: false;								_XENUM5_NWLN \
			_XENUM5_INDENT_DEC							\
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \
	_XENUM5_DOC(Get enum value with given identifier (name), without throwing on error.	_XENUM5_NWLN \
		Warning: Linear search, terrible performance.					_XENUM5_NWLN \
		@param identifier Identifier to look up.					_XENUM5_NWLN \
		@param value Return value; is set to the requested enum value,			_XENUM5_NWLN \
			_XENUM5_INDENT_ADD							\
			if it exists, else it is not touched.					_XENUM5_NWLN \
		@return True if enum-value with given identifier was found, else false.)	\
	DECLPFX bool DSCOPE SNAME fromIdentifier(const char* identifier,			\
						VNAME& value) noexcept				_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_INC								\
		return fromIdentifierN(identifier, value, 0);					_XENUM5_NWLN \
		_XENUM5_INDENT_DEC								\
	}											_XENUM5_NWLN \


/**
 * Define identifier functions (SRC).
 */
#define _XENUM5_IDENT_SRC_DEFS_FUNCS_I1(LSCOPE, DSCOPE, SNAME, VNAME, XDCL, CTXT)		\
	const char* DSCOPE SNAME::getIdentifier(DSCOPE SNAME::Enum value) noexcept		_XENUM5_NWLN \
	{											_XENUM5_NWLN \
		_XENUM5_INDENT_ADD								\
		return &LSCOPE::identValues[LSCOPE::getIdentOffset(value)];			_XENUM5_NWLN \
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
