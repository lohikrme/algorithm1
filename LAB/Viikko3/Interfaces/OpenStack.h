// OpenStack.h
// 13.4.2024

#ifndef OPENSTACK_H
#define OPENSTACK_H

#include "IntStack.h"

class OpenStack : public IntStack {
public:
    virtual void ReadItem() = 0;  // Pure virtual function
};

#endif
