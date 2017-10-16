#include "catch.hpp"
#include <stack.hpp>

SCENARIO("TEST POP METHOD"){
	Stack<int> A( {1, 2, 3, 4, 5, 0} );
	A.pop();
	A.pop();
	A.pop();

	REQUIRE(A.count() == 3);
}