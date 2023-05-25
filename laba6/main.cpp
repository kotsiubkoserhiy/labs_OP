#include "Queue.h"

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue<int> queue;

    // Додавання елементів до черги
    for (int i = 0; i < size; i++) {
        int item;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> item;
        queue.enqueue(item);
    }

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    // Виведення вмісту черги за допомогою ітератора
    cout << "Queue contents: ";
    for (const int& item : queue) {
        cout << item << " ";
    }
    cout << endl;

    // Видалення елемента з черги
    int item = queue.dequeue();
    cout << "Dequeued item: " << item << endl;


    cout << "Queue contents: ";
    for (const int& item : queue) {
        cout << item << " ";
    }
    cout << endl;

    // Очищення черги
    queue.clear();

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}