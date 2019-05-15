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

int min_sqr(int i, int j, int x)
{
    int m = i;

    if (m > j){
        m = j;
    }
    if (m > x) {
        m = x;
    }
    return (m);
}

void print_my_sqr(char **tab, t_struct *square_detect)
{
    int tmp = square_detect->posy;

    for (int i = square_detect->size_sqr; i != 0; i--) {
        for (int j = 0; j < square_detect->size_sqr; j++) {
            tab[square_detect->posx][tmp] = 'x';
            tmp--;
        }
        tmp = square_detect->posy;
        square_detect->posx--;
    }
}

void pos_sqr(int **sqr, char **tab, t_struct *square_detect)
{
    int max_i = 0;
    int max_j = 0;
    int max_s;
    int i = 0;
    int j = 0;

    max_s = sqr[0][0];

    for (i = 0; i < square_detect->nb_line; i++) {
        for (j = 0; j < square_detect->nb_cols; j++) {
            if (max_s < sqr[i][j]) {
                max_s = sqr[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    square_detect->posx = max_i;
    square_detect->posy = max_j;
    print_my_sqr(tab, square_detect);
}

void test_file(char *buffer)
{
    if (buffer == NULL) {
        exit(84);
    }
}

void find_file(int fd)
{
    if (fd == -1)
        exit(84);
}