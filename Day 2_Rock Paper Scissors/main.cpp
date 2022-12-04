#include "parte1.h"

int sumaParte2(string &a, string &b){
    int suma;
    int valor;
    switch (b[0]) {
        case 'X':
            suma += 0;
            valor = 0;
            break;
        case 'Y':
            suma += 3;
            valor = 3;
            break;
        case 'Z':
            suma += 6;
            valor = 6;
            break;
        default:
            break;
    }
     suma += sumaParcial(a, valor);
    return suma;
}

int main(){
    int     sumaTotal = 0;
    string    op;
    string    rpta;

    //parte1("data.txt"); Proporciona la primera parte del desafio

    ifstream data("data.txt");
    while(!data.eof()){
        data >> op >> rpta;

        sumaTotal += sumaParte2(op, rpta);
    }
    data.close();
    cout << sumaTotal;
}
