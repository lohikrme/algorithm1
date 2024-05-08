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
void insertionSort(vector<int>& data, int lowestIndex, int highestIndex) {
    for (int i = lowestIndex; i < highestIndex; i++) {

        for (int j = i; j > lowestIndex; j--) {

            if (data[j - 1] > data[j]) {
                itemSwap(data, j - 1, j);
            }
        }
    }
}


// function sorts numbers from smallest to largest using first quickSort, and later in small subsets insertionSort
// include also the median of three methods inside hybrid
void quickSortHybrid(vector<int>& data, int lowestIndex, int highestIndex, int insertionSubsetLength) {
    if (lowestIndex < highestIndex) {

        // Choose pivot to be the median value of first, middle and last item of vector
        int middleIndex = lowestIndex + (highestIndex - lowestIndex) / 2;
        if (data[middleIndex] < data[lowestIndex])
            itemSwap(data, lowestIndex, middleIndex);
        if (data[highestIndex] < data[lowestIndex])
            itemSwap(data, lowestIndex, highestIndex);
        if (data[highestIndex] < data[middleIndex])
            itemSwap(data, middleIndex, highestIndex);

        if (highestIndex - lowestIndex + 1 < insertionSubsetLength) {
            insertionSort(data, lowestIndex, highestIndex);
        }
        else {
            int pivotIndex = partition(data, lowestIndex, highestIndex);
            quickSortHybrid(data, lowestIndex, pivotIndex - 1, insertionSubsetLength);
            quickSortHybrid(data, pivotIndex + 1, highestIndex, insertionSubsetLength);
        }
    }
}




int main()
{
    // These needed for all three different quicksort methods
    int amountOfNumbers = 75000;
    SecondClock timer;

    cout << "Quicksort main program is starting..." << endl;
    cout << "Dataset size will be " << amountOfNumbers << " items." << endl;

    // generate random numbers and take copy for each different algo, so every algo sorts same dataset
    cout << endl << "Generating random numbers begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;
    
    vector<int> randomNumbersOriginal = randomizeNumbers(amountOfNumbers);
    vector<int> randomNumbersBasic = randomNumbersOriginal;
    vector<int> randomNumbersMedian = randomNumbersOriginal;
    vector<int> randomNumbersHybrid = randomNumbersOriginal;

    ofstream unorderedFile("OutputFiles/NumbersUnordered.txt");
    if (!unorderedFile) {
        cerr << "Error opening outputfile for writing.\n";
        return 1;
    }

    for (int i = 0; i < randomNumbersMedian.size(); i++) {
        unorderedFile << to_string(randomNumbersMedian[i]) << '\n';
    }
    
    cout << "Random numbers have been generated!" << endl;
    cout << timer.getTime() << endl;
    


    //--------------------------------------------------------
    // QUICKSORTBASIC METHOD!!!
    cout << endl << "Sorting the numbers using quickSortBasic begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;
    quickSortBasic(randomNumbersBasic, 0, randomNumbersBasic.size() - 1);
    cout << "Numbers have been sorted!" << endl;
    cout << timer.getTime() << endl;


    // write the sorted numbers into a file
    cout << endl << "Writing the numbers into OutputFiles/SortedNumbersBasic.txt begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;

    ofstream basicFile("OutputFiles/SortedNumbersBasic.txt");
    if (!basicFile) {
        cerr << "Error opening outputfile for writing.\n";
        return 1;
    }

    for (int i = 0; i < randomNumbersBasic.size(); i++) {
        basicFile << to_string(randomNumbersBasic[i]) << '\n';
    }
    basicFile.close();
    cout << "Numbers have been written in OutputFiles/SortedNumbersBasic.txt file!" << endl;
    cout << timer.getTime() << endl;




    //--------------------------------------------------------
    // QUICKSORTMEDIAN METHOD!!!
    cout << endl << "Sorting the numbers using quickSortMedian begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;
    quickSortMedian(randomNumbersMedian, 0, randomNumbersMedian.size() - 1);
    cout << "Numbers have been sorted!" << endl;
    cout << timer.getTime() << endl;


    // write the sorted numbers into a file
    cout << endl << "Writing the numbers into OutputFiles/SortedNumbersMedian.txt begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;

    ofstream medianFile("OutputFiles/SortedNumbersMedian.txt");
    if (!medianFile) {
        cerr << "Error opening outputfile for writing.\n";
        return 1;
    }

    for (int i = 0; i < randomNumbersMedian.size(); i++) {
        medianFile << to_string(randomNumbersMedian[i]) << '\n';
    }
    medianFile.close();
    cout << "Numbers have been written in OutputFiles/SortedNumbersMedian.txt file!" << endl;
    cout << timer.getTime() << endl;


    //--------------------------------------------------------
    // QUICKSORTHYBRID METHOD!!!
    
    int insertionSubsetLength = 10;
    cout << endl << "Sorting the numbers using quickSortHybrid begins!" << endl 
        << "InsertionSubsetLength will be " << insertionSubsetLength << endl;
    timer.start();
    cout << timer.getTime() << endl;
    quickSortHybrid(randomNumbersHybrid, 0, randomNumbersHybrid.size() - 1, insertionSubsetLength);
    cout << "Numbers have been sorted!" << endl;
    cout << timer.getTime() << endl;


    // write the sorted numbers into a file
    cout << endl << "Writing the numbers into OutputFiles/SortedNumbersHybrid.txt begins!" << endl;
    timer.start();
    cout << timer.getTime() << endl;

    ofstream hybridFile("OutputFiles/SortedNumbersHybrid.txt");
    if (!hybridFile) {
        cerr << "Error opening outputfile for writing.\n";
        return 1;
    }

    for (int i = 0; i < randomNumbersHybrid.size(); i++) {
        hybridFile << to_string(randomNumbersHybrid[i]) << '\n';
    }
    hybridFile.close();
    cout << "Numbers have been written in OutputFiles/SortedNumbersHybrid.txt file!" << endl;
    cout << timer.getTime() << endl;

    // End the main program
    return 0;
}

