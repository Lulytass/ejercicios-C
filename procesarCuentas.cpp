#include <iostream>     //para usar COUT
#include <stdlib.h>     //Para usar EXIT()
#include<fstream>       //Para trabajar con files
#include <iomanip>      //para usar SETPRECISION(), FIXED, SETW
#include <string>       //para usar STROK() y GETLINE()
#include<string.h>      //Para usar STRCPY()
using namespace std;

int menu();


int main()
{
    int cta,opc;
    float saldo;
    ifstream arch;
    string line; // Lo declaramos String porque acepta espacios y para poder usar C_STR()
    char *nombre, *c, *s, lin[100]; //Apuntadores para los datos y una dimension
    const char *linea;  //es el apuntador donde vamos a guardar la direccion de la dimension String

    arch.open("cuentas.txt",ios::in);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    opc=menu();
    while(opc!=4)
    {
        switch(opc)
        {
            case 1:
                cout<<"Cuentas con saldo acreedor"<<endl;
                break;
            case 2:
                cout<<"Cuentas con saldo deudor"<<endl;
                break;
            case 3:
                cout<<"Cuentas con saldo cero"<<endl;
        }

        getline(arch,line);//guardamos la linea hasta el ENTER en la variable String

        while(!arch.eof()) // usamos una negacion con EOF() para ejecutar el WHILE mientras que no sea el final del txt
        {
            linea=line.c_str(); //con C_STR() convertimos un string en un puntero a una dimension char de C
            strcpy(lin,linea);  // Copiamos ese puntero a una dimension para poder usar STRCPY
            c=strtok(lin,",");  // Con STRTOK(nombreDimension, "separador") capturamos los datos por separado
            nombre=strtok(NULL,","); // Solo en el primer uso se usa como argumento el nombre de la dimension, despues usamos NULL
            s=strtok(NULL,",");
            saldo=atof(s); //Convertimos a dato Float con ATOF(apuntador)
            cta=atoi(c); //Convertimos a dato Int con ATOI(apuntador)
            if(saldo>0 && opc==1)
                cout<<left<<setw(10)<<cta<<setw(25)<<nombre<<setw(7)<<setprecision(2)<<fixed<<saldo<<endl;
            else
                if(saldo<0 && opc==2)
                    cout<<left<<setw(10)<<cta<<setw(25)<<nombre<<setw(7)<<setprecision(2)<<fixed<<saldo<<endl;
                else
                    if(saldo ==0 && opc==3)
                        cout<<left<<setw(10)<<cta<<setw(25)<<nombre<<setw(7)<<setprecision(2)<<fixed<<saldo<<endl;

            getline(arch,line); //Repetimos el GETLINE para que siga entrando al bucle
        }
        arch.clear(); //Limpiamos el buffer para que no tire error y reutilizar el txt
        arch.seekg(0);  //SEEKG() nos sirve para posicionarnos en determinada linea del txt, en este caso la 0
        system("pause"); //pausamos para que no limpie consola
        system("cls");  //Limpiamos consola
        opc=menu(); //ejecutamos la funcion menu de nuevo
    }
    arch.close();//SIEMPRE se tiene que cerrar el archivo
    return 0;
}

int menu()
{
    int opc;
    cout<<"1- Cuentas con saldo acreedor"<<endl;
    cout<<"2- Cuentas con saldo deudor"<<endl;
    cout<<"3- Cuentas con saldo cero"<<endl;
    cout<<"4- Salir"<<endl;
    cout<<endl<<"Ingrese una opción: ";
    do
    {
        cin>>opc;
        if(opc<1 || opc>4)
            cout<<"Opción incorrecta"<<endl;
    }while(opc<1 || opc>4);
    return opc;
}
