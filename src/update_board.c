#include "../includes/all.h"

void update_board(char **board, int nb_lines, int line, int nb_matches)
{
    int i = (nb_lines * 2) - 1;
    int j;

    while (board[line][i] != '|')
        i--;
    j = nb_matches;
    for (; j > 0; j--) {
        if (board[line][i] != '*')
        board[line][i] = ' ';
        i--;
    }
    print_board(board, nb_lines);
}
