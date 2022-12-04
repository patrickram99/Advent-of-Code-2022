#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream data("prueba.txt");
    if(data.is_open()){
        string temp;
        while(!data.eof()){
            data >> temp;
            string sub1 = temp.substr(0, temp.length()/2);
            string sub2 = temp.substr(temp.length()/2, temp.length()/2);
            
        }
    } else{
        cout << "No se pudo abrir el archivo";
    }
    data.close();
    return 0;
}
