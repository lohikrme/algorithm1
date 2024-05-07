// Types.h
#ifndef TYPES_H
#define TYPES_H

#include "Item.h"

// value outside the data range
// #define INFONIL ((Item)"\xff\xff\xff")

// min value - should be outside the data range
// #define KEYMIN ((Item)"\x01\x01\x01")

// Tree node info item 
// typedef char *Item;

// Tree node definition
struct node {
    Item item;
    node *left, *right;

    node(Item x, node *l, node *r) {
        item = x;
        left = l;
        right = r;
    };
};

// Tree link type
typedef struct node *link;

#endif
