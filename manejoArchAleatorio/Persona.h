#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <string>
using namespace std;
class Persona
{
    public:
        Persona(int=0,string ="",int=0);
        void setEdad(int);
        int getEdad();
        void setNombre(string);
        string getNombre();
        void setCodigo(int);
        int getCodigo();
    private:
        int codigo,edad;
        char nombre[25];
};

#endif // PERSONA_H_INCLUDED
