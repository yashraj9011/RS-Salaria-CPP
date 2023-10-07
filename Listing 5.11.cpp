#include <iostream>
using namespace std;

template <class T>
class LinearArray {
private:
    T* a;
    int n;
    int capacity;

public:
    LinearArray(int size) {
        n = 0;
        capacity = size;
        a = new T[capacity];
    }

    ~LinearArray() {
        delete[] a;
    }

    int getElements() {
        return n;
    }

    int getCapacity() {
        return capacity;
    }

    void displayArray();
    void inputArray();

    void insertAt(int k, T item);
    void insertInSortedArray(T item);
    void deleteFrom(int k);
    void deletefromSortedArray(T item);

    int linearSearch(T item);
    int binarySearchRecursive(int lb, int ub, T item);

    void bubbleSortModified();
};

template <class T>
void LinearArray<T>::displayArray() {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

template <class T>
void LinearArray<T>::inputArray() {
    char choice;
    while (true) {
        cout << "Enter element a[" << (n + 1) << "]: ";
        cin >> a[n++];

        cout << "More element Y/N? : ";
        cin >> choice;

        if (choice == 'N' || choice == 'n')
            break;
    }
}

template <class T>
void LinearArray<T>::insertAt(int k, T item) {
    int j;

    if (n == capacity) {
        cout << "\nArray is full...\n";
        return;
    }

    j = n - 1;
    while (j >= k) {
        a[j + 1] = a[j];
        j--;
    }
    a[k] = item;
    n++;
}

template <class T>
void LinearArray<T>::insertInSortedArray(T item) {
    int k;

    if (n == capacity) {
        cout << "\nArray is full...\n";
        return;
    }

    k = n - 1;
    while ((item < a[k]) && (k >= 0)) {
        a[k + 1] = a[k];
        k--;
    }
    a[k + 1] = item;
    n++;
}

template <class T>
void LinearArray<T>::deleteFrom(int k) {
    int j;

    if (n == 0) {
        cout << "\nArray is empty...\n";
        return;
    }

    j = k + 1;
    while (j < n) {
        a[j - 1] = a[j];
        j++;
    }
    n--;
}

template <class T>
void LinearArray<T>::deletefromSortedArray(T item) {
    int j, k;

    if (n == 0) {
        cout << "\nArray is empty...\n";
        return;
    }

    k = binarySearchRecursive(0, n - 1, item);
    if (k == -1) {
        cout << "\nElement " << item << " is not in the array\n";
        return;
    }

    j = k + 1;
    while (j < n) {
        a[j - 1] = a[j];
        j++;
    }
    n--;
}

template <class T>
int LinearArray<T>::linearSearch(T item) {
    int i;
    for (i = 0; i < n; ++i) {
        if (a[i] == item)
            return i;
    }
    return -1;
}

template <class T>
int LinearArray<T>::binarySearchRecursive(int lb, int ub, T item) {
    int mid;
    if (lb > ub)
        return -1;
    else {
        mid = (lb + ub) / 2;
        if (item == a[mid])
            return mid;
        else if (item < a[mid])
            return binarySearchRecursive(lb, mid - 1, item);
        else
            return binarySearchRecursive(mid + 1, ub, item);
    }
}

template <class T>
void LinearArray<T>::bubbleSortModified() {
    int j, i, temp, exchange_flag = 1;
    i = 0;
    while ((i < n - 1) && (exchange_flag)) {
        exchange_flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                exchange_flag = 1;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        i++;
    }
}

int main() {
    LinearArray<int> la(10);

    cout << "\nEnter elements for array LA:\n";
    la.inputArray();

    cout << "\nElements of array LA: ";
    la.displayArray();

    int element, pos;

    cout << "\nEnter new element to insert: ";
    cin >> element;

    cout << "\nEnter position where to insert: ";
    cin >> pos;

    la.insertAt(pos - 1, element);
    cout << "\nElements of array LA after insertion: ";
    la.displayArray();

    cout << "\nEnter position from where to delete element: ";
    cin >> pos;
    la.deleteFrom(pos - 1);
    cout << "\nElements of LA after deletion: ";
    la.displayArray();

    cout << "\nEnter the element to search: ";
    cin >> element;
    pos = la.linearSearch(element);
    if (pos < 0)
        cout << "\nElement not found!\n";
    else
        cout << "\nElement found at index " << pos << "\n";

    la.bubbleSortModified();
    cout << "\nElements of array LA after sorting: ";
    la.displayArray();

    cout << "\nEnter the element to search: ";
    cin >> element;
    pos = la.binarySearchRecursive(0, la.getElements() - 1, element);
    if (pos < 0)
        cout << "\nElement not found!\n";
    else
        cout << "\nElement found at index " << pos << "\n";

    cout << "\nEnter new element to insert: ";
    cin >> element;
    la.insertInSortedArray(element);

    cout << "\nElements of array LA after insertion: ";
    la.displayArray();

    cout << "\nEnter element to delete: ";
    cin >> element;
    la.deletefromSortedArray(element);

    cout << "\nElements of LA after deletion: ";
    la.displayArray();

    return 0;
}

