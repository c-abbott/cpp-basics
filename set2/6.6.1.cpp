// 6.1 Array Operations.
#include <iostream>

using namespace std;

void printArray(const int arr[], const int length)
{
    for(int i = 0; i < length; ++i)
    {
        if(i < length - 1)
        {
            cout << arr[i] << ", ";
        }
        else
        {
            cout << arr[length - 1] << endl;
        }
    }
}

// Prints given array in reverse.
// No new array created.
void reverse(const int arr[], const int length)
{
    for (int i = length - 1; i >= 0; i--)
    {
        if (i > 0)
        {
            cout << arr[i] << ", ";
        }
        else
        {
            cout << arr[0] << endl;
        }
    }
}

// Modifies original array.
void reverseMIT(int numbers[], const int numbersLen){
    for (int i = 0; i < numbersLen / 2; ++i){
        int tmp = numbers[i];
        int indexFromEnd = numbersLen - i - 1;
        numbers[i] = numbers[indexFromEnd];
        numbers[indexFromEnd] = tmp;
    }
    for (int j = 0; j < numbersLen; ++j){
        if (j <= numbersLen - 2) {
            cout << numbers[j] << ", ";
        }
        else {
            cout << numbers[numbersLen - 1] << "\n";
        }
    }
}

// Modifies original array.
void reverseOffset(int numbers[], const int numbersLen) {
    for (int i = 0; i < numbersLen / 2; ++i) {
        int tmp = *(numbers + i);
        int indexFromEnd = numbersLen - 1 - i;
        *(numbers + i) = *(numbers + indexFromEnd);
        *(numbers + indexFromEnd) = tmp;
    }
    for (int j = 0; j < numbersLen; ++j) {
        if (j <= numbersLen - 2) {
            cout << numbers[j] << ", ";
        }
        else
        {
            cout << numbers[numbersLen - 1] << "\n";
        }
    }
}

const int WIDTH = 3;
const int LENGTH = 3;
// Creates new transposed array.
void transpose(const int input[][LENGTH], int output[][WIDTH])
{
    for (int i = 0; i < LENGTH; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            output[j][i] = input[i][j];
        }
    }
    for (int i = 0; i < LENGTH; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            cout << output[i][j];
            if (j == LENGTH - 1)
            {
                cout << "\n";
            }
        }
    }
}

int main()
{
    // Creating 1D array of integers.
    int N;
    cout << "How many integers would you like to separate? " << "\n";
    cin >> N;
    int intArr[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Entry " << i + 1 << ": ";
        cin >> intArr[i];
    }

    // Creating 2D array of integers.
    int input [LENGTH][WIDTH], trans [WIDTH][LENGTH];
    cout << "Enter elements of (3x3) matrix" << "\n";
    for(int i = 0; i < LENGTH; ++i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            cin >> input[i][j];
        }
    }

    // Printing results.
    printArray(intArr, N);
    reverse(intArr, N); // Print reverse.
    reverseMIT(intArr, N); // Actually reverses it.
    reverseOffset(intArr, N); // Reverses it back!
    transpose(input, trans);
    return 0;
}