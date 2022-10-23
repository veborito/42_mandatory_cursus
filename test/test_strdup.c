#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libft.h"

int main()
{
	const char s[5][20] = {"Boris", "Verdecia Echarte", "" , "            "};
	char **sc1 = (char **)malloc(sizeof(char *) * 5);
	char **sc2 = (char **)malloc(sizeof(char *) * 5);	
	int	i = 0;
	int flag;
	int j;

	while (i < 4)
	{
		sc1[i] = strdup(s[i]);
		sc2[i] = ft_strdup(s[i]);
		i++;
	}
	sc1[i] = "\0";
	sc2[i] = "\0";
	i = 0;
	while (i < 4)
	{
		flag = 0;
		j = 0;
		printf("%s, %s\n", sc1[i], sc2[i]);
		while (sc1[i][j])
		{
			if (sc1[i][j] != sc2[i][j])
				flag = 1;
			j++;
		}
		if (flag == 1)
		{
			printf("\033[0;31m");
			printf("KO\n");
			printf("\033[0;29m");
		}
		else
		{
			printf("\033[0;32m");
			printf("C'est tout bon chacal!\n");
			printf("\033[0;29m");
		}
		i++;
	}
	return 0;
}
