#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node // Create a node
{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data; // insert the data
    new_node->next = (*head_ref);
    (*head_ref) = new_node; // Move head to new node
}

void insertAtEnd(struct Node **head_ref, int new_data) // Insert at the end
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) // Find the key to be deleted
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) // If the key is not present
        return;

    prev->next = temp->next; // Remove the node
    free(temp);
}


void printList(struct Node *node) // Print the linked list
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main(int argc, char **argv) // Menu Driven program
{
    struct Node *head = NULL;
    int input, ch, again = 1, next;
    while (again)
    {
        cout << endl
             << "Enter the option to continue: " << endl;
        cout << "1. Insert at Start" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Delete an element" << endl;
        cout << "4. Show linked list" << endl;
        cout << "5. Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element to insert" << endl;
            cin >> input;
            insertAtBeginning(&head, input);
            break;

        case 2:
            cout << "Enter the element to insert" << endl;
            cin >> input;
            
            insertAtEnd(&head, input);
            break;

        case 3:
            cout << "Enter the element to delete" << endl;
            cin >> input;
            deleteNode(&head, input);
            break;

        case 4:
            printList(head);
            break;

        case 5:
            again = 0;
            break;

        default:
            break;
        }
    }
}