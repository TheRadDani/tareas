#include "ecuaciones4x4gauss.h"

#include <vector>
#include <algorithm>
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
    int counter = 0; // contador de intentos
    int zeroCounter = 0; // contador de ceros
    static const int limit = 1000; // límite de intentos
    vector<int> aIndices; // indices de coeficientes significativos (basado en la cantidad de ecuaciones)

    // obtención de índices significativos
    for (int i = 0; i < NECUACIONES; ++i)
    {
        aIndices.push_back(i);
    }

    // ciclo para intentar evitar ceros en los coeficientes significativos de las ecuaciones
    while (counter <= limit)
    {
        // ¿cuántos ceros se pudieron encontrar en las posiciones significativas de las ecuaciones en total?
        zeroCounter = 0;
        std::for_each(aIndices.begin(), aIndices.end(), [&](int indice)
        {
            if (m_sistema[indice][indice] == 0.0)
            {
                ++zeroCounter;
            }
        });

        // no encontramos ceros en posiciones significativas, hemos terminado el ciclo
        if (zeroCounter == 0)
        {
            break;
        }
        else
        {
            // hacemos intento por intercambiar ecuaciones evitando tener cero en la posición indicada
            for (int i = 0; i < NECUACIONES; ++i)
            {
                m_sistema[i].check(i, this, i);
            }
            ++counter; // un intento más se ha hecho
        }
    }
    return zeroCounter == 0;
}

void Ecuaciones4x4Gauss::swap(int ecuIndexA, int ecuIndexB)
{
    m_sistema[ecuIndexA].swap(m_sistema[ecuIndexB]);
}

const EcuacionGaussBase &Ecuaciones4x4Gauss::operator[](int indice) const
{
    return m_sistema[indice];
}
