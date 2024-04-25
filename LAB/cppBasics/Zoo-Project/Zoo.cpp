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

