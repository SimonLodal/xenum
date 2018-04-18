/**
 * @file
 * @author Simon Lodal
 * @copyright 2017-2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 * @version 4.0
 *
 * @section Description
 * A better enum class for C++. Adds all the functionality that standard C++ enums lack.
 *
 * C++11's "enum class" is already a big improvement over earlier plain "enum" which were
 * just dumb ints. The new "enum class" adds type safety and scoping. But there is still
 * a lot left to be desired...
 *
 * @section Features
 * - Access to name (string) and index of an enum-value.
 * - Lookup enum value by name.
 * - Lookup enum value by index.
 * - constexpr size.
 * - Iteration over enum values.
 * - switch() on enum value in a typesafe manner.
 * - Unlimited number of values in an enum. All other extended C++ enum I have found have a
 *   limit of around 64 or 256 values in an enum, due to recursion limits in preprocessor
 *   and/or templates. Way too low for real life use. Xenum overcomes this by having the enum
 *   values declared as a list of macro calls, which can have unlimited length.
 * - Can be placed inside a class, just like regular enums (except if it has custom properties,
 *   see Caveats).
 * - Zero runtime overhead compared to using a native enum class.
 * - Extensible: You can add custom properties to each enum value. Normal Xenum values
 *   have a name (an identifier) and an index value (assigned sequentially), but no "ordinal"
 *   value like a plain enum. However, if you want you can just add an "ordinal" property
 *   (example below). You can have multiple custom properties. Their datatype can be any plain
 *   type (integers), strings (C style), or objects, as long as they are constexpr.
 *   Custom properties can even be multidimensional, fx. a list of strings, or a
 *   list-of-lists-of-strings, etc.
 * - Type safety: Inherently uses the type safety of C++11 enum class. Additionally, the
 *   generated classes are unique for each enum, which also provides type safety; you can not
 *   assign or compare with other enum classes.
 * - Implementation is only headers, no source files. Just include Xenum.hpp.
 * - Everything is static and const(expr). So an xenum can be used in template metaprogramming,
 *   and also in declaration of data structures, fx. array sizes based on the number of enum
 *   values.
 * - No runtime initialization/computation, and no pointers in the generated data.
 *   This means xenums are friendly for shared libraries; the pages that contain their data
 *   are truly static so they can be shared between processes.
 * - Reasonably simple declaration of an enum. Requires a few macros in header, and one in a
 *   source file. The latter is minimal (no duplication of value list or other parameters).
 * - Includes XenumSet; a container with a set of values from an xenum, implemented as a bitset.
 *
 * @subsection Compilers Supported compilers
 * - g++-4.9
 * - clang-3.5
 * - Others may or may not work.
 *
 * @subsection Platforms Supported platforms
 * Xenum is being developed on Linux. I have no access to Windows or Mac systems so others
 * will have to test on those. The Xenum headers should work everywhere but is it possible
 * that some of the util scripts have some GNU or Unix ism's.
 *
 * @subsection Requirements
 * - Build requirements:
 *   - C++11 compiler
 *   - Boost.Preprocessor (boost-1.64.0 used)
 * - Runtime requirements: None.
 *
 * @section DesignImpl Design / implementation
 * C/C++ enums have always confused me. There is the enum, and then there is the individual
 * values within it. But both are "the enum".
 *
 * Xenum separates the two, so there are enum values, and a container class that contains the
 * values. They are distinct classes. And for semantic clarity, they should usually be
 * named in pluralis and singular form of the same word, fx. Fruits/Fruit, Cards/Card, etc.
 *
 * So when you create an xenum (say, "Fruits"), two classes are created, the enum container
 * class (Fruits) and the value class (Fruit). Actually a third class is also generated, but
 * only for internal purposes (storage of data related to the enum).
 *
 * The enum-value class (Fruit) is a very lightweight wrapper around a native enum value.
 * Being a class, it adds several useful functions. But it adds no data or other overhead,
 * so it's size is exactly the same as the native enum value.
 *
 * The container class contains all the enum values as value objects, so you can refer to
 * Fruits::apple and Fruits::lemon just like you would with a native C++11 enum class. The
 * difference is that you get a enum-value objects, not just raw native enum values.
 *
 * The container class makes the native C++11 enum class available as Fruits::_Enum, should
 * you want to use them directly. They are equivalent and interchangeable with the enum-value
 * objects. There is zero runtime overhead in using the value object.
 *
 * Implementation is based on preprocessor macros, not templates, at least the core task
 * of defining the enum values and associated data. Template metaprogramming would have been
 * nice for it's elegance and power, but it has some shortcomings:
 * - It can not generate identifiers (the enum values), only types or values.
 * - Big lists do not work (fx >256 entries), since all iteration over lists is recursive,
 *   and all preprocessors have a rather small recursion limit.
 *
 * So for now, we have to deal with incomprehensible error messages when something goes wrong.
 *
 * @section Documentation Documentation
 * Below are some examples that show how to create and use xenums.
 *
 * Further below complete reference of all the parameters.
 *
 * @section Example_Basic Example: Basic xenum
 * Here we declare a simple "Fruits" enum, with values "apple", "orange", "lemon".
 *
 * @subsection Basic_Create Create the xenum
 *
 * In your header file:
 * - \#include <xenum4/Xenum.hpp>
 * - First some general declarations:
 *	@code
 *	#define XENUM_DECL_Fruits (, Fruits, Fruit)
 *	@endcode
 *   - Note the space between XENUM_DECL_Fruits and the opening parenthesis.
 * - Then the values:
 *	@code
 *	#define XENUM_VALS_Fruits(V,C)		\
 *		V(C, apple)			\
 *		V(C, orange)			\
 *		V(C, lemon)
 *	@endcode
 * - Finally trigger code generation (header part):
 *	@code
 *	XENUM4_DECLARE(Fruits)
 *	@endcode
 *
 * In your source file:
 * - Trigger code generation (source part):
 *	@code
 *	XENUM4_DEFINE(Fruits)
 *	@endcode
 *
 * In this example, "Fruits" is the suffix that ties it all together; The XENUM_DECL and
 * XENUM_VALS macros use this suffix, and the same suffix is passed to XENUM4_DECLARE() and
 * XENUM4_DEFINE() macros, which allows them to find and use the declaration macros. The suffix
 * can be anything, it just needs to be unique (two xenums may not use same suffix, that
 * would redefine the declaration macros).
 *
 * Note that XENUM_DECL_${suffix} and XENUM_VALS_${suffix} are not macro calls, they are macro
 * definitions. XENUM_DECL_${suffix} is a data definition, while XENUM_VALS_${suffix} is a
 * macro function that is evaluated by the xenum generator over and over.
 *
 * XENUM4_DECLARE() and XENUM4_DEFINE() macros are the actual generator functions, to be used
 * in your header and source files respectively.
 *
 * @subsection Basic_Use Use the Xenum
 * - Create/Assign:
 *	@code
 *	// Value objects
 *	Fruit fruit1 = Fruits::apple;
 *	Fruit fruit2 = Fruits::orange;
 *	Fruit fruit3(fruit1); // copy apple
 *	Fruit fruit4 = Fruits::_fromIndex(1); // => orange
 *	Fruit fruit5 = Fruits::_fromIdentifier("lemon"); // => lemon (warning: inefficient string lookup)
 *	// Native enum values. Fruits::_Enum is the native C++ enum class.
 *	Fruits::_Enum value1 = Fruits::_Enum::apple;
 *	Fruits::_Enum value2 = Fruits::orange(); // assign from object
 *	Fruits::_Enum value5 = fruit5(); // assign from object
 *	@endcode
 *   Note the last two: The () operator on an enum value object returns the native enum value.
 *   Fruits::apple() and Fruits::_Enum::apple both yield the same native enum value.
 * - Access the properties of enum values:
 *	@code
 *	const char* ident = fruit1.getIdentifier(); // identifier is the name
 *	Fruits::_Index index = fruit2.getIndex();
 *	Fruits::_Enum nativeEnumValue = fruit3();
 *	@endcode
 *   These are the only properties that Xenum values have (plus any custom properties).
 * - Print:
 *	@code
 *	std::cout << "fruit1:"
 *		  << " index=" << fruit1.getIndex()
 *		  << " identifier='" << fruit1 << "'"
 *		  << std::endl;
 *	@endcode
 *   The default ostream::operator<<() for an Xenum value prints the identifier.
 *
 *   Note that there is no output operator for the native enum value, it is just printed
 *   as an integer.
 * - Comparison works like with native enum values, and value objects can also compare against
 *   native values.
 *	@code
 *	if (fruit1 == fruit3) { ... } // true
 *	if (fruit1 == value1) { ... } // true
 *	if (fruit1 == fruit2) { ... } // false
 *	if (fruit1 != fruit2) { ... } // true
 *	if (fruit1 < fruit2) { ... } // true
 *	if (fruit1 > fruit2) { ... } // false
 *	@endcode
 * - Iterate - notice the parentheses on Fruits():
 *	@code
 *	for (Fruit fruit : Fruits()) { ... }
 *	for (auto fruit : Fruits()) { ... }
 *	@endcode
 *   These are the same. The iterator returns enum value objects.
 * - Iterate old style:
 *	@code
 *	for (Fruits::iterator iter = Fruits.begin(); iter != Fruits.end(); ++iter) {
 *		std::cout << (*iter).getIdentifier() << std::endl;
 *	}
 *	@endcode
 * - Iterate with indexes:
 *	@code
 *	for (Fruits::_Index index = 0; index < Fruits::_size; index++) {
 *		std::cout << Fruits::_fromIndex(index).getIdentifier() << std::endl;
 *	}
 *	@endcode
 * - switch(): C++11 provides type safety for this, which can not be achieved in other ways. So
 *   for switch(), always use a native enum value. If you have an enum-value wrapper object, just
 *   use the () operator to get the native enum value:
 *	@code
 *	switch (fruit()) { // notice the parentheses, retrieves the native enum value
 *	case Fruits::apple():		...; break;
 *	case Fruits::orange():		...; break;
 *	case Fruits::_Enum::lemon:	...; break;
 *	default:			...; break;
 *	}
 *	@endcode
 *
 * @section Example_Custom0 Example: Xenum with simple custom properties
 * First the what and why. If you have some static data associated with each enum value, you
 * could just create an external array, sized using the constexpr Fruits::_size, and a custom
 * lookup function for it. It is just not very OO'ish. Xenum's custom properties allows you
 * to put the associated data into the enum declaration, and have getters generated on the
 * enum value class.
 *
 * Here we extend the xenum with three custom properties:
 * - "Ordinal" of type int, without any default value.
 * - "Sour" of type bool, with default value "false".
 * - "Color" of type string, with default value "unknown".
 *
 * @subsection Custom0_Create Create the xenum
 * In your header file:
 * - \#include <xenum4/Xenum.hpp>
 * - The general declaration:
 *	@code
 *	#define XENUM_DECL_Fruits (my::ns::, Fruits, Fruit, int8_t, , (	\
 *		(Ordinal, int),			\
 *		(Sour, bool, false),		\
 *		(Color, cstring, "unknown")	\
 *		))
 *	@endcode
 *   - Note the "cstring" type of Color. It is really a plain const char*, but strings need
 *     special handling, so you must use this special cooked type name for them. All other
 *     types can just be used as is.
 *   - Besides declaring the custom properties, we also added a few other arguments:
 *     - Namespace path is now defined. This is required when the enum exists in a namespace
 *       and/or class.
 *     - int8_t is now enforced as the integer type to use for the enum values.
 * - The values now also define the values of the custom properties:
 *	@code
 *	#define XENUM_VALS_Fruits(V,C)		\
 *		V(C, apple, 22, , "red")	\
 *		V(C, orange, 44)		\
 *		V(C, lemon, 17, true, "yellow")
 *	@endcode
 *   - Apple has Ordinal=22, Sour=false (default value applied since it is empty), and Color="red".
 *   - Orange has Ordinal=44, Sour=false (default) and Color="varies".
 *   - Lemon has Ordinal=17, Sour=true and Color="yellow".
 *
 * Code generation is like in the first example:
 * - Header part:
 *	@code
 *	XENUM4_DECLARE(Fruits)
 *	@endcode
 * - Source part:
 *	@code
 *	XENUM4_DEFINE(Fruits)
 *	@endcode
 *
 * @subsection Custom0_Use Use the xenum
 * A getter function is created for each property (in the xenum value class):
 *	@code
 *	const int& getOrdinal() const;
 *	const bool& getSour() const;
 *	const char* getColor() const;
 *	@endcode
 * So:
 *	@code
 *	Fruit fruit = Fruits::lemon;
 *	int ord = fruit.getOrdinal(); // => 17
 *	bool sour = fruit.getSour(); // => true
 *	const char* color = fruit.getColor(); // => "yellow"
 *	@endcode
 *
 * @section Example_Custom1 Example: Xenum with an array custom property
 * Well what if a fruit can have multiple colors? We want to declare not one color for it,
 * but a variable-length list.
 *
 * @subsection Custom1_Create Create the xenum
 * In your header file:
 * - \#include <xenum4/Xenum.hpp>
 * - The general declaration:
 *	@code
 *	#define XENUM_DECL_Fruits (my::ns::, Fruits, Fruit, int8_t, , (	\
 *		(Color, cstring, "black", 1)	\
 *		))
 *	@endcode
 *   - Now the default value is "black".
 *   - More importantly, the "1" means that the data has one dimension, which means a single
 *     array of values (0 means data is an immediate value; this is the default we used in
 *     the previous example).
 * - For each enum value, the custom property values are now defined as a list:
 *	@code
 *	#define XENUM_VALS_Fruits(V,C)				\
 *		V(C, apple, ("red", "yellow", "green"))		\
 *		V(C, orange, ("orange", "green"))		\
 *		V(C, lemon, ("yellow"))
 *	@endcode
 *
 * @subsection Custom1_Use Use the xenum
 * The getter function now includes an index, naturally, and you can get the size of the arrays
 * too:
 *	@code
 *	size_t getColorSize() const;
 *	const char* getColor(size_t index) const;
 *	@endcode
 * So:
 *	@code
 *	Fruit fruit = Fruits::orange;
 *	size_t colors = fruit.getColorSize(); // => 2
 *	const char* color0 = fruit.getColor(0); // => "orange"
 *	const char* color1 = fruit.getColor(1); // => "green"
 *	const char* color2 = fruit.getColor(2); // => throws std::out_of_range
 *	@endcode
 *
 * @subsection Custom1_Emptiness Some notes about emptiness
 * - Non-existent values are replaced by their default, as usual. Example:
 *	@code
 *		V(C, orange, ("orange", , "yellow"))
 *	@endcode
 *   The empty value in the middle would be substituted by the default "black" value.
 * - Non-existent arrays are allowed. Example:
 *	@code
 *		V(C, apple, )
 *		V(C, orange)
 *	@endcode
 *   These are equivalent. No defaults are applied to them; these enum values just have zero
 *   custom property values.
 * - Empty arrays are allowed - but they are not really empty! Example:
 *	@code
 *		V(C, lemon, ())
 *	@endcode
 *   Due to preprocessor interpretation, the "()" array is actually an array with one empty
 *   value in it, which will be substituted by the default value. So if you really want an
 *   empty list, do not define it at all.
 *
 * @section Example_Custom2 Example: Xenum with a multilevel-array custom property
 * You are not limited to one-dimensional arrays; any number of dimensions can be added.
 *
 * Arrays can only be indexed by an integer type, so whatever the indexes mean is up to the
 * context you use it in.
 *
 * @subsection Custom2_Create Create the xenum
 * In your header file:
 * - \#include <xenum4/Xenum.hpp>
 * - The general declaration:
 *	@code
 *	#define XENUM_DECL_Fruits (my::ns::, Fruits, Fruit, int8_t, , (	\
 *		(RandNum, int, , 2)	\
 *		))
 *	@endcode
 *   I can not come up with a meaningful example of it, so here is just a two-level array of
 *   random int's, without a default value.
 * - The data must of course now be defined with two levels - arrays in arrays:
 *	@code
 *	#define XENUM_VALS_Fruits(V,C)					\
 *		V(C, apple, ((5,3,7), (11,8), (-22, 44, 1, -9)))	\
 *		V(C, orange, ())					\
 *		V(C, lemon)
 *	@endcode
 *
 * @subsection Custom2_Use Use the xenum
 * The getter functions are extended with one index level:
 *	@code
 *	// size of level0 array
 *	size_t getRandNumSize() const;		
 *	// size of level1 array
 *	size_t getRandNumSize(size_t index1) const;
 *	const char* getRandNum(size_t index1, size_t index2) const;
 *	@endcode
 * So:
 *	@code
 *	size_t size0;
 *	size0 = Fruits::apple.getRandNumSize(); // => 3
 *	size0 = Fruits::orange.getRandNumSize(); // => 1 (empty array is not empty, it contains one undefined child array)
 *	size0 = Fruits::lemon.getRandNumSize(); // => 0
 *
 *	size_t size1;
 *	size1 = Fruits::apple.getRandNumSize(0); // => 3
 *	size1 = Fruits::apple.getRandNumSize(1); // => 2
 *	size1 = Fruits::apple.getRandNumSize(2); // => 4
 *	size1 = Fruits::orange.getRandNumSize(0); // => 0
 *
 *	int randNum:
 *	randNum = Fruits::apple.getRandNum(0, 0); // => 5
 *	randNum = Fruits::apple.getRandNum(1, 1); // => 8
 *	randNum = Fruits::apple.getRandNum(2, 3); // => -9
 *	@endcode

 * @section Reference Reference
 * @subsection XENUM_DECL XENUM_DECL_$suffix
 * The XENUM_DECL_$suffix macro contains general parameters, defined as a tuple (comma-separated
 * values inside parentheses). Syntax:
 *	@code
 *	#define XENUM_DECL_${suffix} (scope, enumClassName, enumValueName [, intType [, features [, custom_properties]]])
 *	@endcode
 * Again note the space between XENUM_DECL_${suffix} and the opening parenthesis.
 * @param scope The containing namespace and/or class. Define this if the call to
 *	XENUM4_DEFINE() is not inside the same namespace and class (if any) as the call to
 *	XENUM4_DECLARE() (or "using" that namespace). If defined, it must end in "::", fx
 *	"my::ns::" (do not quote the value). You may also use a :: prefix to denote
 *	the toplevel namespace, to avoid any relative resolution of namespace.
 *	Note that if the xenum is member in a class (XENUM4_DECLARE() is called from within
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
 * Custom property declaration tuple syntax:
 *	@code
 *	(propertyName, propertyType [, defaultValue [, depth]])
 *	@endcode
 * @param propertyName Name of the custom property.
 * @param propertyType Data-type of the custom property. You may use simple types, like int/bool
 *	types, or even other Xenum's, or other classes, as long as they have a fixed size and a
 *      constexpr constructor. If you want to store strings, you must use the special type
 *      "cstring" (not quoted), it is a plain const char*, but needs special handling in the
 *      generator (because they are really variable-sized arrays).
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
 * @subsection SYMBOLS Generated symbols
 * Everything in the generated code is named to minimize risk of name clashes with other code.
 * But if you get errors about duplicate symbols you may want to check this list.
 *
 * @subsubsection XENUM4_DECLARE XENUM4_DECLARE()
 *	- class \_XenumStore_${container-name} : The internal store class.
 *	- ${valueclass-name} : The enum-value class; an actual class, or a typedef of XenumValue.
 *	- class \_XenumCntnr_${container-name} : The container class.
 *	- ${container-name} : Typedef of container class to desired name.
 *
 * @subsubsection XENUM4_DEFINEE XENUM4_DEFINE()
 *	- namespace \_XenumImpl_${container-name}_[${property-name}] : Zero or more namespaces,
 *	  inside an anonymous namespace, for data/functions that is not declared in the classes.
 *
 * @subsubsection CONTAINER The container class
 * The generated container class contains all the enum values (as objects). Most other symbols
 * in the class have an underscore prefix, to minimize risk of name clashes with your enum value
 * names. This of course assumes that your enum values do not have an underscore prefix.
 *
 * Underscore-prefixed members are:
 *	- \_Value
 *	- \_Index
 *	- \_size
 *	- \_Enum
 *	- \_fromIndex
 *	- \_fromIdentifier
 *	- \_XenumStore_${container-name}
 *
 * A few members do not have an underscore prefix, these are needed by for(:) loops:
 *	- iterator
 *	- begin
 *	- end
 *
 * @section Caveats
 * - Xenum can not be declared inside a class if it has custom properties. The reason is C++'s
 *   rule that class members are not considered complete before the whole class is complete.
 *   This in turn means that one member class can not use another member class, which is what
 *   the Xenum does; first the enum-value class is declared, then the enum-container is declared,
 *   and populated with static constexpr enum-value objects. Which fails since the enum-value
 *   class is not considered "complete" when it is all declared inside another class. The reason
 *   why it works without custom properties is that in this case we do not create a new value
 *   class, we just typedef the base XenumValue class. But when there are custom properties we
 *   need to subclass XenumValue to add getters for the properties.
 * - Name lookup is currently very inefficient, uses linear search. Need to find a way to
 *   generate a static constexpr string-hashtable, or at least a constexpr way to sort the
 *   string list and use binary search.
 * - No API doc for the generated Xenum classes. It is not really possible to generate API doc
 *   for macro-generated functions.
 * - Poor error messages, due to how the preprocessor works. Since this is all implemented with
 *   preprocessor macros, when something goes wrong you tend to get 1000 lines of
 *   incomprehensible error messages, none of which point to where the actual comma is missing.
 * - There is a limit on the number of custom properties, currently 64 or maybe a little less.
 *   This is due to the recursion limit in the preprocessor.
 * - Preprocessing time (wallclock) increases if you add a lot of custom properties, deep
 *   hierarchies, many values. It does not scale very well. Perhaps depends on the preprocessor
 *   used.
 *
 * @section Troubleshooting Troubleshooting / developing / debugging
 * - First of all, when something goes wrong, use trial and error to make your xenum declaration
 *   simpler, until it works.
 * - If you are unsure about correct syntax, see the unit tests for working examples.
 * - You can also use util/xenum-test-gen to generate xenums of any size, just to inspect
 *   how it declares them, and perhaps to test the limits of your own compiler.
 * - Use xenum-inspect script. It runs the preprocessor only on a file of your choice,
 *   and formats the output with indentation and newlines so it is readable. It is the only way
 *   you can actually inspect what all the macro code produces, so it is a crucial tool both in
 *   troubleshooting and development.
 *   - Troubleshooting: Run xenum-inspect only on the source file where the problematic enum is
 *     defined (or even just on the header file where it is declared). Search the output for
 *     "BOOST" and "_XENUM", this is usually the actual error location (a macro call that was
 *     pasted literally instead of being executed). If no such error is found, inspect the
 *     generated code/data, you should at least be able to find what the compiler complains
 *     about.
 *   - Developing/debugging: Normal development cycle is edit -> compile -> run. In Xenum, it is
 *     edit -> xenum-inspect -> read output. At least until that produces correct output, then
 *     back to compiling and running.
 *
 * @section Future_Plans Future plans
 * - Support for more compilers / versions.
 * - Per-enum options:
 *   - Omit identifier string table, if you want to save some space and can do
 *     without conversion to/from string.
 *   - Placement of identifier string table (header/source).
 *   - Omit iteration functions, and perhaps other parts.
 * - Lookup of enum value by custom property value.
 * - Per-custom-property options:
 *   - Placement of property data (header/source).
 *   - Generate lookup function.
 *   - Custom getter prefix.
 * - Make xenum with custom properties work when declared inside a class. Probably requires a
 *   separate XENUM4_DECLARE_PRE() macro call outside the class, ugly.
 * - Efficient string-to-enum lookup. Requires a hashmap, which is difficult given these
 *   requirements: 1) Everything static-const(expr), 2) No external compile tools.
 *   Some template magic may be possible in C++14/17 but for now we stick with C++11.
 * - Custom properties of type bool stored as bits.
 * - Faster compiling. Preprocessor can spend enormous amounts of CPU and RAM.
 * - Some way to generate documentation of the generated code.
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
#ifndef _XENUM4_XENUM_HPP
#define _XENUM4_XENUM_HPP

/// Namespace that Xenum lives in.
/// Note that most of Xenum is macros that ignore namespaces anyway.
#define _XENUM4_NS xenum4

//#include <cstdint>
#include <iostream>
// For SelectInt
#include <type_traits>
// For DeclareCntnr, DefineCntnr
#include <stdexcept>
// For ?
#include <cstring>
// For offsetof()
#include <cstddef>
// For all generators
#include <boost/preprocessor.hpp>
#include <boost/preprocessor/facilities/is_empty.hpp>

#include <xenum4/impl/Util.hpp>
#include <xenum4/impl/SelectInt.hpp>
#include <xenum4/impl/XenumCntnrIterator.hpp>
#include <xenum4/impl/XenumValue.hpp>
#include <xenum4/impl/TupleTree.hpp>
#include <xenum4/impl/Decl.hpp>
#include <xenum4/impl/PropDef.hpp>
#include <xenum4/impl/Ctxt.hpp>
#include <xenum4/impl/IndexNode.hpp>
#include <xenum4/impl/Props.hpp>
#include <xenum4/impl/Plain.hpp>
#include <xenum4/impl/PlainDeclStore.hpp>
#include <xenum4/impl/PlainDeclValue.hpp>
#include <xenum4/impl/PlainDefine.hpp>
#include <xenum4/impl/Cstring.hpp>
#include <xenum4/impl/CstringDeclStore.hpp>
#include <xenum4/impl/CstringDeclValue.hpp>
#include <xenum4/impl/CstringDefine.hpp>
#include <xenum4/impl/DeclareStore.hpp>
#include <xenum4/impl/DeclareCntnr.hpp>
#include <xenum4/impl/DeclareValue.hpp>
#include <xenum4/impl/DefineStore.hpp>
#include <xenum4/impl/DefineCntnr.hpp>
#include <xenum4/impl/Main.hpp>


/**
 * Generate the header parts (declarations) of an Xenum.
 * @param SUFFIX Suffix of your xenum declaration macros.
 * @hideinitializer
 */
#define XENUM4_DECLARE(SUFFIX)									\
	_XENUM4_DO_DECLARE(_XENUM4_CTXT_INIT(SUFFIX))

/**
 * Generate the source parts (definitions) of an Xenum.
 * @param SUFFIX Suffix of your xenum declaration macros.
 * @hideinitializer
 */
#define XENUM4_DEFINE(SUFFIX)									\
	_XENUM4_DO_DEFINE(_XENUM4_CTXT_INIT(SUFFIX))


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
template<class XenumStore>
inline std::ostream& operator<<(std::ostream& out, ::_XENUM4_NS::XenumValue<XenumStore> enumValue) {
	return out << enumValue.getIdentifier();
}


#endif // _XENUM4_XENUM_HPP
