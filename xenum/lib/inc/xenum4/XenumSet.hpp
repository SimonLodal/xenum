/**
 * @file
 * @author Simon Lodal
 * @copyright 2017 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 * @version 3.0
 */
#ifndef _XENUM4_XENUMSET_HPP
#define _XENUM4_XENUMSET_HPP

#include <cstring>
#include <iostream>
#include "Xenum.hpp"

namespace xenum4 {


/**
 * An XenumSet is a set of enum-values of a given Xenum type. It is essentially a bitset with
 * exactly the same number of bits as the number of enumvalues, but provides much nicer (and
 * typesafe) semantics than a plain bitset, and is also potentially more efficient than other
 * bitsets since it has no functionality to resize, and no external allocations; all the bits
 * are inside the object.
 */
template<typename XenumCntnr>
class XenumSet {
private:
public:
	/// The XenumValue class.
	using value_t = typename XenumCntnr::_value_t;
	/// Integer type used for enum values.
	using index_t = typename XenumCntnr::_index_t;

protected:
#if 1 // 64bit chunks
	/// Integer type used in the bit store.
	typedef uint64_t chunk_t;
	/// When you have the index of an enum-value, right-shift .chunkIndexShift times to
	/// get the index of the chunk that this enum-value bit is in.
	/// Same as dividing the index by the bitsize of the chunk_t.
	static constexpr const index_t chunkIndexShift = 6;
	/// Mask of the bits that are removed by right-shifting by chunkIndexShift.
	static constexpr const chunk_t bitShiftMask = 63;
#else // 8bit chunks
	typedef uint8_t chunk_t;
	static constexpr const index_t chunkIndexShift = 3;
	static constexpr const chunk_t bitShiftMask = 7;
#endif
	/// Number of bits in a chunk_t.
	static constexpr const index_t chunkBitSize = sizeof(chunk_t) * 8;

protected:
	/// Number of chunks.
	static constexpr const index_t chunkCount = (XenumCntnr::_size / chunkBitSize) +
		(((XenumCntnr::_size % chunkBitSize) != 0) ? 1 : 0);
	/// Bit store with one bit for each possible enum-value. Excess bits are always zero.
	chunk_t bitChunks[chunkCount];

public:
	/**
	 * Default ctor. Creates an empty set.
	 */
	constexpr XenumSet(void) noexcept
		: bitChunks {0}
	{
	}


	/**
	 * Copy ctor.
	 */
	XenumSet(const XenumSet<XenumCntnr>& other) noexcept
	{
		memcpy(bitChunks, other.bitChunks, sizeof(bitChunks));
	}


	/**
	 * Assignment.
	 */
	XenumSet& operator=(const XenumSet<XenumCntnr>& other) noexcept
	{
		if (this != &other)
			for (index_t chunkIndex=0; chunkIndex<chunkCount; chunkIndex++)
				bitChunks[chunkIndex] = other.bitChunks[chunkIndex];
		return *this;
	}


	/**
	 * Comparison.
	 */
	bool operator==(const XenumSet<XenumCntnr>& other) const noexcept
	{
		for (index_t chunkIndex=0; chunkIndex<chunkCount; chunkIndex++) {
			if (bitChunks[chunkIndex] != other.bitChunks[chunkIndex])
				return false;
		}
		return true;
	}


	/**
	 * Comparison.
	 */
	bool operator!=(const XenumSet<XenumCntnr>& other) const noexcept
	{
		for (index_t chunkIndex=0; chunkIndex<chunkCount; chunkIndex++) {
			if (bitChunks[chunkIndex] != other.bitChunks[chunkIndex])
				return true;
		}
		return false;
	}


	/**
	 * Add a value to this set.
	 * @return this
	 */
	XenumSet& add(const value_t value) noexcept
	{
		bitChunks[value.getIndex()>>chunkIndexShift] |= ((chunk_t)1) << (value.getIndex() & bitShiftMask);
		return *this;
	}


	/**
	 * Add multiple values to this set.
	 * @return this
	 */
	XenumSet& add(std::initializer_list<value_t> values) noexcept
	{
		for (auto value : values)
			add(value);
		return *this;
	}


	/**
	 * Add all values of the enum to this set (fill it).
	 * @return this
	 */
	XenumSet& addAll(void) noexcept
	{
		if (chunkCount > 1)
			memset(bitChunks, -1, sizeof(bitChunks));
		bitChunks[chunkCount-1] = (chunk_t)~(((chunk_t)-1) << (XenumCntnr::_size % chunkBitSize));
		return *this;
	}


	/**
	 * Remove a value from this set. No action if the value was not part of the set.
	 * @return this
	 */
	XenumSet& remove(const value_t value) noexcept
	{
		bitChunks[value.getIndex()>>chunkIndexShift] &= ~(((chunk_t)1) << (value.getIndex() & bitShiftMask));
		return *this;
	}


	/**
	 * Remove multiple values from this set. No error if value(s) were not added.
	 * @return this
	 */
	XenumSet& remove(std::initializer_list<value_t> values) noexcept
	{
		for (auto value : values)
			remove(value);
		return *this;
	}


	/**
	 * Remove all values from this set (clear it).
	 * @return this
	 */
	XenumSet& removeAll(void) noexcept
	{
		memset(bitChunks, 0, sizeof(bitChunks));
		return *this;
	}


	/**
	 * Test if the enum value exists in this set.
	 */
	bool contains(const value_t value) const noexcept
	{
		return ((bitChunks[value.getIndex()>>chunkIndexShift] >> (value.getIndex() & bitShiftMask)) & 1);
	}


	/**
	 * Test if this set contains any of the values of the other set.
	 * Note: Returns false if other set is empty.
	 */
	bool containsAny(const XenumSet<XenumCntnr>& other) const noexcept
	{
		for (index_t chunkIndex=0; chunkIndex<chunkCount; chunkIndex++) {
			if ((bitChunks[chunkIndex] & other.bitChunks[chunkIndex]) != 0)
				return true;
		}
		return false;
	}


	/**
	 * Test if this set contains all values of the other set.
	 * Note: Returns false if other set is empty.
	 */
	bool containsAll(const XenumSet<XenumCntnr>& other) const noexcept
	{
		bool otherIsNonEmpty = false;
		for (index_t chunkIndex=0; chunkIndex<chunkCount; chunkIndex++) {
			if (other.bitChunks[chunkIndex] != 0)
				otherIsNonEmpty = true;
			if ((bitChunks[chunkIndex] & other.bitChunks[chunkIndex])
			    != other.bitChunks[chunkIndex])
				return false;
		}
		return otherIsNonEmpty;
	}


protected:
	/**
	 * Search for next value. Basis for the iterator.
	 */
	index_t getNextValueIndex(index_t begin) const noexcept
	{
		if (begin >= XenumCntnr::_size)
			return XenumCntnr::_size;
		index_t cidx = begin >> chunkIndexShift;
		index_t bidx = begin & bitShiftMask;
		if (bidx != 0) {
			chunk_t chunk = bitChunks[cidx];
			if (chunk != 0) {
				for (; bidx<chunkBitSize; bidx++) {
					if (((chunk >> bidx) & 1) != 0)
						return ((cidx << chunkIndexShift) | bidx);
				}
			}
			cidx++;
		}

		for (; cidx<chunkCount; cidx++) {
			chunk_t chunk = bitChunks[cidx];
			if (chunk == 0)
				continue;
			for (bidx=0; bidx<chunkBitSize; bidx++) {
				if (((chunk >> bidx) & 1) != 0)
					return ((cidx << chunkIndexShift) | bidx);
			}
		}
		return XenumCntnr::_size;
	}

public:
	/**
	 * Simple forward const iterator that iterates the values in the set.
	 */
	class iterator {
	public:
		/// Default ctor, initializes to begin().
		iterator(const XenumSet<XenumCntnr>& xenumSet) noexcept
			: xenumSet(xenumSet)
			, index(xenumSet.getNextValueIndex(0))
			{}

		/// Assignment.
		iterator& operator= (iterator other) { xenumSet = other.xenumSet; index = other.index; return *this; }

		/// Prefix increment operator.
		iterator& operator++(void) noexcept { index = xenumSet.getNextValueIndex(index+1); return *this; }

		/// Postfix increment operator.
		iterator& operator++(int) noexcept { index = xenumSet.getNextValueIndex(index+1); return *this; }

		/// Comparison operator.
		bool operator!=(const iterator& other) noexcept { return xenumSet != other.xenumSet || index != other.index; }

		/// Comparison operator.
		bool operator==(const iterator& other) noexcept { return xenumSet == other.xenumSet && index == other.index; }

		/// Dereference operator.
		const value_t operator*(void) { return value_t(XenumCntnr::_fromIndex(index)); }
	protected:
		/// Ctor with initialization to a specific index.
		iterator(const XenumSet<XenumCntnr>& xenumSet, index_t index) noexcept
			: xenumSet(xenumSet)
			, index(index)
			{}
		/// Allow begin() to use the protected ctor.
		friend iterator XenumSet::begin(void) noexcept;
		/// Allow end() to use the protected ctor.
		friend iterator XenumSet::end(void) noexcept;
	protected:
		/// XenumSet to iterate.
		const XenumSet<XenumCntnr>& xenumSet;
		/// Current position.
		index_t index;
	};

	/// Get iterator to beginning (before the first enum-value in the set).
	iterator begin(void) noexcept { return iterator(*this); }

	/// Get iterator to end (past the last enum-value).
	iterator end(void) noexcept { return iterator(*this, XenumCntnr::_size); }


/// DEBUG
#if 0
public:
	void dumpChunks(std::ostream& out) const
	{
		for (index_t cidx=0; cidx<chunkCount; cidx++) {
			chunk_t chunk = bitChunks[cidx];
			out<<"\n\t["<<cidx<<"]=";
			for (index_t bidx=chunkBitSize-1; bidx>=0; bidx--)
				out<<((chunk >> bidx) & 1);
		}
	}
#endif
};

} // namespace xenum4


/// Print an XenumSet.
template<typename XenumCntnr>
std::ostream& operator<<(std::ostream& out, const ::_XENUM4_NS::XenumSet<XenumCntnr>& xenumSet) {
	out<<"[";
	bool any = false;
	for (typename ::_XENUM4_NS::XenumSet<XenumCntnr>::index_t index=0; index<XenumCntnr::_size; index++) {
		typename XenumCntnr::_value_t value = XenumCntnr::_fromIndex(index);
		if (!xenumSet.contains(value))
			continue;
		if (any)
			out<<",";
		out<<value.getIdentifier();
		any = true;
	}
	out<<"]";
	return out;
}


#endif // _XENUM4_XENUMSET_HPP
