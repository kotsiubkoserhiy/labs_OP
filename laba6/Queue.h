#ifndef LABA6_QUEUE_H
#define LABA6_QUEUE_H
#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* front; // Вказівник на перший елемент черги
    Node* rear; // Вказівник на останній елемент черги

public:
    Queue();
    ~Queue();

    bool isEmpty() const;
    void clear();
    void enqueue(const T& item);
    T dequeue();

    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node);

        T& operator*() const;
        Iterator& operator++();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin() const;
    Iterator end() const;
};

#endif //LABA6_QUEUE_H
