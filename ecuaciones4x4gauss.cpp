#include "ecuaciones4x4gauss.h"

#include <vector>
#include <iostream>
#include <algorithm>

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

bool Ecuaciones4x4Gauss::sort(int limit /*<-- límite de intetos, por default = 1000 */)
{
    int counter = 0; // contador de intentos
    int zeroCounter = 0; // contador de ceros
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

void Ecuaciones4x4Gauss::solve()
{
    for (int i = 0; i < NECUACIONES; ++i)
    {
        solve(i);
    }
}

void Ecuaciones4x4Gauss::swap(int ecuIndexA, int ecuIndexB)
{
    m_sistema[ecuIndexA].swap(m_sistema[ecuIndexB]);
}

const EcuacionGaussBase &Ecuaciones4x4Gauss::operator[](int indice) const
{
    return m_sistema[indice];
}

void Ecuaciones4x4Gauss::solve(int i)
{
    // deben dividir cada coeficiente de toda la ecuación "i"
    // por el valor a[i,i] de manera que el término a[i,i] sea = 1
    for (int c = 0; c < NCOEFICIENTES; ++c)
    {
        m_sistema[i][c] /= m_sistema[i][i];
    }

    // deben recorrer todas las ecuaciones desde k=0 hasta k=3
    // evitando k=i
    for (int k = 0; k < NECUACIONES; ++k)
    {
        if (k != i)
        {
            for (int c = 0; c < NCOEFICIENTES; ++c)
            {
                // multiplicar cada término de la ecuación "i"
                // por -a[k,i] de manera que a[i,i] es el negativo de
                // a[k,i]
                m_sistema[i][c] *= -m_sistema[k][i];

                // sumar cada término de la ecuación "i" a cada término
                // de la ecuación "k"
                m_sistema[i][c] += m_sistema[k][c];
            }
        }
    }

    for (int c = 0; c < NCOEFICIENTES; ++c)
    {
        m_sistema[i][c] /= m_sistema[i][i];
    }
}
