#include "Producto.h"
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

Producto::Producto(int cod, string desc, int exis, int sMin,int sMax,float preRep)
{
    setCodigo(cod);
    setDescripcion(desc);
    setExistencia(exis);
    setStockMin(sMin);
    setStockMax(sMax);
    setPrecioRepo(preRep);
}
void Producto::setDescripcion(string desc)
{
    const char *dirDescripcion=desc.data();
    int longitud = desc.size();
    if(longitud>=100)
        longitud=99;
    strncpy(descripcion,dirDescripcion,longitud);
    descripcion[longitud] = '\0';
}
string Producto::getDescripcion()
{
    return descripcion;
}
void Producto::setCodigo(int c)
{
    codigo=c;
}
int Producto::getCodigo()
{
    return codigo;
}
void Producto::setExistencia(int e)
{
    existencia=e;
}
int Producto::getExistencia()
{
    return existencia;
}
void Producto::setStockMin(int sMin)
{
    stockMin=sMin;
}
int Producto::getStockMin()
{
    return stockMin;
}
void Producto::setStockMax(int sMax)
{
    stockMax=sMax;
}
int Producto::getStockMax()
{
    return stockMax;
}
void Producto::setPrecioRepo(float preR)
{
    precioRepo=preR;
}
float Producto::getPrecioRepo()
{
    return precioRepo;
}
void Producto::setEliminado(int el)
{
    eliminado = el;
}
int Producto::getEliminado()
{
    return eliminado;
}
