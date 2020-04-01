#include <iostream>

using namespace std;

int main()
{
    int arg1;
    arg1 = -1;
    {
        char arg1 = 'A';
        cout << arg1 << endl;
    }
    cout << arg1 << endl;
    return 0;
}