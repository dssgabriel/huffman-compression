#ifndef ARBREB_HPP
#define ARBREB_HPP

#include "Sommet.hpp"

class ArbreB
{
private:
    Sommet* m_Root;

public:
    ArbreB();
    ArbreB(Sommet& sommet);
    ArbreB(const ArbreB& other);
    ~ArbreB();
};

#endif
