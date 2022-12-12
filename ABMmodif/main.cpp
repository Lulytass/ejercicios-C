#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "Cliente.h"
using namespace std;
#include<stdio.h>

void buscar(fstream &,int);
int menu();
void altaCliente(fstream &);
void bajaCliente(fstream &);
void modificarCliente(fstream &);
void crearArchivoTexto(fstream &);
void mostrar(fstream &);
void eliminarRegistros(fstream &);

int main()
{
    Cliente reg;
    fstream arch;
    int opc;
    arch.open("cuentas.dat",ios::app|ios::binary);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    arch.close();
    arch.open("cuentas.dat",ios::in|ios::out |ios::binary);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }

    opc = menu();
    while(opc!=7)
    {
        switch(opc)
        {
        case 1:
            altaCliente(arch);
            break;
        case 2:
            bajaCliente(arch);
            break;
        case 3:
            modificarCliente(arch);
            break;
        case 4:
            crearArchivoTexto(arch);
            break;
        case 5:
            mostrar(arch);
            break;
        case 6:
            eliminarRegistros(arch);
        }
        arch.clear();
        system("pause");
        system("cls");
        opc=menu();
    }
    arch.close();
    return 0;
}

int menu()
{
    int opc;
    cout<<"1- Alta de una cuenta"<<endl;
    cout<<"2- Baja de una cuenta"<<endl;
    cout<<"3- Modificar una cuenta"<<endl;
    cout<<"4- Crear archivo de texto"<<endl;
    cout<<"5- Mostrar cuentas"<<endl;
    cout<<"6- Eliminar registros"<<endl;
    cout<<"7- Terminar"<<endl;
    cout<<endl<<"Ingrese una opción: ";
    do
    {
        cin>>opc;
        if(opc<1 || opc>7)
        {
            cout<<"Opción incorrecta"<<endl;
        }
    }
    while(opc<1 || opc>7);
    return opc;
}

void altaCliente(fstream & arch)
{
    int cta;
    float s;
    string n;
    Cliente reg;
    cout<<"Ingrese el nro de cuenta: ";
    cin>>cta;
    while(cta!=0)
    {
        buscar(arch,cta);
        if(!arch.eof())
            cout<<"Alta existente"<<endl;
        else
        {
            arch.clear();
            reg.setCuenta(cta);
            reg.setBorrado(0);
            cout<<"Ingrese el nombre: ";
            fflush(stdin);
            getline(cin,n);
            reg.setNombre(n);
            cout<<"Ingrese el saldo: ";
            cin>>s;
            reg.setSaldo(s);
            arch.seekp(0,ios::end);
            arch.write(reinterpret_cast<const char *>(&reg),sizeof(Cliente));
        }
        cout<<"Ingrese el nro de cuenta: ";
        cin>>cta;
    }
}

void bajaCliente(fstream &arch)
{
    int cta;
    string n;
    Cliente reg;
    cout<<"Ingrese el nro de cuenta a dar de baja: ";
    cin>>cta;
    while(cta!=0)
    {
        buscar(arch,cta);
        if(arch.eof())
        {
            cout<<"Baja inexistente"<<endl;
            arch.clear();
        }
        else
        {
            arch.seekg(arch.tellg()-sizeof(Cliente),ios::beg);
            arch.read(reinterpret_cast<char *>(&reg),sizeof(Cliente));
            reg.setBorrado(1);
            arch.seekp(arch.tellg()-sizeof(Cliente),ios::beg);
            arch.write(reinterpret_cast<const char *>(&reg),sizeof(Cliente));
        }
        cout<<"Ingrese el nro de cuenta: ";
        cin>>cta;
    }
}

void modificarCliente(fstream &arch)
{
    int cta;
    float s,monto;
    Cliente reg;

    cout<<"Ingrese el nro de cuenta a modificar: ";
    cin>>cta;
    while(cta!=0)
    {
        buscar(arch,cta);
        if(arch.eof())
           {

            cout<<"Modificación inexistente"<<endl;
            arch.clear();
           }
        else
        {
            arch.seekg(arch.tellg()-sizeof(Cliente),ios::beg);
            arch.read(reinterpret_cast<char *>(&reg),sizeof(Cliente));
            if(reg.getBorrado()==0)
            {
                cout<<"Ingrese el monto (+) o (-) para actualizar el saldo: ";
                cin>>monto;
                s=reg.getSaldo();
                s+=monto;
                reg.setSaldo(s);
                arch.seekp(arch.tellg()-sizeof(Cliente),ios::beg);
                arch.write(reinterpret_cast<const char *>(&reg),sizeof(Cliente));
            }
            else
            {
                cout<<"Cuenta dada de baja"<<endl;
            }

        }
        cout<<"Ingrese el nro de cuenta: ";
        cin>>cta;
    }
}

void crearArchivoTexto(fstream &arch)
{
    ofstream archt;
    Cliente reg;
    archt.open("cuentasTxt.dat",ios::out);
    if(!archt)
    {
        cout<<"Error en la apertura"<<endl;
        exit(1);
    }
    archt<<left<<setw(10)<<"Cuenta"<<setw(20)<<"Nombre"<<setw(10)<<"Saldo"<<endl;

    arch.seekg(0);
    arch.read(reinterpret_cast<char *>(&reg),sizeof(Cliente));
    while(!arch.eof())
    {
        if(reg.getBorrado()==0)
        {
            archt<<left<<setw(10)<<reg.getCuenta()<<setw(20)<<reg.getNombre()<<setw(10)<<setprecision(2)<<fixed<<reg.getSaldo()<<endl;
        }
        arch.read(reinterpret_cast<char *>(&reg),sizeof(Cliente));
    }
    archt.close();
}

void mostrar(fstream &arch)
{
    Cliente reg;
    arch.clear();
    arch.seekg(0,ios::beg);
    cout<<left<<setw(10)<<"Cuenta"<<setw(20)<<"Nombre"<<setw(10)<<"Saldo"<<endl;
    arch.read(reinterpret_cast<char *>(&reg),sizeof(Cliente));
    while(!arch.eof())
    {
        if(reg.getBorrado()==0)
        {
            cout<<left<<setw(10)<<reg.getCuenta()<<setw(20)<<reg.getNombre()<<setw(10)<<setprecision(2)<<fixed<<reg.getSaldo()<<endl;
        }
        arch.read(reinterpret_cast<char *>(&reg),sizeof(Cliente));
    }
}

void buscar(fstream &a,int c)
{
    Cliente reg;
    a.clear();
    a.seekg(0,ios::beg);
    a.read(reinterpret_cast<char *>(&reg),sizeof(Cliente));
    while(!a.eof()&&reg.getCuenta()!=c)
    {
        a.read(reinterpret_cast<char *>(&reg),sizeof(Cliente));
    }
}

void eliminarRegistros(fstream &a)
{
    fstream temp;
    Cliente reg;

    temp.open("temporal.dat",ios::out |ios::binary);
    if(!temp)
    {
        cout<<"Error de apertura de archivo"<<endl;
        exit(1);
    }

    a.clear();
    a.seekg(0,ios::beg);
    a.read(reinterpret_cast<char *>(&reg),sizeof(Cliente));
    while(!a.eof())
    {
        if(reg.getBorrado()==0)
        {
            temp.write(reinterpret_cast<const char *>(&reg),sizeof(Cliente));
        }
        a.read(reinterpret_cast<char *>(&reg),sizeof(Cliente));
    }
    a.close();
    temp.close();
    system("del cuentas.dat");
    system("rename temporal.dat cuentas.dat");
    a.open("cuentas.dat",ios::in|ios::out |ios::binary);
    if(!a)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
}
