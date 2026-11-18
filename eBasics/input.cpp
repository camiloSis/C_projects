#include <iostream>
using namespace std;  
int main(){

    string name; 
    int edad; 
    cout<< "WHAT YOUR NAME?"; 
    getline(cin,name); // ENTRADA DE USUARIO PARA STRING USANDO GET LINE ES NECESARIO I THJINK
    cout << " hola" << name << "\n"; 

    cout << "CUAL ES TU EDAD ? \n";
    cin >> edad; 
    cout << "tu edad es " << edad; 
    return 0; 
}