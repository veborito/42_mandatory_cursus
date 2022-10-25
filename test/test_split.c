#include <stdio.h>

#include "../libft/libft.h"

int	main()
{
	char	str[] ="ttttttthellottttt";
	char	c = 't';
	char	**splited;
	int		i;
	
	i = 0;
	splited = ft_split(str, c); 
	while (splited[i])
	{
		printf("%s\n", splited[i]);
		i++;
	}
	return 0;
}

