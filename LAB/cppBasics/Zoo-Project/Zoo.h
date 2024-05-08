// Zoo.h
// 8th may 2024

#include <map> // needed for map ds
#include <vector> // needed for vector ds
#include <algorithm> // needed for sorting the animals
#include <string>
#include "Animal.h"
#include "Date.h"
#include "AgeComparator.h"

#pragma once
class Zoo
{
private:
    std::map<std::string, Animal*> enclosures;

    // returns list of animals ordered by name, date, weight
    std::vector<Animal*> getListOfZooAnimals();

public:

    // add first destructor, because zoo class uses pointers to avoid memory overleak
    ~Zoo() {
        for (auto const& pair : enclosures) {
            delete pair.second;
        }
    }


    Animal* remove(std::string nameOfAnimal);


    Animal* add(Animal* animal); 
    

    void printSortedByName();

    
    void printSortedByAge();
};

