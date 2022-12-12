#include <string>   //para trabajar con txt
#include <fstream>  //para trabajar con txt
#include <stdlib.h> //para usar EXIT
#include <iostream> //para usar el COUT
#include<string.h>  //para usar STRCPY
#include <iomanip> //para usar SETW

using namespace std;

void listado(int, ifstream &);//se usa & para hacer un pasaje por referencia, para que el main registre el movimiento del puntero;
float promedio(ifstream &);
int menu();

int main()
{
    ifstream arch;      //Lo declaramos como IFSTREAM para tener acceso al txt
    int opc;
    float prom=0;
    arch.open("personas.txt",ios::in);
        if(!arch)
        {
            cout<<"Error de apertura"<<endl;
            exit(1);
        }

    opc= menu();
   while(opc!=6)
    {
        switch(opc)
        {
        case 1:
            prom=promedio(arch);
            cout<<"El promedio es: "<<fixed<<setprecision(2)<<prom<<endl;
            break;
        case 2:
            listado(1,arch);
            break;
        case 3:
            listado(2,arch);
            break;
        case 4:
            listado(3,arch);
            break;
        case 5:
            listado(4,arch);
        }
        system("pause");
        system("cls");
        opc=menu();
    }



    arch.close();    //SIEMPRE usar .CLOSE()
    return 0;
}
int menu(){
    int opc=0;
    cout<<"1- Edad Promedio"<<endl;
    cout<<"2- Listado primario"<<endl;
    cout<<"3- Listado secundario"<<endl;
    cout<<"4- Listado terceario"<<endl;
    cout<<"5- Listado universitario"<<endl;
    cout<<"6- salir"<<endl;
    do{
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        if(opc<1 || opc>6)
            cout<<"La opcion ingresada es incorrecta"<<endl;
    }while(opc<1 || opc>6);
    return opc;
}
void listado(int opc, ifstream &dim){
    int edad, estudios, cont=0;
    const char *dirLinea;
    char *nombre,linea[100];
    string lineaTxt;

    dim.clear();
    dim.seekg(0);

    cout<<left<<setw(10)<<"Nombre"<<setw(10)<<"Edad"<<endl;

    getline(dim,lineaTxt);
    while(!dim.eof()){
        dirLinea=lineaTxt.c_str();
        strcpy(linea,dirLinea);
        nombre=strtok(linea,",");
        edad=atoi(strtok(NULL,","));
        estudios=atoi(strtok(NULL,","));

        if(opc == estudios){
            cout<<left<<setw(10)<<nombre<<setw(10)<<edad<<setw(10)<<estudios<<endl;
            cont++;
        }
        getline(dim,lineaTxt);
    }
     switch(opc)
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
float promedio(ifstream &dim){
    int edad, estudios, suma=0, cont=0;
    char *nombre, linea[100];
    const char *dirLinea;
    string lineaTxt;

    dim.clear();
    dim.seekg(0);

    getline(dim, lineaTxt);
    while(!dim.eof()){
        dirLinea=lineaTxt.c_str();
        strcpy(linea,dirLinea);
        nombre=strtok(linea,",");
        edad=atoi(strtok(NULL,","));
        estudios=atoi(strtok(NULL,","));
        suma+=edad;
        cont++;
        getline(dim, lineaTxt);
    }
    return (float)suma/cont;

}
