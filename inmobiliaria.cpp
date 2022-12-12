#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void leerArch(ifstream &);

int main()
{
    ifstream arch;
    arch.open("inmobiliaria.txt",ios::in);
    if(!arch){
        cout<<"ERROR EN LA APERTURA DEL TXT";
        exit(1);
    }

    leerArch(arch);

    arch.close();
    return 0;
}

void leerArch(ifstream &txt){
    string linea,b;
    char *barrio, arr[100],nMasCaro[30];
    const char *puntLinea;
    int amb, precio,a,pM,total2Pal=0,masCaro=0;

    cout<<"Barrio: "<<endl;
        fflush(stdin);
        getline(cin,b);
        cout<<"Cantidad de ambientes: "<<endl;
        cin>>a;
        cout<<"Precio maximo: "<<endl;
        cin>>pM;
            cout<<left<<setw(20)<<"barrio"<<setw(10)<<"amb"<<setw(15)<<"precio"<<endl;

    getline(txt,linea);
    while(!txt.eof()){
        puntLinea=linea.c_str();
        strcpy(arr,puntLinea);
        barrio=strtok(arr,",");
        amb=atoi(strtok(NULL,","));
        precio=atoi(strtok(NULL,","));


        if(barrio==b && amb == a && precio <= pM){
            cout<<left<<setw(20)<<barrio<<setw(10)<<amb<<setw(15)<<precio<<endl;
           }
        if(amb==2 && (strcmp(barrio,"Palermo")==0)){
            total2Pal++;
           }
        if(precio>masCaro && amb == 3){
            masCaro=precio;
            strcpy(nMasCaro,barrio);
        }

        getline(txt,linea);
    }
    cout<<"La propiedad mas cara de 3 amb esta en "<<nMasCaro<<" y tiene un costo de "<<masCaro<<endl;
    cout<<"Hay "<<total2Pal<<" propiedades de 2 amb. en Palermo"<<endl;
}
