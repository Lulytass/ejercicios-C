#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>

using namespace std;

void sueldo(ifstream &);

int main()
{
    ifstream empleados;


    empleados.open("tarea1.txt",ios::in);
    sueldo(empleados);
    empleados.close();
    return 0;
}

void sueldo(ifstream &emp)
{
    string linea;
    const char *dirLinea;
    int pree,pri,sec,hijosTotal,hX;
    char arr[100], *estC, *nomb, *cat, *cod;
    float basico,salario;
    cout<<left<<setw(12)<<"Codigo"<<setw(12)<<"Categoria"<<setw(12)<<"Nombre"<<setw(12)<<"Est. Civil"<<setw(12)<<"Salario"<<endl;

    getline(emp, linea);
    while(!emp.eof()){
        dirLinea=linea.c_str();
        strcpy(arr,dirLinea);
        cod=strtok(arr,",");
        nomb=strtok(NULL,",");
        cat=strtok(NULL,",");
        estC=strtok(NULL,",");
        basico=atof(strtok(NULL,","));
        hijosTotal=atoi(strtok(NULL,","));
        pree=atoi(strtok(NULL,","));
        pri=atoi(strtok(NULL,","));
        sec=atoi(strtok(NULL,","));
        hX=atoi(strtok(NULL,","));

        if((strcmp(cat,"C")==0) && (strcmp(estC,"Casado")==0)){
            salario= basico + (hX*7) + (hijosTotal*8) + (pree*6) + (pri*7) + (sec*8);
            cout<<left<<setw(12)<<cod<<setw(12)<<nomb<<setw(12)<<cat<<setw(12)<<estC<<setw<<salario<<endl;
        }

        getline(emp, linea);
    }
}
