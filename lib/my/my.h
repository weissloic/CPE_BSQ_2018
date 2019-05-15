/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my_h
*/

#ifndef MY_LIST_H_
#define MY_LIST_H_

typedef struct square {
    int nb_cols;
    int nb_line;
    int posx;
    int posy;
    int size_sqr;
} t_struct;

char *my_strcat(char *dest, char const *src);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_compute_power_it(int nb, int p);
int my_print_params(int argc, char **argv);
int my_show_word_array(char * const *tab);

char **double_array(char *buffer, t_struct *);
int buffer_nb_line(char const *);
int buffer_nb_cols(char const *);
int min_sqr(int, int, int);
void pos_sqr(int **, char **, t_struct *);
int **sqr_stock_bin(char **, t_struct *);
int **find_sqr(int **, t_struct *);
void fs_cat_500_bytes(char const *);
void test_file(char *buffer);

#endif