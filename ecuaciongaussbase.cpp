#include "ecuaciongaussbase.h"
#include "ecuaciones4x4gauss.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

EcuacionGaussBase::EcuacionGaussBase(const EcuacionGaussBase &other)
{
    *this = other;
}

void EcuacionGaussBase::operator=(const EcuacionGaussBase &other)
{
    for (int i = 0; i < NCOEFICIENTES; ++i)
    {
        m_coeficientes[i] = other.m_coeficientes[i];
    }
}

EcuacionGaussBase::EcuacionGaussBase()
{
    for (int i = 0; i < NCOEFICIENTES; ++i)
    {
        m_coeficientes[i] = 0.0;
    }
}

EcuacionGaussBase::EcuacionGaussBase(double a0, double a1, double a2, double a3, double a4)
{
    m_coeficientes[0] = a0;
    m_coeficientes[1] = a1;
    m_coeficientes[2] = a2;
    m_coeficientes[3] = a3;
    m_coeficientes[4] = a4;
}

EcuacionGaussBase::~EcuacionGaussBase()
{
    // nada que hacer aquí
}

double EcuacionGaussBase::operator[](int indice) const
{
    if (indice >= 0 && indice <= NCOEFICIENTES-1)
    {
        return m_coeficientes[indice];
    }
    else
    {
        return 0.0;
    }
}

void EcuacionGaussBase::show() const
{
    if (m_coeficientes[0] >= 0)
    {
        printf(" ");
    }
    printf("%4.3f", m_coeficientes[0]);
    for (int i = 1; i < NCOEFICIENTES; ++i)
    {
        if (m_coeficientes[i] >= 0)
        {
            printf(" ");
        }
        printf(" %4.3f", m_coeficientes[i]);
    }
}

void EcuacionGaussBase::swap(EcuacionGaussBase &other)
{
    EcuacionGaussBase copy = *this;
    *this = other;
    other = copy;
}

/*
 * cIndex: índice del coeficiente que queremos verificar si es 0
 * S: sistema de ecuaciones de 4x4
 * eIndex: índice de la ecuación que estamos verificando
 */
void EcuacionGaussBase::check(int cIndex, Ecuaciones4x4Gauss *S, int eIndex)
{
    // el coeficiente referenciado es cero,
    // tenemos que hacer swap con alguna otra ecuación
    // para revertir esta situación
    if (m_coeficientes[cIndex] == 0)
    {
        // guardamos los índices de las otras ecuaciones
        vector<int> eIndices;
        for (int i = 0; i < NECUACIONES; ++i)
        {
            if (i != eIndex)
            {
                eIndices.push_back(i);
            }
        }

        // recorremos las otras ecuaciones para encontrar una que sirva para hacer intercambio
        std::for_each(eIndices.begin(), eIndices.end(), [&](int i)
        {
            if ((*S)[i][cIndex] != 0)
            {
                // hemos encontrado una ecuación que no tiene cero en su
                // coeficiente indicado, entonces hacemos un intercambio
                (*S)[i].swap(*this);
                return;
            }
        });
    }
}

double &EcuacionGaussBase::operator[](int indice)
{
    return m_coeficientes[indice];
}
