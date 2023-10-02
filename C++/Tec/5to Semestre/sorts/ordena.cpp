// By: Gabriel Rodriguez, A01027384
// Date: 2021/04/19
// Description: Program that sorts an array using the merge sort algorithm and the quick sort algorithm

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Function that sorts an array using the merge sort algorithm
// Parameters: int arr[] (array to be sorted), int size (size of the array), int index (first index of the array)
// Returns: int *newArr (sorted array)
// Computational complexity: O(nlogn) in average, O(nlogn) in the worst case
vector<int> mergeSort(vector<int> arr, int size, int index)
{
    if (size == 0)
    {
        // Base case
        // If the size of the array is 1, return the array
        return arr;
    }
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

// Function that sorts an array using the quick sort algorithm
// Parameters: int arr[] (array to be sorted), int startIndex (first index of the array), int lastIndex (last index of the array)
// Returns: int *arr (sorted array)
// Computational complexity: O(nlogn) in average, O(n^2) in the worst case
vector<int> quickSort(vector<int> &arr, int startIndex, int lastIndex)
{
    // size of the array calcualted with hi-lo
    int size = (lastIndex - startIndex);

    if (size == 0)
    {
        // Base case
        // If the size of the array is 1, return the array
        return arr;
    }

    // pivot is defined as the middle index of the array
    int pivot = ((size - 1) / 2) + startIndex;
    int temporaryVal = 0;

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

    // if the size of the array is bigger than 2, the function is called recursively
    if (size > 2)
    {
        quickSort(arr, pivot + 1, lastIndex);
        quickSort(arr, startIndex, pivot);
    }

    return arr;
}

// Function that prints the values of an array by iterating through it
void imprimeDatos(vector<int> datos, int size, string name)
{
    if (size == 0)
    {
        cout << "Error: array is empty" << endl;
        return;
    }
    cout << "Arreglo ordenado por el metodo: " << name << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << datos[i] << " ";
    }
    cout << endl;
    cout << "-----------------------------------------------------------------" << endl;

    return;
}

// code to read the file
// this code was made based on the following link
// https://www.geeksforgeeks.org/copy-file-to-vector-in-cpp-stl/
// the code was modified to fit the needs of the program, such as returning a array and the size of the array
vector<int> leeDatos(string fileName)
{
    // the variable data is the one that will be returned
    vector<int> data;

    // the file is opened
    ifstream file(fileName);

    // checks if the file was opened correctly
    if (!file)
    {
        cout << "Error opening file " << endl;
        return data;
    }

    // the first line of the file is read to determine the size of the array
    string line;
    int firstVal = 0;
    if (getline(file, line))
    {
        // the first line is converted to an int
        try
        {
            firstVal = stoi(line);
        }
        catch (const exception &)
        {
            // error management
            cout << "Error: wrong file format in file" << endl;
            return data;
        }
    }
    else
    {
        // error management
        cout << "Error: wrong file format in file" << endl;
        return data;
    }

    // the rest of the file is read and converted to an array
    for (int i = 0; i < firstVal; i++)
    {
        if (getline(file, line))
        {
            data.push_back(stoi(line));
        }
    }
    file.close();
    return data;
}

int main()
{
    vector<int> datos = leeDatos("./datos.txt");
    int size = datos.size();

    imprimeDatos(datos, size, "Sin orden"); // datos desordenados

    vector<int> datosOrdenados = mergeSort(datos, size, 0);

    imprimeDatos(datosOrdenados, size, "Merge Sort"); // datos ordenados con Merge Sort

    datosOrdenados = quickSort(datos, 0, size - 1);

    imprimeDatos(datosOrdenados, size, "Quick Sort"); // datos ordenados con Quick Sort

    return 0;
}