#include <stdio.h>
#include <ctype.h>

int ft_isascii(int c);

int main()
{
	int i = 1;
	int x = 0;
	while (i != 150)
	{
		if (isascii(i) != ft_isascii(i))	
		{
			printf("\033[0;31m");
			printf("KO sur: %c", i);
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

