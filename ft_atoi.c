
int ft_atoi(const char *nptr)
{
    int i;
    int sign;
    int number;

    i = 0;
    sign = 1;
    number = 0;
    while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
        i++;
    while (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign *= -1;
        if (nptr[i + 1] == '+' || nptr[i + 1] == '-')
            return (0);
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        number += nptr[i] - 48;
        if (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
            number *= 10;
        i++;
    }
    return (number * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        printf("%d \n", ft_atoi(av[1]));
        printf("%d \n", atoi(av[1]));
    }
    return (0);
}
*/
