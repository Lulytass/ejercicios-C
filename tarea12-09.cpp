//Dado un archivo de texto con los campos: código obrero, nombre, categoría(1,2,3) y horas trabajadas.
//Hacer un programa para calcular el sueldo de cada obrero, mostrando en cada uno toda la información y el sueldo y el total de sueldos que debe pagar la empresa.
//Tener en cuenta para el sueldo:
//Categoría 1: $100 xh
//Categoría 2: $150 xh
//Categoría 3: $200 xh
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void sueldoTotalSueldos(ifstream &);

int main()
{
    ifstream arch;

    arch.open("empleados.txt",ios::in);
    if(!arch){
        cout<<"ERROR EN LA APERTURA DEL TXT";
        exit(1);
    }
    sueldoTotalSueldos(arch);

    arch.close();
    return 0;
}

void sueldoTotalSueldos(ifstream &txt)
{
    string linea;
    int cod, cat, hT,sueldoTotal=0;
    char *nombre, arr[100];
    const char *puntLine;

    cout<<left<<setw(8)<<"CODIGO"<<setw(20)<<"NOMBRE"<<setw(10)<<"CATEGORIA"<<setw(12)<<"HORAS TRAB."<<setw(15)<<"SUELDO"<<endl;

    getline(txt,linea);
    while(!txt.eof())
    {
        puntLine= linea.c_str();
        strcpy(arr,puntLine);
        cod=atoi(strtok(arr,","));
        nombre=strtok(NULL,",");
        cat=atoi(strtok(NULL,","));
        hT=atoi(strtok(NULL,","));

        if(cat==1){
            cout<<left<<setw(8)<<cod<<setw(20)<<nombre<<setw(10)<<cat<<setw(12)<<hT<<setw(15)<<hT*100<<endl;
            sueldoTotal+=hT*100;
        }
        else if(cat==2){
            cout<<left<<setw(8)<<cod<<setw(20)<<nombre<<setw(10)<<cat<<setw(12)<<hT<<setw(15)<<hT*150<<endl;
            sueldoTotal+=hT*150;
        }else{
            cout<<left<<setw(8)<<cod<<setw(20)<<nombre<<setw(10)<<cat<<setw(12)<<hT<<setw(15)<<hT*200<<endl;
            sueldoTotal+=hT*200;
        }
        getline(txt,linea);
    }
    cout<<"El total de sueldos que se deben pagar es de: "<<sueldoTotal<<endl;
}
