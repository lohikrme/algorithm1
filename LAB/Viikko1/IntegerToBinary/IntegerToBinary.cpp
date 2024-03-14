// IntegerToBinary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string integer_to_binary(int number);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Give one integer number to be transformed into a binary number." << endl;
        return 1;
    }
    int input = stoi(argv[1]);
    string binarynumber = integer_to_binary(input);
    cout << input << " is " << binarynumber << " as a binary number." << endl;
    return 0;
}

// my own algorithm works next:
// 
// 1. find largest 2^x number from input
// for example, 17 < 32, but 17 > 16
// then substract the largest number from input
// 
// 2. Check every 2^x number below the largest 2^x number
// If left < right, substract right away
// 
// 3. Example of total process using 17:
//      largest 2^x number < 17 = 16
//      substract 17 - 16, left remainder = 1 -> binary number = "1"
//      1 < 2^3 -> binary number = "10"
//      1 < 2^2 -> binary number = "100"
//      1 < 2^1 -> binary number = "1000"
//      1 >= 1^0 -> binary number = "10001"
//      1 - 1, left remainder = 0
//      if x > 0, rest of binaries will be 0

string integer_to_binary(int number)
{
    string answer = "";

    // step 1: find largest number and the 2^x = largest number x-variable
    int largest_number = 0;
    int exponent_of_2 = 0;
    while (number >= pow(2, exponent_of_2))
    {
        exponent_of_2 += 1;
    };
    exponent_of_2 -= 1;
    largest_number = pow(2, (exponent_of_2));

    // step 2: go down from largest number to 2^0

    for (int i = exponent_of_2; i >= 0; i--)
    {
        if (number >= pow(2, i))
        {
            number -= pow(2, i);
            answer += "1";
        }
        else
        {
            answer += "0";
        }
    }

    return answer;
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
