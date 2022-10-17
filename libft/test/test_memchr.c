#include <stdio.h>
#include <string.h>

#include "../libft.h"

void	printArray(int *tab)
{
	int	i = 0;

	while (tab[i])
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}


int main()
{
	const char	s[] = "123 456";	
	const char	s1[] = "123 456";	
	char		*str = memchr(s,0, 10);
	char		*str1 = ft_memchr(s1, 0, 10);
	
	printf("%s, %s\n", str,str1);
	printf("%s, %s\n", s,s1);
	return 0;
}
