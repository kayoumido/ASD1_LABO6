#include <iostream>
#include "Mouchard.h"

using namespace std;

int main() {

    // 1st code check
    {
        Int p1;             // DC
        Int p2 = 5;         // IC
        Int p3 = p2;        // CC
        Int p4 = move(p3);  // MC
            p1 = p2;        // C=
            p1 = move(p4);  // M=

        // result : DC IC(5) CC(5) MC(5) C=(5) M=(5) D(-2) D(-1) D(5) D(5)
    }

    cout << endl << endl;

    // 2nd code check
    {
        Int* p1  = new Int();
        Int* p2  = new Int(5);
        Int* p3  = new Int(*p2);
        Int* p4  = new Int(move(*p3));
            *p1  = *p2;
            *p1  = move(*p4);

        delete p4;
        delete p3;
        delete p2;
        delete p1;

        // result : same as 1st
    }

    return 0;
}