/*
** EPITECH PROJECT, 2018
** assignement 1
** File description:
** assignement 1
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void print_my_map(char **tab, t_struct *square_detect)
{
    for (int i = 0; i < square_detect->nb_line; i++) {
        write(1, tab[i], square_detect->nb_cols);
        my_putchar('\n');
    }
}

void print_all(char *buffer, char **tab, int **sqr, t_struct *square_detect)
{
    square_detect->nb_cols = buffer_nb_cols(buffer);
    square_detect->nb_line = buffer_nb_line(buffer);
    tab = double_array(buffer, square_detect);
    sqr = sqr_stock_bin(tab, square_detect);
    sqr = find_sqr(sqr, square_detect);
    pos_sqr(sqr, tab, square_detect);
    print_my_map(tab, square_detect);
}

void bsq_function(char const *filepath)
{
    t_struct *square_detect = malloc(sizeof(t_struct));
    int fd;
    int taille_nbr = 0;
    struct stat st;
    stat(filepath, &st);
    int size = st.st_size;
    char *buffer = malloc(sizeof(char) * size + 1);
    char **tab = NULL;
    int **sqr;

    buffer[size] = '\0';
    fd = open(filepath, O_RDONLY);
    find_file(fd);
    read(fd, buffer, size);
    for (; buffer[taille_nbr] != '\n'; taille_nbr++);
    for (int del = 0; del <= taille_nbr; del++)
        buffer++;
    test_file(buffer);
    print_all(buffer, tab, sqr, square_detect);
}

int main(char argc, char *argv[])
{
    if (argc != 2)
        return (84);
    bsq_function(argv[1]);
    return (0);
}