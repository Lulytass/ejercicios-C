/*Se dispone de la siguiente información almacenada en un archivo de texto de no más de 100 registros:
 Nro. de cta. cte. y saldo. Se ingresan todos los movimientos efectuados en el día indicando:
  Nro. de cuenta corriente, código de movimiento (1- entrada, 2- salida) e importe. La entrada
  finalizará cuando se ingrese nro. de cta. cte. igual a –1. El programa deberá:
a)	Mostrar un listado ordenado por número de cuenta corriente detallando nro. de cuenta cte. y saldo
 final.
b)	Importe total de entradas.
c)	Importe total de salidas.
d)	Del mayor movimiento del día: nro. de cuenta cte., importe, si fue ingreso o egreso.
El archivo de texto debe quedar actualizado después de procesar todos los movimientos del
 día de cada cuenta.
*/

#include<iostream>
using namespace std;
#include<fstream>
#include<string.h>
#include<string>
#include<iomanip>
#include<stdlib.h>

void ordenar(int[],float [],int);
void procesar(int[],float [],int);
int buscar(int [],int,int);
int main()
{
    int ctas[100],i=0,j;
    float saldo[100];
    fstream arch;
    string line;
    const char *linea;
    char lin[100];
    arch.open("banco.txt",ios::in);
    if(!arch)
    {
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    getline(arch,line);
    while(!arch.eof())
    {
        linea=line.c_str();
        strcpy(lin,linea);
        ctas[i]=atoi(strtok(lin,","));
        saldo[i]=atof(strtok(NULL,","));
        i++;
        getline(arch,line);
    }
    arch.close();
    procesar(ctas,saldo,i);
    arch.open("banco.txt",ios::out);
    if(!arch)
    {
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    for(j=0;j<i;j++)
        arch<<ctas[j]<<","<<fixed<<setprecision(2)<<saldo[j]<<endl;
    arch.close();
    ordenar(ctas,saldo,i);
    cout<<"Listado de cuentas"<<endl;
    cout<<setw(10)<<"Cuenta"<<setw(10)<<"Saldo"<<endl;
    for(j=0;j<i;j++)
        cout<<setw(10)<<ctas[j]<<setw(10)<<fixed<<setprecision(2)<<saldo[j]<<endl;
    return 0;
}

void procesar(int c[],float s[],int n)
{
    int cta,pos,cod,maxcta,tipo;
    float imp,entradas=0,salidas=0,maxi=0;
    cout<<"Ingrese un nro de cuenta: ";
    cin>>cta;
    while(cta!=-1)
    {
        pos=buscar(c,n,cta);
        if(pos!=-1)
        {
            do
            {
                cout<<"Ingrese el codigo de movimiento: ";
                cin>>cod;
                if(cod!=1 && cod!=2)
                    cout<<"Dato incorrecto"<<endl;
            }while(cod!=1 && cod!=2);
            cout<<"Ingrese el importe: ";
            cin>>imp;
            if(cod==1)
            {
                s[pos]+=imp;
                entradas+=imp;
            }
            else
            {
                s[pos]-=imp;
                salidas+=imp;
            }
            if(imp>maxi)
            {
                maxi=imp;
                maxcta=cta;
                tipo=cod;
            }
        }
        else
            cout<<"Nro de cuenta incorrecto"<<endl;
        cout<<"Ingrese un nro de cuenta: ";
        cin>>cta;
    }
    cout<<"Importe total de entradas: "<<fixed<<setprecision(2)<<entradas<<endl;
    cout<<"Importe total de salidas: "<<fixed<<setprecision(2)<<salidas<<endl;
    cout<<"Importe mayor: "<<fixed<<setprecision(2)<<maxi<<" correspondiente a la cuenta: "<<maxcta<<" y el tipo de movimiento es: "<<tipo<<endl;
}

int buscar(int c[],int n,int cta)
{
    int i=0;
    while(i<n && c[i]!=cta)
        i++;
    if(i==n)
        return -1;
    else
        return i;
}

void ordenar(int c[],float s[],int n)
{
    int i,j,auxc;
    float auxs;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(c[i]>c[j])
            {
                auxc=c[i];
                c[i]=c[j];
                c[j]=auxc;
                auxs=s[i];
                s[i]=s[j];
                s[j]=auxs;
            }
        }
    }
}
