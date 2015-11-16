#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRLEN 255
#define PATHFILE "passwd.txt"

struct s_record{
    char    userName[MAX_STRLEN];
    char    userEmail[MAX_STRLEN];
    char    site[MAX_STRLEN];
    char    password[MAX_STRLEN];
};
typedef struct s_record record;

int main(int argc, char** argv) {
    int option;
    char sito[MAX_STRLEN];
    FILE *pFile;
    record elemento;
    
    pFile = fopen(PATHFILE, "r+");
    if(pFile == NULL) {
        printf("CREAZIONE NUOVO FILE ...\n");
        pFile = fopen(PATHFILE, "w+");
        if(pFile == NULL){
            printf("IMPOSSIBILE CREARE NUOVO FILE\n");
            exit(1);
        }
    }
    
    printf("\nOPZIONI DISPONIBILI:\n1.  AGGIUNGI PASSWORD\n2.   LEGGI PASSWORD\nInserisci l'opzione desiderata: ");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            option = 1;
            while(option) {
            printf("\nNUOVA PASSWORD\n");
            printf("User Name: ");
            scanf("%s", elemento.userName);
            printf("Email: ");
            scanf("%s", elemento.userEmail);
            printf("Sito: ");
            scanf("%s", elemento.site);
            printf("Password: ");
            scanf("%s", elemento.password);
            fprintf(pFile,  "Site: %s\n"
                            "\tUserName: %s\n"
                            "\tEmail: %s\n"
                            "\tPassword: %s\n\n",
                    elemento.site,
                    elemento.userName,
                    elemento.userEmail,
                    elemento.password);
            printf("PASSWORD SALVATA\n\n");
            printf("Inserire un'altra password (Sì -> 1 | No -> 0)  ");
            scanf("%d", &option);
            }
            break;
            
        case 2:
            option = 1;
            while(option) {
                printf("RICERCA PASSOWORD\nSito: ");
                scanf("%s", sito);
                rewind(pFile);
                while(!(feof(pFile))) {
                    fscanf(pFile,  "Site: %s\n"
                            "\tUserName: %s\n"
                            "\tEmail: %s\n"
                            "\tPassword: %s \n\n",
                    elemento.site,
                    elemento.userName,
                    elemento.userEmail,
                    elemento.password);
                    if(!(strcmp(sito, elemento.site))) {
                        printf("Sito: %s\n"
                            "\tUserName: %s\n"
                            "\tEmail: %s\n"
                            "\tPassword: %s \n\n",
                    elemento.site,
                    elemento.userName,
                    elemento.userEmail,
                    elemento.password);
                    }
                }
                printf("Avviare un'altra ricerca (Sì -> 1 | No -> 0)  ");
                scanf("%d", &option);
                
            }
            break;
            
        default: printf("OPZIONE ANCORA NON DISPONIBILE");
                    
                
    }
    return (EXIT_SUCCESS);
}

