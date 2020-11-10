#ifndef ARBREB_HPP
#define ARBREB_HPP

#include "Sommet.hpp"

class ArbreB {
private:
    Sommet* root;

public:
    ArbreB();
    ArbreB(const ArbreB& a);
    ~ArbreB();

    void insert(Sommet& s);
    ArbreB& remove(Sommet& s);
    Sommet& search(int value);
    ArbreB& operator=(const ArbreB& a);
    ArbreB operator+=(const ArbreB& a);
};

#endif
