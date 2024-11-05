#ifndef ALL_H_
#define ALL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>

typedef struct line_matche
{
    int line;
    int nb_lines;
    int matche;
    int nb_matches;
    char **board;
    int status;
}line_matche;

void my_putchar(char c);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int my_putnbr(long long nb);
int my_strlen(char const *str);
void fill_board_frame(int nb_lines, char **board);
void fill_board_stick(int nb_lines, char **board);
char **alloc_board(int nb_lines);
void print_board(char **board, int nb_lines);
int my_getnbr(char const *str);
int handle_error(int ac, char **av);
int game_play(int nb_lines, int matches, char **board);
void update_board(char **board, int nb_lines, int line, int nb_matches);
int get_number(void);
line_matche verify_input(line_matche nb);
int ia(char **board, int nb_lines, int max_matche, int matche);
int count_stick(char **board, int line, int nb_lines);
int check_map(char **board, int nb_lines);
int game_loop(char **board, int nb_lines, int max_matches);

#endif
