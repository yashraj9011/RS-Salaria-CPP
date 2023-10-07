#include<bits/stdc++.h>
using namespace std;

template <class T> 
class node
{
	public:
	 T info;

	node * next;
};
template <class T>

 class LinkStack
{

protected:  // data member


			node<T> *top;

	public:
			LinkStack();

// destructor

			~LinkStack();


// Check whether the stack is empty
 int isEmpty();

// Insert (push) an element at the top of stack
 void push (T value);

// Access and remove the top element of the stack

T pop();

// Access the top element of the stack

// without removing it from the stack

T peek();

};


template <class T> 
LinkStack<T>::LinkStack()
{

top= NULL;
}

template <class T>

int LinkStack<T>::isEmpty()
{

return (top== NULL ? 1 : 0);
}
//Insert (push) an element at the top of stack

template <class T>

void LinkStack<T>::push(T value)
{

node<T> *ptr;

ptr= new node<T>;

ptr->info= value;
 ptr->next=top;

top = ptr;
}

template<class T>

T LinkStack<T>::pop()
{
	node<T> *head;
	T temp;
	node<T> *ptr;

	temp = head->info;
	ptr = top;
	top = head->next;
	delete ptr;
	return temp;

//Access the top element of the stack without removing it from the sta
}
template <class T>

T LinkStack<T>::peek()
{

return(top->info );
}
// remove stack from memory

template <class T> 
LinkStack<T>::~LinkStack()
{

node<T> *ptr;
node<T> *head;
 while (head!=0) {

	ptr=head;
	head =head->next;
	delete ptr;
}
}
int main()
{

int choice, element,m;
/*
cout<<"\n size enter";
cin>>m;
*/
LinkStack<int> intStack;

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

case 1:	cout<<"Enter value: ";
	 cin >> element; 
	 intStack.push(element);
	 break;

	

case 2: if (intStack.isEmpty()) 
	
		cout << "Stack empty, press any key to continue";

else

 cout << "Value poped is " << intStack.pop();

	break;
	
	 case 3:  if (intStack.isEmpty()) 

		cout << "Stack empty, press any key to continue";
	
	else
	
	cout<<"Vlaue at top is"<<intStack.peek();
		}
	}
		while ( choice != 4 );
	
}





