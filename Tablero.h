
#ifndef TABLERO_H
#define TABLERO_H

#include <bits/stdc++.h>

using namespace std;

class Tablero {
    private: 
        int matriz[3][3];
        int filavacia; 
        int columnavacia; 

        void actposicionvacia();
    
    public: 
        Tablero();
        Tablero(const int inicial[3][3]);

        void mostrarconsola();
        bool moverficha(int fila, int columna);
        bool esmeta(const int meta[3][3]) const;
        int getvalor(int fila, int columna) const;
};

#endif