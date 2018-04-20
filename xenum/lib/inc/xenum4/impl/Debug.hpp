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


#if XENUM4_DEBUG_PP
/// In debug mode, inserts a newline. Else empty.
#define _XENUM4_NWLN @XENUM4-NWLN@
/// Increase global indentation level.
#define _XENUM4_INDENT_INC @XENUM4-INDENT-G:+1@
/// Decrease global indentation level.
#define _XENUM4_INDENT_DEC @XENUM4-INDENT-G:-1@
/// Increase local indentation level (for current line only).
#define _XENUM4_INDENT_ADD @XENUM4-INDENT-L:+1@
/// Decrease local indentation level (for current line only).
#define _XENUM4_INDENT_SUB @XENUM4-INDENT-L:-1@
/// In debug mode, prints the text as a comment. Else empty.
#define _XENUM4_CMNT(...) @XENUM4-CMNT-BEG: __VA_ARGS__ XENUM4-CMNT-END@
/// In debug mode, prints the text as a documentation comment. Else empty.
#define _XENUM4_DOC(...) @XENUM4-DOC-BEG: __VA_ARGS__ XENUM4-DOC-END@
/// In debug mode, prints the text as a marker. Else empty.
#define _XENUM4_MARK(TXT) @XENUM4-MARK:TXT@
#else
/// In debug mode, inserts a newline. Else empty.
#define _XENUM4_NWLN
/// Increase global indentation level.
#define _XENUM4_INDENT_INC
/// Decrease global indentation level.
#define _XENUM4_INDENT_DEC
/// Increase local indentation level (for current line only).
#define _XENUM4_INDENT_ADD
/// Decrease local indentation level (for current line only).
#define _XENUM4_INDENT_SUB
/// In debug mode, prints the text as a comment. Else empty.
#define _XENUM4_CMNT(...)
/// In debug mode, prints the text as a documentation comment. Else empty.
#define _XENUM4_DOC(...)
/// In debug mode, prints the text as a marker. Else empty.
#define _XENUM4_MARK(...)
#endif


#endif // _XENUM4_IMPL_DEBUG_HPP
