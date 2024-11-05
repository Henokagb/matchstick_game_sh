#include "../includes/all.h"
#include "../includes/macros.h"

int get_number(void)
{
    int i;
    size_t length = 10;
    char *buf = malloc(sizeof(char) * 10);
    size_t instruct;

    if (getline(&buf, &length, stdin) == -1)
        return (-99999);
    if (buf[0] == '\n') {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (84);
    }
    for (i = 0; buf[i] != '\n'; i++)
        if (buf[i] < '0' || buf[i] > '9') {
            write(1, "Error: invalid input (positive number expected)\n", 48);
            return (84);
        }
    return (my_getnbr(buf));
}

int game_loop(char **board, int nb_lines, int max_matches)
{
    DECLARATION()
    while (1) {
        my_putstr("\nYour turn:\n");
        while (1) {
            status = verify_input(nb);
            if (status.status == 0)
                break;
            else if (status.status == -1)
                return (-1);
        }
        update_board(board, status.nb_lines, status.line, status.matche);
        if (check_map(board, nb_lines) == 84) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        if (ia(board, nb_lines, max_matches, status.matche) == 84) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
}

int handle_error(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[2]) <= 0 ||
        my_getnbr(av[1]) >= 100)
        return (84);
    return (0);
}
