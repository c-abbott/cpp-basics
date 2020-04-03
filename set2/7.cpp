// 7. Pointers and String
#include <iostream>

using namespace std;

int getStrLength(const char* str) {
    int length = 0;
    while (*(str + length) != '\0') {
        ++length;
    }
    return length; 
}
// Can pass just the variables.
void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}
// Must pass by reference.
void swapWithPointers(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;  

}
// Passing pointer locations.
void swapPointers(int **x, int **y) {
    int *tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    // String length.
    char str[100];
    cout << "Enter a string: ";
    cin.get(str, 100);
    int strLength;
    strLength = getStrLength(str);
    cout << strLength << endl;

    // Pointer swap.
    int x = 5, y = 6;
    int *ptr1 = &x, *ptr2 = &y;
    swapPointers(&ptr1, &ptr2);
    cout << *ptr1 << " " << *ptr2 << endl; // Prints "6 5"

    // 7.5
    char *oddOrEven = "Never odd or even"; // Creates pointer to string literal consisting of char*.
    char *nthCharPtr = &oddOrEven[5]; // Creates pointer to the address of the 6th char.
    nthCharPtr -= 2; // Now pointing to the fourth element.
    cout << *nthCharPtr << "\n"; // Printing the value stored in the memory location the pointer points to.
    char **pointerPtr = &nthCharPtr; // Create pointer to the original pointer.
    cout << pointerPtr << "\n"; // Will print where in the memory this is stored.
    cout << **pointerPtr << "\n"; // First dereference takes you to nthCharPter, second takes you to 'e'
    cout << nthCharPtr - oddOrEven << endl; // Distance between pointer and start of the string. (3)
    return 0;
}