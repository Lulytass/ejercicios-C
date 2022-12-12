#include <iostream>
#include "Cliente.h"
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    ofstream arch;
    arch.open("cuentas3.dat",ios::out | ios::binary);
    if(!arch)
    {
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    Cliente reg;
    for (int i=0;i<100;i++)
        arch.write(reinterpret_cast<const char *>(&reg),sizeof(Cliente));
    arch.close();
    return 0;
}
