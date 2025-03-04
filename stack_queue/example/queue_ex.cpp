#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // Enqueue elements into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Access the front element
    int frontElement = myQueue.front();
    int backElement = myQueue.back();
    std::cout << "Front element: " << frontElement << std::endl;//10
    std::cout << "back element: " << backElement << std::endl<<std::endl;//30

    // Dequeue elements from the queue
    myQueue.pop();
    myQueue.pop();
    frontElement = myQueue.front();
    std::cout << "Front element: " << frontElement << std::endl;//30

    // Check if the queue is empty
    if (myQueue.empty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    return 0;
}