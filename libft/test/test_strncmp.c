#include <string.h>
#include <stdio.h>

#include "../libft.h"

int main(int ac, char **av)
{
	(void)ac;
	/*(void)av;
	char s[]="\0";
	char t[]="\200";
	
	printf("%d, %d\n", strncmp(s, t, 100), ft_strncmp(s, t, 100));*/
	printf("%d, %d\n", strncmp(av[1], av[2], 100), ft_strncmp(av[3], av[4], 100));

	return 0;
}
