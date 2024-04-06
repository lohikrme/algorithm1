// CalculatorPolishLogic.cpp : This file contains the 'main' function.
// 6th april 2024 Joonas Harjula

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
    // a stack that stores operators + - * / ^
    Stack operators; 
    // expression in reverse polish notation form
    string output; 

    for (char c : expression) {
        // transform char to string so char works with Element of stack and priority map
        string s(1, c); 
        if (c == ' ') {
            continue;
        }
        else if (isdigit(c)) {
            output += c;
        }

        // if meet an operator of higher priority,
        // then pop the lower priority operator from stack to output,
        // and push from expression the higher priority operator to the stack
        else if (isOperator(s)) {
            while (!operators.isEmpty() && operators.top() != "(" && priority[operators.top()] >= priority[s]) {
                output += operators.top();
                operators.pop();
            }
            operators.push(s);
        }

        // here starts a new sub-expression, push "(" into operators
        // that is a sign that a new sub-expression begins
        // if face multiple (), for example ((2+2)+3)*2
        // then store both (( to the operators, whichs allows to store
        // different layers of sub-expressions
        else if (c == '(') {
            operators.push(s);
        }

        // sub-expression ends, so add all operators from stack to output except "(" which is just deleted
        else if (c == ')') {
            while (!operators.isEmpty() && operators.top() != "(") {
                output += operators.top();
                operators.pop();
            }
            if (!operators.isEmpty()) {
                operators.pop();
            }
        }
    }

    // now we have added 
    while (!operators.isEmpty()) {
        output += operators.top();
        operators.pop();
    }

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
