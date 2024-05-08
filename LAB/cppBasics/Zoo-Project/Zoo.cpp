// Zoo.cpp
// 18th april 2024

#include "Zoo.h"
#include <algorithm>
#include <vector>
#include "AgeComparator.h"

using namespace std;

vector<Animal*> Zoo::getListOfZooAnimals() {
	vector<Animal*> animals;
	// Iterating over the elements of the map
	for (auto & pair : enclosures) {
		animals.push_back(pair.second);
	}
	return animals;
}

// c++ map orders lists automatically by key, so i dont need separately order by name
void Zoo::printSortedByName() {
	vector<Animal*> animals = getListOfZooAnimals();
	for (int i = 0; i < animals.size(); i++) {
		cout << animals[i]->toString() << endl;
	}
}



void Zoo::printSortedByAge() {
	vector<Animal*> animals = getListOfZooAnimals();
	sort(animals.begin(), animals.end(), AgeComparator());
	for (Animal* animal : animals) {
		cout << animal->toString() << endl;
	}
}


Animal* Zoo::remove(string nameOfAnimal) {
	try {
		Animal* returnableAnimal = enclosures[nameOfAnimal];
		enclosures.erase(nameOfAnimal);
		return returnableAnimal;
	}
	catch (...) {
		std::cout << "Animal could not be removed because does not exist." << std::endl;
		return nullptr;
	}
}


Animal* Zoo::add(Animal* newAnimal) {

	Animal* returnableAnimal;

	// check if animal* is found from map using its key (name)
	auto inputAnimalIsInsideMap = enclosures.find(newAnimal->getName());

	// if animal with same key already exists, replace it and then return the old animal
	if (inputAnimalIsInsideMap != enclosures.end()) {
		returnableAnimal = remove(newAnimal->getName());
		enclosures[newAnimal->getName()] = newAnimal;
		return returnableAnimal;
	}
	else {
		enclosures[newAnimal->getName()] = newAnimal;
		return nullptr;
	}
}