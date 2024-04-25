// Shark.h
// 17th april 2024

#include "Animal.h"
#include <iostream>
#include <string>
#include "Date.h"
#include "SeaAreas.h"

#pragma once
class Shark : public Animal
{
private:
	SeaAreas::Enum sea;

public:
	Shark() : Animal() {
		this->sea = SeaAreas::Enum::SARGASSO_SEA;
	}

	Shark(std::string name, Date birth, double weight, bool female, SeaAreas::Enum seaArea)
		: Animal(name, birth, weight, female) {
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
		return Animal::toString() + " Sea area: " + seaAreaToString(this->sea);
	}

};

