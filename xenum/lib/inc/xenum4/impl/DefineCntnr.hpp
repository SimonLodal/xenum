/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM4_IMPL_DEFINE_CNTNR_HPP
#define _XENUM4_IMPL_DEFINE_CNTNR_HPP


// ==============================================================================================
/**
 * Define the EnumCntnr::size static var.
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_ENUMSIZE(CTXT, DECL)						\
	constexpr const size_t _XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL) ::size; NWLN


// ==============================================================================================
/**
 * Define the static enum-values in the enum-container class.
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_ENUM_COPY(CTXT)							\
	_XENUM4_CALL_VALS(_XENUM4_DEFINE_CNTNR_ENUM_COPY_MEMBER, CTXT)

/**
 * Callback worker for _XENUM4_DEFINE_CNTNR_ENUM_COPY().
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_ENUM_COPY_MEMBER(CTXT, VALUEIDENT, ...)				\
	_XENUM4_DEFINE_CNTNR_ENUM_COPY_MEMBER_PREFIX(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))		\
		VALUEIDENT;									NWLN

/**
 * Calback worker for _XENUM4_DEFINE_CNTNR_ENUM_COPY_MEMBER().
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_ENUM_COPY_MEMBER_PREFIX(CTXT, DECL)				\
	constexpr const _XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL) ::Enum	\
		_XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL) ::


// ==============================================================================================
/**
 * Define the enum-container's .from*() functions.
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_FUNCS(CTXT, DECL)							\
	_XENUM4_DEFINE_CNTNR_FUNCS_I1(								\
		CTXT,										\
		DECL,										\
		_XENUM4_DECL_GET_SCOPE(DECL),							\
		_XENUM4_DECL_GET_CNTNRNAME(DECL),						\
		_XENUM4_DECL_GET_VALUENAME(DECL)						\
	)

/**
 * Callback worker for _XENUM4_DEFINE_CNTNR_FUNCS().
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_FUNCS_I1(CTXT, DECL, SCOPE, CNTNRNAME, VALUENAME)			\
	SCOPE CNTNRNAME::Enum SCOPE CNTNRNAME::fromIndex(SCOPE CNTNRNAME::index_t index)	NWLN \
	{											NWLN \
IND1		if (index < size)								NWLN \
IND2			return static_cast<SCOPE CNTNRNAME::Enum>(index);			NWLN \
IND1		throw std::out_of_range("Index >= size.");					NWLN \
	}											NWLN \
	bool SCOPE CNTNRNAME::fromIndex(SCOPE CNTNRNAME::index_t index, SCOPE CNTNRNAME::Enum& value) noexcept NWLN \
	{											NWLN \
IND1		if (index < size) {								NWLN \
IND2			value = static_cast<SCOPE CNTNRNAME::Enum>(index);			NWLN \
IND2			return true;								NWLN \
IND1		}										NWLN \
IND1		return false;									NWLN \
	}											NWLN \
	SCOPE CNTNRNAME::Enum SCOPE CNTNRNAME::fromIdentifier(const char* identifier)		NWLN \
	{											NWLN \
		/* FIXME: Linear search, terrible performance. */				NWLN \
IND1		for (index_t index=0; index<size; index++) {					NWLN \
IND2			SCOPE VALUENAME value(static_cast<SCOPE CNTNRNAME::Enum>(index));	NWLN \
IND2			if (strcmp(value.getIdentifier(), identifier) == 0)			NWLN \
IND3				return value();							NWLN \
IND1		}										NWLN \
IND1		throw std::out_of_range("No such identifier.");					NWLN \
	}											NWLN \
	bool SCOPE CNTNRNAME::fromIdentifier(const char* identifier, SCOPE CNTNRNAME::Enum& value) noexcept NWLN \
	{											NWLN \
		/* FIXME: Linear search, terrible performance. */				NWLN \
IND1		for (index_t index=0; index<size; index++) {					NWLN \
IND2			if (strcmp(SCOPE VALUENAME(static_cast<SCOPE CNTNRNAME::Enum>(index)).getIdentifier(), identifier) != 0) NWLN \
IND3				continue;							NWLN \
IND2			value = static_cast<SCOPE CNTNRNAME::Enum>(index);			NWLN \
IND2			return true;								NWLN \
IND1		}										NWLN \
IND1		return false;									NWLN \
	}											NWLN \


// ==============================================================================================
/**
 * Define data for identifier stringpool and offsets table.
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_IDENTPOOL(CTXT, DECL)						\
	_XENUM4_DEFINE_CNTNR_IDENTPOOL_BEGIN(CTXT, DECL)					NWLN \
		_XENUM4_CALL_VALS(_XENUM4_DEFINE_CNTNR_IDENTPOOL_MEMBER, CTXT)			NWLN \
	};											NWLN \
	_XENUM4_DEFINE_CNTNR_IDENTPOOL_OFFSETS_BEGIN(CTXT, DECL)				NWLN \
		_XENUM4_CALL_VALS(_XENUM4_DEFINE_CNTNR_IDENTPOOL_OFFSETS_MEMBER, CTXT)		NWLN \
	};											NWLN
/**
 * Callback worker for _XENUM4_DEFINE_CNTNR_IDENTPOOL().
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_IDENTPOOL_BEGIN(CTXT, DECL)					\
	constexpr const _XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL) ::IdentifierPool \
		_XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL) ::identifierPool = {	\

/**
 * Callback worker for _XENUM4_DEFINE_CNTNR_IDENTPOOL().
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_IDENTPOOL_MEMBER(CTXT, VALUEIDENT, ...)				\
IND1	#VALUEIDENT,										NWLN

/**
 * Callback worker for _XENUM4_DEFINE_CNTNR_IDENTPOOL().
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_IDENTPOOL_OFFSETS_BEGIN(CTXT, DECL)				\
	constexpr const _XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL)::IdentifierOffset \
		_XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL)			\
		::identifierOffsets[_XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL)::size]  = { \

/**
 * Callback worker for _XENUM4_DEFINE_CNTNR_IDENTPOOL().
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_IDENTPOOL_OFFSETS_MEMBER(CTXT, VALUEIDENT, ...)			\
IND1	_XENUM4_DEFINE_CNTNR_IDENTPOOL_OFFSETS_MEMBER_BEGIN(CTXT, _XENUM4_CTXT_GET_DECL(CTXT))	\
		->VALUEIDENT,	NWLN

/**
 * Callback worker for _XENUM4_DEFINE_CNTNR_IDENTPOOL_OFFSETS_MEMBER().
 * @hideinitializer
 */
#define _XENUM4_DEFINE_CNTNR_IDENTPOOL_OFFSETS_MEMBER_BEGIN(CTXT, DECL)				\
	(intptr_t)&((_XENUM4_DECL_GET_SCOPE(DECL) _XENUM4_DECL_GET_CNTNRNAME(DECL) ::IdentifierPool*)0)


#endif // _XENUM4_IMPL_DEFINE_CNTNR_HPP
