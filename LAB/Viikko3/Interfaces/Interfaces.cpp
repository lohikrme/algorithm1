// Interfaces.cpp
// 13.4.2024

#include <iostream>
#include "FixedStack.h"

int main() {
    FixedStack stack;
    for (int i = 0; i <= 20; i++) {
        stack.push(i);
    }
    std::cout << "Stack after adding numbers 0-20:" << std::endl;
    stack.ReadItem();
    for (int i = 0; i < 5; i++) {
        std::cout << "Removing toppest value from stack: " << stack.pop() << std::endl;
    }
    std::cout << "Stack after removing 5 toppest items:" << std::endl;
    stack.ReadItem();

    return 0;
}
