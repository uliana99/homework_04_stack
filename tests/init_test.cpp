#include "catch.hpp"
#include <stack.hpp>

SCENARIO("TEST INIT METHOD"){
	Stack<int> A;
	REQUIRE(A.count() == 0);
}