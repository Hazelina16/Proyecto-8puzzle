
#include "Tablero.h"
#include <bits/stdc++.h> 

using namespace std;

Tablero::Tablero(){
    int base[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,0}};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            matriz[i][j] = base[i][j];
        }
    }
    actposicionvacia();

}

Tablero::Tablero(const int inicial[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            matriz[i][j] = inicial[i][j];
        }
    }
    actposicionvacia();
}

void Tablero::actposicionvacia(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matriz[i][j] == 0){
                filavacia = i;
                columnavacia = j;
                return;
            }
        }
    }
}

void Tablero::mostrarconsola(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matriz[i][j] == 0){
                cout << "[ ]";
            } else {
                cout << "[" << matriz[i][j] << "] ";
            }
        }
        cout << "\n";
    }
}

bool Tablero::moverficha(int fila, int columna){
    if(fila<0 || fila>=3 || columna<0 || columna>=3){
        return false; 
    }
    int distmanhattan = abs(fila - filavacia) + abs(columna - columnavacia); //uso "abs" para sacar el valor absoluto de la resta
    if(distmanhattan != 1){
        return false; 
    }
    matriz[filavacia][columnavacia] = matriz[fila][columna];
    matriz[fila][columna] = 0;
    filavacia = fila; 
    columnavacia = columna;
    return true;
}

bool Tablero::esmeta(const int meta[3][3]) const{
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matriz[i][j] != meta[i][j]){
                return false;
            }
        }
    }
    return true;
}

int Tablero::getvalor(int fila, int columna) const{
    if(fila<0 || fila>=3 || columna<0 || columna>=3){
        return -1; 
    }
    return matriz[fila][columna];
}

void Tablero::mezclarnivel(int nivel){

    int minmov; 
    int maxmov; 
    int totalmov;

    //posibles direcciones 
    //arriba, abajo, izq, derecha
    int dfila[4] = {-1, 1, 0, 0}; 
    int dcolumna[4] = {0, 0, -1, 1}; 

    int ultimafila =-1; 
    int ultimacolumna =-1; 
    int movrealizados = 0; 

    //reinicio el tablero a la posicion 'base'
    int base[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,0}};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            matriz[i][j] = base[i][j];
        }
    }
    actposicionvacia();

    //minimos y maximos movimientos para el pimer nivel
    minmov = 4; 
    maxmov = 8; 

    //minimos y maximos movimientos para el segundo nivel
    if(nivel == 2){
        minmov = 15; 
        maxmov = 25; 
    }

    totalmov = minmov + (rand()%(maxmov - minmov + 1));

    while (movrealizados < totalmov){
        int direccion = rand()%4; 
        int filacan = filavacia + dfila[direccion]; 
        int columnacan = columnavacia + dcolumna[direccion]; 

        if(filacan == ultimafila && columnacan == ultimacolumna){
            continue; 
        }

        int previafila = filavacia; 
        int previacolumna = columnavacia; 

        if(moverficha(filacan, columnacan)){
            ultimafila = previafila; 
            ultimacolumna = previacolumna; 
            movrealizados++;
        }
    }

}