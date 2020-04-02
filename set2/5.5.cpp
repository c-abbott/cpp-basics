// 5 Calculating Pi.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{   
    srand(time(0));
    double x;
    double y;
    int n;
    int counter = 0;
    // Must enter a postiive integer.
    while (cout << "Enter the number of dart throws: " &&
           (!(cin >> n) || n < 0))
    {
        cout << "Not a positive integer!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for(int i = 0; i < n; i++)
    {
        x = rand() / (double)RAND_MAX;
        y = rand() / (double)RAND_MAX;
        double dist = sqrt(x * x + y * y);
        if(dist < 1.0)
        {
            counter += 1;
        }
    }
    float pi;
    pi =  4 * (float)counter / (float)n;
    cout << "The value of pi is approximately: " << pi << endl;
    return 0;
}

