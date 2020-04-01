// 3.4 Multiples of numbers
#include <iostream>

using namespace std;

int main()
{
    int N;
    int result;
    while(true)
    {
        cout << "Enter an integer: ";
        cin >> N;
        if (N == -1)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else if (N % 5 != 0)
        {
            continue;
        }
        result = N/5;
        cout << result << endl;
    }
    return 0;
}