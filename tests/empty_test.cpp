#include "catch.hpp"
#include <stack.hpp>

SCENARIO("TEST EMPTY METHOD"){
	Stack<char> A( {'I', 'U', '8'} );
	A.pop();
	A.pop();
	A.pop();

	REQUIRE(A.empty() == false);
}