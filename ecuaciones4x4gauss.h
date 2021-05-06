/**
 * @author Daniel Ferreto
 * @file ecuaciones4x4gauss.h
 * @date 1 de mayo del 2021
 * @brief sistema de ecuaciones de 4x4 por el método de Gauss-Jordan
 */

#ifndef ECUACIONES4X4GAUSS_H
#define ECUACIONES4X4GAUSS_H

#include "ecuaciongaussbase.h"

/** cantidad de ecuaciones del sistema de ecuaciones */
#define NECUACIONES 4

/** sistema de ecuaciones de 4x4 por el método de Gauss-Jordan */
class Ecuaciones4x4Gauss
{
public:
    /** constructor */
    Ecuaciones4x4Gauss();

    /** destructor */
    virtual ~Ecuaciones4x4Gauss();

    /** operador para acceder a ecuación (referencia) */
    EcuacionGaussBase &operator[](int indice);

    /** operator para acceder a ecuación */
    const EcuacionGaussBase &operator[](int indice) const;

    /** imprime en pantalla el sistema de ecuaciones */
    void show() const;

    /**
     * ordena las ecuaciones de forma que:
     * a00, a11, a22, a33 sean diferentes de 0.0,
     * y hay que definir un límite de intentos
     */
    bool sort(int limit = 1000);

    /** soluciona sistema de ecuaciones */
    void solve();
private:
    /** intercambia dos ecuaciones mediante su índice */
    void swap(int ecuIndexA, int ecuIndexB);

    EcuacionGaussBase m_sistema[NECUACIONES]; //!< sistema de 4x4
};

#endif // ECUACIONES4X4GAUSS_H
