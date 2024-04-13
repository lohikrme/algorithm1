// FixedStack.cpp
// 13.4.2024

#include <iostream>
#include "FixedStack.h"

void FixedStack::push(int value) {
    stack.push_back(value);
}

int FixedStack::pop() {
    if (!stack.empty()) {
        int value = stack.back();
        stack.pop_back();
        return value;
    }
    else {
        return -9999999;
    }
}

void FixedStack::ReadItem() {
    for (int i = stack.size() - 1; i >= 0; i--) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}
