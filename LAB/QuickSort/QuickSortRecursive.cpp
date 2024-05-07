// QuickSortRecursive.cpp 
// 8th may 2024

#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include "SecondClock.h"

using namespace std;

vector<int> randomizeNumbers(int sizeOfVector) {
    vector<int> v;
    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < sizeOfVector; i++) {
        uniform_int_distribution<int> dis(0, 1000000);
        v.push_back(dis(gen));
    }
    return v;
}

// function swaps 2 items in a vector
void itemSwap(vector<int>& data, int index1, int index2) {
        int temporary = data[index1];
        data[index1] = data[index2];
        data[index2] = temporary;
}

// function moves the item of highestIndex to its final position
// by moving smaller ones left of it, and bigger ones right of it
int partition(vector<int>& data, int lowestIndex, int highestIndex) {
    int middleValue = data[highestIndex];
    int lastSmallerIndex = (lowestIndex - 1);

    for (lowestIndex; lowestIndex <= highestIndex - 1; lowestIndex++) {
        if (data[lowestIndex] < middleValue) {
            lastSmallerIndex++;
            itemSwap(data, lastSmallerIndex, lowestIndex);
        }
    }
    itemSwap(data, lastSmallerIndex + 1, highestIndex);
    return (lastSmallerIndex + 1);
}

// function sorts numbers of vector from smallest to largest using recursion
// good for unarranged or large datasets
void quickSortBasic(vector<int>& data, int lowestIndex, int highestIndex) {
    if (lowestIndex < highestIndex) {
        int pivotIndex = partition(data, lowestIndex, highestIndex);
        quickSortBasic(data, lowestIndex, pivotIndex - 1);
        quickSortBasic(data, pivotIndex + 1, highestIndex);
    }
}

// function sorts numbers of vector from smallest to largest using recursion and median pivot
// good for unarranged or large datasets
void quickSortMedian(vector<int>& data, int lowestIndex, int highestIndex) {
    if (lowestIndex < highestIndex) {
        // Choose pivot to be the median value of first, middle and last item of vector
        // imagine list [6,5,4,3,2,1]... take 6, 4, 1... then if 4 < 6, swap. 
        // then we have 4, 6, 1... then if 1 < 4, swap. 
        // then we have 1, 6, 4... then if 4 < 6 swap... 
        // then we have 1, 4, 6 and median will be the middleIndex one.
        int middleIndex = lowestIndex + (highestIndex - lowestIndex) / 2;
        if (data[middleIndex] < data[lowestIndex])
            itemSwap(data, lowestIndex, middleIndex);
        if (data[highestIndex] < data[lowestIndex])
            itemSwap(data, lowestIndex, highestIndex);
        if (data[highestIndex] < data[middleIndex])
            itemSwap(data, middleIndex, highestIndex);

        // Move pivot to the end of vector before calling partition
        itemSwap(data, middleIndex, highestIndex);

        int pivotIndex = partition(data, lowestIndex, highestIndex);
        quickSortMedian(data, lowestIndex, pivotIndex - 1);
        quickSortMedian(data, pivotIndex + 1, highestIndex);
    }
}

// Insertion method sorts numbers O(n^2) speed
// good for pre-arranged or small datasets
void insertionSort(vector<int>& data) {
    for (int i = 0; i < data.size(); i++) {

        for (int j = i; j > 0; j--) {

            if (data[j - 1] > data[j]) {
                itemSwap(data, j - 1, j);
            }
        }
    }
}




int main()
{
    // These needed for all three different quicksort methods
    int amountOfNumbers = 75000;
    SecondClock timer;

    //--------------------------------------------------------
    // START THE QUICKSORTBASIC METHOD!!!
    cout << "QuickSortBasic is starting..." << endl;

    // generate random numbers
    cout << endl << "Generating random numbers begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;
    
    vector<int> randomNumbers = randomizeNumbers(amountOfNumbers);
    
    cout << "Random numbers have been generated!" << endl;
    cout << timer.getTime() << endl;
    
    // sort the numbers of vector using QuickSortBasic
    cout << endl << "Sorting the numbers using quickSortBasic begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;
    quickSortBasic(randomNumbers, 0, randomNumbers.size() - 1);
    cout << "Numbers have been sorted!" << endl;
    cout << timer.getTime() << endl;


    // write the sorted numbers into a file
    cout << endl << "Writing the numbers into Data/SortedNumbersBasic.txt begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;

    ofstream basicFile("OutputFiles/SortedNumbersBasic.txt");
    if (!basicFile) {
        cerr << "Error opening outputfile for writing.\n";
        return 1;
    }

    for (int i = 0; i < randomNumbers.size(); i++) {
        basicFile << to_string(randomNumbers[i]) << '\n';
    }
    basicFile.close();
    cout << "Numbers have been written in Data/SortedNumbersBasic.txt file!" << endl;
    cout << timer.getTime() << endl;


    //--------------------------------------------------------
    // START THE QUICKSORTMEDIAN METHOD
    cout << endl << "QuickSortMedian is starting..." << endl;

    // generate random numbers
    cout << endl << "Generating random numbers begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;

    randomNumbers = randomizeNumbers(amountOfNumbers);

    cout << "Random numbers have been generated!" << endl;
    cout << timer.getTime() << endl;

    // sort the numbers of vector using QuickSortMedian
    cout << endl << "Sorting the numbers using quickSortMedian begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;
    quickSortMedian(randomNumbers, 0, randomNumbers.size() - 1);
    cout << "Numbers have been sorted!" << endl;
    cout << timer.getTime() << endl;


    // write the sorted numbers into a file
    cout << endl << "Writing the numbers into Data/SortedNumbersMedian.txt begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;

    ofstream medianFile("OutputFiles/SortedNumbersMedian.txt");
    if (!medianFile) {
        cerr << "Error opening outputfile for writing.\n";
        return 1;
    }

    for (int i = 0; i < randomNumbers.size(); i++) {
        medianFile << to_string(randomNumbers[i]) << '\n';
    }
    medianFile.close();
    cout << "Numbers have been written in Data/SortedNumbersMedian.txt file!" << endl;
    cout << timer.getTime() << endl;


    // End the main program
    return 0;
}

