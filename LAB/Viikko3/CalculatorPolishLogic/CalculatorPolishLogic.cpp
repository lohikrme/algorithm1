// CalculatorPolishLogic.cpp : This file contains the 'main' function.
// 8th april 2024 Joonas Harjula
// dependant on c++ 14th version

#include <iostream>
#include <vector> 
#include <sstream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <map>
using namespace std;

// defines local data type to be used inside stacks
typedef string Element;
typedef double Number;

// defines mysteryDouble to be used in stringToDouble function and calculate function
double mysteryDouble = -952367.9238123;

//---------------------------------------------------------------------------
//---------------- STACK IMPLEMENTATION -------------------------------------

// implements a custom Stack class instead of using <stack> library
// user can create a new Stack object and decide the preferred datatype
template <typename LocalType>
class Stack {

private:
    vector<LocalType> elements;
    int items = 0;

public:
    // [constructor] reserves space for elements to optimize memory allocation
    Stack() {
        elements.reserve(300);
    }

    // adds a new element to the top of stack
    void push(LocalType value) {
        elements.push_back(value);
        items += 1;
    }

    // deletes the top element from stack
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
            items -= 1;
        }
        else {
            throw runtime_error("Stack underflow!");
        }
    }

    // returns the top element from stack without deleting it
    LocalType top() {
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

    // returns how many items are inside the stack
    int size() {
        return items;
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

//-------------- POLISH LOGIC FUNCTION-----------------------
// transforms mathematical expression to polish notation
string stringToPolishLogic(const string& expression) {

    // stores all full numbers here
    string num;

    // creates a stack that stores operators + - * / ^
    Stack<Element> operators;

    // stores reverse polish form of expression
    string output;

    // if last letter was "(", that means "-" must be a prefix for number
    bool previousIsOpenParenthesis = false;

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
            previousIsOpenParenthesis = false;
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
            if (previousIsOpenParenthesis && s == "-") {
                output += "-";
                previousIsOpenParenthesis = false;
                continue;
            }
            
            // if meet an operator, add number to the output
            else if (!num.empty()) {
                output += num + ";";
                num.clear();
                previousIsOpenParenthesis = false;
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
            previousIsOpenParenthesis = true;
            if (num.empty()) {
                continue;
            }
            else if (!num.empty()) {
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

//--------------- ISDOUBLE FUNCTION --------------------------------------
// transforms string to double, or returns a secretDouble if string is not a number
double stringToDouble(const std::string& s)
{
    bool isValid = false;
    std::istringstream iss(s);
    double d;
    isValid = (iss >> d) && iss.eof();
    return isValid ? d : mysteryDouble;
}


//--------------- CALCULATE FUNCTION ---------------------------------------
// receives reverse polish notation as input param and returns calculated answer
string calculate(string notation) {

    // store here the local Double during loop phase
    double localDouble;

    // split notation into this vector
    vector<string> notationVector;

    // take 2 numbers from this stack every time you meet an operator
    Stack<Number> numberStack; 

    // split received notation by ";" and add to the notationVector via istringstream method
    istringstream iss(notation);
    string word;
    while (getline(iss, word, ';')) {
        notationVector.push_back(word);
    }

    // run through every element of notationVector
    for (const auto& element : notationVector) {
        // cout << "element: " << element << endl;

        // try to transform the current element to a double, if result is != mysteryDouble, it is a double, if == mysteryDobule, it is an operator
        localDouble = stringToDouble(element);
        // cout << "localDouble: " << localDouble << endl;

        // element was a number, so push it in the numberStack
        if (localDouble != mysteryDouble) {
            numberStack.push(localDouble);
        }

        // else was an operator, so take 2 numbers from stack, calculate their new value using current operator and push back the new value
        else {
            if (numberStack.size() < 2) {
                throw std::runtime_error("Not enough numbers for operation");
            }
            double num2 = numberStack.top();
            numberStack.pop();
            double num1 = numberStack.top();
            numberStack.pop();

            if (element == "+") {
                numberStack.push(num1 + num2);
            }
            else if (element == "-") {
                numberStack.push(num1 - num2);
            }
            else if (element == "*") {
                numberStack.push(num1 * num2);
            }
            else if (element == "/") {
                numberStack.push(num1 / num2);
            }
            else if (element == "^") {
                numberStack.push(pow(num1, num2));
            }
        }
    }

    // take the answer from stack and return it
    string answer = to_string(numberStack.top());
    return answer;
}


int main()
{
    while (true) {
        
        // instructions to the user of calculator
        cout << "Welcome to our calculator!" << endl
            << "You can use + - * / ^ () operators." << endl
            << "If you want to use the '-' operator as a prefix" << endl
            << "such as '-2+2', you must write every number with prefix" << endl
            << "inside parenthesis. So correct form would be '(-2)+2'" << endl
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
        cout << endl << "The reverse polish notation to your calculation is: " << endl;
        cout << polished_expression << endl << endl;

        string answer = "trololoo";
        answer = calculate(polished_expression);

        cout << endl << "The answer to your calculation is: " << endl;
        cout << answer << endl << endl;
    }
}
