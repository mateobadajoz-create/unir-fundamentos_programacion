#include <stdio.h>

#define TAM_TABLERO 12   /* tablero 12x12 */

/* Estructura */
typedef struct {
    char pos[TAM_TABLERO][TAM_TABLERO];  /* posiciones del tablero */
} Tablero;

/* Funciones */
void mostrarMenu();
void jugar();
void inicializarTableros(Tablero *j1, Tablero *j2);
void inicializarTablero(Tablero *t);
void colocarBarcos(Tablero *t);
void mostrarTablero(const Tablero *t);
void mejoresPuntuaciones();
void ejecutarPartida(Tablero *j1, Tablero *j2);

int main(void) {
    //Menú inicial
    int opcion;
    int salir = 0;

    while (!salir) {
        mostrarMenu();
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            jugar();                   
            break; /* Solo se inicializan y se muestran los dos tableros por pantalla. */
        case 2:
            mejoresPuntuaciones();     /* TODO */
            break;
        case 3:
            printf("Hasta otra!\n");  /* Salir del juego */
            salir = 1;
            break;
        default:
            break;
        }
    }

    return 0;
}

/* Muestra el menú principal exactamente con las tres opciones pedidas */
void mostrarMenu() {
    printf("=============================================== HUNDIR LA FLOTA ===========================================\n");
    printf("1. Jugar\n");
    printf("2. Mejores puntuaciones\n");
    printf("3. Salir\n");
    printf("===========================================================================================================\n");
}

/* Opcion Jugar:
   - inicializar tableros 
   - colocar barcos 
   - mostrar tableros
   - TODO...
*/
void jugar() {
    printf("\n--------------------------------------------- INICIO DEL JUEGO ---------------------------------------------\n");
    //Inicializo tableros
    Tablero tableroJugador1;
    Tablero tableroJugador2;
    inicializarTableros(&tableroJugador1, &tableroJugador2);

    //Coloco los barcos
    colocarBarcos(&tableroJugador1);
    colocarBarcos(&tableroJugador2);

    //Muestro los tableros
    printf("\n----------------------------------Jugador 1:----------------------------------\n");
    mostrarTablero(&tableroJugador1);
    printf("\n----------------------------------Jugador 2:----------------------------------\n");
    mostrarTablero(&tableroJugador2);

    //Aquí llamaría a la subrutina que ejecuta la partida, pero no pedís hacerla.
    ejecutarPartida(&tableroJugador1, &tableroJugador2);

    printf("\n");
}

/* Inicializa ambos tableros */
void inicializarTableros(Tablero *j1, Tablero *j2) {
    inicializarTablero(j1);
    inicializarTablero(j2);
}

/* Rellena un tablero con agua ('~') */
void inicializarTablero(Tablero *t) {
    int x, y;
    for (x = 0; x < TAM_TABLERO; x++) {
        for (y = 0; y < TAM_TABLERO; y++) {
            t->pos[x][y] = '~';
        }
    }
}

/* barcos en posiciones fijas:
    '0' para barco.
   - 1 portaviones (4 posiciones)
   - 2 cruceros (3 posiciones cada uno)
   - 3 patrulleros (2 posiciones cada uno)
   
*/
//Imagino que cuando toque la actividad 3, no serán fijas. Aquí ambos tableros les pongo las mismas posiciones
void colocarBarcos(Tablero *t) {
    /* Portaviones (4 posiciones) */
    t->pos[0][5] = '0';
    t->pos[0][6] = '0';
    t->pos[0][7] = '0';
    t->pos[0][8] = '0';

    /* Crucero 1 (3 posiciones) */
    t->pos[2][1] = '0';
    t->pos[2][2] = '0';
    t->pos[2][3] = '0';

    /* Crucero 2 (3 posiciones) */
    t->pos[5][5] = '0';
    t->pos[5][6] = '0';
    t->pos[5][7] = '0';

    /* Patrullero 1 (2 posiciones) */
    t->pos[7][3] = '0';
    t->pos[7][4] = '0';

    /* Patrullero 2 (2 posiciones) */
    t->pos[8][8] = '0';
    t->pos[8][9] = '0';

    /* Patrullero 3 (2 posiciones) */
    t->pos[10][1]  = '0';
    t->pos[10][2] = '0';
}

/* Muestra un tablero por consola */
void mostrarTablero(const Tablero *t) {
    int x, y;

    /* índice columnas */
    printf("   ");
    for (y = 0; y < TAM_TABLERO; y++) {
        printf("%d ", y);
    }
    printf("\n");

    /* separador */
    printf("  ");
    for (y = 0; y < TAM_TABLERO; y++) {
        printf("--");
    }
    printf("-\n");

    /* índice xs */
    for (x = 0; x < TAM_TABLERO; x++) {
        printf("%2d|", x);
        for (y = 0; y < TAM_TABLERO; y++) {
            printf("%c ", t->pos[x][y]);
        }
        printf("\n");
    }
}

/* no implementada ...TODO */
void mejoresPuntuaciones() {
    printf("\n[Mejores puntuaciones]---> Está para la actividad 3 ...TODO\n");
    printf("\n...volviendo al menú principal\n");
}

/* no implementada ...TODO */
void ejecutarPartida(Tablero *j1, Tablero *j2) {
    printf("\n[Jugar] -----------------> Está para la actividad 3 ...TODO\n");
    printf("\n...volviendo al menú principal\n");
}
