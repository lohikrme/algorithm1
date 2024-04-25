// LenghtyTask.cpp
// 22.4.2024

#include <iostream>
#include <string>
#include <chrono>
using namespace std;

void showProgress(int progress, double totalSeconds) {
 // form time to print
    string minutesInClock = "00";
    string secondsInClock = "00";

    int elapsedMinutes = static_cast<int>(totalSeconds) / 60;
    int elapsedSeconds = totalSeconds - elapsedMinutes * 60;

    if (elapsedMinutes >= 10) {
        minutesInClock = to_string(elapsedMinutes);
    } 
    else {
        minutesInClock = "0" + to_string(elapsedMinutes);
    }

    if (elapsedSeconds >= 10) {
        secondsInClock = to_string(elapsedSeconds);
    }
    else {
        secondsInClock = "0" + to_string(elapsedSeconds);
    }

    cout << "Time passed so far: " << minutesInClock << ":" << secondsInClock << endl;
    cout << "Installation is " << progress << " % completed." << endl;
    cout << endl;    
}

long lenghtyTask(long goalNumber) {
    long count = 0;
    double nextIncrementPercent = 5;
    double progressPercent = 0;
    long goal = goalNumber;

    // Start timer
    auto start = chrono::high_resolution_clock::now();

    while (count < goal) {
        count++;
        progressPercent = static_cast<double>(count) / goal * 100;
        if (progressPercent >= nextIncrementPercent) {
            auto end = chrono::high_resolution_clock::now();
            double elapsedSeconds = chrono::duration<double>(end - start).count();
            showProgress(progressPercent, elapsedSeconds);
            nextIncrementPercent += 5;
        }
    }
    return count;
}

int main()
{
    lenghtyTask(1000000000);
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
