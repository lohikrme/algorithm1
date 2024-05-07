// BinaryTreeSearch-v2.cpp 
// Compile: g++ -std=c++14 BinaryTreeSearch-v2.cpp   -o BinaryTreeSearch-v2
// run test: valgrind ./BinaryTreeSearch-v2
// added insert to top and remove

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

    void rotR(link &h) {
        link x = h->left;
        h->left = x->right;
        x->right = h;
        h = x;
    }
    void rotL(link &h) {
        link x = h->right;
        h->right = x->left;
        x->left = h;
        h = x;
    }
    void insertT(link &h, Item x) {
        if(h == nullptr) {
            h = new node(x, nullptr, nullptr);
            return;
        }
        if(x.key() < h->item.key()) {
            insertT(h->left, x);
            rotR(h);
        } else {
            insertT(h->right, x);
            rotL(h);
        }
    }
    link minValueNode(link &h) {
        link t = h;
        while(t != nullptr && t->left != nullptr) {
            t = t->left;
        }
        return t;
    }
     void removeR(link &h, Key x) {
        if(h == nullptr)    return;

        if(x < h->item.key()) {
            removeR(h->left, x);
        } else if(x > h->item.key()) {
            removeR(h->right, x);
        } else {    
            // h points to node to be deleted
            if(h->left == nullptr && h->right == nullptr) {
                // node has no children => delete this
                delete h;
                h = nullptr;
                return;
            }   
            else if(h->left == nullptr) {
                // node has no left child => copy right link and delete this
                link t = h;
                h = h->right;
                delete t;
                return;
            } else if(h->right == nullptr) {
                // node has no right child => copy left link and delete this
                link t = h;
                h = h->left;
                delete t;
                return;
            }
            // node with 2 children => find minimum from right subtree
            // (note that node can not have left child)
            // copy the value to the root and delete the source of copying 
            link t = minValueNode(h->right);
            h->item.copyItem(t->item);
            removeR(h->right, t->item.key());
        }
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
    void insertTop(Item x) {
        return insertT(root, x);
    }
    void remove(Key x) {
        removeR(root, x);
    }
    void traverse_inorder(link t, void (*pfVisit)(link node)) {
        if(t == nullptr)    return;

        traverse_inorder(t->left, pfVisit);
        (*pfVisit)(t);
        traverse_inorder(t->right, pfVisit);
    }
    void traverse_preorder(link t, void (*pfVisit)(link node)) {
        if(t == nullptr)    return;

        (*pfVisit)(t);
        traverse_preorder(t->left, pfVisit);
        traverse_preorder(t->right, pfVisit);
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
        Item(10,8.0),
        Item(46,9.0),
        Item(43,10.0),
        Item(45,11.0),
        Item(55,12.0),
        Item(57,13.0),
        Item(56,14.0),
        Item(47,15.0),
        Item(69,16.0),
        Item(58,17.0),
        Item(40,18.0),
    };

    int i;
    Item item;
    BinaryTree bt;
    BinaryTree btt;

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

    // binary tree top
    for(i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
        btt.insertTop(data[i]);
    }
    cout << "TOP: Insert done ... traversal..." << endl;
    btt.traverse_inorder(btt.getRoot(), printItem);
    cout << "Insert done ... searching..." << endl;

    cout << "Pre-order traversal..." << endl;
    btt.traverse_preorder(btt.getRoot(), printItem);

    for(i = sizeof(data)/sizeof(data[0])-1; i>= 0; i--) {
        Item t = btt.search(data[i].key());
        cout << "searching for " << data[i].key() << " result: ";
        cout << t.key() <<" with value "<< t.value() << endl;
    }
    // Testing remove
    btt.remove(47);
    cout << "Pre-order traversal after remove..." << endl;
    btt.traverse_preorder(btt.getRoot(), printItem);
    return 0;
}

