#include "Queue.h"

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    clear();
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

template <typename T>
void Queue<T>::clear() {
    while (!isEmpty()) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

template <typename T>
// Встановлення елемента в чергу
void Queue<T>::enqueue(const T& item) {
    Node* newNode = new Node(item);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

template <typename T>
// Виключення елемента з черги
T Queue<T>::dequeue() {
    if (isEmpty()) {
        cout << "Error: Queue is empty.\n";
        exit(1);
    }

    T item;
    cout << "Enter the item to dequeue: ";
    cin >> item;

    Node* current = front;
    Node* previous = nullptr;

    while (current != nullptr && current->data != item) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Item not found in the queue. Please try again.\n";
        return dequeue(); // Повторне введення елемента
    }

    if (current == front) {
        front = front->next;
    } else {
        previous->next = current->next;
    }

    if (current == rear) {
        rear = previous;
    }

    T data = current->data;
    delete current;

    return data;
}

template <typename T>
Queue<T>::Iterator::Iterator(Node* node) : current(node) {}

template <typename T>
T& Queue<T>::Iterator::operator*() const {
    return current->data;
}

template <typename T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    if (current != nullptr) {
        current = current->next;
    }
    return *this;
}

template <typename T>
bool Queue<T>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

template <typename T>
bool Queue<T>::Iterator::operator!=(const Iterator& other) const {
    return !(*this == other);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator(front);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::end() const {
    return Iterator(nullptr);
}

// Інстанціювання класу для підтримки типу даних
template class Queue<int>;