#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int st, mid, end, i, num, tgt;

    cout << "Enter the size of the array: " << endl;
    cin >> num;
    int arr[num];
    // enter only sorted array
    cout << "Enter the values of the array(only in sorted order): " << endl;

    for (i = 0; i < num; i++)
        cin >> arr[i];

    // initialize the starting and ending variable's values
    st = 0;
    end = num - 1; // size of array (num) - 1

    // define the item or value to be search
    cout << "Enter the value to be searched from sorted array: " << endl;
    cin >> tgt;

    // use while loop to check 'st', should be less than equal to 'end'.
    while (st <= end)
    {
        // get middle value by splitting the array in half
        mid = (st + end) / 2;
        if (arr[mid] == tgt)
        {
            cout << "Element is found at index " << (mid + 1);
            break;
        }
        // check whether the value of target element is greater than the mid element' value
        else if (tgt > arr[mid])
        {
            st = mid + 1;
        }

        // check the value of target element is less than the mid element' value
        else if (tgt < arr[mid])
        {
            end = mid - 1;
        }
        else
            cout << "Number is not found. " << endl;
    }

    return 0;
}