#include <iostream>
using namespace std;

template <class T>
class node {
public:
    T info;
    node* next;
};

template <class T>
class LList {
private:
    node<T>* head;

public:
    LList() {
        head = NULL;
    }

    ~LList();

    int isEmpty();
    void traverseInOrder();
    void traverseReverseOrder();
    static void traverseReverseRecursive(node<T>* ptr);

    void insertAtBeginning(T item);
    void insertAfterElement(T item, T after);
    void insertAtEnd(T item);

    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteElement(T item);
    void deleteAfterElement(T after);

    void reverseList();
};

template <class T>
int LList<T>::isEmpty() {
    if (head == NULL)
        return 1;
    else
        return 0;
}

template <class T>
void LList<T>::traverseInOrder() {
    node<T>* ptr;
    ptr = head;

    while (ptr != NULL) {
        cout << " " << ptr->info;
        ptr = ptr->next;
    }
}

template <class T>
void LList<T>::traverseReverseOrder() {
    traverseReverseRecursive(head);
}

template <class T>
void LList<T>::traverseReverseRecursive(node<T>* ptr) {
    if (ptr->next != NULL)
        traverseReverseRecursive(ptr->next);
    cout << " " << ptr->info;
}

template <class T>
void LList<T>::insertAtBeginning(T item) {
    node<T>* ptr;
    ptr = new node<T>;
    ptr->info = item;

    if (head == NULL)
        ptr->next = NULL;
    else
        ptr->next = head;

    head = ptr;
}

template <class T>
void LList<T>::insertAfterElement(T item, T after) {
    node<T>* ptr1, * ptr2;
    ptr1 = head;

    while (ptr1 != NULL) {
        if (ptr1->info == after)
            break;

        ptr1 = ptr1->next;
    }

    if (ptr1 == NULL) {
        cout << "\nElement " << after << " not found\n";
        return;
    }

    ptr2 = new node<T>;
    ptr2->info = item;

    ptr2->next = ptr1->next;
    ptr1->next = ptr2;
}

template <class T>
void LList<T>::insertAtEnd(T item) {
    node<T>* ptr, * loc;
    ptr = new node<T>;
    ptr->info = item;
    ptr->next = NULL;

    if (head == NULL)
        head = ptr;
    else {
        loc = head;
        while (loc->next != NULL)
            loc = loc->next;

        loc->next = ptr;
    }
}

template <class T>
void LList<T>::deleteFromBeginning() {
    node<T>* ptr;
    if (head == NULL)
        return;
    else {
        ptr = head;
        head = head->next;
        delete ptr;
    }
}

template <class T>
void LList<T>::deleteFromEnd() {
    node<T>* ptr, * loc;
    if (head == NULL)
        return;
    else if (head->next == NULL) {
        ptr = head;
        head = NULL;
        delete ptr;
    }
    else {
        loc = head;
        ptr = head->next;
        while (ptr->next != NULL) {
            loc = ptr;
            ptr = ptr->next;
        }
        loc->next = NULL;
        delete ptr;
    }
}

template <class T>
void LList<T>::deleteElement(T item) {
    node<T>* loc, * ploc;
    ploc = NULL;
    loc = head;

    while (loc != NULL) {
        if (loc->info == item) {
            if (ploc == NULL) {
                head = loc->next;
                delete loc;
            }
            else {
                ploc->next = loc->next;
                delete loc;
            }
            return;
        }
        ploc = loc;
        loc = loc->next;
    }
}

template <class T>
void LList<T>::deleteAfterElement(T after) {
    node<T>* ptr1, * ptr2;
    ptr1 = head;

    while (ptr1 != NULL) {
        if (ptr1->info == after)
            break;

        ptr1 = ptr1->next;
    }

    if (ptr1 == NULL) {
        cout << "\nElement " << after << " not found\n";
        return;
    }

    ptr2 = ptr1->next;
    if (ptr2 != NULL) {
        ptr1->next = ptr2->next;
        delete ptr2;
    }
}

template <class T>
void LList<T>::reverseList() {
    node<T>* previousNode, * currentNode, * nextNode;
    currentNode = head;
    nextNode = currentNode->next;
    previousNode = NULL;

    currentNode->next = NULL;
    while (nextNode != NULL) {
        previousNode = currentNode;
        currentNode = nextNode;
        nextNode = currentNode->next;
        currentNode->next = previousNode;
    }
    head = currentNode;
}

template <class T>
LList<T>::~LList() {
    node<T>* ptr;

    while (head != NULL) {
        ptr = head;
        head = head->next;
        delete ptr;
    }
}

int main() {
    LList<int> list;
    int choice, element, after;

    while (1) {
        cout << "Options available\n";
        cout << "++++++++\n\n";
        cout << " 1. Insert at beginning\n";
        cout << " 2. Insert at end\n";
        cout << " 3. Insert after a given element\n";
        cout << " 4. Traverse in order\n";
        cout << " 5. Traverse in reverse order\n";
        cout << " 6. Delete from beginning\n";
        cout << " 7. Delete from end\n";
        cout << " 8. Delete given element\n";
        cout << " 9. Delete after a given element\n";
        cout << " 10. Reverse linked list\n";
        cout << "Enter your choice (1-10): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter element: ";
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
            if (list.isEmpty())
                cout << "\nList is empty...";
            else {
                list.traverseInOrder();
                cout << "\n";
            }
            break;

        case 5:
            if (list.isEmpty())
                cout << "\nList is empty...";
            else {
                list.traverseReverseOrder();
                cout << "\n";
            }
            break;

        case 6:
            list.deleteFromBeginning();
            break;

        case 7:
            list.deleteFromEnd();
            break;

        case 8:
            cout << "\nEnter element to be deleted: ";
            cin >> element;
            list.deleteElement(element);
            break;

        case 9:
            cout << "\nEnter element after which to delete: ";
            cin >> after;
            list.deleteAfterElement(after);
            break;

        case 10:
            list.reverseList();
            break;

        default:
            return 0;
        }
    }

    return 0;
}

