#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <string>
using namespace std;

class Producto
{
    public:
    Producto(int=0, string="",int=0,int=0,int=0,float=0);
    void setCodigo(int);
    int getCodigo();
    void setExistencia(int);
    int getExistencia();
    void setStockMin(int);
    int getStockMin();
    void setStockMax(int);
    int getStockMax();
    void setPrecioRepo(float);
    float getPrecioRepo();
    void setDescripcion(string);
    string getDescripcion();
    void setEliminado(int);
    int getEliminado();
    private:
        int codigo, existencia, stockMin, stockMax, eliminado;
        float precioRepo;
        char descripcion[100];
};
#endif // PRODUCTO_H_INCLUDED
