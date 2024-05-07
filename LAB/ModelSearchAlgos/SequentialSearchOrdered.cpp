// SequentialSearchOrdered.cpp

#include <iostream>
#include <stdlib.h>

#include "Item.h"

using namespace std;

static int compareCount = 0;
static int swapCount = 0;

template <class Item>
void dbgOutput(Item a, int N) {
    for(int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <class Item>
void itemSwap(Item &a, Item &b) {
    Item t = a; a = b; b = t;
    swapCount++;
}

template <class Item>
void compareAndSwap(Item &a, Item &b) {
    compareCount++;
    if(b < a)   itemSwap(a,b);
}

// array based symbol table ordered
template <class Item, class Key>
class ST {
  private:
    Item nullItem, *st;
    int N;
  public:
    ST(int maxN) {
        st = new Item[maxN+1];
        N = 0;
    }
    int count() {
        return N;
    }
    void insert(Item x) {
        int i = N++;
        Key v = x.key();
        while(i > 0 && v < st[i-1].key()) {
            st[i] = st[i-1];
            i--;
        }
        st[i] = x;
    }
    Item search(Key v) {
        int i;
        for(i = 0; i < N; i++) {
            if(!(st[i].key() < v)) break;
        }
        if(v == st[i].key()) return st[i];
        return nullItem;    // item with keyval == maxkey
    }
    int remove(Key v) {
        // ToDo: implement
        return 0;
    }
    Item select(int k) {
        return st[k];
    }
    void show(ostream &os) {
        int i = 0;
        while(i < N) st[i++].show(os);
    }
};


int main(int argc, char *argv[]) {
    int N;
    int maxN = 10;
    int sw = 1;
    if(argc == 3) {
        maxN = atoi(argv[1]);
        sw = atoi(argv[2]);
    }

    ST<Item, Key> st(maxN);
    Key keystore[maxN];

    for(N = 0; N < maxN; N++) keystore[N] = -1;

    for(N = 0; N < maxN; N++) {
        Item v;
        if(sw)  v.rand();
        else if(!v.scan())  break;

        if(!(st.search(v.key())).isNull()) {
            cout << "key "<< v.key() << " already found ... skipping insert (at index ";
            cout << N << ")" << endl;
            continue;
        }
        st.insert(v);
        keystore[N] = v.key();
    }
    st.show(cout);
    cout << endl;
    cout << N << " keys" << endl;
    cout << st.count() << " distinct keys" << endl;

    cout << "searching items" << endl;
    for(N = 0; N < maxN; N++) {
        if(keystore[N] >= 0) {
            cout << N <<" key: " << keystore[N];
            cout << " search returns key: " << st.search(keystore[N]).key();
            cout << " and value: " << st.search(keystore[N]).value() << endl;
        } else {
            cout << "skipping item " << N << endl;
        }
    }
    return 0;
}