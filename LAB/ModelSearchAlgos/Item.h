// Item.h
#ifndef ITEM_H
#define ITEM_H


#include <stdlib.h>
#include <iostream>

using namespace std;

static int maxKey = 1000;
typedef int Key;
typedef float ItemValue;

class Item {
  private:
    Key keyval;
    ItemValue info;
  public:
    Item() {
        keyval = maxKey;    // this is a nullitem
    }
    Item(Key k, ItemValue v) {
        keyval = k;
        info = v;
    }
    Key key() {
        return keyval;
    }
    void copyItem(Item v)    {
        keyval = v.key();
        info = v.value();
    }
    // void setKey(Key v) {
    //     keyval = v;
    // }    
    ItemValue value() {
        return info;
    }    
    int isNull() {
        return keyval == maxKey;
    }
    void rand() {
        keyval = std::rand()%1000;
        info   = (float)std::rand()/RAND_MAX;
        // keyval = 1000*std::rand()/RAND_MAX;
        // info   = 1.0 *std::rand()/RAND_MAX;
    }
    // linux needs this removed
    int scan(istream &is=cin) {
        return (is >> keyval >> info) != 0;
    }
    void show(ostream &os=cout) {
        os << keyval << " " << info << endl;
    }
};

ostream& operator<<(ostream &os, Item &x) {
    x.show(os);
    return os;
} 

#endif