// DecimalToBitOrHexa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string helperFunction(int number) 
{
    string answer = "";
    vector<string> lettersAsNumbers = { "A", "B", "C", "D", "E", "F" };
    if (number >= 0 and number <= 9) {
        answer = to_string(number);
    }
    else if (number >= 10)
    {
        number -= 10;
        answer = lettersAsNumbers[number];
    }
    return answer;
}

// This function transform a decimal number to a basenumber
// base must be between 2 and 16 (binary and hexadecimal)
int outputBaseNumberString(int number, int base)
{
    // store answer here
    string answer = "";

    // warn user and quit if base number is too high
    if (base > 16) 
    {
        cout << "base must be maximum of 16!" << endl;
        return 1;
    }

    // start transforming the number by dividing with base
    // use helper function to change single numbers to
    // suitable string form, eg 15 = F or 11 = B or 9 = 9
    while (number > 0)
    {
        string remainderNumber = helperFunction(number % base);
        answer.insert(0, remainderNumber);
        number /= base;
    }

    // now we have given full "tens" for the base number
    // so next we define, which base we using, and with that info
    // we can add the remainder as last

    // now answer is ready, so print the answer
    cout << answer << endl;
    return 0;
}

vector<int> testNumbers = { 31,32,33,69,420,2137,77,88 };

int main() {
    int base = 16;
    for (int n : testNumbers)
    {
        outputBaseNumberString(n, base);
    }
    return 0;
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
