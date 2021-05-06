#include "ecuaciones4x4gauss.h"

#include <iostream>

using namespace std;

int main()
{
    // sistema de ecuaciones de 4x4
    Ecuaciones4x4Gauss S;

    // asignamos ecuaciones
    S[0] = EcuacionGaussBase(1.0, -2.0, 2.0, -3.0, 15.0);
    S[1] = EcuacionGaussBase(3.0, 4.0, -1.0, 1.0, -6.0);
    S[2] = EcuacionGaussBase(2.0, -3.0, 2.0, -1.0, 17.0);
    S[3] = EcuacionGaussBase(1.0, 1.0, -3.0, -2.0, -7.0);

    // imprime ecuaciones iniciales
    cout << "ecuaciones iniciales:" << endl;
    S.show();

    // ordena las ecuaciones de manera conveniente
    cout << "sort: " << std::boolalpha << S.sort() << endl;

    // imprime ecuaciones ya ordenadas
    cout << "ecuaciones ordenadas:" << endl;
    S.show();

    // soluciona sistema de ecuaciones
    S.solve();
    cout << "solucion:" << endl;
    S.show();

    return 0;
}
