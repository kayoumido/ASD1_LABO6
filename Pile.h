#ifndef Pile_hpp
#define Pile_hpp

#include <ostream>

// Forward declarations
template<typename T>
class Pile;

template<typename T>
std::ostream &operator<<(std::ostream &os,
                         const Pile<T> &p);

class PileOverflowException : public std::exception {
};

// Type Pile
template<typename T>
class Pile {
    friend std::ostream &operator<<<>(std::ostream &os,
                                      const Pile<T> &p);

public:
    using value_type = T;
    using pointer = value_type *;
    using reference = value_type &;
    using const_reference = const value_type &;

private:
    pointer donnees;
    size_t taille;
    const size_t CAPACITE;

public:
    explicit Pile(size_t _capacite) : CAPACITE(_capacite), donnees((T *) ::operator new(_capacite * sizeof(T))),
                                      taille(0) {}

    ~Pile() {

        for (size_t i = 0; i < this->taille; ++i)
            (this->donnees + i)->~T();

        ::operator delete(this->donnees);
    }

    Pile(const Pile &other) : CAPACITE(other.CAPACITE), donnees(nullptr), taille(0) {

        this->donnees = (T *) ::operator new(this->CAPACITE * sizeof(T));

        for (size_t i = 0; i < other.taille; ++i) {
            new(this->donnees + i) T(*(other.donnees + i));
            ++this->taille;
        }
    }

    void empiler(const value_type &v) {
        if (this->taille == this->CAPACITE) throw PileOverflowException();

        new(donnees + taille) T(v);
        ++taille;
    }

    void depiler() {
        --taille;
        (this->donnees + taille)->~T();
    }

    const_reference sommet() const {
        return *(donnees + (taille - 1));
    }

};

// ne pas modifier
template<typename T>
std::ostream &operator<<(std::ostream &os,
                         const Pile<T> &p) {
    os << "Pile(" << p.taille << "/" << p.CAPACITE << "): ";
    size_t i = p.taille;
    while (i > 0)
        os << p.donnees[--i] << " ";
    return os;
}

#endif /* Pile_hpp */