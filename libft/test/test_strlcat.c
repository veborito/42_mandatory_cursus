#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libft.h"

int main(int ac, char **av)
{
	(void) ac;
	char dst[30] = "Je m'appelle";
	char dst1[30] = "Je m'appelle";
	int	x, y;
	int z = atoi(av[2]);
	x = strlcat(dst, av[1], z);
	y = ft_strlcat(dst1, av[1], z);
	printf("%s %s\n%d %d\n", dst, dst1, x, y);
	if (x == y)
	{
		printf("\033[0;32m");
		printf("C'est tout bon chacal!\n");
	}
	return 0;
}

