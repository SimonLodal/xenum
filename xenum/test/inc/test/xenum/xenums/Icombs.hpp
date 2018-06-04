/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Xenums for testing all combinations of identifier feature options.
 * - getIdentifier() implementation: off, ext, inl(?), cxp
 * - fromIdentifier() implementation: off, ext, inl, cxp
 * These have different code paths in the generators so it is important to test them all.
 */
#ifndef TEST_XENUM_XENUMS_ICOMBS_HPP
#define TEST_XENUM_XENUMS_ICOMBS_HPP

#include <cstdint>
#include <xenum5/Xenum.hpp>


// Flags to turn each Icombs xenum on/off, while developing.
#define XENUM5_TEST_IdentOffOff	0
#define XENUM5_TEST_IdentOffExt	0
#define XENUM5_TEST_IdentOffInl	0
#define XENUM5_TEST_IdentOffCxp	0
#define XENUM5_TEST_IdentExtOff	0
#define XENUM5_TEST_IdentExtExt	1
#define XENUM5_TEST_IdentExtInl	1
#define XENUM5_TEST_IdentExtCxp	1
#define XENUM5_TEST_IdentCxpOff	0
#define XENUM5_TEST_IdentCxpExt	1
#define XENUM5_TEST_IdentCxpInl	1
#define XENUM5_TEST_IdentCxpCxp	1


namespace test {
namespace xenum {
namespace xenums {

#if XENUM5_TEST_IdentOffOff
/// Namespace for testing identifier implementation options (off, off)
namespace IdentOffOff {
/// Xenum with identifier features: getIdentifier=off, fromIdentifier=off
#define XENUM5_IdentOffOff(D,V,C)		\
	D(C, test::xenum::xenums::IdentOffOff::,\
	  Icombs, Icomb, , (off, off))		\
	V(C, OffOff0) V(C, OffOff1) V(C, OffOff2)
XENUM5_DECLARE(IdentOffOff)
}
#endif

#if XENUM5_TEST_IdentOffExt
/// Namespace for testing identifier implementation options (off, ext)
namespace IdentOffExt {
/// Xenum with identifier features: getIdentifier=off, fromIdentifier=ext
#define XENUM5_IdentOffExt(D,V,C)		\
	D(C, test::xenum::xenums::IdentOffExt::,\
	  Icombs, Icomb, , (off, ext))		\
	V(C, OffExt0) V(C, OffExt1) V(C, OffExt2)
XENUM5_DECLARE(IdentOffExt)
}
#endif

#if XENUM5_TEST_IdentOffInl
/// Namespace for testing identifier implementation options (off, inl)
namespace IdentOffInl {
/// Xenum with identifier features: getIdentifier=off, fromIdentifier=inl
#define XENUM5_IdentOffInl(D,V,C)		\
	D(C, test::xenum::xenums::IdentOffInl::,\
	  Icombs, Icomb, , (off, inl))		\
	V(C, OffInl0) V(C, OffInl1) V(C, OffInl2)
XENUM5_DECLARE(IdentOffInl)
}
#endif

#if XENUM5_TEST_IdentOffCxp
/// Namespace for testing identifier implementation options (off, cxp)
namespace IdentOffCxp {
/// Xenum with identifier features: getIdentifier=off, fromIdentifier=cxp
#define XENUM5_IdentOffCxp(D,V,C)		\
	D(C, test::xenum::xenums::IdentOffCxp::,\
	  Icombs, Icomb, , (off, cxp))		\
	V(C, OffCxp0) V(C, OffCxp1) V(C, OffCxp2)
XENUM5_DECLARE(IdentOffCxp)
}
#endif


#if XENUM5_TEST_IdentExtOff
/// Namespace for testing identifier implementation options (ext, off)
namespace IdentExtOff {
/// Xenum with identifier features: getIdentifier=ext, fromIdentifier=off
#define XENUM5_IdentExtOff(D,V,C)		\
	D(C, test::xenum::xenums::IdentExtOff::,\
	  Icombs, Icomb, , (ext, off))		\
	V(C, ExtOff0) V(C, ExtOff1) V(C, ExtOff2)
XENUM5_DECLARE(IdentExtOff)
}
#endif

#if XENUM5_TEST_IdentExtExt
/// Namespace for testing identifier implementation options (ext, ext)
namespace IdentExtExt {
/// Xenum with identifier features: getIdentifier=ext, fromIdentifier=ext
#define XENUM5_IdentExtExt(D,V,C)		\
	D(C, test::xenum::xenums::IdentExtExt::,\
	  Icombs, Icomb, , (ext, ext))		\
	V(C, ExtExt0) V(C, ExtExt1) V(C, ExtExt2)
XENUM5_DECLARE(IdentExtExt)
}
#endif

#if XENUM5_TEST_IdentExtInl
/// Namespace for testing identifier implementation options (ext, inl)
namespace IdentExtInl {
/// Xenum with identifier features: getIdentifier=ext, fromIdentifier=inl
#define XENUM5_IdentExtInl(D,V,C)		\
	D(C, test::xenum::xenums::IdentExtInl::,\
	  Icombs, Icomb, , (ext, inl))		\
	V(C, ExtInl0) V(C, ExtInl1) V(C, ExtInl2)
XENUM5_DECLARE(IdentExtInl)
}
#endif

#if XENUM5_TEST_IdentExtCxp
/// Namespace for testing identifier implementation options (ext, cxp)
namespace IdentExtCxp {
/// Xenum with identifier features: getIdentifier=ext, fromIdentifier=cxp
#define XENUM5_IdentExtCxp(D,V,C)		\
	D(C, test::xenum::xenums::IdentExtCxp::,\
	  Icombs, Icomb, , (ext, cxp))		\
	V(C, ExtCxp0) V(C, ExtCxp1) V(C, ExtCxp2)
XENUM5_DECLARE(IdentExtCxp)
}
#endif


#if XENUM5_TEST_IdentCxpOff
/// Namespace for testing identifier implementation options (cxp, off)
namespace IdentCxpOff {
/// Xenum with identifier features: getIdentifier=cxp, fromIdentifier=off
#define XENUM5_IdentCxpOff(D,V,C)		\
	D(C, test::xenum::xenums::IdentCxpOff::,\
	  Icombs, Icomb, , (cxp, off))		\
	V(C, CxpOff0) V(C, CxpOff1) V(C, CxpOff2)
XENUM5_DECLARE(IdentCxpOff)
}
#endif

#if XENUM5_TEST_IdentCxpExt
/// Namespace for testing identifier implementation options (cxp, ext)
namespace IdentCxpExt {
/// Xenum with identifier features: getIdentifier=cxp, fromIdentifier=ext
#define XENUM5_IdentCxpExt(D,V,C)		\
	D(C, test::xenum::xenums::IdentCxpExt::,\
	  Icombs, Icomb, , (cxp, ext))		\
	V(C, CxpExt0) V(C, CxpExt1) V(C, CxpExt2)
XENUM5_DECLARE(IdentCxpExt)
}
#endif

#if XENUM5_TEST_IdentCxpInl
/// Namespace for testing identifier implementation options (cxp, inl)
namespace IdentCxpInl {
/// Xenum with identifier features: getIdentifier=cxp, fromIdentifier=inl
#define XENUM5_IdentCxpInl(D,V,C)		\
	D(C, test::xenum::xenums::IdentCxpInl::,\
	  Icombs, Icomb, , (cxp, inl))		\
	V(C, CxpInl0) V(C, CxpInl1) V(C, CxpInl2)
XENUM5_DECLARE(IdentCxpInl)
}
#endif

#if XENUM5_TEST_IdentCxpCxp
/// Namespace for testing identifier implementation options (cxp, cxp)
namespace IdentCxpCxp {
/// Xenum with identifier features: getIdentifier=cxp, fromIdentifier=cxp
#define XENUM5_IdentCxpCxp(D,V,C)		\
	D(C, test::xenum::xenums::IdentCxpCxp::,\
	  Icombs, Icomb, , (cxp, cxp))		\
	V(C, CxpCxp0) V(C, CxpCxp1) V(C, CxpCxp2)
XENUM5_DECLARE(IdentCxpCxp)
}
#endif


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_ICOMBS_HPP
