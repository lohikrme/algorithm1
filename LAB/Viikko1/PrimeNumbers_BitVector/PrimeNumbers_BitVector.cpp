// PrimeNumbers_BitVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

int printPrimeNumbers(int n);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Give one number as input." << endl;
        return 1;
    }
    int n = stoi(argv[1]);
    int print_completed = printPrimeNumbers(n);
    return 0;
}

int printPrimeNumbers(int n)
{
    if (n < 0 or n > 999) {
        cout << "Too large or too small number for the primeNumberPrinter!" << endl;
        return 1;
    }
    // assume first none is prime
    bitset<1000> primes;

    for (int i = 2; i <= n; i++)
    {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            primes.set(i);
        }
    }
    
    for (int i = 2; i < 1000; i++) 
    {
        if (primes[i] == 1)
        {
            cout << i << " ";
        }

    }
    cout << endl;
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
