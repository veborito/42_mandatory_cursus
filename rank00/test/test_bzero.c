#include <strings.h>
#include <stdio.h>

#include "../libft.h"

int main()
{
	char s[] = "salut";
	char st[] = "salut";
	int	flag = 0;
	int i = 0;

	bzero(s, 3);
	ft_bzero(st, 3);
	while (s[i] && st[i])
	{
		if (s[i] != st[i])
		{
			flag = 1;
			printf("\033[0;31m");
			printf("KO");
			break;
		}
		i++;
	}
	if (flag == 0)
	{
		printf("\033[0;32m");
		printf("C'est tout bon chacal!\n");
	}
	return (0);
}
