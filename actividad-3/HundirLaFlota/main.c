#include <stdio.h>

/* Incluimos directamente el módulo ranking */
#include "ranking.c"

int main(void) {
    int opcion;
    int turnos;

    do {
        printf("====== PRUEBA RANKING ======\n");
        printf("1. Añadir puntuación (simular victoria)\n");
        printf("2. Mostrar mejores puntuaciones\n");
        printf("3. Salir\n");
        printf("============================\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Introduce número de turnos: ");
            scanf("%d", &turnos);
            guardarPuntuacion(turnos);
            printf("Puntuación guardada.\n\n");
            break;

        case 2:
            mostrarMejoresPuntuaciones();
            break;

        case 3:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opción no válida.\n\n");
            break;
        }

    } while (opcion != 3);

    return 0;
}