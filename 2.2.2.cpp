#include <iostream>

using namespace std;

// For loop method.
int forLoop(int integer, const char* string)
{
    for (int i = 0; i < integer; i++)
    {
        cout << string << "\n";
    }
    return 0;
}
// While loop method.
int whileLoop(int integer, const char* string)
{
    int i = 1;
    while(true)
    {
        cout << string << "\n";
        if(++i > integer)
            break;
    }
    return 0;
}
// Do while loop method.
int doWhile(int integer, const char* string)
{
    int i = 1;
    bool condition = true;
    while (condition == true)
    {
        cout << string << "\n";
        if (++i > integer)
            condition = false;
    }
    return 0;
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
