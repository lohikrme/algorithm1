// StringToInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// function prototypes
int string_to_integer(string numbers);
// function 2
// function 3
// function 4

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Give a string of numbers as a command line parameter." << endl;
        return 1;
    }
    string new_integer = argv[1];
    cout << new_integer << endl;
    return 0;
}

int string_to_integer(string numbers) {
    int result = 0;
    int length = numbers.length();
    for (int i = 0; i < length; ++i) {
        if (numbers[i] == ' ') {
            break;
        }
        int digit = numbers[i] - '0';
        result += digit * pow(10, length - i - 1);
    }
    return result;
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

