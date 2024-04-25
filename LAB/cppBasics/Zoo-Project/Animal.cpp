// Animal.cpp
// 18th april 2024

#include "Animal.h"

using namespace std;

int Animal::nameComparison(string name1, string name2) {
	if (name1 == name2) {
		return 0;
	}
	else if (name1 > name2) {
		return 1;
	}
	else return -1;
}

int Animal::weightComparison(double weight1, double weight2) {
	if (weight1 == weight2) {
		return 0;
	}
	else if (weight1 > weight2) {
		return 1;
	}
	else return -1;
}

string Animal::toString() {
	return "Name " + this->name + " "
		+ "Birthdate: " + this->birth.toString() + " "
		+ "Weight: " + to_string(this->weight) + " "
		+ "Gender: " + (this->female ? "female" : "male");
}



std::string Animal::continentToString(Continents::Enum continent) {
	switch (continent) {
	case Continents::AFRICA: return "AFRICA";
	case Continents::ASIA: return "ASIA";
	case Continents::ANTARCTICA: return "ANTARCTICA";
	case Continents::AUSTRALIA: return "AUSTRALIA";
	case Continents::EUROPE: return "EUROPE";
	case Continents::NORTH_AMERICA: return "NORTH_AMERICA";
	case Continents::SOUTH_AMERICA: return "SOUTH_AMERICA";
	default: return "UNKNOWN";
	}
}

std::string Animal::seaAreaToString(SeaAreas::Enum seaArea) {
	switch (seaArea) {
	case SeaAreas::ARABIAN_SEA: return "ARABIAN_SEA";
	case SeaAreas::ARCTIC_OCEAN: return "ARCTIC_OCEAN";
	case SeaAreas::ANTARCTIC_OCEAN: return "ANTARCTIC_OCEAN";
	case SeaAreas::ATLANTIC_OCEAN: return "ATLANTIC_OCEAN";
	case SeaAreas::BERING_SEA: return "BERING_SEA";
	case SeaAreas::CARIBBEAN_SEA: return "CARIBBEAN_SEA";
	case SeaAreas::CORAL_SEA: return "CORAL_SEA";
	case SeaAreas::EAST_CHINA_SEA: return "EAST_CHINA_SEA";
	case SeaAreas::GULF_OF_MEXICO: return "GULF_OF_MEXICO";
	case SeaAreas::HUDSON_BAY: return "HUDSON_BAY";
	case SeaAreas::INDIAN_OCEAN: return "INDIAN_OCEAN";
	case SeaAreas::MEDITERRANEAN_SEA: return "MEDITERRANEAN_SEA";
	case SeaAreas::NORTH_ATLANTIC_OCEAN: return "NORTH_ATLANTIC_OCEAN";
	case SeaAreas::NORTH_PACIFIC_OCEAN: return "NORTH_PACIFIC_OCEAN";
	case SeaAreas::PACIFIC_OCEAN: return "PACIFIC_OCEAN";
	case SeaAreas::PHILIPPINE_SEA: return "PHILIPPINE_SEA";
	case SeaAreas::SARGASSO_SEA: return "SARGASSO_SEA";
	case SeaAreas::SOUTH_ATLANTIC_OCEAN: return "SOUTH_ATLANTIC_OCEAN";
	case SeaAreas::SOUTH_CHINA_SEA: return "SOUTH_CHINA_SEA";
	case SeaAreas::SOUTH_PACIFIC_OCEAN: return "SOUTH_PACIFIC_OCEAN";
	case SeaAreas::SOUTHERN_OCEAN: return "SOUTHERN_OCEAN";
	case SeaAreas::WEDDELL_SEA: return "WEDDELL_SEA";
	default: return "UNKNOWN";
	}
}