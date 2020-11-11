#ifndef SOMMET_HPP
#define SOMMET_HPP

class Sommet
{
private:
    char m_Data;
    double m_Freq;
    Sommet* m_Left;
    Sommet* m_Right;

public:
    Sommet();
    Sommet(char& data, double& freq);
    Sommet(const Sommet& other);

    Sommet& operator=(const Sommet& other);
};

#endif
