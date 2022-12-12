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
#include <string>   //para trabajar con txt
#include <fstream>  //para trabajar con txt
#include <stdlib.h> //para usar EXIT
#include <iostream> //para usar el COUT
#include<string.h>  //para usar STRCPY
#include <iomanip> //para usar SETW

using namespace std;
void ordenar(int[], float[],int);
void procesar(int[],float[],int);
int buscar(int [], int, int);
int main()
{
    fstream doc;
    int cuentas[100];
    float saldos[100];
    doc.open("banco.txt",ios::in);
    if(!doc){
        cout<<"No se pudo abrir el documento";
        exit(1);
    }
    string linea;
    const char *dirLinea;
    char lin[100];
    int i=0;

    getline(doc,linea);
    while(!doc.eof()){
        dirLinea=linea.c_str();
        strcpy(lin,dirLinea);
        cuentas[i]=atoi(strtok(lin,","));
        saldos[i]=atof(strtok(NULL,","));
        i++;
        getline(doc,linea);
    }

    doc.close();
    procesar(cuentas,saldos,i);

    int j;
    doc.open("banco.txt",ios::out);
    if(!doc){
        cout<<"No se pudo abrir el documento";
        exit(1);
    }
    for(j=0; j<i;j++)
        doc<<cuentas[j]<<","<<fixed<<setprecision(2)<<saldos[j]<<endl;
    doc.close();
    ordenar(cuentas,saldos,i);
    cout<<left<<setw(15)<<"Nro Cta"<<setw(15)<<"Saldo"<<endl;
    for(j=0;j<i;j++){
        cout<<left<<setw(15)<<cuentas[j]<<setw(15)<<saldos[j]<<endl;
    }

    return 0;
}

void procesar(int nroCta[],float saldo[],int tam){
    int i,numC=0,opc,resultBuscar,mayorCta=0,mayorOp=0;
    float importe=0,mayorSaldo=0,entradas=0,salidas=0;
    cout<<"Ingrese un numero de Cta Cte: ";
    cin>>numC;
    while(numC != -1){
        resultBuscar=buscar(nroCta,tam, numC);
        if(resultBuscar !=-1){
           do{
            cout<<"1_realizar un deposito"<<endl;
            cout<<"2_realizar una extraccion"<<endl;
            cout<<"Selecciones una opcion"<<endl;
            cin>>opc;
            if(opc!=1 && opc!=2)
                cout<<"Dato incorrecto"<<endl;
            }while(opc!=1 && opc!=2);
            cout<<"Ingrese el monto: ";
            cin>>importe;


            if(opc == 1){
                saldo[resultBuscar]+=importe;
                entradas+=importe;
            }else{
                saldo[resultBuscar]-=importe;
                salidas+=importe;
            }

            if(mayorSaldo<importe){
                mayorSaldo=importe;
                mayorCta=numC;
                mayorOp=opc;
            }

        }else
        cout<<"Cuenta incorrecta"<<endl;
        cout<<"ingrese un numero de Cta Cte: ";
        cin>>numC;

    }
    cout<<"La cuenta "<<mayorCta<<" es la que registra la transaccion mas grande, siendo esta de "<<mayorSaldo<<" con codigo "<<mayorOp<<endl;
    cout<<"El total de depositos es de: "<<entradas<<endl;
    cout<<"El total de extracciones es de: "<<salidas<<endl;

}


int buscar(int cta[],int tam,int num){
    int i=0;
    while(i<tam && cta[i] != num)
                i++;
            if(i==tam)
                return -1;
            else
                return i;
}
void ordenar(int nroCta[],float saldo[],int tam){
    int auxC=0,i,j;
    float auxS=0;

    for(i=0;i<tam-1;i++)
    for(j=i+1;j<tam;j++){
        if(nroCta[i]>nroCta[j]){
            auxC=nroCta[i];
            nroCta[i]=nroCta[j];
            nroCta[j]=auxC;
            auxS=saldo[i];
            saldo[i]=saldo[j];
            saldo[j]=auxS;
        }
    }
}
