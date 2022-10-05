#include <stdlib.h>

char    *ft_strdup(char *s)
{
    int     i;
    char    *dup;
   
    i = 0;
    while(s[i])
        i++;
    dup = malloc(sizeof(*s) * (i + 1));
    if (!dup)
        return (0);
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

/*
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i = 1;
        while (i < ac)
        {
            char *dup = ft_strdup(av[i]);
            printf("copie %d: %s \n", i, dup);
            i++;
        }
    }
    return (0);
}
*/
