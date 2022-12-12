#include "Cliente.h"
#include <string.h>
#include<iostream>
using namespace std;
#include<string>

Cliente::Cliente(int cta,string nom,float s)
{
    setCuenta(cta);
    setNombre(nom);
    setSaldo(s);
}

void Cliente::setCuenta(int cta)
{
    cuenta = cta;
}

int Cliente::getCuenta()
{
    return cuenta;
}

void Cliente::setBorrado(int b)
{
    borrado = b;
}

int Cliente::getBorrado()
{
    return borrado;
}

void Cliente::setNombre(string nom)
{
    const char *valorNombre = nom.data();
    int longitud = nom.size();
    if(longitud>=25)
        longitud = 24;
    strncpy(nombre,valorNombre,longitud);
    nombre[longitud] = '\0';
}

string Cliente::getNombre()
{
    return nombre;
}

void Cliente::setSaldo(float s)
{
    saldo = s;
}

float Cliente::getSaldo()
{
    return saldo;
}
