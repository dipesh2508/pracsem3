#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
	struct node *temp;
	temp = new node;
	cout << "Enter the element you want to insert: ";
	cin >> temp->data;
	temp->next = NULL;

	if (temp == NULL)
	{ // if no memory is available in comp for allocation then the node remains null
		cout << "OVERFLOW, Queue is full\n";
		return;
	}
	else
	{
		if (front == NULL)
		{ // no element in queue
			front = rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = rear->next;
		}
	}
}

void dequeue()
{

	struct node *temp;
	temp = new node;

	if (front == NULL)
	{
		cout << "Underflow, queue is empty\n";
		return;
	}
	else
	{
		if (front == rear)
		{ // only 1 element left in queue
			temp = front;
			front = rear = NULL;
		}
		else
		{
			front = front->next;
		}
		delete temp;
	}
}

void display()
{

	struct node *temp = front;
	if (front == NULL && rear == NULL)
	{
		cout << "Queue is empty\n";
		return;
	}

	cout << "Queue elements are: \n";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{

	while (true)
	{
		cout << "1) Enqueue"<<endl<<"2) Dequeue"<<endl<<"3) Display"<<endl<<"4) Exit"<<endl;
		cout << "Please enter your choice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{

		case 1:
			enqueue();
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
			cout << "Invalid choice";
		}
	}
	return 0;
}