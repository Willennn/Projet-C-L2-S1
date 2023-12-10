//
// Created by Willen on 15/11/2023.
//

#ifndef PROJET_L2_S1_C_CHIBOUT_LEGUILLERME_FONCTIONS_H
#define PROJET_L2_S1_C_CHIBOUT_LEGUILLERME_FONCTIONS_H


typedef struct s_contact
{
    char* first_name;
    char* last_name;

} t_contact;

typedef struct s_rdv
{
    char* object;
    int date_hour;
    int date_minute;
    int date_day;
    int date_month;
    int date_year;
    struct s_rdv *next;

} t_rdv;

typedef struct s_input
{
    t_contact* contact;
    t_rdv* rdv;

    struct s_input *next;
    int level;

} t_input;

typedef struct s_input_list
{
    int max_level;
    t_input **heads;

} t_input_list;


t_rdv* create_rdv(char*, int, int, int, int, int);

void insert_rdv(t_rdv*, t_input *);

int is_name_before(char*, char*);

t_input * find_contact(char*, t_input_list*);

t_contact* create_contact(char*, char*);

t_input* create_input(t_contact*, int);

t_input_list* create_input_list(int);

void insert_input(t_contact *, t_input_list*);

void display_input_list(t_input_list*);

char* scan_string();

char* get_name_formatted(t_contact*);

#endif //PROJET_L2_S1_C_CHIBOUT_LEGUILLERME_FONCTIONS_H
