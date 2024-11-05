int my_strlen(char const *str)
{
    int i = 1;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
