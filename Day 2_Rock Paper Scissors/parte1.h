#ifndef DAY_2_ROCK_PAPER_SCISSORS_PARTE1_H
#define DAY_2_ROCK_PAPER_SCISSORS_PARTE1_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
 int sumaParcial(string &a, int b){
     string resultados[] = {"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"};
     int puntaje[] = {3, 6, 0, 0, 3, 6, 6, 0, 3};
     for(size_t i = 0; i < 9; ++i){
         for(size_t i = 0; i < 9; ++i){
             if(puntaje[i] == b && resultados[i].substr(0, 1) == a){
                 return stoi(resultados[i].substr(1, 1));
             }
         }
     }
 }

int sumaParcial(string &a, string &b){
    int suma = 0;
    string resultados[] = {"AX", "AY", "AZ", "BX", "BY", "BZ", "CX", "CY", "CZ"};
    int puntaje[] = {3, 6, 0, 0, 3, 6, 6, 0, 3};
    string rpta = a + b;
    switch (b[0]) {
        case 'X':
            suma += 1;
            break;
        case 'Y':
            suma += 2;
            break;
        case 'Z':
            suma += 3;
            break;
        default:
            break;
    }
    for(size_t i = 0; i < 9; ++i){
        if(rpta == resultados[i]){
            suma += puntaje[i];
            break;
        }
    }
    return suma;
}

void parte1(string const &fichero){
    int     sumaTotal = 0;
    string    op;
    string    rpta;

    ifstream data(fichero);
    while(!data.eof()){
        data >> op >> rpta;
        sumaTotal += sumaParcial(op, rpta);
        //cout << op << " " << rpta << " " << sumaTotal << endl;
    }
    data.close();
    cout << sumaTotal;
}
#endif //DAY_2_ROCK_PAPER_SCISSORS_PARTE1_H