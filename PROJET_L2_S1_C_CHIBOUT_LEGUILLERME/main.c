#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

#include "fichier.h"
#include "fonctions.h"
#include "timer.h"
#include "interface.h"


int main() {
    t_input_list* MAIN_LIST = create_input_list(4);
    int run = 1;

    while (run == 1) {

        scanf("");

        printf("BIENVENUE DANS VOTRE AGENDA\n\n\n");
        printf("%d contacts dans la liste\n", get_number_of_contacts(MAIN_LIST));
        printf("1. Ajouter un contact\n");
        printf("2. Chercher un contact\n");
        printf("3. Afficher les contacts\n");
        printf("4. Ajouter un RDV\n");
        printf("5. Afficher les RDVs\n");
        printf("6. Prelever les RDVs\n");
        printf("7. Quitter\n");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                menu_add_contact(MAIN_LIST);
                break;
            }

            case 2: {
                menu_find_contact(MAIN_LIST);
                break;
            }

            case 3: {
                menu_display_all_contacts(MAIN_LIST);
                break;
            }

            case 4 : {
                menu_add_rdv(MAIN_LIST);
                break;
            }

            case 5: {
                menu_display_rdv(MAIN_LIST);
                break;
            }

            case 6: {printf("Fonctionnalite non disponible\n\n\n\n");
                break;
            }

            case 7: {
                run = 0;
                break;
            }

            default: {

                printf("Commande impossible\n");
                break;
            }
        }
    }

    return 0;
}