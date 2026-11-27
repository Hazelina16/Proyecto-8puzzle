
#include "Tablero.h"
#include <bits/stdc++.h>

using namespace std;

int main(){

    srand(static_cast<unsigned int>(time(0))); 

    Tablero t; 

    cout << "NIVEL 1 mezclado"<< endl; 
    t.mezclarnivel(1);
    t.mostrarconsola();

    cout << "NIVEL 2 mezclado"<< endl; 
    t.mezclarnivel(2);
    t.mostrarconsola();

    return 0; 
}