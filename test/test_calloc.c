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
	int		*tab3 = (int *)calloc(0, 10);
	int		i = 1;
	int		n = 9;
	tab1 = (int *)calloc(n, sizeof(int));
	tab2= (int *)ft_calloc(n, sizeof(int));

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
