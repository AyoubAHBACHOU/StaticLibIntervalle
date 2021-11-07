#pragma once
#include "Tableau.h"
#include <iostream>
using namespace Math;
class TableauBorne :
    private Tableau
{
private:
    float Binf;
    float Bsup;
public:
    TableauBorne(int nbelm = 1, float bI = 0, float bS = 0);
    float& operator[](int indice) = delete;
    void operator()(int indice, float newEm);
    void afficher()const;
};

