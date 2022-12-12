#include <iostream>
#include <stdlib.h>
#include<fstream>
#include <iomanip>
#include <string>
#include<string.h>
using namespace std;
#include<math.h>

int main()
{
    ifstream arch;
    string line;
    const char *linea;
    char lin[50];
    int x,y;
    float dist;

    arch.open("puntos.dat",ios::in);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    cout<<setw(10)<<"Coord. x"<<setw(10)<<"Coord. y"<<setw(20)<<"Distancia"<<endl;
    getline(arch,line);
    while(!arch.eof())
    {
        linea=line.c_str();
        strcpy(lin,linea);
        x=atoi(strtok(lin,","));
        y=atoi(strtok(NULL,","));
        dist=sqrt(x*x+y*y);
        cout<<setw(10)<<x<<setw(10)<<y<<setw(20)<<fixed<<setprecision(2)<<dist<<endl;
        getline(arch,line);
    }
    arch.close();
    return 0;
}
