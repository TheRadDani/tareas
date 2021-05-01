/**
 * @author
 * @file ecuaciones4x4gauss.h
 * @date 1 de mayo del 2021
 * @brief sistema de ecuaciones de 4x4 por el método de Gauss-Jordan
 */


#ifndef ECUACIONES4X4GAUSS_H
#define ECUACIONES4X4GAUSS_H

#include "ecuaciongaussbase.h"

#define NECUACIONES 4

/** sistema de ecuaciones de 4x4 por el método de Gauss-Jordan */
class Ecuaciones4x4Gauss
{
public:
    /** constructor */
    explicit Ecuaciones4x4Gauss();

    /** destructor */
    virtual ~Ecuaciones4x4Gauss();
private:
    EcuacionGaussBase m_sistema[NECUACIONES]; //!< sistema de 4x4
};

#endif // ECUACIONES4X4GAUSS_H
