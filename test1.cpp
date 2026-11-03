#include <iostream>
#include <cstdlib>
#include <iArray.h>

using namespace std;

int main()
{
    int n = 10;

    //allocate a pointer (pi) to an iArray instance
    iArray* pi = new iArray(n);

    //fill the array with random numbers 0-99 inclusive
    pi -> initialise (100,n);
    pi -> display();

    //call countOccurence (int x)
    cout << endl << "The number of odd values is: " << pi -> countOdd() << endl;

    //call append
    int data[] = {10, 20, 30};
    pi -> append(data, 3);
    pi -> display();

    delete pi;

    return 0;

}