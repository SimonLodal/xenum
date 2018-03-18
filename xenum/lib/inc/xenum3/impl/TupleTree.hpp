/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 *
 * Macros to iterate a hierarchical data structure (a tree) of tuples.
 *
 * Iteration is done using a stack that is incremented by an exiting function,
 * so while the stack describes a recursing operation, there is no corresponding
 * function recursion (except inside boost_pp).
 */
#ifndef _XENUM3_IMPL_TUPLETREE_HPP
#define _XENUM3_IMPL_TUPLETREE_HPP


/// =============================================================================================
/// ITERPOS objects describes the current position in the data tree.
/// =============================================================================================
/**
 * @return Current level in the data structure. Goes in reverse (decreases); the root node
 *	has level=$DEPTH, it children have level=$DEPTH-1, and so on. Leaf values are level 0.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS) BOOST_PP_SEQ_ELEM(0, ITERPOS)

/**
 * Set LEVEL field and return new iterpos object.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_SET_LEVEL(ITERPOS, LEVEL) BOOST_PP_SEQ_REPLACE(ITERPOS, 0, LEVEL)

/**
 * @return Path through the data tree to the current node, as a seq of indexes.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS) BOOST_PP_SEQ_ELEM(1, ITERPOS)

/**
 * Set INDEXPATH field and return new iterpos object.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_SET_INDEXPATH(ITERPOS, INDEXPATH) BOOST_PP_SEQ_REPLACE(ITERPOS, 1, INDEXPATH)

/**
 * @return Index of next child of this node.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_GET_NEXTCHILD(ITERPOS) BOOST_PP_SEQ_ELEM(2, ITERPOS)

/**
 * Set NEXTCHILD field and return new iterpos object.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_SET_NEXTCHILD(ITERPOS, NEXTCHILD) BOOST_PP_SEQ_REPLACE(ITERPOS, 2, NEXTCHILD)

/**
 * @return Number of child nodes in the original data structure (does not change as .NODE is
 *	processed and elements removed from it).
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS) BOOST_PP_SEQ_ELEM(3, ITERPOS)

/**
 * Create a new iteration-position "object".
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_INIT(LEVEL, INDEXPATH, NEXTCHILD, CHILDCOUNT)			\
	(LEVEL)											\
	(INDEXPATH)										\
	(NEXTCHILD)										\
	(CHILDCOUNT)										\

/**
 * DEBUG
 * Dump an ITERPOS object.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_DUMP(ITERPOS)							\
/*	iv=_XENUM3_TUPLETREE_ITERPOS_IS_VALUE(ITERPOS) */					\
	lv=_XENUM3_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS)						\
	ip(_XENUM3_GET_SEQ_OR_EMPTY_SIZE(_XENUM3_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS)))=_XENUM3_TUPLETREE_ITERPOS_DUMP_INDEXPATH(_XENUM3_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS))	\
	nc=_XENUM3_TUPLETREE_ITERPOS_GET_NEXTCHILD(ITERPOS)					\
	cc=_XENUM3_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS)					\

/**
 * DEBUG
 * Helper for _XENUM3_TUPLETREE_ITERPOS_DUMP().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_DUMP_INDEXPATH(INDEXPATH)					\
	[BOOST_PP_CAT(										\
		_XENUM3_TUPLETREE_ITERPOS_DUMP_INDEXPATH_,					\
		BOOST_PP_NOT(BOOST_PP_IS_EMPTY(INDEXPATH))					\
	) (INDEXPATH)]

/**
 * DEBUG
 * Helper for _XENUM3_TUPLETREE_ITERPOS_DUMP().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_DUMP_INDEXPATH_0(INDEXPATH)					\

/**
 * DEBUG
 * Helper for _XENUM3_TUPLETREE_ITERPOS_DUMP().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERPOS_DUMP_INDEXPATH_1(INDEXPATH)					\
	BOOST_PP_SEQ_ENUM(INDEXPATH)
/* Argh. fails.
	BOOST_PP_SEQ_FOLD_LEFT(_XENUM3_TUPLETREE_ITERPOS_DUMP_INDEXPATH_APPEND, , INDEXPATH)
*/

/**
 * DEBUG
 * Helper for _XENUM3_TUPLETREE_ITERPOS_DUMP().
 * @hideinitializer
 */
/*
#define _XENUM3_TUPLETREE_ITERPOS_DUMP_INDEXPATH_APPEND(S, STATE, ELEM)				\
	_XENUM3_ECHO(STATE)BOOST_PP_COMMA_IF(BOOST_PP_NOT(BOOST_PP_IS_EMPTY(STATE)))ELEM
*/

/// =============================================================================================
/// STACKENTRY : The element on the iteration stack.
/// =============================================================================================
/**
 * @return Path through the data tree to the current node, as a seq of indexes.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STACKENTRY_GET_INDEXPATH(STACKENTRY)					\
	_XENUM3_TUPLETREE_ITERPOS_GET_INDEXPATH(_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(STACKENTRY))

/**
 * @return Object describing current position in the data tree.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(STACKENTRY) BOOST_PP_SEQ_ELEM(0, STACKENTRY)

/**
 * @return Contents of this node in the data tree, as a seq (converted from tuple)
 *	of childnodes. Each time a childnode has been processed it is removed from the
 *	seq, so the seq ends up empty.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STACKENTRY_GET_NODE(STACKENTRY) BOOST_PP_SEQ_ELEM(1, STACKENTRY)

/**
 * Create a new stack entry "object".
 */
#define _XENUM3_TUPLETREE_STACKENTRY_INIT(ITERPOS, DATA)					\
	(ITERPOS)										\
	(DATA)											\

/**
 * DEBUG
 * Dump an STACKENTRY object.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STACKENTRY_DUMP(STACKENTRY)						\
	iterpos:{_XENUM3_TUPLETREE_ITERPOS_DUMP(_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(STACKENTRY))} \
	node=[_XENUM3_TUPLETREE_STACKENTRY_GET_NODE(STACKENTRY)]

/// =============================================================================================
/// STACK : Iteration is done using a stack.
/// =============================================================================================
/**
 * Create the initial stack.
 * @param DATA The data structure.
 * @param DEPTH Max depth of the data structure.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STACK_INIT(DATA, DEPTH)						\
	(_XENUM3_TUPLETREE_STACKENTRY_INIT(							\
		_XENUM3_TUPLETREE_ITERPOS_INIT(							\
			DEPTH,									\
			,									\
			0,									\
			_XENUM3_GET_TUPLE_SIZE_IF_TUPLE(DATA)					\
		),										\
		_XENUM3_TUPLE_TO_SEQ_IF_TUPLE(DATA)						\
	))

/**
 * DEBUG
 * Dump an STACK object.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STACK_DUMP(STACK)							\
	Stack(_XENUM3_GET_SEQ_OR_EMPTY_SIZE(STACK)):						NWLN \
	BOOST_PP_CAT(_XENUM3_TUPLETREE_STACK_DUMP_, BOOST_PP_NOT(BOOST_PP_IS_EMPTY(STACK))) (STACK)

/**
 * DEBUG
 * Helper for _XENUM3_TUPLETREE_STACK_DUMP().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STACK_DUMP_0(STACK)

/**
 * DEBUG
 * Helper for _XENUM3_TUPLETREE_STACK_DUMP().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STACK_DUMP_1(STACK)							\
	BOOST_PP_REPEAT(									\
		BOOST_PP_SEQ_SIZE(STACK),							\
		_XENUM3_TUPLETREE_STACK_DUMP_ENTRY,						\
		STACK										\
	)

/**
 * DEBUG
 * Helper for _XENUM3_TUPLETREE_STACK_DUMP_1().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STACK_DUMP_ENTRY(Z, N, STACK)						\
IND1	[N] _XENUM3_TUPLETREE_STACKENTRY_DUMP(BOOST_PP_SEQ_ELEM(N, STACK)) NWLN


/// =============================================================================================
/// STATE contains all the data used for iteration.
/// =============================================================================================
/**
 * @return Iteration stack.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_GET_STACK(ITERSTATE)						\
	BOOST_PP_SEQ_ELEM(0, ITERSTATE)

/**
 * @return Head of iteration stack.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_GET_STACKHEAD(ITERSTATE)					\
	BOOST_PP_SEQ_HEAD(_XENUM3_TUPLETREE_STATE_GET_STACK(ITERSTATE))

/**
 * Set the STACK field.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_SET_STACK(ITERSTATE, STACK)					\
	BOOST_PP_SEQ_REPLACE(ITERSTATE, 0, STACK)

/**
 * @return Name of callback function to be executed for each node in the data tree.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_GET_CALLBACK(ITERSTATE)						\
	BOOST_PP_TUPLE_ELEM(2, 0, BOOST_PP_SEQ_ELEM(1, ITERSTATE))

/**
 * @return Name of filter function to be executed for each node in the data tree.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_GET_FILTER(ITERSTATE)						\
	BOOST_PP_TUPLE_ELEM(2, 1, BOOST_PP_SEQ_ELEM(1, ITERSTATE))

/**
 * @return Caller-provided context object that is passed to callback function.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_GET_CTXT(ITERSTATE)						\
	BOOST_PP_SEQ_ELEM(2, ITERSTATE)

/**
 * @return Caller data store.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_GET_CDATA(ITERSTATE)						\
	BOOST_PP_SEQ_ELEM(3, ITERSTATE)

/**
 * Set caller data store.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_SET_CDATA(ITERSTATE, CDATA)					\
	BOOST_PP_SEQ_REPLACE(ITERSTATE, 3, CDATA)

/**
 * Set both the CDATA and STACK fields.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_SET_CDATA_AND_STACK(ITERSTATE, CDATA, STACK)			\
	BOOST_PP_SEQ_REPLACE(BOOST_PP_SEQ_REPLACE(ITERSTATE, 3, CDATA), 0, STACK)


/**
 * Filter function for iteration: Only trigger when entering a new node; do not trigger
 * on return from childnodes.
 * This is the default filtering function.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FILTER_NODE_ENTRY(ITERPOS, NODE, CTXT, ...)				\
	BOOST_PP_NOT(_XENUM3_TUPLETREE_ITERPOS_GET_NEXTCHILD(ITERPOS))

/**
 * Filter function for iteration: Only trigger on leaf values; ignore all the branch nodes in
 * the tree.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FILTER_LEAF(ITERPOS, NODE, CTXT, ...)					\
	BOOST_PP_NOT(_XENUM3_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS))

/**
 * Helper for _XENUM3_TUPLETREE_STATE_INIT().
 * Note: The reason why the FUNCS tuple is not just separate fields in the STATE seq is
 * that we want to apply a default filter function if not defined by caller, however, if
 * we just handle FILTER as a plain single parameter we need to check it with
 * BOOST_PP_IS_EMPTY, which fails when the argument is a macro name; it seems to insist
 * on trying to execute it.
 * So we need an alternative IS_EMPTY(), and the only method found to work is the one
 * used here; define a tuple of one or two functions, and decide if the FILTER function
 * is defined by checking tuple size.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_INIT_FUNCS(FUNCS)						\
	BOOST_PP_IF(										\
		BOOST_PP_EQUAL(1, BOOST_PP_TUPLE_SIZE(FUNCS)),					\
		BOOST_PP_TUPLE_PUSH_BACK(FUNCS, _XENUM3_TUPLETREE_FILTER_NODE_ENTRY),		\
		FUNCS										\
	)

/**
 * Create a new iteration-state "object".
 * @param DATA The data structure to iterate.
 * @param DEPTH Max depth of the data structure.
 * @param FUNCS Tuple of callback and optional filter functions.
 * @param CTXT Caller-provided context data that is passed to the callback function.
 * @param CDATA Caller data object.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_STATE_INIT(DATA, DEPTH, FUNCS, CTXT, CDATA)				\
	(_XENUM3_TUPLETREE_STACK_INIT(DATA, DEPTH))						\
	(_XENUM3_TUPLETREE_STATE_INIT_FUNCS(FUNCS))						\
	(CTXT)											\
	(CDATA)											\


/// =============================================================================================
/// Common iteration functions.
/// =============================================================================================
/**
 * Called by main loop to check if we should continue or stop.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_CMP(N, ITERSTATE)							\
	BOOST_PP_NOT(BOOST_PP_IS_EMPTY(_XENUM3_TUPLETREE_STATE_GET_STACK(ITERSTATE)))


/**
 * Called from OP/MACRO parts to increment the main loop.
 * @return New stack.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_INC(ITERSTATE)							\
	_XENUM3_TUPLETREE_DEPTH_INC_I1(								\
		ITERSTATE,									\
		_XENUM3_TUPLETREE_STATE_GET_STACK(ITERSTATE),					\
		_XENUM3_TUPLETREE_STATE_GET_STACKHEAD(ITERSTATE)				\
	)											\

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_INC().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_INC_I1(ITERSTATE, STACK, HEAD)					\
	BOOST_PP_CAT(										\
		_XENUM3_TUPLETREE_DEPTH_INC_I1_,						\
		_XENUM3_TUPLETREE_DEPTH_INC_STACKENTRY_DONE(_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(HEAD))	\
	) (ITERSTATE, STACK, HEAD)
/*
_TUPLETREE_DEPTH_INC_I1: head=_XENUM3_TUPLETREE_STACKENTRY_DUMP(HEAD) done=_XENUM3_TUPLETREE_DEPTH_INC_STACKENTRY_DONE(_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(HEAD)) NWLN \
*/

/**
 * Helper for _XENUM3_TUPLETREE_DEPTH_INC_I1().
 * Determine if this current stack entry has completed iterating it's children.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_INC_STACKENTRY_DONE(ITERPOS)					\
	BOOST_PP_OR(										\
		BOOST_PP_NOT(_XENUM3_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS)),			\
		BOOST_PP_EQUAL(									\
			_XENUM3_TUPLETREE_ITERPOS_GET_NEXTCHILD(ITERPOS),			\
			_XENUM3_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS)			\
		)										\
	)

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_INC_I1().
 * Not done with childnodes: Iterate to next child.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_INC_I1_0(ITERSTATE, STACK, HEAD)				\
	_XENUM3_TUPLETREE_DEPTH_INC_NEXT_CHILD(							\
		ITERSTATE,									\
		STACK,										\
		_XENUM3_TUPLETREE_STACKENTRY_GET_NODE(HEAD),					\
		_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(HEAD)					\
	)

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_INC_I1().
 * Done with childnodes: Return to parent so it can continue.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_INC_I1_1(ITERSTATE, STACK, HEAD)				\
	BOOST_PP_SEQ_POP_FRONT(STACK)
/*
_TUPLETREE_DEPTH_INC_I1_1: pop self NWLN \
*/
/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_INC_I1().
 * Push next child to the stack.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_INC_NEXT_CHILD(ITERSTATE, STACK, NODE, ITERPOS)			\
	_XENUM3_TUPLETREE_DEPTH_INC_NEXT_CHILD_I1(						\
		ITERSTATE,									\
		STACK,										\
		NODE,										\
		ITERPOS,									\
		_XENUM3_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS),					\
		_XENUM3_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS),				\
		_XENUM3_TUPLETREE_ITERPOS_GET_NEXTCHILD(ITERPOS),				\
		_XENUM3_TUPLETREE_ITERPOS_GET_CHILDCOUNT(ITERPOS)				\
	)

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_INC_NEXT_CHILD().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_INC_NEXT_CHILD_I1(ITERSTATE, STACK, NODE, ITERPOS,		\
						LEVEL, INDEXPATH, NEXTCHILD, CHILDCOUNT)	\
	BOOST_PP_SEQ_PUSH_FRONT(								\
		BOOST_PP_SEQ_PUSH_FRONT(							\
			BOOST_PP_SEQ_POP_FRONT(STACK),						\
			_XENUM3_TUPLETREE_STACKENTRY_INIT					\
			(									\
				_XENUM3_TUPLETREE_ITERPOS_SET_NEXTCHILD(			\
					ITERPOS,						\
					BOOST_PP_INC(NEXTCHILD)					\
				),								\
				BOOST_PP_SEQ_POP_FRONT(NODE)					\
			)									\
		),										\
		_XENUM3_TUPLETREE_STACKENTRY_INIT						\
		(										\
			_XENUM3_TUPLETREE_ITERPOS_INIT(						\
				BOOST_PP_DEC(LEVEL),						\
				BOOST_PP_SEQ_PUSH_BACK(INDEXPATH, NEXTCHILD),			\
				0,								\
				_XENUM3_GET_TUPLE_SIZE_IF_TUPLE(BOOST_PP_SEQ_HEAD(NODE))	\
			),									\
			_XENUM3_TUPLE_TO_SEQ_COND(BOOST_PP_SEQ_HEAD(NODE), BOOST_PP_BOOL(LEVEL))	\
		)										\
	)											\


/// =============================================================================================
/// Iteration functions for ITERATE_DEPTH_GEN().
/// =============================================================================================
/**
 * Called by main loop in every iteration. Calls supplied callback.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_GEN_EXEC(N, ITERSTATE)						\
	_XENUM3_TUPLETREE_DEPTH_GEN_EXEC_I1(ITERSTATE, _XENUM3_TUPLETREE_STATE_GET_STACKHEAD(ITERSTATE))
/*
_TUPLETREE_DEPTH_GEN_EXEC: n=N callback=_XENUM3_TUPLETREE_STATE_GET_CALLBACK(ITERSTATE) filter=_XENUM3_TUPLETREE_STATE_GET_FILTER(ITERSTATE) NWLN \
_TUPLETREE_DEPTH_GEN_EXEC: n=N stack=BOOST_PP_SEQ_SIZE(_XENUM3_TUPLETREE_STATE_GET_STACK(ITERSTATE)) \
*/

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_GEN_EXEC().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_GEN_EXEC_I1(ITERSTATE, HEAD)					\
	_XENUM3_TUPLETREE_DEPTH_GEN_EXEC_I2							\
	(											\
		ITERSTATE,									\
		_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(HEAD),					\
		_XENUM3_TUPLETREE_STACKENTRY_GET_NODE(HEAD),					\
		_XENUM3_TUPLETREE_STATE_GET_CTXT(ITERSTATE)					\
	)

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_GEN_EXEC_I1().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_GEN_EXEC_I2(ITERSTATE, ITERPOS, NODE, CTXT)			\
	BOOST_PP_CAT(										\
		_XENUM3_TUPLETREE_DEPTH_GEN_EXEC_,						\
		_XENUM3_TUPLETREE_STATE_GET_FILTER(ITERSTATE) (ITERPOS, NODE, CTXT)		\
	) (ITERSTATE, ITERPOS, NODE, CTXT)

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_GEN_EXEC_I2().
 * Do NOT execute callback since filter returned 0.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_GEN_EXEC_0(ITERSTATE, ITERPOS, NODE, CTXT)			\

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_GEN_EXEC_I2().
 * Do execute callback since filter returned 1.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_GEN_EXEC_1(ITERSTATE, ITERPOS, NODE, CTXT)			\
	_XENUM3_TUPLETREE_STATE_GET_CALLBACK(ITERSTATE) (ITERPOS, NODE, CTXT)

/**
 * Called by main loop to increment state.
 * @return New iterstate with new stack.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_GEN_INC(N, ITERSTATE)						\
	_XENUM3_TUPLETREE_STATE_SET_STACK							\
	(											\
		ITERSTATE,									\
		_XENUM3_TUPLETREE_DEPTH_INC(ITERSTATE)						\
	)


/// =============================================================================================
/// Iteration functions for ITERATE_FLAT_GEN().
/// =============================================================================================

// FIXME: Move debug stuff somewhere else.
/**
 * Debug helper.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DBG_NODE_NAME(ITERSTATE)						\
	[_XENUM3_CTXT_GET_IDENT(_XENUM3_TUPLETREE_STATE_GET_CTXT(ITERSTATE)			\
	),_XENUM3_PROPDEF_GET_NAME(								\
		_XENUM3_CTXT_GET_PROPDEF(							\
			_XENUM3_TUPLETREE_STATE_GET_CTXT(ITERSTATE)				\
		)										\
	)_XENUM3_TUPLETREE_DBG_NODE_NAME_INDEXPATH(						\
		_XENUM3_TUPLETREE_ITERPOS_GET_INDEXPATH(					\
			_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(				\
				_XENUM3_TUPLETREE_STATE_GET_STACKHEAD(ITERSTATE)		\
			)									\
		)										\
	)]

/**
 * Debug helper.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DBG_NODE_NAME_INDEXPATH(INDEXPATH)					\
	BOOST_PP_CAT(										\
		_XENUM3_TUPLETREE_DBG_NODE_NAME_INDEXPATH_,					\
		BOOST_PP_BOOL(BOOST_PP_SEQ_SIZE(INDEXPATH))					\
	) (INDEXPATH)

/**
 * Debug helper.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DBG_NODE_NAME_INDEXPATH_0(INDEXPATH)					\

/**
 * Debug helper.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DBG_NODE_NAME_INDEXPATH_1(INDEXPATH)					\
	, BOOST_PP_SEQ_ENUM(INDEXPATH)

// ============================================================
/**
 * Called by main loop in every iteration. Calls supplied callback.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES(R, ITERSTATE)				\
	_XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_I1(					\
		ITERSTATE,									\
		_XENUM3_TUPLETREE_STATE_GET_STACKHEAD(ITERSTATE)				\
	)
/*
_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES _XENUM3_TUPLETREE_DBG_NODE_NAME(ITERSTATE) NWLN
*/


/**
 * Worker for _XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_I1(ITERSTATE, HEAD)			\
	BOOST_PP_CAT(										\
		_XENUM3_TUPLETREE_FLAT_GEN_EXEC_ROOT_,						\
		BOOST_PP_EQUAL(1, BOOST_PP_SEQ_SIZE(_XENUM3_TUPLETREE_STATE_GET_STACK(ITERSTATE)))\
	) (ITERSTATE, HEAD)									\
	BOOST_PP_CAT(										\
		_XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_,					\
		/* Only iterate children when entering a node, and ignore leaf level */		\
		BOOST_PP_AND(									\
			BOOST_PP_BOOL(								\
				_XENUM3_TUPLETREE_ITERPOS_GET_LEVEL(				\
					_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(HEAD)		\
				)								\
			),									\
			BOOST_PP_NOT(								\
				_XENUM3_TUPLETREE_ITERPOS_GET_NEXTCHILD(			\
					_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(HEAD)		\
				)								\
			)									\
		)										\
	) (											\
		ITERSTATE,									\
		HEAD										\
	)

/**
 * Helper for _XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_I1().
 * Do nothing since this is not the root node.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_EXEC_ROOT_0(ITERSTATE, HEAD)					\

/**
 * Helper for _XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_I1().
 * Execute callback for the root node.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_EXEC_ROOT_1(ITERSTATE, HEAD)					\
	_XENUM3_TUPLETREE_DEPTH_GEN_EXEC_I1(ITERSTATE, HEAD)

/**
 * Worker for _XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_I1().
 * Do nothing since this is not the beginning of a node.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_0(ITERSTATE, HEAD)			\

/*
_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_0: iterpos=ITERPOS node=NODE NWLN
*/

/**
 * Worker for _XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_I1().
 * Iterate child nodes.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_1(ITERSTATE, HEAD)			\
	BOOST_PP_REPEAT(									\
		_XENUM3_TUPLETREE_ITERPOS_GET_CHILDCOUNT(_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(HEAD)),	\
		_XENUM3_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE,					\
		ITERSTATE									\
	)
/*
_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_1 _XENUM3_TUPLETREE_DBG_NODE_NAME(ITERSTATE) node=_XENUM3_TUPLETREE_STACKENTRY_GET_NODE(HEAD) NWLN \
*/

/**
 * Callback worker for _XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES_1(); loop for each childnode.
 * Handle the N'th childnode.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE(Z, N, ITERSTATE)				\
	_XENUM3_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE_I1(						\
		ITERSTATE,									\
		_XENUM3_TUPLETREE_STATE_GET_STACKHEAD(ITERSTATE),				\
		N										\
	)

/**
 * Worker for _XENUM3_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE_I1(ITERSTATE, HEAD, N)			\
	_XENUM3_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE_I2(						\
		ITERSTATE,									\
		_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(HEAD),					\
		BOOST_PP_SEQ_ELEM(N, _XENUM3_TUPLETREE_STACKENTRY_GET_NODE(HEAD)),		\
		_XENUM3_TUPLETREE_STATE_GET_CTXT(ITERSTATE),					\
		N										\
	)

/**
 * Worker for _XENUM3_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE_I1().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE_I2(ITERSTATE, ITERPOS, CHILDNODE, CTXT, N)	\
	_XENUM3_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE_I3(						\
		ITERSTATE,									\
		_XENUM3_TUPLETREE_ITERPOS_INIT(							\
			BOOST_PP_DEC(_XENUM3_TUPLETREE_ITERPOS_GET_LEVEL(ITERPOS)),		\
			BOOST_PP_SEQ_PUSH_BACK(_XENUM3_TUPLETREE_ITERPOS_GET_INDEXPATH(ITERPOS), N),	\
			0,									\
			_XENUM3_GET_TUPLE_SIZE_IF_TUPLE(CHILDNODE)				\
		),										\
		CHILDNODE,									\
		CTXT										\
	)
/*
_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE_I2 _XENUM3_TUPLETREE_DBG_NODE_NAME(ITERSTATE) iterpos=[ITERPOS] n=N childnode=CHILDNODE parens=BOOST_PP_IS_BEGIN_PARENS(CHILDNODE) NWLN \
*/

#define _XENUM3_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE_I3(ITERSTATE, ITERPOS, CHILDNODE, CTXT)	\
	BOOST_PP_CAT(										\
		_XENUM3_TUPLETREE_FLAT_GEN_EXEC_,						\
		_XENUM3_TUPLETREE_STATE_GET_FILTER(ITERSTATE) (ITERPOS, CHILDNODE, CTXT)	\
	) (ITERSTATE, ITERPOS, CHILDNODE, CTXT)
/*
_TUPLETREE_FLAT_GEN_EXEC_CHILDNODE_I3 _XENUM3_TUPLETREE_DBG_NODE_NAME(ITERSTATE) iterpos={_XENUM3_TUPLETREE_ITERPOS_DUMP(ITERPOS)} childnode=CHILDNODE NWLN \
*/

/**
 * Worker for _XENUM3_TUPLETREE_FLAT_GEN_EXEC_I3().
 * Do NOT execute callback since filter returned 0.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_EXEC_0(ITERSTATE, ITERPOS, NODE, CTXT)			\

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_GEN_EXEC_I2().
 * Do execute callback since filter returned 1.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_FLAT_GEN_EXEC_1(ITERSTATE, ITERPOS, NODE, CTXT)			\
	_XENUM3_TUPLETREE_STATE_GET_CALLBACK(ITERSTATE) (ITERPOS, NODE, CTXT)


/// =============================================================================================
/// Iteration functions for ITERATE_DEPTH_CALC().
/// =============================================================================================
/**
 * Called by main calc loop to execute callback and increment state.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_CALC_EXEC_AND_INC(N, ITERSTATE)					\
	_XENUM3_TUPLETREE_STATE_SET_CDATA_AND_STACK						\
	(											\
		ITERSTATE,									\
		_XENUM3_TUPLETREE_DEPTH_CALC_EXEC(						\
			ITERSTATE,								\
			_XENUM3_TUPLETREE_STATE_GET_STACKHEAD(ITERSTATE)			\
		),										\
		_XENUM3_TUPLETREE_DEPTH_INC(ITERSTATE)						\
	)

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_CALC_EXEC_AND_INC().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_CALC_EXEC(ITERSTATE, HEAD)					\
	_XENUM3_TUPLETREE_DEPTH_CALC_EXEC_I2							\
	(											\
		ITERSTATE,									\
		_XENUM3_TUPLETREE_STACKENTRY_GET_ITERPOS(HEAD),					\
		_XENUM3_TUPLETREE_STACKENTRY_GET_NODE(HEAD),					\
		_XENUM3_TUPLETREE_STATE_GET_CTXT(ITERSTATE),					\
		_XENUM3_TUPLETREE_STATE_GET_CDATA(ITERSTATE)					\
	)

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_GEN_EXEC_I1().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_CALC_EXEC_I2(ITERSTATE, ITERPOS, NODE, CTXT, CDATA)		\
	BOOST_PP_CAT(										\
		_XENUM3_TUPLETREE_DEPTH_CALC_EXEC_,						\
		_XENUM3_TUPLETREE_STATE_GET_FILTER(ITERSTATE) (ITERPOS, NODE, CTXT, CDATA)	\
	) (ITERSTATE, ITERPOS, NODE, CTXT, CDATA)

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_CALC_EXEC_I2().
 * Do NOT execute callback since filter returned 0.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_CALC_EXEC_0(ITERSTATE, ITERPOS, NODE, CTXT, CDATA)		\
	CDATA

/**
 * Worker for _XENUM3_TUPLETREE_DEPTH_CALC_EXEC_I2().
 * Do execute callback since filter returned 1.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_DEPTH_CALC_EXEC_1(ITERSTATE, ITERPOS, NODE, CTXT, CDATA)		\
	_XENUM3_TUPLETREE_STATE_GET_CALLBACK(ITERSTATE) (ITERPOS, NODE, CTXT, CDATA)


/// =============================================================================================
/// Main (public) iteration functions.
/// =============================================================================================
/**
 * Iterate a hierarchical tuple data structure (a tree), depth-first.
 * In this variant, the callback can generate content; anything it returns becomes part of the
 * preprocessor output. On the other hand, the callback invocations can not communicate with
 * each other; there is no modifiable data store shared between.
 *
 * Example tree:
 *        A
 *       / \
 *      B   C
 *     /   /|\
 *    D   E F G
 * Callback execution order is [A,B,D,C,E,F,G]; a plain depth-first order. However, this is
 * only because the default filtering function prevents some more callbacks. The core loop
 * wants to execute a callback multiple times for each node, except leaf nodes; both when it
 * enters a node, and when returning from each child. So without a filter function, the
 * callback execution order would be: [A,B,D,B,A,C,E,C,F,C,G,C,A].
 * This could actually be useful especially in the CALC variant (below), but in most cases
 * you only want to get a callback once for each node. So that is what the default filtering
 * function ensures.
 * You just have to keep this in mind if you provide your own filtering function.
 * 
 * @param DATA The data to iterate.
 * @param DEPTH Depth to iterate to. If 0, the DATA node is returned (to callback functions) as
 *	sole leaf value. If 1 (one level deep), the DATA node is iterated, and it's children
 *	returned as leaf values. Etc. The tree as such can have any level; DEPTH is just the
 *	limit we will iterate to; anything found at this level is returned as a leaf value, and
 *	anything before that must be a tuple.
 * @param FUNCS A tuple of one or two functions (macros):
 *	[0]: The callback function to execute for every node in the data tree.
 *	     Parameters:
 *		- ITERPOS: Object that describes current position in the tree.
 *		- NODE: Current node in the tree.
 *		- CTXT: Same CTXT object.
 *	     Returns: Nothing (just preprocessed output).
 *	[1]: A filtering function (optional); if defined, it is called before the macro
 *	     (with the same parameters) to determine if the callback should be called at all.
 *	     Must return 0|1. This is just a convenience that allows the caller site to
 *           define less code than if it does the filtering in the callback.
 * @param CTXT Static data to be passed to the callback.
 * @return Nothing (just preprocessed output).
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERATE_DEPTH_GEN(DATA, DEPTH, FUNCS, CTXT)				\
	BOOST_PP_FOR(										\
		_XENUM3_TUPLETREE_STATE_INIT(DATA, DEPTH, FUNCS, CTXT, ),			\
		_XENUM3_TUPLETREE_CMP,								\
		_XENUM3_TUPLETREE_DEPTH_GEN_INC,						\
		_XENUM3_TUPLETREE_DEPTH_GEN_EXEC						\
	)
/*
_TUPLETREE_ITERATE_DEPTH_GEN: depth=DEPTH funcs=FUNCS ctxt=CTXT data=DATA NWLN \
*/


/**
 * Iterate a hierarchical tuple data structure, depth-first.
 * In this variant, there is a data store shared between the callback invocations; one can
 * save data that is read/written by the next, and the final data store is returned to caller.
 * So this can be used to run calculations across all the nodes in the data structure.
 * On the other hand, the callback can not generate content; anything it outputs ends up in
 * the data store, so it can not generate any C++ code (or debugging output, which makes it a
 * bit hard to use this variant).
 * @param DATA See _XENUM3_TUPLETREE_ITERATE_DEPTH_GEN().
 * @param DEPTH See _XENUM3_TUPLETREE_ITERATE_DEPTH_GEN().
 * @param FUNCS See _XENUM3_TUPLETREE_ITERATE_DEPTH_GEN().
 * @param CTXT See _XENUM3_TUPLETREE_ITERATE_DEPTH_GEN().
 * @param CDATA Initial data store. Each callback invocation returns a new caller state.
 *	Thus it is possible for the callback to do calculations across the data tree
 *	and store aggregated data here.
 * @return Final data store.
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERATE_DEPTH_CALC(DATA, DEPTH, FUNCS, CTXT, CDATA)			\
	_XENUM3_TUPLETREE_STATE_GET_CDATA(							\
		BOOST_PP_WHILE(									\
			_XENUM3_TUPLETREE_CMP,							\
			_XENUM3_TUPLETREE_DEPTH_CALC_EXEC_AND_INC,				\
			_XENUM3_TUPLETREE_STATE_INIT(DATA, DEPTH, FUNCS, CTXT, CDATA)		\
		)										\
	)											\


/**
 * Iterate a hierarchical tuple data structure (a tree), in a semi-breadth-first way.
 * The tree is iterated depth-first, but when a new node is encountered, instead of
 * executing the callback, this function iterates all the node's childnodes (but no
 * deeper), and executes the callback for each of them. This function only iterates
 * deeper once all the current node's childnodes have had their callbacks executed.
 * When the childnodes are visited again as part of depth iteration, the callback is
 * not executed again.
 * Example data structure:
 *        A
 *       / \
 *      B   C
 *     /   /|\
 *    D   E F G
 *   /|\    |\
 *  H I J   K L
 * Callback execution order: A,B,C, D, H,I,J, E,F,G, K,L
 * Note that even though the root node is not a child of anything, a callback is executed for it,
 * first, just for convenience.
 * 
 * All args are the same as for _XENUM3_TUPLETREE_ITERATE_DEPTH_GEN().
 * @hideinitializer
 */
#define _XENUM3_TUPLETREE_ITERATE_FLAT_GEN(DATA, DEPTH, FUNCS, CTXT)				\
	BOOST_PP_FOR(										\
		_XENUM3_TUPLETREE_STATE_INIT(DATA, DEPTH, FUNCS, CTXT, ),			\
		_XENUM3_TUPLETREE_CMP,								\
		_XENUM3_TUPLETREE_DEPTH_GEN_INC,						\
		_XENUM3_TUPLETREE_FLAT_GEN_ITERATE_CHILDNODES					\
	)
/*
_TUPLETREE_ITERATE_FLAT_GEN: depth=DEPTH funcs=FUNCS ctxt=CTXT data=DATA NWLN \
*/

#endif // _XENUM3_IMPL_TUPLETREE_HPP
