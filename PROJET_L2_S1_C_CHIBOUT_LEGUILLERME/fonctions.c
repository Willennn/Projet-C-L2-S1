//
// Created by Willen on 30/11/2023.
//

#include "fonctions.h"


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "fonctions.h"

/*  Outils  */

char* scan_string() {

    int max_size = 100;

    char* string = (char*) malloc(sizeof(char) * max_size);
    scanf("%s", string);

    return string;
}

char* get_name_formatted(t_contact* contact) {
    // Alloue de la mémoire pour une nouvelle chaîne de caractères
    char* name = (char*) malloc(sizeof(char) * (strlen(contact->last_name) + strlen(contact->first_name) + 2));
    // +2 pour le tiret bas et le caractère nul

    // Copie le nom de famille dans la nouvelle chaîne et le converti en minuscules
    for(int i = 0; i < strlen(contact->last_name); i++) {
        name[i] = tolower(contact->last_name[i]);
    }
    name[strlen(contact->last_name)] = '\0';

    // Ajoute un underscore
    strncat(name, "_", 1);

    // Ajoute le prénom et le converti en minuscules
    for(int i = 0; i < strlen(contact->first_name); i++) {
        name[strlen(contact->last_name) + 1 + i] = tolower(contact->first_name[i]);
    }

    // Assure que la chaîne est terminée par null
    name[strlen(contact->last_name) + strlen(contact->first_name) + 1] = '\0';

    return name;
}

int is_name_before(char* str1, char* str2) {
    // Vérifie si str1 est avant str2 alphabétiquement
    // Vérifie 1 si vrai, 0 si faux
    int i = 0;
    int j = 0;

    while(str1[i] != '\0' && str2[j] != '\0') {

        if(str1[i] < str2[j]) {
            return 1;
        } else if(str1[i] > str2[j]) {
            return 0;
        }

        i++;
        j++;
    }

    if(str1[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

t_input * find_contact(char* last_name, t_input_list* list) {

    // Cherche le contact dans la liste
    // Retourne les informations s'il le trouve, sinon NULL

    for(int i = 0; i < list->max_level; i++) {

        t_input* tmp = list->heads[i];

        while(tmp != NULL) {

            if(strcmp(tmp->contact->last_name, last_name) == 0) {
                return tmp;
            }

            tmp = tmp->next;
        }

    }

    return NULL;

}

/*  Contacts  */


t_contact* create_contact(char* first_name, char* last_name) {

    t_contact* contact = (t_contact*) malloc(sizeof(t_contact));

    contact->last_name = last_name;
    contact->first_name = first_name;

    return contact;

}


/*  RDV  */


t_rdv* create_rdv(char* object, int date_hour, int date_minute, int date_day, int date_month, int date_year) {

    t_rdv* rdv = (t_rdv*) malloc(sizeof(t_rdv));

    rdv->object = object;
    rdv->date_hour = date_hour;
    rdv->date_minute = date_minute;
    rdv->date_day = date_day;
    rdv->date_month = date_month;
    rdv->date_year = date_year;
    rdv->next = NULL;

    return rdv;
}


t_input* create_input(t_contact* contact, int level) {

    t_input* input = (t_input*) malloc(sizeof(t_input));

    input->contact = contact;
    input->rdv = NULL;
    input->next = NULL;
    input->level = level;

    return input;
}


t_input_list* create_input_list(int level) {

    t_input_list * input_list = (t_input_list*) malloc(sizeof(t_input_list));

    input_list->heads = (t_input **) malloc(sizeof(t_input*) * level);
    input_list->max_level = level;

    for(int i = 0; i < level; i++) {
        input_list->heads[i] = NULL;
    }

    return input_list;
}


void insert_rdv(t_rdv* rdv, t_input* input) {

    rdv->next = input->rdv;
    input->rdv = rdv;

    return;

}

void insert_input(t_contact * contact, t_input_list* list) {

    // Vérifie si le contact est déjà dans la liste
    char* name = get_name_formatted(contact);

    for(int i = 0; i < list->max_level; i++) {

        t_input* tmp = list->heads[i];

        while(tmp != NULL) {

            if(strcmp(get_name_formatted(tmp->contact), name) == 0) {
                printf("Contact already in the list\n");
                return;
            }

            tmp = tmp->next;
        }

    }

    // Insère le contact dans la liste dans l'ordre alphébétique au niveau 0
    t_input* input = create_input(contact, 0);

    if(list->heads[0] == NULL) {
        list->heads[0] = input;
        return;
    }

    if(is_name_before(name, get_name_formatted(list->heads[0]->contact))) {
        input->next = list->heads[0];
        list->heads[0] = input;
        return;
    }

    t_input* tmp = list->heads[0];

    while(tmp->next != NULL && is_name_before(get_name_formatted(tmp->next->contact), name)) {
        tmp = tmp->next;
    }

    input->next = tmp->next;
    tmp->next = input;

    return;
}

void display_input_list(t_input_list* list) {

    for(int i = 0; i < list->max_level; i++) {

        printf("[list head_%d @-]-->", i);
        t_input *tmp = list->heads[i];


        while(tmp != NULL) {

            printf("[ %s|@ ]-->", tmp->contact->last_name);
            tmp = tmp->next;
        }

        printf("NULL\n");

    }

}