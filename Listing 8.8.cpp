#include <iostream>
#include <iomanip>

template <class T>
class LinearQueue {
protected:
    int front;
    int rear;
    int size;
    T* elements;

public:
    // zero argument constructor, it constructs a queue with default size = 10
    LinearQueue() {
        elements = new T[10];
        front = rear = -1;
        size = 10;
    }

    // parametrized constructor that constructs a queue with size n
    LinearQueue(int n) {
        elements = new T[n];
        front = rear = -1;
        size = n;
    }

    // destructor that removes the queue from memory
    ~LinearQueue() {
        delete[] elements;
        front = rear = -1;
        size = 0;
    }

    // Check whether the queue is empty
    int isEmpty() {
        return (front == -1 ? 1 : 0);
    }

    // Check whether the queue is full
    int isFull() {
        return ((front == 0) && (rear == size - 1) ? 1 : 0);
    }

    // Insert an element at the end of the queue
    void enqueue(T value);

    // Access and remove the first element of the queue
    T dequeue();

    // Access the first element of the queue without removing it from the queue
    T peek();
};

// Insert an element at the end of the queue
template <class T>
void LinearQueue<T>::enqueue(T value) {
    if (isEmpty())
        front = rear = 0;
    else if (rear == size - 1) {
        for (int i = front; i <= rear; i++)
            elements[i - front] = elements[i];
        rear = rear - front;
        front = 0;
    } else {
        rear++;
    }

    elements[rear] = value;
}

// Access and remove the first element of the queue
template <class T>
T LinearQueue<T>::dequeue() {
    T temp = elements[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return temp;
}

// Access the first element of the queue without removing it from the queue
template <class T>
T LinearQueue<T>::peek() {
    return elements[front];
}

int main() {
    int choice, element, m;
    std::cout << "\nSize of queue you want to use: ";
    std::cin >> m;
    LinearQueue<int> intQueue(m);

    do {
        std::cout << "\n\nOptions available \n";
        std::cout << "++++ ++++ \n\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Exit\n\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (intQueue.isFull())
                    std::cout << "\nQueue full...\n";
                else {
                    std::cout << "Enter value: ";
                    std::cin >> element;
                    intQueue.enqueue(element);
                }
                break;

            case 2:
                if (intQueue.isEmpty())
                    std::cout << "\nQueue empty...\n";
                else
                    std::cout << "Value dequeued is " << intQueue.dequeue();
                break;

            case 3:
                if (intQueue.isEmpty())
                    std::cout << "\nQueue empty...\n";
                else
                    std::cout << "First Element of queue is " << intQueue.peek();
                break;
        }
    } while (choice != 4);

    return 0;
}

