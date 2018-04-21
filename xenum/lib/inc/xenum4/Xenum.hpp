/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 * @version 4.1-pre1
 */
#ifndef _XENUM4_XENUM_HPP
#define _XENUM4_XENUM_HPP

/// Namespace that Xenum lives in.
/// Note that most of Xenum is macros that ignore namespaces anyway.
#define _XENUM4_NS xenum4

//#include <cstdint>
#include <iostream>
// For SelectInt
#include <type_traits>
// For DeclareCntnr, DefineCntnr
#include <stdexcept>
// For ?
#include <cstring>
// For offsetof()
#include <cstddef>
// For all generators
#include <boost/preprocessor.hpp>
#include <boost/preprocessor/facilities/is_empty.hpp>

#include <xenum4/impl/Debug.hpp>
#include <xenum4/impl/Util.hpp>
#include <xenum4/impl/SelectInt.hpp>
#include <xenum4/impl/XenumCntnrIterator.hpp>
#include <xenum4/impl/XenumValue.hpp>
#include <xenum4/impl/TupleTree.hpp>
#include <xenum4/impl/Decl.hpp>
#include <xenum4/impl/PropDef.hpp>
#include <xenum4/impl/Ctxt.hpp>
#include <xenum4/impl/IndexNode.hpp>
#include <xenum4/impl/Props.hpp>
#include <xenum4/impl/Plain.hpp>
#include <xenum4/impl/PlainDeclStore.hpp>
#include <xenum4/impl/PlainDeclValue.hpp>
#include <xenum4/impl/PlainDefine.hpp>
#include <xenum4/impl/Cstring.hpp>
#include <xenum4/impl/CstringDeclStore.hpp>
#include <xenum4/impl/CstringDeclValue.hpp>
#include <xenum4/impl/CstringDefine.hpp>
#include <xenum4/impl/DeclareStore.hpp>
#include <xenum4/impl/DeclareCntnr.hpp>
#include <xenum4/impl/DeclareValue.hpp>
#include <xenum4/impl/DefineStore.hpp>
#include <xenum4/impl/DefineCntnr.hpp>
#include <xenum4/impl/Main.hpp>


/**
 * Generate the header parts (declarations) of an Xenum.
 * @param SUFFIX Suffix of your xenum declaration macros.
 */
#define XENUM4_DECLARE(SUFFIX)									\
	_XENUM4_MARK(declare begin SUFFIX)							\
	_XENUM4_DO_DECLARE(_XENUM4_CTXT_INIT(SUFFIX))						\
	_XENUM4_MARK(declare end SUFFIX)							\

/**
 * Generate the source parts (definitions) of an Xenum.
 * @param SUFFIX Suffix of your xenum declaration macros.
 */
#define XENUM4_DEFINE(SUFFIX)									\
	_XENUM4_MARK(define begin SUFFIX)							\
	_XENUM4_DO_DEFINE(_XENUM4_CTXT_INIT(SUFFIX))						\
	_XENUM4_MARK(define end SUFFIX)								\


/// Print an XenumValue.
template<class XenumStore>
inline std::ostream& operator<<(std::ostream& out, ::_XENUM4_NS::XenumValue<XenumStore> enumValue) {
	return out << enumValue.getIdentifier();
}


#endif // _XENUM4_XENUM_HPP
