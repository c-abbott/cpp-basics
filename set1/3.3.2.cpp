// 3.2 Basic Statistics.
#include <iostream>  // std::cout
#include <algorithm> // std::min_element, std::max_element

using namespace std;

double getMean(int arr[], int length)
{
    double sum = 0.0;
    double avg;
    for(int i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    avg = sum / (double)length;
    return avg;
}

int getMax(int arr[], int length)
{
    int result = *max_element(arr, arr + length);
    return result;
}

int getMin(int arr[], int length)
{
    int result = *min_element(arr, arr + length);
    return result;
}

int getRange(int arr[], int length)
{
    int result = *max_element(arr, arr + length) - 
                 *min_element(arr, arr + length);
    return result;
}

int main()
{
    int N;
    // Must enter a postiive integer.
    while (cout << "Enter a positive integer: " &&
           (!(cin >> N) || N < 0))
    {
        cout << "Not a positive integer!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int integerArray[N];
    // Initialising integer array.
    for (int i = 0; i < N; ++i)
    {
        cout << i + 1 << ". Enter number: ";
        cin >> integerArray[i];
    }
    cout << "Mean: " << getMean(integerArray, N) << endl;
    cout << "Max: " << getMax(integerArray, N) << endl;
    cout << "Min: " << getMin(integerArray, N) << endl;
    cout << "Range: " << getRange(integerArray, N) << endl;
    return 0;
}
