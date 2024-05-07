
// SecondClock.cpp
// 4th may 2024

#include "SecondClock.h"
using namespace std;

string SecondClock::getTime() {

     this->currentTime = chrono::high_resolution_clock::now();
     double elapsedMilliseconds = chrono::duration<double, milli>(this->currentTime - this->startTime).count();

     // form time to print
     string minutesInClock = "00";
     string secondsInClock = "00";
     string millisecondsInClock = "000";

     int elapsedMinutesInt = static_cast<int>(elapsedMilliseconds) / 60000;
     int elapsedSecondsInt = (static_cast<int>(elapsedMilliseconds) / 1000) % 60;
     int elapsedMillisecondsInt = static_cast<int>(elapsedMilliseconds) % 1000;

     // if clock goes over one hour, starts from 0 minute
     if (elapsedMinutesInt >= 60) {
         elapsedMinutesInt -= 60;
     }

     // draw minutes
     if (elapsedMinutesInt >= 10) {
         minutesInClock = to_string(elapsedMinutesInt);
     }
     else {
         minutesInClock = "0" + to_string(elapsedMinutesInt);
     }

     // draw seconds
     if (elapsedSecondsInt >= 10) {
         secondsInClock = to_string(elapsedSecondsInt);
     }
     else {
         secondsInClock = "0" + to_string(elapsedSecondsInt);
     }

     // draw milliseconds
     if (elapsedMillisecondsInt >= 100) {
         millisecondsInClock = to_string(elapsedMillisecondsInt);
     }
     else if (elapsedMillisecondsInt >= 10) {
         millisecondsInClock = "0" + to_string(elapsedMillisecondsInt);
     }
     else {
         millisecondsInClock = "00" + to_string(elapsedMillisecondsInt);
     }

     return minutesInClock + ":" + secondsInClock + ":" + millisecondsInClock;
}


void SecondClock::start() {
    this->startTime = chrono::high_resolution_clock::now();
    this->currentTime = chrono::high_resolution_clock::now();
}