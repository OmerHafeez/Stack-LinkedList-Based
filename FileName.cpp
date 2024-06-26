#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int a)
    {
        data = a;
        next = nullptr;
    }
};

class Stack {
public:
    Node* top;
    Stack() {
        top = nullptr;
    }
    void push(int dat)
    {
        Node* newNode = new Node(dat);
        if (top == nullptr)
            top = newNode;
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop()
    {
        Node* temp = top;
        cout << "Popped:" << top->data << endl;
        top = top->next;
        delete temp;
    }

    int isEmpty()
    {
        if (top == 0)
            return 1;
        else
            return 0;

    }

    int peek()
    {
        return top->data;
    }

    int size()
    {
        int count = 0;
        Node* current = top;
        while (current->next != nullptr)
        {
            current = current->next;
            count++;
        }
        return count + 1;
    }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top element: " << myStack.peek() << endl;

    myStack.pop();
    cout << "Top element after pop: " << myStack.peek() << endl;

    myStack.pop();
    myStack.pop(); // Pop the remaining elements

    if (myStack.isEmpty()) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}