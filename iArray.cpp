#include <iostream>
#include "iArray.h"
#include <cstdlib>

using namespace std;

//destructor ~iArray() to free allocated memory
iArray :: ~iArray()
{
    delete[] data; //the delete releases the entire data and use [] cz we use new
    //the data is a pointer to allocate memory
}

//initialise(int limit, int n) function, to assign each element of data with random
//numbers between 0 and max -> -1
void iArray :: initialise(int max, int n)
{
    for (int i = 0; i<n && i<size; i++)
    {
        data[i] = rand() % max;
    }
}

void iArray :: display() //print = display
{
    for (int i = 0; i<size; i++)
    {
        cout << data[i] << " ";
    }
}

int iArray :: countOdd()
{
    int count = 0;

    for (int i = 0; i<size; i++)
    {
        if (data[i] % 2 != 0)
        {
            count++;
        }
    }

    return count;
}

//appends the contents of array values (of size n) to the end of array data,
//returning true if successful and false otherwise
bool iArray :: append(int* values, int n)
{
    int* newData = new int[size + n];
    //int* newData: Create a pointer called newData.
    //new int[size + n]: Allocate a new array with enough space for both arrays.
    //For example: Original array has 10 elements.
    //New array has 3 elements.
    //We need space for:[10+3=13]

    //check whether memory allocation fails
    if (newData == nullptr) //if memory allocation fails
    {
        return false; //then return false -> appending unsucessful 
    }

    //loop thru og array and copy each og element into newData
    for (int i=0; i<size; i++)
    {
        newData[i] = data[i];
    } 

    //loop through the new array (values)
    for (int i=0; i<n; i++)
    {
        newData[size + i] = values[i]; //copy its elements into newData
        //size + i = determined where to put each new element
        //n also cz we want to start copying after the og elements
    }

    //free the old array's allocated memory
    delete[] data;
    //we hv alrdy copied all its elements into newData so we dont need it anymore

    //make the og pointer data point to the new array
    data = newData;

    //update the size of the array
    size = size + n; //our array now contains the og elements + the appended elements

    return true; //tell program appending was successful
}
