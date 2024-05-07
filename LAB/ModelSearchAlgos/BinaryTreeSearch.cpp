// BinaryTreeSearch.cpp 
// Compile: g++ -std=c++14 BinaryTreeSearchRecursive.cpp   -o BinaryTreeSearchRecursive
// run test: valgrind ./BinaryTreeSearchRecursive

#include <iostream>
#include <string.h>

#include "Types.h"
#include "Item.h"

using namespace std;

// value outside the data range
#define INFONIL 0

class BinaryTree {
  private:
    link root;
    Item nullItem;

    Item searchR(link h, Key v) {
        if(h == nullptr)    return nullItem;
        Key t = h->item.key();
        if(v == t)  return h->item;
        if(v < t)   return searchR(h->left, v);
        else        return searchR(h->right, v);
    }

    void insertR(link &h, Item x) {
        if(h == nullptr)    {
            h = new node(x, nullptr, nullptr);
            return;
        }
        if(x.key() < h->item.key()) insertR(h->left, x);
        else                        insertR(h->right, x);
    }

  public:
    link getRoot() {
        return root;
    }
    BinaryTree() {
        root = nullptr;
    }
    ~BinaryTree() {
        deleteTree(root);
    }
    void deleteTree(link t) {
        if(t == nullptr)    return;
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
    int isEmpty() {
        return (root == nullptr);
    }
    Item search(Key v) {
        return searchR(root, v);
    }
    void insert(Item x) {
        return insertR(root, x);
    }
    void traverse_inorder(link t, void (*pfVisit)(link node)) {
        if(t == nullptr)    return;

        traverse_inorder(t->left, pfVisit);
        (*pfVisit)(t);
        traverse_inorder(t->right, pfVisit);
    }
};

void printItem(link t) {
    cout << "- k:"<< t->item.key() << " v:" << t->item.value() << endl;
}

int main() {
    Item data[] = {
        Item(30,1.0),
        Item(37,2.0),
        Item(17,3.0),
        Item(11,4.0),
        Item(19,5.0),
        Item(31,6.0),
        Item(38,7.0),
        Item(10,8.0)
    };

    int i;
    Item item;
    BinaryTree bt;

    for(i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
        bt.insert(data[i]);
    }
    cout << "Insert done ... traversal..." << endl;
    bt.traverse_inorder(bt.getRoot(), printItem);
    cout << "Insert done ... searching..." << endl;

    for(i = sizeof(data)/sizeof(data[0])-1; i>= 0; i--) {
        Item t = bt.search(data[i].key());
        cout << "searching for " << data[i].key() << " result: ";
        cout << t.key() <<" with value "<< t.value() << endl;
    }
    return 0;
}

