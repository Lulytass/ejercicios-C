#include <iostream>
#include <stdlib.h>
#include<fstream>
using namespace std;
#include<string>

int main()
{
    ofstream arch;
    string nombre;
    int edad,estudios;
    arch.open("personas.txt",ios::out);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    cout<<"Ingrese el nombre: ";
    getline(cin,nombre);
    while(nombre!="")
    {
        do
        {
            cout<<"Ingrese la edad: ";
            cin>>edad;
            if(edad<1 || edad>110)
                cout<<"Edad incorrecta"<<endl;
        }while(edad<1 || edad>110);
        do
        {
            cout<<"Ingrese los estudios: ";
            cin>>estudios;
            if(estudios<1 ||estudios>4)
                cout<<"Dato incorrectos"<<endl;
        }while(estudios<1 ||estudios>4);
        arch<<nombre<<","<<edad<<","<<estudios<<endl;
        cout<<"Ingrese el nombre: ";
        fflush(stdin);
        getline(cin,nombre);
    }
    arch.close();
    return 0;
}
