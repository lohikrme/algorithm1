// Date.cpp
// 17th april 2024

#include "Date.h"

using namespace std;

bool Date::isLeapYear(int year) {
	// 1200, 1600, 2000, 2400...
	if (year % 400 == 0) {
		return true;
	}
	// 1996, 2004, 2008, 2012
	if (year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	return false;
}

bool Date::isCorrectDate(int day, int month, int year) {
	// determines allowed days for each month of each year
	int maxDaysPerMonth = 0;
	switch (month) {
		// January
	case 1:
		maxDaysPerMonth = 31;
		break;
		// February
	case 2:
		if (isLeapYear(year)) {
			maxDaysPerMonth = 29;
		}
		else {
			maxDaysPerMonth = 28;
		}
		break;
		// March
	case 3:
		maxDaysPerMonth = 31;
		break;
	case 4:
		maxDaysPerMonth = 30;
		break;
	case 5:
		maxDaysPerMonth = 31;
		break;
	case 6:
		maxDaysPerMonth = 30;
		break;
	case 7:
		maxDaysPerMonth = 31;
		break;
	case 8:
		maxDaysPerMonth = 31;
		break;
	case 9:
		maxDaysPerMonth = 30;
		break;
	case 10:
		maxDaysPerMonth = 31;
		break;
	case 11:
		maxDaysPerMonth = 30;
		break;
	case 12:
		maxDaysPerMonth = 31;
		break;
		// if month is less than 1 or more than 12, date is incorrect
	default:
		return false;
	}

	// if day is not in range of maxDaysPerMonth return false
	if (day < 1 || day > maxDaysPerMonth) {
		return false;
	}

	// now we know month and day is allowed range, so date is correct
	return true;
}


string Date::toString() {
	return to_string(this->d) + "." + to_string(this->m) + "." + to_string(this->y);
}

bool Date::setValues(int d, int m, int y) {
	if (isCorrectDate(d, m, y)) {
		this->d = d;
		this->m = m;
		this->y = y;
		return true;
	}
	return false;
}