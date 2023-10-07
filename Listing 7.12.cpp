
//operation based array on stack  

// working


#include<bits/stdc++.h>
using namespace std;


template<class T>

class ArrayStack
{
	protected:

	int top;
	int size;
 	T *elements;

// member functions

public:

//zero argument constructor,
 ArrayStack();

// it constructs a stack with default size = parametrized constructor that constructs,



// a stack with size n
ArrayStack (int n); 

// destructor that removes the stack from memory

	~ArrayStack();

// Check whether the stack is empty / Check whether the stack is full

	int isEmpty(); 

	int isFull();

	//Insert (push) an element at the top of stack
	 void push (T value);

//Access and remove the top element of the stack

	T pop();

// Access the top element of the stack //without removing it from the stack

	T peek();
};

template<class T>

 ArrayStack<T>::ArrayStack()
  {

	elements = new T[10];
 	size= 10;

	top =-1;
}
//parametrized constructor that constructs,

	
template <class T>

ArrayStack <T> :: ArrayStack (int n) {

	elements= new T[n];
	 size = n;

	top= -1;
}
//destructor that removes the stack from

template <class T>

ArrayStack<T>::~ArrayStack() {

	delete elements;

	top = -1;

	size= 0;
}
//Check whether the stack is empty
template <class T>

int ArrayStack<T>::isEmpty()
 { 
 return (top== -1 ? 1 : 0);
}
//Check whether the stack is full
 template <class T>
  int ArrayStack<T>::isFull () {

return( top == size-1 ? 1 : 0);

}
//Insert (push) an element at the top of stack

template <class T>

void ArrayStack<T>::push (T value) {

		top++;

	elements [top] = value;
}
//Access and remove the top element of the stack

template <class T>
T  ArrayStack<T>::pop() {

T temp;

temp =elements [top];

top--;

return temp;
}
//Access the top element of the stack

//without removing it from the stack 
template <class T>

T ArrayStack<T>::peek()
 { 
 return elements [top];

}

int  main()
{

	int choice, element, m;

	cout << "\nSize of stack you want to use: ";

	cin >> m;
 	ArrayStack<int> intStack (m);
  do
	{

	cout << "\n Options available \n";
	 cout << " ++++ \n\n";

	cout << " 1. Push \n";
	cout << " 2. Pop \n";

	cout << " 3. Peek \n"; 
	cout <<"  4. Exit\n\n";

	cout<<"Enter your choice (1-4): ";

	cin >> choice;
	 switch (choice)
{

	case 1: if (intStack.isFull())
	 { 
	 cout << "Stack full, press any key to continue";

	} else

{

	cout<<"Enter value: ";
	 cin >> element; 
	 intStack.push(element);
}
	break;

case 2: if (intStack.isEmpty()) {
	
		cout << "Stack empty, press any key to continue";
}
else{

 cout << "Value poped is " << intStack.pop();
}
	break;
	
	 case 3:  if (intStack.isEmpty()) {

		cout << "Stack empty, press any key to continue";
	}
	else
	
	cout<<"Vlaue at top is"<<intStack.peek();
		}
	}
		while ( choice != 4 );
	
}





