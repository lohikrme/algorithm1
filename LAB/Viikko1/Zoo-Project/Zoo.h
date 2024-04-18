// Zoo.h
// 18th april 2024

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

    void add(Animal* animal) {
        enclosures[animal->getName()] = animal;
    }


    void remove(std::string nameOfAnimal) {
        Animal* animal = enclosures[nameOfAnimal];
        enclosures.erase(nameOfAnimal);
        delete animal;
    }

    void printSortedByName();

    
    void printSortedByAge();
};

