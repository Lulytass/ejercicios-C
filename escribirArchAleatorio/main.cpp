#include <iostream>
#include "Cliente.h"
#include <stdlib.h>
#include <fstream>
#include<string>
using namespace std;

int main()
{
    int cta;
    string nombre;
    float saldo;
    Cliente reg;
    fstream arch;
    arch.open("cuentas3.dat",ios::in | ios::out |ios::binary);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    do
    {
        cout<<"Ingrese un número de cuenta: ";
        cin>>cta;
        if(cta<0 || cta >100)
        {
            cout<<"Número de cuenta incorrecto"<<endl;
        }
    }while(cta<0 ||cta>100);
    while(cta!=0)
    {
        cout<<"Ingrese el nombre: ";
        cin>>nombre;
        cout<<"Ingrese el saldo: ";
        cin>>saldo;
        reg.setCuenta(cta);
        reg.setNombre(nombre);
        reg.setSaldo(saldo);
        arch.seekp((reg.getCuenta() - 1) * sizeof(Cliente));
        arch.write(reinterpret_cast<const char *>(&reg),sizeof(Cliente));
        do
        {
            cout<<"Ingrese un número de cuenta: ";
            cin>>cta;
            if(cta<0 || cta >100)
            {
                cout<<"Número de cuenta incorrecto"<<endl;
            }
        }while(cta<0 ||cta>100);
    }
    arch.close();
    return 0;
}
