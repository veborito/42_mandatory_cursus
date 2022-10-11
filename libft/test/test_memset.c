#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libft.h"

void printArr(int *tab)
{
	int i = 0;

	while(i < 4)
	{
		printf("%d", tab[i]);
		i++;
	}
	printf("\n");
	
}

int main()
{
	char s[] = "que pasa";
	char st[] = "que pasa";
	int	tab[5] = {1,2,3,4};
	int	tab1[5] = {1,2,3,4};

	printf("%s\n%s\n", memset(s, 49, 5), ft_memset(st, 49, 5));
	memset(tab, 10, 3);
   	ft_memset(tab1, 10, 3);
	printArr(tab);
	printArr(tab1);
	
	return (0);
}

