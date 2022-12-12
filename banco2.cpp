#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>

using namespace std;

struct datos
{
       char categoria[5], estadoC[10];
       float sueldo;
};
void sueldo(ifstream &);
void buscar(ifstream &, datos);
void menu(ifstream &);

int main()
{
    ifstream empleados;

    empleados.open("tarea1.txt",ios::in);
    if(!empleados){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        exit(1);
    }

    sueldo(empleados);
    menu(empleados);
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
    cout<<left<<setw(12)<<"Codigo"<<setw(12)<<"Nombre"<<setw(12)<<"Categoria"<<setw(12)<<"Est. Civil"<<setw(12)<<"Salario"<<endl;

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
            cout<<left<<setw(12)<<cod<<setw(12)<<nomb<<setw(12)<<cat<<setw(12)<<estC<<setw(12)<<fixed<<setprecision(2)<<salario<<endl;
        }

        getline(emp, linea);
    }
}

void buscar(ifstream &emp, datos datEmp){
    string linea;
    const char *dirLinea;
    int pree,pri,sec,hijosTotal,hX;
    char arr[100], *estC, *nomb, *cat, *cod;
    float basico,salario;

    emp.clear();
    emp.seekg(0);

    cout<<left<<setw(12)<<"Codigo"<<setw(12)<<"Nombre"<<setw(12)<<"Categoria"<<setw(12)<<"Est. Civil"<<setw(12)<<"Salario"<<endl;

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


        if((strcmp(estC, datEmp.estadoC)== 0) && (strcmp(cat, datEmp.categoria)== 0)){
            salario= basico + (hX*7) + (hijosTotal*8) + (pree*6) + (pri*7) + (sec*8);
            if(salario>datEmp.sueldo)
            cout<<left<<setw(12)<<cod<<setw(12)<<nomb<<setw(12)<<cat<<setw(12)<<estC<<setw(12)<<fixed<<setprecision(2)<<salario<<endl;
        }
        getline(emp, linea);
    }
}

void menu(ifstream &emp){
    datos info;
        cout<<"\nSELECCIONE UNA OPCION DEL MENU"<<endl;
        cout<<"Ver empleados de la categoria: "<<endl;
        cin>>info.categoria;
        cout<<"Ver empleados con estado civil: "<<endl;
        cin>>info.estadoC;
        cout<<"Con sueldos mayores a: "<<endl;
        cin>>info.sueldo;

    buscar(emp,info);

}
