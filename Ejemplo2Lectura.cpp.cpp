/*Hacer un programa que lea el archivo de texto creado en Ejercicio2 y utilizando funciones a través
de un menú permita calcular y mostrar por pantalla la edad promedio, listado de personas con estudios
primarios, listado de personas con estudios secundarios, listado de personas con estudios terciarios y
listado de personas con estudios universitarios.*/


#include<fstream>
#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>
#include<string.h>
#include<iomanip>

float promedio(ifstream &);
void listado(ifstream &,int);
int menu();

int main()
{
    int opc;
    ifstream arch;
    float prom;

    arch.open("personas.dat",ios::in);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    opc=menu();
    while(opc!=6)
    {
        switch(opc)
        {
        case 1:
            prom=promedio(arch);
            cout<<"El promedio es: "<<fixed<<setprecision(2)<<prom<<endl;
            break;
        case 2:
            listado(arch,1);
            break;
        case 3:
            listado(arch,2);
            break;
        case 4:
            listado(arch,3);
            break;
        case 5:
            listado(arch,4);
        }
        system("pause");
        system("cls");
        opc=menu();
    }
    arch.close();
    return 0;
}

float promedio(ifstream &a)
{
    int est,edad,suma=0,cont=0;
    char *nom,lin[100];
    const char *linea;
    string line;

    a.clear();
    a.seekg(0);

    getline(a,line);
    while(!a.eof())
    {
        linea=line.c_str();
        strcpy(lin,linea);
        nom=strtok(lin,",");
        edad=atoi(strtok(NULL,","));
        est=atoi(strtok(NULL,","));
        suma+=edad;
        cont++;
        getline(a,line);
    }
    return (float)suma/cont;
}

void listado(ifstream &a, int e)
{
    int cont=0,edad,est;
    char *nom,lin[100];
    const char *linea;
    string line;

    a.clear();
    a.seekg(0);

    cout<<left<<setw(10)<<"Nombre"<<setw(10)<<"Edad"<<endl;
    getline(a,line);
    while(!a.eof())
    {
        linea=line.c_str();
        strcpy(lin,linea);
        nom=strtok(lin,",");
        edad=atoi(strtok(NULL,","));
        est=atoi(strtok(NULL,","));
        if(est==e)
        {
            cout<<left<<setw(10)<<nom<<setw(10)<<edad<<endl;
            cont++;
        }
        getline(a,line);
    }
    switch(e)
    {
    case 1:
        cout<<"Cantidad de personas con estudios primarios: "<<cont<<endl;
        break;
    case 2:
        cout<<"Cantidad de personas con estudios secundarios: "<<cont<<endl;
        break;
    case 3:
        cout<<"Cantidad de personas con estudios terciarios: "<<cont<<endl;
        break;
    case 4:
        cout<<"Cantidad de personas con estudios universitarios: "<<cont<<endl;
    }
}


int menu()
{
    int o;
    cout<<"1- Edad promedio"<<endl;
    cout<<"2- Listado de personas con estudios primarios"<<endl;
    cout<<"3- Listado de personas con estudios secundarios"<<endl;
    cout<<"4- Listado de personas con estudios terciarios"<<endl;
    cout<<"5- Listado de personas con estudios universitarios"<<endl;
    cout<<"6- Salir"<<endl;
    do
    {
        cout<<"Ingrese una opcion: ";
        cin>>o;
        if(o<1 || o>6)
            cout<<"Dato incorrecto"<<endl;
    }
    while(o<1 || o>6);
    return o;
}
