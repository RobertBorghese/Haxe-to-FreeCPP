#include "Main.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <math.h>

int Main::returnCode = 0;;

void Main::assert(bool b, std::optional<std::shared_ptr<haxe::PosInfos>> infos) {
	if(!b) {
		{
			auto temp = infos.value_or(std::make_shared<haxe::PosInfos>("", "test/unit_testing/tests/Math/Main.hx",10, ""));
			std::cout << temp->fileName << ":" << temp->lineNumber << ": " << "Assert failed" << std::endl;
		};
		Main::returnCode = 1;
	};
}

void Main::assertFloat(double a, double b, std::optional<std::shared_ptr<haxe::PosInfos>> infos) {
	if(abs(a - b) >= 0.001) {
		{
			auto temp = infos.value_or(std::make_shared<haxe::PosInfos>("", "test/unit_testing/tests/Math/Main.hx",17, ""));
			std::cout << temp->fileName << ":" << temp->lineNumber << ": " << "Assert failed" << std::endl;
		};
		Main::returnCode = 1;
	};
}

int main() {
	Main::assert(ceil(2 * pow(3.14159265358979323846, 2)) == 20, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 25, "main"));
	Main::assert(abs(-3) == 3, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 27, "main"));
	Main::assert(ceil(2.1) == 3, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 29, "main"));
	Main::assert(ceil(0.9) == 1, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 30, "main"));
	Main::assert(ceil(exp(1.0)) == 3, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 32, "main"));
	Main::assert(floor(exp(1.0)) == 2, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 33, "main"));
	Main::assert(floor(99.9) == 99, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 35, "main"));
	Main::assert(std::isfinite((double)12), std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 37, "main"));
	Main::assert(isnan(nan("")), std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 38, "main"));
	Main::assert(!std::isfinite(std::numeric_limits<double>::infinity()), std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 39, "main"));
	Main::assert(!std::isfinite(-std::numeric_limits<double>::infinity()), std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 40, "main"));
	Main::assertFloat(sin(3.14159265358979323846), 0.0, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 42, "main"));
	Main::assertFloat(cos(0), 1, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 43, "main"));
	Main::assertFloat(tan(4), 1.157821, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 44, "main"));
	Main::assertFloat(asin(1), 1.570796, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 45, "main"));
	Main::assert(isnan(acos(100)), std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 46, "main"));
	Main::assertFloat(atan(12), 1.4876, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 47, "main"));
	Main::assertFloat(atan2(-3, 3), -0.78539, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 48, "main"));
	Main::assertFloat(log(10), 2.30258, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 50, "main"));
	Main::assert(sqrt(25) == 5, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 52, "main"));
	Main::assert(sqrt(100) == 10, std::make_shared<haxe::PosInfos>("Main", "test/unit_testing/tests/Math/Main.hx", 53, "main"));
	
	return Main::returnCode;
}
