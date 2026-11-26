
#include "Tablero.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    Tablero t; 
    t.mostrarconsola();
    cout << "Prueba de movimiento de ficha" << endl;
    if(t.moverficha(2,1)){
        t.mostrarconsola();
    }
    return 0; 
}