// euclid_fraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// function prototype
string euclid_fraction(int a, int b);

int main(int argc, char* argv[])
{
    if (argc < 3) {
        cout << "Give two integers as command line parameters." << endl;
        return 1;
    }
    int a = stoi(argv[1]);
    int b = stoi(argv[2]);

    // solve the greatest common divider for both a and b:
    string gcd = euclid_fraction(a, b);
    cout << "The greatest common divider of numbers "
        << a << " and " << b << " is " << gcd << "." << endl;
    return 0;
}

string euclid_fraction(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        cout << " a = " << a << endl;
        cout << " b = " << b << endl;
    }
    return to_string(a);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
