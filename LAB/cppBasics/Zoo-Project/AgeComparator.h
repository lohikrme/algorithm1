// AgeComparator.h
// 18th april 2024

#pragma once


#include <algorithm> // needed for std::sort
#include "Animal.h"

// Comparator function
struct AgeComparator {
    bool operator()(const Animal* a1, const Animal* a2) const {
        return a1->getBirth() < a2->getBirth();
    }
};
