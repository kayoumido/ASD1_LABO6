#include <iostream>
#include "Mouchard.h"
#include "Pile.h"

using namespace std;

int main() {

/*    // 1st code check
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

    cout << endl << endl;

    // 3rd code check
    {
        Int* p = (Int*) ::operator new(4 * sizeof(Int));

        new(p)       Int();
        new(p + 1)   Int(5);
        new(p + 2)   Int(*(p + 1));
        new(p + 3)   Int(move(*(p + 2)));

              *(p) = *(p + 1);
              *(p) = move(*(p + 3));

        (p + 3)->~Int();
        (p + 2)->~Int();
        (p + 1)->~Int();
            (p)->~Int();

        ::operator delete(p);
    }*/

    cout << "Test constructeur \n";
    Pile<Int> pile1(6);
    cout << endl << endl;

    cout << "Test empiler \n";
    for(int i = 0; i < 4; ++i)
        pile1.empiler(Int(i));
    cout << endl << endl;

    cout << "Contenu pile \n";
    cout << pile1 << endl << endl;
    {
        cout << "Test constructeur de copie \n";
        Pile<Int> pile2 = pile1;
        cout << endl << endl;

        cout << "Contenu pile copiée\n";
        cout << pile2 << endl << endl;

        cout << "Test destructeur \n";
    } // test destruction de pile2
    cout << endl << endl;

    cout << "Tests sommet et depiler \n";
    for(int i = 0; i < 2; ++i) {
        cout << pile1.sommet() << " ";
        pile1.depiler();
    }
    cout << endl << endl;

    cout << "Contenu pile dépilée\n";
    cout << pile1 << endl << endl;  // test contenu pile

    cout << "Test destructeur 2\n";

    return 0;
}
