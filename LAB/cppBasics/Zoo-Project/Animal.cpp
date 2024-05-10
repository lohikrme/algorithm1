// Animal.cpp
// 10th may 2024

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

	// CLEAN THE WEIGHT DECIMAL NUMBER TO SUITABLE AMOUNT OF MAX DECIMALS AND SIGNIFICANT NUMBERS ONLY

	// osstringstream allows to set decimal accurasy of 3
	ostringstream stream;
	stream << std::fixed << setprecision(3) << this->weight;
	string weightStr = stream.str();

	// use stack to store numbers and dots
	stack<char> number;

	for (char& c : weightStr) {
		number.push(c);
	}

	// delete numbers until meet significant number (1-9)
	while (!number.empty() && (number.top() == '0' || number.top() == '.')) { 
		if (number.top() == '.') {
			number.pop();
			break;
		}
		number.pop();
	}

	// move stack content into reverseWeigth string, also replace '.' with ','
	string reverseWeight; 

	while (!number.empty()) { 
		if (number.top() == '.') {
			reverseWeight += ',';
			number.pop();
		}
		else {
			reverseWeight += number.top();
			number.pop();
		}
	}

	// move reverseWeight content in weightStr in correct order
	weightStr = ""; 

	for (char& c : reverseWeight) {
		weightStr = c + weightStr;
	}

	// PRINT THE ANIMAL ATTRIBUTES
	return "Name " + this->name + ". "
		+ "Species: " + this->speciesToString(this->species) + ". "
		+ "Birthdate: " + this->birth.toString() + ". "
		+ "Weight: " + weightStr + ". "
		+ "Gender: " + (this->female ? "female" : "male") + ". ";
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

std::string Animal::speciesToString(Species::Enum species)
{
	switch (species) {
	case Species::COBRA: return "COBRA";
	case Species::CROCODILE: return "CROCODILE";
	case Species::DOG: return "DOG";
	case Species::ELEPHANT: return "ELEPHANT";
	case Species::LIZARD: return "LIZARD";
	case Species::MANGOOSE: return "MANGOOSE";
	case Species::PARROT: return "PARROT";
	case Species::SHARK: return "SHARK";
	case Species::TIGER: return "TIGER";
	default: return "UNKNOWN";
	}
}

