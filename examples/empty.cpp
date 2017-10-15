#include "stack.hpp"

void StackEMPTY(size_t _size) {
	Stack<int> A;

	for(int i=0; i<_size; i++) {
		A.push(i);
	}

	Stack<int> B = Stack<int>(A);
	Stack<int> C( { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 } );

	cout << "CREATED STACK A & STACK B" << endl;
	cout << "PUSHED " << _size << " VALUES" << endl;
	cout << "COPIED STACK A" << endl;

	while(A.empty()) {
		A.pop();
		cout << A.top() << " ";
	}
	cout << endl << "CLEAN STACK A COMPLETE" << endl;

	while(B.empty()) {
		B.pop();
		cout << B.top() << " ";
	}
	cout << endl << "CLEAN STACK C COMPLETE" << endl;

	while(C.empty()) {
		C.pop();
		cout << C.top() << " ";
	}
	cout << endl << "CLEAN STACK C COMPLETE" << endl;
}

int main() {
	try {
		StackEMPTY(10);
	} catch(std::exception &e) {
		cout << e.what() << endl;
	}
}