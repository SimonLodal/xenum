/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * These macros insert various markers in the output. They cause the output to become
 * invalid C++. The markers are supposed to be processed/replaced by another tool,
 * which may turn it back into valid C++ syntax.
 */
#ifndef _XENUM4_IMPL_DEBUG_HPP
#define _XENUM4_IMPL_DEBUG_HPP

#ifdef NWLN
#	error Macro 'NWLN' already defined.
#endif
#ifdef IND1
#	error Macro 'IND1' already defined.
#endif
#ifdef IND2
#	error Macro 'IND2' already defined.
#endif
#ifdef IND3
#	error Macro 'IND3' already defined.
#endif
#ifdef IND4
#	error Macro 'IND4' already defined.
#endif
#ifdef CMNT
#	error Macro 'CMNT' already defined.
#endif
#ifdef _XENUM4_MARK
#	error Macro '_XENUM4_MARK' already defined.
#endif


#if XENUM4_DEBUG_PP
/// In debug mode, inserts a newline. Else empty.
#define NWLN @\n@
/// In debug mode, inserts a single indentation level. Else empty.
#define IND1 @\t@
/// In debug mode, inserts two indentation levels. Else empty.
#define IND2 @\t\t@
/// In debug mode, inserts three indentation levels. Else empty.
#define IND3 @\t\t\t@
/// In debug mode, inserts three indentation levels. Else empty.
#define IND4 @\t\t\t\t@
/// In debug mode, prints the text as a comment. Else empty.
#define CMNT(TXT) @XENUM4-CMNT:TXT@ NWLN
/// In debug mode, prints the text as a marker. Else empty.
#define _XENUM4_MARK(TXT) @XENUM4-MARK:TXT@ NWLN
#else
/// In debug mode, inserts a newline. Else empty.
#define NWLN 
/// In debug mode, inserts a single indentation level. Else empty.
#define IND1 
/// In debug mode, inserts two indentation levels. Else empty.
#define IND2 
/// In debug mode, inserts three indentation levels. Else empty.
#define IND3 
/// In debug mode, inserts three indentation levels. Else empty.
#define IND4 
/// In debug mode, prints the text as a comment. Else empty.
#define CMNT(TXT) 
/// In debug mode, prints the text as a marker. Else empty.
#define _XENUM4_MARK(TXT) 
#endif



#endif // _XENUM4_IMPL_DEBUG_HPP
