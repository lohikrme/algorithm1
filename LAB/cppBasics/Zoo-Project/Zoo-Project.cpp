// Zoo-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 18th april 2024

#include <iostream>
#include <string>
#include "Date.h"
#include "Animal.h"
#include "Shark.h"
#include "Tiger.h"
#include "Continents.h"
#include "SeaAreas.h"
#include <vector>
#include <algorithm>
#include "Zoo.h"

using namespace std;

int main()
{
    // test that Date object's basic abilities work
    cout << endl;
    cout << "Testing basic methods of Date object..." << endl;
    Date date1 = Date(15, 4, 2024);
    cout << date1.toString() << endl;
    date1.setValues(16, 4, 2024);
    cout << date1.toString() << endl;
    cout << "Basic methods of Date object work!" << endl;
    cout << endl;

    // test that Date compareTo works
    cout << "Testing compareTo method of Date object..." << endl;
    Date date2 = Date(26, 6, 2023);
    Date date3 = Date(1, 1, 2024);
    Date date4 = Date(2, 1, 2024);
    vector<Date> dates;

    dates.push_back(date1);
    dates.push_back(date2);
    dates.push_back(date3);
    dates.push_back(date4);

    sort(dates.begin(), dates.end());

    for (int i = 0; i < dates.size(); i++) {
        cout << dates[i].toString() << endl;
    }
    cout << "compareTo method of Date object works!" << endl;
    cout << endl;

    // test that tiger class that inherited Animal works
    cout << "Testing Tiger class..." << endl;
    Tiger tiger1 = Tiger();
    Tiger tiger2 = Tiger("Tigru", date2, 255, false, Continents::ASIA);
    cout << "Tiger1: " + tiger1.toString() << endl;
    cout << "Tiger2: " + tiger2.toString() << endl;
    cout << tiger2.getName() << endl;
    tiger2.move();
    tiger2.utter();
    cout << "Tiger class works as expected!" << endl;
    cout << endl;

    // test that also Shark class works which also inherited Animal class
    cout << "Testing Shark class..." << endl;
    Shark shark1 = Shark("Hampaaton", date3, 1500.2, true, SeaAreas::SOUTH_ATLANTIC_OCEAN);
    cout << shark1.toString() << endl;
    shark1.move();
    shark1.utter();
    cout << "Shark class works as expected!" << endl;
    cout << endl;

    // test that zoo works as expected
    // special focus on ordering by name and ordering by birthdate
    cout << "Testing Zoo class..." << endl;

    Date date10 = Date(20, 6, 2001);
    Date date11 = Date(30, 10, 1999);
    Date date12 = Date(15, 3, 2010);
    Date date13 = Date(6, 4, 2004);
    Date date14 = Date(10, 10, 2015);

    // create pointers to animals using subclasses tiger and shark
    Animal* tiger10 = new Tiger("David", date10, 350, false, Continents::ASIA);
    Animal* tiger11 = new Tiger("Arttu", date11, 250, false, Continents::ASIA);
    Animal* tiger12 = new Tiger("Silja", date12, 300, true, Continents::ASIA);
    Animal* shark13 = new Shark("Arttu", date13, 750, false, SeaAreas::CARIBBEAN_SEA);
    Animal* shark14 = new Shark("Bandit", date14, 800, true, SeaAreas::SARGASSO_SEA);

    cout << "Animals are created, 3 tigers and 2 sharks." << endl;
    cout << "Next we will test, what happens, if i try to insert 2 animals of same name." << endl;
    cout << "If 'Arttu' has Sea-Area: CARIBBEAN_SEA, it means that newer Arttu replaced old one" << endl;

    Zoo zoo = Zoo();
    zoo.add(tiger10);
    zoo.add(tiger11);
    zoo.add(tiger12);
    zoo.add(shark13);
    zoo.add(shark14);

    cout << endl;
    cout << "Print sorted by name method: " << endl;
    zoo.printSortedByName();
    cout << endl;

    cout << "Print sorted by birthdate method : " << endl;
    zoo.printSortedByAge();
    cout << endl;

    cout << "The printSortedByAge method works!" << endl;
    cout << endl;

    cout << "Next we will try to add the tiger named 'arttu' again. " << endl;
    cout << "Ideally add-command returns the info of the shark," << endl;
    cout << "and then tiger named 'Arttu' is found in the list" << endl;
    cout << zoo.add(tiger11)->toString() << endl;
    cout << endl;
    cout << "As expected, adding returned the shark named 'Arttu'. Now make sure tiger replaced the shark:" << endl;
    zoo.printSortedByName();
    cout << endl;
    cout << "As expected, now tiger is inside the zoo, Continent word tells its tiger not shark!" << endl;
    cout << endl;

    cout << "Next trying out if the remove function works properly. Trying to remove the shark named 'Bandit'" << endl;
    cout << zoo.remove("Bandit")->toString() << endl;
    cout << "Bandit should we removed, print animals by name" << endl;
    zoo.printSortedByName();
    cout << endl;
    cout << "Everything looks so far as expected. Therefore, the zoo class and all assisting classes seems to work correctly!" << endl;

}

