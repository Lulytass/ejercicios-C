#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "Persona.h"
#include<stdio.h>
using namespace std;

void buscar(fstream &,int);
void mostrar(fstream &);
int main()
{
    Persona p;
    int cod,ed;
    string n;
    fstream arch;
    arch.open("personas.dat",ios::app|ios::binary);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    arch.close();
    arch.open("personas.dat",ios::in|ios::out |ios::binary);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    cout<<"Ingrese el código: ";
    cin>>cod;
    while(cod!=0)
    {
        buscar(arch,cod);
        if(!arch.eof())
            cout<<"Alta existente"<<endl;
       else
       {
            arch.clear();
            p.setCodigo(cod);
            cout<<"Ingrese el nombre: ";
            fflush(stdin);
            getline(cin,n);
            p.setNombre(n);
            cout<<"Ingrese la edad: ";
            cin>>ed;
            p.setEdad(ed);
            arch.seekp(0,ios::end);
            arch.write(reinterpret_cast<const char *>(&p),sizeof(Persona));
       }
       cout<<"Ingrese el codigo: ";
       cin>>cod;
    }
    mostrar(arch);
    cout<<"Ingrese el código a modificar: ";
    cin>>cod;
    arch.clear();
    while(cod!=0)
    {
        buscar(arch,cod);
        if(arch.eof())
            {
                cout<<"Modificación inexistente"<<endl;
                arch.clear();
            }
       else
       {
            arch.seekg(arch.tellg()-sizeof(Persona),ios::beg);
            arch.read(reinterpret_cast<char *>(&p),sizeof(Persona));
            cout<<"Ingrese la edad: ";
            cin>>ed;
            p.setEdad(ed);
            arch.seekp(arch.tellg()-sizeof(Persona),ios::beg);
            arch.write(reinterpret_cast<const char *>(&p),sizeof(Persona));
       }
       cout<<"Ingrese el codigo: ";
       cin>>cod;
    }
    cout<<"Despues de modificar"<<endl;
    mostrar(arch);
    arch.close();
    return 0;
}

void buscar(fstream &a,int c)
{
  Persona p;
  a.clear();
  a.seekg(0);
  a.read(reinterpret_cast<char *>(&p),sizeof(Persona));
  while(!a.eof()&&p.getCodigo()!=c)
  {
      a.read(reinterpret_cast<char *>(&p),sizeof(Persona));
  }
}

void mostrar(fstream &a)
{
    Persona p;
    a.clear();
    a.seekg(0,ios::beg);
    a.read(reinterpret_cast<char *>(&p),sizeof(Persona));
    while(!a.eof())
    {
        cout<<"Código: "<<p.getCodigo()<<endl;
        cout<<"Nombre: "<<p.getNombre()<<endl;
        cout<<"Edad: "<<p.getEdad()<<endl;
        a.read(reinterpret_cast<char *>(&p),sizeof(Persona));
    }
}
