/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;


int fibonacci(int n) {
  
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    
   
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;


    if (n < 0 || n > 30) {
        cout << "Input is out of range. Please enter a number between 0 and 30." << endl;
    } else {
        cout << "F(" << n << ") = " << fibonacci(n) << endl;
    }

    return 0;
}
