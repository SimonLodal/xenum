# xenum-4.1

## Description
Xenum is a better C++ enum, a native C++11 enum extended with enum size, iteration,
conversion to/from string, and custom properties. All static/const(expr). All the
functionality that native C++ enums lack.

C++11's "enum class" is already a big improvement over earlier plain "enum" which were
just dumb ints. The new "enum class" adds type safety and scoping. But there is still
a lot left to be desired...

## Features
- Access to name (string) and index of an enum-value.
- Lookup enum value by name.
- Lookup enum value by index.
- constexpr size.
- Iteration over enum values.
- switch() on enum value in a typesafe manner.
- Unlimited number of values in an enum. All other extended C++ enum I have found have a
  limit of around 64 or 256 values in an enum, due to recursion limits in preprocessor
  and/or templates. Way too low for real life use. Xenum overcomes this by having the enum
  values declared as a list of macro calls, which can have unlimited length.
- Can be placed inside a class, just like regular enums (except if it has custom properties,
  see Caveats).
- Extensible: You can add custom properties to each enum value. Normal Xenum values
  have an identifier (a name) and an index value (assigned sequentially), but no "ordinal"
  value like a plain enum. However, if you want you can just add an "ordinal" property
  (example below). You can have multiple custom properties. Their datatype can be any plain
  type (integers), strings (C style), or objects, as long as they are constexpr.
  Custom properties can even be multidimensional, fx. a list of strings, or a
  list-of-lists-of-strings, etc.
- Type safety: Inherently uses the type safety of C++11 enum class. Additionally, the
  generated classes are unique for each enum, which also provides type safety; you can not
  assign or compare with other enum classes.
- Implementation is only headers, no source files. Just include Xenum.hpp.
- Everything is static and const(expr). So an xenum can be used in template metaprogramming,
  and also in declaration of data structures, fx. array sizes based on the number of enum
  values.
- No runtime initialization/computation, and no pointers in the generated data.
  This means xenums are friendly for shared libraries; the pages that contain their data
  are truly static so they can be shared between processes.
- Reasonably simple declaration of an enum. Requires a few macros in header, and one in a
  source file. No duplication of value list or other parameters.
- Includes XenumSet; a container with a set of values from an xenum, implemented as a bitset.
- Code generation is macro based.
- Includes a tool (xenum4-inject) to reformat preprocessed output back into readable C++,
  code, so you can inspect what gets generated. The post-processed code even includes
  documentation that doxygen can read.
- xenum4-inject can be used as an external code generator, so you do not run the macro-based
  code generation every time you compile.

## Environment
### Supported compilers
- g++-4.9
- clang-3.5
- Others may or may not work.

### Supported platforms
The Xenum headers should work everywhere but is it possible that some of the util scripts have
some GNU or Unix ism's.

Xenum is being developed on Linux and not currently on Windows or Mac systems so others
will have to test on those.

### Requirements
- Building your own project that uses Xenum:
  - C++11 compiler
  - Boost.Preprocessor (boost-1.64.0 used)
- Building the xenum project:
  - C++11 compiler
  - Boost.Preprocessor (boost-1.64.0 used)
  - gtest (Google Test), for compiling unit tests
  - doxygen, for generating documentation
- Runtime requirements: None.
- perl, if you use the util/ scripts.

### Compile and install
No compiling is *required*, as xenum is all implemented in headers.

You only need to copy ${xenum-root}/xenum/lib/inc/xenum4 directory to somewhere that is in
your compiler's include path, fx. /usr/local/include, so you can \#include <xenum4/Xenum.hpp>.

However, it is very much recommended that you compile and run the unit tests, to make sure
that xenum works with your compiler.

	cd build
	cmake .
	make
Run unit tests (must not fail):

	make test
Generate documentation (doxygen):

	make doc
Install headers and documentation:

	make install

## Design / implementation
C/C++ enums have always confused me. There is the enum, and then there is the individual
values within it. But both are "the enum".

Xenum separates the two, so there are enum values, and a container class that contains the
values. They are distinct classes. And for semantic clarity, they should usually be
named in pluralis and singular form of the same word, fx. Fruits/Fruit, Cards/Card, etc.

So when you create an xenum (say, "Fruits"), two classes are created, the value class
(Fruit) and the container class (Fruits). Actually a third class is also generated, but
only for internal purposes (storage of data related to the enum).

The enum-value class (Fruit) is a very lightweight wrapper around a native enum value.
Being a class, it adds several useful functions. But it adds no data or other overhead
(and is not virtual), so it's size is exactly the same as the native enum value.

The container class contains all the enum values as value objects, so you can refer to
Fruits::apple and Fruits::lemon just like you would with a native C++11 enum class. The
difference is that you get a enum-value objects, not just raw native enum values.

The container class makes the native C++11 enum class available as Fruits::_Enum, should
you want to use them directly. They are equivalent and interchangeable with the enum-value
objects. There should be zero runtime (CPU) overhead in using the value object as the
compiler should treat the value object just like a native enum value.

Implementation is based on preprocessor macros, not templates, at least the core task
of defining the enum values and associated data. Template metaprogramming would have been
nice for it's elegance and power, but it has some shortcomings:
- It can not generate identifiers (the enum values), only types or values.
- Big lists do not work (fx >256 entries), since all iteration over lists is recursive,
  and all preprocessors have a rather small recursion limit.

So for now, we have to deal with 1000 lines of incomprehensible preprocessor error
messages when anything goes wrong.

## Example: Basic xenum
Here we declare a simple "Fruits" enum, with values "apple", "orange", "lemon".

### Create the xenum

#### In your header file
First some general declarations:

	#include <xenum4/Xenum.hpp>
	#define XENUM_DECL_Fruits (, Fruits, Fruit)
Note the space between XENUM_DECL_Fruits and the opening parenthesis.

Then the values:

	#define XENUM_VALS_Fruits(V,C)		\
		V(C, apple)			\
		V(C, orange)			\
		V(C, lemon)

Finally trigger code generation (header part):

	XENUM4_DECLARE(Fruits)

#### In your source file
Trigger code generation (source part):

	XENUM4_DEFINE(Fruits)

#### Explanation
In this example, "Fruits" is the suffix that ties it all together; The XENUM_DECL and
XENUM_VALS macros use this suffix, and the same suffix is passed to XENUM4_DECLARE() and
XENUM4_DEFINE() macros, which allows them to find and use the declaration macros. The suffix
can be anything, it just needs to be unique. Two xenums may not use same suffix, that
would redefine the declaration macros.

Note that XENUM_DECL_${suffix} and XENUM_VALS_${suffix} are not macro calls, they are macro
definitions. XENUM_DECL_${suffix} is a data definition, while XENUM_VALS_${suffix} is a
macro function that is evaluated by the xenum generator over and over.

XENUM4_DECLARE() and XENUM4_DEFINE() macros are the actual generator functions, to be used
in your header and source files respectively.

### Use the Xenum
#### Create/Assign

	// Value objects
	Fruit fruit1 = Fruits::apple;
	Fruit fruit2 = Fruits::orange;
	Fruit fruit3(fruit1); // copy apple
	Fruit fruit4 = Fruits::_fromIndex(1); // => orange
	Fruit fruit5 = Fruits::_fromIdentifier("lemon"); // => lemon (warning: inefficient string lookup)
	// Native enum values. Fruits::_Enum is the native C++ enum class.
	Fruits::_Enum value1 = Fruits::_Enum::apple;
	Fruits::_Enum value2 = Fruits::orange(); // assign from object
	Fruits::_Enum value5 = fruit5(); // assign from object
Note the last two: The () operator on an enum value object returns the native enum value.
Fruits::apple() and Fruits::_Enum::apple both yield the same native enum value.

#### Access the properties of enum values

	const char* ident = fruit1.getIdentifier(); // identifier is the name
	Fruits::_Index index = fruit2.getIndex();
	Fruits::_Enum nativeEnumValue = fruit3();
These are the only properties that Xenum values have (plus any custom properties).

#### Print

	std::cout << "fruit1:"
		<< " index=" << fruit1.getIndex()
		<< " identifier='" << fruit1 << "'"
		<< std::endl;
The default ostream::operator<<() for an Xenum value prints the identifier.

Note that there is no output operator for the native enum value, it is just printed
as an integer.

#### Comparison
Works like with native enum values, and value objects can also compare against
native values.

	if (fruit1 == fruit3) { ... } // true
	if (fruit1 == value1) { ... } // true
	if (fruit1 == fruit2) { ... } // false
	if (fruit1 != fruit2) { ... } // true
	if (fruit1 < fruit2) { ... } // true
	if (fruit1 > fruit2) { ... } // false

#### Iterate new style
Notice the parentheses on Fruits().

	for (Fruit fruit : Fruits()) {
		std::cout << fruit.getIdentifier() << std::endl;
	}
The iterator returns enum-value objects.

#### Iterate old style

	for (Fruits::iterator iter = Fruits::begin(); iter != Fruits::end(); ++iter) {
		std::cout << (*iter).getIdentifier() << std::endl;
	}

#### Iterate with indexes

	for (Fruits::_Index index = 0; index < Fruits::_size; index++) {
		std::cout << Fruits::_fromIndex(index).getIdentifier() << std::endl;
	}

#### switch()
C++11 provides type safety for this, which can not be achieved in other ways. So
for switch(), always use a native enum value. If you have an enum-value wrapper object, just
use the () operator to get the native enum value:

	switch (fruit()) { // notice the parentheses, retrieves the native enum value
	case Fruits::apple():		...; break;
	case Fruits::orange():		...; break;
	case Fruits::_Enum::lemon:	...; break;
	default:			...; break;
	}

## Example: Xenum with simple custom properties
First the what and why. If you have some static data associated with each enum value, you
could just create an external array, sized using the constexpr Fruits::_size, and a custom
lookup function for it. It is just not very OO'ish. Xenum's custom properties allows you
to put the associated data into the enum declaration, and have getters generated on the
enum value class.

Here we extend the xenum with three custom properties:
- "Ordinal" of type int, without any default value.
- "Sour" of type bool, with default value "false".
- "Color" of type string, with default value "unknown".

### Create the xenum
In your header file:

	#include <xenum4/Xenum.hpp>
	#define XENUM_DECL_Fruits (my::ns::, Fruits, Fruit, int16_t, , (	\
		(Ordinal, int),			\
		(Sour, bool, false),		\
		(Color, cstring, "unknown")	\
		))
Note the "cstring" type of Color. It is really a plain const char*, but strings need
special handling, so you must use this special cooked type name for them. All other
types can just be used as is.

Besides declaring the custom properties, we also added a few other arguments:
- Namespace path is now defined. This is required when the enum exists in a namespace
  and/or class.
- int16_t is now enforced as the integer type to use for the enum values. The default is
  to use the smallest type that is big enough to hold the number of enum values.

The values macro now also define the values of the custom properties:

	#define XENUM_VALS_Fruits(V,C)		\
		V(C, apple, 22, , "red")	\
		V(C, orange, 44)		\
		V(C, lemon, 17, true, "yellow")
So:
- Apple has Ordinal=22, Sour=false (default value applied since it is empty), and Color="red".
- Orange has Ordinal=44, Sour=false (default) and Color="varies".
- Lemon has Ordinal=17, Sour=true and Color="yellow".

Code generation is like in the first example:
Header part:

	XENUM4_DECLARE(Fruits)
Source part:

	XENUM4_DEFINE(Fruits)

### Use the xenum
A getter function is created for each property (in the xenum value class):

	const int& getOrdinal() const;
	const bool& getSour() const;
	const char* getColor() const;
So you can do:

	Fruit fruit = Fruits::lemon;
	int ord = fruit.getOrdinal(); // => 17
	bool sour = fruit.getSour(); // => true
	const char* color = fruit.getColor(); // => "yellow"

## Example: Xenum with an array custom property
Well what if a fruit can have multiple colors? We want to declare not one color for it,
but a variable-length list.

### Create the xenum
In your header file:

	#include <xenum4/Xenum.hpp>

The general declaration:

	#define XENUM_DECL_Fruits (my::ns::, Fruits, Fruit, int16_t, , (	\
		(Color, cstring, "black", 1)	\
		))
- Now the default value is "black".
- More importantly, the "1" means that the data has one dimension, which means a single
  array of values (0 means data is an immediate value; this is the default we used in
  the previous example).

For each enum value, the custom property values are now defined as a list:

	#define XENUM_VALS_Fruits(V,C)				\
		V(C, apple, ("red", "yellow", "green"))		\
		V(C, orange, ("orange", "green"))		\
		V(C, lemon, ("yellow"))

### Use the xenum
The getter function now includes an index, naturally, and you can get the size of the arrays
too:

	size_t getColorSize() const;
	const char* getColor(size_t index) const;
So you can do:

	Fruit fruit = Fruits::orange;
	size_t colors = fruit.getColorSize(); // => 2
	const char* color0 = fruit.getColor(0); // => "orange"
	const char* color1 = fruit.getColor(1); // => "green"
	const char* color2 = fruit.getColor(2); // => throws std::out_of_range

### Some notes about emptiness
Non-existent values are replaced by their default, as usual. Example:

	V(C, orange, ("orange", , "yellow"))

The empty value in the middle is substituted by the default "black" value.

Non-existent arrays are allowed. Example:

	V(C, apple, )
	V(C, orange)
These are equivalent. No defaults are applied to them; these enum values just have zero
custom property values. Their getColorSize() returns 0, and any getColor() call throws
an out-of-bounds exception.

Empty array declarations are allowed - but they are not really empty! Example:

	V(C, lemon, ())
Due to preprocessor interpretation, the "()" array is actually an array with one empty
value in it, which will be substituted by the default value. So if you really want an
empty array, do not define it at all.

## Example: Xenum with a multilevel-array custom property
You are not limited to one-dimensional arrays; any number of dimensions can be added.

Arrays can only be indexed by an integer type, so whatever the indexes mean is up to the
context you use it in.

### Create the xenum
In your header file:

	#include <xenum4/Xenum.hpp>
	#define XENUM_DECL_Fruits (my::ns::, Fruits, Fruit, int16_t, , (	\
		(RandNum, int, , 2)	\
		))
I can not come up with a meaningful example of it, so here is just a two-level array of
random int's, without a default value.

The data must of course now be defined with two levels - arrays in arrays:

	#define XENUM_VALS_Fruits(V,C)					\
		V(C, apple, ((5,3,7), (11,8), (-22, 44, 1, -9)))	\
		V(C, orange, ())					\
		V(C, lemon)

### Use the xenum
The getter functions are extended with one index level:

	// size of level0 array
	size_t getRandNumSize() const;		
	// size of level1 array
	size_t getRandNumSize(size_t index1) const;
	const char* getRandNum(size_t index1, size_t index2) const;
So:

	size_t size0;
	size0 = Fruits::apple.getRandNumSize(); // => 3
	size0 = Fruits::orange.getRandNumSize(); // => 1 (empty array is not empty, it contains one undefined child array)
	size0 = Fruits::lemon.getRandNumSize(); // => 0

	size_t size1;
	size1 = Fruits::apple.getRandNumSize(0); // => 3
	size1 = Fruits::apple.getRandNumSize(1); // => 2
	size1 = Fruits::apple.getRandNumSize(2); // => 4
	size1 = Fruits::orange.getRandNumSize(0); // => 0

	int randNum:
	randNum = Fruits::apple.getRandNum(0, 0); // => 5
	randNum = Fruits::apple.getRandNum(1, 1); // => 8
	randNum = Fruits::apple.getRandNum(2, 3); // => -9

## Reference
### XENUM_DECL_$suffix
The XENUM_DECL_$suffix macro contains general parameters, defined as a tuple (comma-separated
values inside parentheses). Syntax:

	#define XENUM_DECL_${suffix} (scope, enumClassName, enumValueName [, intType [, features [, custom_properties]]])

Again note the space between XENUM_DECL_${suffix} and the opening parenthesis.

Parameters:
- **scope** The containing namespace and/or class. Define this if the call to
  XENUM4_DEFINE() is not inside the same namespace and class (if any) as the call to
  XENUM4_DECLARE() (or "using" that namespace). If defined, it must end in "::", fx
  "my::ns::" (not quoted). You may also use a :: prefix to denote the toplevel namespace,
  to avoid any relative resolution of namespace.

  Note that if the xenum is member in a class (XENUM4_DECLARE() is called from within
  a class), the scope MUST contain at least the class name, if not also the namespace.
- **enumClassName** Name of the generated enum-container class, fx. "Fruits" (not quoted).
- **enumValueName** Name of the generated enum-value class, fx. "Fruit" (not quoted).
- **intType** Optional. Integer-type for the enum values. Should be unsigned, and must be large
  enough to hold the number of enum values (compile-time error if not). Leave empty
  to let Xenum decide the smallest possible type.
- **features** Optional. Not implemented yet. Leave empty for now.
- **properties** Optional. Defines custom properties. Leave field empty/undefined if the
  xenum does not have any custom properties. If defined, it must be a tuple of one or
  more tuples that each define a property (see below).

Custom property tuple syntax:

	(propertyName, propertyType [, defaultValue [, depth]])

Parameters:
- **propertyName** Name of the custom property.
- **propertyType** Data-type of the custom property. You may use simple types, like int/bool
  types, or even other Xenum's, or other classes, as long as they have a fixed size and a
  constexpr constructor. If you want to store strings, you must use the special type
  "cstring" (not quoted), it is a plain const char*, but needs special handling in the
  generator (because they are really variable-sized arrays).
- **defaultValue** Optional (default=none). Default value to apply if an enum value does not
  define a value for this property.
- **depth** Optional (default=0). Defines number of array levels. Depth=0 means each enum value
  has exactly one value for this custom property. Depth=1 means that each enum value has an
  array of values. Depth=2 means they each have a two-level array of values, etc. Array sizes
  are not fixed; you can make them any length (up to preprocessor limit of maybe 64 or 256).
  Arrays can also be empty or non-existent (empty branches allowed).
  Arrays are indexed by the smallest possible integer (decided by Xenum) (but may be converted
  to/from size_t).
  Values can only exist as leaf nodes in the data hierarchy, that is, they can only appear
  at level $depth, not somewhere in between.

### XENUM_VALS XENUM_VALS_${suffix}()
The XENUM_VALS macro defines the enum-values, as a series of calls to a V() macro that is
passed as a parameter itself. Syntax:

	#define XENUM_VALS_${suffix}(V,C)	\
		V(C, value0 [, custom0 [, custom1 [, ...]]])	\
		V(C, value1 [, custom0 [, custom1 [, ...]]])	\
		...				\
		V(C, valueN [, custom0 [, custom1 [, ...]]])

The V() macro:
- **C** The same "C" that your XENUM_VALS_${suffix}() macro was called with; a "context"
  data structure used to pass variables around between internal functions.
- **value** The enum-value name (identifier), fx. "foo" (not quoted).
- **custom** Zero or more custom property values; must match the ones defined in the
  XENUM_DECL_$suffix macro. If a value field is empty, the default defined in
  XENUM_DECL_$suffix is used, if there is one (if not all values must be specified).

### Generated symbols
Everything in the generated code is named to minimize risk of name clashes with other code.
But if you get errors about duplicate symbols you may want to check this list.

#### XENUM4_DECLARE()
- class \_XenumStore_${container-name} : The internal store class.
- ${valueclass-name} : The enum-value class; an actual class, or a typedef of XenumValue.
- class ${container-name} : The container class.

#### XENUM4_DEFINE()
- namespace \_XenumImpl_${suffix}_* : Zero or more namespaces,
  inside an anonymous namespace, for data/functions that is not declared in the classes.

#### The container class
The generated container class contains all the enum values (as objects). Most other symbols
in the class have an underscore prefix, to minimize risk of name clashes with your enum value
names. This of course assumes that your enum values do not have an underscore prefix.

Underscore-prefixed members are:
- \_Value
- \_Index
- \_size
- \_Enum
- \_fromIndex
- \_fromIdentifier
- \_XenumStore_${container-name}

A few members do not have an underscore prefix, these are needed by for(:) loops:
- iterator
- begin
- end

### Limits
- Number of values in an enum: Unlimited
- Custom properties: Almost everything is subject to preprocessor recursion limit of 64 (or
  a little less). So:
  - Max number of custom properties in an enum: 64
  - Max depth of a custom property data hierarchy: 64
  - Max number of childnodes (or values) at any point in the data hierarchy: 64.

  So if you have a custom property with depth=1, the array of values (per enum value) can
  be no larger than 64. However, if your have depth>1, each leafnode can contain it's own
  array of up to 64 values.

## Reviving the generated code
Xenum is macro-based. The disadvantage is that the generated code is only readable to
a compiler, not to a human. The util/xenum4-inject script helps to overcome this.

xenum4-inject runs the preprocessor on a single header or source file. It replaces the main
macros (XENUM4_DECLARE() and XENUM4_DEFINE()) with the content they produce, and leaves
everything else as is. The generated sections are reformatted with indentation, newlines
and documentation comments. The result is both human readable, and valid C++, which can be
compiled to produce exactly the same result as compiling the original file.

What you can use this for:
- Inspecting the generated code.
- Generate API documentation for the generated classes. See build/CMakeLists.txt for an
  example of how to set this up (on the xenums used in the unit tests). Maybe not perfect,
  but working.
- Use as an external code generator that only runs when necessary. Basically the same setup
  as for doxygen, except the output files must be compiled as part of your project, not the
  input files (and you need to run xenum4-inject both on header and source files).

## Caveats
- Xenum can not be declared inside a class if it has custom properties. The reason is C++'s
  rule that class members are not considered complete before the whole class is complete.
  This in turn means that one member class can not use another member class, which is what
  the Xenum does; first the enum-value class is declared, then the enum-container is declared,
  and populated with static constexpr enum-value objects. Which fails since the enum-value
  class is not considered "complete" when it is all declared inside another class. The reason
  why it works without custom properties is that in this case we do not create a new value
  class, we just typedef the base XenumValue class. But when there are custom properties we
  need to subclass XenumValue to add getters for the properties.
- Name lookup is currently very inefficient, uses linear search. Need to find a way to
  generate a static constexpr string-hashtable, or at least a constexpr way to sort the
  string list and use binary search.
- Poor error messages, due to how the preprocessor works. Since this is all implemented with
  preprocessor macros, when something goes wrong you tend to get 1000 lines of
  incomprehensible error messages, none of which point to where the actual comma is missing.
- Preprocessing time (wallclock) increases if you add a lot of custom properties, deep
  hierarchies, many values. It does not scale very well. Perhaps depends on the preprocessor
  used.

## Troubleshooting / developing / debugging
- First of all, when something goes wrong, use trial and error to make your xenum declaration
  simpler, until it works.
- If you are unsure about correct syntax, see the unit tests for working examples.
- You can also use util/xenum4-test-gen to generate xenums of any size, just to inspect
  how it declares them, and perhaps to test the limits of your own compiler.
- Use util/xenum4-inject script to view the generated code. It is the only way you can
  actually inspect what all the macro code produces, so it is a crucial tool both in
  troubleshooting and development.
  - Troubleshooting: Run xenum4-inject only on the header or source file where the problematic
    enum is defined. Search the output for "BOOST" and "_XENUM", this is usually the actual
    error location (a macro call that was pasted literally instead of being executed). If no
    such error is found, inspect the generated code/data, you should at least be able to find
    what the compiler complains about.
  - Developing/debugging: Normal development cycle is edit -> compile -> run. In Xenum, it is
    edit -> xenum4-inject -> read output. At least until that produces correct output, then
    back to compiling and running.

## Future plans
- Support for more compilers / versions.
- Per-enum options:
  - Omit identifier string table, if you want to save some space and can do
    without conversion to/from string.
  - Placement of identifier string table (header/source).
  - Omit iteration functions, and perhaps other parts.
- Lookup of enum value by custom property value.
- Per-custom-property options:
  - Placement of property data (header/source).
  - Generate lookup function.
  - Custom getter prefix.
- Make xenum with custom properties work when declared inside a class. Probably requires a
  separate XENUM4_DECLARE_PRE() macro call outside the class, ugly.
- Efficient string-to-enum lookup. Requires a hashmap, which is difficult given these
  requirements: 1) Everything static-const(expr), 2) No external compile tools.
  Some template magic may be possible in C++14/17 but for now we stick with C++11.
- Custom properties of type bool stored as bits.
- Faster compiling. Preprocessor can spend enormous amounts of CPU and RAM.
- Enum class inheritance (maybe).
- Custom code injection (maybe - if custom properties are not enough).

## Versioning
Major version is increased when introducing incompatible API changes.

Minor versions may include features/changes that have sane, backwards-compatible
(within same major version) defaults, and do not require changes to users' code.

All preprocessor symbols have a versioned prefix (_XENUM${MAJORVERSION}).
Toplevel directory and namespace are also versioned (xenum${majorversion}).

This allows different versions to be used in the same project. Very convenient
when you might want to upgrade, but not update all the enum definitions at once.

## Contributing
Any feedback, criticism or ideas, is appreciated.

And of course, patches are welcome.