// Declare the class template, because we need it to declare the operator
template<typename> class Stack;

// Declare the operator, because (as the error says) templates must be declared
// in the namespace before you can declare them friends. At this point, we can't
// define the operator, since the class template is incomplete.
template<typename T>
ostream& operator<<(ostream& out, const Stack<T>& stack) {
	stack.show();
	return out;
}

template<typename T>
class Stack {
private:
	T* elements;
	int top;
	int size;
	void allocate();
	// Include <> to indicate that this is the template
	friend ostream& operator<< <> (ostream& out, const Stack<T>& stack);

public:
	enum {
		DEFAULTSIZE = 50, EMPTY = -1
	};
	Stack();
	Stack(int size);
	~Stack();
	void push(const T& item);
	void show() const;
	T pop();
	T peek() const;
	bool isEmpty() const;
	bool isFull() const;
	int count() const;
};

template<typename T>
Stack<T>::Stack() {
	size = DEFAULTSIZE;
	allocate();
}

template<typename T>
Stack<T>::Stack(int size) {
	// Exception
	if(size <= 0)
		size = DEFAULTSIZE;

	this->size = size;
	allocate();
}

template<typename T>
Stack<T>::~Stack() {
	delete[] elements;
}

template<typename T>
void Stack<T>::allocate() {
	elements = new T[size];
	top = EMPTY;
}

template<typename T>
void Stack<T>::push(const T& item) {
	if(!isFull())
		elements[++top] = item;
	else
		cout << "Stack is Full" << endl;
}

template<typename T>
void Stack<T>::show() const {
	cout << "elemets: {";
	int i = top;
	while(i > EMPTY) {
		cout << " " << elements[i--];
	}
	cout << " } count: " << count() << endl;
}

template<typename T>
T Stack<T>::pop() {
	if(!isEmpty())
		return elements[top--];
	else
		cout << "Stack is empty" << endl;
}

template<typename T>
T Stack<T>::peek() const {
	if(!isEmpty())
		return elements[top];
	else
		cout << "Stack is empty" << endl;
}

template<typename T>
bool Stack<T>::isEmpty() const {
	return (top == EMPTY);
}

template<typename T>
bool Stack<T>::isFull() const {
	return (count() >= size);
}

template<typename T>
int Stack<T>::count() const {
	return top + 1;
}
