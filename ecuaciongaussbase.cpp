#include "ecuaciongaussbase.h"

EcuacionGaussBase::EcuacionGaussBase()
{
    for (int i = 0; i < NCOEFICIENTES; ++i)
    {
        m_coeficientes[i] = 0.0;
    }
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

double &EcuacionGaussBase::operator[](int indice)
{
    return m_coeficientes[indice];
}
