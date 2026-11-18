#include <iostream>
using namespace std; 

int main (){
    int edad; 
    cout << "Ingresa tu edad: "; 
    cin >> edad; 

    if(edad >= 15){ //si se cumple se ejecuta el bloque de codigo
        cout << "Bienvenido";
    }
    else if (edad < 0 ){ //si la primera condicion es falsa, ahoar se evalua esta condicion 
        cout <<"no haz nacido"; 
    }
    else {
        cout << "No puedes"; 
    }
    return 0;
}