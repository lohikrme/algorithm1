// Tiger.h
// 10th may 2024


#include "Animal.h"
#include <iostream>

#pragma once

class Tiger : public Animal
{
private:
	Continents::Enum continent;

public:
	Tiger() : Animal("Tigru", Species::TIGER, Date(1,1,2010), 210.5, true) {
		this->continent = Continents::ASIA;
	}

	Tiger(std::string name, Species::Enum species, Date birth, double weight, bool female, Continents::Enum continent)
	: Animal(name, species, birth, weight, female) {
		this->continent = continent;
	}

	Continents::Enum getContinent() {
		return this->continent;
	}

	void setContinent(Continents::Enum continent) {
		this->continent = continent;
	}

	void move() override {
		std::cout << "The tiger leaps on its prey..." << std::endl;
	}

	void utter() override {
		std::cout << "GRRR MIAOW NOMNOMNOM!" << std::endl;
	}

	std::string toString() {
		return Animal::toString() + "Continent: " + continentToString(this->continent) + ". ";
	}
};

