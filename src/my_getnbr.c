
int my_getnbr(char const *str)
{
    int i;
    int a = 0;
    int sign = 1;

    for (i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-') {
            sign = sign * (-1);
        }
    }
    for (; str[i] <= '9' && str[i] >= '0'; i++) {
        a = (a * 10) + (str[i] - '0');
    }
    return (a * sign);
}
