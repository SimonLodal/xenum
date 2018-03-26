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
 * Main entry function.
 * @hideinitializer
 */
#define _XENUM4_DEFINE_STORE(CTXT, DECL)								\
	_XENUM4_DEFS_SIZE(CTXT, DECL)								\
	_XENUM4_DEFS_IDENTPOOL(CTXT, DECL)							\
	_XENUM4_DEFS_LOOKUP_FUNCS(CTXT, DECL)							\
	_XENUM4_PROPS_DEFINE(CTXT, DECL)							\


// ==============================================================================================
/**
 * Define the _size var.
 * @hideinitializer
 */
// FIXME: Is it really necessary to define this at all?
#define _XENUM4_DEFS_SIZE(CTXT, DECL)								\
	constexpr const size_t _XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_STORE_NAME(DECL) ::_size;	NWLN


// ==============================================================================================
/**
 * Define data for identifier stringpool and offsets table.
 * @hideinitializer
 */
#define _XENUM4_DEFS_IDENTPOOL(CTXT, DECL)							\
	_XENUM4_DEFS_IDENTPOOL_BEGIN(CTXT, DECL)						NWLN \
		_XENUM4_CALL_VALS(_XENUM4_DEFS_IDENTPOOL_MEMBER, CTXT)				NWLN \
	};											NWLN \
	_XENUM4_DEFS_IDENTPOOL_OFFSETS_BEGIN(CTXT, DECL)					NWLN \
		_XENUM4_CALL_VALS(_XENUM4_DEFS_IDENTPOOL_OFFSETS_MEMBER, CTXT)			NWLN \
	};											NWLN
/**
 * Worker for _XENUM4_DEFS_IDENTPOOL().
 * @hideinitializer
 */
#define _XENUM4_DEFS_IDENTPOOL_BEGIN(CTXT, DECL)						\
	constexpr const										\
	_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_STORE_NAME(DECL)::_IdentPool			\
	_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_STORE_NAME(DECL)::_identPool = {			\

/**
 * Callback worker for _XENUM4_DEFS_IDENTPOOL().
 * @hideinitializer
 */
#define _XENUM4_DEFS_IDENTPOOL_MEMBER(CTXT, IDENT, ...)						\
IND1	#IDENT,											NWLN

/**
 * Worker for _XENUM4_DEFS_IDENTPOOL().
 * @hideinitializer
 */
#define _XENUM4_DEFS_IDENTPOOL_OFFSETS_BEGIN(CTXT, DECL)					\
	constexpr const										\
	_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_STORE_NAME(DECL)::_IdentOffset			\
	_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_STORE_NAME(DECL)::_identOffsets[] = {		\

/**
 * Callback worker for _XENUM4_DEFS_IDENTPOOL().
 * @hideinitializer
 */
#define _XENUM4_DEFS_IDENTPOOL_OFFSETS_MEMBER(CTXT, IDENT, ...)					\
IND1	_XENUM4_DEFS_IDENTPOOL_OFFSETS_MEMBER_BEGIN(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))		\
		->IDENT,									NWLN

/**
 * Worker for _XENUM4_DEFS_IDENTPOOL_OFFSETS_MEMBER().
 * @hideinitializer
 */
#define _XENUM4_DEFS_IDENTPOOL_OFFSETS_MEMBER_BEGIN(CTXT, DECL)					\
	(intptr_t)&((_XENUM4_DECL_GET_SCOPE(DECL)_XENUM4_STORE_NAME(DECL)::_IdentPool*)0)


// ==============================================================================================
/**
 * Define from*() functions.
 * @hideinitializer
 */
#define _XENUM4_DEFS_LOOKUP_FUNCS(CTXT, DECL)							\
	_XENUM4_DEFS_LOOKUP_FUNCS_I1(								\
		CTXT,										\
		DECL,										\
		_XENUM4_DECL_GET_SCOPE(DECL),							\
		_XENUM4_STORE_NAME(DECL),							\
		_XENUM4_DECL_GET_VALUENAME(DECL)						\
	)

/**
 * Worker for _XENUM4_DEFS_LOOKUP_FUNCS().
 * @hideinitializer
 */
#define _XENUM4_DEFS_LOOKUP_FUNCS_I1(CTXT, DECL, SCOPE, STORENAME, VALUENAME)			\
	SCOPE STORENAME::_Enum SCOPE STORENAME::_fromIndex(SCOPE STORENAME::_index_t index)	NWLN \
	{											NWLN \
IND1		if (index < _size)								NWLN \
IND2			return static_cast<SCOPE STORENAME::_Enum>(index);			NWLN \
IND1		throw std::out_of_range("Index >= size.");					NWLN \
	}											NWLN \
	bool SCOPE STORENAME::_fromIndex(SCOPE STORENAME::_index_t index,			\
					 SCOPE STORENAME::_Enum& value) noexcept		NWLN \
	{											NWLN \
IND1		if (index < _size) {								NWLN \
IND2			value = static_cast<SCOPE STORENAME::_Enum>(index);			NWLN \
IND2			return true;								NWLN \
IND1		}										NWLN \
IND1		return false;									NWLN \
	}											NWLN \
	SCOPE STORENAME::_Enum SCOPE STORENAME::_fromIdent(const char* identifier)		NWLN \
	{											NWLN \
		/* FIXME: Linear search, terrible performance. */				NWLN \
IND1		for (_index_t index=0; index<_size; index++) {					NWLN \
IND2			SCOPE VALUENAME value(static_cast<SCOPE STORENAME::_Enum>(index));	NWLN \
IND2			if (strcmp(value.getIdentifier(), identifier) == 0)			NWLN \
IND3				return value();							NWLN \
IND1		}										NWLN \
IND1		throw std::out_of_range("No such identifier.");					NWLN \
	}											NWLN \
	bool SCOPE STORENAME::_fromIdent(const char* identifier,				\
					 SCOPE STORENAME::_Enum& value) noexcept		NWLN \
	{											NWLN \
		/* FIXME: Linear search, terrible performance. */				NWLN \
IND1		for (_index_t index=0; index<_size; index++) {					NWLN \
IND2			if (strcmp(SCOPE VALUENAME(static_cast<SCOPE STORENAME::_Enum>(index))	\
				   .getIdentifier(), identifier) != 0)				NWLN \
IND3				continue;							NWLN \
IND2			value = static_cast<SCOPE STORENAME::_Enum>(index);			NWLN \
IND2			return true;								NWLN \
IND1		}										NWLN \
IND1		return false;									NWLN \
	}											NWLN \


#endif // _XENUM4_IMPL_DEFINE_STORE_HPP
