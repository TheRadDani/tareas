#include "ecuaciongaussbase.h"

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

double &EcuacionGaussBase::operator[](int indice)
{
    return m_coeficientes[indice];
}
