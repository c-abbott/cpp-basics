// 4.4 Factorials Gone Wrong.
#include <iostream>

using namespace std;

int main()
{
    short N;
    // Must enter a postiive integer.
    while (cout << "Enter a positive integer: " &&
           (!(cin >> N) || N < 0))
    {
        cout << "Not a positive integer!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(N > 20)
    {
        cout << "Program will not produce correct result!\n";
    }
    cout << "The factorial of " << N << " is ";
    long long int accumulator = 1;
    for (; N > 0; accumulator *= N--);
    cout << accumulator << ".\n";
    return 0;
}