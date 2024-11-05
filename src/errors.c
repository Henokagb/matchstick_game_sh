#include "../includes/all.h"
#include "../includes/macros.h"

int verify_matche(line_matche nb)
{
    if (nb.matche == 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (84);
    }
    else if (nb.matche > nb.nb_matches) {
        write(1, "Error: you cannot remove more than ", 35);
        my_putnbr(nb.nb_matches);
        write(1, " matches per turn\n", 18);
        return (84);
    }
    else if (count_stick(nb.board, nb.line, nb.nb_lines) < nb.matche) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (84);
    }
}

int verify_lines(line_matche nb)
{
    if (nb.line > nb.nb_lines || nb.line == 0) {
        write(1, "Error: this line is out of range\n", 33);
        return (84);
    }
}

line_matche verify_input(line_matche nb)
{
    my_putstr("Line: ");
    nb.line = get_number();
    EOF_LINES()
    CHECK_VALIDITY_LINE()
    if (verify_lines(nb) == 84) {
        nb.status = 84;
        return (nb);
    }
    my_putstr("Matches: ");
    nb.matche = get_number();
    EOF_MATCHE()
    CHECK_VALIDITY_MATCHE()
    if (verify_matche(nb) == 84) {
        nb.status = 84;
        return (nb);
    }
    CONFIRMATION()
    return (nb);
}
