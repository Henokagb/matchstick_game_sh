#include "../includes/all.h"


int main(int ac, char **av)
{
    int lines;
    char **board;
    int return_value = 0;

    if (handle_error(ac, av) == 84)
        return (84);
    lines = my_getnbr(av[1]);
    board = alloc_board(lines);
    print_board(board, lines);
    return_value = game_loop(board, lines, my_getnbr(av[2]));
    if (return_value == 1) {
        free(board);
        return (1);
    }
    else if (return_value == 2){
        free(board);
        return (2);
    }
    free(board);
    return (0);
}
