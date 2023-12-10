//
// Created by Willen on 15/11/2023.
//


#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>

//  Cell  //

t_d_cell *create_cell(int value, int level) {
    // Creates a new cell with the given value and level.

    t_d_cell *cell = (t_d_cell*) malloc(sizeof(t_d_cell));

    cell->value = value;
    cell->level = level;
    cell->next = (t_d_cell**) malloc(sizeof(t_d_cell*) * level);

    for(int i = 0; i < level; i++) {
        cell->next[i] = NULL;
    }

    return cell;
}

void display_cell(t_d_cell* cell) {
    // Displays the contents of a cell.

    for(int i = 0; i < cell->level; i++) {
        printf("[ %d|@ ]-->\n", cell->value);
    }

    return;
}

//  List  //

t_d_list *create_list(int max_level) {
    // Creates a new list with the specified maximum level.

    t_d_list *list = (t_d_list*) malloc(sizeof(t_d_list));

    list->max_level = max_level;
    list->heads = (t_d_cell**) malloc(sizeof(t_d_cell*) * max_level);

    for(int i = 0; i < max_level; i++) {
        list->heads[i] = NULL;
    }

    return list;
}


void display_list(t_d_list* list) {

    for(int i = 0; i < list->max_level; i++) {
        printf("[list head_%d @-]--", i);
        t_d_cell *tmp = list->heads[i];
        t_d_cell *cursor = list->heads[0];

        while(cursor != NULL) {
            if(tmp == NULL) {
                printf("----------");
                cursor = cursor->next[0];
                continue;
            }
            if(cursor->value == tmp->value) {
                printf(">[ %d|@ ]--", tmp->value);
                tmp = tmp->next[i];
            } else {
                printf("----------");
            }
            cursor = cursor->next[0];
        }

        printf(">NULL\n");
    }
}


void insert_cell(int value, int level, t_d_list* list) {

    t_d_cell *cell = create_cell(value, level);

    for(int i = 0; i < level; i++) {
        if(list->heads[i] == NULL) {
            list->heads[i] = cell;
        } else {
            if(list->heads[i]->value > value) {
                cell->next[i] = list->heads[i];
                list->heads[i] = cell;
            } else {
                t_d_cell *tmp = list->heads[i];

                while(tmp->next[i] != NULL && tmp->next[i]->value < value) {
                    tmp = tmp->next[i];
                }

                cell->next[i] = tmp->next[i];
                tmp->next[i] = cell;
            }
        }
    }
    return;
}


t_d_cell* search_cell_classic(int value, t_d_list* list) {
    // La recherche commence au nv 0
    t_d_cell *tmp = list->heads[0];

    // parcourt de liste
    while (tmp != NULL && tmp->value < value) {
        tmp = tmp->next[0];
    }

    // Retourne l'élément si la valeur est correcte
    if (tmp != NULL && tmp->value == value) {
        return tmp;
    } else {
        return NULL;
    }
}


t_d_cell* search_cell_rapide(int value, t_d_list* list) {
    t_d_cell *temp = NULL;
    int i = list->max_level - 1;
    temp = list->heads[i];

    while (temp != NULL && temp->value != value && i >= 0) {
        if (temp->value > value) {--i;
            temp = list->heads[i];
        }
        else if (temp->value < value) {--i;
            temp = temp->next[i-1];
        }
    }

    if (temp != NULL && temp->value == value) {
        return temp;
    }

    return NULL;
}