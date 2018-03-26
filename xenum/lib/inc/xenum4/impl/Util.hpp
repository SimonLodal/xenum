/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM4_IMPL_UTIL_HPP
#define _XENUM4_IMPL_UTIL_HPP

namespace xenum4 {


// ===================================================================================================
#if XENUM_DEBUG_PP
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
#endif


// ===================================================================================================
/**
 * Report an error. This is tricky since we have no stderr channel, and sometimes not even a
 * stdout; any output from a macro may be gobbled up and discarded by the caller. So this only
 * works when all output eventually ends up as C++ output code.
 *
 * The goals are:
 * - Produce some output that is searchable (when you only preprocess the source).
 * - Make sure that the code can not compile.
 *
 * So we wrap the error message in a static_assert(). If the preprocessor does not fail on this
 * data, then at least the compiler will fail later. And it is somewhat searchable, together with
 * the "Xenum4 error" prefix.
 * @param LOC String describing data location, to help user figure out where the error happened.
 * @param MSG The error message.
 * @hideinitializer
 */
#define _XENUM4_ERROR(LOC, MSG)									\
	static_assert(false, BOOST_PP_STRINGIZE(Xenum4 error (LOC): MSG));


// ===================================================================================================
/// Can be used for unwanted _XENUM4_EXEC_COND branch.
#define _XENUM4_NOOP()
/// Can be used for unwanted _XENUM4_EXEC_COND branch.
#define _XENUM4_ECHO(msg) msg


// ===================================================================================================
/// Helper for _XENUM4_EXEC_IF*(): Executes if condition is true. Executes macro with args.
/// @hideinitializer
#define _XENUM4_EXEC_IF_1(MACRO, ...) MACRO(__VA_ARGS__)
/// Helper for _XENUM4_EXEC_IF*(): Executes if condition is false. Does nothing, returns empty.
/// @hideinitializer
#define _XENUM4_EXEC_IF_0(MACRO, ...)
/// Generic utility function: Execute MACRO with args if first arg is non-empty, else do nothing.
/// @hideinitializer
#define _XENUM4_EXEC_IF_NONEMPTY(MACRO, ...)							\
	BOOST_PP_CAT(										\
		_XENUM4_EXEC_IF_,								\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(BOOST_PP_VARIADIC_ELEM(0, __VA_ARGS__)))		\
	) (MACRO, __VA_ARGS__)


// ===================================================================================================
/**
 * Generic utility function: Execute a macro+args if first arg is true, or another if false.
 * The problem is that if you just use BOOST_PP_IF, it tends to execute both, and just ignore
 * the false path. The problem is that the preprocessor will spew errors from both, and it is
 * pretty common to have a false branch that would throw an error if executed, after all that
 * is why you make it conditional.
 * Anyway this function makes sure that only the true branch is executed.
 * Not reentrant so copy/paste if nesting.
 * @param COND The condition variable, must be 1 or 0.
 * @param ... Commands to execute if COND is true or false respectively.
 * Each command is defined as a tuple, where the first field is the name of the macro to
 * execute, and all remaining value are passed as parameters to that macro when executed.
 * @hideinitializer
 */
#define _XENUM4_EXEC_COND(COND, ...)								\
	BOOST_PP_CAT(_XENUM4_EXEC_COND_, COND)							\
	(BOOST_PP_TUPLE_ENUM(BOOST_PP_VARIADIC_ELEM(BOOST_PP_NOT(COND), __VA_ARGS__)))

/// Helper for _XENUM4_EXEC_COND().
/// @hideinitializer
#define _XENUM4_EXEC_COND_0(...)		_XENUM4_EXEC_COND_DO(__VA_ARGS__)
/// Helper for _XENUM4_EXEC_COND().
/// @hideinitializer
#define _XENUM4_EXEC_COND_1(...)		_XENUM4_EXEC_COND_DO(__VA_ARGS__)
/// Helper for _XENUM4_EXEC_COND().
/// @hideinitializer
#define _XENUM4_EXEC_COND_DO(MACRO, ...)	MACRO(__VA_ARGS__)


// ===================================================================================================
/**
 * @return Size of tuple, or zero if the parameter empty.
 * @hideinitializer
 */
#define _XENUM4_GET_TUPLE_OR_EMPTY_SIZE(DATA)							\
	BOOST_PP_CAT(_XENUM4_GET_TUPLE_OR_EMPTY_SIZE_, BOOST_PP_NOT(BOOST_PP_IS_EMPTY(DATA))) (DATA)

/**
 * Worker for _XENUM4_GET_TUPLE_OR_EMPTY_SIZE().
 * @hideinitializer
 */
#define _XENUM4_GET_TUPLE_OR_EMPTY_SIZE_0(DATA)							\
	0

/**
 * Worker for _XENUM4_GET_TUPLE_OR_EMPTY_SIZE().
 * @hideinitializer
 */
#define _XENUM4_GET_TUPLE_OR_EMPTY_SIZE_1(DATA)							\
	BOOST_PP_TUPLE_SIZE(TUPLE)


// ===================================================================================================
/**
 * @return Size of seq, or zero if the parameter empty.
 * @hideinitializer
 */
#define _XENUM4_GET_SEQ_OR_EMPTY_SIZE(DATA)							\
	BOOST_PP_CAT(_XENUM4_GET_SEQ_OR_EMPTY_SIZE_, BOOST_PP_NOT(BOOST_PP_IS_EMPTY(DATA))) (DATA)

/**
 * Worker for _XENUM4_GET_SEQ_OR_EMPTY_SIZE().
 * @hideinitializer
 */
#define _XENUM4_GET_SEQ_OR_EMPTY_SIZE_0(DATA)							\
	0

/**
 * Worker for _XENUM4_GET_SEQ_OR_EMPTY_SIZE().
 * @hideinitializer
 */
#define _XENUM4_GET_SEQ_OR_EMPTY_SIZE_1(DATA)							\
	BOOST_PP_SEQ_SIZE(DATA)


// ===================================================================================================
/**
 * @return Size of tuple, if data looks like it might actually be a tuple, else zero.
 * @hideinitializer
 */
#define _XENUM4_GET_TUPLE_SIZE_IF_TUPLE(DATA)							\
	BOOST_PP_CAT(_XENUM4_GET_TUPLE_SIZE_IF_TUPLE_, BOOST_PP_IS_BEGIN_PARENS(DATA)) (DATA)

/**
 * Worker for _XENUM4_GET_TUPLE_SIZE_IF_TUPLE().
 * @hideinitializer
 */
#define _XENUM4_GET_TUPLE_SIZE_IF_TUPLE_0(DATA)							\
	0

/**
 * Worker for _XENUM4_GET_TUPLE_SIZE_IF_TUPLE().
 * @hideinitializer
 */
#define _XENUM4_GET_TUPLE_SIZE_IF_TUPLE_1(DATA)							\
	BOOST_PP_TUPLE_SIZE(DATA)


// ===================================================================================================
/**
 * @return Tuple converted to seq, if data looks like it might be a tuple, else just the data
 *	itself.
 * @hideinitializer
 */
#define _XENUM4_TUPLE_TO_SEQ_IF_TUPLE(DATA)							\
	BOOST_PP_CAT(_XENUM4_TUPLE_TO_SEQ_IF_TUPLE_, BOOST_PP_IS_BEGIN_PARENS(DATA)) (DATA)

/**
 * Worker for _XENUM4_TUPLE_TO_SEQ_IF_TUPLE().
 * @hideinitializer
 */
#define _XENUM4_TUPLE_TO_SEQ_IF_TUPLE_0(DATA)							\
	DATA

/**
 * Worker for _XENUM4_TUPLE_TO_SEQ_IF_TUPLE().
 * @hideinitializer
 */
#define _XENUM4_TUPLE_TO_SEQ_IF_TUPLE_1(DATA)							\
	BOOST_PP_TUPLE_TO_SEQ(DATA)


// ===================================================================================================
/**
 * @return Tuple converted to seq, if data looks like it might actually be a tuple,
 *	and COND is true; else just the data itself.
 * @hideinitializer
 */
#define _XENUM4_TUPLE_TO_SEQ_COND(DATA, COND)							\
	BOOST_PP_CAT(										\
		_XENUM4_TUPLE_TO_SEQ_COND_,							\
		BOOST_PP_AND(COND, BOOST_PP_IS_BEGIN_PARENS(DATA))				\
	) (DATA)

/**
 * Worker for _XENUM4_TUPLE_TO_SEQ_COND().
 * @hideinitializer
 */
#define _XENUM4_TUPLE_TO_SEQ_COND_0(DATA)							\
	DATA

/**
 * Worker for _XENUM4_TUPLE_TO_SEQ_COND().
 * @hideinitializer
 */
#define _XENUM4_TUPLE_TO_SEQ_COND_1(DATA)							\
	BOOST_PP_TUPLE_TO_SEQ(DATA)


// ===================================================================================================
/**
 * Common helper to return the N'th vararg, if it is defined.
 * @hideinitializer
 */
#define _XENUM4_GET_VARARG(N, ...)								\
	BOOST_PP_IF(BOOST_PP_GREATER(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), N),			\
		    BOOST_PP_VARIADIC_ELEM(N,__VA_ARGS__),					\
		    )										\

/**
 * Callback helper for generation of .size.
 */
#define _XENUM4_ADD_ONE(...) +1


/**
 * Common helper to call the XENUM_VALS_${suffix} macro.
 * @param CALLBACK Callback macro to make the XENUM_VALS_${suffix} macro call.
 * @param CTXT Context object to pass around. Must contain at least the SUFFIX field.
 */
#define _XENUM4_CALL_VALS(CALLBACK, CTXT)							\
	BOOST_PP_CAT(XENUM_VALS_, _XENUM4_CTXT_GET_SUFFIX(CTXT)) (CALLBACK, CTXT)


// ===================================================================================================
/**
 * Integer max() function that is constexpr.
 * std::max is constexpr in c++14, but we are still targeting c++11 where it is not.
 */
template <class T>
constexpr const T& cmax (const T& a, const T& b)
{
	return (a>b) ? a : b;
}


} // namespace xenum4
#endif // _XENUM4_IMPL_UTIL_HPP
