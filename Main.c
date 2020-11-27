#include <stdio.h>

/*
 * Funciones para validación de datos.
 */

void mainMenu(){
    char option;
    do{
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
        scanf("%c",&option);
        getchar();
        fflush(stdin);
        switch (option) {
            case '1':
                printf("%s","**Convetir en nombre propio el contendio de la cadena**\n");
                break;
            case '2':
                printf("%s","**Contar el numero de veces que existe una palabra en una cadena**\n");            
                break;
            case '3':
                printf("%s","**Encriptar Cadena**\n");
                break;
            case '4':
                printf("%s","**Desencriptar**\n");
                break;
            case '5':
                printf("%s","**Llenar acarcteres por izquierda o por derecha**\n");
                break;
            case '6':
                printf("%s","**Borrar caracteres de una cadena**\n");
            case '7':
                printf("%s","**Interseccion**\n"); 
                break;
            case '8':
                printf("%s","**Diferencia entre dos cadenas**\n"); 
                break;
            case '9':
                printf("%s","**Borrar caracteres izquierda o derecha**\n"); 
                break;
        }
    }while (toupper(option) != 'S');

}

int main() {       
    mainMenu();
    return (0);
}
