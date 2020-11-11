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
    Sommet(const char& data, const double& freq);
    Sommet(const Sommet& other);

    Sommet& operator=(const Sommet& other);

    char& get_m_Data();
    double& get_m_Freq();
    void set_m_Data(const char& data);
    void set_m_Freq(const double& freq);
};

#endif
