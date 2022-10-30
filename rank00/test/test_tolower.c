#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "../libft.h"

int main(int ac, char **av)
{
	(void) ac;
	int i = 1;

	while (av[i])
	{
		char *s = strdup(av[i]);
		char *str = strdup(av[i]);
		int j = 0;
		while(str[j])
		{
			putchar(tolower(str[j]));
			j++;
		}
		printf(", ");
		j = 0;
		while(s[j])
		{
			putchar(ft_tolower(s[j]));
			j++;
		}
		i++;
		printf("\n");
	}
	return 0;
}


