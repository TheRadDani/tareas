#include "ecuaciones4x4gauss.h"

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

const EcuacionGaussBase &Ecuaciones4x4Gauss::operator[](int indice) const
{
    return m_sistema[indice];
}

