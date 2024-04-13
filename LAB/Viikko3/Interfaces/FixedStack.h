// FixedStack.h
// 13.4.2024

#ifndef FIXEDSTACK_H
#define FIXEDSTACK_H

#include <vector>
#include "OpenStack.h"

class FixedStack : public OpenStack {
private:
    std::vector<int> stack;
public:
    FixedStack() {}
    void push(int value);
    int pop();
    void ReadItem();
};

#endif
