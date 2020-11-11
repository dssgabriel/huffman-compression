#ifndef ARBREB_HPP
#define ARBREB_HPP

#include "Sommet.hpp"

class ArbreB
{
private:
    Sommet* m_Root;

public:
    ArbreB();
    ArbreB(const char& data, const double& freq);
    ArbreB(const Sommet& node);
    ArbreB(const ArbreB& other);
    ~ArbreB();

    ArbreB& operator=(const ArbreB& other);

    Sommet& get_m_Root();

    void insert(const Sommet& node, const double& freq);
    bool search(const double& freq);
    ArbreB& remove(const double& freq);

    ArbreB fuse(const ArbreB& other);
};

#endif
