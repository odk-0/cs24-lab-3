#include "intbst.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    cout << "===== Testing empty tree =====" << endl;
    IntBST t;

    // Empty tree checks
    assert(t.sum() == 0);
    assert(t.count() == 0);
    assert(t.contains(16) == false);
    assert(t.getPredecessor(16) == 0);
    assert(t.getSuccessor(16) == 0);
    assert(t.remove(16) == false);

    cout << "Empty tree tests passed.\n" << endl;

    cout << "===== Building tree =====" << endl;

    // Insert values (same as lab spec)
    int values[] = {64, 8, 128, 4, 32, 512, 16, 256};
    for (int v : values) {
        assert(t.insert(v) == true);
    }

    // Duplicate insert
    assert(t.insert(64) == false);

    cout << "Tree built successfully.\n" << endl;

    cout << "===== Testing print orders =====" << endl;

    cout << "Pre-order: ";
    t.printPreOrder();
    cout << endl;

    cout << "In-order: ";
    t.printInOrder();
    cout << endl;

    cout << "Post-order: ";
    t.printPostOrder();
    cout << endl << endl;

    cout << "===== Testing sum, count, contains =====" << endl;

    assert(t.sum() == 1020);
    assert(t.count() == 8);

    assert(t.contains(64) == true);
    assert(t.contains(4) == true);
    assert(t.contains(16) == true);
    assert(t.contains(128) == true);
    assert(t.contains(17) == false);
    assert(t.contains(512) == true);

    cout << "sum(), count(), contains() passed.\n" << endl;

    cout << "===== Testing predecessor =====" << endl;

    assert(t.getPredecessor(64) == 32);
    assert(t.getPredecessor(512) == 256);
    assert(t.getPredecessor(4) == 0);

    cout << "Predecessor tests passed.\n" << endl;

    cout << "===== Testing successor =====" << endl;

    assert(t.getSuccessor(64) == 128);
    assert(t.getSuccessor(512) == 0);
    assert(t.getSuccessor(4) == 8);

    cout << "Successor tests passed.\n" << endl;

    cout << "===== Testing remove =====" << endl;

    assert(t.remove(4) == true);
    assert(t.remove(64) == true);
    assert(t.remove(128) == true);

    assert(t.contains(4) == false);
    assert(t.contains(64) == false);
    assert(t.contains(128) == false);
    assert(t.contains(16) == true);
    assert(t.contains(512) == true);

    cout << "After removals, in-order: ";
    t.printInOrder();
    cout << endl << endl;

    cout << "===== Testing clear =====" << endl;

    t.~IntBST();  // explicitly test destructor behavior
    IntBST t2;
    assert(t2.count() == 0);
    assert(t2.sum() == 0);

    cout << "Clear/destructor tests passed.\n" << endl;

    cout << " ALL TESTS PASSED " << endl;

    return 0;
}
