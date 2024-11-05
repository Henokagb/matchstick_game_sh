#include "../includes/all.h"
#include "../includes/all.h"

void fill_board_frame(int nb_lines, char **board)
{
    int a;
    int i;
    int j;
    int k;

    for (i = 0; i < (nb_lines * 2) + 1; i++)
        board[0][i] = '*';
    for (j = 1; j < nb_lines + 1; j++) {
        board[j][0] = '*';
        for (a = 1; a < nb_lines * 2; a++)
            board[j][a] = ' ';
        board[j][(nb_lines * 2)] = '*';
    }
    for (k = 0; k < (nb_lines * 2) + 1; k++)
        board[nb_lines + 1][k] = '*';
}

void loop(int begin, int end, int line, char **board)
{
    while (begin < end) {
            board[line][begin] = '|';
            begin++;
    }
}

void fill_board_stick(int nb_lines, char **board)
{
    int begin = 1;
    int end = nb_lines * 2;
    int i = nb_lines;
    int a = begin;

    for (; i > 0; i--) {
        loop(begin, end, i, board);
        begin++;
        end--;
    }
}

char **alloc_board(int nb_lines)
{
    int i;
    char **tab;

    tab = malloc(sizeof(char *) * nb_lines + 2);
    for (i = 0; i < nb_lines + 2; i++)
        tab[i] = malloc(sizeof(char) * (nb_lines * 2) + 1);
    fill_board_frame(nb_lines, tab);
    fill_board_stick(nb_lines, tab);
    return (tab);
}

void print_board(char **board, int nb_lines)
{
    int i;
    int j;

    for (i = 0; i < nb_lines + 2; i++) {
        for (j = 0; j < (nb_lines * 2)+ 1; j++)
            my_putchar(board[i][j]);
        my_putchar('\n');
    }
}
