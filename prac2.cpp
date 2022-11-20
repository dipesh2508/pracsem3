#include<iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n, x;

    cout<<"Enter the size for the array: "<<endl;
    cin>>n;

    int a[n];

    cout<<"Enter the elements of the array:"<<endl;
    
    //input of elements
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cout<<"Enter the element to search"<<endl;
    cin>>x;

    //for loop for iterating the array elements
    for(int i=0; i<n; i++){
        if(a[i] == x){
            cout<<"Element found at index "<<i<<endl;
            break;
        }
    }

    
    return 0;
}