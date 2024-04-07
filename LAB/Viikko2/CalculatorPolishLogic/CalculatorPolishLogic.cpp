// CalculatorPolishLogic.cpp : This file contains the 'main' function.
// 8th april 2024 Joonas Harjula

#include <iostream>
#include <vector> 
#include <string>
#include <stdexcept>
#include <cctype>
#include <map>
using namespace std;

// defines local data type to be used inside stacks
typedef string Element;

//---------------------------------------------------------------------------
//---------------- STACK IMPLEMENTATION -------------------------------------

// implements a custom Stack class instead of using <stack> library
class Stack {

private:
    vector<Element> elements;

public:
    // [constructor] reserves space for elements to optimize memory allocation
    Stack() {
        elements.reserve(300);
    }

    // adds a new element to the top of stack
    void push(Element value) {
        elements.push_back(value);
    }

    // deletes the top element from stack
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
        else {
            throw runtime_error("Stack underflow!");
        }
    }

    // returns the top element from stack without deleting it
    Element top() {
        if (!elements.empty()) {
            return elements.back();
        }
        else {
            throw runtime_error("Stack underflow!");
        }
    }

    // deletes all elements from stack clearing stack
    void clearStack() {
        elements.clear();
    }

    // checks if stack is empty or not
    bool isEmpty() {
        return elements.empty();
    }
};


//---------------------------------------------------------------------------
//---------------- REVERSE POLISH NOTATION ----------------------------------

// defines the precedence/priority of the operators
map<Element, int> priority = {
    {"+", 1},
    {"-", 1},
    {"*", 2},
    {"/", 2},
    {"^", 3}
};

// checks if a character is an operator
bool isOperator(Element c) {
    return priority.count(c) > 0;
}

// transforms mathematical expression to polish notation
string stringToPolishLogic(const string& expression) {

    // stores all full numbers here
    string num;

    // creates a stack that stores operators + - * / ^
    Stack operators;

    // stores reverse polish form of expression
    string output;

    // iterates through every character of expression
    for (char c : expression) {

        // character is transformed to string s
        string s(1, c);

        // if character is empty, skip this character
        if (c == ' ') {
            continue;
        }

        // if character is a number or "," or "." they are part of full numbers
        // replace ',' with '.' automatically
        else if (isdigit(c) || c == ',' || c == '.') {
            if (c == ',') {
                num += '.';
            }
            else {
                num += c;
            }
            
        }

        // if character is an operator, we add previous number to output
        // think of situation "200+8*12"
        // first num is 200, then u get +, release 200, store +
        // then u face 8, add to num, face *, release 8, 
        // because priority of + is not >= *, store *. 
        else if (isOperator(s)) {
            if (!num.empty()) {
                output += num + ";";
                num.clear();
            }
            while (!operators.isEmpty() && operators.top() != "(" && priority[operators.top()] >= priority[s]) {
                output += operators.top() + ";";
                operators.pop();
            }
            operators.push(s);
        }


        // if character is an opening parenthesis, it means a new sub-expression starts
        // if num contains something, release it as it belongs to the upper sentence
        // then store '(' to operators
        else if (c == '(') {
            if (!num.empty()) {
                output += num + ";";
                num.clear();
            }
            operators.push(s);
        }

        // if character is a closing parenthesis, it means the latest sub-expression ends
        // if num contains something, release it as it belongs to this same sub-expression
        // then iterate through operators releasing them until u find the matching parenthesis
        else if (c == ')') {
            if (!num.empty()) {
                output += num + ";";
                num.clear();
            }
            while (!operators.isEmpty() && operators.top() != "(") {
                output += operators.top() + ";";
                operators.pop();
            }
            if (!operators.isEmpty()) {
                operators.pop();
            }
        }
    }

    // after every character is iterated, if num contains something, release it. 
    // think of example (22+22)*(44+44)
    // now we have the last 44 in num
    if (!num.empty()) {
        output += num + ";";
    }

    // after every char is iterated and last num is released
    // release the last operators.
    while (!operators.isEmpty()) {
        output += operators.top() + ";";
        operators.pop();
    }

    // this output is now in reverse polish notation
    return output;
}


int main()
{
    while (true) {
        
        // instructions to the user of calculator
        cout << "Welcome to our calculator!" << endl 
            << "You can use + - * / ^ () operators." << endl
            << "If you want to exit, press 'e'" << endl 
            << "Write your calculation here:" << endl;

        // store user given expression here, use getline so wont stop at first space
        string expression; 
        getline(cin, expression); 

        // allow user to end calculating by pressing "e"
        if (expression == "e" or expression == "E") {
            break;
        }
        
        // print the polished_expression to user
        string polished_expression = stringToPolishLogic(expression);
        cout << endl << "The answer to your calculation is: " << endl;
        cout << polished_expression << endl << endl;
    }
}
