#include<iostream>
using namespace std;

int merge(int a[], int beg, int mid, int end)    
{    
    int i=0, j=0, k= beg;  
    int n1 = mid - beg + 1, n2 = end - mid;
    int Left[n1], Right[n2];   
 
    for (int i = 0; i < n1; i++)    
        Left[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
        Right[j] = a[mid + 1 + j];    
      
    while (i < n1 && j < n2)    
    {    
        if(Left[i] <= Right[j])    
        {    
            a[k] = Left[i];
            i++;    
        }    
        else    
        {    
            a[k] = Right[j];
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = Left[i];    
        i++;    
        k++;    
    }      
    while (j<n2)    
    {    
        a[k] = Right[j];    
        j++;    
        k++;    
    }
    return 0;    
}  

int mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    } 
    return 0; 
}  

int printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<<" ";  
    cout<<endl;  
    return 0;
}  

int main(int argc, char** argv)
{
    int a[] = { 12, 31, 25, 8, 32, 17, 40, 42, 9, 13 };  
    int n = sizeof(a) / sizeof(a[0]);

    cout<<"Before sorting array elements are -"<<endl;  
    printArray(a, n);  
    mergeSort(a, 0, n - 1);
    cout<<"After sorting array elements are -"<<endl;  
    printArray(a, n);  
    return 0;
}