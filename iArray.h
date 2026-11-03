class iArray
{
private:
    int size;
    int* data;

public:
    iArray(int n) 
    {
        size = n;
        data = new int[size];
    }

    // destructor to free the allocated memory
    ~iArray();

    // initialise the array with n random values between 0 and max-1 (inclusive)
    void initialise(int max, int n);

    // print the elements of data in one-line, each separated with a space
    void display();

    // count the number of occurrences of odd numbers in the array
    int countOdd();

    // append array ‘values’ (with n elements) to the array ‘data’
    bool append(int* values, int n);
};
