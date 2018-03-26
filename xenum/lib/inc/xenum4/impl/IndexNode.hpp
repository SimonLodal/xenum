/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM4_IMPL_INDEXNODE_HPP
#define _XENUM4_IMPL_INDEXNODE_HPP

namespace xenum4 {


/**
 * Multilevel arrays of custom property values are built by IndexNode's.
 * @param index_t An integer type large enough to index and count all values of the
 *	custom property, and all IndexNode's of the custom property (whichever is larger).
 */
template<typename index_t>
class IndexNode {
public:
	/// Integer type for indexing and counting.
	using type = index_t;
	/// Number of elements on next level.
	index_t size;
	/// Starting index of elements on next level.
	index_t index;
	/// Get index at next level.
	/// @param offset Offset relative to this node's index.
	/// @throws std::out_of_range if offset >= number of elements at next level.
	index_t getNextIndex(index_t offset) const
	{
		if (offset >= size)
			throw std::out_of_range("Offset >= size");
		return index + offset;
	}
};

/// Static instantiation for uint8_t.
template class IndexNode<uint8_t>;
/// Static instantiation for uint16_t.
template class IndexNode<uint16_t>;


} // namespace xenum4
#endif // _XENUM4_IMPL_INDEXNODE_HPP
