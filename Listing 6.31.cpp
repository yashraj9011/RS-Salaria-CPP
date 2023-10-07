//executed
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

template<class T>

class node{


 	public:

	T info;
	node *prev;
	node *next;
};
template <class T>
 class DList {
 	
  private:

	node<T> *head;
	node<T> *tail;

	public:

	DList() {
	head =tail= NULL;
}

	~DList();



	bool isEmpty();

	void traverseForward(); 
	void traverseBackward();

	void insertAtBeginning (int item);
	void insertAtEnd (int item);

	void insertAfterElement (int item, int after);

	void insertBeforeElement (int item, int before);

	void deleteFromBeginning();

	void deleteFromEnd();
	void deleteBeforeElement (int before);

	void deleteAfterElement (int after);
 
};
template <class T> 

DList<T>::~DList()
{

	node<T> *ptr;

	while (head!=NULL) {

	ptr= head;

	head=head->next;
	 delete ptr;
}
	tail = NULL;

}

template <class T>

 bool DList<T>::isEmpty()
{

return ((head == NULL) ? 1 : 0);
}

template <class T>

void DList<T>::traverseForward()
{

node<T> *ptr= head;

while (ptr != NULL) {
 cout <<"  "<< ptr->info;

ptr=ptr->next;
}
}
template <class T>


void DList<T>::traverseBackward()
{

 node<T> *ptr=tail;
while (ptr != NULL)
 { 
 	cout<<" "<< ptr->info;

	ptr =ptr->prev;
}
}
template <class T> 

void DList<T>::insertAtBeginning (int item)
{

	node<T> *ptr;

	ptr= new node<T>;
	 ptr->info=item;

if(head== NULL) { // list initially empty 

	ptr->next = ptr->prev = NULL;
	head=tail=ptr;
	head=ptr;
} else {

	ptr->prev = NULL;
	 ptr->next= head;
	  head->prev =ptr;

	head = ptr;
}
}
template <class T> 

	void DList<T>::insertAtEnd (int item)
{

	node<T> *ptr;
	ptr= new node<T>;

	ptr->info= item;

	if (head==NULL) { // list initially empty 
	ptr->next = ptr->prev = NULL;
	 head=tail=ptr;

} else {

	ptr->next=NULL; 
	ptr->prev=tail;

	tail->next=ptr;
 	tail = ptr;
}
}
template <class T> 
void DList<T>::insertAfterElement (int item, int after)
{

	node<T> *ptr1, *ptr2;

	ptr1=head;

	while (ptr1 != NULL) // list initially empty 
	if (ptr1->info == item)

	break;
	 ptr1= ptr1->next;

	if (ptr1== NULL)
	 { 
	 cout << "\nElement" << after << "not present\n\n";

	return;

	ptr2 = new node<T>;
	 ptr2->info=item;

	if (ptr1->next == NULL)
	 {
	 
	  ptr2->next = NULL;

	ptr1->next=ptr2;



	ptr2->prev= tail;
	 tail=ptr2;

} else {

	ptr2->prev=ptr1;
	 ptr2->next = ptr1->next;
	  (ptr1->next)->prev = ptr2;

	ptr1->next=ptr2;
}
}
}
template <class T>

void DList<T>::insertBeforeElement (int item, int before)
{

	node<T> *ptr1, *ptr2;

	ptr1=head;

	while (ptr1!=NULL) 
	{
	 if (ptr1->info ==item)

	break;	

	ptr1=ptr1->next;
}
	if (ptr1==NULL) {

	cout<<"\nElement" << before << "not present\n\n";

	return;
}
	ptr2=new node<T>;

	ptr2->info=item; 
	if (ptr1->prev == NULL) {

	ptr2->prev=NULL; 
	ptr1->prev=ptr2;

	ptr2->next=head;

	head=ptr2;
}
 else {

	ptr2->prev=ptr1->prev;
	 ptr2->next=ptr1;

	(ptr1->prev)->next = ptr2;
 	ptr1->prev=ptr2;
	}
}
template <class T> 
void DList<T>::deleteFromBeginning ()
{

node<T> *ptr;
 if (head== NULL)

	return;
	 ptr=head;

	if ( head==tail )

	head =tail= NULL;
else{
	(ptr->next)->prev= NULL;
	head=ptr->next;
} delete ptr;
}


template <class T> 
void DList<T>:: deleteFromEnd()
{

	node<T> *ptr;

if(head==NULL) // list initially empty return;
	return;
	
	
	
	ptr=tail;

	if (head==tail) // one element only

	head=tail=NULL;
else{

	(ptr->prev)->next = NULL;
	 tail=ptr->prev;
}

	delete ptr;
}

template <class T> 
void DList<T>::deleteAfterElement (int after)
{

node<T> *ptr1, *ptr2;

	ptr1= head;
	 while (ptr1!= NULL) {

	if (ptr1->info==after) 
	break;

	ptr1=ptr1->next;
}
	 if (ptr1== NULL) {

	cout << "\nElement "<< after <<" not present\n\n";

	return;
}
	 else if ((ptr1->next)->next== NULL) {

		ptr2=ptr1->next;

	ptr1->next=NULL;

	tail = ptr1;

	delete ptr2;
	
 } else
{

	ptr2=ptr1->next;

	ptr1->next=ptr2->next;

	(ptr2->next)->prev = ptr1;

	delete ptr2;
	 }
}
template <class T> 
void DList<T>::deleteBeforeElement (int before)
{

	node<T> *ptr1, *ptr2;

	ptr1 = head;
	 while (ptr1 != NULL) 
	 {
	  if (ptr1->info== before)

		break;

	ptr1=ptr1->next;
}
if	(ptr1== NULL) {

	cout<<"\nElement" << before << "not present\n\n";

	return;
}
	else if ((ptr1->prev)->prev == NULL)
	 {

	ptr2=ptr1->prev; 
	ptr1->prev=NULL;

	head=ptr1;

delete ptr2;
 } else {

	ptr2=ptr1->prev;



	ptr1->prev=ptr2->prev;
	 (ptr2->prev)->next = ptr1;
	  delete ptr2;

}
}


// (Your class and function definitions go here...)

int main()
{
    DList<int> list;
    int choice, element, after, before;

    while (1)
    {
        cout << "\n\n Options available \n";
        cout << " ++++++++++++++++++++++++++  \n \n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a given element \n";
        cout << "4. Insert before a given element \n";
        cout << "5. Traverse in Forward direction\n";
        cout << "6. Traverse in backward direction\n";
        cout << "7. Delete from beginning\n";
        cout << "8. Delete from end\n";
        cout << "9. Delete after a given element\n";
        cout << "10. Delete before a given element\n";
        cout << "11. Exit\n\n";
        cout << "Enter your choice (1-11): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter element :";
            cin >> element;
            list.insertAtBeginning(element);
            break;
        case 2:
            cout << "\nEnter element: ";
            cin >> element;
            list.insertAtEnd(element);
            break;
        case 3:
            cout << "\nEnter element: ";
            cin >> element;
            cout << "\nEnter element after which to insert: ";
            cin >> after;
            list.insertAfterElement(element, after);
            break;
        case 4:
            cout << "\nEnter element: ";
            cin >> element;
            cout << "\nEnter element before which to insert: ";
            cin >> before;
            list.insertBeforeElement(element, before);
            break;
        case 5:
            if (list.isEmpty())
                cout << "\nList is empty...";
            else
                list.traverseForward();
            cout << "\n\nPress any key to continue...";
            getch();
            break;
        case 6:
            if (list.isEmpty())
                cout << "\nList is empty..";
            else
                list.traverseBackward();
            cout << "\n\nPress any key to continue";
            getch();
            break;
        case 7:
            list.deleteFromBeginning();
            break;
        case 8:
            list.deleteFromEnd();
            break;
        case 9:
            cout << "\nEnter element after which to delete: ";
            cin >> after;
            list.deleteAfterElement(after);
            break;
        case 10:
            cout << "\nEnter element before which to delete: ";
            cin >> before;
            list.deleteBeforeElement(before);
            break;
        case 11:
            return 0;
        }
    }
}

