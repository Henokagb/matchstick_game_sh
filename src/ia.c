#include "../includes/all.h"

int remove_stick(char **board, int line, int nb_lines, int max_matche)
{
    int stick = count_stick(board, line, nb_lines);

    if (stick <= max_matche) {
        if ((stick - 1) != 0)
            return (stick - 1);
    }
    else
        return (-1);
}

int check_map(char **board, int nb_lines)
{
    int i;
    int j;

    for (i = 0; i < nb_lines + 2; i++)
        for (j = 0; j < (nb_lines * 2)+ 1; j++)
            if (board[i][j] == '|')
                return (0);
    return (84);
}

int count_stick(char **board, int line, int nb_lines)
{
    int i;
    int nb = 0;

    for (i = 0; i < (nb_lines * 2) + 1; i++)
        if (board[line][i] == '|')
            nb++;
    return (nb);
}

int ia(char **board, int nb_lines, int max_matche, int matche)
{
    int i = (random()%nb_lines + 1);
    int j = 0;

    while (i == 0 || count_stick(board, i, nb_lines) == 0)
        i = (random()%nb_lines + 1);
    j = remove_stick(board, i, nb_lines, max_matche);
    if (j == -1) {
        j = (random()%max_matche + 1);
        while (j == 0 || j > count_stick(board, i, nb_lines))
            j = (random()%max_matche + 1);
    }
    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_putnbr(j);
    my_putstr(" match(es) from line ");
    my_putnbr(i);
    my_putchar('\n');
    update_board(board, nb_lines, i, j);
    if (check_map(board, nb_lines) == 84)
        return (84);
    return (0);
}
