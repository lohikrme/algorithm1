// IntStack.h
// 13.4.2024

#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack {
public:
    virtual void push(int value) = 0;  // Pure virtual function
    virtual int pop() = 0;  // Pure virtual function
};

#endif
