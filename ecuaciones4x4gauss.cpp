#include "ecuaciones4x4gauss.h"

#include <iostream>

using namespace std;

Ecuaciones4x4Gauss::Ecuaciones4x4Gauss()
{
    // nada que hacer aquí
}

Ecuaciones4x4Gauss::~Ecuaciones4x4Gauss()
{
    // nada que hacer aquí
}

EcuacionGaussBase &Ecuaciones4x4Gauss::operator[](int indice)
{
    return m_sistema[indice];
}

void Ecuaciones4x4Gauss::show() const
{
    m_sistema[0].show();
    cout << endl;
    for (int i = 1; i < NECUACIONES; ++i)
    {
        m_sistema[i].show();
        cout << endl;
    }
}

const EcuacionGaussBase &Ecuaciones4x4Gauss::operator[](int indice) const
{
    return m_sistema[indice];
}
