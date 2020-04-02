// 4.1 Sums
#include <iostream>

using namespace std;

// Summing with iteration.
int sum(const int arr[], const int L)
{
    int sum = 0;
    for(int j = 0; j < L; j++)
    {
        sum += arr[j];
    }
    return sum;
}

// Summing with recursion.
int recursiveSum(const int arr[], const int L)
{   
    int sum = 0;
    // Base case.
    if(L < 0)
    {
        return sum;
    }
    // Recursive call.
    else
    {
        return arr[L] + recursiveSum(arr, L - 1);
    }
}

int ternarySum(const int arr[], const int L)
{
    int sum = 0;
    return L == 0 ? 0 : arr[0] + ternarySum(arr + 1, L - 1);
}

int main()
{   
    int N;
    int total;
    int recursiveTotal;
    int ternaryTotal;
    cout << "How many integers would you like to sum? ";
    cin >> N;
    int intArr[N];
    cout << "Please enter these N integers" << endl;
    for(int i = 0; i < N; i++)
    {
        cout << "Entry " << i + 1 << ": ";
        cin >> intArr[i];
    }
    total = sum(intArr, N);
    cout << total << endl;
    recursiveTotal = recursiveSum(intArr, N);
    cout << recursiveTotal << endl;
    ternaryTotal = ternarySum(intArr, N);
    cout << ternaryTotal << endl;
    return 0;
}