#define CONFIRMATION() my_putstr("Player removed ");    \
    my_putnbr(nb.matche);                               \
    my_putstr(" match(es) from line ");                 \
    my_putnbr(nb.line);                                 \
    my_putchar('\n');                                   \
    nb.status = 0;

#define DECLARATION() int line = 0;                                     \
    int matche = 0;                                                     \
    line_matche nb= {line, nb_lines, matche, max_matches, board};       \
    line_matche status;

#define CHECK_VALIDITY_LINE() if (nb.line == 84) { \
        nb.status = 84;                         \
        return (nb);                            \
    }

#define CHECK_VALIDITY_MATCHE() if (nb.matche == 84) {      \
        nb.status = 84;                                 \
        return (nb);                                    \
    }

#define EOF_LINES() if (nb.line == -99999) {  \
        nb.status = -1;                         \
        return (nb);                            \
    }

#define EOF_MATCHE() if (nb.matche == -99999) { \
        nb.status = -1;                         \
        return (nb);                            \
    }
