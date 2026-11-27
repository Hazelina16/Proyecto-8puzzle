
#include "Tablero.h"
#include <bits/stdc++.h>

using namespace std;

int main(){

    srand(static_cast<unsigned int>(time(0))); //evita advertencias del compilador

    Tablero resuelto; 

    cout << "TABLERO RESUELTO"<< endl; 
    resuelto.mostrarconsola();

    cout << "DISTANCIA MANHATTAN:"<< resuelto.distanciaman() << endl; 

    Tablero mezclado;
    mezclado.mezclarnivel(1);
    cout << "TABLERO MEZCLADO"<< endl;
    mezclado.mostrarconsola();
    cout << "DISTANCIA MANHATTAN:"<< mezclado.distanciaman() << endl;
    return 0; 
}