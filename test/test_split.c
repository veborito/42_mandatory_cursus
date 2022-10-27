#include <stdio.h>

#include "../libft/libft.h"

int	main()
{
	char	str1[] = "split  ||this|for|me|||||!|";
	char	c1 = '|';
	char	**splited1;
	int		i;
	
	i = 0;
	splited1 = ft_split(str1, c1); 
	while (splited1[i])
	{
		printf("%s\n", splited1[i]);
		printf("--------\n");
		i++;
	}
	return 0;
}

