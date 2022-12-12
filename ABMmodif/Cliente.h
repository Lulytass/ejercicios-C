#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <string>
using namespace std;
class Cliente
{
    public:
        Cliente(int =0,string ="",float = 0.0);
        void setCuenta(int);
        int getCuenta();
        void setBorrado(int);
        int getBorrado();
        void setNombre(string);
        string getNombre();
        void setSaldo(float);
        float getSaldo();
    private:
        int cuenta,borrado;
        char nombre[25];
        float saldo;

};

#endif // CLIENTE_H_INCLUDED
