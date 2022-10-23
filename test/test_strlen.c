#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libft.h"

int main()
{
	int nb_str, num, i;
	char **str; 
	str = malloc(sizeof(char*) * 20);
	nb_str = 0;
	while(nb_str < 20)
	{
		num = rand() % 21;
		char *s; 
		s = malloc(sizeof(char) * (num + 1));
		i = 0;
		while (i <= num)
		{
			s[i] = 'a';
			i++;
		}
		s[i] = '\0';
		str[nb_str] = s;
		nb_str++;
	}
	str[nb_str] = "\0";
	int flag = 0;
	int j = 0;
	while (str[j])
	{
		if (strlen(str[j]) != ft_strlen(str[j]))
		{
			printf("\033[0;31m");
			printf("KO sur: %s", str[j]);
			flag++;
		}
		j++;
	}

	if (flag == 0)
	{
		printf("\033[0;32m");
		printf("C'est tout bon chacal!\n");
	}
}
