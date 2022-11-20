#include<iostream>
using namespace std;

struct node     
{
    int num;
    struct node *nextptr;
}*stnode;

void createList(int n);     
void NodeInsertEnd(int num);	
void displayList(); 

int main(int argc, char** argv)
{
    int n, num;

    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    createList(n);
    cout<<"Data entered in the list are: "<<endl;
    displayList();

    cout<<endl<<"Enter data to be enter at the end of the list: "<<endl;
    cin>>num;
    NodeInsertEnd(num);

    cout<<"After insertion the list is: "<<endl;
    displayList();

    return 0;
}

void createList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL) 
        cout<< " Memory can not be allocated."<<endl;
    else{
        cout<<" Input data for node 1 : "<<endl;
        cin>>num;
 
        stnode-> num = num;      
        stnode-> nextptr = NULL; 
        tmp = stnode;

        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL) 
            {
                cout<<" Memory can not be allocated."<<endl;
                break;
            }
            else
            {
                cout<<" Input data for node "<< i<<endl;
                cin>>num;
                fnNode->num = num;
                fnNode->nextptr = NULL; 
                tmp->nextptr = fnNode; 
                tmp = tmp->nextptr;
            }
        }
    }
} 

void NodeInsertEnd(int num)
{
    struct node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        cout<<" Memory can not be allocated."<<endl;
    }
    else
    {
        fnNode->num = num;
        fnNode->nextptr = NULL; 
        tmp = stnode;
        while(tmp->nextptr != NULL)
            tmp = tmp->nextptr;
        tmp->nextptr = fnNode;  
    }
}

void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" No data found in the empty list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            cout<<" "<< tmp->num; 
            tmp = tmp->nextptr;                
        }
    }
}
