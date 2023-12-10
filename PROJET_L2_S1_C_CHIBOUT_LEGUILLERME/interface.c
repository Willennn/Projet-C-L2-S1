//
// Created by Willen on 15/11/2023.
//
#include "interface.h"

#include "interface.h"
#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>

// Affiche les détails d'un contact.
void menu_display_contact(t_contact* contact) {
    printf("Nom : %s\n", contact->last_name);
    printf("Prenom : %s\n", contact->first_name);
}

// Ajoute un nouveau contact à la liste.
void menu_add_contact(t_input_list* input_list) {
    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    printf("Entrer le prenom du contact : ");
    char* first_name = scan_string();

    t_contact* contact = create_contact(first_name, last_name);
    insert_input(contact, input_list);
}


void menu_find_contact(t_input_list* input_list) {
    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    t_input* input = find_contact(last_name, input_list);

    if (input == NULL) {
        printf("Le contact n'existe pas.\n");
        return;
    } else {
        menu_display_contact(input->contact);
    }
}

void menu_display_all_contacts(t_input_list* input_list) {
    t_input* tmp = input_list->heads[0];

    if (tmp == NULL) {
        printf("Vous n'avez pas de contact.\n");
        return;
    }

    while (tmp != NULL) {
        menu_display_contact(tmp->contact);
        tmp = tmp->next;
    }
}



void menu_add_rdv(t_input_list* input_list) {

    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    t_input* input = find_contact(last_name, input_list);

    if(input == NULL) {
        printf("Le contact n'existe pas\n\n\n");
        return;
    }

    input = find_contact(last_name, input_list);

    printf("Entrer l'objet du rendez-vous : ");
    char* object = scan_string();

    printf("Entrer l'heure du rendez-vous : ");
    int hour;
    scanf("%d", &hour);

    printf("Entrer les minutes du rendez-vous : ");
    int minute;
    scanf("%d", &minute);


    printf("Entrer la date (jour) du rendez-vous : ");
    int day;
    scanf("%d", &day);

    printf("Entrer la date (mois) du rendez-vous : ");
    int month;
    scanf("%d", &month);


    printf("Entrer l'annee du rendez-vous : ");
    int year;
    scanf("%d", &year);

    t_rdv* rdv = create_rdv(object, hour, minute, day, month, year);

    insert_rdv(rdv, input);

    return;
}


void menu_display_rdv(t_input_list* input_list) {

    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    t_input* input = find_contact(last_name, input_list);

    if(input == NULL) {
        printf("Le contact n'existe pas.\n\n\n");
        return;
    }

    t_rdv* tmp = input->rdv;

    while(tmp != NULL) {
        printf("Objet : %s\n", tmp->object);
        printf("Heure : %d:%d\n", tmp->date_hour, tmp->date_minute);
        printf("Date : %d/%d/%d\n", tmp->date_day, tmp->date_month, tmp->date_year);
        tmp = tmp->next;
    }

    return;
}

int get_number_of_contacts(t_input_list* input_list) {
    int number_of_contacts = 0;

    for (int i = 0; i < input_list->max_level; i++) {
        t_input* tmp = input_list->heads[i];

        while (tmp != NULL) {
            number_of_contacts++;
            tmp = tmp->next;
        }
    }

    return number_of_contacts;
}
