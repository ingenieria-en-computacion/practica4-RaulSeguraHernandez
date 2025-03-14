#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crea un tipo de dato estudiante que guarde el nombre del estudiante max. 40 caracteres y su edad
typedef struct {
    char nombre[41]; //haciendo espacio para el fin de cadena//
    int edad;
} Estudiante;

int main() {

    int size = 2;

    Estudiante* arr = (Estudiante*)malloc(sizeof(Estudiante)*size);
    // Crea un arreglo dinámico usando malloc de tamaño size
    //Si el arreglo es nulo imprime el mensaje
    if ( arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    char nombre[50];
    int edad;
    printf("Ingrese estudiantes (nombre y edad, ingrese 'fin' para terminar):\n");
    while (1) {
        printf("Nombre: ");
        scanf("%s", nombre);
        if (strcmp(nombre, "fin") == 0){
            break;
        }
        printf("Edad: ");
        scanf("%d", &edad);

        if (count >= size) {
            size *= 2;
            //Cambia el tamaño del arreglo
            arr = (Estudiante*)realloc(arr,sizeof(Estudiante)*size);
            //Verifica nuevamente que si apunta a nulo se imprima el error
            if ( arr== NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
            
        }
        strcpy(arr[count].nombre, nombre);
        arr[count].edad=edad;

        //copia el nombre leido en el nuevo estudiante y su edad
        
        count++;
    }

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < count; i++) {
        printf("%s ,%d\n", arr[i].nombre, arr[i].edad );
    }

    //libera la memoria
    free(arr);
    return 0;
}
