# include "../includes/all.h"

int my_putnbr(long long nb)
{
    long long nb_ = nb - (nb * 2);

    if (nb <= 9 && nb >= 0) {
        my_putchar(nb + '0');
    }
    else if (nb > 9) {
        my_putnbr((nb/10));
        my_putchar((nb%10) + '0');
    }
    else if (nb < 0) {
        my_putchar('-');
        my_putnbr(nb_);
    }
    return (0);
}
