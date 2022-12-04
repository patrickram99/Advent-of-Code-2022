#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int elementoComun(string &a, string &b, string &c){
    vector<char> comun;
    for(size_t i = 0; i < a.length(); ++i){
        for(size_t j = 0; j < b.length(); ++j){
            if(a[i] == b[j]){
                comun.push_back(a[i]);
            }
        }
    }
    for(size_t i = 0; i < comun.size(); ++i){
        for(size_t j = 0; j < c.length(); ++j){
            if(comun[i] == c[j]){
                return int(comun[i]);
            }
        }
    }
}

int main() {
    vector<int> elementosComunes;
    ifstream data("data.txt");
    if(data.is_open()){
        string temp1;
        string temp2;
        string temp3;
        while(!data.eof()){
            data >> temp1 >> temp2 >> temp3;
            elementosComunes.push_back(elementoComun(temp1, temp2, temp3));
        }
    } else{
        cout << "No se pudo abrir el archivo";
    }
    data.close();
    int sumaTotal = 0;
    for(auto a: elementosComunes) {
        if (int(a) > 96) {
            sumaTotal += int(a) - 96;
        } else {
            sumaTotal += int(a) - 38;
        }
    }
    cout << sumaTotal;
}
