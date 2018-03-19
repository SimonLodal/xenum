/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 * @version 3.0
 *
 * @section Description
 * Xenum is an enum class that adds all the functionality that standard C++ enums lack.
 *
 * The goals are to provide type safety, conversion to/from string, iteration, and zero
 * runtime overhead compared to using a plain C++ enum alone. And a syntax that is not too
 * strange or difficult.
 *
 * C++11's "enum class" is already a big improvement over earlier plain "enum" which were
 * just dumb ints. The new "enum class" adds type safety and scoping. But there is still no
 * iteration, string conversion, or anything else, so there is still a big need for Xenum.
 *
 * The basic design is to extend native C++ enums by creating two classes per enum, a
 * container class for all the enum values, and an enum-value wrapper.
 *
 * @section Requirements
 * - Build requirements:
 *   - C++11 compiler. g++-4.9 is fine; use -std=c++11. But do not use -ansi, it
 *     prevents boost.preprocessor's variadic stuff from working.
 *   - Boost.Preprocessor (boost-1.64.0 used).
 * - Runtime requirements: None.
 *
 * @section Features
 * - Access to name and index of an enum-value.
 * - Lookup enum value by name.
 * - Lookup enum value by index.
 * - Iteration over enum values.
 * - switch() on enum value in a typesafe manner.
 * - Extensible enum values; add custom properties to each enum value. Normal Xenum values
 *   have a name and an index value (sequential), but no "ordinal" value. But if you miss
 *   that, you can just add it (example below) and many others; you can have multiple custom
 *   properties, and they can even be multilevel arrays of values.
 * - General type safety: The generated classes are unique for each enum, which provides type
 *   safety; you can not assign or compare with other enum classes.
 * - Reasonably simple definition of an enum. Requires a few macros in header, and one in a
 *   source file. The latter is minimal (no duplication of value list or other parameters).
 * - Implementation is only headers, no source files. Just include Xenum.hpp.
 * - Unlimited number of values in an enum. As if that should be a feature, but yes, naive
 *   implementations keep the enum-values in some sort of parameter list, which has maximum
 *   length as low as 64 or 256, both for macros and templates, so they just fail on larger
 *   enums.
 * - Almost everything is static/const(expr), with zero runtime initialization. This means an
 *   xenum can be used in template metaprogramming, and also in declaration of data structures,
 *   fx. array sizes based on the number of enum values.
 *
 * @section DesignImpl Design / implementation
 * C/C++ enums have always confused me. There is the enum, and then there is the individual
 * values within it. But both are "the enum".
 *
 * Xenum separates the two, so there are enum values, and a container class that contains the
 * values. They are distinct classes. And for semantic clarity, they should usually be
 * named in pluralis and singular form of the same word, fx. Fruits/Fruit, Cards/Card, etc.
 *
 * So when you create an xenum (say, "Fruits"), two classes are created. First the enum
 * container class (Fruits), then the value wrapper (Fruit).
 *
 * The container class contains a native C++ enum (Fruits::Enum) with all the values. We would
 * inherit the container class from the native enum class if C++ allowed that, instead the
 * container class copies all the enum values into itself, so they are available as Fruits::apple,
 * Fruits::lemon, etc, just as if the container was the actual native C++ enum.
 *
 * Next, the enum value class (Fruit) is created. It is a very lightweight wrapper around a
 * native enum value. Being a class, it adds several useful functions. But it adds no data or
 * other overhead, so it's size is exactly the same as the native enum value.
 *
 * In your own code you can use the native enum values or the value objects as you like, they are
 * equivalent and interchangeable. There is zero runtime overhead in using the value object.
 *
 * Some other points:
 * - No pointers in the static data. They could force each process to create a copy of the
 *   page(s) with static data because the pointers would be unique for the process' address
 *   space. No pointers means that the page(s) may be shared between processes.
 * - Implementation is based on preprocessor macros, not templates, at least the core task
 *   of defining the enum values and associated data. Template metaprogramming would have been
 *   nice for it's elegance and power, but it has some shortcomings:
 *   - It can not generate identifiers (the enum values), only types or values.
 *   - Big lists do not work (fx >256 entries), since all iteration over lists is recursive,
 *     and all preprocessors have a rather small recursion limit.
 *
 *   So for now, we have to deal with incomprehensible error messages when something goes wrong.
 *
 * @section Creating_An_Xenum Creating an Xenum
 * An Xenum requires three macros in header, and one in a source file. Below are some examples.
 * Parameters are documented further below.
 *
 * @subsection EXAMPLE_BASIC Basic enum example
 * In your header file:
 * - \#include <xenum3/Xenum.hpp>
 * - First some general definitions:
 *	@code
 *	#define XENUM_DECL_Fruits (, Fruits, Fruit)
 *	@endcode
 *   - Note the space between XENUM_DECL_Fruits and the opening parenthesis.
 * - Then the values:
 *	@code
 *	#define XENUM_VALS_Fruits(V,C)		\
 *		V(C, apple)			\
 *		V(C, grape)			\
 *		V(C, lemon)
 *	@endcode
 * - Finally trigger code generation (header part):
 *	@code
 *	XENUM3_DECLARE(Fruits)
 *	@endcode
 *
 * In your source file:
 * - Trigger code generation (source part):
 *	@code
 *	XENUM3_DEFINE(Fruits)
 *	@endcode
 *
 * In this example, "Fruits" is the suffix that ties it all together; The XENUM_DECL and
 * XENUM_VALS macros use this suffix, and the same suffix is passed to XENUM3_DECLARE() and
 * XENUM3_DEFINE() macros, which allows them to find and use the declaration macros. The suffix
 * can be anything, it just needs to be unique (two xenums may not use same suffix, that
 * would redefine the declaration macros).
 *
 * Note that the XENUM_DECL_${suffix} and XENUM_VALS_${suffix} macros are not macro calls, they
 * are macro definitions. XENUM_DECL_${suffix} is a data definition, while XENUM_VALS_${suffix}
 * is a macro function that is evaluated by the xenum generator over and over.
 *
 * XENUM3_DECLARE() and XENUM3_DEFINE() macros are the actual generator functions, to be used
 * in your header and source files respectively.
 *
 * @subsection EXAMPLE_CUSTOM_PROPS Enum example with custom properties
 * In header file:
 * - \#include <xenum3/Xenum.hpp>
 * - The general definition can contain a bit more:
 *	@code
 *	#define XENUM_DECL_Fruits (my::ns::, Fruits, Fruit, int8_t, , (	\
 *		(Ordinal, int),			\
 *		(Sour, bool, false)		\
 *		))
 *	@endcode
 *   - Namespace path is now defined. This is required when the enum exists in a namespace
 *     and/or class.
 *   - int8_t is now enforced as the integer type to use for the enum values.
 *   - Two custom properties are added: "Ordinal" of type int, without any default value, and
 *     "Sour" of type bool, with default value "false".
 * - The values now also define the values of the custom properties:
 *	@code
 *	#define XENUM_VALS_Fruits(V,C)		\
 *		V(C, apple, 22)			\
 *		V(C, grape, 44, true)		\
 *		V(C, lemon, 17, true)
 *	@endcode
 *   - Apple gets Ordinal=22, and Sour=false (default value applied since it is empty).
 *   - Grape gets Ordinal=44, and Sour=true.
 *   - Lemon gets Ordinal=17, and Sour=true.
 *
 * Code generation is like in the first example:
 * - Header part:
 *	@code
 *	XENUM3_DECLARE(Fruits)
 *	@endcode
 * - Source part:
 *	@code
 *	XENUM3_DEFINE(Fruits)
 *	@endcode
 *
 * FIXME: Multilevel custom properties example.
 * @subsection XENUM_DECL XENUM_DECL_$suffix
 * The XENUM_DECL_$suffix macro contains general parameters, defined as a tuple (comma-separated
 * values inside parentheses). Syntax:
 *	@code
 *	#define XENUM_DECL_${suffix} (scope, enumClassName, enumValueName [, intType [, features [, custom_properties]]])
 *	@endcode
 * Again note the space between XENUM_DECL_${suffix} and the opening parenthesis.
 * @param scope The containing namespace and/or class. Define this if the call to
 *	XENUM3_DEFINE() is not inside the same namespace and class (if any) as the call to
 *	XENUM3_DECLARE() (or "using" that namespace). If defined, it must end in "::", fx
 *	"my::ns::" (do not quote the value). You may also use a :: prefix to denote
 *	the toplevel namespace, to avoid any relative resolution of namespace.
 *	Note that if the xenum is member in a class (XENUM3_DECLARE() is called from within
 *	a class), the scope MUST contain at least the class name, if not also the namespace.
 * @param enumClassName Name of the generated enum-container class, fx. "Fruits" (not quoted).
 * @param enumValueName Name of the generated enum-value class, fx. "Fruit" (not quoted).
 * @param intType Optional. Integer-type for the enum values. Should be unsigned, and must be large
 *	enough to hold the number of enum values (compile-time error if not). Leave empty
 *	to let Xenum decide the smallest possible type.
 * @param features Optional. Not implemented yet. Leave empty for now.
 * @param properties Optional. Defines custom properties. Leave field empty/undefined if the
 *	xenum does not have any custom properties. If defined, it must be a tuple of one or
 *	more tuples that each define a property (see below).
 *
 * Custom property definition tuple syntax:
 *	@code
 *	(propertyName, propertyType [, defaultValue [, depth]])
 *	@endcode
 * @param propertyName Name of the custom property.
 * @param propertyType Data-type of the custom property. For now only simple bool/int types
 *	are supported (not strings).
 * @param defaultValue Optional (default=none). Default value to apply if an enum value does not
 *	define a value for this property.
 * @param depth Optional (default=0). Defines number of array levels. Depth=0 means each enum value
 *	has exactly one value for this custom property. Depth=1 means that each enum value has an
 *	array of values. Depth=2 means they each have a two-level array of values, etc. Array sizes
 *	are not fixed; you can make them any length (up to preprocessor limit of maybe 64 or 256).
 *	Arrays can also be empty or non-existent (empty branches allowed).
 *	Arrays are indexed by the smallest possible integer (decided by Xenum).
 *	Values can only exist as leaf nodes in the data hierarchy, that is, they can only appear
 *	at level $depth, not somewhere in between.
 *
 * @subsection XENUM_VALS XENUM_VALS_${suffix}()
 * The XENUM_VALS macro defines the enum-values, as a series of calls to a V() macro that is
 * passed as a parameter itself. Syntax:
 *	@code
 *	#define XENUM_VALS_${suffix}(V,C)	\
 *		V(C, value0 [, custom, ...])	\
 *		V(C, value1 [, custom, ...])	\
 *		...				\
 *		V(C, valueN [, custom, ...])
 *	@endcode
 * The V() macro:
 * @param C The same "C" that your XENUM_VALS_${suffix}() macro was called with; a "context"
 *	data structure used to pass variables around between internal functions.
 * @param value The enum-value name (identifier), fx. "foo" (not quoted).
 * @param custom Zero or more custom property values; must match the ones defined in the
 *	XENUM_DECL_$suffix macro. If a value field is empty, the default defined in
 *	XENUM_DECL_$suffix is used, if there is one (if not all values must be specified).
 *
 * @section Using_An_Xenum Using an Xenum
 * - Create/Assign:
 *	@code
 *	// Value object
 *	Fruit fruit1 = Fruits::apple;
 *	Fruit fruit2 = Fruits::lemon;
 *	Fruit fruit3(fruit1); // copy
 *	Fruit fruit4 = Fruits::fromIndex(1); // => grape
 *	Fruit fruit5 = Fruits::fromIdentifier("lemon"); // => lemon (warning: inefficient string lookup)
 *	// Native enum value
 *	Fruits::Enum value1 = Fruits::apple;
 *	Fruits::Enum value2 = fruit2();
 *	@endcode
 *   Note the last one: The () operator on an enum value object returns the native enum value.
 * - Access the properties of enum values:
 *	@code
 *	const char* ident = fruit1.getIdentifier();
 *	Fruits::index_t = fruit2.getIndex();
 *	Fruits::Enum nativeEnumValue = fruit3();
 *	@endcode
 *   These are the only properties that Xenum values have (plus any custom properties).
 * - Print:
 *	@code
 *	std::cout << "fruit1:"
 *		  << " index=" << fruit1.getIndex()
 *		  << " identifier='" << fruit1 << "'"
 *		  << std::endl;
 *	@endcode
 *   The default ostream::operator<<() for an Xenum value print the identifier.
 *
 *   Note that there is no output operator for the native enum value, it is just printed
 *   as an integer.
 * - Comparisons: Works like with native enum values, and value objects can also compare against
 *   native values.
 *	@code
 *	if (fruit1 == fruit2) { ... } // false
 *	if (fruit1 != fruit2) { ... } // true
 *	if (fruit1 < fruit2) { ... } // true
 *	if (fruit1 > fruit2) { ... } // false
 *	@endcode
 * - Iterate - notice the parentheses on Fruits() - and notice that you can iterate with a native
 *   enum value or a value object:
 *	@code
 *	for (Fruit fruit : Fruits()) { ... }
 *	for (Fruits::Enum value : Fruits()) { ... }
 *	for (auto value : Fruits()) { ... }
 *	@endcode
 *   The last two are the same; the iterator returns native enum values.
 * - Iterate old style:
 *	@code
 *	for (Fruit::iterator iter = Fruits.begin(); iter != Fruits.end(); ++iter) {
 *		std::cout << iter->getIdentifier() << std::endl;
 *	}
 *	@endcode
 * - Iterate with indexes:
 *	@code
 *	for (Fruits::index_t index = 0; index < Fruits::size; index++) {
 *		std::cout << Fruits::fromIndex(index).getIdentifier() << std::endl;
 *	}
 *	@endcode
 * - switch(): C++11 provides type safety for this, which can not be achieved in other ways. So
 *   for switch(), always use a native enum value. If you have an enum-value wrapper object, just
 *   use the () operator to get the native enum value, fx:
 *	@code
 *	switch (fruit()) { // notice the parentheses, retrieves the native enum value
 *	case Fruits::apple:	...; break;
 *	case Fruits::grape:	...; break;
 *	case Fruits::lemon:	...; break;
 *	default:		...; break;
 *	}
 *	@endcode
 * - Custom properties: A getter function is created for each property, so in the example above,
 *   the enum value class will have these functions:
 *	@code
 *	constexpr const int& getOrdinal() const;
 *	constexpr const bool& getSour() const;
 *	@endcode
 *   So:
 *	@code
 *	int ord = Fruits::apple::getOrdinal(); // => 22
 *	Fruit fruit = Fruits::lemon;
 *	bool sour = fruit.getSour(); // => true
 *	@endcode
 * - See unit tests for working examples.
 *
 * @section Caveats
 * - Name lookup is currently very inefficient, uses linear search. Need to find a way to
 *   generate a static constexpr string-hashtable, or at least a constexpr way to sort the
 *   string list and use binary search.
 * - Reserved names: All the common members of the enum-container class have names that can
 *   not be used for an enum-value, since the enum-value objects are also direct members of
 *   the container class. So these names can not be used as an enum-value (the list may grow
 *   in future versions):
 *	- index_t
 *	- size
 *	- Enum
 *	- fromIndex
 *	- fromIdentifier
 *	- iterator
 *	- begin
 *	- end
 *	- the name of the enum-container class.
 *	- For each custom property, a number of ${property-name}_* symbols are created, as
 *	  well as the get${property-name}*() getters (several for array-type properties).
 * - No API doc for the generated Xenum classes. It is not really possible to generate API doc
 *   for macro-generated functions. However, you can inspect the generated code: Use the
 *   util/xenum-inspect script, it runs the preprocessor only on a file of your choice, and
 *   formats the output with indentation and newlines so it is readable.
 * - Poor error messages, due to how the preprocessor works. Since this is all implemented with
 *   preprocessor macros, when something goes wrong you tend to get 10000 lines of
 *   incomprehensible error messages, none of which point to where the actual comma is missing.
 *   When this happens, try to make your enum declaration simpler until it works, then start
 *   adding again - trial and error. And again, you may want or need to use the pp.sh script to
 *   preprocess only that source file where the problematic enum is defined, and inspect the
 *   preprocessed code.
 * - There is a limit on the number of custom properties, currently 64 or maybe a little less.
 *   This is due to the recursion limit in the preprocessor.
 * - Preprocessing time (wallclock) increases if you add a lot of custom properties, deep
 *   hierarchies, many values. It does not scale very well. Perhaps depends on the preprocessor
 *   used.
 *
 * @section Future_Plans Future plans
 * - Custom properties of string type.
 * - Efficient string-to-enum lookup. Requires a hashmap, which is difficult given these
 *   requirements: 1) Everything static-const(expr), 2 No external compile tools.
 *   Some template magic may be possible in C++14 but for now we stick with C++11.
 * - Enum class inheritance (maybe).
 * - Custom code injection (maybe - if custom properties are not enough).
 *
 * @section Versioning Versioning
 * Major version is increased when introducing incompatible API changes.
 *
 * Minor versions may include features/changes that have sane, backwards-compatible
 * (within same major version) defaults, and do not require changes to users' code.
 *
 * All preprocessor symbols have a versioned prefix (_XENUM${MAJORVERSION}).
 * Toplevel directory and namespace are also versioned (xenum${majorversion}).
 *
 * This allows different versions to be used in the same project. Very convenient
 * when you might want to upgrade, but not update all the enum definitions at once.
 */
#ifndef _XENUM3_XENUM_HPP
#define _XENUM3_XENUM_HPP

/// Namespace that Xenum lives in.
/// Note that most of Xenum is macros that ignore namespaces anyway.
#define _XENUM3_NS xenum3

//#include <cstdint>
#include <iostream>
// For SelectInt
#include <type_traits>
// For DeclareCntnr, DefineCntnr
#include <stdexcept>
// For DefineCntnr
#include <cstring>
// For all generators
#include <boost/preprocessor.hpp>
#include <boost/preprocessor/facilities/is_empty.hpp>

#include <xenum3/impl/Util.hpp>
#include <xenum3/impl/SelectInt.hpp>
#include <xenum3/impl/XenumCntnrIterator.hpp>
#include <xenum3/impl/XenumValue.hpp>
#include <xenum3/impl/TupleTree.hpp>
#include <xenum3/impl/Decl.hpp>
#include <xenum3/impl/PropDef.hpp>
#include <xenum3/impl/Ctxt.hpp>
#include <xenum3/impl/IndexNode.hpp>
#include <xenum3/impl/Cstring.hpp>
#include <xenum3/impl/DeclareCntnr.hpp>
#include <xenum3/impl/DeclareCntnrProps.hpp>
#include <xenum3/impl/DeclareValue.hpp>
#include <xenum3/impl/DefineCntnr.hpp>
#include <xenum3/impl/DefineCntnrProps.hpp>
#include <xenum3/impl/Main.hpp>


/**
 * Declares the header part of an Xenum.
 * @param SUFFIX Suffix of the declaration macros.
 * @hideinitializer
 */
#define XENUM3_DECLARE(SUFFIX)									\
	_XENUM3_DO_DECLARE(_XENUM3_CTXT_INIT(SUFFIX))

/**
 * Declares the source part of an Xenum.
 * @param SUFFIX Suffix of the declaration macros.
 * @hideinitializer
 */
#define XENUM3_DEFINE(SUFFIX)									\
	_XENUM3_DO_DEFINE(_XENUM3_CTXT_INIT(SUFFIX))


// Doxygen trouble: Everything below is internal. Would like to hide it from doxygen, but would
// also like a simple (one line) way to turn it back on. Difficult. This instead groups most of
// the internal members (but not the template class, argh) into an "Xenum Internals" group, and
// moves the detailed documentation about them to a separate page. But they are still listed on
// the main page's brief.
/// @name Xenum Internals
///@{
/// @defgroup Xenum Internals2
///@{


// ===================================================================================================

// End of doxygen groups.
///@}
///@}



/// Print an XenumValue.
template<class XenumCntnr>
inline std::ostream& operator<<(std::ostream& out, ::_XENUM3_NS::XenumValue<XenumCntnr> enumValue) {
	return out << enumValue.getIdentifier();
}


#endif // _XENUM3_XENUM_HPP
