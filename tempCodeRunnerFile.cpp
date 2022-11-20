#include <iostream>
using namespace std;

int n = 5;
int Q[5], front = -1, rear = -1;

void Cenqueue(int item)
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        cout << "Overflow"<<endl<<endl;
        return;
    }
    if (front == -1)
        front = rear = 0;
    else if (rear == n - 1)
    {
        rear = 0;
    }
    else
        rear = rear + 1;
    Q[rear] = item;
}

void Cdequeue()
{
    if (front == -1)
    {
        cout << "Underflow"<<endl<<endl;
        return;
    }
    else if (front == rear)
    { // only one element left
        front = rear = -1;
    }
    else if (front == n - 1)
        front = 0;
    else
        front = front + 1;
}

void Cdisplay()
{
    if (front == -1 && rear == -1)
        cout << "Underflow. Queue is empty\n";
    else
    {
        for (int i = front; i != rear; i = ((i + 1) % 5))
        {
            cout << Q[i] << " ";
        }
        cout << Q[rear];
        cout << endl;
    }
}

void enqueue(int item)
{
    if ((rear == n - 1))
    {
        cout << "Overflow\n\n";
        return;
    }
    if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear = rear + 1;
    Q[rear] = item;
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Underflow. Queue is empty"<<endl;
        return;
    }
    if (front == rear)
        front = rear = -1;

    else
        front = front + 1;
}

void display()
{
    if (front == -1 && rear == -1)
        cout << "Underflow. Queue is empty"<<endl;
    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    int q;
    cout << "Enter 1 if you want to store your data in a simple queue\nEnter 2 if you want to store yourdata in a circular queue\n";
    cin >> q;
    switch (q)
    {
    case 1:
        while (true)
        {
            int choice;
            cout << "1) Enqueue"<<endl<<"2) Dequeue"<<endl<<"3) Display"<<endl<<"4) Exit"<<endl;
            cout << "Enter the operation to be performed: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter the value you want to insert in the queue: ";
                int val;
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid Input. Please try again.";
            }
        }
    case 2:
        while (true)
        {
            int choice;
            cout << "1) Enqueue"<<endl<<"2) Dequeue"<<endl<<"3) Display"<<endl<<"4) Exit"<<endl;
            cout << "Enter the operation to be performed: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter the value you want to insert in the queue: ";
                int val;
                cin >> val;
                Cenqueue(val);
                break;
            case 2:
                Cdequeue();
                break;
            case 3:
                Cdisplay();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid Input. Please try again.";
            }
        }
    }
    return 0;
}