#include <string.h>
#include <stdio.h>

#include "../libft.h"

int main(int ac, char **av)
{
	(void)ac;
	char c = av[2][0];
	char l = av[4][0];
	
	printf("%s, %s\n", strchr(av[1], c), ft_strchr(av[3], l));

	return 0;
}

