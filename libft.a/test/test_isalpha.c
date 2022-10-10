//is alpha
#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c);

int main()
{
	char i = 1;
	while (i != '\0')
	{
		if (isalpha(i) == ft_isalpha(i))
		{
			printf("\033[0;32m");
			printf("OK\n");
		}
		else
		{
			printf("\033[0;31m");
			printf("KO");
		}
		i++;
	}
}
