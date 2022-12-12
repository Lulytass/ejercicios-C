#include "Persona.h"
#include <string.h>
using namespace std;
Persona::Persona(int cod,string nom,int e)
{
    setCodigo(cod);
    setNombre(nom);
    setEdad(e);
}

void Persona::setCodigo(int cod)
{
    codigo = cod;
}

int Persona::getCodigo()
{
    return codigo;
}

void Persona::setNombre(string nom)
{
    const char *valorNombre = nom.data();
    int longitud = nom.size();
    if(longitud>=25)
        longitud=24;
    strncpy(nombre,valorNombre,longitud);
    nombre[longitud] = '\0';
}

string Persona::getNombre()
{
    return nombre;
}

void Persona::setEdad(int e)
{
    if(e<0)
        edad=0;
    else
        edad=e;
}

int Persona::getEdad()
{
    return edad;
}
