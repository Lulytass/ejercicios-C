#ifndef CLIENTE_H
#define CLIENTE_H
#include<string>
using namespace std;
class Cliente
{
    public:
        Cliente(int =0,string ="",float = 0.0);
        void setCuenta(int);
        int getCuenta();
        void setNombre(string);
        string getNombre();
        void setSaldo(float);
        float getSaldo();
    private:
        int cuenta;
        char nombre[25];
        float saldo;
};

#endif
