// Date.h
// 18th april 2024

#pragma once

#include <iostream>
#include <string>

class Date
{
private:
	int d;
	int m;
	int y;

	bool isLeapYear(int year);
	bool isCorrectDate(int day, int month, int year);

public:

	// default constructor
	Date() {
		this->d = 1;
		this->m = 1;
		this->y = 1900;
	}

	// constructor with parameters
	Date(int d, int m, int y) {
		this->d = d;
		this->m = m;
		this->y = y;
	}

	int getD() {
		return this->d;
	}

	void setD(int d) {
		this->d = d;
	}

	int getM() {
		return this->m;
	}

	void setM(int m) {
		this->m = m;
	}

	int getY() {
		return this->y;
	}

	void setY(int y) {
		this->y = y;
	}

	std::string toString();

	bool setValues(int d, int m, int y);

	// create operators that allow natural comparing of dates, e.g date1 < date2
	bool operator<(const Date& other) const {
		if (this->y != other.y)
			return this->y < other.y;
		if (this->m != other.m)
			return this->m < other.m;
		return this->d < other.d;
	}

	bool operator>(const Date& other) const {
		if (this->y != other.y)
			return this->y > other.y;
		if (this->m != other.m)
			return this->m > other.m;
		return this->d > other.d;
	}

	bool operator!=(const Date& other) const {
		if (this->y != other.y || this->m != other.m || this->d != other.d) {
			return true;
		}
		return false;
	}

	bool operator==(const Date& other) const {
		if (this->y == other.y && this->m == other.m && this->d == other.d) {
			return true;
		}
		return false;
	}


};

