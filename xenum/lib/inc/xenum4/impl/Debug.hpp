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


#ifdef _XENUM4_NWLN
#	error Macro '_XENUM4_NWLN' already defined.
#endif
#ifdef _XENUM4_IND1
#	error Macro '_XENUM4_IND1' already defined.
#endif
#ifdef _XENUM4_IND2
#	error Macro '_XENUM4_IND2' already defined.
#endif
#ifdef _XENUM4_IND3
#	error Macro '_XENUM4_IND3' already defined.
#endif
#ifdef _XENUM4_IND4
#	error Macro '_XENUM4_IND4' already defined.
#endif
#ifdef _XENUM4_CMNT
#	error Macro '_XENUM4_CMNT' already defined.
#endif
#ifdef _XENUM4_MARK
#	error Macro '_XENUM4_MARK' already defined.
#endif


#if XENUM4_DEBUG_PP
/// In debug mode, inserts a newline. Else empty.
#define _XENUM4_NWLN @XENUM4-NWLN@
/// In debug mode, inserts a single indentation level. Else empty.
#define _XENUM4_IND1 @XENUM4-IND:1@
/// In debug mode, inserts two indentation levels. Else empty.
#define _XENUM4_IND2 @XENUM4-IND:2@
/// In debug mode, inserts three indentation levels. Else empty.
#define _XENUM4_IND3 @XENUM4-IND:3@
/// In debug mode, inserts three indentation levels. Else empty.
#define _XENUM4_IND4 @XENUM4-IND:4@
/// In debug mode, prints the text as a comment. Else empty.
#define _XENUM4_CMNT(TXT) @XENUM4-CMNT:TXT@ _XENUM4_NWLN
/// In debug mode, prints the text as a marker. Else empty.
#define _XENUM4_MARK(TXT) @XENUM4-MARK:TXT@
#else
/// In debug mode, inserts a newline. Else empty.
#define _XENUM4_NWLN 
/// In debug mode, inserts a single indentation level. Else empty.
#define _XENUM4_IND1 
/// In debug mode, inserts two indentation levels. Else empty.
#define _XENUM4_IND2 
/// In debug mode, inserts three indentation levels. Else empty.
#define _XENUM4_IND3 
/// In debug mode, inserts three indentation levels. Else empty.
#define _XENUM4_IND4 
/// In debug mode, prints the text as a comment. Else empty.
#define _XENUM4_CMNT(TXT) 
/// In debug mode, prints the text as a marker. Else empty.
#define _XENUM4_MARK(TXT) 
#endif



#endif // _XENUM4_IMPL_DEBUG_HPP
