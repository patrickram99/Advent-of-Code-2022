#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;
void elfoMayor(const string &txt){
    ifstream data(txt);
    string temp;
    int suma = 0;
    int mayor = 0;
    if (data.is_open()) {
        while (getline(data, temp)) {
            if(temp.empty()){
                if(suma > mayor){
                    mayor = suma;
                }
                suma = 0;
            } else{
                suma += std::stoi(temp);
            }
        }
    }else{
        cout << "No se pudo abrir el archivo";
    }

    //cout << "\nslda " << suma << endl << mayor;
    if(suma > mayor){
        mayor = suma;
        suma = 0;
    }
    cout << "\n El mayor es: " << mayor << endl;
    data.close();
}

int main() {
    vector<int> caloriasElfos;
    ifstream data("data.txt");
    string temp;
    int suma = 0;
    if (data.is_open()) {
        while (getline(data, temp)) {
            if(temp.empty()){
                caloriasElfos.push_back(suma);
                suma = 0;
            } else{
                suma += std::stoi(temp);
            }

        }
    }else{
        cout << "No se pudo abrir el archivo";
    }

    caloriasElfos.push_back(suma);
    sort(caloriasElfos.begin(), caloriasElfos.end());

    int sumaTotal = caloriasElfos[size(caloriasElfos)-1] + caloriasElfos[size(caloriasElfos) - 2] + caloriasElfos[size(caloriasElfos)-3];
    cout << "La suma total es: "  << sumaTotal << endl;
    data.close();
}