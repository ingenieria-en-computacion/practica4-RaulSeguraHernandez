#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    int *arr;

    arr = (int*)malloc(sizeof(int)*n);
    
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }
    

    printf("Ingrese %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("El arreglo es: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("] \n");

    
    return 0;
}
