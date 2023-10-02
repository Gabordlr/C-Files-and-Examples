// By: Gabriel Rodriguez, A01027384
// Date: 2021/04/19
// Description: Program that sorts an array using the merge sort algorithm
#include <iostream>
#include <vector>

using namespace std;

// Function that sorts an array using the merge sort algorithm
// Parameters: int arr[] (array to be sorted), int size (size of the array), int index (first index of the array)
// Returns: int *newArr (sorted array)
vector<int> mergeSort(vector<int> arr, int size, int index)
{
    // val is used to determine to modify sp1 size in case of odd size
    int val = size % 2 == 0 ? 0 : 1;
    vector<int> spl1;
    vector<int> spl2;

    // the new array that will be returned
    vector<int> newArr;

    // Base case
    if (size > 2)
    {
        // Recursive case
        // Split the array in two
        spl1 = mergeSort(arr, (size / 2) + val, index);
        spl2 = mergeSort(arr, size / 2, index + (size / 2) + val);
    }
    else
    {
        // Base case
        spl1.push_back(arr[index]);
        spl2.push_back(arr[index + (size / 2)]);
    }

    // Merge the two arrays
    // a and b are used to iterate through the arrays
    int a = 0;
    int b = 0;
    for (int i = 0; i <= size - 1; i++)
    {
        // If the value of spl1 is smaller than the value of spl2, or if spl2 has been fully iterated, add the value of spl1 to the new array
        if ((spl1[a] <= spl2[b] && a < (size / 2) + val) || b >= (size / 2))
        {
            newArr.push_back(spl1[a]);
            a++;
        }
        else if ((spl1[a] > spl2[b] && b < (size / 2)) || a >= (size / 2) + val)
        {
            newArr.push_back(spl2[b]);
            b++;
        }
    }

    return newArr;
}

int main()
{
    vector<int> numArr;

    numArr.push_back(5);
    numArr.push_back(3);
    numArr.push_back(1);
    numArr.push_back(2);
    numArr.push_back(4);
    numArr.push_back(8);
    numArr.push_back(6);
    numArr.push_back(7);

    int size = numArr.size();
    vector<int> numArrSorted;

    numArrSorted = mergeSort(numArr, size, 0);

    cout << "Final Array: " << endl;
    cout << "--------" << endl;
    for (int i = 0; i <= size - 1; i++)
    {
        cout << numArrSorted[i] << " ";
    }
}