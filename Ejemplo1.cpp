#include <iostream>
#include <stdlib.h>
#include<fstream>
using namespace std;


int main()
{
    int x,y,n=0;
    ofstream arch;

    arch.open("puntos.dat",ios::out);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    do
    {
        cout<<"Ingrese las coordenadas del punto: ";
        cin>>x>>y;
        if(x!=0 || y!=0)
        {
            arch<<x<<','<<y<<endl;
            n++;
        }
    }while((x!=0 || y!=0) && n<50);
    arch.close();
    return 0;
}
