//
// Created by Willen on 15/11/2023.
//

#ifndef PROJET_L2_S1_C_CHIBOUT_LEGUILLERME_FICHIER_H
#define PROJET_L2_S1_C_CHIBOUT_LEGUILLERME_FICHIER_H



typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell **next;

} t_d_cell;

typedef struct s_d_list
{

    int max_level;
    t_d_cell **heads;

} t_d_list;

t_d_list* create_list(int);
t_d_cell* create_cell(int, int);

void display_cell(t_d_cell*);
void display_list(t_d_list*);

void insert_cell(int, int, t_d_list*);
t_d_cell* search_cell_classic(int value, t_d_list* list);
t_d_cell* search_cell_rapide(int value, t_d_list* list);


#endif //PROJET_L2_S1_C_CHIBOUT_LEGUILLERME_FICHIER_H
