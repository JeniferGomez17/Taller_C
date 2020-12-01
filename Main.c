#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM_MAXIMO 80
/*
 * Funciones para encriptar y desencriptar.
 */
void encrypt(char Message[100], int number);
void decrypt(char Message[100], int number);

char* ABC = "ABCDEFGHIJKLMN\xa5OPQRSTUVWXYZ";
char* abc = "abcdefghijklmn\xa4opqrstuvwxyz";

int longitud1;
char cadena [TAM_MAXIMO];
char *relleno = "A";
int x, i;
int op;
char caracter[1];
int lgcadena;

char cadena1[50];
int j;
char cadena2[50];
int lgcadena1;
int longCadena2;

int CadenasRepetidas(char* cadena1, char* cadena2) {
    char*busqueda = NULL;
    busqueda = strstr(cadena1, cadena2);
    int i = 0;
    while (busqueda != 0) {
        i++;
        busqueda = strstr(busqueda + 1, cadena2);
    }
    return i;

}

void encrypt(char Message[100], int number) {
    int i;
    char*p;
    for (i = 0; Message[i]; i++) {
        if (p = strchr(ABC, Message[i])) {
            Message[i] = ABC[(p - ABC + number) % 27];
        }
        if (p = strchr(abc, Message[i])) {
            Message[i] = abc[(p - abc + number) % 27];
        }
    }
    printf("\nEl mensaje encriptado es:\n%s\n", Message);
}

void decrypt(char Message[100], int number) {
    char*p;
    int i;
    for (i = 0; Message[i]; i++) {
        if (p = strchr(ABC, Message[i])) {
            Message[i] = ABC[(p - ABC - number + 27) % 27];
        }
        if (p = strchr(abc, Message[i])) {
            Message[i] = abc[(p - abc - number + 27) % 27];
        }

    }
    printf("\nEl mensaje desencriptado es:\n%s\n", Message);
}

void mainMenu() {
    char option;
    do {
        printf("\n<<<<MENU>>>\n\n "
               "1.Convetir en nombre propio el contendio de la cadena\n "
               "2.Contar el numero de veces que existe una palabra en una cadena\n "
               "3.Encriptar Cadena\n "
               "4.Desencriptar\n"
               " 5.Llenar acarcteres por izquierda o por derecha\n"
               " 6.Borrar caracteres de una cadena\n"
               " 7.Interseccion\n "
               "8.Diferencia entre dos cadenas\n "
               "9.Borrar caracteres izquierda o derecha\n "
               "Digite: [s/S]-Salir\n");
        scanf("%c", &option);
        getchar();
        fflush(stdin);
        switch (option) {
            case '1':
                printf("%s", "**Convetir en nombre propio el contendio de la cadena**\n");
                int i;
                char aux[300];
                char cadena[301];

                printf("Introduzca una cadena -> ");

                gets(aux);
                cadena[0] = ' ';
                for (i = 0; cadena[i] != '\0'; i++) {
                    cadena[i + 1] = aux[i];
                }
                for (i = 0; cadena[i] != '\0'; i++) {
                    if (cadena[i - 1] == ' ') {
                        cadena[i] = toupper(cadena[i]);
                    }
                    else {
                        cadena[i] = tolower(cadena[i]);
                    }
                }
                printf(" %s ", cadena);

                getchar();
                break;
            case '2':
                printf("%s", "**Contar el numero de veces que existe una palabra en una cadena**\n");
                char cadena1A [200];
                char cadena2A [200];
                printf("Digite la oracion: ");
                scanf("%[^\n]", &cadena1A);
                printf("Digite la palabra a hallar: ");
                scanf("%s", &cadena2A);
                printf("%d", CadenasRepetidas(&cadena1A, &cadena2A));
                break;
            case '3':
                printf("%s", "**Encriptar Cadena**\n");
                char cadenaS[100];
                printf("El algoritmo de encriptacion consiste en aumenta en 1 cada letra del mensaje ingresado\n");
                printf("Ingrese el mensaje: ");
                fflush(stdin);
                fgets(cadenaS, 100, stdin);
                encrypt(cadenaS, 1);
                break;
            case '4':
                printf("%s", "**Desencriptar**\n");
                printf("El algoritmo de desencriptacion consiste en disminuir en 1 cada letra del mensaje ingresado\n");
                printf("Ingrese el mensaje: ");
                fflush(stdin);
                fgets(cadenaS, 100, stdin);
                decrypt(cadenaS, 1);
                break;
            case '5':
                printf("Digite cuantas veces desea que se repita el carácter\n");
                scanf("%d", &longitud1);

                printf("Cadena a mostrar\n");
                scanf("%s", cadena);

                printf("¿Por donde desea llenar?\n1. Derecha\n2. Izquierda\nIngrese opción\n");
                scanf("%d", &op);

                if (op == 1) {
                    printf("%s", cadena);
                    for (x = 0; x < longitud1; x++) {
                        printf("%s", relleno);
                    }
                } else {
                    for (x = 0; x < longitud1; x++) {
                        printf("%s", relleno);
                    }
                    printf("%s", cadena);
                }
                break;
            case '6':

                printf("ingresa una cadena: \n");
                gets(cadena);
                lgcadena = strlen(cadena);

                printf("ingresa el carácter a eliminar: \n");
                gets(caracter);

                for (i = 0; i < lgcadena; i++) {
                    if (cadena[i] != 'o') {
                        putchar(cadena[i]);
                    }
                }
                break;
            case '7':
                printf("Ingresa una cadena: \n");
                gets(cadena1);
                lgcadena1 = strlen(cadena1);

                printf("Ingrese otra cadena: \n");
                gets(cadena2);
                longCadena2 = strlen(cadena2);

                for (i = 0; i < lgcadena1; i++) {
                    for (j = 0; j < longCadena2; j++) {
                        if (cadena1[i] == cadena2[j]) {
                            putchar(cadena2[j]);
                        }
                    }
                }
                break;
            case '8':
                printf("%s", "**Diferencia entre dos cadenas**\n");
                char cadena1[100];
                printf("Ingrese el mensaje: ");
                fflush(stdin);
                fgets(cadena1, 100, stdin);
                printf("%s\n", cadena1);
                int sizeCadenaUno = strlen(cadena1);
                printf("%d\n", sizeCadenaUno);

                char cadena2[200];
                printf("Cadena dos: ");
                fflush(stdin);
                fgets(cadena2, 100, stdin);
                printf("%s\n", cadena2);
                int sizeCadenaDos = strlen(cadena2);
                printf("%d\n", sizeCadenaDos);




                for (int i = 0; i < sizeCadenaUno; i++) {

                    for (int j = 0; j < sizeCadenaDos; j++) {

                        if (cadena2[j] == cadena1[i]) {

                            cadena1[i] = ' ';
                        }
                    }
                }


                printf("%s\n", cadena1);
                break;
            case '9':
                printf("%s", "**Borrar caracteres izquierda o derecha**\n");
                break;
        }
    } while (toupper(option) != 'S');

}

int main() {
    mainMenu();
    return (0);
}

