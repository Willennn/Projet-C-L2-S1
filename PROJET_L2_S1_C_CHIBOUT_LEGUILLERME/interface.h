//
// Created by Willen on 15/11/2023.
//

#ifndef PROJET_L2_S1_C_CHIBOUT_LEGUILLERME_INTERFACE_H
#define PROJET_L2_S1_C_CHIBOUT_LEGUILLERME_INTERFACE_H


#include "fonctions.h"

void menu_add_contact(t_input_list* input_list);

void menu_find_contact(t_input_list* input_list);

void menu_add_rdv(t_input_list* input_list);

void menu_display_contact(t_contact* contact);

void menu_display_all_contacts(t_input_list* input_list);

void menu_display_rdv(t_input_list* input_list);

int get_number_of_contacts(t_input_list* input_list);


#endif //PROJET_L2_S1_C_CHIBOUT_LEGUILLERME_INTERFACE_H
