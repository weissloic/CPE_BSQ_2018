/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char **double_array(char *buffer, t_struct *square_detect)
{
    char **tab = malloc(sizeof(char *) * square_detect->nb_line);
    int line = 0;
    int cols = 0;

    for (int i = 0; i < square_detect->nb_line; i++) {
        tab[i] = malloc(sizeof(char) * square_detect->nb_cols + 1);
    }
    for (int j = 0; buffer[j] != 0; j++) {
        if (buffer[j] == '\n') {
            tab[line][cols] = 0;
            line++;
            cols = 0;
        } else {
            tab[line][cols] = buffer[j];
            cols++;
        }
    }
    return (tab);
}

int **sqr_stock_bin(char **tab, t_struct *square_detect)
{
    int **sqr = malloc(sizeof(int *) * square_detect->nb_line + 1);

    for (int i = 0; i < square_detect->nb_line; i++) {
        sqr[i] = malloc(sizeof(int) * square_detect->nb_cols + 1);
    }

    for (int j = 0; j < square_detect->nb_line; j++) {
        for (int e = 0; e < square_detect->nb_cols; e++) {
            if (tab[j][e] != 'o') {
                sqr[j][e] = 1;
            } else
                sqr[j][e] = 0;
        }
    }
    return (sqr);
}

int **find_sqr(int **sqr, t_struct *square_detect)
{
    int result = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < square_detect->nb_cols; i++) {
        for (j = 0; j < square_detect->nb_line; j++) {
            if (i == 0 || j == 0) {
            } else if (sqr[i][j] > 0) {
                sqr[i][j] = 1 + min_sqr(sqr[i][j-1], sqr[i-1][j],
                    sqr[i-1][j-1]);
            }
            if (sqr[i][j] > result)
                result = sqr[i][j];
        }
    }
    square_detect->size_sqr = result;
    return (sqr);
}

int buffer_nb_line(char const *buffer)
{
    int j = 0;
    int counter = 0;
    char *str;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            j++;
    }
    return (j);
}

int buffer_nb_cols(char const *buffer)
{
    int i = 0;
    int j = 0;
    int counter = 0;
    char *str;

    for (int i = 0; buffer[i] != '\n'; i++) {
        j++;
    }
    return (j);
}