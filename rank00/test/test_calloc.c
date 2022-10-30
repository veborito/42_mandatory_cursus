#include <stdlib.h>
#include <stdio.h>

#include "../libft/libft.h"

void printArray(int *tab, int len)
{
	int i = 0;
	while (i < len)
	{
		printf("%d", tab[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	int		*tab1;
	int		*tab2;
	int		*tab3 = (int *)calloc(0, 0);
	int		i = 1;
	int		n = 0;
	tab1 = (int *)calloc(n, 0);
	tab2= (int *)ft_calloc(n, 0);

	while (i < n - 3)
	{
		tab1[i] = i + 1;
		tab2[i] = i + 1;
		i++;
	}

	printArray(tab1, n);
	printArray(tab2, n);
	printArray(tab3, 1);
	return 0;
}
