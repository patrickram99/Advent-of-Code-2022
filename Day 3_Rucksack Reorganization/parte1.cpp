#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char elementoComun(string &a, string &b){
    char elmComun;
    for(size_t i = 0; i < a.length(); ++i){
        for(size_t j = 0; j < b.length(); ++j){
            if(a[i] == b[j]){
                elmComun = a[i];
                break;
            }
        }
    }
    return elmComun;
}

int main() {
    vector<char> elementosComunes;
    ifstream data("data.txt");
    if(data.is_open()){
        string temp;
        while(!data.eof()){
            data >> temp;
            string sub1 = temp.substr(0, temp.length()/2);
            string sub2 = temp.substr(temp.length()/2, temp.length()/2);
            elementosComunes.push_back(elementoComun(sub1, sub2));
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
    return 0;
}
