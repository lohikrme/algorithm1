// Shark.h
// 10th may 2024

#include "Animal.h"
#include <iostream>

#pragma once
class Shark : public Animal
{
private:
	SeaAreas::Enum sea;

public:
	Shark() : Animal("Jaws", Species::SHARK, Date(1, 1, 2010), 1500, true) {
		this->sea = SeaAreas::Enum::SARGASSO_SEA;
	}

	Shark(std::string name, Species::Enum species, Date birth, double weight, bool female, SeaAreas::Enum seaArea)
		: Animal(name, species, birth, weight, female) {
		this->sea = seaArea;
	}

	SeaAreas::Enum getSea() {
		return this->sea;
	}

	void setSea(SeaAreas::Enum seaArea) {
		this->sea = seaArea;
	}

	void move() override {
		std::cout << "Shark launches itself from the bottom of ocean towards the unsuspecting victim..." << std::endl;
	}

	void utter() override {
		std::cout << "SPLASH SPLISH BULB BULB SPLASH BITE BITE NONOMNOM!!!" << std::endl;
	}

	std::string toString() {
		return Animal::toString() + " Sea area: " + seaAreaToString(this->sea) + ". ";
	}

};

