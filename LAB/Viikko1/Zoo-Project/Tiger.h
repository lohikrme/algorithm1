// Tiger.h
// 17th april 2024


#include "Animal.h"
#include <iostream>
#include <string>
#include "Date.h"
#include "Continents.h"

#pragma once

class Tiger : public Animal
{
private:
	Continents::Enum continent;

public:
	Tiger() : Animal() {
		this->continent = Continents::ASIA;
	}

	Tiger(std::string name, Date birth, double weight, bool female, Continents::Enum continent)
	: Animal(name, birth, weight, female) {
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
		return Animal::toString() + " " + "Continent: " + continentToString(this->continent);
	}
};

