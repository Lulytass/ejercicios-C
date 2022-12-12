#include <iostream>
#include <fstream>
#include "Cliente.h"
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main()
{
   Cliente reg;
   ifstream arch;
   arch.open("cuentas3.dat",ios::in |ios::binary);
   if(!arch)
   {
       cout<<"Error de apertura"<<endl;
       exit(1);
   }
   cout<<left<<setw(10)<<"Cuenta"<<setw(20)<<"Nombre"<<setw(10)<<"Saldo"<<endl;
   arch.read(reinterpret_cast< char *>(&reg),sizeof(Cliente));
   while(!arch.eof())
   {
       if(reg.getCuenta()!=0)
       {
           cout<<left<<setw(10)<<reg.getCuenta()<<setw(20)<<reg.getNombre()<<setw(10)<<setprecision(2)<<fixed<<reg.getSaldo()<<endl;
       }
       arch.read(reinterpret_cast< char *>(&reg),sizeof(Cliente));
   }
   arch.close();
    return 0;
}
