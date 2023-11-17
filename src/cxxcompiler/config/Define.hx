// =======================================================
// * Define
//
// List all the custom defines used in this project and
// provides access using a String enum abstract.
// =======================================================

package cxxcompiler.config;

enum abstract Define(String) from String to String {
	/**
		-D cxx_callstack

		If defined, Reflaxe/C++ will generate content to track
		the Haxe callstack in C++ code. This define is required
		to use the `haxe.CallStack` class.
	**/
	var Callstack = "cxx_callstack";

	/**
		-D cxx_imprecise_number_types

		If defined, the `cxx.num` will use relative approximation
		number types that do not require an #include.
	**/
	var ImpreciseNumberTypes = "cxx_imprecise_number_types";

	/**
		-D cxx_exceptions_disabled

		If defined, Reflaxe/C++ will avoid generating exceptions.
		This includes `try`/`catch` statements and `throw` statements.
	**/
	var ExceptionsDisabled = "cxx_exceptions_disabled";

	/**
		-D dont-cast-numeric-comparisons

		If defined, number comparisons will not be casted to 
		the same type.
	**/
	var DontCastNumComp = "dont-cast-numeric-comparisons";

	/**
		-D keep-unused-locals

		If defined, unused local variables are generated.
	**/
	var KeepUnusedLocals = "keep-unused-locals";

	/**
		-D keep-useless-exprs

		If defined, expressions that don't do anything
		are still generated.
	**/
	var KeepUselessExprs = "keep-useless-exprs";

	/**
		-D cxx-no-null-warnings

		If defined, Reflaxe/C++ will not print warnings
		about non-nullable types being assigned `null`.
	**/
	var NoNullAssignWarnings = "cxx-no-null-warnings";

	/**
		-D cmake

		If defined, a `CMakeLists.txt` file will be
		generated in the output folder.
	**/
	var CMake = "cmake";
}
