#include <iostream>
#include "intstack.hxx"
using namespace std;



int main(void) {
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	cout << stack;
	cout << "Count: " << stack.count() << endl;
	cout << "Top elem: " << stack.peek() << endl;
	cout << "Count: " << stack.count() << endl;
	cout << "Pop: " << stack.pop() << endl;
	cout << "Count: " << stack.count() << endl;
	cout << stack;
}
