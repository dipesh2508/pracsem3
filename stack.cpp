#include <iostream>
using namespace std;

#define MAX 1000 // max size for stack

class Stack
{
    int top;

public:
    int myStack[MAX]; // stack array

    Stack()
    {
        top = -1;
    }
    bool push(int x);
    int pop();
    bool isEmpty();
    void print();
};
// pushes element on to the stack
bool Stack::push(int item)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow!";
        return false;
    }
    else
    {
        myStack[++top] = item;
        return true;
    }
}

// removes or pops elements out of the stack
int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow!";
        return 0;
    }
    else
    {
        int item = myStack[top--];
        return item;
    }
}

// check if stack is empty
bool Stack::isEmpty()
{
    return (top < 0);
}

// printing the stack
void Stack::print()
{
    if (top < 0)
    {
        cout << "Stack Underflow!";
    }
    else
    {
        cout<<"[ ";
        for (int i = 0; i <= top; i++)
        {
            cout << myStack[i] << " ";
        }
        cout<<" ]";
    }
}

// menu driven main functions
int main()
{
    class Stack stack;
    cout << "The Stack Push " << endl;
    int element, again = 1, ch;
    while (again)
    {
        cout << endl;
        cout << "1. Push in stack" << endl;
        cout << "2. Pop in stack" << endl;
        cout << "3. Pop all elements in stack" << endl;
        cout << "4. Print stack" << endl;
        cout << "5. Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter the number to push" << endl;
            cin >> element;
            stack.push(element);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            while (!stack.isEmpty())
            {
                stack.pop();
            }
            break;

        case 4:
            stack.print();
            break;

        case 5:
            again = 0;
            break;

        default:
            break;
        }
    }
    return 0;
}