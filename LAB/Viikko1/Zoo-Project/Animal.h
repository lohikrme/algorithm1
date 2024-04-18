// Animal.h
// 18th april 2024

#pragma once

#include <iostream>
#include <string>
#include "Date.h"
#include "Continents.h"
#include "SeaAreas.h"

class Animal
{
private:
	std::string name;
	Date birth;
	double weight;
	bool female;

	// compare if name1 is bigger than name2
	int nameComparison(std::string name1, std::string name2);

	// compare if weight1 is bigger than weight2
	int weightComparison(double weight1, double weight2);

public:
	// default constructor
	Animal() {
		this->name = "Haukku";
		this->birth = Date(1, 1, 2000);
		this->weight = 200.5;
		this->female = true;
	}

	// constructor with parameters
	Animal(std::string name, Date birthDate, double weight, bool female) {
		this->name = name;
		this->birth = birthDate;
		this->weight = weight;
		this->female = female;
	}

	std::string getName() const {
		return this->name;
	}

	void setName(std::string name) {
		this->name = name;
	}

	Date getBirth() const {
		return this->birth;
	}

	void setBirth(Date birth) {
		this->birth = birth;
	}

	double getWeight() const {
		return this->weight;
	}

	void setWeight(double weight) {
		this->weight = weight;
	}

	bool isFemale() {
		return this->female;
	}

	void setFemale(bool female) {
		this->female = female;
	}

	virtual std::string toString();

	virtual void move() = 0;
	virtual void utter() = 0;

	// used to transform continent enum to string
	std::string continentToString(Continents::Enum continent);

	// used to transform sea area to string
	std::string seaAreaToString(SeaAreas::Enum seaArea);

	// create operators that allow natural comparing of animal subclasses, e.g tiger1 < tiger2
	bool operator<(const Animal& other) const {
		if (this->name != other.name)
			return this->name < other.name;
		if (this->birth != other.birth)
			return this->birth < other.birth;
		return this->weight < other.weight;
	}

	bool operator>(const Animal& other) const {
		if (name != other.name) 
			return name > other.name;
		if (birth != other.birth) 
			return birth > other.birth;
		return weight > other.weight;
	}

	bool operator!=(const Animal& other) const {
		if (this->name != other.name || this->birth != other.birth || this->weight != other.weight) {
			return true;
		}
		return false;
	}

	bool operator==(const Animal& other) const {
		if (this->name == other.name && this->birth == other.birth && this->weight == other.weight) {
			return true;
		}
		return false;
	}

	

};

