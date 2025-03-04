#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Access the top element
    int topElement = myStack.top();
    std::cout << "Top element: " << topElement << std::endl;//30

    // Pop elements from the stack
    myStack.pop();
    myStack.pop();
    
    topElement = myStack.top();
    std::cout << "Top element: " << topElement << std::endl;//10
    // Check if the stack is empty
    if (myStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    return 0;
}