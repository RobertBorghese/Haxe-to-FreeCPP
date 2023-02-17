package gcfcompiler.helpers;

#if (macro || gcf_runtime)

import haxe.macro.Context;
import haxe.macro.Expr;

enum ErrorType {
	// General
	CannotCompileNullType;
	DynamicUnsupported;
	OMMIncorrectParamCount;
	ValueSelfRef;

	// Meta
	ConstExprMetaInvalidUse;

	// Memory Management Conversion
	UnsafeToShared;
	UnsafeToUnique;
	SharedToUnique;
	UniqueToShared;
	UniqueToUnique;
}

class GCFError {
	public static function makeError(pos: Position, err: ErrorType): Dynamic {
		final msg = switch(err) {
			// General
			case CannotCompileNullType: {
				"GCFCompiler.compileTypeSafe was passed 'null'. Unknown type detected?";
			}
			case DynamicUnsupported: {
				"Dynamic not supported";
			}
			case OMMIncorrectParamCount: {
				"@:overrideMemoryManagement wrapper does not have exactly one type parameter.";
			}
			case ValueSelfRef: {
				"Types using @:valueType cannot reference themselves. Consider wrapping with SharedPtr<T>.";
			}

			// Meta
			case ConstExprMetaInvalidUse: {
				"Invalid use of @:constexpr. Must be used with if statement.";
			}

			// Memory Management Conversion
			case UnsafeToShared: {
				"Cannot convert unsafe pointer (Ptr<T>) to shared pointer (SharedPtr<T>).";
			}
			case UnsafeToUnique: {
				"Cannot convert unsafe pointer (Ptr<T>) to unique pointer (UniquePtr<T>).";
			}
			case SharedToUnique: {
				"Cannot convert shared pointer (SharedPtr<T>) to unique pointer (UniquePtr<T>).";
			}
			case UniqueToShared: {
				"Cannot move or copy a unique pointer (UniquePtr<T>), so it cannot be converted to shared pointer (SharedPtr<T>).";
			}
			case UniqueToUnique: {
				"Cannot move or copy a unique pointer (UniquePtr<T>).";
			}

			case _: {
				"Unknown error.";
			}
		}
		return Context.error(msg, pos);
	}
}

#end
