# xenum-5.1-pre2

## Description
Want better C++ enums?

Xenum is a macro-based code generator. It creates wrapper classes around native C++11 enums,
adding a lot of functionality that they lack.

## Features
Enums:
- To/from string
- Iteration
- constexpr size
- XenumSet: Bit-based set of values from an xenum
- Custom properties: Static data associated with each enum value.

Implementation:
- No duplicate declaration of values
- Unlimited number of values in an enum. Most other 'smart' C++ enums are limited to around
  64 or 256 values due to recursion limits in preprocessor and/or templates.
- Everything is static and const(expr).
- No runtime initialization/computation, and no pointers in the generated data (friendly for
  shared libraries).
- Type safety: Based on C++11 'enum class'. And generates unique wrapper classes for each enum.
- Can be placed inside a class, just like regular enums (except if it has custom properties,
  see Caveats).
- Headers only. Just include Xenum.hpp.
- xenum5-inject tool reformats preprocessed output back into readable C++ code.
  - You can inspect what gets generated.
  - You can run doxygen on the post-processed code.
  - It can even be used as an external code generator.

## Environment
### Supported compilers
- g++-4.9
- clang-3.5
- Others may or may not work.

### Supported platforms
The Xenum headers should work everywhere but some of the util scripts have some GNU or Unix
-ism's.

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

You only need to copy ${xenum-root}/xenum/lib/inc/xenum5 directory to somewhere that is in
your compiler's include path, fx. /usr/local/include, so you can \#include <xenum5/Xenum.hpp>.

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

The container class makes the native C++11 enum class available as Fruits::_enum, should
you want to use them directly. They are equivalent and interchangeable with the enum-value
objects. There should be zero runtime (CPU) overhead in using the value object as the
compiler should treat the value object just like a native enum value.

Implementation is based on preprocessor macros, not templates, at least the core task
of defining the enum values and associated data. Template metaprogramming would have been
nice for it's elegance and power, but it has some shortcomings:
- It can not generate identifiers (the enum values, and associated getter functions), only
  types or values.
- Big lists do not work (fx >256 entries), since all iteration over lists is recursive,
  and all preprocessors have a rather small recursion limit.

## Example: Basic xenum
Here we declare a simple "Fruits" enum, with values "apple", "orange", "lemon".

### Create the xenum

#### In your header file
First the declaration of the enum:

	#include <xenum5/Xenum.hpp>
	#define XENUM5_Fruits(D,V,C)		\
		D(C, , Fruits, Fruit)		\
		V(C, apple)			\
		V(C, orange)			\
		V(C, lemon)

Trigger code generation (header part):

	XENUM5_DECLARE(Fruits)

#### In your source file
Trigger code generation (source part):

	XENUM5_DEFINE(Fruits)

#### Explanation
In this example, "Fruits" is the suffix that ties it all together; The XENUM5_Fruits declaration
macro uses this suffix, and the same suffix is passed to XENUM5_DECLARE() and
XENUM5_DEFINE() macros, which allows them to find and use the declaration macro. The suffix
can be anything, it just needs to be unique. Two xenums may not use same suffix, that
would redefine the declaration macro.

Note that XENUM5_${suffix} is a macro function that you define, by itself it does not do anything,
but it is evaluated by the xenum generator over and over. The D, V and C parameters are callback
macro functions and data, defined by the generators. Just consider them boilerplate stuff that
has to be there.

XENUM5_DECLARE() and XENUM5_DEFINE() macros are the actual generator functions, to be used
in your header and source files respectively.

### Use the Xenum
#### Create/Assign

	// Value objects
	Fruit fruit1 = Fruits::apple;
	Fruit fruit2 = Fruits::orange;
	Fruit fruit3(fruit1); // copy apple
	Fruit fruit4 = Fruits::_fromIndex(1); // => orange
	Fruit fruit5 = Fruits::_fromIdentifier("lemon"); // => lemon (warning: inefficient string lookup)
	// Native enum values. Fruits::_enum is the native C++ enum class.
	Fruits::_enum value1 = Fruits::_enum::apple;
	Fruits::_enum value2 = Fruits::orange(); // assign from object
	Fruits::_enum value5 = fruit5(); // assign from object
Note the last two: The () operator on an enum value object returns the native enum value.
Fruits::apple() and Fruits::_enum::apple both yield the same native enum value.

#### Access the properties of enum values

	const char* ident = fruit1.getIdentifier(); // identifier is the name
	Fruits::_index_t index = fruit2.getIndex();
	Fruits::_enum nativeEnumValue = fruit3();
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

	for (Fruits::_index_t index = 0; index < Fruits::_size; index++) {
		std::cout << Fruits::_fromIndex(index).getIdentifier() << std::endl;
	}

#### switch()
C++11 provides type safety for this, which can not be achieved in other ways. So
for switch(), always use a native enum value. If you have an enum-value wrapper object, just
use the () operator to get the native enum value:

	switch (fruit()) { // notice the parentheses, retrieves the native enum value
	case Fruits::apple():		...; break;
	case Fruits::orange():		...; break;
	case Fruits::_enum::lemon:	...; break;
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

	#include <xenum5/Xenum.hpp>
	#define XENUM5_Fruits(D,V,C)				\
		D(C, my::ns::, Fruits, Fruit, int16_t, , (	\
			(Ordinal, int),				\
			(Sour, bool, false),			\
			(Color, cstring, "unknown")		\
		))						\
		V(C, apple, 22, , "red")			\
		V(C, orange, 44)				\
		V(C, lemon, 17, true, "yellow")

Several things to note here:
- Namespace path is now defined. This is required when the enum exists in a namespace
  and/or class.
- int16_t is now enforced as the integer type to use for the enum values. The default is
  to use the smallest type that is big enough to hold the number of enum values.
- The custom properties are defined as separate lists.
- Color has the special type "cstring". It is really a plain const char*, but strings need
  special handling, so you must use this special cooked type name for them. All other
  types can just be used as is.
- The values (the V() macros) now also define the values of the custom properties.

So:
- Apple has Ordinal=22, Sour=false (default value applied since it is empty), and Color="red".
- Orange has Ordinal=44, Sour=false (default) and Color="varies".
- Lemon has Ordinal=17, Sour=true and Color="yellow".

Code generation is like in the first example:
Header part:

	XENUM5_DECLARE(Fruits)
Source part:

	XENUM5_DEFINE(Fruits)

### Use the xenum
In the xenum value class, a getter function is created for each property:

	const int& getOrdinal() const noexcept;
	const bool& getSour() const noexcept;
	const char* getColor() const noexcept;
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

	#include <xenum5/Xenum.hpp>
	#define XENUM5_Fruits(D,V,C)				\
		D(C, my::ns::, Fruits, Fruit, int16_t, , (	\
			(Color, cstring, "black", 1)		\
		))						\
		V(C, apple, ("red", "yellow", "green"))		\
		V(C, orange, ("orange", "green"))		\
		V(C, lemon, ("yellow"))

- Now the default value is "black".
- More importantly, the "1" after "black" means that the data has one dimension, which means
  a single array of values (0 means data is an immediate value; this is the default we used in
  the previous example).
- For each enum value, the custom property values are now defined as a list.

### Use the xenum
The getter function now includes an index, naturally, and you can get the size of the arrays
too:

	using ColorIndex = size_t;
	ColorIndex getColorSize() const noexcept;
	const char* getColor(ColorIndex index) const;
So you can do:

	Fruit fruit = Fruits::orange;
	auto colors = fruit.getColorSize(); // => 2
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

I can not come up with a meaningful example of it, so here is just a two-level array of
random int's, without a default value.

### Create the xenum
In your header file:

	#include <xenum5/Xenum.hpp>
	#define XENUM5_Fruits(D,V,C)					\
		D(C, my::ns::, Fruits, Fruit, int16_t, , (		\
			(RandNum, int, , 2)				\
		))							\
		V(C, apple, ((5,3,7), (11,8), (-22, 44, 1, -9)))	\
		V(C, orange, ())					\
		V(C, lemon)

Note that the data is now defined with two levels - arrays in arrays.

### Use the xenum
The getter functions are extended with one index level:

	using RandNumIndex = size_t;
	// size of level0 array
	RandNumIndex getRandNumSize() const noexcept;
	// size of level1 array
	RandNumIndex getRandNumSize(RandNumIndex index1) const;
	const char* getRandNum(RandNumIndex index1, RandNumIndex index2) const;
So:

	RandNumIndex size0;
	size0 = Fruits::apple.getRandNumSize(); // => 3
	size0 = Fruits::orange.getRandNumSize(); // => 1 (empty array is not empty, it contains one undefined child array)
	size0 = Fruits::lemon.getRandNumSize(); // => 0

	RandNumIndex size1;
	size1 = Fruits::apple.getRandNumSize(0); // => 3
	size1 = Fruits::apple.getRandNumSize(1); // => 2
	size1 = Fruits::apple.getRandNumSize(2); // => 4
	size1 = Fruits::orange.getRandNumSize(0); // => 0

	int randNum:
	randNum = Fruits::apple.getRandNum(0, 0); // => 5
	randNum = Fruits::apple.getRandNum(1, 1); // => 8
	randNum = Fruits::apple.getRandNum(2, 3); // => -9

## Reference
### XENUM5_$suffix
The XENUM5_$suffix macro is defined by user, and contains the complete declaration of the xenum.
It contains a series of calls to D() and V() macros that are provided by the xenum generator
which calls the declaration repeatedly. Syntax:

	#define XENUM5_${suffix}(D,V,C)		\
		D(C, scope, enumClassName, enumValueName [, intType [, features [, custom_properties]]]) \
		V(C, value0 [, custom0 [, custom1 [, ...]]])	\
		V(C, value1 [, custom0 [, custom1 [, ...]]])	\
		...				\
		V(C, valueN [, custom0 [, custom1 [, ...]]])

#### D() macro
This callback defines general parameters of the enum.

- **C** The same "C" that XENUM5_${suffix}() was called with; a "context" data structure
  used to pass variables around between internal functions.
- **scope** The containing namespace and/or class. Define this if the call to
  XENUM5_DEFINE() is not inside the same namespace and class (if any) as the call to
  XENUM5_DECLARE() (or "using" that namespace). If defined, it must end in "::", fx
  "my::ns::" (not quoted). You may also use a :: prefix to denote the toplevel namespace,
  to avoid any relative resolution of namespace.

  Note that if the xenum is member in a class (XENUM5_DECLARE() is called from within
  a class), the scope MUST contain at least the class name, if not also the namespace.
- **enumClassName** Name of the generated enum-container class, fx. "Fruits" (not quoted).
- **enumValueName** Name of the generated enum-value class, fx. "Fruit" (not quoted).
- **intType** Optional. Integer-type for the enum values. Should be unsigned, and must be large
  enough to hold the number of enum values (compile-time error if not). Leave empty
  to let Xenum decide the smallest possible type.
- **features** Optional. A list (comma-separated, in parentheses) of not so common
  features/options (more may be added):
  - [0] (getIdentifier): How to implement the getIdentifier() method. See discussion below.
    Valid values are:
    - off: Do not implement this method.
    - ext (the default, if empty): Declare in generated header, define in generated source.
    - cxp: Declare and define constexpr, in generated header.
  - [1] (fromIdentifier): How to implement the fromIdentifier() method. See discussion below.
    Valid values are:
    - off: Do not implement this method.
    - ext (the default, if empty): Declare in generated header, define in generated source.
    - inl: Declare and define inline, but not constexpr, in generated header.
    - cxp: Declare and define constexpr, in generated header.
- **properties** Optional. Defines custom properties. Leave field empty/undefined if the
  xenum does not have any custom properties. If defined, it must be a tuple of one or
  more tuples that each define a property (see below).

Custom property tuple syntax:

	(propertyName, propertyType [, defaultValue [, depth [, features]]])

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
- **features** Optional. A list (comma-separated, in parentheses) of not so common
  features/options (more may be added):
  - [0] (get${propertyName}): How to implement the getter method for this custom property.
    See discussion below. Valid values are:
    - ext (the default, if empty): Declare in generated header, define in generated source.
    - cxp: Declare and define constexpr, in generated header.


##### Warning about inline/constexpr methods
You can implement the get*() and from*() functions for identifiers and custom properties in
different ways (the options above). The default ("ext" option) is to generate their declaration
in the header, and the definition (along with related data) in the source file.

You can also have these functions implemented inline or constexpr, but you should only use
these options if you really need constexpr access to the data, or for some reason want it to
be inlined. They come with big costs.

- Compile time cost: All source units that include the header will run the whole code generation
  (several iterations over the whole xenum declaration). This can take considerable time if your
  xenum is big/complex. When using "ext", this only happens for the source file where the xenum
  is defined.
- Runtime cost: Inline from*() and constexpr get*() methods are fine, but the constexpr from*()
  methods are slow. Reason is that non-constexpr functions can use strcmp() and other functions
  that are highly optimized, but since such library functions are usually not constexpr themselves,
  we have to use other implementations of these functions, which are much, much slower.
  The only advantage to constexpr is that you can use the method at compile time. The price is
  terrible runtime performance. In the future C++ may allow to define different code for constexpr
  and non-constexpr, but until then, this is a problem for everyone.

You can also define a get*() or from*() method implementation as "off" to omit it, it might save
some space in your compiled binary.

#### V() macro
This callback defines a single enum value.

- **C** Same as in D() macro.
- **value** The enum-value name (identifier), fx. "foo" (not quoted).
- **custom...** Zero or more custom property values; must match the ones defined in the
  D() macro. If a value field is empty, the default defined in D() is used, if there is one
  (if not all values must be specified).

### Generated symbols
Everything in the generated code is named to minimize risk of name clashes with other code.
But if you get errors about duplicate symbols you may want to check this list.

#### XENUM5_DECLARE()
- class \_xenum5_store_${enumClassName} : The internal store class.
- ${enumValueName} : The enum-value class; an actual class, or a typedef of XenumValue.
- class ${enumClassName} : The container class.

#### XENUM5_DEFINE()
- namespace \_XenumImpl_${suffix}_* : Zero or more namespaces,
  inside an anonymous namespace, for data/functions that is not declared in the classes.

#### The container class
The generated container class contains all the enum values (as objects). Most other symbols
in the class have an underscore prefix, to minimize risk of name clashes with your enum value
names. This of course assumes that your enum values do not have an underscore prefix.

Underscore-prefixed members are:
- \_value_t
- \_index_t
- \_size
- \_enum
- \_fromIndex
- \_fromIdentifier

A few members do not have an underscore prefix.
- The default constructor
- iterator
- begin
- end

iterator(), begin() and end() are needed by for(:) loops.

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
a compiler, not to a human. The util/xenum5-inject script helps to overcome this.

xenum5-inject runs the preprocessor on a single header or source file. It replaces the main
macros (XENUM5_DECLARE() and XENUM5_DEFINE()) with the content they produce, and leaves
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
  input files (and you need to run xenum5-inject both on header and source files).

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
- Preprocessing time (wallclock) increases if you add a lot of custom properties, deep
  hierarchies, many values. It does not scale very well. Perhaps depends on the preprocessor
  used.

## Troubleshooting / developing / debugging
What to do when your xenum declaration does not work, the preprocessor just spews a large
number of errors, and none of them make any sense?

- The xenum declaration (the D() macro) is validated to some extent. If an error is found, a
  static_assert() is generated instead of any other content. The compiler will fail, probably
  with a lot of errors, but the static_assert should be the first. Read it.
- If you are unsure about correct syntax, see the reference above, and the unit tests for
  working examples.
- Use trial and error to make your xenum declaration simpler, until it works.
- You can also use util/xenum5-test-gen to generate xenums of any size, just to inspect
  how it declares them, and perhaps to test the limits of your own compiler.
- Use util/xenum5-inject script to view the generated code. It is the only way you can
  actually inspect what all the macro code produces, so it is a crucial tool both in
  troubleshooting and development.
  - Troubleshooting: Run xenum5-inject only on the header or source file where the problematic
    enum is defined. Search the output for "BOOST" and "XENUM", this is often the actual
    error location (a macro call that was pasted literally instead of being executed). If no
    such error is found, inspect the generated code/data, you should at least be able to find
    what the compiler complains about.
  - Developing/debugging: Normal development cycle is edit -> compile -> run. In Xenum, it is
    edit -> xenum5-inject -> read output. At least until that produces correct output, then
    back to compiling and running.

## Future plans
- Support for more compilers / versions.
- Per-enum options:
  - Omit iteration functions, and perhaps other parts.
- Lookup of enum value by custom property value.
- Per-custom-property options:
  - Generate lookup function.
  - Custom getter prefix.
- Make xenum with custom properties work when declared inside a class. Probably requires a
  separate XENUM5_DECLARE_PRE() macro call outside the class, ugly.
- Efficient string-to-enum lookup. Requires a hashmap, which is difficult given these
  requirements: 1) Everything static-const(expr), 2) No external compile tools.
  Some template magic may be possible in C++14/17 but for now we stick with C++11.
- Custom properties of type bool stored as bits.
- Faster compiling. Preprocessor can spend enormous amounts of CPU and RAM.
- Enum class inheritance (maybe).
- Custom code injection (maybe - if custom properties are not enough).

## Versioning
Major version is increased when introducing incompatible changes to the public API.

Minor versions may include features/changes that have sane, backwards-compatible
(within same major version) defaults, and do not require changes to users' code.

All preprocessor symbols have a versioned prefix (_XENUM${MAJORVERSION}).
Toplevel directory and namespace are also versioned (xenum${majorversion}).

This allows different versions to be used in the same project. Very convenient
when you might want to upgrade, but not update all the enum definitions at once.

## Contributing
Any feedback, criticism or ideas, is appreciated.

And of course, patches are welcome.
