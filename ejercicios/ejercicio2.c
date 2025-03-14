#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int m, n;
    printf("Ingrese el número de filas: ");
    scanf("%d", &m);
    
    
    printf("Ingrese el número de columnas: ");
    scanf("%d", &n);

    int *matrix = (int *)calloc(m * n, sizeof(int));
    if (matrix == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    printf("Matriz inicializada con ceros:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(matrix +j +n*i));
        }
        printf("\n");
    }

    printf("Ingrese las coordenadas (fila, columna) y el valor para modificar (ej. 1 2 5):\n");
    int row, col, value;
    //lee los varlores solicitados
    char input[100];
    while(getchar()!='\n');
    //despues de preguntar por qué no funcionaba a mi padre, me dijo que añadiera esta línea para que fgets no leyera el caracter de nueva linea que deja scanf//
    fgets(input, sizeof(input), stdin);
    row = atoi(strtok(input, " "));
    col = atoi(strtok(NULL, " "));
    value = atoi(strtok(NULL, " " ));
    matrix[(row-1) * n + (col-1)] = value;

    printf("Matriz actualizada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(matrix +j +n*i));
        }
        printf("\n");
    }
    
    free(matrix);
    return 0;
}
