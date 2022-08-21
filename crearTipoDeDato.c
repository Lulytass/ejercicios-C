#include <stdio.h>
#include <string.h>
typedef struct
{
    char nombre[30];
    int dni;
    float sueldo;
}datos;

void cargar(datos[], int);
void mostrar(datos[], int);
void ordenar(datos[], int);

int main()
{
    datos empleados[5];

    //INGRESAMOS LOS DATOS POR TECLADO
    cargar(empleados, 5);

    printf("SE MUESTRAN LOS DATOS CARGADOS\n");
    mostrar(empleados, 5);

    //ACOMODAMOS LOS DATOS POR DNI
    ordenar(empleados, 5);

    printf("\nMOSTRAMOS LOS DATOS ACOMODADOS\n");
    mostrar(empleados, 5);

    return 0;
}

void cargar(datos emp[],int tam)
{
    int i;
    for(i=0;i<tam;i++){
        printf("Ingrese el nombre del empleado: ");
        fflush(stdin);
        gets(emp[i].nombre);
        printf("Ingrese el DNI del empleado: ");
        scanf("%d", &emp[i].dni);
        printf("Ingrese el sueldo del empleado: ");
        scanf("%f", &emp[i].sueldo);
        printf("\n");
    }
}

void mostrar(datos emp[],int tam)
{
    int i;
    for(i=0;i<tam;i++){
        printf("Nombre: %s \nDNI: %d \nSueldo: %.2f \n", emp[i].nombre, emp[i].dni, emp[i].sueldo);
    }
}

void ordenar(datos emp[],int tam)
{
    int i,j;
    datos aux;
    for(i=0;i<tam-1;i++)
    for(j=i+1;j<tam;j++){
        if(emp[i].dni>emp[j].dni){
            aux= emp[i];
            emp[i]=emp[j];
            emp[j]=aux;
        }
    }
}
