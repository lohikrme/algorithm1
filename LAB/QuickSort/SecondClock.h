// SecondClock.h
// 3th may 2024

#include <string>
#include <chrono>

#pragma once
class SecondClock
{
private:
    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();

public:
    // this function returns 
    std::string getTime();

    void start();
};

