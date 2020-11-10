#ifndef SOMMET_HPP
#define SOMMET_HPP

#include <iostream>

class Sommet {
private:
    int tag;
    Sommet* left;
    Sommet* right;

public:
    Sommet(int tag): tag(tag), left(nullptr), right(nullptr) {}
};

#endif
