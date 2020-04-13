// 2.2 Hello World II
#include <iostream>

using namespace std;

// For loop method.
void forLoop(int integer, const char* string)
{
    for (int i = 0; i < integer; i++)
    {
        cout << string << "\n";
    }
}
// While loop method.
void whileLoop(int integer, const char* string)
{
    int i = 1;
    while(true)
    {
        cout << string << "\n";
        if(++i > integer)
            break;
    }
}
// Do while loop method.
void doWhile(int integer, const char* string)
{
    int i = 0;
    do
    {
        cout << string << "\n";
        i++;
    }
    while(i < integer);
}
// Main programme.
int main()
{
    const char* str = "Hello, World!";
    string method;
    int n;
    // Must enter a postiive integer.
    while(cout << "Enter a positive integer: " && 
         (!(cin >> n) || n < 0))
    {
        cout << "Not a positive integer!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter a vaid method; for, while or do while: ";
    cin >> method;

    if (method == "for")
    {
        forLoop(n, str);
    }
    if (method == "while")
    {
        whileLoop(n, str);
    }
    if (method == "dowhile")
    {
        doWhile(n, str);
    }
    return 0;
}
