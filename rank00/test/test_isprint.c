#include <stdio.h>
#include <ctype.h>

int ft_isprint(int c);

int main()
{
	char i = 1;
	int x = 0;
	while (i != '\0')
	{
		if (isprint(i) != ft_isprint(i))	
		{
			printf("\033[0;31m");
			printf("KO sur: %c\n", i);
			x++;
		}
		i++;
	}
	if (x == 0)
	{
		printf("\033[0;32m");
		printf("C'est tout bon chacal!\n");
	}
}

