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

bool Ecuaciones4x4Gauss::sort()
{
    // contador de intentos
    int counter = 0;

    // límite de intentos
    const int limit = 1000;

    // ciclo para intentar mantener coherencia entre los coeficientes de las ecuaciones
    while (m_sistema[0][0] == 0.0
           && m_sistema[1][1] == 0.0
           && m_sistema[2][2] == 0.0
           && m_sistema[3][3] == 0.0
           && counter <= limit)
    {
        m_sistema[0].check(0, this, 0); // verifica a00
        m_sistema[1].check(1, this, 1); // verifica a11
        m_sistema[2].check(2, this, 2); // verifica a22
        m_sistema[3].check(3, this, 3); // verifica a33
        ++counter; // incrementamos contador de intentos
    }

    // si todos los coeficientes indicados son diferente de cero, todo salió bien
    return m_sistema[0][0] != 0.0
           && m_sistema[1][1] != 0.0
           && m_sistema[2][2] != 0.0
           && m_sistema[3][3] != 0.0;
}

void Ecuaciones4x4Gauss::swap(int ecuIndexA, int ecuIndexB)
{
    m_sistema[ecuIndexA].swap(m_sistema[ecuIndexB]);
}

const EcuacionGaussBase &Ecuaciones4x4Gauss::operator[](int indice) const
{
    return m_sistema[indice];
}
