/**
 * @author Daniel Ferreto
 * @file ecuaciongaussbase.h
 * @date 1 de mayo del 2021
 * @brief ecuación base para formar sistemas de ecuaciones
 */

#ifndef ECUACIONGAUSSBASE_H
#define ECUACIONGAUSSBASE_H

/** cantidad de coeficientes de la ecuación */
#define NCOEFICIENTES 5

/** ecuación base para formar sistemas de ecuaciones */
class EcuacionGaussBase
{
public:
    /** constructor */
    explicit EcuacionGaussBase();

    /** destructor */
    virtual ~EcuacionGaussBase();

    /** operador para acceder a posición (su valor) */
    double operator[](int indice) const;

    /** operator para acceder a posición (su referencia en memoria) */
    double &operator[](int indice);
private:
    double m_coeficientes[NCOEFICIENTES]; //!< array de coeficientes (tamaño 5)
};

#endif // ECUACIONGAUSSBASE_H
