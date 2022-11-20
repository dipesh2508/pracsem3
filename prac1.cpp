#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    //Dipesh Ranjan 21BCS4792
    int exit = 1;
    char choice;

    while (exit)
    {
        int n;
        // Menu Options

        cout << "1. Insert a new element at end as well as at a given position "<<endl;
        cout << "2. Delete an element from a given whose value is given or whose position is given. "<<endl;
        cout << "3. To find the location of a given element. "<<endl;
        cout << "4. To display the elements of the linear array. "<<endl;
        cout <<endl<< "Select an option between 1 to 4: ";
        cin >> n;

        //Option 1
        if (n == 1)
        {
            int ch;
            cout << " Type 0 for inserting element at the end "<<endl;
            cout << " Type 1 for inserting element at specific position "<<endl;
            cin >> ch;

            // Inserting element at the end of the array
            if (ch == 0)
            {
                int size;
                int num, i;
                cout << "Enter number of elements - " << endl;
                cin >> size;
                int a[size];
                cout << "Enter the elements in the array - " << endl;
                for (int k = 0; k < size; k++)
                    cin >> a[k];

                cout << "Enter the element to insert - ";
                cin >> num;
                int l = size;
                a[l] = num;
                cout << "The new array is - " << endl;
                for (int j = 0; j < size + 1; j++)
                    cout << a[j] << " ";
            }
            // Inserting elements at specific position of the array
            else if (ch == 1)
            {
                int size, pos, num, i;
                cout << "Enter number of elements - " << endl;
                cin >> size;

                int a[size];
                cout << "Enter the elements in the array - " << endl;

                for (int k = 0; k < size; k++)
                    cin >> a[k];

                cout << "Enter the element to insert - ";
                cin >> num;

                cout << "Enter the position at which you want to insert the new element- ";
                cin >> pos;
                if (pos > size + 1)
                    cout << "Insertion is not possible";
                else
                {
                    for (i = size; i >= pos; i--)
                        a[i] = a[i - 1];

                    a[i] = num;
                }
                cout << "The new array is - " << endl;
                for (int j = 0; j < size + 1; j++)
                    cout << a[j] << " ";

            }
            else
            {
                cout << "Invalid Input";
            }
        }
        //Option 2 - Deleting an element
        else if (n == 2)
        {
            int size, pos, number, i;
            cout << "Enter number of elements - " << endl;
            cin >> size;
            int a[size];
            cout << "Enter the elements in the array - " << endl;

            for (int k = 0; k < size; k++)
                cin >> a[k];

            cout << "Enter the position - ";
            cin >> pos;
            if (pos >= size + 1)
            {
                cout << "Deletion not possible ! " << endl;
            }
            else
            {
                for (int c = pos - 1; c <= size - 1; c++)
                    a[c] = a[c + 1];
                
            }
            cout << "The new array is - " << endl;
            for (int k = 0; k < size - 1; k++)
                cout << a[k] << " ";
            
        }
        //Option 3 Searching
        else if (n == 3)
        {
            int size, pos, num, i;
            cout << "Enter number of elements - " << endl;
            cin >> size;
            int a[size], fact = 0;
            cout << "Enter the elements in the array - " << endl;

            for (int k = 0; k < size; k++)
                cin >> a[k];
            
            cout << "Enter the number you want to search - ";
            cin >> num;
            for (int i = 0; i < size; i++)
            {
                if (num == a[i])
                {
                    fact = 1;
                    pos = i + 1;
                }
            }
            if (fact == 1)
            {
                cout << "The number is found ! " << endl;
                cout << "It is at the position : " << pos << endl;
            }
            else
            {
                cout << "The number is not in the array bro!" << endl;
            }
        }
        // Option 4 Displaying elements
        else if (n == 4)
        {
            int size;
            cout << "Enter number of elements - " << endl;
            cin >> size;
            int a[size], fact = 0;
            cout << "Enter the elements in the array - " << endl;
            for (int i = 0; i < size; i++)
                cin >> a[i];
            
            cout << "The new array is - " << endl;
            for (int i = 0; i < size; i++)
                cout << a[i] << " ";
            
        }
        else
        {
            cout << "Invalid Option";
        }
        // Wish to continue or not
        cout << "\n Do you want to continue? (Y or N)"<<endl;
        cin >> choice;
        if (choice == 'N' || choice == 'n')
        {
            exit = 0;
        }
    }
    return 0;
}