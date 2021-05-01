#include "ecuaciones4x4gauss.h"

#include <iostream>

using namespace std;

int main()
{
    // sistema de ecuaciones de 4x4
    Ecuaciones4x4Gauss S;

    // asignamos ecuaciones
    S[0] = EcuacionGaussBase(2.0, 2.0, -2.0, 1.0, -12.0);
    S[1] = EcuacionGaussBase(5.0, 1.0, 3.0, -1.0, 16.0);
    S[2] = EcuacionGaussBase(3.0, 2.0, -4.0, 3.0, -25.0);
    S[3] = EcuacionGaussBase(1.0, 1.0, 1.0, 1.0, -2.0);

    S.show();

    return 0;
}


/*
//===============================================
//Archivo: main_double.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
//===============================================
#include <stdio.h>
#include <iostream>
using namespace std;
#include "gauss_4_incognitas.h"

void view(const char *msg,_ecuaciones4x4_gauss &p)
{
  cout << msg << endl;
  for(int i=0;i<ECUACIONES;i++)
  {
    for (int j=0;j< ECUSIZE;j++)
      printf("% 7.2f\t",p[i][j]);
    cout << endl;
  }
}//__________________________________________________


int main(void)
{


  double ecuaciones1[4][5]= {{2.0,     2.0,      -2.0,      1.0,     -12.0},
                           {5.0,     1.0,       3.0,     -1.0,      16.0},
                           {3.0,     2.0,      -4.0,      3.0,     -25.0},
                           {1.0,     1.0,       1.0,      1.0,      -2.0}};

  double ecuaciones2[4][5]= {{2.0,     2.0,      -2.0,      1.0,     -12.0},
                           {5.0,     1.0,       3.0,     -1.0,      16.0},
                           {3.0,     2.0,      -4.0,      3.0,     -25.0},
                           {1.0,     1.0,      -1.0,      0.5,      -6.0}};
  _ecuaciones4x4_gauss syslin1, syslin2;

  //LI
  //++++
  for(int i=0;i<ECUACIONES;i++)
    for (int j=0;j< ECUSIZE;j++)
       syslin1[i][j]=ecuaciones1[i][j];

  //LD
  //++++
  for(int i=0;i<ECUACIONES;i++)
    for (int j=0;j< ECUSIZE;j++)
       syslin2[i][j]=ecuaciones2[i][j];

  cout << "Sistema de ecuaciones Gauss-Jordan" << endl;
  cout << "Habilitar DEBUG en define.h para ver detalle pausado" << endl;

  view("Inicial:",syslin1);
  if (!syslin1.resolve()) cout << "Sistema de Ecuaciones LD..." << endl;
  view("Solucion:",syslin1);
  view("Inicial:",syslin2);
  if (!syslin2.resolve()) cout << "Sistema de Ecuaciones LD..." << endl;
  view("Solucion:",syslin2);
}//__________________________________________________

*/
