#include <iostream>
#include "Mouchard.h"

using namespace std;

int main() {

    // DC IC(5) CC(5) MC(5) C=(5) M=(5) D(-2) D(-1) D(5) D(5)
    // DC IC(5) CC(5) MC(5) C=(5) M=(5) D(-2) D(-1) D(5) D(5)

    Int p1;             // DC
    Int p2 = 5;         // IC
    Int p3 = p2;        // CC
    Int p4 = move(p3);  // MC
    p1 = p2;            // C=
    p1 = move(p4);      // M=

    return 0;
}