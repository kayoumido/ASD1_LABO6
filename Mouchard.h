#ifndef LABO6_MOUCHARD_H
#define LABO6_MOUCHARD_H

#include <ostream>

class Int;

std::ostream& operator<<( std::ostream& os, const Int& i);

class Int {
    friend std::ostream& operator<<( std::ostream& os, const Int& i);
    int data;
    int checkConstruction;
    static const int OK = 20180413;
public:
    Int();
    ~Int();
    Int(int d);
    Int(const Int& other);
    Int(Int&& other);
    Int& operator= (const Int& other);
    Int& operator= (Int&& other);
};

#endif //LABO6_MOUCHARD_H