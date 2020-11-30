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
                char cadena[100];
                printf("El algoritmo de encriptacion consiste en aumenta en 1 cada letra del mensaje ingresado\n");
                printf("Ingrese el mensaje: ");
                fflush(stdin);
                fgets(cadena, 100, stdin);
                encrypt(cadena, 1);
                break;
            case '4':
                printf("%s","**Desencriptar**\n");
                 printf("El algoritmo de desencriptacion consiste en disminuir en 1 cada letra del mensaje ingresado\n");
                printf("Ingrese el mensaje: ");
                fflush(stdin);
                fgets(cadena, 100, stdin);
                decrypt(cadena, 1);
                break;
            case '5':               
                printf("Digite cuantas veces desea que se repita el carácter\n");
                scanf("%d", &longitud1);

                printf("Cadena a mostrar\n");
                scanf("%s", cadena);

                printf("¿Por donde desea llenar?\n1. Derecha\n2. Izquierda\nIngrese opción\n");
                scanf("%d", &op);

                if(op == 1){
                    printf("%s", cadena);
                    for(x = 0; x < longitud1; x++){
                        printf("%s", relleno);
                    }
                }else{
                    for(x = 0; x < longitud1; x++){
                        printf("%s", relleno);
                    }
                    printf("%s", cadena);
                }
                break;
            case '6':
                
    			printf("ingresa una cadena: \n");
    		    gets(cadena);
    			lgcadena=strlen(cadena);
    
    			printf("ingresa el carácter a eliminar: \n");
    			gets(caracter);
    
				for (i = 0; i < lgcadena; i++) {		
     				if (cadena[i] != 'o') {
         				putchar(cadena[i]);
    	 			}	
				}
				break;
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




