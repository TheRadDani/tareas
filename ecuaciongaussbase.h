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
    /** constructor por default */
    explicit EcuacionGaussBase();

    /** constructor */
    explicit EcuacionGaussBase(double a0, //!< coeficiente de variable 1
                                 double a1, //!< coeficiente de variable 2
                                 double a2, //!< coeficiente de variable 3
                                 double a3, //!< coeficiente de variable 4
                                 double a4 //!< termino independiente
    );

    /** destructor */
    virtual ~EcuacionGaussBase();

    /** operador para acceder a posición (su valor) */
    double operator[](int indice) const;

    /** operator para acceder a posición (su referencia en memoria) */
    double &operator[](int indice);

    void show() const;
private:
    double m_coeficientes[NCOEFICIENTES]; //!< array de coeficientes (tamaño 5)
};

#endif // ECUACIONGAUSSBASE_H
