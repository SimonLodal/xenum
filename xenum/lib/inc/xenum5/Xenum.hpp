/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 * @version 5.2
 */
#ifndef _XENUM5_XENUM_HPP
#define _XENUM5_XENUM_HPP

/// Major version
#define XENUM5_VER_MAJOR	5
/// Minor version
#define XENUM5_VER_MINOR	2
/// Micro/patch/pre version
#define XENUM5_VER_PATCH	

/// Namespace that Xenum lives in.
/// Note that most of Xenum is macros that ignore namespaces anyway.
#define _XENUM5_NS xenum5

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

#include <xenum5/impl/Debug.hpp>
#include <xenum5/impl/Util.hpp>
#include <xenum5/impl/SelectInt.hpp>
#include <xenum5/impl/XenumCntnrIterator.hpp>
#include <xenum5/impl/XenumValue.hpp>
#include <xenum5/impl/TupleTree.hpp>
#include <xenum5/impl/Xdcl.hpp>
#include <xenum5/impl/PropDef.hpp>
#include <xenum5/impl/Ctxt.hpp>
#include <xenum5/impl/IndexNode.hpp>
#include <xenum5/impl/PropOwner.hpp>
#include <xenum5/impl/Ident.hpp>
#include <xenum5/impl/Props.hpp>
#include <xenum5/impl/Plain.hpp>
#include <xenum5/impl/Cstring.hpp>
#include <xenum5/impl/Store.hpp>
#include <xenum5/impl/Value.hpp>
#include <xenum5/impl/Cntnr.hpp>
#include <xenum5/impl/Main.hpp>


/**
 * Generate the header parts (declarations) of an Xenum.
 * @param SUFFIX Suffix of your xenum declaration macros.
 */
#define XENUM5_DECLARE(SUFFIX)									\
	_XENUM5_MARK(declare begin SUFFIX)							\
	_XENUM5_MAIN_DECLARE(SUFFIX)								\
	_XENUM5_MARK(declare end SUFFIX)							\

/**
 * Generate the source parts (definitions) of an Xenum.
 * @param SUFFIX Suffix of your xenum declaration macros.
 */
#define XENUM5_DEFINE(SUFFIX)									\
	_XENUM5_MARK(define begin SUFFIX)							\
	_XENUM5_MAIN_DEFINE(SUFFIX)								\
	_XENUM5_MARK(define end SUFFIX)								\


/// Print an XenumValue.
template<class XenumStore>
inline std::ostream& operator<<(std::ostream& out, ::_XENUM5_NS::XenumValue<XenumStore,1> enumValue) {
	return out << enumValue.getIdentifier();
}
/// Print an XenumValue.
template<class XenumStore>
inline std::ostream& operator<<(std::ostream& out, ::_XENUM5_NS::XenumValue<XenumStore,2> enumValue) {
	return out << enumValue.getIdentifier();
}


#endif // _XENUM5_XENUM_HPP
