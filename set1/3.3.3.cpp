// 3.3 Prime Numbers.
#include <iostream>
#include <iomanip>

using namespace std;

/* Finding the first 
   N primes. */
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
    for(int i = 2; i < N; ++i)
    {
        bool isPrime = true;
        for(int j = 2; j < i; ++j)
        {
            if(i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            cout << i << "\n";
        }
    } 
    return 0;
}