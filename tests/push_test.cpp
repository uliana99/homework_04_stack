#include "catch.hpp"
#include <stack.hpp>

SCENARIO("TEST PUSH METHOD"){
	Stack<char> A;
	A.push('M');
	A.push('O');
	A.push('S');
	A.push('C');
	A.push('O');
	A.push('W');

	REQUIRE(A.count() == 6);
}