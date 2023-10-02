// By: Gabriel Rodriguez, A01027384
// Date: 2021/04/19
// Description: Program that sorts an array using the quick sort algorithm

#include <iostream>
#include <vector>

using namespace std;

// Function that sorts an array using the quick sort algorithm
// Parameters: int arr[] (array to be sorted), int startIndex (first index of the array), int lastIndex (last index of the array)
// Returns: int *arr (sorted array)
vector<int> quickSort2(vector<int> &arr, int startIndex, int lastIndex)
{
    // size of the array calcualted with (hi-lo/2)+lo
    int size = (lastIndex - startIndex);

    // pivot is defined as the middle index of the array
    int pivot = ((size - 1) / 2) + startIndex;
    int temporaryVal;

    // pivot and last element are swapped
    temporaryVal = arr[pivot];
    arr[pivot] = arr[lastIndex];
    arr[lastIndex] = temporaryVal;

    // two indexes are defined, one at the start of the array and one at the end
    int i = 0;
    int j = lastIndex - 1;

    // the array is iterated until the indexes cross
    while (j >= i)
    {
        // if the value of arr[i] is smaller than the pivot, i is incremented
        if (arr[i] <= arr[lastIndex])
        {
            i++;
        }
        // if the value of arr[j] is bigger than the pivot, j is decremented
        else if (arr[j] >= arr[lastIndex])
        {
            j--;
        }
        // once i and j reached values where they should be swapped, they are swapped
        else
        {
            temporaryVal = arr[i];
            arr[i] = arr[j];
            arr[j] = temporaryVal;
        }
    }

    // the pivot is swapped with the value of arr[i] back
    pivot = i;
    temporaryVal = arr[pivot];
    arr[pivot] = arr[lastIndex];
    arr[lastIndex] = temporaryVal;

    // if the size of the array is bigger than 3, the function is called recursively
    if (size > 2)
    {
        quickSort2(arr, pivot + 1, lastIndex);
        quickSort2(arr, startIndex, pivot);
    }

    return arr;
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

    quickSort2(numArr, 0, size - 1);

    cout << "Final Array: " << endl;
    cout << "--------" << endl;
    for (int i = 0; i <= size - 1; i++)
    {
        cout << numArr[i] << " ";
    }
}