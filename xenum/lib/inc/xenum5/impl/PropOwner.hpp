/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef _XENUM5_IMPL_PROPOWNER_HPP
#define _XENUM5_IMPL_PROPOWNER_HPP

namespace xenum5 {


/**
 * Simple pair that tells which enum value owns a given custom property value.
 * @param EnumIndex An integer type large enough to index and count all the enum-values.
 * @param PropIndex An integer type large enough to index and count all the values of
 *	the custom property.
 */
template<typename EnumIndex, typename PropIndex>
class PropOwner {
public:
	/// Enum value; the owner.
	EnumIndex enumValue;
	/// Custom property value; the owned value. Index into the ${pname}Values array.
	PropIndex propIndex;
};


} // namespace xenum5
#endif // _XENUM5_IMPL_PROPOWNER_HPP
