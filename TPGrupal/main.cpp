#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include<stdio.h>
#include "Producto.h"
using namespace std;

int menu();
void buscar(fstream &, int);
void mostrarExistencia(fstream &);
void mostrarAReponer(fstream &);
void alta(fstream &);
void baja(fstream &);
void modificar(fstream &);
void venta(fstream &);
void comprar(fstream &);

int main()
{
    fstream arch;
    int opc;
    arch.open("documento.dat",ios::app|ios::binary);
    if(!arch)
    {
        cout<<"ERROR AL ABRIR EL ARCHIVO";
        exit(1);
    }
    arch.close();
    arch.open("documento.dat",ios::in|ios::out|ios::binary);
    if(!arch)
    {
        cout<<"ERROR AL ABRIR EL ARCHIVO";
        exit(1);
    }
    opc=menu();
while(opc!=0)
    {
        switch(opc)
        {
        case 1:
            alta(arch);
            break;
        case 2:
            baja(arch);
            break;
        case 3:
            modificar(arch);
            break;
        case 4:
            mostrarExistencia(arch);
            break;
        case 5:
            mostrarAReponer(arch);
            break;
        case 6:
            venta(arch);
            break;
        case 7:
            comprar(arch);;
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
    cout<<"0-Salir"<<endl;
    cout<<"1-Dar un producto de alta"<<endl;
    cout<<"2-Dar un producto de  baja"<<endl;
    cout<<"3-Modificar stock minimo, maximo y precio de reposicion"<<endl;
    cout<<"4-Listar existencia de productos"<<endl;
    cout<<"5-Listar productos a reponer"<<endl;
    cout<<"6-Venta"<<endl;
    cout<<"7-Compra"<<endl;
    cout<<"Ingrese una opcion:"<<endl;
    do{
        cin>>opc;
        if(opc<0 || opc>7)
            cout<<"OPCION INCORRECTA"<<endl;
    }while(opc<0 || opc>7);
    return opc;
}
void buscar(fstream &a, int c)
{
    Producto reg;
    a.clear();
    a.seekg(0,ios::beg);
    a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));

    while(!a.eof() && reg.getCodigo() != c)
    {
       a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    }
}
void mostrarExistencia(fstream &a)
{
    Producto reg;
    a.clear();
    a.seekg(0,ios::beg);
    a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    cout<<left<<setw(15)<<"Codigo Art."<<setw(15)<<"Existencia"<<endl;

    while(!a.eof())
    {
        if(reg.getEliminado()==0)
        {
            cout<<left<<setw(15)<<reg.getCodigo()<<setw(15)<<reg.getExistencia()<<endl;
        }
        a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    }
}
void mostrarAReponer(fstream &a)
{
    Producto reg;
    a.clear();
    a.seekg(0,ios::beg);
    a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));

    while(!a.eof())
    {
        if(reg.getStockMin() >= reg.getExistencia()){
            cout<<"ARTICULO: "<<reg.getCodigo()<<endl;
            cout<<"DESCRIPCION: "<<reg.getDescripcion()<<endl;
            cout<<"REPONER: "<<reg.getStockMax()-reg.getExistencia()<<endl;
            cout<<"COSTO DE REPOSICION: "<< (reg.getStockMax()-reg.getExistencia())*reg.getPrecioRepo()<<endl;
        }
        a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    }
}
void alta(fstream &a)
{
    Producto reg;
    int cod,stock,mi,ma;
    string desc;
    float pre;

    cout<<"Ingrese el codigo del producto: ";
    cin>>cod;
    while(cod !=0)
    {
        buscar(a,cod);
        if(!a.eof())
            cout<<"El producto ya existe"<<endl;
        else
        {
            a.clear();
            reg.setCodigo(cod);
            reg.setEliminado(0);
            cout<<"Ingrese la descripcion del producto: ";
            fflush(stdin);
            getline(cin,desc);
            reg.setDescripcion(desc);
            cout<<"Ingrese el stock actual: ";
            cin>>stock;
            reg.setExistencia(stock);
            cout<<"Ingrese el stock minimo con el que quiere contar: ";
            cin>>mi;
            reg.setStockMin(mi);
            cout<<"Ingrese el stock maximo con el que quiere contar: ";
            cin>>ma;
            reg.setStockMax(ma);
            cout<<"Ingrese el precio al que se repondra el producto: ";
            cin>>pre;
            reg.setPrecioRepo(pre);
            a.seekp(0,ios::end);
            a.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
        }
        cout<<"Ingrese el codigo del producto: ";
        cin>>cod;
    }
}
void baja(fstream &a)
{
    int cod;
    Producto reg;
    cout<<"Ingrese el codigo del producto que se dara de baja: ";
    cin>>cod;
    while(cod != 0)
    {
        buscar(a,cod);
        if(a.eof())
        {
            cout<<"El producto no existe"<<endl;
            a.clear();
        }
        else
        {
            a.seekg(a.tellg()-sizeof(Producto),ios::beg);
            a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
            reg.setEliminado(1);
            a.seekp(a.tellg()-sizeof(Producto),ios::beg);
            a.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
        }
        cout<<"Ingrese el codigo del producto que se dara de baja: ";
        cin>>cod;
    }
}
void modificar(fstream &a)
{
    Producto reg;
    int cod,mi,ma,cantmin,cantmax;
    float pre;

    cout<<"Ingrese el codigo del producto a modificar: ";
    cin>>cod;
    while(cod!=0)
    {
        buscar(a,cod);
        if(a.eof())
           {

            cout<<"El producto no existe"<<endl;
            a.clear();
           }
        else
        {
            a.seekg(a.tellg()-sizeof(Producto),ios::beg);
            a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
            if(reg.getEliminado()==0)
            {
                cout<<"Ingrese la cantidad (+) o (-) para actualizar el stock minimo: ";
                cin>>cantmin;
                mi=reg.getStockMin();
                mi+=cantmin;
                reg.setStockMin(mi);
                a.seekp(a.tellg()-sizeof(Producto),ios::beg);
                a.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
                cout<<"Ingrese la cantidad (+) o (-) para actualizar el stock maximo: ";
                cin>>cantmax;
                ma=reg.getStockMax();
                ma+=cantmax;
                reg.setStockMax(ma);
                a.seekp(a.tellg()-sizeof(Producto),ios::beg);
                a.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
            }
            else
            {
                cout<<"Producto dado de baja"<<endl;
            }

        }
        cout<<"Ingrese el codigo del producto a modificar: ";
        cin>>cod;
    }
}
void venta(fstream &a)
{
    Producto reg;
    int cod,vta,stock;

    cout<<"Ingrese el codigo del producto a vender: ";
    cin>>cod;
    while(cod!=0)
    {
        buscar(a,cod);
        if(a.eof())
           {

            cout<<"El producto no existe"<<endl;
            a.clear();
           }
        else
        {
            a.seekg(a.tellg()-sizeof(Producto),ios::beg);
            a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
            if(reg.getEliminado()==0)
            {
                cout<<"Ingrese la cantidad la vendeder: ";
                cin>>vta;
                if(vta>reg.getExistencia())
                {
                    cout<<"No se cuenta con el stock suficiente.\n";
                }
                else
                {
                    stock=reg.getExistencia();
                    stock-=vta;
                    reg.setExistencia(stock);
                    a.seekp(a.tellg()-sizeof(Producto),ios::beg);
                    a.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
                }
            }

            else
            {
                cout<<"Producto dado de baja"<<endl;
            }

        }
        cout<<"Ingrese el codigo del a vender: ";
        cin>>cod;
    }
}
void comprar(fstream &a)
{
    Producto reg;
    int cod,stock,comp;


    cout<<"Ingrese el codigo del producto a comprar: ";
    cin>>cod;
    while(cod!=0)
    {
        buscar(a,cod);
        if(a.eof())
           {

            cout<<"El producto no existe, seleccione la opcion 1"<<endl;
            a.clear();
           }
        else
        {
            a.seekg(a.tellg()-sizeof(Producto),ios::beg);
            a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
            if(reg.getEliminado()==0)
            {
                cout<<"Ingrese la cantidad a comprar: ";
                cin>>comp;
                if(comp>reg.getStockMax())
                {
                    cout<<"La cantidad total supera el stock maximo permitido.\n";
                }
                else
                {
                    stock=reg.getExistencia();
                    stock+=comp;
                    reg.setExistencia(stock);
                    a.seekp(a.tellg()-sizeof(Producto),ios::beg);
                    a.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
                }
            }

            else
            {
                cout<<"Producto dado de baja"<<endl;
            }

        }
        cout<<"Ingrese el codigo del a comprar: ";
        cin>>cod;
    }
}
